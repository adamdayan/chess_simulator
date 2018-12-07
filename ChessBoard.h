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
  int move_colour;
  Piece* king_ptrs[2];
  bool is_game_over; 

  /* constructor */ 
  ChessBoard();

  ~ChessBoard(); 
  
  void initialiseBoard();
  void terminateBoard(); 
  void resetBoard(); 
  std::string coordinateTranslator(int row, int col);
  Piece* getCell(std::string coord); 
  void printLine();
  void printCells(int iterator); 
  void displayBoard();
  bool isCheck();
  bool isCheck(std::string piece_coord, std::string destination_coord); 
  bool isCheckmate();
  bool isStalemate();
  bool isCastle(Piece* piece_ptr, std::string new_position); 
  std::string playerColour();
  std::string enemyColour();
  void switchMove();
  void submitMove(const char* piece_char, const char* destination_char);
  
  
  
};

#endif
