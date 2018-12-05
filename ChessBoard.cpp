#include "ChessBoard.h"
#include <iostream>

using namespace std; 

ChessBoard::ChessBoard()
{
  char letter, num;
  Piece* piece_ptr; 
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
bool ChessBoard::isCheck(bool for_player)
{
  string coord, king_coord;
  Piece* test_ptr;
  int target_colour;  

  if (for_player)
    target_colour = move_colour;
  else
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

/* TO COMPLETE */ 
bool ChessBoard::isCheckmate()
{
  return false;
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
  if (move_colour)
    move_colour = 0;
  else
    move_colour = 1;
}

void ChessBoard::submitMove(const char* piece_char, const char* destination_char)
{
  std::string piece = piece_char, destination = destination_char;
  Piece* piece_ptr;
  Piece* destination_ptr;

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

  if (!piece_ptr->isValidMove(destination))
    {
      cout << playerColour() << "'s " <<  piece_ptr->type
	   << " cannot move to " << destination << "!" << endl;
      return;
    }

  /* TO COMPLETE */ 
  if (isCheck())
    {
      cout << "Your move is invalid as it results in check. Please take it again!" << endl;
      return;
    }

  cout << endl << playerColour() << "'s " << piece_ptr->type << " moves to " << destination;

  if (destination_ptr != nullptr)
    {
      cout << " taking " << enemyColour() << "'s " << destination_ptr->type;
    }

  cout << endl;
  board_map[destination] = board_map[piece];
  board_map[destination]->setPosition(destination); 
  board_map[piece] = nullptr; 

  /* TO COMPLETE */ 
  if (isCheck(false))
    cout << enemyColour() << " is in check" << endl;

  switchMove(); 
}

 
