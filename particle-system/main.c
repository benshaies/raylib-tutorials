#include <raylib.h>
#include "particles.h"
#include <math.h>

ParticleSystem ps;

void update(){
  
 if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    Vector2 m = GetMousePosition();

    // Big orange embers: the body of the trail
    for (int i = 0; i < 2; i++) {
        ParticleSystemSpawn(
            &ps, m,
            GetRandomValue(4, 8),
            (Color){255, 60, 0, 255},
            (Vector2){GetRandomValue(-4, 4), GetRandomValue(-8, -3)},
            GetRandomValue(4, 8)
        );
    }

    // Medium amber: fills the gaps and adds warmth
    ParticleSystemSpawn(
        &ps, m,
        GetRandomValue(3, 5),
        (Color){255, 140, 0, 255},
        (Vector2){GetRandomValue(-3, 3), GetRandomValue(-9, -4)},
        GetRandomValue(3, 6)
    );

    // Small yellow sparks: bright and fast
    ParticleSystemSpawn(
        &ps, m,
        GetRandomValue(2, 3),
        (Color){255, 220, 40, 255},
        (Vector2){GetRandomValue(-3, 3), GetRandomValue(-11, -5)},
        GetRandomValue(2, 5)
    );
} 
  


 ParticleSystemUpdate(&ps); 
}

void draw(){
  ClearBackground(BLACK);

  BeginDrawing();

  ParticleSystemDraw(ps);


  EndDrawing();
}

int main(){
  InitWindow(1280, 720, "Particle System Tutorial");
  SetTargetFPS(60);

  while(!WindowShouldClose()){
    update();
    draw();
  }
}
