#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Game.h"

using namespace std;



SDL_Texture* m_pTexture;
SDL_Rect m_sourceectangle;
SDL_Rect m_destinationRectangle;


int main()
{
    
  Game* gGame;
  gGame = new Game();
  gGame->init();
  
  SDL_Surface* pTempSurface  = SDL_LoadBMP("../assets/animate2.bmp");
  
  if (pTempSurface == NULL)
  {
    cout<<"Cant load pucture"<<endl;
  }
  int colorkey = SDL_MapRGB(pTempSurface->format,0,0,0);
  SDL_SetColorKey(pTempSurface, SDL_TRUE,colorkey );
  m_pTexture = SDL_CreateTextureFromSurface(gGame->ReturnRenderer(), pTempSurface);
      if (m_pTexture == NULL)
  {
    cout<<"m_pTexture cant load"<<endl;
  }
 
    SDL_FreeSurface(pTempSurface);
 // SDL_QueryTexture(m_pTexture,NULL,NULL,&m_sourceectangle.w,&m_sourceectangle.h);
  
  m_destinationRectangle.x = m_sourceectangle.x = 0;
  m_destinationRectangle.y = m_sourceectangle.y = 0;
  m_destinationRectangle.w =128;
  m_sourceectangle.w = 128;
  m_destinationRectangle.h = 82;
  m_sourceectangle.h = 82;
  
  
  

  
  while(gGame->ReturnRunning())
  {
    gGame->handleEvents();
    gGame->update( m_sourceectangle,m_destinationRectangle );
    gGame->render(m_pTexture, m_sourceectangle,m_destinationRectangle );
   
  }

  gGame->clean();
  
 
  
  return 0;
  
}