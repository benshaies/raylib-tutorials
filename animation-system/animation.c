#include "animation.h"
#include <raylib.h>

Animation Animation_Init(Texture2D texture, int frameSize, int frameCount){
  Animation animation;

  animation.texture = texture;
  animation.frameCount = frameCount;
  animation.frameSize = frameSize;

  animation.timer = 0;
  animation.currentFrame = 0;

  return animation;
}

void Animation_Play(Animation *animation, Rectangle destination, bool facingRight, float speed){
  animation->timer += GetFrameTime();
  if(animation->timer >= speed){
    animation->currentFrame++;
    animation->timer = 0;

    if(animation->currentFrame >= animation->frameCount){
      animation->currentFrame = 0;
    }
  }
  
  int direction = 1;
  if(!facingRight){
    direction = -1;
  }


  Rectangle frameRec = {animation->currentFrame * animation->frameSize, 0, animation->frameSize * direction, animation->frameSize};

  DrawTexturePro(animation->texture, frameRec, destination, (Vector2){0,0}, 0.0f, WHITE);
}
