#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <string>

class King: public Piece
{
 public:
  King(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool isValidMoveSpecific(std::string new_position) override;
};

#endif
