#include "Engine.h"
#include <SDL.h>
#include <iostream>

using namespace std;

Engine::Engine()
{
  m_lTimer = 0;
}

void Engine::Process(int interval)
{
  unsigned int currentTime = SDL_GetTicks();
  
  if (currentTime - m_lTimer >= interval)
  {
    cout<<currentTime<<endl;
    m_lTimer = currentTime;
  }
}


