#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"
#include <string>

class Queen: public Rook,  public Bishop
{
 public: 
  /* constructor */ 
  Queen(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  /* checks whether a proposed move is legal according to Queen specific rules */ 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif
