#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "Piece.h"
#include "GameState.h"
#include "time.h"
#include "functions.h"

using namespace std;

int main()
{

////
////Initialization of the gamestate
////This gamestate will hold the current state of the game
////
	GameState initialGame;
	vector< vector <string> > initialBoard;
	vector< Piece* > whitePieces;
	vector< Piece* > blackPieces;
   
////
////Initialization and sizing of the 2D vector
////
	initialBoard.resize(8);
	for(int i = 0; i<8; i++){
		initialBoard[i].resize(7);
	}
	
	
////setting all relevant areas empty.
////Essentially all the working spaces in the board.
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 6; j++) {
            initialBoard[i][j] = "empty";
        }
    }
    
	////settings for out of bounds.
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
////Initial configuration of the pieces
////

////
////Variables for the white pieces
////
	int rowWP1;
	char letterWP1;
	int columnWP1;
	Pawn* whitePawn1 = new Pawn;
	whitePawn1->setPieceColor("White");
	whitePawn1->setPieceWeight(1);
	whitePawn1->setPieceName("P");
    
	int rowWP2;
	char letterWP2;
	int columnWP2;
	Pawn* whitePawn2 = new Pawn;
	whitePawn2->setPieceColor("White");
	whitePawn2->setPieceWeight(1);
	whitePawn2->setPieceName("P");
    
	int rowWP3;
	char letterWP3;
	int columnWP3;
	Pawn* whitePawn3 = new Pawn;
	whitePawn3->setPieceColor("White");
	whitePawn3->setPieceWeight(1);
	whitePawn3->setPieceName("P");
    
	int rowWP4;
	char letterWP4;
	int columnWP4;
	Pawn* whitePawn4 = new Pawn;
	whitePawn4->setPieceColor("White");
	whitePawn4->setPieceWeight(1);
	whitePawn4->setPieceName("P");
    
	int rowWP5;
	char letterWP5;
	int columnWP5;
	Pawn* whitePawn5 = new Pawn;
	whitePawn5->setPieceColor("White");
	whitePawn5->setPieceWeight(1);
	whitePawn5->setPieceName("P");
    
	int rowWN;
	char letterWN;
	int columnWN;
	Knight* whiteKnight = new Knight;
	whiteKnight->setPieceColor("White");
	whiteKnight->setPieceWeight(3);
	whiteKnight->setPieceName("N");
    
	int rowWB;
	char letterWB;
	int columnWB;
	Bishop* whiteBishop = new Bishop;
	whiteBishop->setPieceColor("White");
	whiteBishop->setPieceWeight(3);
	whiteBishop->setPieceName("B");
    
	int rowWR;
	char letterWR;
	int columnWR;
	Rook* whiteRook = new Rook;
	whiteRook->setPieceColor("White");
	whiteRook->setPieceWeight(5);
	whiteRook->setPieceName("R");
    
	int rowWQ;
	char letterWQ;
	int columnWQ;
	Queen* whiteQueen = new Queen;
	whiteQueen->setPieceColor("White");
	whiteQueen->setPieceWeight(9);
	whiteQueen->setPieceName("Q");
    
	int rowWK;
	char letterWK;
	int columnWK;
	King* whiteKing = new King;
	whiteKing->setPieceColor("White");
	whiteKing->setPieceWeight(10);
	whiteKing->setPieceName("K");
    
////
////Variables for the black pieces
////
	int rowBP1;
	char letterBP1;
	int columnBP1;
	Pawn* blackPawn1 = new Pawn;
	blackPawn1->setPieceColor("Black");
	blackPawn1->setPieceWeight(1);
	blackPawn1->setPieceName("P");
    
	int rowBP2;
	char letterBP2;
	int columnBP2;
	Pawn* blackPawn2 = new Pawn;
	blackPawn2->setPieceColor("Black");
	blackPawn2->setPieceWeight(1);
	blackPawn2->setPieceName("P");
    
	int rowBP3;
	char letterBP3;
	int columnBP3;
	Pawn* blackPawn3 = new Pawn;
	blackPawn3->setPieceColor("Black");
	blackPawn3->setPieceWeight(1);
	blackPawn3->setPieceName("P");
    
	int rowBP4;
	char letterBP4;
	int columnBP4;
	Pawn* blackPawn4 = new Pawn;
	blackPawn4->setPieceColor("Black");
	blackPawn4->setPieceWeight(1);
	blackPawn4->setPieceName("P");
    
	int rowBP5;
	char letterBP5;
	int columnBP5;
	Pawn* blackPawn5 = new Pawn;
	blackPawn5->setPieceColor("Black");
	blackPawn5->setPieceWeight(1);
	blackPawn5->setPieceName("P");
    
	int rowBN;
	char letterBN;
	int columnBN;
	Knight* blackKnight = new Knight;
	blackKnight->setPieceColor("Black");
	blackKnight->setPieceWeight(3);
	blackKnight->setPieceName("N");
    
	int rowBB;
	char letterBB;
	int columnBB;
	Bishop* blackBishop = new Bishop;
	blackBishop->setPieceColor("Black");
	blackBishop->setPieceWeight(3);
	blackBishop->setPieceName("B");
    
	int rowBR;
	char letterBR;
	int columnBR;
	Rook* blackRook = new Rook;
	blackRook->setPieceColor("Black");
	blackRook->setPieceWeight(5);
	blackRook->setPieceName("R");
    
	int rowBQ;
	char letterBQ;
	int columnBQ;
	Queen* blackQueen = new Queen;
	blackQueen->setPieceColor("Black");
	blackQueen->setPieceWeight(9);
	blackQueen->setPieceName("Q");
    
	int rowBK;
	char letterBK;
	int columnBK;
	King* blackKing = new King;
	blackKing->setPieceColor("Black");
	blackKing->setPieceWeight(10);
	blackKing->setPieceName("K");
	
	
////
////Automatic Standard Configuration Setup
////

	string invalidInput;
	string answer;
	cout << "Would you like to have the customary starting configuration? (y/n)" << endl;
	cin >> answer;
	while(answer != "y" && answer != "n"){
		cout << "Please enter (y/n): " << endl;
		cin >> answer;
	}
	
	if(answer == "y"){
		rowWP1 = 5;
		columnWP1 = 1;
		whitePawn1->setPieceCoordinates(rowWP1, columnWP1);
		whitePieces.push_back(whitePawn1);
		initialBoard[rowWP1][columnWP1] = "WP";
		
		rowWP2 = 5;
		columnWP2 = 2;
		whitePawn2->setPieceCoordinates(rowWP2, columnWP2);
		whitePieces.push_back(whitePawn2);
		initialBoard[rowWP2][columnWP2] = "WP";
		
		rowWP3 = 5;
		columnWP3 = 3;
		whitePawn3->setPieceCoordinates(rowWP3, columnWP3);
		whitePieces.push_back(whitePawn3);
		initialBoard[rowWP3][columnWP3] = "WP";
		
		rowWP4 = 5;
		columnWP4 = 4;
		whitePawn4->setPieceCoordinates(rowWP4, columnWP4);
		whitePieces.push_back(whitePawn4);
		initialBoard[rowWP4][columnWP4] = "WP";
		
		rowWP5 = 5;
		columnWP5 = 5;
		whitePawn5->setPieceCoordinates(rowWP5, columnWP5);
		whitePieces.push_back(whitePawn5);
		initialBoard[rowWP5][columnWP5] = "WP";
		
		rowWR = 6;
		columnWR = 1;
		whiteRook->setPieceCoordinates(rowWR, columnWR);
		whitePieces.push_back(whiteRook);
		initialBoard[rowWR][columnWR] = "WR";
		
		rowWB = 6;
		columnWB = 2;
		whiteBishop->setPieceCoordinates(rowWB, columnWB);
		whitePieces.push_back(whiteBishop);
		initialBoard[rowWB][columnWB] = "WB";
		
		rowWK = 6;
		columnWK = 3;
		whiteKing->setPieceCoordinates(rowWK, columnWK);
		whitePieces.push_back(whiteKing);
		initialBoard[rowWK][columnWK] = "WK";
		
		rowWQ = 6;
		columnWQ = 4;
		whiteQueen->setPieceCoordinates(rowWQ, columnWQ);
		whitePieces.push_back(whiteQueen);
		initialBoard[rowWQ][columnWQ] = "WQ";
		
		rowWN = 6;
		columnWN = 5;
		whiteKnight->setPieceCoordinates(rowWN, columnWN);
		whitePieces.push_back(whiteKnight);
		initialBoard[rowWN][columnWN] = "WN";
		
		rowBP1 = 2;
		columnBP1 = 1;
		blackPawn1->setPieceCoordinates(rowBP1, columnBP1);
		blackPieces.push_back(blackPawn1);
		initialBoard[rowBP1][columnBP1] = "BP";
		
		rowBP2 = 2;
		columnBP2 = 2;
		blackPawn2->setPieceCoordinates(rowBP2, columnBP2);
		blackPieces.push_back(blackPawn2);
		initialBoard[rowBP2][columnBP2] = "BP";
		
		rowBP3 = 2;
		columnBP3 = 3;
		blackPawn3->setPieceCoordinates(rowBP3, columnBP3);
		blackPieces.push_back(blackPawn3);
		initialBoard[rowBP3][columnBP3] = "BP";
		
		rowBP4 = 2;
		columnBP4 = 4;
		blackPawn4->setPieceCoordinates(rowBP4, columnBP4);
		blackPieces.push_back(blackPawn4);
		initialBoard[rowBP4][columnBP4] = "BP";
		
		rowBP5 = 2;
		columnBP5 = 5;
		blackPawn5->setPieceCoordinates(rowBP5, columnBP5);
		blackPieces.push_back(blackPawn5);
		initialBoard[rowBP5][columnBP5] = "BP";
		
		rowBR = 1;
		columnBR = 1;
		blackRook->setPieceCoordinates(rowBR, columnBR);
		blackPieces.push_back(blackRook);
		initialBoard[rowBR][columnBR] = "BR";
		
		rowBB = 1;
		columnBB = 2;
		blackBishop->setPieceCoordinates(rowBB, columnBB);
		blackPieces.push_back(blackBishop);
		initialBoard[rowBB][columnBB] = "BB";
		
		rowBK = 1;
		columnBK = 3;
		blackKing->setPieceCoordinates(rowBK, columnBK);
		blackPieces.push_back(blackKing);
		initialBoard[rowBK][columnBK] = "BK";
		
		rowBQ = 1;
		columnBQ = 4;
		blackQueen->setPieceCoordinates(rowBQ, columnBQ);
		blackPieces.push_back(blackQueen);
		initialBoard[rowBQ][columnBQ] = "BQ";
		
		rowBN = 1;
		columnBN = 5;
		blackKnight->setPieceCoordinates(rowBN, columnBN);
		blackPieces.push_back(blackKnight);
		initialBoard[rowBN][columnBN] = "BN";
	}
	
	
////
////Custom configuration:
////	input of coordinates for all remaining pieces
////
	else{
		int numOfWhitePawns;
		cout << "How many white pawns are on the board? (0-5)" << endl;
		cin >> numOfWhitePawns;
		
		while(cin.fail()){
			cin.clear();
			getline(cin, invalidInput);
			cout << "Please enter an integer number of pawns: " << endl;
			cin >> numOfWhitePawns;
		}
		
		if(numOfWhitePawns > 0){
			cout << "Input the position of white pawn (1). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWP1;
			cin >> rowWP1;
			columnWP1 = letterWP1 - 96;
			whitePawn1->setPieceCoordinates(rowWP1, columnWP1);
			whitePieces.push_back(whitePawn1);
			initialBoard[rowWP1][columnWP1] = "WP";
		}
		
		if(numOfWhitePawns > 1){
			cout << "Input the position of white pawn (2). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWP2;
			cin >> rowWP2;
			columnWP2 = letterWP2 - 96;
			whitePawn2->setPieceCoordinates(rowWP2, columnWP2);
			whitePieces.push_back(whitePawn2);
			initialBoard[rowWP2][columnWP2] = "WP";
		}
		
		if(numOfWhitePawns > 2){
			cout << "Input the position of white pawn (3). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWP3;
			cin >> rowWP3;
			columnWP3 = letterWP3 - 96;
			whitePawn3->setPieceCoordinates(rowWP3, columnWP3);
			whitePieces.push_back(whitePawn3);
			initialBoard[rowWP3][columnWP3] = "WP";
		}
		
		if(numOfWhitePawns > 3){
			cout << "Input the position of white pawn (4). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWP4;
			cin >> rowWP4;
			columnWP4 = letterWP4 - 96;
			whitePawn4->setPieceCoordinates(rowWP4, columnWP4);
			whitePieces.push_back(whitePawn4);
			initialBoard[rowWP4][columnWP4] = "WP";
		}
		
		if(numOfWhitePawns > 4){
			cout << "Input the position of white pawn (5). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWP5;
			cin >> rowWP5;
			columnWP5 = letterWP5 - 96;
			whitePawn5->setPieceCoordinates(rowWP5, columnWP5);
			whitePieces.push_back(whitePawn5);
			initialBoard[rowWP5][columnWP5] = "WP";
		}
		
		string WROnBoard;
		cout << "Is there a white rook on the board? (y/n)" << endl;
		cin >> WROnBoard;
		
		while(WROnBoard != "y" && WROnBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> WROnBoard;
		}
		
		if(WROnBoard == "y"){
			cout << "Input the position of white rook. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWR;
			cin >> rowWR;
			columnWR = letterWR - 96;
			whiteRook->setPieceCoordinates(rowWR, columnWR);
			whitePieces.push_back(whiteRook);
			initialBoard[rowWR][columnWR] = "WR";
		}
		
		string WNOnBoard;
		cout << "Is there a white knight on the board? (y/n)" << endl;
		cin >> WNOnBoard;
		
		while(WNOnBoard != "y" && WNOnBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> WNOnBoard;
		}
		
		if(WNOnBoard == "y"){
			cout << "Input the position of white knight. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWN;
			cin >> rowWN;
			columnWN = letterWN - 96;
			whiteKnight->setPieceCoordinates(rowWN, columnWN);
			whitePieces.push_back(whiteKnight);
			initialBoard[rowWN][columnWN] = "WN";
		}
		
		string WBOnBoard;
		cout << "Is there a white bishop on the board? (y/n)" << endl;
		cin >> WBOnBoard;
		
		while(WBOnBoard != "y" && WBOnBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> WBOnBoard;
		}
		
		if(WBOnBoard == "y"){
			cout << "Input the position of white bishop. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWB;
			cin >> rowWB;
			columnWB = letterWB - 96;
			whiteBishop->setPieceCoordinates(rowWB, columnWB);
			whitePieces.push_back(whiteBishop);
			initialBoard[rowWB][columnWB] = "WB";
		}
		
		string WQOnBoard;
		cout << "Is there a white queen on the board? (y/n)" << endl;
		cin >> WQOnBoard;
		
		while(WQOnBoard != "y" && WQOnBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> WQOnBoard;
		}
		
		if(WQOnBoard == "y"){
			cout << "Input the position of white queen. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterWQ;
			cin >> rowWQ;
			columnWQ = letterWQ - 96;
			whiteQueen->setPieceCoordinates(rowWQ, columnWQ);
			whitePieces.push_back(whiteQueen);
			initialBoard[rowWQ][columnWQ] = "WQ";
		}
		
		cout << "Input the position of white king. First enter the column (a-e). Then the row(1-6):" << endl;
		cin >> letterWK;
		cin >> rowWK;
		columnWK = letterWK - 96;
		whiteKing->setPieceCoordinates(rowWK, columnWK);
		whitePieces.push_back(whiteKing);
		initialBoard[rowWK][columnWK] = "WK";
		
		////
		////Black Pieces
		////
		
		int numOfBlackPawns;
		cout << "How many black pawns are on the board? (0-5)" << endl;
		cin >> numOfBlackPawns;
		
		while(cin.fail()){
			cin.clear();
			getline(cin, invalidInput);
			cout << "Please enter an integer number of pawns: " << endl;
			cin >> numOfBlackPawns;
		}
		
		if(numOfBlackPawns > 0){
			cout << "Input the position of black pawn (1). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBP1;
			cin >> rowBP1;
			columnBP1 = letterBP1 - 96;
			blackPawn1->setPieceCoordinates(rowBP1, columnBP1);
			blackPawn1->setPieceColor("Black");
			blackPieces.push_back(blackPawn1);
			initialBoard[rowBP1][columnBP1] = "BP";
		}
		
		if(numOfBlackPawns > 1){
			cout << "Input the position of black pawn (2). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBP2;
			cin >> rowBP2;
			columnBP2 = letterBP2 - 96;
			blackPawn2->setPieceCoordinates(rowBP2, columnBP2);
			blackPawn2->setPieceColor("Black");
			blackPieces.push_back(blackPawn2);
			initialBoard[rowBP2][columnBP2] = "BP";
		}
		
		if(numOfBlackPawns > 2){
			cout << "Input the position of black pawn (3). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBP3;
			cin >> rowBP3;
			columnBP3 = letterBP3 - 96;
			blackPawn3->setPieceCoordinates(rowBP3, columnBP3);
			blackPawn3->setPieceColor("Black");
			blackPieces.push_back(blackPawn3);
			initialBoard[rowBP3][columnBP3] = "BP";
		}
		
		if(numOfBlackPawns > 3){
			cout << "Input the position of black pawn (4). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBP4;
			cin >> rowBP4;
			columnBP4 = letterBP4 - 96;
			blackPawn4->setPieceCoordinates(rowBP4, columnBP4);
			blackPawn4->setPieceColor("Black");
			blackPieces.push_back(blackPawn4);
			initialBoard[rowBP4][columnBP4] = "BP";
		}
		
		if(numOfBlackPawns > 4){
			cout << "Input the position of black pawn (5). First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBP5;
			cin >> rowBP5;
			columnBP5 = letterBP5 - 96;
			blackPawn5->setPieceCoordinates(rowBP5, columnBP5);
			blackPawn5->setPieceColor("Black");
			blackPieces.push_back(blackPawn5);
			initialBoard[rowBP5][columnBP5] = "BP";
		}
		
		string BRonBoard;
		cout << "Is there a black rook on the board? (y/n)" << endl;
		cin >> BRonBoard;
		
		while(BRonBoard != "y" && BRonBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> BRonBoard;
		}
		
		if(BRonBoard == "y"){
			cout << "Input the position of black rook. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBR;
			cin >> rowBR;
			columnBR = letterBR - 96;
			blackRook->setPieceCoordinates(rowBR, columnBR);
			blackRook->setPieceColor("Black");
			blackPieces.push_back(blackRook);
			initialBoard[rowBR][columnBR] = "BR";
		}
		
		string BNonBoard;
		cout << "Is there a black knight on the board? (y/n)" << endl;
		cin >> BNonBoard;
		
		while(BNonBoard != "y" && BNonBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> BNonBoard;
		}
		
		if(BNonBoard == "y"){
			cout << "Input the position of black knight. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBN;
			cin >> rowBN;
			columnBN = letterBN - 96;
			blackKnight->setPieceCoordinates(rowBN, columnBN);
			blackKnight->setPieceColor("Black");
			blackPieces.push_back(blackKnight);
			initialBoard[rowBN][columnBN] = "BN";
		}
		
		string BBonBoard;
		cout << "Is there a black bishop on the board? (y/n)" << endl;
		cin >> BBonBoard;
		
		while(BBonBoard != "y" && BBonBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> BBonBoard;
		}
		
		if(BBonBoard == "y"){
			cout << "Input the position of black bishop. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBB;
			cin >> rowBB;
			columnBB = letterBB - 96;
			blackBishop->setPieceCoordinates(rowBB, columnBB);
			blackBishop->setPieceColor("Black");
			blackPieces.push_back(blackBishop);
			initialBoard[rowBB][columnBB] = "BB";
		}
		
		string BQonBoard;
		cout << "Is there a black queen on the board? (y/n)" << endl;
		cin >> BQonBoard;
		
		while(BQonBoard != "y" && BQonBoard != "n"){
			cout << "Please enter (y/n): " << endl;
			cin >> BQonBoard;
		}
		
		if(BQonBoard == "y"){
			cout << "Input the position of black queen. First enter the column (a-e). Then the row(1-6):" << endl;
			cin >> letterBQ;
			cin >> rowBQ;
			columnBQ = letterBQ - 96;
			blackQueen->setPieceCoordinates(rowBQ, columnBQ);
			blackQueen->setPieceColor("Black");
			blackPieces.push_back(blackQueen);
			initialBoard[rowBQ][columnBQ] = "BQ";
		}
		
		cout << "Input the position of black king. First enter the column (a-e). Then the row(1-6):" << endl;
		cin >> letterBK;
		cin >> rowBK;
		columnBK = letterBK - 96;
		blackKing->setPieceCoordinates(rowBK, columnBK);
		blackKing->setPieceColor("Black");
		blackPieces.push_back(blackKing);
		initialBoard[rowBK][columnBK]="BK";
	}
    
	
	
////
////Initial Questions and variable declarations
////
	string programColor;
	string userColor;
	cout << "Which color will you be playing as? (white/black)" << endl;
	cin >> userColor;
	while(userColor != "white" && userColor != "black"){
		cout << "Please enter (white/black): " << endl;
		cin >> userColor;
	}
	
	if(userColor == "white"){
		programColor = "black";
	}
	
	else{
		programColor = "white";
	}
	
	string firstMoveColor;
	cout << "Which color has the first move? (white/black)" << endl;
	cin >> firstMoveColor;
	
	while(firstMoveColor != "white" && firstMoveColor != "black"){
		cout << "Please enter (white/black): " << endl;
		cin >> firstMoveColor;
	}
	
	int drawMoves;
	cout << "How many previous moves have been made without there being either a capture, a rescue, or a promotion?" << endl;
	cin >> drawMoves;
	
	while(cin.fail()){
		cin.clear();
		getline(cin, invalidInput);
		cout << "Please enter an integer number of moves: " << endl;
		cin >> drawMoves;
	}
	
	double moveTime;
	cout << "How much time is allowed for a program move? (0.0 < t <= 240.0)" << endl;
	cin >> moveTime;
	
	while(cin.fail()){
		cin.clear();
		getline(cin, invalidInput);
		cout << "Please enter a time t in the range (0.0 < t <= 240.0): " << endl;
		cin >> moveTime;
	}

////
//// setting the members of initialGame
////
	initialGame.setBoardConfig(initialBoard);
	initialGame.setBlack(blackPieces);
	initialGame.setWhite(whitePieces);
	
	
	cout << "Starting configuration: " << endl;
	initialGame.print();
	
	
	

////
////Game simulation:
////The program and operator take turns making moves
////


	string stalematedOpponent = "draw";
	string currentMoveColor = firstMoveColor;
	
	int moveNumber = 1;
	cout << "Move number: " << moveNumber << endl;
	
////Only use the opening book if the customary starting config was used
	if(answer == "y"){
		
////
////The opening book runs for the first 4 moves of the game.
////These moves are predetermined and are picked based on
//// the current move number.
////
		while(moveNumber <= 4){
			
			//Program has the current move
			//It is the program's first move of the game
			if(currentMoveColor==programColor and moveNumber < 3){
				//Make the appriopriate move.
				if(programColor=="black"){
					movePiece(initialGame, currentMoveColor, make_pair(2, 3), make_pair(3, 3));
					initialGame.makeVectors();
					cout << "Program's move: " << endl << endl;
					cout << "Piece name: (P) startColumn(c) startRow(2) endColumn(c) endRow(3) result(moves)" << endl << endl ;
					drawMoves++;
				}
				
				else{
					movePiece(initialGame, currentMoveColor, make_pair(5, 3), make_pair(4, 3));
					initialGame.makeVectors();
					cout << "Program's move: " << endl;
					cout << "Piece name: (P) startColumn(c) startRow(5) endColumn(c) endRow(4) result(moves)" << endl << endl ;
					drawMoves++;
				}
				
			initialGame.print();
			}
			
			//It is the program's second move of the game
			else if(currentMoveColor==programColor and moveNumber > 2){
				//Make the appriopriate move.
				if(programColor=="black"){
					if(initialGame.getBoardConfig()[2][5] == "WN"){
						movePiece(initialGame, currentMoveColor, make_pair(1, 4), make_pair(2, 5));
						initialGame.makeVectors();
						cout << "Program's move: " << endl << endl;
						cout << "Piece name: (Q) startColumn(d) startRow(1) endColumn(e) endRow(2) result(captures N)" << endl << endl ;
						drawMoves = 0;
					}
					else{
						movePiece(initialGame, currentMoveColor, make_pair(1, 2), make_pair(2, 3));
						initialGame.makeVectors();
						cout << "Program's move: " << endl << endl;
						cout << "Piece name: (B) startColumn(b) startRow(1) endColumn(c) endRow(2) result(moves)" << endl << endl ;
						drawMoves++;
					}
				}
				
				//The opponent put the program in check in two moves, take the knight with queen
				else{
					if(initialGame.getBoardConfig()[5][5] == "BN"){
						movePiece(initialGame, currentMoveColor, make_pair(6, 4), make_pair(5, 5));
						initialGame.makeVectors();
						cout << "Program's move: " << endl << endl;
						cout << "Piece name: (Q) startColumn(d) startRow(6) endColumn(e) endRow(2) result(captures N)" << endl << endl ;
						drawMoves = 0;
					}
					else{
						movePiece(initialGame, currentMoveColor, make_pair(6, 2), make_pair(5, 3));
						initialGame.makeVectors();
						cout << "Program's move: " << endl;
						cout << "Piece name: (B) startColumn(b) startRow(6) endColumn(c) endRow(5) result(moves)" << endl << endl ;
						drawMoves++;
					}
				}
				
			initialGame.print();
			
			}
			
			//Human has the current move.
			else{
				
				if(initialGame.kingInCheck(userColor) == true){
					cout << "Your king is in check!" << endl;
				}
				
				string humanMoveName;
				char humanMoveStartColumn;
				char humanMoveEndColumn;
				int numHumanMoveStartColumn;
				int numHumanMoveEndColumn;
				int humanMoveStartRow;
				int humanMoveEndRow;
				string result;
				string resultPiece;
				cout << "Enter your move in the format and hit enter after each parameter:" << endl 
				<< "Piece name(P, B, N, R, Q, K) startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6) result: " << endl;
				cin >> humanMoveName;
				cin >> humanMoveStartColumn;
				cin >> humanMoveStartRow;
				while(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Invalid row number. Enter (1-6): " << endl;
					cin >> humanMoveStartRow;
				}
				cin >> humanMoveEndColumn;
				cin >> humanMoveEndRow;
				while(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Invalid row number. Enter (1-6): " << endl;
					cin >> humanMoveEndRow;
				}
				cin >> result;
				if(result == "captures" || result == "rescues"){
					cin >> resultPiece;
					result.append(" ");
					result.append(resultPiece);
				}
				numHumanMoveStartColumn = humanMoveStartColumn - 96;
				numHumanMoveEndColumn = humanMoveEndColumn - 96;
				pair <int, int> startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
				pair <int, int> endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
				
				////Check if the move is valid. If not, ask for a valid move.				
				while(validMove(initialGame, currentMoveColor, humanMoveName, startCoords, endCoords, result) == false){
					cout << "Invalid move." << endl;
					cout << "Enter your move in the format and hit enter after each parameter:" << endl << "startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6) result: " << endl;
					cin >> humanMoveName;
					cin >> humanMoveStartColumn;
					cin >> humanMoveStartRow;
					while(cin.fail()){
						cin.clear();
						cin.ignore();
						cout << "Invalid row number. Enter (1-6): " << endl;
						cin >> humanMoveStartRow;
					}
					cin >> humanMoveEndColumn;
					cin >> humanMoveEndRow;
					while(cin.fail()){
						cin.clear();
						cin.ignore();
						cout << "Invalid row number. Enter (1-6): " << endl;
						cin >> humanMoveEndRow;
					}
					cin >> result;
					if(result == "captures" || result == "rescues"){
						cin >> resultPiece;
						result.append(" ");
						result.append(resultPiece);
					}
					numHumanMoveStartColumn = humanMoveStartColumn - 96;
					numHumanMoveEndColumn = humanMoveEndColumn - 96;
					startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
					endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
				}
				
				//Save the state of the board before the move, so the result can be checked
				GameState savedGame;
				savedGame.setBoardConfig(initialGame.getBoardConfig());
				
				movePiece(initialGame, currentMoveColor, startCoords, endCoords);
				initialGame.makeVectors();
				
				//If the move is valid except the operator gave an invalid result,
				// output what the correct result for the move is.
				if(initialGame.findResult(savedGame) != result){
					cout << "You gave an incorrect result for your move. Actual result: " << initialGame.findResult(savedGame) << endl;
				}
				
				cout << endl;

				//Check to see if a promotion/rescue needs to be made
				bool promotionMade = initialGame.promotePawn(userColor);
				if(promotionMade == true){
					initialGame.makeVectors();
				}

				initialGame.print();
				
				//Update "drawMoves" - the number of moves since the last capture/rescue/promotion
				if(initialGame.findResult(savedGame).substr(0, 8) == "captures"
					|| promotionMade){
					drawMoves = 0;
				}
				else{
					drawMoves++;
				}
				
				
				if(initialGame.kingInCheck(programColor) == true){
					cout << "You put the enemy king in check!" << endl;
				}
				
			}
			
			
			//change the currentMove color
			if(currentMoveColor == "white")
				currentMoveColor = "black";
			else
				currentMoveColor = "white";
				
			//increase moveNumber
			moveNumber++;
			cout << "Move number:  " << moveNumber << endl;
		}
	}
		
////
////Negamax search for program moves
////

	while(initialGame.checkmate(userColor) == false && initialGame.checkmate(programColor) == false && stalematedOpponent == "draw" && drawMoves < 20){	
		
		vector <GameState> movesForCurrBoard;
		
		if(currentMoveColor == programColor){
			//search for programMove using Negamax
			
			movesForCurrBoard = makeBoards(initialGame, programColor);
			
			clock_t start;

			double duration;
			start = clock();
			
			pair <int, int> bestPair = negaMax(initialGame.getBoardConfig(), 0, programColor);

			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			cout << "this took " << duration << " seconds" << endl;
			
			GameState savedGame;
			savedGame.setBoardConfig(initialGame.getBoardConfig());
			
			cout << "Program's move: " << endl << endl;
			initialGame.setBoardConfig(movesForCurrBoard[bestPair.second].getBoardConfig());
			initialGame.makeVectors();
			
			string moveResult;
			moveResult = initialGame.getGameDifference(savedGame);
			initialGame.print();
			
			
			//Check if a promotion has been made
			bool promotionMade = initialGame.progPromotePawn(programColor);
			if(promotionMade == true){
				initialGame.makeVectors();
			}
			
			//Update "drawMoves" - the number of moves since the last capture/rescue/promotion
			if(initialGame.findResult(savedGame).substr(0,8) == "captures"
				|| promotionMade){
				drawMoves = 0;
			}
			else{
				drawMoves++;
			}
			
			//Check if either color has no possible moves
			//If a color has no moves, that color has been stalemated
			vector <GameState> checkingStalemateWhite;
			vector <GameState> checkingStalemateBlack;
			checkingStalemateWhite = makeBoards(initialGame, "white");
			if(checkingStalemateWhite.size() == 0){
				stalematedOpponent = "black";
			}
			
			checkingStalemateBlack = makeBoards(initialGame, "black");
			if(checkingStalemateBlack.size() == 0){
				stalematedOpponent = "white";
			}
		}
		
		
/////
/////Human move inside negamax
/////
		else{
			if(initialGame.kingInCheck(userColor) == true){
				cout << "Your king is in check!" << endl;
			}
			string humanMoveName;
			char humanMoveStartColumn;
			char humanMoveEndColumn;
			int numHumanMoveStartColumn;
			int numHumanMoveEndColumn;
			int humanMoveStartRow;
			int humanMoveEndRow;
			string result;
			string resultPiece;
			cout << "Enter your move in the format and hit enter after each parameter:" << endl 
			<< "Piece name(P, B, N, R, Q, K) startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6) result: " << endl;
			cin >> humanMoveName;
			cin >> humanMoveStartColumn;
			cin >> humanMoveStartRow;
			while(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Invalid row number. Enter (1-6): " << endl;
				cin >> humanMoveStartRow;
			}
			cin >> humanMoveEndColumn;
			cin >> humanMoveEndRow;
			while(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Invalid row number. Enter (1-6): " << endl;
				cin >> humanMoveEndRow;
			}
			cin >> result;
			if(result == "captures" || result == "rescues"){
				cin >> resultPiece;
				result.append(" ");
				result.append(resultPiece);
			}
			numHumanMoveStartColumn = humanMoveStartColumn - 96;
			numHumanMoveEndColumn = humanMoveEndColumn - 96;
			pair <int, int> startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
			pair <int, int> endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
			
			while(validMove(initialGame, currentMoveColor, humanMoveName, startCoords, endCoords, result) == false){
				cout << "Invalid move." << endl;
				cout << "Enter your move in the format and hit enter after each parameter:" << endl 
				<< "Piece name(P, B, N, R, Q, K) startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6) result: " << endl;
				cin >> humanMoveName;
				cin >> humanMoveStartColumn;
				cin >> humanMoveStartRow;
				while(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Invalid row number. Enter (1-6): " << endl;
					cin >> humanMoveStartRow;
				}
				cin >> humanMoveEndColumn;
				cin >> humanMoveEndRow;
				while(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Invalid row number. Enter (1-6): " << endl;
					cin >> humanMoveEndRow;
				}
				cin >> result;
				if(result == "captures" || result == "rescues"){
					cin >> resultPiece;
					result.append(" ");
					result.append(resultPiece);
				}
				numHumanMoveStartColumn = humanMoveStartColumn - 96;
				numHumanMoveEndColumn = humanMoveEndColumn - 96;
				startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
				endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
			}
			
			//Save the state of the board before the move, so the result can be checked
			GameState savedGame;
			savedGame.setBoardConfig(initialGame.getBoardConfig());
			
			movePiece(initialGame, currentMoveColor, startCoords, endCoords);
			initialGame.makeVectors();
			
			
			if(result.compare(initialGame.findResult(savedGame)) != 0){
				cout << "You gave an incorrect result for your move. Actual result: " << initialGame.findResult(savedGame) << endl;
			}
			
			cout << endl;
			
			//Check if a rescue/promotion has been made
			bool promotionMade = initialGame.promotePawn(userColor);
			if(promotionMade == true){
				initialGame.makeVectors();
			}
			
			initialGame.print();
			
			//Update "drawMoves" - the number of moves since the last capture/rescue/promotion
			if(initialGame.findResult(savedGame).substr(0,8) == "captures"
				|| promotionMade){
				drawMoves = 0;
			}
			else{
				drawMoves++;
			}
			

			//Check if either color has no possible moves
			//If a color has no moves, that color has been stalemated
			vector <GameState> checkingStalemateWhite;
			vector <GameState> checkingStalemateBlack;
			checkingStalemateWhite = makeBoards(initialGame, "white");
			if(checkingStalemateWhite.size() == 0){
				stalematedOpponent = "black";
			}
			
			checkingStalemateBlack = makeBoards(initialGame, "black");
			if(checkingStalemateBlack.size() == 0){
				stalematedOpponent = "white";
			}
			
			
			
			if(initialGame.kingInCheck(programColor) == true){
				cout << "You put the enemy king in check!" << endl;
			}
			
		}



		//change the currentMove color
		if(currentMoveColor == "white")
			currentMoveColor = "black";
		else
			currentMoveColor = "white";
			
		//increase moveNumber
		moveNumber++;
		cout << "Move number:  " << moveNumber << endl;
		
	}
	
	
//Determine the winner based on how the game ended

	if(initialGame.checkmate(userColor) == true){
		cout << "YOU LOSE!" << endl;
	}
		
	else if(initialGame.checkmate(programColor) == true){
		cout << "YOU WIN!" << endl;
	}
	
	else if(drawMoves > 19){
		if(initialGame.drawWinner(stalematedOpponent) > 0){
			cout << "WHITE WINS!" << endl;
		}
		else if(initialGame.drawWinner(stalematedOpponent) < 0){
			cout << "BLACK WINS!" << endl;
		}
		else{
			cout << "The game is a DRAW!" << endl;
		}
	}
	
    
    return 0;
}


