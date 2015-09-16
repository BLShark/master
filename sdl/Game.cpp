/*
 * Author: Stanislav Todorov
 */

#include "Game.h"
#include <SDL.h>
#include <iostream>
#include <SDL_video.h>

using namespace std;

Game::Game()
{
  m_bRunning = false;
  m_pWindow = 0;
  m_pRender = 0;
  timer = 0;
  counter =0;
}

Game::~Game()
{

}


bool Game::init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0 )
  {
    m_pWindow = SDL_CreateWindow("Stanislav",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800,600,
    0);
  
  
      if (m_pWindow != 0)
      {
	  m_pRender = SDL_CreateRenderer(m_pWindow, -1,0 );
	  if (m_pRender != 0)
	  {
	    SDL_SetRenderDrawColor(m_pRender, 255, 255,255,255);
	  }
	  else
	  {
	    std::cout<<"m_pRender init fail"<<std::endl;
	    return false;
	  }
      }
      else
      {
	std::cout<<"window fail"<<std::endl;
	return false;
      }
  }
  else
  {
    std::cout<<"SDL init fail"<<std::endl;
    return false;
  }
  
  std::cout<<"init sucess"<<std::endl;
  m_bRunning = true;
  
  return true;
  
}

void Game::render(SDL_Texture* m_pTexture, SDL_Rect& m_sourceectangle, SDL_Rect& m_destinationRectangle)
{
  SDL_SetRenderDrawColor(m_pRender, 255,255,255,255);
  SDL_RenderClear(m_pRender);
  //SDL_RenderCopy(m_pRender, m_pTexture, &m_sourceectangle, &m_destinationRectangle);
  int x=0;
  int y=0;
  SDL_GetWindowSize(m_pWindow, &x ,&y);
  

 long timeStamp = (SDL_GetTicks());
 cout<<timeStamp<<endl;
   if (timeStamp - timer >= 200)
   {
    SDL_RenderCopyEx(m_pRender, m_pTexture,&m_sourceectangle, &m_destinationRectangle,0,0,SDL_FLIP_NONE);
    timer=timeStamp;
    counter++
   }
 
    
  
  
     
    
  SDL_RenderPresent(m_pRender);
  

}


void Game::clean()
{
  SDL_DestroyRenderer(m_pRender);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
	m_bRunning = false;break;
	
      default: break;
    }
  }
}

void Game::update(SDL_Rect& m_sourceectangle, SDL_Rect& m_destinationRectangle)
{
  
  m_sourceectangle.x = 128 * int(((SDL_GetTicks()/200) % 6));
 // m_destinationRectangle.x = m_sourceectangle.x;
 
}


