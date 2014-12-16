#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include "Piece.h"
#include "GameState.h"
#include "time.h"
#include "functions.h"

using namespace std;

int main()
{

    GameState initialGame;
    vector< vector <string> > initialBoard;
    vector< Piece* > whitePieces;
    vector< Piece*> blackPieces;
	priority_queue <pair <int, vector <vector <string > > > > worklist;
    
    ////
    ////Initialization and sizing of the 2D vector
	////
    
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
	whitePawn1->setPieceColor("White");
	whitePawn1->setPieceWeight(1);
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
	char answer;
	cout << "Would you like to have the customary starting configuration? (y/n)" << endl;
	cin >> answer;
	while(answer != 'y' && answer != 'n'){
		cout << "Please enter (y/n): " << endl;
		cin >> answer;
	}
	
	if(answer == 'y'){
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
////Input of coordinates for all pieces
////
	else{
		cout << "Input the position of white pawn (1). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWP1;
		cin >> letterWP1;
		columnWP1 = letterWP1 - 96;
		whitePawn1->setPieceCoordinates(rowWP1, columnWP1);
		whitePieces.push_back(whitePawn1);
		initialBoard[rowWP1][columnWP1] = "WP";
		
		cout << "Input the position of white pawn (2). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWP2;
		cin >> letterWP2;
		columnWP2 = letterWP2 - 96;
		whitePawn2->setPieceCoordinates(rowWP2, columnWP2);
		whitePieces.push_back(whitePawn2);
		initialBoard[rowWP2][columnWP2] = "WP";
		
		cout << "Input the position of white pawn (3). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWP3;
		cin >> letterWP3;
		columnWP3 = letterWP3 - 96;
		whitePawn3->setPieceCoordinates(rowWP3, columnWP3);
		whitePieces.push_back(whitePawn3);
		initialBoard[rowWP3][columnWP3] = "WP";
		
		cout << "Input the position of white pawn (4). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWP4;
		cin >> letterWP4;
		columnWP4 = letterWP4 - 96;
		whitePawn4->setPieceCoordinates(rowWP4, columnWP4);
		whitePieces.push_back(whitePawn4);
		initialBoard[rowWP4][columnWP4] = "WP";
		
		cout << "Input the position of white pawn (5). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWP5;
		cin >> letterWP5;
		columnWP5 = letterWP5 - 96;
		whitePawn5->setPieceCoordinates(rowWP5, columnWP5);
		whitePieces.push_back(whitePawn5);
		initialBoard[rowWP5][columnWP5] = "WP";
		
		cout << "Input the position of white rook. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWR;
		cin >> letterWR;
		columnWR = letterWR - 96;
		whiteRook->setPieceCoordinates(rowWR, columnWR);
		whitePieces.push_back(whiteRook);
		initialBoard[rowWR][columnWR] = "WR";
		
		cout << "Input the position of white knight. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWN;
		cin >> letterWN;
		columnWN = letterWN - 96;
		whiteKnight->setPieceCoordinates(rowWN, columnWN);
		whitePieces.push_back(whiteKnight);
		initialBoard[rowWN][columnWN] = "WN";
		
		cout << "Input the position of white bishop. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWB;
		cin >> letterWB;
		columnWB = letterWB - 96;
		whiteBishop->setPieceCoordinates(rowWB, columnWB);
		whitePieces.push_back(whiteBishop);
		initialBoard[rowWB][columnWB] = "WB";
		
		cout << "Input the position of white queen. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWQ;
		cin >> letterWQ;
		columnWQ = letterWQ - 96;
		whiteQueen->setPieceCoordinates(rowWQ, columnWQ);
		whitePieces.push_back(whiteQueen);
		initialBoard[rowWQ][columnWQ] = "WQ";
		
		cout << "Input the position of white king. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowWK;
		cin >> letterWK;
		columnWK = letterWK - 96;
		whiteKing->setPieceCoordinates(rowWK, columnWK);
		whitePieces.push_back(whiteKing);
		initialBoard[rowWK][columnWK] = "WK";
		
		////
		////Black Pieces
		////
		cout << "Input the position of black pawn (1). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBP1;
		cin >> letterBP1;
		columnBP1 = letterBP1 - 96;
		blackPawn1->setPieceCoordinates(rowBP1, columnBP1);
		blackPawn1->setPieceColor("Black");
		blackPieces.push_back(blackPawn1);
		initialBoard[rowBP1][columnBP1] = "BP";
		
		cout << "Input the position of black pawn (2). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBP2;
		cin >> letterBP2;
		columnBP2 = letterBP2 - 96;
		blackPawn2->setPieceCoordinates(rowBP2, columnBP2);
		blackPawn2->setPieceColor("Black");
		blackPieces.push_back(blackPawn2);
		initialBoard[rowBP2][columnBP2] = "BP";
		
		cout << "Input the position of black pawn (3). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBP3;
		cin >> letterBP3;
		columnBP3 = letterBP3 - 96;
		blackPawn3->setPieceCoordinates(rowBP3, columnBP3);
		blackPawn3->setPieceColor("Black");
		blackPieces.push_back(blackPawn3);
		initialBoard[rowBP3][columnBP3] = "BP";
		
		cout << "Input the position of black pawn (4). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBP4;
		cin >> letterBP4;
		columnBP4 = letterBP4 - 96;
		blackPawn4->setPieceCoordinates(rowBP4, columnBP4);
		blackPawn4->setPieceColor("Black");
		blackPieces.push_back(blackPawn4);
		initialBoard[rowBP4][columnBP4] = "BP";
		
		cout << "Input the position of black pawn (5). First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBP5;
		cin >> letterBP5;
		columnBP5 = letterBP5 - 96;
		blackPawn5->setPieceCoordinates(rowBP5, columnBP5);
		blackPawn5->setPieceColor("Black");
		blackPieces.push_back(blackPawn5);
		initialBoard[rowBP5][columnBP5] = "BP";
		
		cout << "Input the position of black rook. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBR;
		cin >> letterBR;
		columnBR = letterBR - 96;
		blackRook->setPieceCoordinates(rowBR, columnBR);
		blackRook->setPieceColor("Black");
		blackPieces.push_back(blackRook);
		initialBoard[rowBR][columnBR] = "BR";
		
		cout << "Input the position of black knight. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBN;
		cin >> letterBN;
		columnBN = letterBN - 96;
		blackKnight->setPieceCoordinates(rowBN, columnBN);
		blackKnight->setPieceColor("Black");
		blackPieces.push_back(blackKnight);
		initialBoard[rowBN][columnBN] = "BN";
		
		cout << "Input the position of black bishop. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBB;
		cin >> letterBB;
		columnBB = letterBB - 96;
		blackBishop->setPieceCoordinates(rowBB, columnBB);
		blackBishop->setPieceColor("Black");
		blackPieces.push_back(blackBishop);
		initialBoard[rowBB][columnBB] = "BB";
		
		cout << "Input the position of black queen. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBQ;
		cin >> letterBQ;
		columnBQ = letterBQ - 96;
		blackQueen->setPieceCoordinates(rowBQ, columnBQ);
		blackQueen->setPieceColor("Black");
		blackPieces.push_back(blackQueen);
		initialBoard[rowBQ][columnBQ] = "BQ";
		
		cout << "Input the position of black king. First enter the row (1-6). Then the column(a-e):" << endl;
		cin >> rowBK;
		cin >> letterBK;
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
		cin.ignore();
		cout << "Please enter an integer number of moves: " << endl;
		cin >> drawMoves;
	}
	
	double moveTime;
	cout << "How much time is allowed for a program move? (0.0 < t <= 240.0)" << endl;
	cin >> moveTime;
	
	while(cin.fail()){
		cin.clear();
		cin.ignore();
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
////Negamax Search and game simulation
////On the programs turn: the negamax function runs and a move is choosen.
//// This move is then made and the board is updated.
////
////On the programs turn: the operator inputs the move.
//// If the move is legal, it is made and the board is updated.
//// Otherwise, the program will ask for a legal move (the illegal move is discarded).
////

	string stalematedOpponent = "draw";
	string currentMoveColor = firstMoveColor;
	
	int moveNumber = 1;
	
	if(answer == 'y'){
		while(moveNumber <= 4){
			
			//Program has the current move
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
				
				
				while(validMove(initialGame, currentMoveColor, humanMoveName, startCoords, endCoords, result) == false){
					cout << "Invalid move." << endl;
					cout << "Enter your move in the format and hit enter after each parameter:" << endl << "startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6) result: " << endl;
					cin >> humanMoveName;
					cin >> humanMoveStartColumn;
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
				
				
				if(initialGame.findResult(savedGame) != result){
					cout << "You gave an incorrect result for your move. Actual result: " << initialGame.findResult(savedGame) << endl;
				}
				
				if(initialGame.findResult(savedGame).substr(0, 8) == "captures"
					|| initialGame.findResult(savedGame) == "promoted"
					|| initialGame.findResult(savedGame) == "rescues"){
					drawMoves = 0;
				}
				else{
					drawMoves++;
				}
				
				cout << endl;

				initialGame.print();
				
				bool promotionMade = initialGame.promotePawn(userColor);
				if(promotionMade == true){
					initialGame.makeVectors();
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
		
		
		priority_queue <pair <int, vector <vector <string> > > > currWorklist;
		priority_queue <pair <int, vector <vector <string> > > > currCopy;
		vector <GameState> movesForCurrBoard;
		
		if(currentMoveColor == programColor){
			//search for programMove using Negamax
			
			movesForCurrBoard = makeBoards(initialGame, programColor);
			
			pair <int, int> bestPair = negaMax(initialGame.getBoardConfig(), 0, programColor);
			
			GameState savedGame;
			savedGame.setBoardConfig(initialGame.getBoardConfig());
			
			cout << "Program's move: " << endl << endl;
			initialGame.setBoardConfig(movesForCurrBoard[bestPair.second].getBoardConfig());
			initialGame.makeVectors();
			
			string moveResult;
			moveResult = initialGame.getGameDifference(savedGame);
			initialGame.print();
			
			bool promotionMade = initialGame.progPromotePawn(programColor);
			if(promotionMade == true){
				initialGame.makeVectors();
			}
			
			if(moveResult != "moves"){
				drawMoves = 0;
			}
			else{
				drawMoves++;
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
			
			if(initialGame.findResult(savedGame).substr(0,8) == "captures"
				|| initialGame.findResult(savedGame) == "promoted"
				|| initialGame.findResult(savedGame) == "rescues"){
				drawMoves = 0;
			}
			else{
				drawMoves++;
			}
			
			cout << endl;

			initialGame.print();
			
			bool promotionMade = initialGame.promotePawn(userColor);
			if(promotionMade == true){
				initialGame.makeVectors();
			}
			
			
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


