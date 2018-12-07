#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>


class Rook: virtual public Piece
{
 public:
  Rook(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool isValidMoveSpecific(std::string new_position) override;
  bool isValidCastle(std::string new_position); 
};

#endif
