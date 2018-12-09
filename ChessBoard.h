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
  /* hashmap of coordinates and piece pointers */ 
  std::map<std::string, Piece*> board_map;
  /* records which player's move it currently is. 0 represents black, 1 white */ 
  int move_colour;
  /* array that holds pointers to both kings */ 
  Piece* king_ptrs[2];
  /* boolean used to stop play once an end condition has been reached */ 
  bool is_game_over; 

  /* METHODS */ 
  
  /* constructor */ 
  ChessBoard();

  /* destructor */ 
  ~ChessBoard(); 

  /* creates pieces and writes their pointers to correct starting positions on board */ 
  void initialiseBoard();
  /* deletes all remaining pieces and sets their pointers to null */ 
  void terminateBoard(); 
  /* calls terminateBoard() and initialiseBoard() so that that a used board is 
     ready to start a game */ 
  void resetBoard(); 
  /* translates numerical coordinates into rank and file references */ 
  std::string coordinateTranslator(int row, int col);
  /* takes a rank and file coordinate and returns the pointer found at that location */ 
  Piece* getCell(std::string coord); 
  /* methods to display state of board */ 
  void printLine();
  void printCells(int iterator); 
  void displayBoard();
  /* checks that the arguments provided to submitMove() are of the create length and contents */ 
  bool checkArgs(std::string argument_1, std::string argument_2); 
  /* method that computers whether the current position includes check for the opposing player */ 
  bool isCheck();
  /* method that takes a hypothetical move and computes if it results in check 
     for the current player */
  bool isCheck(std::string piece_coord, std::string destination_coord); 
  /* computes whether the current position is a checkmate for the opposing player */ 
  bool isCheckmate();
  /* checks whether the current position is stalemate */ 
  bool isStalemate();
  /* computes whether a move is a valid attempt to castle */ 
  bool isCastle(Piece* piece_ptr, std::string new_position); 
  /* getter for current player's colour */ 
  std::string playerColour();
  /* getter for opposing player's colour */ 
  std::string enemyColour();
  /* switches the move_colour variable, denoting a change in turn */ 
  void switchMove();
  /* accepts coordinates for a piece and the proposed destination for that piece, 
     computes whether the move is valid and if so, executes the move */ 
  void submitMove(const char* piece_char, const char* destination_char);
  
  
  
};

#endif
