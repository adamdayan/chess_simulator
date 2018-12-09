#ifndef PAWN_H
#define PAWN_H

#include <string>
#include "Piece.h"

class Pawn: public Piece
{
 public:
  /* constructor */ 
  Pawn(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  /* checks whether a proposed move is legal according to Pawn specific rules */ 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif


