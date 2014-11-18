#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"
#include "GameState.h"

using namespace std;

int main()
{
    
    GameState initialGame;
    vector< vector <string> > initialBoard;
    vector< Piece > whitePieces;
    vector< Piece > blackPieces;
    
    
    ///Resizing the 2D vector
    
    initialBoard.resize(8);
    for(int i = 0; i<8; i++){
        initialBoard[i].resize(7);
    }
	
	
    //setting all relevant areas empty. Essentially all the
    //working spaces in the board.
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 6; j++) {
            initialBoard[i][j] = "empty";
        }
    }
    
    //settings for out of bounds.
        for(int i = 0; i < 8; i++){
            for (int j = 0; j< 7; j++) {
                if (i == 0 || i ==7) {
                    initialBoard[i][j] = "outOfBounds";
                }
                if (j == 0 || j == 6) {
                    initialBoard[i][j] = "outOfBounds";
                }
            }
        }
    
    ////
    ////Initial configuration
    ////
    ////Variables for the white pieces
    ////
    int rowWP1;
    char letterWP1;
    int columnWP1;
    Pawn whitePawn1;
    
    int rowWP2;
    char letterWP2;
    int columnWP2;
    Pawn whitePawn2;
    
    int rowWP3;
    char letterWP3;
    int columnWP3;
    Pawn whitePawn3;
    
    int rowWP4;
    char letterWP4;
    int columnWP4;
    Pawn whitePawn4;
    
    int rowWP5;
    char letterWP5;
    int columnWP5;
    Pawn whitePawn5;
    
    int rowWN;
    char letterWN;
    int columnWN;
    Knight whiteKnight;
    
    int rowWB;
    char letterWB;
    int columnWB;
    Bishop whiteBishop;
    
    int rowWR;
    char letterWR;
    int columnWR;
    Rook whiteRook;
    
    int rowWQ;
    char letterWQ;
    int columnWQ;
    Queen whiteQueen;
    
    int rowWK;
    char letterWK;
    int columnWK;
    King whiteKing;
    
    ////
    ////Variables for the black pieces
    ////
    int rowBP1;
    char letterBP1;
    int columnBP1;
    Pawn blackPawn1;
    
    int rowBP2;
    char letterBP2;
    int columnBP2;
    Pawn blackPawn2;
    
    int rowBP3;
    char letterBP3;
    int columnBP3;
    Pawn blackPawn3;
    
    int rowBP4;
    char letterBP4;
    int columnBP4;
    Pawn blackPawn4;
    
    int rowBP5;
    char letterBP5;
    int columnBP5;
    Pawn blackPawn5;
    
    int rowBN;
    char letterBN;
    int columnBN;
    Knight blackKnight;
    
    int rowBB;
    char letterBB;
    int columnBB;
    Bishop blackBishop;
    
    int rowBR;
    char letterBR;
    int columnBR;
    Rook blackRook;
    
    int rowBQ;
    char letterBQ;
    int columnBQ;
    Queen blackQueen;
    
    int rowBK;
    char letterBK;
    int columnBK;
    King blackKing;
	
	
	////
	////Automatic Standard Configuration Setup
    ////
	char answer;
	cout << "Would you like to have the customary starting configuration? (y/n)" << endl;
	cin >> answer;
	
	if(answer == 'y'){
		rowWP1 = 2;
		columnWP1 = 1;
		whitePawn1.setPieceCoordinates(rowWP1, columnWP1);
		initialBoard[rowWP1][columnWP1] = "wp";
		
		rowWP2 = 2;
		columnWP2 = 2;
		whitePawn2.setPieceCoordinates(rowWP2, columnWP2);
		initialBoard[rowWP2][columnWP2] = "wp";
		
		rowWP3 = 2;
		columnWP3 = 3;
		whitePawn3.setPieceCoordinates(rowWP3, columnWP3);
		initialBoard[rowWP3][columnWP3] = "wp";
		
		rowWP4 = 2;
		columnWP4 = 4;
		whitePawn4.setPieceCoordinates(rowWP4, columnWP4);
		initialBoard[rowWP4][columnWP4] = "wp";
		
		rowWP5 = 2;
		columnWP5 = 5;
		whitePawn5.setPieceCoordinates(rowWP5, columnWP5);
		initialBoard[rowWP5][columnWP5] = "wp";
		
		rowWR = 1;
		columnWR = 1;
		whiteRook.setPieceCoordinates(rowWR, columnWR);
		initialBoard[rowWR][columnWR] = "wr";
		
		rowWB = 1;
		columnWB = 2;
		whiteBishop.setPieceCoordinates(rowWB, columnWB);
		initialBoard[rowWB][columnWB] = "wb";
		
		rowWK = 1;
		columnWK = 3;
		whiteKing.setPieceCoordinates(rowWK, columnWK);
		initialBoard[rowWK][columnWK] = "wk";
		
		rowWQ = 1;
		columnWQ = 4;
		whiteQueen.setPieceCoordinates(rowWQ, columnWQ);
		initialBoard[rowWQ][columnWQ] = "wq";
		
		rowWN = 1;
		columnWN = 5;
		whiteKnight.setPieceCoordinates(rowWN, columnWN);
		initialBoard[rowWN][columnWN] = "wn";
		
		rowBP1 = 5;
		columnBP1 = 1;
		blackPawn1.setPieceCoordinates(rowBP1, columnBP1);
		initialBoard[rowBP1][columnBP1] = "Bp";
		
		rowBP2 = 5;
		columnBP2 = 2;
		blackPawn2.setPieceCoordinates(rowBP2, columnBP2);
		initialBoard[rowBP2][columnBP2] = "Bp";
		
		rowBP3 = 5;
		columnBP3 = 3;
		blackPawn3.setPieceCoordinates(rowBP3, columnBP3);
		initialBoard[rowBP3][columnBP3] = "Bp";
		
		rowBP4 = 5;
		columnBP4 = 4;
		blackPawn4.setPieceCoordinates(rowBP4, columnBP4);
		initialBoard[rowBP4][columnBP4] = "Bp";
		
		rowBP5 = 5;
		columnBP5 = 5;
		blackPawn5.setPieceCoordinates(rowBP5, columnBP5);
		initialBoard[rowBP5][columnBP5] = "Bp";
		
		rowBR = 6;
		columnBR = 1;
		blackRook.setPieceCoordinates(rowBR, columnBR);
		initialBoard[rowBR][columnBR] = "Br";
		
		rowBB = 6;
		columnBB = 2;
		blackBishop.setPieceCoordinates(rowBB, columnBB);
		initialBoard[rowBB][columnBB] = "Bb";
		
		rowBK = 6;
		columnBK = 3;
		blackKing.setPieceCoordinates(rowBK, columnBK);
		initialBoard[rowBK][columnBK] = "Bk";
		
		rowBQ = 6;
		columnBQ = 4;
		blackQueen.setPieceCoordinates(rowBQ, columnBQ);
		initialBoard[rowBQ][columnBQ] = "Bq";
		
		rowBN = 6;
		columnBN = 5;
		blackKnight.setPieceCoordinates(rowBN, columnBN);
		initialBoard[rowBN][columnBN] = "Bn";
	}
	
	
    ////
    ////Input of coordinates for all pieces
    ////
	else{
    cout << "Input the position of white pawn (1). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP1;
    cin >> letterWP1;
    columnWP1 = letterWP1 - 96;
    whitePawn1.setPieceCoordinates(rowWP1, columnWP1);
    whitePieces.push_back(whitePawn1);
    initialBoard[rowWP1][columnWP1] = "whitePawn";
    
    cout << "Input the position of white pawn (2). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP2;
    cin >> letterWP2;
    columnWP2 = letterWP2 - 96;
    whitePawn2.setPieceCoordinates(rowWP2, columnWP2);
    whitePieces.push_back(whitePawn2);
    initialBoard[rowWP2][columnWP2] = "whitePawn";
    
    cout << "Input the position of white pawn (3). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP3;
    cin >> letterWP3;
    columnWP3 = letterWP3 - 96;
    whitePawn3.setPieceCoordinates(rowWP3, columnWP3);
    whitePieces.push_back(whitePawn3);
    initialBoard[rowWP3][columnWP3] = "whitePawn";
    
    cout << "Input the position of white pawn (4). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP4;
    cin >> letterWP4;
    columnWP4 = letterWP4 - 96;
    whitePawn4.setPieceCoordinates(rowWP4, columnWP4);
    whitePieces.push_back(whitePawn4);
    initialBoard[rowWP4][columnWP4] = "whitePawn";
    
    cout << "Input the position of white pawn (5). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP5;
    cin >> letterWP5;
    columnWP5 = letterWP5 - 96;
    whitePawn5.setPieceCoordinates(rowWP5, columnWP5);
    whitePieces.push_back(whitePawn5);
    initialBoard[rowWP5][columnWP5] = "whitePawn";
    
    cout << "Input the position of white rook. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWR;
    cin >> letterWR;
    columnWR = letterWR - 96;
    whiteRook.setPieceCoordinates(rowWR, columnWR);
    whitePieces.push_back(whiteRook);
    initialBoard[rowWR][columnWR] = "whiteRook";
    
    cout << "Input the position of white knight. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWN;
    cin >> letterWN;
    columnWN = letterWN - 96;
    whiteKnight.setPieceCoordinates(rowWN, columnWN);
    whitePieces.push_back(whiteKnight);
    initialBoard[rowWN][columnWN] = "whiteKnight";
    
    cout << "Input the position of white bishop. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWB;
    cin >> letterWB;
    columnWB = letterWB - 96;
    whiteBishop.setPieceCoordinates(rowWB, columnWB);
    whitePieces.push_back(whiteBishop);
    initialBoard[rowWB][columnWB] = "whiteBishop";
    
    cout << "Input the position of white queen. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWQ;
    cin >> letterWQ;
    columnWQ = letterWQ - 96;
    whiteQueen.setPieceCoordinates(rowWQ, columnWQ);
    whitePieces.push_back(whiteQueen);
    initialBoard[rowWQ][columnWQ] = "whiteQueen";
    
    cout << "Input the position of white king. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWK;
    cin >> letterWK;
    columnWK = letterWK - 96;
    whiteKing.setPieceCoordinates(rowWK, columnWK);
    whitePieces.push_back(whiteKing);
    initialBoard[rowWK][columnWK] = "whiteKing";
    
    ////
    ////Black Pieces
    ////
    cout << "Input the position of black pawn (1). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBP1;
    cin >> letterBP1;
    columnBP1 = letterBP1 - 96;
    blackPawn1.setPieceCoordinates(rowBP1, columnBP1);
    blackPieces.push_back(blackPawn1);
    initialBoard[rowBP1][columnBP1] = "blackPawn";
    
    cout << "Input the position of black pawn (2). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBP2;
    cin >> letterBP2;
    columnBP2 = letterBP2 - 96;
    blackPawn2.setPieceCoordinates(rowBP2, columnBP2);
    blackPieces.push_back(blackPawn2);
    initialBoard[rowBP2][columnBP2] = "blackPawn";
    
    cout << "Input the position of black pawn (3). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBP3;
    cin >> letterBP3;
    columnBP3 = letterBP3 - 96;
    blackPawn3.setPieceCoordinates(rowBP3, columnBP3);
    blackPieces.push_back(blackPawn3);
    initialBoard[rowBP3][columnBP3] = "blackPawn";
    
    cout << "Input the position of black pawn (4). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBP4;
    cin >> letterBP4;
    columnBP4 = letterBP4 - 96;
    blackPawn4.setPieceCoordinates(rowBP4, columnBP4);
    blackPieces.push_back(blackPawn4);
    initialBoard[rowBP4][columnBP4] = "blackPawn";
    
    cout << "Input the position of black pawn (5). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBP5;
    cin >> letterBP5;
    columnBP5 = letterBP5 - 96;
    blackPawn5.setPieceCoordinates(rowBP5, columnBP5);
    blackPieces.push_back(blackPawn5);
    initialBoard[rowBP5][columnBP5] = "blackPawn";
    
    cout << "Input the position of black rook. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBR;
    cin >> letterBR;
    columnBR = letterBR - 96;
    blackRook.setPieceCoordinates(rowBR, columnBR);
    blackPieces.push_back(blackRook);
    initialBoard[rowBR][columnBR] = "blackRook";
    
    cout << "Input the position of black knight. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBN;
    cin >> letterBN;
    columnBN = letterBN - 96;
    blackKnight.setPieceCoordinates(rowBN, columnBN);
    blackPieces.push_back(blackKnight);
    initialBoard[rowBN][columnBN] = "blackKnight";
    
    cout << "Input the position of black bishop. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBB;
    cin >> letterBB;
    columnBB = letterBB - 96;
    blackBishop.setPieceCoordinates(rowBB, columnBB);
    blackPieces.push_back(blackBishop);
    initialBoard[rowBB][columnBB] = "blackBishop";
    
    cout << "Input the position of black queen. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBQ;
    cin >> letterBQ;
    columnBQ = letterBQ - 96;
    blackQueen.setPieceCoordinates(rowBQ, columnBQ);
    blackPieces.push_back(blackQueen);
    initialBoard[rowBQ][columnBQ] = "blackQueen";
    
    cout << "Input the position of black king. First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowBK;
    cin >> letterBK;
    columnBK = letterBK - 96;
    blackKing.setPieceCoordinates(rowBK, columnBK);
    blackPieces.push_back(blackKing);
    initialBoard[rowBK][columnBK]="blackKing";
	}
    
	
	
//// setting the members of initialGame
	initialGame.setBoardConfig(initialBoard);
	initialGame.setBlack(blackPieces);
	initialGame.setWhite(whitePieces);
	
	initialGame.print();
    
    return 0;
}


