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

  cb.submitMove("D5", "A5");

  cb.submitMove("D2", "D4");

  cb.submitMove("C7", "C6");

  cb.submitMove("G1", "F3");

  cb.submitMove("C8", "G4");

  cb.submitMove("C1", "F4");

  cb.submitMove("E7", "E6");

  cb.submitMove("H2", "H3");

  cb.submitMove("G4", "F3");

  cb.submitMove("D1", "F3");

  cb.submitMove("F8", "B4");

  cb.submitMove("F1", "E2");

  cb.submitMove("B8", "D7");

  cb.submitMove("A2", "A3");

  cb.submitMove("E8", "C8");

  cb.submitMove("A3", "B4");

  cb.submitMove("A5", "A1");

  cb.submitMove("E1", "D2");

  cb.submitMove("A1", "H1");

  cb.submitMove("F3", "C6");

  cb.submitMove("B7", "C6");

  cb.submitMove("E2", "A6"); 

  cb.displayBoard(); 
  
  return 0;
}
