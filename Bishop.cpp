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
  
  new_rank = new_position[0];
  new_file = new_position[1];
  cur_rank = position[0];
  cur_file = position[1];

  rank_delta = new_rank - cur_rank;
  file_delta = new_file - cur_file;

  if (!(abs(rank_delta) == abs(file_delta)))
    return false;

  if (rank_delta > 0 && file_delta > 0)
    {
      for (int i = 1; i < abs(rank_delta); i++)
	{
	  test_rank = cur_rank + i;
	  test_file = cur_file + i;
	  coord = std::string() + test_rank + test_file;
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
	  coord = std::string() + test_rank + test_file;
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
	  coord = std::string() + test_rank + test_file;
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
	  coord = std::string() + test_rank + test_file;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr != nullptr)
	    return false;
	}
    }
  
  return true; 
}

