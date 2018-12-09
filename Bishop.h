#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>

class Bishop: virtual public Piece
{
 public:
  /* constructor */ 
  Bishop(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  /* checks whether proposed move is legal according to Bishop specific rules */ 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif
