#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>


class Rook: virtual public Piece
{
 public:
  /* constructor */ 
  Rook(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  /* checks whether proposed move is legal according to Rook specific rules  */ 
  bool isValidMoveSpecific(std::string new_position) override;
  /* checks whether a proposed castling move is legal for the rook */ 
  bool isValidCastle(std::string new_position); 
};

#endif
