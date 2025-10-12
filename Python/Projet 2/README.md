# 102architect - Transformations géométriques 2D

Application de transformations géométriques (translation, rotation, mise à l'échelle, réflexion) sur des points en 2D.

## Description

Ce projet implémente les transformations géométriques classiques en utilisant des matrices de transformation homogènes. Il permet d'appliquer une ou plusieurs transformations à un point et calcule la matrice de transformation composée résultante.

## Fonctionnalités

- 🔄 **Transformation par translation** : Déplacer un point
- 📐 **Transformation par rotation** : Tourner un point autour de l'origine
- 📏 **Transformation par mise à l'échelle** : Agrandir/réduire
- 🪞 **Transformation par réflexion** : Symétrie axiale
- 🔗 **Composition de transformations** : Enchaîner plusieurs transformations
- 🧮 **Calcul matriciel** : Affichage des matrices de transformation
- ✅ **Validation complète** : Gestion d'erreurs robuste

## Mathématiques - Coordonnées homogènes

Les transformations 2D sont représentées par des matrices 3×3 en coordonnées homogènes :

```
Point : (x, y, 1)

Matrice générale :
⎡ a  b  c ⎤
⎢ d  e  f ⎥
⎣ 0  0  1 ⎦
```

Cette représentation permet de combiner toutes les transformations (translation, rotation, etc.) par simple multiplication matricielle.

## Transformations supportées

### 1. Translation `-t dx dy`

Déplace un point de `dx` unités sur l'axe X et `dy` unités sur l'axe Y.

**Matrice de translation :**
```
⎡ 1  0  dx ⎤
⎢ 0  1  dy ⎥
⎣ 0  0  1  ⎦
```

**Effet :**
```
(x, y) → (x + dx, y + dy)
```

### 2. Mise à l'échelle `-z sx sy`

Multiplie les coordonnées par les facteurs `sx` et `sy`.

**Matrice de scaling :**
```
⎡ sx  0  0 ⎤
⎢ 0  sy  0 ⎥
⎣ 0   0  1 ⎦
```

**Effet :**
```
(x, y) → (sx × x, sy × y)
```

### 3. Rotation `-r theta`

Tourne le point de `theta` degrés autour de l'origine (sens anti-horaire).

**Matrice de rotation :**
```
⎡ cos(θ)  -sin(θ)  0 ⎤
⎢ sin(θ)   cos(θ)  0 ⎥
⎣   0        0     1 ⎦
```

**Effet :**
```
(x, y) → (x×cos(θ) - y×sin(θ), x×sin(θ) + y×cos(θ))
```

### 4. Réflexion `-s phi`

Symétrie par rapport à un axe d'inclinaison `phi` degrés.

**Matrice de réflexion :**
```
⎡ cos(2φ)   sin(2φ)  0 ⎤
⎢ sin(2φ)  -cos(2φ)  0 ⎥
⎣    0         0     1 ⎦
```

## Utilisation

### Afficher l'aide

```bash
./102architect -h
```

Affiche :
```
Usage: ./102architect x0 y0 [transformations]
Transformations:
 -t dx dy   Translation along vector (dx, dy)
 -z sx sy   Scaling by factors sx and sy
 -r theta   Rotation by a theta degree angle
 -s phi     Reflection over an axis with an inclination angle of phi degrees
 -h         Display this help message
```

### Syntaxe

```bash
./102architect x0 y0 [transformation1] [transformation2] ...
```

- `x0 y0` : Coordonnées du point initial
- Transformations : Une ou plusieurs transformations à appliquer

## Exemples

### Exemple 1 : Translation simple

```bash
$ ./102architect 1 2 -t 3 4

Translation along vector (3, 4)
1.00 0.00 3.00
0.00 1.00 4.00
0.00 0.00 1.00
(1.00, 2.00) => (4.00, 6.00)
```

Point (1, 2) déplacé de (3, 4) = (4, 6)

### Exemple 2 : Rotation de 90°

```bash
$ ./102architect 1 0 -r 90

Rotation by a 90 degree angle
0.00 -1.00 0.00
1.00 0.00 0.00
0.00 0.00 1.00
(1.00, 0.00) => (0.00, 1.00)
```

Point (1, 0) tourné de 90° = (0, 1)

### Exemple 3 : Mise à l'échelle

```bash
$ ./102architect 2 3 -z 2 3

Scaling by factors 2 and 3
2.00 0.00 0.00
0.00 3.00 0.00
0.00 0.00 1.00
(2.00, 3.00) => (4.00, 9.00)
```

Point (2, 3) × (2, 3) = (4, 9)

### Exemple 4 : Réflexion horizontale

```bash
$ ./102architect 5 3 -s 0

Reflection over an axis with an inclination angle of 0 degrees
1.00 0.00 0.00
0.00 -1.00 0.00
0.00 0.00 1.00
(5.00, 3.00) => (5.00, -3.00)
```

Symétrie par rapport à l'axe X : y devient -y

### Exemple 5 : Composition de transformations

```bash
$ ./102architect 1 0 -t 1 0 -r 90 -z 2 2

Translation along vector (1, 0)
1.00 0.00 1.00
0.00 1.00 0.00
0.00 0.00 1.00
Rotation by a 90 degree angle
0.00 -1.00 1.00
1.00 0.00 0.00
0.00 0.00 1.00
Scaling by factors 2 and 2
0.00 -2.00 2.00
2.00 0.00 0.00
0.00 0.00 1.00
(1.00, 0.00) => (2.00, 4.00)
```

1. Translation : (1, 0) → (2, 0)
2. Rotation 90° : (2, 0) → (0, 2)
3. Scale ×2 : (0, 2) → (0, 4)

**Note importante** : Les transformations sont appliquées de gauche à droite !

## Ordre des transformations

⚠️ **L'ordre est crucial !**

Les transformations ne sont **pas commutatives**.

```bash
# Translation puis rotation ≠ Rotation puis translation

$ ./102architect 1 0 -t 1 0 -r 90
(1.00, 0.00) => (0.00, 2.00)

$ ./102architect 1 0 -r 90 -t 1 0
(1.00, 0.00) => (1.00, 1.00)
```

Résultats différents ! La composition matricielle se fait dans l'ordre spécifié.

## Algorithme

### 1. Parsing des arguments

```python
if len(sys.argv) < 5:
    print("Usage: ./102architect x0 y0 [transformations]")
    sys.exit(84)

x0, y0 = float(sys.argv[1]), float(sys.argv[2])
transformations = sys.argv[3:]
```

### 2. Création des matrices

```python
def translation_matrix(dx, dy):
    return [[1, 0, dx], [0, 1, dy], [0, 0, 1]]

def rotation_matrix(theta):
    rad = math.radians(theta)
    return [[cos(rad), -sin(rad), 0],
            [sin(rad),  cos(rad), 0],
            [0, 0, 1]]

def scaling_matrix(sx, sy):
    return [[sx, 0, 0], [0, sy, 0], [0, 0, 1]]

def reflection_matrix(phi):
    rad = math.radians(phi)
    return [[cos(2*rad),  sin(2*rad), 0],
            [sin(2*rad), -cos(2*rad), 0],
            [0, 0, 1]]
```

### 3. Multiplication matricielle

```python
def multiply_matrices(m1, m2):
    result = [[sum(a*b for a, b in zip(row, col))
               for col in zip(*m2)]
              for row in m1]
    return result
```

### 4. Composition

```python
final_matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]  # Matrice identité

for each transformation:
    matrix = create_transformation_matrix(params)
    final_matrix = multiply_matrices(matrix, final_matrix)
```

### 5. Application au point

```python
def apply_transformation(matrix, point):
    result = multiply_matrices(matrix, [[x], [y], [1]])
    return [result[0][0], result[1][0]]
```

## Structure du code

```
102architect
├── print_help()              # Affichage aide
├── homogeneous_vector()      # Conversion point → vecteur homogène
├── Matrices de transformation
│   ├── translation_matrix()
│   ├── scaling_matrix()
│   ├── rotation_matrix()
│   └── reflection_matrix()
├── multiply_matrices()       # Produit matriciel
├── apply_transformation()    # Applique matrice à point
├── Utilitaires
│   ├── clean_float()        # Nettoyage valeurs proches de 0
│   ├── format_number()      # Formatage 2 décimales
│   └── print_matrix()       # Affichage matrice
└── main()                   # Programme principal
```

## Gestion d'erreurs

| Erreur | Code retour | Message |
|--------|-------------|---------|
| Arguments insuffisants | 84 | Usage: ./102architect x0 y0 [transformations] |
| Coordonnées invalides | 84 | Invalid coordinates: x0 and y0 must be numbers |
| Paramètres transformation invalides | 84 | Invalid arguments for transformation |
| Transformation inconnue | 84 | Unknown transformation: <type> |

## Nettoyage numérique

Le programme nettoie les valeurs très proches de 0 pour éviter les imprécisions flottantes :

```python
def clean_float(num):
    if abs(num) < 1e-10:
        return 0.0
    return num
```

Exemple : `-0.0000000001` devient `0.00`

## Tests

### Test de translation

```bash
./102architect 0 0 -t 5 3
# Attendu : (0, 0) => (5, 3)
```

### Test de rotation

```bash
./102architect 1 0 -r 180
# Attendu : (1, 0) => (-1, 0)
```

### Test de scaling

```bash
./102architect 2 2 -z 0.5 0.5
# Attendu : (2, 2) => (1, 1)
```

### Test de composition complexe

```bash
./102architect 1 1 -t 1 1 -r 45 -z 2 2 -s 0
# Composition de 4 transformations
```

## Applications pratiques

### Graphisme 2D
- Déplacement d'objets
- Rotation de sprites
- Zoom/dézoom
- Effets miroir

### CAO (Conception Assistée par Ordinateur)
- Transformation de formes
- Alignement d'objets
- Opérations symétriques

### Robotique
- Changements de repères
- Calcul de positions
- Planification de trajectoires

### Vision par ordinateur
- Rectification d'images
- Calibration de caméras
- Détection de motifs

## Concepts mathématiques démontrés

- ✅ Matrices de transformation homogènes
- ✅ Multiplication matricielle
- ✅ Composition de transformations
- ✅ Trigonométrie (sin, cos)
- ✅ Conversion degrés ↔ radians
- ✅ Algèbre linéaire

## Extensions possibles

- [ ] Transformations 3D (matrices 4×4)
- [ ] Transformation inverse
- [ ] Décomposition de matrices
- [ ] Interpolation de transformations
- [ ] Visualisation graphique des transformations
- [ ] Export vers formats standards (SVG, etc.)

## Dépendances Python

- Python 3.x
- Module `math` (standard)
- Module `sys` (standard)

Aucune dépendance externe requise !

## Précision numérique

Le programme formate tous les nombres avec 2 décimales :

```python
def format_number(num):
    return f"{clean_float(num):.2f}"
```

## Bonus

Le dossier `bonus/` pourrait contenir :
- Visualisation graphique avec Matplotlib
- Animation des transformations
- Interface interactive

## Auteur

Enzo Pambout - Epitech

## Licence

Projet éducatif - Epitech
