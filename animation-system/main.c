#include <raylib.h>
#include <stdbool.h>
#include "animation.h"

#define SCREEN_WIDTH 750
#define SCREEN_HEIGHT 750

Texture2D playerIdleTexture;
Texture2D enemyTexture;

Animation playerAnim;
Animation enemyAnim;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Animation System");
  SetTargetFPS(60);

  playerIdleTexture = LoadTexture("../playerIdle.png");
  enemyTexture = LoadTexture("../enemy2Run.png");

  playerAnim = Animation_Init(playerIdleTexture, 16, 4);
  enemyAnim = Animation_Init(enemyTexture, 16, 8);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    
    Animation_Play(&playerAnim, (Rectangle){300, 300, 150, 150}, true, 0.15f);

    Animation_Play(&enemyAnim, (Rectangle){300, 500, 100, 100}, false, 0.075f);

    EndDrawing();
  }
}
