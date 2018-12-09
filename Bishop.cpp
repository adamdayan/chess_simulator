#include "Bishop.h"
#include "ChessBoard.h"

Bishop::Bishop(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
  : Piece(passed_colour, passed_position, passed_board_ptr)
{
  symbol = 'B';
  type = "Bishop"; 
}

bool Bishop::isValidMoveSpecific(std::string new_position)
{
  char new_rank, new_file, cur_rank, cur_file, test_rank, test_file;
  std::string coord;
  Piece* test_ptr;
  int rank_delta, file_delta; 

  /* split out current and proposed positions into constituent rank and file */ 
  new_file = new_position[0];
  new_rank = new_position[1];
  cur_file = position[0];
  cur_rank = position[1];

  file_delta = new_file - cur_file;
  rank_delta = new_rank - cur_rank;

  /* must have 1:1 ratio of file and rank change */ 
  if (!(abs(rank_delta) == abs(file_delta)))
    return false;

  /* check there are no pieces in the way */ 
  if (rank_delta > 0 && file_delta > 0)
    {
      for (int i = 1; i < abs(rank_delta); i++)
	{
	  test_rank = cur_rank + i;
	  test_file = cur_file + i;
	  coord = std::string() + test_file + test_rank; 
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr != nullptr)
	    return false;
	}
    }

  if (rank_delta < 0 && file_delta > 0)
    {
      for (int i = 1; i < abs(rank_delta); i++)
	{
	  test_rank = cur_rank - i;
	  test_file = cur_file + i;
	  coord = std::string() + test_file + test_rank;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr != nullptr)
	    return false;
	}
    }

  if (rank_delta > 0 && file_delta < 0)
    {
      for (int i = 1; i < abs(rank_delta); i++)
	{
	  test_rank = cur_rank + i;
	  test_file = cur_file - i;
	  coord = std::string() + test_file + test_rank;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr != nullptr)
	    return false;
	}
    }
  
  if (rank_delta < 0 && file_delta < 0)
    {
      for (int i = 1; i < abs(rank_delta); i++)
	{
	  test_rank = cur_rank - i;
	  test_file = cur_file - i;
	  coord = std::string() + test_file + test_rank;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr != nullptr)
	    return false;
	}
    }
  
  return true; 
}

