#ifndef PARTICLES_H
#define PARTICLES_H

#include <raylib.h>

#define MAX_PARTICLES 1024

typedef struct{
  Vector2 pos;
  bool active;
  float life;
  Color color;
  Vector2 velocity;
  float size;
}Particle;

typedef struct{
  Particle pool[MAX_PARTICLES];
}ParticleSystem;

void ParticleSystemSpawn(ParticleSystem *ps, Vector2 pos, float life, Color color, Vector2 velocity, float size);

void ParticleSystemUpdate(ParticleSystem *ps);

void ParticleSystemDraw(ParticleSystem ps);


#endif // !PARTICLES_H
