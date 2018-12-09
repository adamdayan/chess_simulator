#include "King.h"
#include "ChessBoard.h"

King::King(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
  : Piece(passed_colour, passed_position, passed_board_ptr)
{
  symbol = 'K';
  type = "King"; 
}

bool King::isValidMoveSpecific(std::string new_position)
{
  char new_rank, new_file, cur_rank, cur_file;
  int rank_delta, file_delta;

  /* split out current and proposed positions into constituent rank and file */ 
  new_file = new_position[0];
  new_rank = new_position[1];
  cur_file = position[0];
  cur_rank = position[1];

  rank_delta = new_rank - cur_rank;
  file_delta = new_file - cur_file;

  /* can move 1 in any direction */ 
  if (abs(rank_delta) > 1 || abs(file_delta) > 1)
    return false; 
  
  return true; 
}

bool King::isValidCastle(std::string new_position)
{
  char new_rank, new_file, cur_rank, cur_file;
  std::string coord; 
  int rank_delta, file_delta, signer, incrementer;
  Piece* test_ptr; 

  new_file = new_position[0];
  new_rank = new_position[1];
  cur_file = position[0];
  cur_rank = position[1];

  rank_delta = new_rank - cur_rank;
  file_delta = new_file - cur_file;

  /* only 2 possible destination files */ 
  if (!(new_file == 'C' || new_file == 'G'))
    return false; 

  /* cannot have moved previously */ 
  if (move_count != 0)
    return false;

  /* cannot move ranks */ 
  if (rank_delta != 0)
    return false;

  /* always moves 2 files */ 
  if (abs(file_delta) != 2)
    return false; 

  /* check for pieces in the way */ 
  for (int i = 0; i <= file_delta; i++)
    {
      /* used to modify 'i' such that it has the correct sign */ 
      signer = file_delta / abs(file_delta);
      incrementer = i * signer;

      coord = std::string() + ((char) (cur_file + incrementer)) + cur_rank;
      test_ptr = board_ptr->getCell(coord);

      if (test_ptr != nullptr && coord != position)
	return false;

      if (board_ptr->isCheck(position, coord))
	return false;

    }

  return true;
}
