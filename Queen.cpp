#include "Queen.h"

Queen::Queen(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
  : Piece(passed_colour, passed_position, passed_board_ptr)
  , Rook(passed_colour, passed_position, passed_board_ptr)
  , Bishop(passed_colour, passed_position, passed_board_ptr)
{
  symbol = 'Q';
  type = "Queen"; 
}

bool Queen::isValidMoveSpecific(std::string new_position)
{
  /* the Queen combines the movement of a Rook and a Bishop. This use of multiple inheritance 
     checks whether a proposed move conforms to either of these 2 pieces' legal moves */ 
  if (!(Rook::isValidMoveSpecific(new_position) || Bishop::isValidMoveSpecific(new_position)))
    return false;
  
  return true; 
}
