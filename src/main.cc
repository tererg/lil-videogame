#include<iostream>

#include "Game.hh"




int main()
{
  
  Game* game{new Game()};
  game->Init();

  delete game;
  return EXIT_SUCCESS;
}