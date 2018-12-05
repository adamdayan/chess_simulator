#include "Pawn.h"
#include <cmath>
#include "ChessBoard.h"

Pawn::Pawn(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
  : Piece(passed_colour, passed_position, passed_board_ptr)
{
  symbol = 'P';
  type = "Pawn"; 
}

bool Pawn::isValidMoveSpecific(std::string new_position)
{
  char new_rank, new_file, cur_rank, cur_file;
  int rank_delta, file_delta; 
  Piece* test_ptr;

  new_rank = new_position[0];
  new_file = new_position[1];
  cur_rank = position[0];
  cur_file = position[1];

  rank_delta = new_rank - cur_rank;
  file_delta = new_file - cur_file;

  test_ptr = board_ptr->getCell(new_position); 
  
  /* check magnitude of fowards movement */ 
  if ((colour == 0 && cur_file != 7 && file_delta < -1)
      || (colour == 0 && cur_file == 7 && file_delta < -2))
    return false;
  if ((colour == 1 && cur_file != 2 && file_delta > 1)
      || (colour == 1 && cur_file == 2 && file_delta > 2))
    return false;

  if (test_ptr == nullptr && rank_delta != 0)
    return false;
  if (abs(rank_delta) > 1)
    return false;
  if (colour == 0 && abs(rank_delta) > 0 && file_delta > 1)
    return false;
  if (colour == 1 && abs(rank_delta) > 0 && file_delta < -1)
    return false;
  
  return true; 
}

