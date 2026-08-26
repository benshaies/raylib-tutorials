#ifndef ANIMATION_H
#define ANIMATION_H

#include <raylib.h>
typedef struct{
  Texture2D texture;
  float timer;
  int frameSize;
  int frameCount;
  int currentFrame;
}Animation;

Animation Animation_Init(Texture2D texture, int frameSize, int frameCount);

void Animation_Play(Animation *animation, Rectangle destination, bool facingRight, float speed);

#endif // !ANIMATION_H
