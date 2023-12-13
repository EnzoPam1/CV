/*
** EPITECH PROJECT, 2023
** templatemain
** File description:
** templatemain
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../include/game.h"
#include "../include/events.h"
#include "../include/graphics.h"
#include "../include/duck.h"
#include "../include/animation.h"
#include "../include/init.h"
#include "../include/cleanup.h"
#include "../include/endscreen.h"
#include "../include/text_utils.h"
#include "../include/duck_init.h"
#include "../include/my.h"

void display_help(void)
{
    my_putstr("My Hunter Game\n");
    my_putstr("Description: Un jeu de tir où le joueur doit abattre des"
                " canards.\n");
    my_putstr("Au bout de trois canards loupés, vous perdez.\n");
    my_putstr("Si vous touchez un canard, vous obtenez de nouveau trois"
                " chances pour toucher un canard.\n");
    my_putstr("Arriverez-vous à finir les 20 niveaux ?\n");
    my_putstr("Commandes:\n");
    my_putstr("  - Clic gauche de la souris : Tirer sur un canard.\n");
    my_putstr("  - Échap : Quitter le jeu.\n\n");
    my_putstr("Jeu réalisé par Enzo Pambout.\n");
}

int main(int argc, char *argv[])
{
    Game game;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            display_help();
            return 0;
        }
    }
    if (!initialize_game(&game)) {
        my_putstr("Erreur lors de l'initialisation du jeu.\n");
        return 84;
    }
    game_loop(&game);
    cleanup_game(&game);
    return 0;
}
