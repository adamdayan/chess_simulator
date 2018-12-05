ChessMain: ChessMain.o ChessBoard.o  
	g++ -Wall -g ChessMain.o ChessBoard.o -o ChessMain

ChessMain.o: ChessMain.cpp 
	g++ -Wall -g -c ChessMain.cpp -o main.o

playground: playground.cpp ChessBoard.o Piece.o Pawn.o Rook.o Knight.o Bishop.o King.o Queen.o
	g++ -Wall -g $^ -o playground 

ChessBoard.o: ChessBoard.cpp ChessBoard.h Pawn.h Rook.h Knight.h Bishop.h King.h Queen.h
	g++ -Wall -g -c  ChessBoard.cpp 

Piece.o: Piece.cpp Piece.h
	g++ -Wall -g -c Piece.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h
	g++ -Wall -g -c Pawn.cpp

Rook.o: Rook.cpp Rook.h Piece.h
	g++ -Wall -g -c Rook.cpp

Knight.o: Knight.cpp Knight.h Piece.h
	g++ -Wall -g -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h
	g++ -Wall -g -c Bishop.cpp

King.o: King.cpp King.h Piece.h
	g++ -Wall -g -c King.cpp

Queen.o: Queen.cpp Queen.h Piece.h
	g++ -Wall -g -c Queen.cpp

clean:
	rm -f *.o playground 
