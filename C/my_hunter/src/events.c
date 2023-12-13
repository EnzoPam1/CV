/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** events
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

static void update_view(Game *game, unsigned int width, unsigned int height)
{
    sfView *view;

    view = sfView_createFromRect((sfFloatRect){0, 0, (float)width,
        (float)height});
    sfRenderWindow_setView(game->window, view);
    sfView_destroy(view);
}

void handle_key_event(Game *game, sfKeyEvent keyEvent)
{
    if (keyEvent.code == sfKeyEscape) {
        sfRenderWindow_close(game->window);
    }
}

void handle_mouse_or_resize_event(Game *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button ==
        sfMouseLeft) {
        check_duck_shot(game, event.mouseButton.x, event.mouseButton.y);
    } else if (event.type == sfEvtResized) {
        update_view(game, event.size.width, event.size.height);
    }
}

void handle_other_event(Game *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        handle_key_event(game, event.key);
    } else if (event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtResized) {
        handle_mouse_or_resize_event(game, event);
    }
}

void handle_events(Game *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        } else {
            handle_other_event(game, event);
        }
    }
}

void check_duck_shot(Game *game, int mouse_x, int mouse_y)
{
    sfVector2f mouse;
    sfFloatRect bounds;

    mouse = (sfVector2f){mouse_x, mouse_y};
    bounds = sfSprite_getGlobalBounds(game->duck.sprite);
    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) &&
        !game->duck.isShot) {
        game->duck.isShot = sfTrue;
        game->score += 10;
        game->totalDucksShot++;
        if (game->totalDucksShot % 5 == 0)
            game->level++;
        game->missedDucks = 0;
        if (game->level > 20)
            display_victory_screen(game);
    }
}
