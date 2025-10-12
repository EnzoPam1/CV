# my_ls

Implémentation personnalisée de la commande Unix `ls` en C.

## Description

`my_ls` est une réimplémentation de la commande `ls` standard d'Unix qui liste les fichiers et répertoires d'un système de fichiers. Ce projet démontre la maîtrise des appels système, de la manipulation de répertoires et du formatage de sortie.

## Fonctionnalités

### Options supportées

- `-l` : Format long (affiche les permissions, propriétaire, taille, date)
- `-R` : Récursif (liste les sous-répertoires de manière récursive)
- `-a` : Affiche tous les fichiers (y compris les fichiers cachés commençant par `.`)
- `-r` : Inverse l'ordre du tri
- `-t` : Trie par date de modification (du plus récent au plus ancien)
- `-d` : Liste uniquement le répertoire lui-même, pas son contenu

### Options combinables

Les options peuvent être combinées, par exemple :
- `my_ls -la` : Liste tous les fichiers en format long
- `my_ls -lRt` : Liste récursive en format long, triée par date

## Compilation

```bash
make
```

Cela va :
1. Compiler la bibliothèque `libmy.a` dans `lib/my/`
2. Compiler tous les fichiers sources dans `src/`
3. Créer l'exécutable `my_ls`

### Autres commandes make

```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout (objets + exécutable)
make re         # Recompile tout depuis zéro
```

## Utilisation

### Exemples basiques

```bash
# Lister le répertoire courant
./my_ls

# Lister un répertoire spécifique
./my_ls /etc

# Lister avec format long
./my_ls -l

# Lister tous les fichiers (y compris cachés)
./my_ls -a

# Lister récursivement
./my_ls -R
```

### Exemples avancés

```bash
# Format long avec fichiers cachés, triés par date
./my_ls -lat

# Liste récursive en format long
./my_ls -lR /home

# Afficher uniquement les informations du répertoire
./my_ls -ld /etc
```

## Architecture

```
ls/
├── Makefile
├── include/
│   └── my.h              # Prototypes et structures
├── src/
│   ├── my_ls.c           # Point d'entrée et logique principale
│   ├── parse_args.c      # Parsing des arguments
│   ├── list_directory.c  # Listage de répertoire
│   ├── list_functions.c  # Fonctions de listage avancées
│   ├── file_details.c    # Affichage des détails de fichiers
│   └── sort_files.c      # Tri des fichiers
└── lib/my/
    └── (bibliothèque personnalisée)
```

## Structures de données

### t_options
Contient les flags d'options activées :
```c
typedef struct s_options {
    bool list_long;        // -l
    bool recursive;        // -R
    bool sort_time;        // -t
    bool reverse;          // -r
    bool all;              // -a
    bool directory_only;   // -d
    bool error_flag;       // Erreur détectée
} t_options;
```

## Appels système utilisés

- `opendir()` / `readdir()` / `closedir()` : Lecture de répertoires
- `stat()` / `lstat()` : Récupération des métadonnées de fichiers
- `getpwuid()` / `getgrgid()` : Récupération des noms d'utilisateur/groupe
- `scandir()` : Scan et tri de répertoires

## Code de retour

- `0` : Succès
- `84` : Erreur (arguments invalides ou accès refusé)

## Limites connues

- Les liens symboliques cassés peuvent provoquer des avertissements
- Le format long peut avoir des différences mineures avec `ls` GNU
- Pas de support pour toutes les options de GNU `ls` (seulement les principales)

## Tests

Pour tester la conformité avec `ls` standard :

```bash
# Comparer les sorties
./my_ls -l > my_output.txt
ls -l > ls_output.txt
diff my_output.txt ls_output.txt
```

## Auteur

Enzo Pambout - Epitech 2023

## Licence

Projet éducatif - Epitech
