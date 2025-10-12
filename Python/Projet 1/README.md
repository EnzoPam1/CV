# 101pong - Simulation de trajectoire de balle de baseball

Calcul de la trajectoire d'une balle de baseball et détermination de l'impact avec une batte.

## Description

Ce projet simule le mouvement d'une balle de baseball en utilisant des équations de physique cinématique. Il calcule la position de la balle après un temps donné et détermine si elle atteindra la batte du batteur.

## Fonctionnalités

- 📐 **Calcul vectoriel** : Vecteur vitesse entre deux points
- 🎯 **Trajectoire balistique** : Simulation du mouvement de la balle
- 📊 **Prédiction d'impact** : Détermine si la balle atteindra le plan z=0 (batte)
- 🔢 **Angle d'incidence** : Calcul de l'angle entre la balle et la batte
- ✅ **Validation complète** : Gestion d'erreurs et vérification des arguments

## Théorie physique

### Modèle cinématique

Le programme utilise un modèle de mouvement linéaire (sans gravité pour simplifier) :

```
Position(t) = Position_initiale + Vitesse × t
```

En 3D :
```
x(t) = x₀ + vₓ × t
y(t) = y₀ + vᵧ × t
z(t) = z₀ + vᵤ × t
```

### Vecteur vitesse

```
v⃗ = B⃗ - A⃗ = (xb - xa, yb - ya, zb - za)
```

### Angle d'incidence

L'angle entre la trajectoire et le plan de la batte (z=0) :

```
angle = arcsin(|vᵤ| / ‖v⃗‖)
```

Où `‖v⃗‖` est la norme du vecteur vitesse.

## Utilisation

### Syntaxe

```bash
./101pong x0 y0 z0 x1 y1 z1 n
```

### Paramètres

- `x0 y0 z0` : Coordonnées du point A (position initiale)
- `x1 y1 z1` : Coordonnées du point B (position après 1 seconde)
- `n` : Décalage temporel en secondes (entier positif)

### Exemples

#### Exemple 1 : Balle atteignant la batte

```bash
$ ./101pong 0 0 1 1 1 0 2

The velocity vector of the ball is:
(1.00, 1.00, -1.00)
At time t + 2, ball coordinates will be:
(3.00, 3.00, -2.00)
The incidence angle is:
33.56 degrees
```

La balle traverse le plan z=0, donc elle atteindra la batte.

#### Exemple 2 : Balle manquant la batte

```bash
$ ./101pong 0 0 1 1 1 2 5

The velocity vector of the ball is:
(1.00, 1.00, 1.00)
At time t + 5, ball coordinates will be:
(6.00, 6.00, 7.00)
The ball won't reach the paddle.
```

La balle monte (z positif croissant), elle ne touchera jamais la batte.

#### Exemple 3 : Arguments invalides

```bash
$ ./101pong 0 0 0 1 1 1 -5
Time shift must be a positive integer.
$ echo $?
84
```

#### Exemple 4 : Balle stationnaire

```bash
$ ./101pong 5 5 5 5 5 5 10

The velocity vector of the ball is:
(0.00, 0.00, 0.00)
At time t + 10, ball coordinates will be:
(5.00, 5.00, 5.00)
The ball won't reach the paddle.
```

## Sorties possibles

### Cas 1 : Impact avec la batte

```
The velocity vector of the ball is:
(vx, vy, vz)
At time t + n, ball coordinates will be:
(x, y, z)
The incidence angle is:
XX.XX degrees
```

### Cas 2 : Pas d'impact

```
The velocity vector of the ball is:
(vx, vy, vz)
At time t + n, ball coordinates will be:
(x, y, z)
The ball won't reach the paddle.
```

## Algorithme

### 1. Validation des arguments

```python
# Vérifier le nombre d'arguments (8 attendus)
if len(sys.argv) != 8:
    print("Usage: ./101pong x0 y0 z0 x1 y1 z1 n", file=sys.stderr)
    sys.exit(84)

# Vérifier que tous les arguments sont numériques
# Vérifier que n est positif
```

### 2. Calcul du vecteur vitesse

```python
def init_vec(A, B):
    return [B[i] - A[i] for i in range(len(A))]
```

### 3. Calcul de la position future

```python
def calcul_position_apres_temps(vec, A, n):
    nouvelle_position = [A[i] + n * vec[i] for i in range(3)]
    return nouvelle_position
```

### 4. Détection d'impact

```python
# La balle atteint la batte si elle traverse le plan z=0
if (b[2] >= 0 and nouvelle_position[2] <= 0) or \
   (b[2] <= 0 and nouvelle_position[2] >= 0):
    # Calcul de l'angle d'incidence
    angle = calcul_angle_incidence(vec)
    print(f"The incidence angle is:\n{angle:.2f} degrees")
else:
    print("The ball won't reach the paddle.")
```

### 5. Calcul de l'angle

```python
def calcul_angle_incidence(vec):
    norme_v = sqrt(vec[0]² + vec[1]² + vec[2]²)
    angle_rad = asin(abs(vec[2]) / norme_v)
    return degrees(angle_rad)
```

## Structure du code

```
101pong
├── Validation des arguments
├── Fonctions utilitaires
│   ├── init_vec()              # Calcul du vecteur vitesse
│   ├── format_vec()            # Formatage pour affichage
│   ├── norme()                 # Calcul de la norme
│   ├── calcul_position_apres_temps()  # Position future
│   └── calcul_angle_incidence() # Angle d'incidence
└── Programme principal
    ├── Parse des arguments
    ├── Calcul du vecteur vitesse
    ├── Calcul de la position
    └── Détection d'impact et angle
```

## Gestion d'erreurs

Le programme gère les erreurs suivantes :

| Erreur | Code retour | Message |
|--------|-------------|---------|
| Nombre d'arguments incorrect | 84 | Usage: ./101pong x0 y0 z0 x1 y1 z1 n |
| Arguments non numériques | 84 | Invalid arguments. Arguments must be numbers. |
| Temps négatif | 84 | Time shift must be a positive integer. |

## Tests

### Test de base

```bash
# Test simple
./101pong 0 0 5 1 1 4 3

# Test avec impact
./101pong 0 0 10 0 0 -2 5

# Test sans mouvement
./101pong 1 1 1 1 1 1 100
```

### Tests de validation

```bash
# Trop peu d'arguments
./101pong 0 0 0

# Arguments non numériques
./101pong a b c d e f g

# Temps négatif
./101pong 0 0 0 1 1 1 -5
```

## Bonus inclus

Le dossier `bonus/` contient des versions étendues :

### bonus2 (Visualisation Pygame)
Visualisation graphique de la trajectoire avec Pygame.

```bash
./bonus2 0 0 5 1 1 -1 10
```

### 101pong_2_bonusV3 (Visualisation 3D)
Visualisation 3D avec Matplotlib.

```bash
./101pong_2_bonusV3 0 0 5 2 2 -1 5
```

## Dépendances Python

### Version de base
- Python 3.x
- Module `math` (standard)
- Module `sys` (standard)

### Versions bonus
```bash
pip install pygame matplotlib numpy
```

## Mathématiques utilisées

- **Vecteurs 3D** : Représentation et calculs
- **Cinématique** : Mouvement rectiligne uniforme
- **Trigonométrie** : Calcul d'angles avec arcsin
- **Algèbre linéaire** : Norme de vecteurs

## Limitations

- Pas de prise en compte de la gravité (trajectoire linéaire)
- Pas de résistance de l'air
- Pas de rotation de la balle (effet Magnus)
- Plan de la batte toujours à z=0

## Extensions possibles

- [ ] Ajouter la gravité (trajectoire parabolique)
- [ ] Simuler la résistance de l'air
- [ ] Calculer le point d'impact exact sur le plan z=0
- [ ] Animation de la trajectoire
- [ ] Gestion de multiples balles

## Concepts démontrés

- Calculs vectoriels en 3D
- Physique cinématique
- Parsing d'arguments en Python
- Gestion d'erreurs robuste
- Formatage de sortie précis (2 décimales)

## Auteur

Enzo Pambout - Epitech

## Licence

Projet éducatif - Epitech
