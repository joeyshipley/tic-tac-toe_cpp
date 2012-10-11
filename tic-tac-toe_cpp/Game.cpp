#include "Game.h"

Game::Game() {}

Game * Game::Build(vector<Cell> cells, string message)
{
    return Game::Build(cells, message, Rules::NONE);
}

Game * Game::Build(vector<Cell> cells, string message, string winner)
{
    Game * game = new Game();
    
    game->Message = message;
    game->Winner = winner;
    
    vector<Move> moves = vector<Move>(cells.size());
    for(int i = 0; i < cells.size(); i++)
        moves[i] = * DTO::BuildMove(cells[i]);
    game->Moves = moves;
    
    return game;
}