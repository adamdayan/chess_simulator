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
  Piece* destination_ptr;

  new_file = new_position[0];
  new_rank = new_position[1];
  cur_file = position[0];
  cur_rank = position[1];

  file_delta = new_file - cur_file;
  rank_delta = new_rank - cur_rank;

  destination_ptr = board_ptr->getCell(new_position);
  
  /* check magnitude of fowards movement */
  if ((colour == 0 && cur_rank != '7' && rank_delta < -1)
      || (colour == 0 && cur_rank == '7' && rank_delta < -2))
    return false;
  if ((colour == 1 && cur_rank != '2' && rank_delta > 1)
      || (colour == 1 && cur_rank == '2' && rank_delta > 2))
    return false;

  /* check pawns move forward */ 
  if (rank_delta == 0)
    return false;
  /* if pawn isn't taking a piece, cannot move diagonally */ 
  if (destination_ptr == nullptr && file_delta != 0)
    return false;
  /* if pawn is taking, it must move diagonally */ 
  if (destination_ptr != nullptr && file_delta == 0)
    return false;
  /* pawn cannot move more than one file diagonally */ 
  if (abs(file_delta) > 1)
    return false;
  /* can't move more than 1 rank forward and also diagonally */ 
  if (colour == 0 && abs(file_delta) > 0 && rank_delta > 1)
    return false;
  if (colour == 1 && abs(file_delta) > 0 && rank_delta < -1)
    return false;

  /* if the pawn is moving 2 squares, check if there is a piece in between*/ 

  if (abs(rank_delta) == 2)
    {
      Piece* intermediate_ptr;
      int intermediate_increment;
      std::string intermediate_coord;
      
      intermediate_increment = ((colour == 1) ? 1 : -1);
      intermediate_coord = std::string() + cur_file + ((char) (cur_rank + intermediate_increment)) ;
      intermediate_ptr = board_ptr->getCell(intermediate_coord);

      if (intermediate_ptr != nullptr)
	return false;
    }
  
  return true; 
}

