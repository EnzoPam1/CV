# my_sokoban

Implémentation du jeu de puzzle classique **Sokoban** avec interface ncurses.

## Description

`my_sokoban` est une réimplémentation du célèbre jeu de puzzle Sokoban. Le joueur doit pousser toutes les caisses sur des emplacements cibles dans un entrepôt. Un jeu de réflexion et de logique qui demande de la planification !

## Règles du jeu

🎯 **Objectif** : Pousser toutes les caisses (`X`) sur les emplacements cibles (`O`)

📜 **Règles** :
- Vous pouvez uniquement **pousser** les caisses, pas les tirer
- Une seule caisse peut être poussée à la fois
- Les caisses ne peuvent pas être poussées à travers les murs (`#`)
- Une caisse sur un emplacement cible ne peut plus être déplacée
- Vous gagnez quand toutes les caisses sont sur des emplacements cibles

## Fonctionnalités

- 🎮 **Interface ncurses** : Affichage console élégant
- ⌨️ **Contrôles claviers** : Déplacement aux flèches ou WASD
- 🔄 **Undo** : Annuler le dernier mouvement (TODO)
- 📊 **Compteur de mouvements** : Track vos performances (TODO)
- 🗺️ **Niveaux personnalisés** : Chargez vos propres maps
- ✅ **Validation des mouvements** : Prévient les actions invalides
- 🏆 **Détection de victoire** : Message automatique en fin de niveau

## Dépendances

### Bibliothèque requise

- **ncurses** : Bibliothèque pour interfaces console

### Installation

```bash
# Ubuntu/Debian
sudo apt-get install libncurses-dev

# Fedora/RHEL
sudo dnf install ncurses-devel

# Arch Linux
sudo pacman -S ncurses
```

## Compilation

```bash
make
```

Cela va :
1. Compiler la bibliothèque `libmy.a`
2. Compiler tous les fichiers sources
3. Lier avec ncurses
4. Créer l'exécutable `my_sokoban`

### Autres commandes make

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout (objets + exécutable)
make re         # Recompile tout depuis zéro
```

## Utilisation

### Afficher l'aide

```bash
./my_sokoban -h
```

Affiche :
```
USAGE
    ./my_sokoban game_map

DESCRIPTION
    map    file representing the warehouse game_map, containing
           '#' for walls,
           'P' for the player, 'X' for boxes and 'O' for storage locations.
```

### Lancer le jeu

```bash
./my_sokoban map.txt
```

## Format du fichier de carte

Le fichier de carte définit la disposition de l'entrepôt.

### Caractères utilisés

| Caractère | Signification |
|-----------|---------------|
| `#` | Mur (infranchissable) |
| `P` | Position de départ du joueur |
| `X` | Caisse à pousser |
| `O` | Emplacement cible |
| ` ` (espace) | Sol libre |

### Exemple de carte (map.txt)

```
#####
#   #
# X #
# O #
# P #
#####
```

### Exemple complexe

```
##########
#        #
# X  X   #
#   ###  #
# O   O  #
#   P    #
##########
```

### Contraintes

- La carte doit être rectangulaire (remplie d'espaces si nécessaire)
- Il doit y avoir exactement **un joueur** (`P`)
- Le nombre de **caisses** (`X`) doit égaler le nombre d'**emplacements** (`O`)
- La carte doit être entourée de murs (`#`)

## Contrôles

### Déplacements

| Touche | Action |
|--------|--------|
| **↑** ou **W** | Se déplacer vers le haut |
| **↓** ou **S** | Se déplacer vers le bas |
| **←** ou **A** | Se déplacer vers la gauche |
| **→** ou **D** | Se déplacer vers la droite |

### Autres

| Touche | Action |
|--------|--------|
| **SPACE** | Attendre (ne rien faire) |
| **R** | Recommencer le niveau |
| **ESC** | Quitter le jeu |

## Architecture

```
sokoban/
├── Makefile
├── include/
│   ├── sokoban.h       # Structures et constantes
│   └── my.h            # Bibliothèque personnalisée
└── src/
    ├── main.c          # Point d'entrée et initialisation
    ├── starting.c      # Démarrage du jeu
    ├── opening.c       # Chargement de carte
    ├── moves.c         # Logique de déplacement (partie 1)
    ├── moves1.c        # Logique de déplacement (partie 2)
    ├── moves2.c        # Logique de déplacement (partie 3)
    └── error_handling.c # Gestion des erreurs
```

## Structures de données

### game_state

Structure principale contenant l'état du jeu :

```c
struct game_state {
    char **game_map;        // Carte du jeu
    char *data_buffer;      // Buffer de lecture fichier
    int player_x;           // Position X du joueur
    int player_y;           // Position Y du joueur
    int boxes_remaining;    // Caisses restantes à placer
    int moves;              // Nombre de mouvements
    // ... autres champs
};
```

## Fonctions ncurses utilisées

- `initscr()` : Initialise l'écran ncurses
- `noecho()` : Désactive l'écho des touches
- `curs_set(0)` : Cache le curseur
- `keypad(stdscr, TRUE)` : Active les touches spéciales (flèches)
- `mvprintw()` : Affiche du texte à une position
- `getch()` : Récupère une touche pressée
- `refresh()` : Rafraîchit l'affichage
- `endwin()` : Termine ncurses proprement

## Vérification de taille de terminal

Le jeu vérifie si le terminal est assez grand :

```c
while (map_width > COLS || map_height > LINES) {
    mvprintw(LINES / 2, (COLS / 2 - 6), "Resize");
    refresh();
}
```

Si le terminal est trop petit, un message "Resize" s'affiche.

## Logique de déplacement

### Déplacement simple

Le joueur peut se déplacer si :
1. La case cible est vide (espace ou emplacement `O`)
2. La case cible n'est pas un mur

### Pousser une caisse

Le joueur peut pousser une caisse si :
1. La case devant le joueur contient une caisse
2. La case derrière la caisse est libre
3. La case derrière n'est pas un mur ou une autre caisse

### Algorithme

```
Si direction = UP:
    Si case_au_dessus == CAISSE:
        Si case_2_au_dessus == LIBRE:
            Déplacer caisse vers le haut
            Déplacer joueur vers le haut
        Sinon:
            Mouvement impossible
    Sinon Si case_au_dessus == LIBRE:
        Déplacer joueur vers le haut
    Sinon:
        Mouvement impossible
```

## Conditions de victoire

Le joueur gagne quand :

```c
boxes_remaining == 0
```

Toutes les caisses sont sur des emplacements cibles.

### Message de victoire

```
################
#              #
#  YOU WIN !   #
#              #
################
```

## Code de retour

- `0` : Victoire ou sortie normale
- `84` : Erreur (arguments invalides, fichier invalide, carte invalide)

## Gestion d'erreurs

Le programme vérifie :
- ✅ Nombre d'arguments correct (doit être 2)
- ✅ Existence du fichier de carte
- ✅ Format de carte valide
- ✅ Présence d'exactement un joueur
- ✅ Nombre égal de caisses et emplacements
- ✅ Carte fermée par des murs

### Messages d'erreur

```bash
# Nombre d'arguments incorrect
$ ./my_sokoban
echo $?  # 84

# Fichier inexistant
$ ./my_sokoban non_existant.txt
# Erreur : Fichier non trouvé

# Carte invalide
$ ./my_sokoban carte_invalide.txt
# Erreur : Carte mal formée
```

## Exemples de cartes

### Niveau facile

```
#######
#     #
# P X #
#   O #
#######
```

### Niveau moyen

```
##########
#        #
# XX  OO #
#  P     #
##########
```

### Niveau difficile

```
  #######
  #     #
  # # # #
###X   X###
#  O P O  #
###   X###
  # # #
  #   #
  #####
```

## Astuces de jeu

1. **Planifiez à l'avance** : Réfléchissez avant de pousser
2. **Évitez les coins** : Ne poussez pas les caisses dans les coins
3. **Ordre important** : Parfois il faut pousser dans un ordre spécifique
4. **Utilisez les murs** : Les murs peuvent servir de guides
5. **Recommencez si bloqué** : Appuyez sur R pour recommencer

## Situations de blocage

❌ **Caisse dans un coin** : Impossible à récupérer
```
##
#X
```

❌ **Deux caisses côte à côte contre un mur** : Souvent impossibles à séparer
```
#XX
```

## Débogage

### Afficher la carte en mode texte

```bash
cat map.txt
```

### Vérifier ncurses

```bash
pkg-config --modversion ncurses
```

### Mode verbose

Ajoutez des logs dans le code :

```c
FILE *debug = fopen("debug.log", "a");
fprintf(debug, "Player at (%d, %d)\n", player_x, player_y);
fclose(debug);
```

## Améliorations possibles

- [ ] Compteur de mouvements affiché
- [ ] Fonction UNDO (annuler dernier coup)
- [ ] Fonction REDO (refaire coup annulé)
- [ ] Timer pour speedrun
- [ ] Sauvegarde du meilleur score
- [ ] Multiple niveaux dans un fichier
- [ ] Éditeur de niveaux intégré
- [ ] Colorisation ncurses
- [ ] Animation des déplacements

## Concepts démontrés

- Interface utilisateur en console (ncurses)
- Gestion d'événements clavier
- Logique de jeu de puzzle
- Parsing de fichiers texte
- Détection de collision
- Gestion d'états de jeu

## Ressources

- [Sokoban original](https://en.wikipedia.org/wiki/Sokoban)
- [Collection de niveaux Sokoban](http://www.sokobano.de/en/levels.php)
- [Documentation ncurses](https://invisible-island.net/ncurses/)

## Auteur

Enzo Pambout - Epitech 2023

## Licence

Projet éducatif - Epitech
