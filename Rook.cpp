#include "Rook.h"
#include "ChessBoard.h"

Rook::Rook(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr)
  : Piece(passed_colour, passed_position, passed_board_ptr)
{
  symbol = 'R';
  type = "Rook"; 
}

bool Rook::isValidMoveSpecific(std::string new_position)
{
  char new_rank, new_file, cur_rank, cur_file, test_rank, test_file;
  std::string coord;
  Piece* test_ptr; 
  
  new_rank = new_position[0];
  new_file = new_position[1];
  cur_rank = position[0];
  cur_file = position[1];

  if (!(cur_rank == new_rank || cur_file == new_file))
    return false;

  if (new_rank > cur_rank)
    {
      int delta = new_rank - cur_rank;
      for (int i = 1; i < delta; i++)
	{
	  test_rank = cur_rank + i; 
	  coord = std::string() + test_rank + cur_file;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr !=  nullptr)
	    return false;
	}
    }

  if (new_rank < cur_rank)
    {
      int delta = cur_rank - new_rank;
      for (int i = 1; i < delta; i++)
	{
	  test_rank = cur_rank - i; 
	  coord = std::string() + test_rank + cur_file;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr !=  nullptr)
	    return false;
	}
    }

  if (new_file > cur_file)
    {
      int delta = new_file - cur_file;
      for (int i = 1; i < delta; i++)
	{
	  test_file = cur_file + i; 
	  coord = std::string() + cur_rank + test_file;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr !=  nullptr)
	    return false;
	}
    }

  if (new_file < cur_file)
    {
      int delta = cur_file - new_file;
      for (int i = 1; i < delta; i++)
	{
	  test_file = cur_file - i; 
	  coord = std::string() + cur_rank + test_file;
	  test_ptr = board_ptr->getCell(coord);

	  if (test_ptr !=  nullptr)
	    return false;
	}
    }

  return true; 
}


