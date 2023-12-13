/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** game
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

int initialize_game(Game *game)
{
    if (!init_font(game) || !init_window(game) || !init_cursor(game) ||
        !init_clock(game) || !init_background(game)) {
        return 0;
    }
    game->level = 1;
    game->missedDucks = 0;
    game->score = 0;
    game->difficulty = EASY;
    game->video_mode = (sfVideoMode){800, 600, 32};
    initialize_graphics(game);
    initialize_ducks(game);
    return 1;
}

static void update_game_state(Game *game)
{
    game->deltaTime = sfTime_asSeconds(sfClock_restart(game->clock));
    handle_events(game);
    update_ducks(game);
    update_animation(game);
}

static void render_game(Game *game)
{
    sfVector2i pixelPos;
    sfVector2f worldPos;

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->backgroundSprite, NULL);
    draw_ducks(game);
    draw_score(game);
    draw_level(game);
    pixelPos = sfMouse_getPositionRenderWindow(game->window);
    worldPos = sfRenderWindow_mapPixelToCoords(game->window, pixelPos,
        sfRenderWindow_getView(game->window));
    sfSprite_setPosition(game->cursorSprite, worldPos);
    sfRenderWindow_drawSprite(game->window, game->cursorSprite, NULL);
    sfRenderWindow_display(game->window);
}

void game_loop(Game *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        update_game_state(game);
        render_game(game);
    }
}

void cleanup_game(Game *game)
{
    cleanup_clock(game);
    cleanup_window(game);
    cleanup_font(game);
    cleanup_background(game);
    cleanup_cursor(game);
}
