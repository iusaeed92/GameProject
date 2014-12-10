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
    whitePawn1->setPieceName("P");
    
    int rowWP2;
    char letterWP2;
    int columnWP2;
    Pawn* whitePawn2 = new Pawn;
	whitePawn2->setPieceName("P");
    
    int rowWP3;
    char letterWP3;
    int columnWP3;
    Pawn* whitePawn3 = new Pawn;
	whitePawn3->setPieceName("P");
    
    int rowWP4;
    char letterWP4;
    int columnWP4;
    Pawn* whitePawn4 = new Pawn;
    whitePawn4->setPieceName("P");
    
    int rowWP5;
    char letterWP5;
    int columnWP5;
    Pawn* whitePawn5 = new Pawn;
	whitePawn5->setPieceName("P");
    
    int rowWN;
    char letterWN;
    int columnWN;
    Knight* whiteKnight = new Knight;
	whiteKnight->setPieceName("N");
    
    int rowWB;
    char letterWB;
    int columnWB;
    Bishop* whiteBishop = new Bishop;
	whiteBishop->setPieceName("B");
    
    int rowWR;
    char letterWR;
    int columnWR;
    Rook* whiteRook = new Rook;
	whiteRook->setPieceName("R");
    
    int rowWQ;
    char letterWQ;
    int columnWQ;
    Queen* whiteQueen = new Queen;
	whiteQueen->setPieceName("Q");
    
    int rowWK;
    char letterWK;
    int columnWK;
    King* whiteKing = new King;
	whiteKing->setPieceName("K");
    
    ////
    ////Variables for the black pieces
    ////
    int rowBP1;
    char letterBP1;
    int columnBP1;
    Pawn* blackPawn1 = new Pawn;
	blackPawn1->setPieceName("P");
    
    int rowBP2;
    char letterBP2;
    int columnBP2;
    Pawn* blackPawn2 = new Pawn;
	blackPawn2->setPieceName("P");
    
    int rowBP3;
    char letterBP3;
    int columnBP3;
    Pawn* blackPawn3 = new Pawn;
	blackPawn3->setPieceName("P");
    
    int rowBP4;
    char letterBP4;
    int columnBP4;
    Pawn* blackPawn4 = new Pawn;
	blackPawn4->setPieceName("P");
    
    int rowBP5;
    char letterBP5;
    int columnBP5;
    Pawn* blackPawn5 = new Pawn;
	blackPawn5->setPieceName("P");
    
    int rowBN;
    char letterBN;
    int columnBN;
    Knight* blackKnight = new Knight;
	blackKnight->setPieceName("N");
    
    int rowBB;
    char letterBB;
    int columnBB;
    Bishop* blackBishop = new Bishop;
	blackBishop->setPieceName("B");
    
    int rowBR;
    char letterBR;
    int columnBR;
    Rook* blackRook = new Rook;
	blackRook->setPieceName("R");
    
    int rowBQ;
    char letterBQ;
    int columnBQ;
    Queen* blackQueen = new Queen;
	blackQueen->setPieceName("Q");
    
    int rowBK;
    char letterBK;
    int columnBK;
    King* blackKing = new King;
	blackKing->setPieceName("K");
	
	
	////
	////Automatic Standard Configuration Setup
    ////
	char answer;
	cout << "Would you like to have the customary starting configuration? (y/n)" << endl;
	cin >> answer;
	
	if(answer == 'y'){
		rowWP1 = 5;
		columnWP1 = 1;
		whitePawn1->setPieceCoordinates(rowWP1, columnWP1);
		whitePawn1->setPieceColor("White");
		whitePawn1->setPieceWeight(1);
		whitePieces.push_back(whitePawn1);
		initialBoard[rowWP1][columnWP1] = "WP";
		
		rowWP2 = 5;
		columnWP2 = 2;
		whitePawn2->setPieceCoordinates(rowWP2, columnWP2);
		whitePawn2->setPieceColor("White");
		whitePawn2->setPieceWeight(1);
		whitePieces.push_back(whitePawn2);
		initialBoard[rowWP2][columnWP2] = "WP";
		
		rowWP3 = 5;
		columnWP3 = 3;
		whitePawn3->setPieceCoordinates(rowWP3, columnWP3);
		whitePawn3->setPieceColor("White");
		whitePawn3->setPieceWeight(1);
		whitePieces.push_back(whitePawn3);
		initialBoard[rowWP3][columnWP3] = "WP";
		
		rowWP4 = 5;
		columnWP4 = 4;
		whitePawn4->setPieceCoordinates(rowWP4, columnWP4);
		whitePawn4->setPieceColor("White");
		whitePawn4->setPieceWeight(1);
		whitePieces.push_back(whitePawn4);
		initialBoard[rowWP4][columnWP4] = "WP";
		
		rowWP5 = 5;
		columnWP5 = 5;
		whitePawn5->setPieceCoordinates(rowWP5, columnWP5);
		whitePawn5->setPieceColor("White");
		whitePawn5->setPieceWeight(1);
		whitePieces.push_back(whitePawn5);
		initialBoard[rowWP5][columnWP5] = "WP";
		
		rowWR = 6;
		columnWR = 1;
		whiteRook->setPieceCoordinates(rowWR, columnWR);
		whiteRook->setPieceColor("White");
		whiteRook->setPieceWeight(5);
		whitePieces.push_back(whiteRook);
		initialBoard[rowWR][columnWR] = "WR";
		
		rowWB = 6;
		columnWB = 2;
		whiteBishop->setPieceCoordinates(rowWB, columnWB);
		whiteBishop->setPieceColor("White");
		whiteBishop->setPieceWeight(3);
		whitePieces.push_back(whiteBishop);
		initialBoard[rowWB][columnWB] = "WB";
		
		rowWK = 6;
		columnWK = 3;
		whiteKing->setPieceCoordinates(rowWK, columnWK);
		whiteKing->setPieceColor("White");
		whiteKing->setPieceWeight(10);
		whitePieces.push_back(whiteKing);
		initialBoard[rowWK][columnWK] = "WK";
		
		rowWQ = 6;
		columnWQ = 4;
		whiteQueen->setPieceCoordinates(rowWQ, columnWQ);
		whiteQueen->setPieceColor("White");
		whiteQueen->setPieceWeight(9);
		whitePieces.push_back(whiteQueen);
		initialBoard[rowWQ][columnWQ] = "WQ";
		
		rowWN = 6;
		columnWN = 5;
		whiteKnight->setPieceCoordinates(rowWN, columnWN);
		whiteKnight->setPieceColor("White");
		whiteKnight->setPieceWeight(3);
		whitePieces.push_back(whiteKnight);
		initialBoard[rowWN][columnWN] = "WN";
		
		rowBP1 = 2;
		columnBP1 = 1;
		blackPawn1->setPieceCoordinates(rowBP1, columnBP1);
		blackPawn1->setPieceColor("Black");
		blackPawn1->setPieceWeight(1);
		blackPieces.push_back(blackPawn1);
		initialBoard[rowBP1][columnBP1] = "BP";
		
		rowBP2 = 2;
		columnBP2 = 2;
		blackPawn2->setPieceCoordinates(rowBP2, columnBP2);
		blackPawn2->setPieceColor("Black");
		blackPawn2->setPieceWeight(1);
		blackPieces.push_back(blackPawn2);
		initialBoard[rowBP2][columnBP2] = "BP";
		
		rowBP3 = 2;
		columnBP3 = 3;
		blackPawn3->setPieceCoordinates(rowBP3, columnBP3);
		blackPawn3->setPieceColor("Black");
		blackPawn3->setPieceWeight(1);
		blackPieces.push_back(blackPawn3);
		initialBoard[rowBP3][columnBP3] = "BP";
		
		rowBP4 = 2;
		columnBP4 = 4;
		blackPawn4->setPieceCoordinates(rowBP4, columnBP4);
		blackPawn4->setPieceColor("Black");
		blackPawn4->setPieceWeight(1);
		blackPieces.push_back(blackPawn4);
		initialBoard[rowBP4][columnBP4] = "BP";
		
		rowBP5 = 2;
		columnBP5 = 5;
		blackPawn5->setPieceCoordinates(rowBP5, columnBP5);
		blackPawn5->setPieceColor("Black");
		blackPawn5->setPieceWeight(1);
		blackPieces.push_back(blackPawn5);
		initialBoard[rowBP5][columnBP5] = "BP";
		
		rowBR = 1;
		columnBR = 1;
		blackRook->setPieceCoordinates(rowBR, columnBR);
		blackRook->setPieceColor("Black");
		blackRook->setPieceWeight(5);
		blackPieces.push_back(blackRook);
		initialBoard[rowBR][columnBR] = "BR";
		
		rowBB = 1;
		columnBB = 2;
		blackBishop->setPieceCoordinates(rowBB, columnBB);
		blackBishop->setPieceColor("Black");
		blackBishop->setPieceWeight(3);
		blackPieces.push_back(blackBishop);
		initialBoard[rowBB][columnBB] = "BB";
		
		rowBK = 1;
		columnBK = 3;
		blackKing->setPieceCoordinates(rowBK, columnBK);
		blackKing->setPieceColor("Black");
		blackKing->setPieceWeight(10);
		blackPieces.push_back(blackKing);
		initialBoard[rowBK][columnBK] = "BK";
		
		rowBQ = 1;
		columnBQ = 4;
		blackQueen->setPieceCoordinates(rowBQ, columnBQ);
		blackQueen->setPieceColor("Black");
		blackQueen->setPieceWeight(9);
		blackPieces.push_back(blackQueen);
		initialBoard[rowBQ][columnBQ] = "BQ";
		
		rowBN = 1;
		columnBN = 5;
		blackKnight->setPieceCoordinates(rowBN, columnBN);
		blackKnight->setPieceColor("Black");
		blackKnight->setPieceWeight(3);
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
	if(userColor == "white"){
		programColor = "black";
	}
	
	else{
		programColor = "white";
	}
	
	string firstMoveColor;
	cout << "Which color has the first move? (white/black)" << endl;
	cin >> firstMoveColor;
	
	int stalemateMoves;
	cout << "How many previous moves have been made without there being either a capture, a rescue, or a promotion?" << endl;
	cin >> stalemateMoves;
	
	double moveTime;
	cout << "How much time is allowed for a program move? (0.0 < t <= 240.0)" << endl;
	cin >> moveTime;

////
//// setting the members of initialGame
////
	initialGame.setBoardConfig(initialBoard);
	initialGame.setBlack(blackPieces);
	initialGame.setWhite(whitePieces);
	
/*	for(unsigned r = 0; r < test.getWhite().size(); r++){
		if(test.getWhite()[r]->getPieceName() == "P"){
			test.getWhite()[r] = new Pawn;
			test.getWhite()[r]->setPieceCoordinates(initialGame.getWhite()[r]->getPieceCoordinates().first, initialGame.getWhite()[r]->getPieceCoordinates().second);
		}
		if(test.getWhite()[r]->getPieceName() == "B"){
			test.getWhite()[r] = new Bishop;
		}
		if(test.getWhite()[r]->getPieceName() == "N"){
			test.getWhite()[r] = new Knight;
		}
		if(test.getWhite()[r]->getPieceName() == "R"){
			test.getWhite()[r] = new Rook;
		}
		if(test.getWhite()[r]->getPieceName() == "Q"){
			test.getWhite()[r] = new Queen;
		}
		if(test.getWhite()[r]->getPieceName() == "K"){
			test.getWhite()[r] = new King;
		}
	}
	
	for(unsigned k = 0; k < test.getWhite().size(); k++){
		cout << "row: " << test.getWhite()[k]->getPieceCoordinates().first << endl;
		cout << "row: " << initialGame.getWhite()[k]->getPieceCoordinates().first << endl << endl;
		test.getWhite()[k]->setPieceCoordinates(initialGame.getWhite()[k]->getPieceCoordinates().first, initialGame.getWhite()[k]->getPieceCoordinates().second);
	}*/
	
	
////
////Testing code for "generatePossibleMoves" functions
////
/*	vector<pair<unsigned,unsigned> > availableMoves;
	availableMoves = whiteKnight->generatePossibleMoves(initialGame);
	
	for(unsigned i=0; i<availableMoves.size(); i++){
		cout << "Row: " << availableMoves[i].first << " Column: " << availableMoves[i].second << endl;
	}

	cout << "Number of Moves for x piece: " << availableMoves.size() << endl;
	
*/	
	cout << "Weight heuristic: " << initialGame.heuristicValue() << endl;

	cout << "Starting configuration: " << endl;
	initialGame.print();
	
	vector <GameState> possibleBoards;
	possibleBoards = makeBoards(initialGame, "white");

/*		for(unsigned j = 0; j < initialGame.getWhite().size(); j++){
			cout << "Row: " << initialGame.getWhite()[j]->getPieceCoordinates().first;
			cout << "Column: " << initialGame.getWhite()[j]->getPieceCoordinates().second << endl;
		}*/

	for(unsigned i = 0; i < possibleBoards.size(); i++){
		cout << "Board " << i << ":" << endl;
//		possibleBoards[i].print();
//		for(unsigned r = 0; r < possibleBoards[i].getWhite().size(); r++){
//			*possibleBoards[i].getWhite()[r] = *whitePieces[r];
//		}
		possibleBoards[i].setWhite(whitePieces);
		for(unsigned j = 0; j < possibleBoards[i].getWhite().size(); j++){
			cout << "Row: " << possibleBoards[i].getWhite()[j]->getPieceCoordinates().first;
			cout << "Column: " << possibleBoards[i].getWhite()[j]->getPieceCoordinates().second << endl;
		}
		cout << endl << endl;
	}
	
////
////Negamax Search and game simulation
////On the programs turn: the negamax function runs and a move is choosen.
//// This move is then made and the board is updated.
////
////On the programs turn: the operator inputs the move.
//// If the move is legal, it is made and the board is updated.
//// Otherwise, the program will ask for a legal move (the illegal move is discarded).
////

// priority queue for worklist/closed node list
//
//
/*	cout << "Priority queue test code: " << endl;
	vector <vector <string> > example;
	vector <vector <string> > example2;
	vector <vector <string> > example3;
	priority_queue <pair <int, vector <vector <string> > > > worklist;
	worklist.push(make_pair(3, example));
	worklist.push(make_pair(4, example2));
	worklist.push(make_pair(2, example3));
	
	cout << worklist.top().first << endl;
	worklist.pop();
	cout << worklist.top().first << endl;
	worklist.pop();
	cout << worklist.top().first << endl << endl;
	*/
	

	makeHeuristicPairs(possibleBoards, worklist);

	
	string currentMoveColor = firstMoveColor;
	
	bool gameOver = false;
	int moveNumber = 1;
	
	while(gameOver == false){
		
		while(moveNumber <= 4){
			
			//Program has the current move
			if(currentMoveColor==programColor and moveNumber < 3){
				//Make the appriopriate move.
				if(programColor=="black"){
					movePiece(initialGame, currentMoveColor, make_pair(2, 3), make_pair(3, 3));
					cout << "Program's move: " << endl << endl;
				}
				
				else{
					movePiece(initialGame, currentMoveColor, make_pair(5, 3), make_pair(4, 3));
					cout << "Program's move: " << endl;
				}
				
			initialGame.print();
			}
			
			else if(currentMoveColor==programColor and moveNumber > 2){
				//Make the appriopriate move.
				if(programColor=="black"){
					movePiece(initialGame, currentMoveColor, make_pair(3, 3), make_pair(4, 3));
					cout << "Program's move: " << endl << endl;
				}
				
				else{
					movePiece(initialGame, currentMoveColor, make_pair(4, 3), make_pair(3, 3));
					cout << "Program's move: " << endl;
				}
				
			initialGame.print();
			}
			
			//Human has the current move.
			else{
				string humanMoveName;
				char humanMoveStartColumn;
				char humanMoveEndColumn;
				int numHumanMoveStartColumn;
				int numHumanMoveEndColumn;
				int humanMoveStartRow;
				int humanMoveEndRow;
				string result;
				cout << "Enter your move in the format and hit enter after each parameter:" << endl 
				<< "Piece name(P, B, N, R, Q, K) startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6): " << endl;
				cin >> humanMoveName;
				cin >> humanMoveStartColumn;
				cin >> humanMoveStartRow;
				cin >> humanMoveEndColumn;
				cin >> humanMoveEndRow;
				numHumanMoveStartColumn = humanMoveStartColumn - 96;
				numHumanMoveEndColumn = humanMoveEndColumn - 96;
				pair <int, int> startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
				cout << "first: " << startCoords.first << "second: " << startCoords.second << endl;
				pair <int, int> endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
				
				while(validMove(initialGame, currentMoveColor, humanMoveName, startCoords, endCoords, result) == false){
					cout << "Invalid move." << endl;
					cout << "Enter your move in the format and hit enter after each parameter:" << endl << "startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6): " << endl;
					cin >> humanMoveName;
					cin >> humanMoveStartColumn;
					cin >> humanMoveStartRow;
					cin >> humanMoveEndColumn;
					cin >> humanMoveEndRow;
					numHumanMoveStartColumn = humanMoveStartColumn - 96;
					numHumanMoveEndColumn = humanMoveEndColumn - 96;
					startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
					endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
				}
				
					movePiece(initialGame, currentMoveColor, startCoords, endCoords);
				
				initialGame.print();
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
		
////
////Negamax search for program moves
////
		
		priority_queue <pair <int, vector <vector <string> > > > currWorklist;
		
		if(currentMoveColor == programColor){
			//search for programMove using Negamax
			cout << "We made it to the program move using negamax!" << endl;
			
			vector <GameState> movesForCurrBoard = makeBoards(initialGame, programColor);
			makeHeuristicPairs(movesForCurrBoard, currWorklist);
			
			int bestMoveHeuristic = negaMax(initialGame.getBoardConfig(), 0, programColor);
			
			cout << "Negamax best heuristic: " << bestMoveHeuristic << endl;
			
			for(unsigned i = 0; i < currWorklist.size(); i++){
				cout << "Worklist value: " << currWorklist.top().first << endl;
				currWorklist.pop();
			}
			
			for(unsigned i = 0; i < currWorklist.size(); i++){
				if(currWorklist.top().first != bestMoveHeuristic){
					currWorklist.pop();
				}
			}
			
			initialGame.setBoardConfig(currWorklist.top().second);
			initialGame.print();
		}
		
		else{
			string humanMoveName;
			char humanMoveStartColumn;
			char humanMoveEndColumn;
			int numHumanMoveStartColumn;
			int numHumanMoveEndColumn;
			int humanMoveStartRow;
			int humanMoveEndRow;
			string result;
			cout << "Enter your move in the format and hit enter after each parameter:" << endl 
			<< "Piece name(P, B, N, R, Q, K) startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6): " << endl;
			cin >> humanMoveName;
			cin >> humanMoveStartColumn;
			cin >> humanMoveStartRow;
			cin >> humanMoveEndColumn;
			cin >> humanMoveEndRow;
			numHumanMoveStartColumn = humanMoveStartColumn - 96;
			numHumanMoveEndColumn = humanMoveEndColumn - 96;
			pair <int, int> startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
			cout << "first: " << startCoords.first << "second: " << startCoords.second << endl;
			pair <int, int> endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
			
			while(validMove(initialGame, currentMoveColor, humanMoveName, startCoords, endCoords, result) == false){
				cout << "Invalid move." << endl;
				cout << "Enter your move in the format and hit enter after each parameter:" << endl << "startColumn(a-e) startRow(1-6) endColumn(a-e) endRow(1-6): " << endl;
				cin >> humanMoveName;
				cin >> humanMoveStartColumn;
				cin >> humanMoveStartRow;
				cin >> humanMoveEndColumn;
				cin >> humanMoveEndRow;
				numHumanMoveStartColumn = humanMoveStartColumn - 96;
				numHumanMoveEndColumn = humanMoveEndColumn - 96;
				startCoords = make_pair(humanMoveStartRow, numHumanMoveStartColumn);
				endCoords = make_pair(humanMoveEndRow, numHumanMoveEndColumn);
			}
			
				movePiece(initialGame, currentMoveColor, startCoords, endCoords);
			
			initialGame.print();
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
	
    
    return 0;
}


