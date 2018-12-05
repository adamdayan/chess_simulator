#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>

class Bishop: virtual public Piece
{
 public:
  Bishop(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif
