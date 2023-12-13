/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** game
*/

#include <SFML/Graphics.h>

#ifndef GAME_H_
    #define GAME_H_

typedef enum {
    EASY, MEDIUM, HARD
} Difficulty;

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

int initialize_game(Game *game);
void game_loop(Game *game);
void cleanup_game(Game *game);

#endif /* !GAME_H_ */
