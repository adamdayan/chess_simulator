#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <string>

class King: public Piece
{
 public:
  /* constructor */ 
  King(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  /* checks whether move is legal according to King specific rules */ 
  bool isValidMoveSpecific(std::string new_position) override;
  /* checks whether a proposed castling move is legal for the King */ 
  bool isValidCastle(std::string new_position); 
};

#endif
