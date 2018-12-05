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
  if (!(Rook::isValidMoveSpecific(new_position) || Bishop::isValidMoveSpecific(new_position)))
    return false;
  
  return true; 
}
