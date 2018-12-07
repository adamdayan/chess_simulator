#include "ChessBoard.h"
#include <iostream>

using namespace std; 

ChessBoard::ChessBoard()
{
  char letter, num; 
  std::string coord; 

  /* create empty board */ 
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  letter = 'A' + j;
	  num = '8' - i;

	  coord = std::string() + letter + num;
	  board_map.insert({coord, nullptr}); 
	}
    }

  initialiseBoard(); 
}

ChessBoard::~ChessBoard()
{
  terminateBoard();
}

void ChessBoard::initialiseBoard()
{
  char letter, num;
  string coord;
  Piece* piece_ptr; 

  is_game_over = false;
  move_colour = 1; 
  
  /* create all pawns */ 
  for (int i = 0; i < 8; i++)
    {
      letter = 'A' + i;

      /* black pawns */
      num = '7';
      coord = std::string() + letter + num;
      piece_ptr = new Pawn(0, coord, this);
      board_map[coord] = piece_ptr;

      /* white pawns */
      num = '2';
      coord = std::string() + letter + num;
      piece_ptr = new Pawn(1, coord, this);
      board_map[coord] = piece_ptr;
    }

  /* rooks */
  coord = std::string("A8"); 
  board_map[coord] = new Rook(0, coord, this);
  coord = std::string("A1");
  board_map[coord] = new Rook(1, coord, this); 

  /* knights */
  coord = std::string("B8");
  board_map[coord] = new Knight(0, coord, this);
  coord = std::string("B1");
  board_map[coord] = new Knight(1, coord, this);

  /* bishops */
  coord = std::string("C8");
  board_map[coord] = new Bishop(0, coord, this);
  coord = std::string("C1");
  board_map[coord] = new Bishop(1, coord, this);

  /* queens */
  coord = std::string("D8");
  board_map[coord] = new Queen(0, coord, this);
  coord = std::string("D1");
  board_map[coord] = new Queen(1, coord, this);

  /* kings */
  coord = std::string("E8");
  board_map[coord] = new King(0, coord, this);
  king_ptrs[0] = board_map[coord]; /* store king ptr for easy location */  
  coord = std::string("E1");
  board_map[coord] = new King(1, coord, this);
  king_ptrs[1] = board_map[coord]; /* store king ptr for easy location */

  /* bishops */
  coord = std::string("F8");
  board_map[coord] = new Bishop(0, coord, this);
  coord = std::string("F1");
  board_map[coord] = new Bishop(1, coord, this);

  /* knights */
  coord = std::string("G8");
  board_map[coord] = new Knight(0, coord, this);
  coord = std::string("G1");
  board_map[coord] = new Knight(1, coord, this);

  /* rooks */
  coord = std::string("H8"); 
  board_map[coord] = new Rook(0, coord, this);
  coord = std::string("H1");
  board_map[coord] = new Rook(1, coord, this);

  cout << "A new chess game is started!"; 
  
  return; 
}

void ChessBoard::terminateBoard()
{
  string coord;
  Piece* piece_ptr; 
  
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  coord = coordinateTranslator(i, j);
	  piece_ptr = getCell(coord);

	  if (piece_ptr != nullptr)
	    {
	      delete piece_ptr;
	      board_map[coord] = piece_ptr = nullptr;
	    }
	}
    }
}

void ChessBoard::resetBoard()
{
  terminateBoard();
  initialiseBoard();
}

/* to account for translating between chess notation and iterators */ 
std::string ChessBoard::coordinateTranslator(int row, int col)
{
  char letter, num;
  std::string coord;

  num = '8' - row;
  letter = 'A' + col;

  coord = std::string() + letter + num;

  return coord;
}

Piece* ChessBoard::getCell(std::string coord)
{
  return board_map[coord];
}

void ChessBoard::printLine()
{
  std::cout << "  +---+---+---+---+---+---+---+---+   " << std::endl;
}

void ChessBoard::printCells(int iterator)
{
  std::string coord; 
  Piece* piece_pointer;
  char piece_symbol;
  
  cout << 8 - iterator << " "; 
  for (int i = 0; i < 8; i++)
    {
      coord = coordinateTranslator(iterator, i); 
      piece_pointer = getCell(coord);
      if (piece_pointer == nullptr)
	piece_symbol = ' ';
      else
	piece_symbol = piece_pointer->symbol; 
      
      cout << "| " << piece_symbol << " ";
    }
  cout << "| " << 8 - iterator << endl;
}

void ChessBoard::displayBoard()
{
  cout << "  "; 
  for (int i = 0; i < 8; i++)
    cout << "  " << (char) ('A' + i) << " ";
  cout << endl; 
  
  for (int i = 0; i < 8; i++)
    {
      printLine();
      printCells(i);
    }

  printLine();
  cout << "  "; 
  for (int i = 0; i < 8; i++)
    cout << "  " << (char) ('A' + i) << " ";
  cout << endl << endl; 
}

/* TO COMPLETE */ 
bool ChessBoard::isCheck(string piece_coord, string destination_coord)
{
  string coord, king_coord;
  Piece* test_ptr; 
  Piece* piece_ptr;
  Piece* saved_target_ptr;

  saved_target_ptr = getCell(destination_coord);
  piece_ptr = getCell(piece_coord);

  /* make proposed move */ 
  board_map[destination_coord] = piece_ptr;
  piece_ptr->setPosition(destination_coord); 
  board_map[piece_coord] = nullptr; 
  

  /* find coordinates of king belonging to current turn holder */ 
  king_coord = king_ptrs[move_colour]->position; 
  
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  coord = coordinateTranslator(i, j);
	  test_ptr = getCell(coord);
	  if (test_ptr != nullptr)
	    {
	      if (test_ptr->getColour() != move_colour)
		{
		  /* compute if the attempted move leads to check on turn holder's king */ 
		  if (test_ptr->isValidMove(king_coord))
		    {
		      /* reverse move and return true */ 
		      board_map[piece_coord] = piece_ptr;
		      piece_ptr->setPosition(piece_coord);
		      board_map[destination_coord] = saved_target_ptr; 
		      
		      return true;
		    }

		}
	    }
	}
    }
  
  /* reverse move and return false */ 
  board_map[piece_coord] = piece_ptr;
  piece_ptr->setPosition(piece_coord);
  board_map[destination_coord] = saved_target_ptr;
  
  return false;
}


bool ChessBoard::isCheck()
{
  string coord, king_coord;
  Piece* test_ptr;
  int target_colour;

  target_colour = move_colour % 1; 

  /* find coordinates of king belonging to current turn holder */ 
  king_coord = king_ptrs[target_colour]->position; 
  
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  coord = coordinateTranslator(i, j);
	  test_ptr = getCell(coord);
	  if (test_ptr != nullptr)
	    {
	      if (test_ptr->getColour() != target_colour)
		{
		  if (test_ptr->isValidMove(king_coord))
		    return true;

		}
	    }
	}
    }
  
  return false;
}

 
bool ChessBoard::isCheckmate()
{
  string piece_coord, move_coord;
  Piece* piece_ptr;
  Piece* saved_target_ptr;

  for (int piece_rank = 0; piece_rank < 8; piece_rank++)
    {
      for (int piece_file = 0; piece_file < 8; piece_file++)
	{
	  piece_coord = coordinateTranslator(piece_rank, piece_file);
	  piece_ptr = getCell(piece_coord);

	  if (piece_ptr != nullptr)
	    {
	      for (int move_rank = 0; move_rank < 8; move_rank++)
		{
		  for (int move_file = 0; move_file < 8; move_file++)
		    {
		      move_coord = coordinateTranslator(move_rank, move_file);
		      if (piece_ptr->isValidMove(move_coord)
			  && (piece_ptr->getColour() != move_colour))
			{
			  saved_target_ptr = getCell(move_coord);

			  board_map[move_coord] = piece_ptr;
			  piece_ptr->setPosition(move_coord); 
			  board_map[piece_coord] = nullptr;

			  if (!isCheck())
			    {
			      board_map[piece_coord] = piece_ptr;
			      piece_ptr->setPosition(piece_coord);
			      board_map[move_coord] = saved_target_ptr;
			      
			      return false;
			    }

			  board_map[piece_coord] = piece_ptr;
			  piece_ptr->setPosition(piece_coord); 
			  board_map[move_coord] = saved_target_ptr;
			}
		    }
		}
	    }
	}
    }
  
  return true;
}

bool ChessBoard::isStalemate()
{
  string piece_coord, move_coord;
  Piece* piece_ptr;

  if (isCheck())
    return false; 
  for (int piece_rank = 0; piece_rank < 8; piece_rank++)
    {
      for (int piece_file = 0; piece_file < 8; piece_file++)
	{
	  piece_coord = coordinateTranslator(piece_rank, piece_file);
	  piece_ptr = getCell(piece_coord);

	  if (piece_ptr != nullptr)
	    {
	      for (int move_rank = 0; move_rank < 8; move_rank++)
		{
		  for (int move_file = 0; move_file < 8; move_file++)
		    {
		      move_coord = coordinateTranslator(move_rank, move_file);
		      if (piece_ptr->isValidMove(move_coord)
			  && (piece_ptr->getColour() != move_colour))
			{
			  return false; 
			}
		    }
		}
	    }
	}
    }
  
  return true;
}

bool ChessBoard::isCastle(Piece* piece_ptr, std::string new_position)
{
  string rook_location, rook_destination, king_location; 
  Piece* test_ptr = nullptr;
  Rook* rook_ptr;
  King* king_ptr; 

  
  if (!(piece_ptr->type == "King"))
    return false;

  king_ptr = dynamic_cast<King*>(piece_ptr); 

  king_location = king_ptr->position; 

  if (!(king_location == string("E8") || king_location == string("E1")))
    return false;

  if (!(new_position == "C1" || new_position == "C8"
	|| new_position == "G1" || new_position == "G8"))
    return false;

  if (new_position == "C1")
    {
      rook_location = "A1"; 
      test_ptr = getCell(rook_location);
      rook_destination = string("D1"); 
    }

  if (new_position == "C8")
    {
      rook_location = "A8"; 
      test_ptr = getCell(rook_location);
      rook_destination = string("D8"); 
    }
  
  if (new_position == "G1")
    {
      rook_location = "H1"; 
      test_ptr = getCell(rook_location);
      rook_destination = string("F1"); 
    }

  if (new_position == "G8")
    {
      rook_location = "H8"; 
      test_ptr = getCell(rook_location);
      rook_destination = string("F8"); 
    }

  if (test_ptr == nullptr)
    return false;

  if (test_ptr->type != "Rook")
    return false;

  rook_ptr = dynamic_cast<Rook*>(test_ptr); 
  
  if (rook_ptr->getColour() != piece_ptr->getColour())
    return false; 

  if (!(king_ptr->isValidCastle(new_position) && rook_ptr->isValidCastle(rook_destination)))
    {
      return false; 
    }

  board_map[new_position] = piece_ptr;
  board_map[king_location] = nullptr; 
  piece_ptr->setPosition(new_position); 
  board_map[rook_destination] = rook_ptr;
  board_map[rook_location] = nullptr; 

  return true; 
}

std::string ChessBoard::playerColour()
{
  if (move_colour)
    return std::string("White");
  
  return std::string("Black");
}

std::string ChessBoard::enemyColour()
{
  if (move_colour)
    return std::string("Black");

  return std::string("White");
}

void ChessBoard::switchMove()
{
  move_colour = 1 - move_colour; 
}

void ChessBoard::submitMove(const char* piece_char, const char* destination_char)
{
  std::string piece = piece_char, destination = destination_char;
  Piece* piece_ptr;
  Piece* destination_ptr;

  /* if game is over, do not allow any more moves to be played */ 
  if (is_game_over)
    {
      cout << "The game is over. You cannot play anymore moves!\n";
      return;
    }

  /* get pointers stored at both the piece cell and the destination cell */ 
  piece_ptr = getCell(piece);
  destination_ptr = getCell(destination);

  if (piece_ptr == nullptr)
    {
      cout << "There is no piece at position " << piece << endl;
      return; 
    }

  if (piece_ptr->getColour() != move_colour)
    {
      cout << "It's not " << enemyColour() << "'s move!" << endl;
      return;
    }

  if (isCastle(piece_ptr, destination))
    {
      cout << playerColour() << " has castled to " << destination << endl;
      return; 
    }

  if (!piece_ptr->isValidMove(destination))
    {
      cout << playerColour() << "'s " <<  piece_ptr->type
	   << " cannot move to " << destination << "!" << endl;
      return;
    }

  /* TO COMPLETE */ 
  if (isCheck(piece, destination))
    {
      cout << "Your move is invalid as it results in check. Please take it again!" << endl;
      return;
    }

  cout << endl << playerColour() << "'s " << piece_ptr->type
       << " moves from " << piece << " to " <<  destination;

  if (destination_ptr != nullptr)
    {
      cout << " taking " << enemyColour() << "'s " << destination_ptr->type;
      delete destination_ptr;
      destination_ptr = nullptr; 
    }

  cout << endl;
  
  board_map[destination] = board_map[piece];
  board_map[destination]->setPosition(destination);
  board_map[destination]->incrementMoveCnt(); 
  board_map[piece] = nullptr; 
 
  if (isCheck())
    {
      if (isCheckmate())
	{
	  cout << enemyColour() << " is in checkmate\n";
	  is_game_over = true;

	  return; 
	}
      else
	cout << enemyColour() << " is in check" << endl;
    }

  if (isStalemate())
    {
      cout << "The game has ended in a stalemate!\n";
      return;
    }

  switchMove(); 
}

 
