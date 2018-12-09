#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <string>

class ChessBoard; 

class Knight: public Piece
{
 public:
  /* constructor */ 
  Knight(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  /* checks whether proposed move is legal according to Knight specific rules */ 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif
