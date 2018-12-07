#ifndef PIECE_H
#define PIECE_H

#include <string> 

class ChessBoard; 

class Piece
{
 public:
  int colour; 
  std::string position;
  char symbol;
  std::string type;
  int move_count; 
  ChessBoard* board_ptr; 

  Piece(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool makeMove(std::string new_position);
  bool isValidMove(std::string new_position);
  virtual bool isValidMoveSpecific(std::string new_position) = 0;
  char getSymbol();
  int getColour();
  void setPosition(std::string new_position);
  void incrementMoveCnt(); 
  virtual ~Piece(); 
};

#endif
