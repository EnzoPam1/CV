# my_printf

Réimplémentation complète de la fonction `printf` de la bibliothèque standard C.

## Description

`my_printf` est une implémentation personnalisée de la fonction printf qui gère le formatage et l'affichage de données. Ce projet démontre la compréhension des fonctions variadiques, du parsing de chaînes et de la manipulation de types en C.

## Fonctionnalités

### Spécificateurs de format supportés

| Spécificateur | Type | Description |
|---------------|------|-------------|
| `%c` | char | Affiche un caractère |
| `%s` | char* | Affiche une chaîne de caractères |
| `%d` | int | Affiche un entier décimal signé |
| `%i` | int | Affiche un entier décimal signé (identique à %d) |
| `%u` | unsigned int | Affiche un entier décimal non signé |
| `%o` | unsigned int | Affiche un entier en octal |
| `%x` | unsigned int | Affiche un entier en hexadécimal (minuscules) |
| `%X` | unsigned int | Affiche un entier en hexadécimal (majuscules) |
| `%p` | void* | Affiche une adresse mémoire |
| `%%` | - | Affiche le caractère % |
| `%b` | unsigned int | **BONUS** : Affiche un entier en binaire |

## Compilation

```bash
make
```

La compilation crée l'exécutable avec la fonction `my_printf` prête à être utilisée.

### Autres commandes make

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout (objets + exécutable)
make re         # Recompile tout depuis zéro
```

## Utilisation

### Exemples basiques

```c
#include "my.h"

int main(void)
{
    // Affichage simple
    my_printf("Hello, World!\n");

    // Affichage d'un caractère
    my_printf("Caractère: %c\n", 'A');

    // Affichage d'une chaîne
    my_printf("Nom: %s\n", "Enzo");

    // Affichage d'entiers
    my_printf("Nombre: %d\n", 42);
    my_printf("Négatif: %d\n", -123);

    return 0;
}
```

### Exemples avancés

```c
#include "my.h"

int main(void)
{
    int number = 255;
    void *ptr = &number;

    // Différentes bases
    my_printf("Décimal: %d\n", number);      // 255
    my_printf("Hexadécimal: %x\n", number);  // ff
    my_printf("Hexadécimal: %X\n", number);  // FF
    my_printf("Octal: %o\n", number);        // 377
    my_printf("Binaire: %b\n", number);      // 11111111 (bonus)

    // Adresse mémoire
    my_printf("Adresse: %p\n", ptr);

    // Non signé
    my_printf("Non signé: %u\n", 4294967295);

    // Échapper le %
    my_printf("Pourcentage: 100%%\n");

    return 0;
}
```

## Architecture

```
printf/
├── Makefile
├── include/
│   └── my.h                    # Prototypes et définitions
└── src/
    ├── my_printf.c             # Fonction principale
    ├── handlers.c              # Dispatch des spécificateurs
    ├── process_functions.c     # Handlers de formats (partie 1)
    ├── process_functions_two.c # Handlers de formats (partie 2)
    ├── base_converters.c       # Conversions de base
    ├── my_put_nbr.c           # Affichage d'entiers
    ├── my_put_hex.c           # Affichage hexadécimal
    ├── my_put_octal.c         # Affichage octal
    ├── my_put_unsigned_nbr.c  # Affichage non signé
    ├── my_putchar.c           # Affichage d'un caractère
    └── my_putstr.c            # Affichage d'une chaîne
```

## Structure de données

### specifiers_t
Tableau associatif liant chaque spécificateur à sa fonction de traitement :

```c
typedef struct {
    char specifier;                    // Le caractère du spécificateur
    int (*func)(va_list *args);        // Fonction de traitement
} specifiers_t;
```

## Implémentation technique

### Fonctions variadiques

Le projet utilise `<stdarg.h>` pour gérer un nombre variable d'arguments :

```c
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    // Traitement...
    va_end(args);
}
```

### Architecture modulaire

Chaque spécificateur de format a sa propre fonction de traitement, facilitant :
- L'ajout de nouveaux formats
- Le débogage
- La maintenabilité

### Gestion des bases numériques

Conversions supportées :
- Base 2 (binaire) : `%b` (bonus)
- Base 8 (octal) : `%o`
- Base 10 (décimal) : `%d`, `%i`, `%u`
- Base 16 (hexadécimal) : `%x`, `%X`

## Valeur de retour

La fonction retourne le nombre de caractères affichés (comme printf standard).

```c
int count = my_printf("Test: %d\n", 42);
// count = 9 (caractères affichés)
```

## Comparaison avec printf standard

### Fonctionnalités identiques
- ✅ Tous les spécificateurs de base
- ✅ Gestion des caractères spéciaux
- ✅ Retour du nombre de caractères affichés

### Différences
- ❌ Pas de gestion des flags (-, +, 0, #, espace)
- ❌ Pas de gestion de la largeur de champ (%10d)
- ❌ Pas de gestion de la précision (%.2f)
- ❌ Pas de support des flottants (%f, %e, %g)
- ✅ Bonus : support du binaire (%b)

## Tests

### Test de base

```c
#include "my.h"

int main(void)
{
    // Test tous les spécificateurs
    my_printf("Char: %c\n", 'X');
    my_printf("String: %s\n", "Hello");
    my_printf("Int: %d\n", -42);
    my_printf("Unsigned: %u\n", 42);
    my_printf("Octal: %o\n", 64);
    my_printf("Hex low: %x\n", 255);
    my_printf("Hex up: %X\n", 255);
    my_printf("Binary: %b\n", 15);
    my_printf("Percent: %%\n");

    return 0;
}
```

### Compilation et test

```bash
make
gcc main.c -L. -I include -o test_printf
./test_printf
```

## Cas limites gérés

- Chaînes NULL : Comportement défini (peut crasher ou afficher "(null)")
- Entiers négatifs en bases non décimales
- Adresses NULL pour `%p`
- Valeurs maximales/minimales d'entiers

## Auteur

Enzo Pambout - Epitech 2023

## Licence

Projet éducatif - Epitech
