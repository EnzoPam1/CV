# my_hunter

Recréation du jeu classique **Duck Hunt** avec CSFML (Simple and Fast Multimedia Library).

## Description

`my_hunter` est un jeu de tir où le joueur doit abattre des canards qui traversent l'écran. Le jeu présente un système de niveaux, de difficulté progressive et de score. Vous perdez après avoir manqué 3 canards, mais toucher un canard vous redonne 3 chances !

## Fonctionnalités

### Gameplay

- 🎯 **Système de tir** : Cliquez sur les canards pour les abattre
- 🦆 **Animations fluides** : Canards animés image par image
- 🎚️ **Système de difficulté** : Easy, Medium, Hard
- 📊 **20 niveaux progressifs** : La difficulté augmente graduellement
- 💯 **Système de score** : Score sauvegardé entre les sessions
- ❤️ **Système de vies** : 3 chances, rechargées à chaque canard touché
- 🎨 **Curseur personnalisé** : Viseur de tir
- 🖼️ **Arrière-plan graphique** : Décor immersif

### Fonctionnalités techniques

- Gestion d'événements SFML
- Boucle de jeu avec delta time
- Système d'animation sprite-based
- Gestion de textures et sprites
- Écran de fin de partie
- Persistance du meilleur score

## Dépendances

### Bibliothèques requises

- **CSFML** (C Simple and Fast Multimedia Library)
  - libcsfml-graphics
  - libcsfml-window
  - libcsfml-system
  - libcsfml-audio

### Installation des dépendances

```bash
# Ubuntu/Debian
sudo apt-get install libcsfml-dev libsfml-dev

# Fedora/RHEL
sudo dnf install CSFML-devel

# Arch Linux
sudo pacman -S csfml
```

## Compilation

```bash
make
```

Cela va :
1. Compiler la bibliothèque `libmy.a`
2. Compiler tous les fichiers sources
3. Lier avec CSFML
4. Créer l'exécutable `my_hunter`

### Autres commandes make

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout (objets + exécutable)
make re         # Recompile tout depuis zéro
```

## Utilisation

### Lancer le jeu

```bash
./my_hunter
```

### Afficher l'aide

```bash
./my_hunter -h
```

Affiche :
- Description du jeu
- Règles
- Commandes
- Informations sur l'auteur

## Commandes de jeu

| Commande | Action |
|----------|--------|
| **Clic gauche** | Tirer sur un canard |
| **ESC** | Quitter le jeu |

## Règles du jeu

1. Des canards apparaissent et traversent l'écran
2. Cliquez sur un canard pour le toucher
3. Vous commencez avec **3 vies**
4. Si un canard sort de l'écran sans être touché, vous perdez une vie
5. Toucher un canard vous redonne **3 vies**
6. Le jeu se termine quand vous n'avez plus de vies
7. Objectif : Passer les **20 niveaux** !

## Architecture

```
my_hunter/
├── Makefile
├── include/
│   ├── game.h          # Structure du jeu et types
│   ├── duck.h          # Gestion des canards
│   ├── events.h        # Gestion des événements
│   ├── graphics.h      # Rendu graphique
│   ├── animation.h     # Système d'animation
│   ├── init.h          # Initialisation
│   ├── cleanup.h       # Nettoyage mémoire
│   ├── endscreen.h     # Écran de fin
│   ├── text_utils.h    # Utilitaires texte
│   ├── duck_init.h     # Initialisation canards
│   └── my.h            # Bibliothèque personnalisée
└── src/
    ├── main.c          # Point d'entrée
    ├── game.c          # Boucle de jeu principale
    ├── duck.c          # Logique des canards
    ├── duck_init.c     # Initialisation canards
    ├── events.c        # Gestion événements
    ├── graphics.c      # Rendu graphique
    ├── animation.c     # Animations
    ├── init.c          # Initialisation ressources
    ├── cleanup.c       # Libération mémoire
    ├── endscreen.c     # Écran de fin
    └── text_utils.c    # Utilitaires texte
```

## Structures de données

### Game
Structure principale contenant l'état complet du jeu :

```c
typedef struct Game {
    sfRenderWindow *window;
    sfClock *clock;
    float deltaTime;
    Duck duck;
    Difficulty difficulty;
    sfVideoMode video_mode;
    int score;
    sfFont* font;
    int level;
    sfTexture* backgroundTexture;
    sfSprite* backgroundSprite;
    int bestScore;
    int missedDucks;
    int totalDucksShot;
    sfSprite* cursorSprite;
    sfTexture* cursorTexture;
} Game;
```

### Duck
Structure représentant un canard :

```c
typedef struct Duck {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f position;
    float velocity;
    int frameCount;
    int currentFrame;
    float timeSinceLastFrame;
    float animationSpeed;
    int frameWidth;
    int frameHeight;
    sfBool isShot;
    int animationDirection;
    float speed;
} Duck;
```

### Difficulty
Énumération des niveaux de difficulté :

```c
typedef enum {
    EASY,
    MEDIUM,
    HARD
} Difficulty;
```

## Système de difficulté

Le jeu ajuste automatiquement la difficulté en fonction du niveau :
- **Niveaux 1-7** : Easy (vitesse lente)
- **Niveaux 8-14** : Medium (vitesse moyenne)
- **Niveaux 15-20** : Hard (vitesse rapide)

## Assets requis

Le jeu nécessite les fichiers suivants (à placer dans le même dossier que l'exécutable) :

- `duck.png` : Spritesheet du canard
- `background.png` : Image d'arrière-plan
- `cursor.png` : Curseur de visée
- `font.ttf` : Police pour le texte

## Améliorations possibles

- [ ] Système de combo pour les tirs rapides
- [ ] Effets sonores (coups de feu, canards)
- [ ] Particules lors des tirs
- [ ] Menu de pause
- [ ] Différents types de canards
- [ ] Power-ups
- [ ] Multijoueur
- [ ] Sauvegarde des paramètres

## Compilation conditionnelle

Le jeu vérifie automatiquement :
- La création de la fenêtre
- Le chargement des ressources
- L'initialisation des textures

En cas d'erreur, le code de retour est `84`.

## Code de retour

- `0` : Succès (jeu terminé normalement)
- `84` : Erreur (échec d'initialisation)

## Débogage

Pour déboguer les problèmes graphiques :

```bash
# Vérifier que CSFML est installé
pkg-config --modversion csfml-graphics

# Lancer avec valgrind pour détecter les fuites mémoire
valgrind --leak-check=full ./my_hunter
```

## Performance

- **FPS cible** : 60 FPS
- **Delta Time** : Utilisé pour des animations fluides indépendantes du framerate
- **Optimisations** : Sprites réutilisés, pas de création dynamique à chaque frame

## Auteur

Enzo Pambout - Epitech 2023

**Jeu réalisé par Enzo Pambout**

## Licence

Projet éducatif - Epitech
