#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>
#include <string>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"


class ChessBoard
{
 public:
  std::map<std::string, Piece*> board_map;
  int move_colour = 1;
  Piece* king_ptrs[2]; 

  /* constructor */ 
  ChessBoard();

  std::string coordinateTranslator(int row, int col);
  Piece* getCell(std::string coord); 
  void printLine();
  void printCells(int iterator); 
  void displayBoard();
  bool isCheck(bool for_player = true);
  bool isCheckmate();
  std::string playerColour();
  std::string enemyColour();
  void switchMove();
  void submitMove(const char* piece_char, const char* destination_char); 
  
  
};

#endif
