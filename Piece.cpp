#include <string>
#include "Piece.h"
#include "ChessBoard.h"

using namespace std;

Piece::Piece(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
{
  colour = passed_colour;
  position = passed_position;
  board_ptr = passed_board_ptr; 
}

bool Piece::makeMove(std::string new_position)
{
  if (!isValidMove(new_position))
    return false;

  position = new_position;

  return true;
}

bool Piece::isValidMove(std::string new_position)
{
  char rank;
  int file;
  Piece* test_ptr;

  rank = new_position[0];
  file = new_position[1] - '0';

  if (!(rank >= 65 && rank < 73))
    return false;

  if (!(file >= 1 && file < 9))
    return false;

  test_ptr =  board_ptr->getCell(new_position);
  if (test_ptr != nullptr)
    {
      if (test_ptr->getColour() == getColour())
	return false;
    }

  if (new_position == position)
    return false; 

  /* REALLY NOT SURE WHY I DID THIS. CHECK LATER */ 
  if (rank == file)
    return false;
  
  if (!isValidMoveSpecific(new_position))
    return false;

  return true; 

  
}

char Piece::getSymbol()
{
  return symbol; 
};

int Piece::getColour()
{
  return colour;
}

void Piece::setPosition(std::string new_position)
{
  position = new_position;
}
 
