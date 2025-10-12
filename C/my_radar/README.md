# my_radar

Simulateur de radar aérien avec visualisation des trajectoires d'avions et détection de collisions en temps réel.

## Description

`my_radar` est une simulation graphique d'un système de contrôle du trafic aérien. Le programme affiche un radar circulaire et visualise la trajectoire de plusieurs avions en temps réel. Il détecte et signale les collisions potentielles entre aéronefs.

## Fonctionnalités

### Simulation

- 🛫 **Trajectoires d'avions** : Visualisation en temps réel
- 📡 **Radar circulaire** : Affichage type contrôle aérien
- ⚠️ **Détection de collisions** : Alerte en cas de proximité dangereuse
- 🎬 **Animation fluide** : Mise à jour continue des positions
- 📊 **Informations vol** : ID, position, trajectoire de chaque avion
- ⏱️ **Simulation temporelle** : Progression du temps contrôlée

### Graphisme

- Interface CSFML pour le rendu graphique
- Radar avec balayage rotatif
- Points représentant les avions
- Lignes de trajectoire
- Zones de collision visuelles

## Dépendances

### Bibliothèques requises

- **CSFML** (C Simple and Fast Multimedia Library)
  - libcsfml-graphics
  - libcsfml-window
  - libcsfml-system

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
1. Compiler tous les fichiers sources
2. Lier avec CSFML
3. Créer l'exécutable `my_radar`

### Autres commandes make

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout (objets + exécutable)
make re         # Recompile tout depuis zéro
```

## Utilisation

### Lancer la simulation

```bash
./my_radar fichier_avions.txt
```

### Format du fichier de configuration

Le fichier d'entrée définit les avions et leurs trajectoires.

#### Format des lignes

```
A <x_start> <y_start> <x_end> <y_end> <vitesse>
```

- `A` : Type d'entité (avion)
- `x_start` : Position X de départ
- `y_start` : Position Y de départ
- `x_end` : Position X d'arrivée
- `y_end` : Position Y d'arrivée
- `vitesse` : Vitesse de l'avion (pixels par seconde)

#### Exemple de fichier (avions.txt)

```
A 100 200 800 600 50
A 400 100 400 700 75
A 900 300 100 300 60
```

Cet exemple définit 3 avions :
- Avion 1 : De (100,200) vers (800,600) à 50 px/s
- Avion 2 : De (400,100) vers (400,700) à 75 px/s
- Avion 3 : De (900,300) vers (100,300) à 60 px/s

## Contrôles

| Touche | Action |
|--------|--------|
| **L** | Afficher/masquer les trajectoires |
| **ESC** | Quitter la simulation |
| **SPACE** | Pause/Reprendre |
| **+/-** | Accélérer/ralentir le temps |

## Architecture

```
my_radar/
├── Makefile
├── include/
│   ├── radar.h         # Structure principale
│   ├── usage.h         # Gestion arguments
│   ├── events.h        # Gestion événements
│   └── building/
│       └── simulation/
│           └── sim.h   # Logique de simulation
└── src/
    ├── main.c          # Point d'entrée
    ├── usage.c         # Parsing arguments
    ├── simulation.c    # Logique simulation
    └── (autres modules)
```

## Structures de données

### window_t

Structure représentant la fenêtre de simulation :

```c
typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    // ... autres champs
} window_t;
```

### Avion (aircraft_t)

Structure d'un avion :

```c
typedef struct {
    int id;
    float x, y;             // Position actuelle
    float x_start, y_start; // Position de départ
    float x_end, y_end;     // Position d'arrivée
    float speed;            // Vitesse
    float angle;            // Direction
    int active;             // Avion actif/arrivé
} aircraft_t;
```

## Algorithme de détection de collision

Le programme détecte les collisions potentielles en :

1. Calculant la distance entre chaque paire d'avions
2. Comparant avec une distance minimale de sécurité
3. Vérifiant si les trajectoires se croisent
4. Signalant visuellement les dangers

### Distance de sécurité

```c
#define COLLISION_DISTANCE 50.0  // pixels
```

Si deux avions sont à moins de 50 pixels, une collision est détectée.

## Affichage du radar

### Éléments visuels

- **Cercle de radar** : Zone de surveillance
- **Ligne de balayage** : Rotation continue (effet radar)
- **Points avions** : Position actuelle de chaque aéronef
- **Lignes de trajectoire** : Chemin prévu (si activé avec L)
- **Zones de collision** : Cercles rouges autour des avions en danger

### Couleurs

- 🟢 **Vert** : Avion en sécurité
- 🔴 **Rouge** : Avion en collision potentielle
- 🔵 **Bleu** : Trajectoires
- ⚪ **Blanc** : Ligne de balayage radar

## Options de ligne de commande

### Afficher l'aide

```bash
./my_radar -h
```

ou

```bash
./my_radar --help
```

Affiche :
- Description du programme
- Format du fichier d'entrée
- Contrôles disponibles
- Exemples d'utilisation

## Code de retour

- `0` : Succès
- `84` : Erreur (arguments invalides, fichier inexistant, erreur d'initialisation)

## Gestion d'erreurs

Le programme vérifie :
- ✅ Nombre d'arguments correct
- ✅ Existence du fichier d'entrée
- ✅ Format du fichier valide
- ✅ Coordonnées dans les limites
- ✅ Vitesse positive
- ✅ Initialisation CSFML réussie

## Exemple de sortie

```
$ ./my_radar avions.txt
[Fenêtre graphique s'ouvre]
Aircraft #1: (100, 200) → (800, 600) @ 50px/s
Aircraft #2: (400, 100) → (400, 700) @ 75px/s
Aircraft #3: (900, 300) → (100, 300) @ 60px/s

⚠️  COLLISION WARNING: Aircraft #1 and #2 at distance 45px
```

## Calculs mathématiques

### Calcul de trajectoire

Position à l'instant `t` :

```c
x(t) = x_start + (x_end - x_start) * (t / total_time)
y(t) = y_start + (y_end - y_start) * (t / total_time)
```

### Distance entre deux avions

```c
distance = sqrt((x2 - x1)² + (y2 - y1)²)
```

### Angle de trajectoire

```c
angle = atan2(y_end - y_start, x_end - x_start)
```

## Performance

- **FPS cible** : 60 FPS
- **Nombre d'avions max recommandé** : 50
- **Optimisation** : Détection de collision O(n²) avec early exit

## Débogage

### Vérifier CSFML

```bash
pkg-config --modversion csfml-graphics
```

### Mode verbose

Pour déboguer, vous pouvez ajouter des prints dans le code :

```c
printf("Aircraft %d at (%.2f, %.2f)\n", id, x, y);
```

### Valgrind

```bash
valgrind --leak-check=full ./my_radar avions.txt
```

## Limitations connues

- Pas de déformation de perspective (vue 2D plate)
- Collisions détectées par distance simple (pas de prédiction avancée)
- Pas de gestion d'altitude (simulation 2D uniquement)
- Interface basique sans HUD détaillé

## Extensions possibles

- [ ] Vue 3D avec altitude
- [ ] Prédiction de trajectoire avancée
- [ ] Gestion de la météo (vent, turbulences)
- [ ] Zones d'exclusion aérienne
- [ ] Historique des trajectoires
- [ ] Statistiques de trafic
- [ ] Export des données de vol
- [ ] Mode replay

## Concepts démontrés

- Graphisme 2D avec CSFML
- Simulation physique simple
- Détection de collisions
- Boucle de jeu temps réel
- Parsing de fichiers de configuration
- Calculs vectoriels

## Auteur

Enzo Pambout - Epitech 2023

## Licence

Projet éducatif - Epitech
