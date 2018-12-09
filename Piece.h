#ifndef PIECE_H
#define PIECE_H

#include <string> 

class ChessBoard; 

class Piece
{
 public:
  /* colour of piece */ 
  int colour;
  /* current position of piece */ 
  std::string position;
  /* symbol used to display piece visually */ 
  char symbol;
  /* piece type */ 
  std::string type;
  /* counter of moves this piece has completed */ 
  int move_count;
  /* pointer to the chessboard this piece sits on */ 
  ChessBoard* board_ptr; 

  /* METHODS */ 
  
  /* constructor */ 
  Piece(int passed_colour, std::string passed_position, ChessBoard* passed_board_ptr); 
  bool makeMove(std::string new_position);
  /* checks whether a proposed move conforms to common rules that govern all pieces */ 
  bool isValidMove(std::string new_position);
  /* pure virtual function that allows subclasses to define the specific rules that govern them */ 
  virtual bool isValidMoveSpecific(std::string new_position) = 0;
  /* getter for piece symbol */ 
  char getSymbol();
  /* getter for piece colour */ 
  int getColour();
  /* setter for position data member */ 
  void setPosition(std::string new_position);
  /* increments the move counter data member */ 
  void incrementMoveCnt(); 
  /* destructor */ 
  virtual ~Piece(); 
};

#endif
