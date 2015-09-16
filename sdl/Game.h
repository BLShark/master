/*
 * Author: Stanislav Todorov
 */

#ifndef GAME_H
#define GAME_H
#include <SDL.h>


class Game
{
  
private:
  int counter;
  long timer;
  bool m_bRunning;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRender;
//   SDL_Rect m_sourceectangle;
//   SDL_Rect m_destinationRectangle;
  
public:
Game();
~Game();

   bool init();
   void render(SDL_Texture* m_pTexture, SDL_Rect& m_sourceectangle, SDL_Rect& m_destinationRectangle);
   void handleEvents();
   void clean();
   void update(SDL_Rect& m_sourceectangle,SDL_Rect& m_destinationRectangle);
   bool ReturnRunning(){
     return m_bRunning;
  }
  SDL_Renderer* ReturnRenderer()
  {
    return m_pRender;
  }

};

#endif // GAME_H
