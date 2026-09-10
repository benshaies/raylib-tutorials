#include <raylib.h> 

#define SCREEN_WIDTH 750
#define SCREEN_HEIGHT 750

Rectangle player = {300, 300, 50, 50};
Rectangle box = {500, 300, 75, 75};
Rectangle collisionRec;

void init(){

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tutorial");
  SetTargetFPS(60);

}

void update(){
  if(IsKeyDown(KEY_D)){
    player.x += 2.5;
  }
  else if(IsKeyDown(KEY_A)){
    player.x -= 2.5;
  }

  if(IsKeyDown(KEY_W)){
    player.y -= 2.5;
  }
  else if(IsKeyDown(KEY_S)){
    player.y += 2.5;
  }

  if(CheckCollisionRecs(player, box)){
    collisionRec = GetCollisionRec(player, box);
    
    // Vertical collision
    if(collisionRec.width > collisionRec.height){
      
      if(player.y < box.y){
        player.y -= collisionRec.height;
      }
      else{
        player.y += collisionRec.height;
      }
    }
    // Horizontal Colision
    else{
        
      if(player.x < box.x){
        player.x -= collisionRec.width;
      }
      else {
        player.x += collisionRec.width;
      }
    }
    
    

  }

}

void draw(){
  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawRectangleRec(player, BLUE);
  DrawRectangleRec(box, BROWN);

  if(CheckCollisionRecs(player, box)){
      DrawRectangleRec(collisionRec, RED);
  }

  EndDrawing();
}


int main(){

  init();

  while(!WindowShouldClose()){
   
    update();
    draw();
  }

  return 1;
}
