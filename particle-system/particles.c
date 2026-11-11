#include "particles.h"
#include <raylib.h>

void ParticleSystemSpawn(ParticleSystem *ps, Vector2 pos, float life, Color color, Vector2 velocity, float size){

  for(int i = 0; i < MAX_PARTICLES; i++){
    if(!ps->pool[i].active){

      ps->pool[i] = (Particle){
        .pos = pos,
        .life = life,
        .color = color,
        .size = size,
        .velocity = velocity,
        .active = true,
      };
      return;
    }
  }
}

void ParticleSystemUpdate(ParticleSystem *ps){

  for(int i = 0; i < MAX_PARTICLES; i++){

    if(!ps->pool[i].active){
      continue;
    }

    ps->pool[i].pos.x += ps->pool[i].velocity.x;
    ps->pool[i].pos.y += ps->pool[i].velocity.y;

    ps->pool[i].velocity.x *= 0.95f;
    ps->pool[i].velocity.y *= 0.95f;

    ps->pool[i].life -= GetFrameTime();

    if(ps->pool[i].life <= 0.0f){
      ps->pool[i].active = false;
    }
  }
}

void ParticleSystemDraw(ParticleSystem ps){
  for(int i = 0; i < MAX_PARTICLES; i++){
    if(!ps.pool[i].active)
      continue;

    DrawCircleV(ps.pool[i].pos, ps.pool[i].size, ps.pool[i].color);
  }
}
