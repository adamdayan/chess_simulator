#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <string>

class ChessBoard; 

class Knight: public Piece
{
 public:
  Knight(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif
