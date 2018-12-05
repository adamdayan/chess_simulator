#ifndef PAWN_H
#define PAWN_H

#include <string>
#include "Piece.h"

class Pawn: public Piece
{
 public:
  Pawn(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif


