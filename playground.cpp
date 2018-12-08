#include "ChessBoard.h"
#include <iostream>

int main()
{
  ChessBoard cb;
  
  cb.displayBoard(); 

  cb.submitMove("E2", "E4");

  cb.submitMove("D7", "D5");

  cb.submitMove("E4", "D5");

  cb.submitMove("D8", "D5");

  cb.submitMove("B1", "C3");

  cb.submitMove("D5", "D8");

  cb.submitMove("D2", "D4");

  cb.submitMove("B8", "C6");

  cb.submitMove("G1", "F3");

  cb.submitMove("C8", "G4");

  cb.submitMove("D4", "D5");

  cb.submitMove("C6", "E5");

  cb.submitMove("F3", "E5");

  cb.submitMove("G4", "D1");

  cb.submitMove("F1", "B5");

  cb.submitMove("C7", "C6");

  cb.submitMove("D5", "C6");

  cb.submitMove("D8", "C7");

  cb.submitMove("C6", "B7");

  cb.submitMove("E8", "D8");

  cb.submitMove("C3", "B5");

  cb.displayBoard(); 
  
  return 0;
}
