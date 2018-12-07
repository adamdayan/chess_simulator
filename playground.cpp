#include "ChessBoard.h"
#include <iostream>

int main()
{
  ChessBoard cb;
  
  cb.displayBoard(); 

  cb.submitMove("E2", "E3");

  cb.displayBoard();

  cb.submitMove("D7", "D6");

  cb.displayBoard();

  cb.submitMove("F1", "B5");

  cb.displayBoard();

  cb.submitMove("C7", "C6");

  cb.submitMove("G1", "F3");

  cb.displayBoard();

  cb.submitMove("H7", "H6");

  cb.displayBoard();

  cb.submitMove("E1", "C1");

  cb.displayBoard();
  
  return 0;
}
