//
// GameState.cpp
//

#include <vector>
#include <string>
#include "GameState.h"

using namespace std; 

//helper function "findPath"
//This is a helper function for member function checkmate
//Pre Cond: Parameters are pair of coordinates string color and a gamestate
//         The coordintes are the starting coordinates of the function, the color is the perspective of the function,
//         and the Game State is to get the vectors of pieces
//Post Cond: returns an integer 1 through 8 each integer corresponds to a line of sight up down left right and diagonals
//          This is so checkmate can find out if it can block the threatening piece
int findPath(pair<int,int> coordinates, string color,GameState dummyGameState){
	pair<int, int> localCoord = coordinates;
	string rook;
	string queen;
	string bishop;
	if(color == "white"){
		 rook = "BR";
		 queen = "BQ";
		 bishop = "BB";
	}
	else{
		rook = "WR";
		queen = "WQ";
		bishop = "WB";
	}
		//move up (1)
		localCoord.first = localCoord.first-1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
					localCoord.first = localCoord.first-1; 
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == rook
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is straight up
					return 1;
				}
		//move down (2)
		localCoord = coordinates;
		localCoord.first = localCoord.first+1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.first+1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == rook
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is straight down
					return 2;
				}
		
		//move left (3)
		localCoord = coordinates;
		localCoord.first = localCoord.second-1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.second-1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == rook
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is straight left
					return 3;
				}
		//move right (4)
		localCoord = coordinates;
		localCoord.first = localCoord.second+1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.second+1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == rook
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is straight right
					return 4;
				}
		//move diag up right (5)
		localCoord = coordinates;
		localCoord.first = localCoord.first-1;
		localCoord.second = localCoord.second+1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.first-1;
			localCoord.second = localCoord.second+1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == bishop
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is diag up right
					return 5;
				}
		//move diag down right (6)
		localCoord = coordinates;
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second+1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.first+1;
			localCoord.second = localCoord.second+1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == bishop
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is diag up right
					return 6;
				}
		//move diag down left (7)
		localCoord = coordinates;
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second-1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.first+1;
			localCoord.second = localCoord.second-1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == bishop
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is diag up right
					return 7;
				}
		//move diag up left (8)
		localCoord = coordinates;
		localCoord.first = localCoord.first-1;
		localCoord.second = localCoord.second-1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.first = localCoord.first-1;
			localCoord.second = localCoord.second-1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == bishop
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is diag up right
					return 8;
				}
	//should never happen
	cout << "checkmate has failed for some reason." << endl;
	return -1000;
	}
	




void GameState::setWhite(vector <Piece*> x){
    white = x; 

}

void GameState::setBlack(vector <Piece*> y){
    black = y;

}

void GameState::setBoardConfig(vector<vector<string> > board){
	boardConfig = board;
}

vector <Piece*> GameState::getWhite(){
	return white;
}

vector <Piece*> GameState::getBlack(){
	return black;
}

vector < vector < string > > GameState::getBoardConfig(){
	return boardConfig;
}

void GameState::print(){
    cout << "    a    b    c    d    e " << endl;
    cout << " --------------------------" << endl;

    for (int i = 1; i < 7; i++) {
        cout << " | ";
        for (int j = 1; j < 6; j++) {
			if(boardConfig[i][j] == "empty"){
				cout << "  " << " | ";
			}
			else{
				cout << boardConfig[i][j] << " | ";
			}
        }

        cout << " Row " << i; 
        cout << endl;
        cout << " --------------------------";
        cout << endl;
    }
}

int GameState::heuristicValue(){
	int heuristicValue = 0;
	
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 6; j++) {
			if(boardConfig[i][j] == "WP"){
				heuristicValue++;
			}
			
			if(boardConfig[i][j] == "BP"){
				heuristicValue--;
			}
			
			if(boardConfig[i][j] == "WB"){
				heuristicValue = heuristicValue + 3;
			}
			
			if(boardConfig[i][j] == "BB"){
				heuristicValue = heuristicValue - 3;
			}
			if(boardConfig[i][j] == "WN"){
				heuristicValue = heuristicValue + 3;
			}
			if(boardConfig[i][j] == "BN"){
				heuristicValue = heuristicValue - 3;
			}
			if(boardConfig[i][j] == "WR"){
				heuristicValue = heuristicValue + 5;
			}
			if(boardConfig[i][j] == "BR"){
				heuristicValue = heuristicValue - 5;
			}
			if(boardConfig[i][j] == "WQ"){
				heuristicValue = heuristicValue + 9;
			}
			if(boardConfig[i][j] == "BQ"){
				heuristicValue = heuristicValue - 9;
			}
		}
	}
	
	return heuristicValue;
}

//member function "kingInCheck"
//Pre Cond: parameter string color is the color to be evaluated. Will look at the color's king to see if it's in check
//Post Cond: returns a bool if the color entered king is in check
bool GameState::kingInCheck(string color){
	GameState dummyGameState;
	dummyGameState.setWhite(white);
	dummyGameState.setBlack(black);
	dummyGameState.setBoardConfig(boardConfig);
	pair<unsigned,unsigned> kingCoords;
	
	if(color == "white"){
		//find king
		
		for(unsigned i=0; i < white.size(); i++){
			if(white[i]->getPieceName() == "K"){
				kingCoords = white[i]->getPieceCoordinates();
			}
		}	
		
			//create all possible moves for black
			//traverse to see if any possible move matches the white kings coordinates
			vector< pair<unsigned,unsigned> > blackMoves;
			for(unsigned i=0; i < black.size(); i++){
				blackMoves = black[i]->generatePossibleMoves(dummyGameState);
				for(unsigned j=0; j < blackMoves.size(); j++){
					if(kingCoords == blackMoves[j]){
						return true;
				}
			  }
			}
			return false;
	}

else{
		pair<unsigned,unsigned> kingCoords;
		for(unsigned i=0; i < black.size(); i++){
			if(black[i]->getPieceName() == "K"){
				kingCoords = black[i]->getPieceCoordinates();
			}
		}
			//create all possible moves for white
			//traverse to see if any possible move matches the black kings coordinates
			vector< pair<unsigned,unsigned> > whiteMoves;
			for(unsigned i=0; i < white.size(); i++){
				whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
				for(unsigned j=0; j < whiteMoves.size(); j++){
					if(kingCoords == whiteMoves[j]){
						return true;
				}
			  }
			}
			//if it finds no match, king not in check
			return false; 
		}
    
	cout << "king in check has returned false do to some unknown error" << endl;
	return false;
}

//member function "isThreatened"
//Pre Cond: Parameters are a pair of unsigned ints and a string for the color to be evaluated
//			 the function will evaluate threats from the perspective of color entered
//Post Cond: Returns a bool whether or not the squareToCheck is threatened by a piece of opposite color
bool GameState::isThreatened(pair<unsigned, unsigned> squareToCheck, string color){
	GameState dummyGameState;
	dummyGameState.setWhite(white);
	dummyGameState.setBlack(black);
	dummyGameState.setBoardConfig(boardConfig);
	
	if(color == "white"){
			
			//create all possible moves for black
			//traverse to see if any possible move matches the white coordinates
			vector< pair<unsigned,unsigned> > blackMoves;
			for(unsigned i=0; i < black.size(); i++){
				blackMoves = black[i]->generatePossibleMoves(dummyGameState);
				if(black[i]->getPieceName() == "P"){
					pair<unsigned,unsigned> temp = black[i]->getPieceCoordinates();
					blackMoves.push_back(make_pair(temp.first+1, temp.second+1));
					blackMoves.push_back(make_pair(temp.first+1, temp.second-1));
				}
				
				for(unsigned j=0; j < blackMoves.size(); j++){
					if(squareToCheck == blackMoves[j]){
						return true;
				}
			  }
			}
			return false;
	}

else{
		
			//create all possible moves for white
			//traverse to see if any possible move matches the squares coordinates
			vector< pair<unsigned,unsigned> > whiteMoves;
			for(unsigned i=0; i < white.size(); i++){
				whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
				if(white[i]->getPieceName() == "P"){
					pair<unsigned,unsigned> temp = white[i]->getPieceCoordinates();
					whiteMoves.push_back(make_pair(temp.first-1, temp.second+1));
					whiteMoves.push_back(make_pair(temp.first-1, temp.second-1));
				}
				for(unsigned j=0; j < whiteMoves.size(); j++){
					if(squareToCheck == whiteMoves[j]){
						return true;
				}
			  }
			}
			//if it finds no match, space is not threatened
			return false; 
		}
    
	cout << "space has returned false do to some unknown error" << endl;
	return false;
} 

//member function "checkmate"
//Pre cond: takes a string of the color you want to evaluate
//Post Cond: returns a bool whether or not the three conditions of 
//checkmate have been evaluated (Capturing piece, blocking piece, moving out of check with king)
bool GameState::checkmate(string color){
	GameState dummyGameState;
	dummyGameState.setWhite(white);
	dummyGameState.setBlack(black);
	dummyGameState.setBoardConfig(boardConfig); 
	pair<unsigned,unsigned> kingCoords;
	pair<unsigned,unsigned> localCoord;
	bool capThreat = false;
	bool canBlock = false;
	bool canMove = false; 
	
	if(dummyGameState.kingInCheck("white") == false && dummyGameState.kingInCheck("black") == false){
		return false; 
	}
	if(color == "white"){
		//find king
		King tempKing;
		pair<int, int> tempKingCoord;
		for(unsigned i=0; i < white.size(); i++){
			if(white[i]->getPieceName() == "K"){
				tempKingCoord = white[i]->getPieceCoordinates();
				tempKing.setPieceCoordinates(tempKingCoord.first,tempKingCoord.second);
				kingCoords = white[i]->getPieceCoordinates();
				localCoord = kingCoords;
			}
		}
		
		//find piece threatening the king
		Piece threat;
		int countThreats = 0;
		vector< pair<unsigned,unsigned> > blackMoves;
			for(unsigned i=0; i < black.size(); i++){
				blackMoves = black[i]->generatePossibleMoves(dummyGameState);
				for(unsigned j=0; j < blackMoves.size(); j++){
					if(kingCoords == blackMoves[j]){
					threat = *black[i]; 	
					countThreats = countThreats+1;
				}
			  }
			}
		
		//see if threat piece can be captured
		if(countThreats <= 1){
			capThreat = dummyGameState.isThreatened(threat.getPieceCoordinates(), "black");
		}
		else{
			 capThreat = false;
		}
		//try blocking the threatening piece
		
		if(threat.getPieceName() == "N" || countThreats > 1){
			canBlock = false;
		}
		else{
			
			if(capThreat == false){
			//iterate from the king's position out in all eight directions to find enemy piece path.
			//once found, iterate through path seeing if friendly pieces can occupy them.
			int path = findPath(kingCoords, "white", dummyGameState);
			
			if(path == 1){
				vector< pair<unsigned,unsigned> > whiteMoves;
					for(unsigned i=0; i < white.size(); i++){
						whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
						for(unsigned j=0; j < whiteMoves.size(); j++){
							if(make_pair(localCoord.first-1, localCoord.second) == whiteMoves[j]){
							canBlock = true;
				        }
					  }
				}
			}
			if(path == 2){
				vector< pair<unsigned,unsigned> > whiteMoves;
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
				}
			}
			if(path == 3){
				vector< pair<unsigned,unsigned> > whiteMoves;
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first, localCoord.second-1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
				}
			}
			if(path == 4){
				vector< pair<unsigned,unsigned> > whiteMoves;
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
				}
			}
			if(path == 5){
				vector< pair<unsigned,unsigned> > whiteMoves;
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first-1, localCoord.second+1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
				}
			}
			if(path == 6){
				vector< pair<unsigned,unsigned> > whiteMoves;
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
				}
			}
			if(path == 7){
				vector< pair<unsigned,unsigned> > whiteMoves;
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second-1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
			}
			if(path == 8){
				vector< pair<unsigned,unsigned> > whiteMoves;
					for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first-1, localCoord.second-1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
		}
	if(capThreat == false && canBlock == false){
	//now test all spaces around king to see if it can move to any without remaining in check
		vector< pair<unsigned, unsigned> > kingMoves = tempKing.generatePossibleMoves(dummyGameState);
		bool movement = true;
		pair<unsigned, unsigned> moveCoord;
		for(int i = 0; i < kingMoves.size(); i++){
			moveCoord = kingMoves[i];
			if(dummyGameState.isThreatened(moveCoord, "black") == true){
				canMove = false;
				movement = false; 
			}
			else{
				canMove = true;
			}
		}
	
		if(movement == false){
			canMove = false;
		}
		else{
			canMove = true;
		}
	}
		if(capThreat == false && canBlock == false && canMove == false){
				return true;
			}
			else{
				return false;
			}
	}
	else{
		//find king
		King tempKing;
		pair<int, int> tempKingCoord;
		for(unsigned i=0; i < black.size(); i++){
			if(black[i]->getPieceName() == "K"){
				tempKingCoord = black[i]->getPieceCoordinates();
				tempKing.setPieceCoordinates(tempKingCoord.first,tempKingCoord.second);
				kingCoords = black[i]->getPieceCoordinates();
				localCoord = kingCoords;
			}
		}
		
		//find piece threatening the king
		Piece threat;
		int countThreats = 0;
		vector< pair<unsigned,unsigned> > whiteMoves;
			for(unsigned i=0; i < white.size(); i++){
				whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
				for(unsigned j=0; j < whiteMoves.size(); j++){
					if(kingCoords == whiteMoves[j]){
					threat = *white[i]; 	
					countThreats = countThreats+1;
				}
			  }
			}
		
		//see if threat piece can be captured
		if(countThreats <= 1){
			capThreat = dummyGameState.isThreatened(threat.getPieceCoordinates(), "white");
		}
		else{
			 capThreat = false;
		}
		//try blocking the threatening piece
		
		if(threat.getPieceName() == "N" || countThreats > 1){
			canBlock = false;
		}
		else{
			//iterate from the king's position out in all eight directions to find enemy piece path.
			//once found, iterate through path seeing if friendly pieces can occupy them.
		if(capThreat == false){	
			int path = findPath(kingCoords, "black", dummyGameState);
			
			if(path == 1){
				vector< pair<unsigned,unsigned> > blackMoves;
					for(unsigned i=0; i < black.size(); i++){
						blackMoves = black[i]->generatePossibleMoves(dummyGameState);
						for(unsigned j=0; j <blackMoves.size(); j++){
							if(make_pair(localCoord.first-1, localCoord.second) == blackMoves[j]){
							canBlock = true;
				        }
					  }
				    }
				}
			
			if(path == 2){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			
			if(path == 3){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first, localCoord.second-1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			
			if(path == 4){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			
			if(path == 5){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first-1, localCoord.second+1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			
			if(path == 6){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			
			if(path == 7){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i <black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second-1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			
			if(path == 8){
				vector< pair<unsigned,unsigned> > blackMoves;
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first-1, localCoord.second-1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
		}
	if(capThreat == false && canBlock == false){	
	//now test all spaces around king to see if it can move to any without remaining in check
	vector< pair<unsigned, unsigned> > kingMoves = tempKing.generatePossibleMoves(dummyGameState);
	bool movement = true;
	pair<unsigned, unsigned> moveCoord;
	for(int i = 0; i < kingMoves.size(); i++){
		moveCoord = kingMoves[i];
			if(dummyGameState.isThreatened(moveCoord, "black") == true){
				canMove = false;
				movement = false; 
			}
			else{
				canMove = true;
			}
		}
	
		if(movement == false){
			canMove = false;
		}
		else{
			canMove = true;
		}
	}
		if(capThreat == false && canBlock == false && canMove == false){
				return true;
			}
			else{
				return false;
			}
	}
}

//make vectors
void GameState::makeVectors(){
	
	white.clear();
	black.clear();
    
    
	
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 6; j++) {
			if(boardConfig[i][j] == "WP"){
				Pawn* newPawn = new Pawn;
				newPawn->setPieceColor("White");
				newPawn->setPieceCoordinates(i, j);
				newPawn->setPieceName("P");
				newPawn->setPieceWeight(1);
				white.push_back(newPawn);
			}
			
			if(boardConfig[i][j] == "BP"){
				Pawn* newPawn = new Pawn;
				newPawn->setPieceColor("Black");
				newPawn->setPieceCoordinates(i, j);
				newPawn->setPieceName("P");
				newPawn->setPieceWeight(1);
				black.push_back(newPawn);
			}
			
			if(boardConfig[i][j] == "WB"){
				Bishop* newBishop = new Bishop;
				newBishop->setPieceColor("White");
				newBishop->setPieceCoordinates(i, j);
				newBishop->setPieceName("B");
				newBishop->setPieceWeight(3);
				white.push_back(newBishop);
			}
			
			if(boardConfig[i][j] == "BB"){
				Bishop* newBishop = new Bishop;
				newBishop->setPieceColor("Black");
				newBishop->setPieceCoordinates(i, j);
				newBishop->setPieceName("B");
				newBishop->setPieceWeight(3);
				black.push_back(newBishop);
			}
			if(boardConfig[i][j] == "WN"){
				Knight* newKnight = new Knight;
				newKnight->setPieceColor("White");
				newKnight->setPieceCoordinates(i, j);
				newKnight->setPieceName("N");
				newKnight->setPieceWeight(3);
				white.push_back(newKnight);
			}
			if(boardConfig[i][j] == "BN"){
				Knight* newKnight = new Knight;
				newKnight->setPieceColor("Black");
				newKnight->setPieceCoordinates(i, j);
				newKnight->setPieceName("N");
				newKnight->setPieceWeight(3);
				black.push_back(newKnight);
			}
			if(boardConfig[i][j] == "WR"){
				Rook* newRook = new Rook;
				newRook->setPieceColor("White");
				newRook->setPieceCoordinates(i, j);
				newRook->setPieceName("R");
				newRook->setPieceWeight(5);
				white.push_back(newRook);
			}
			if(boardConfig[i][j] == "BR"){
				Rook* newRook = new Rook;
				newRook->setPieceColor("Black");
				newRook->setPieceCoordinates(i, j);
				newRook->setPieceName("R");
				newRook->setPieceWeight(5);
				black.push_back(newRook);
			}
			if(boardConfig[i][j] == "WQ"){
				Queen* newQueen = new Queen;
				newQueen->setPieceColor("White");
				newQueen->setPieceCoordinates(i, j);
				newQueen->setPieceName("Q");
				newQueen->setPieceWeight(9);
				white.push_back(newQueen);
			}
			if(boardConfig[i][j] == "BQ"){
				Queen* newQueen = new Queen;
				newQueen->setPieceColor("Black");
				newQueen->setPieceCoordinates(i, j);
				newQueen->setPieceName("Q");
				newQueen->setPieceWeight(9);
				black.push_back(newQueen);
			}
			if(boardConfig[i][j] == "WK"){
				King* newKing = new King;
				newKing->setPieceColor("White");
				newKing->setPieceCoordinates(i, j);
				newKing->setPieceName("K");
				newKing->setPieceWeight(10);
				white.push_back(newKing);
			}
			if(boardConfig[i][j] == "BK"){
				King* newKing = new King;
				newKing->setPieceColor("Black");
				newKing->setPieceCoordinates(i, j);
				newKing->setPieceName("K");
				newKing->setPieceWeight(10);
				black.push_back(newKing);
			}
		}
	} 
}

