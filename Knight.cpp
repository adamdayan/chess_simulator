#include "Knight.h"

Knight::Knight(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
  : Piece(passed_colour, passed_position, passed_board_ptr)
{
  symbol = 'k';
  type = "Knight"; 
}

bool Knight::isValidMoveSpecific(std::string new_position)
{
  char new_rank, new_file, cur_rank, cur_file;
  int rank_delta, file_delta;

  new_rank = new_position[0];
  new_file = new_position[1];
  cur_rank = position[0];
  cur_file = position[1];

  rank_delta = new_rank - cur_rank;
  file_delta = new_file - cur_file;

  if (!((abs(rank_delta) == 2 && abs(file_delta) == 1)
	|| (abs(rank_delta) == 1 && abs(file_delta) == 2)))
    return false;
  
  return true; 
}

