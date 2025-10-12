# my_navy

Implémentation du jeu de **Bataille navale** (Battleship) avec communication inter-processus via signaux Unix.

## Description

`my_navy` est une version du jeu classique de bataille navale jouable entre deux terminaux. Les deux joueurs communiquent via des signaux Unix (`SIGUSR1` et `SIGUSR2`), permettant une communication inter-processus sans utiliser de sockets réseau.

## Fonctionnalités

### Gameplay

- 🚢 **Bataille navale classique** : Placer des bateaux et deviner leur position
- 💬 **Communication par signaux Unix** : `SIGUSR1` et `SIGUSR2`
- 🎮 **Mode 2 joueurs** : Un joueur crée la partie, l'autre rejoint
- 🗺️ **Grille de jeu** : Visualisation des tirs et des bateaux
- 🎯 **Système de feedback** : "Touché", "Manqué", "Coulé"
- 📋 **Fichier de configuration** : Positionnement des bateaux via fichier

### Système de signaux

Le jeu utilise les signaux POSIX pour communiquer :
- **SIGUSR1** : Représente le bit `0`
- **SIGUSR2** : Représente le bit `1`
- Les coordonnées et résultats sont encodés et transmis bit par bit

## Compilation

```bash
make
```

Cela va :
1. Compiler la bibliothèque `libmy.a`
2. Compiler tous les fichiers sources
3. Créer l'exécutable `my_navy`

### Autres commandes make

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout (objets + exécutable)
make re         # Recompile tout depuis zéro
```

## Utilisation

### Afficher l'aide

```bash
./my_navy -h
```

### Démarrer une partie

#### Joueur 1 (crée la partie)

```bash
./my_navy map1.txt
```

Le programme affiche son PID et attend le joueur 2.

#### Joueur 2 (rejoint la partie)

```bash
./my_navy map2.txt <PID_JOUEUR_1>
```

Remplacez `<PID_JOUEUR_1>` par le PID affiché par le joueur 1.

## Format du fichier de carte

Le fichier de carte définit la position des bateaux sur la grille.

### Exemple de fichier (map1.txt)

```
2:C3:N
3:E5:E
3:A1:S
4:F2:E
5:B7:S
```

### Format des lignes

```
<taille>:<position>:<orientation>
```

- **taille** : Longueur du bateau (2-5)
- **position** : Coordonnée de départ (A-H)(1-8)
- **orientation** : N (Nord), S (Sud), E (Est), W (Ouest)

### Types de bateaux

| Taille | Nom |
|--------|-----|
| 2 | Patrouilleur |
| 3 | Contre-torpilleur |
| 3 | Contre-torpilleur |
| 4 | Torpilleur |
| 5 | Porte-avions |

### Contraintes

- Les bateaux ne doivent pas se chevaucher
- Les bateaux doivent rester dans les limites de la grille (A-H, 1-8)
- Tous les bateaux doivent être présents

## Déroulement d'une partie

1. **Connexion** : Les deux joueurs se connectent via leurs PIDs
2. **Affichage** : Chaque joueur voit sa grille et celle de l'adversaire
3. **Tour par tour** :
   - Un joueur entre des coordonnées (ex: `B4`)
   - Le programme envoie les coordonnées via signaux
   - L'adversaire reçoit et répond (touché/manqué)
   - Les grilles sont mises à jour
4. **Victoire** : Le premier qui coule tous les bateaux adverses gagne

## Architecture

```
my_navy/
├── Makefile
├── include/
│   └── my_navy.h       # Structures et prototypes
└── src/
    ├── main.c          # Point d'entrée
    ├── init.c          # Initialisation du jeu
    ├── player.c        # Logique joueur 1
    ├── player2.c       # Logique joueur 2
    ├── handler.c       # Handlers de signaux
    ├── send.c          # Envoi de signaux
    ├── display.c       # Affichage des grilles
    ├── check.c         # Vérification des coups
    └── gnl.c           # Get Next Line (lecture fichier)
```

## Structures de données

### global_signals_t

Structure globale pour gérer les signaux :

```c
typedef struct {
    int signal_state;       // État actuel du signal
    char *signal_str;       // Chaîne représentant le signal
    int feedback;           // Résultat du tir
} global_signals_t;
```

### game_status_t

Structure contenant l'état de la partie :

```c
typedef struct {
    char **my_map;          // Ma grille
    char **enemy_map;       // Grille adversaire
    int enemy_pid;          // PID de l'adversaire
    // ... autres champs
} game_status_t;
```

## Signaux Unix utilisés

### SIGUSR1 et SIGUSR2

Le jeu encode les informations en binaire :
- **SIGUSR1** = bit 0
- **SIGUSR2** = bit 1

### Exemple de transmission

Pour envoyer la coordonnée "B4" :
1. Convertir en format encodé
2. Envoyer chaque bit via `kill(pid, SIGUSR1)` ou `kill(pid, SIGUSR2)`
3. Le receveur reconstruit l'information bit par bit

### Handlers de signaux

```c
signal(SIGUSR1, signal_handler_1);
signal(SIGUSR2, signal_handler_2);
```

## Affichage des grilles

### Ma grille

```
   |A B C D E F G H
---+----------------
 1 |. . 2 2 . . . .
 2 |. . . . . . . .
 3 |. . 3 . . . . .
 4 |. . 3 . . . . .
 5 |. . 3 . . 4 4 4
 6 |. . . . . . . .
 7 |. . . . . . . .
 8 |. . . . . . . .
```

### Grille adverse

```
   |A B C D E F G H
---+----------------
 1 |. . . . . . . .
 2 |. . . x . . . .
 3 |. . . . . . . .
 4 |. o . . . . . .
 5 |. . . . . . . .
 6 |. . . . . . . .
 7 |. . . . . . . .
 8 |. . . . . . . .
```

Légende :
- `.` : Case non touchée
- `o` : Tir manqué
- `x` : Tir réussi (touché)
- Chiffres : Bateaux (sur ma grille)

## Entrée utilisateur

Format : `<Lettre><Chiffre>`

Exemples valides :
- `A1`
- `H8`
- `D4`

## Messages de feedback

- **"missed"** : Tir dans l'eau
- **"hit"** : Touché !
- **"I won"** : Victoire
- **"Enemy won"** : Défaite

## Code de retour

- `0` : Victoire
- `1` : Défaite
- `84` : Erreur (arguments invalides, fichier invalide, etc.)

## Gestion d'erreurs

Le programme vérifie :
- ✅ Nombre d'arguments correct (2 ou 3)
- ✅ Existence du fichier de carte
- ✅ Validité du format de carte
- ✅ Validité du PID adverse (pour le joueur 2)
- ✅ Pas de chevauchement de bateaux
- ✅ Bateaux dans les limites de la grille

## Limitations connues

- Les deux joueurs doivent être sur la même machine (PIDs locaux)
- Variable globale pour les signaux (pas thread-safe)
- Pas de reconnexion en cas d'interruption
- Interface textuelle uniquement

## Exemple de partie complète

**Terminal 1 (Joueur 1) :**
```bash
$ ./my_navy map1.txt
my_pid: 12345
Waiting for enemy connection...

[Grilles affichées]
attack: B4
```

**Terminal 2 (Joueur 2) :**
```bash
$ ./my_navy map2.txt 12345

[Grilles affichées]
B4: missed
attack: C3
```

## Concepts démontrés

- Communication inter-processus (IPC)
- Signaux Unix (SIGUSR1, SIGUSR2)
- Handlers de signaux
- Parsing de fichiers
- Logique de jeu tour par tour
- Validation d'entrées utilisateur

## Débogage

Pour observer les signaux :

```bash
# Dans un terminal, lancer avec strace
strace -e signal ./my_navy map1.txt
```

## Améliorations possibles

- [ ] Communication réseau (sockets) au lieu de signaux
- [ ] Interface graphique
- [ ] IA pour jouer contre l'ordinateur
- [ ] Sauvegarde/reprise de partie
- [ ] Mode spectateur
- [ ] Animations des tirs

## Auteur

Enzo Pambout - Epitech 2024

## Licence

Projet éducatif - Epitech
