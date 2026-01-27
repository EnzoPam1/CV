# Raytracer

Moteur de rendu 3D en C++ utilisant la technique du ray tracing.
Le programme prend en entree un fichier de scene (`.cfg`) et genere une image au format PPM.

## Compilation

Dependances : `libconfig++`

```bash
make
```

## Utilisation

```bash
./raytracer <SCENE_FILE>
```

Exemple :

```bash
./raytracer scenes/basic_spheres.cfg > output.ppm
```

## Fonctionnalites

### Primitives
- Sphere
- Plan
- Cylindre
- Cone

### Transformations
- Translation
- Rotation (X, Y, Z)
- Scale

### Lumieres
- Lumiere ambiante
- Lumiere directionnelle
- Ombres portees

### Materiaux
- Couleur diffuse (flat color)

### Configuration de scene
- Camera configurable (position, rotation, FOV, resolution)
- Ajout de primitives avec position, couleur et transformations
- Configuration des lumieres (ambiante + directionnelle)

## Format de scene

Les scenes utilisent le format `libconfig++` :

```
camera:
{
    resolution = { width = 800; height = 600; };
    position = { x = 0; y = -100; z = 20; };
    fieldOfView = 72.0;
};

primitives:
{
    spheres = (
        { x = 60; y = 5; z = 40; r = 25;
          color = { r = 255; g = 64; b = 64; }; }
    );
    planes = (
        { axis = "Z"; position = -20;
          color = { r = 64; g = 64; b = 255; }; }
    );
};

lights:
{
    ambient = 0.4;
    diffuse = 0.6;
    directional = (
        { x = 1.0; y = -1.0; z = -1.0; }
    );
};
```

## Architecture

Le projet suit une architecture modulaire avec interfaces (`IPrimitive`, `ILight`) et utilise le pattern Factory pour la creation des primitives.

```
src/
├── main.cpp
├── Math/           # Point3D, Vector3D
└── RayTracer/
    ├── Camera, Ray, Scene, SceneParser
    ├── Interfaces/  # IPrimitive, ILight
    ├── Primitives/  # Sphere, Plane, Cylinder, Cone
    ├── Lights/      # AmbientLight, DirectionalLight
    ├── Factories/   # PrimitiveFactory
    └── Utils/       # Color
```

## Exemples de rendus

Les scenes de demonstration et leurs rendus sont dans `scenes/` et `screenshots/`.
