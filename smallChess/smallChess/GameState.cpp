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
		localCoord.second = localCoord.second-1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.second = localCoord.second-1;
		}
		if(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == rook
				|| dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == queen){
					//this means that the path with the threat is straight left
					return 3;
				}
		//move right (4)
		localCoord = coordinates;
		localCoord.second = localCoord.second+1;
		while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			localCoord.second = localCoord.second+1;
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
					//this means that the path with the threat is diag up left
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
			if(boardConfig[i][j] == "WK"){
				heuristicValue = heuristicValue + 15;
			}
			if(boardConfig[i][j] == "BK"){
				heuristicValue = heuristicValue - 15;
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
	
	if(dummyGameState.kingInCheck(color) == false){
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
							if(white[i]->getPieceName() == "K"){
							canBlock = false;
					       }
							else if(make_pair(localCoord.first-1, localCoord.second) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first, localCoord.second-1) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second+1) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						 else if(make_pair(localCoord.first-1, localCoord.second+1) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second+1) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second-1) == whiteMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first-1, localCoord.second-1) == whiteMoves[j]){
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
		pair<unsigned, unsigned> moveCoord;
		canMove = false;
		for(unsigned i = 0; i < kingMoves.size() && canMove = false; i++){
			moveCoord = kingMoves[i];
			if(dummyGameState.isThreatened(moveCoord, "white") == true){
				canMove = false;
			}
			else{
				canMove = true;
			}
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
							if(white[i]->getPieceName() == "K"){
							canBlock = false;
							}
						else if(make_pair(localCoord.first-1, localCoord.second) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first, localCoord.second-1) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second+1) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first-1, localCoord.second+1) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second+1) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first+1, localCoord.second-1) == blackMoves[j]){
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
						if(white[i]->getPieceName() == "K"){
						canBlock = false;
					    }
						else if(make_pair(localCoord.first-1, localCoord.second-1) == blackMoves[j]){
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
	pair<unsigned, unsigned> moveCoord;
	canMove = false
	for(unsigned i = 0; i < kingMoves.size() && canMove = false; i++){
		moveCoord = kingMoves[i];
			if(dummyGameState.isThreatened(moveCoord, "black") == true){
				canMove = false;
			}
			else{
				canMove = true;
			}
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

//member function "makeVector"
//Pre cond: GameState has an initialized boardConfig and possibly incorrect white/black vectors
//Post Cond: white/black vectors are cleared and then reconstructed using the boardConfig
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


//member function "findResult"
//Pre-cond:	GameState is the current state of the game
//				temp is the state of the game one move before GameState
//Post-cond:	returns a string (moves/captures) with the correct result
//				of the move from temp to GameState
string GameState::findResult(GameState temp){

    int endColumnInt= 0;
    int endRow = 0;

	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 6; j++) {
			if(boardConfig[i][j] != temp.getBoardConfig()[i][j]){

				if (boardConfig[i][j] == "empty") {
				}
				else {
					endColumnInt = j;
					endRow = i;
				}
			}
		}
	}


	if (temp.getBoardConfig()[endRow][endColumnInt] == "empty") {
		return "moves";
	}
	else {
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "P"){
			return "captures P";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "N"){
			return "captures N";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "B"){
			return "captures B";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "R"){
			return "captures R";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "Q"){
			return "captures Q";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "K"){
			return "captures K";
		}
	}
}



//member function "getGameDifference"
//Pre-cond:	GameState is the current state of the game
//				temp is the state of the game one move before GameState
//Post-cond:	string contains the correct result of the move from
//				temp to GameState
//				The move from temp to GameState is output in the form
//				Piece startColumn startRow endColumn endRow result
string GameState::getGameDifference(GameState temp){

    string result;
	
    int startColumnInt= 0;
    string startColumn;
    int startRow = 0;
	
    int endColumnInt= 0;
    string endColumn;
    int endRow = 0;
	
    string pieceName;


	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 6; j++) {
			if(boardConfig[i][j] != temp.getBoardConfig()[i][j]){

				if (boardConfig[i][j] == "empty") {
					startColumnInt = j;
					//cout << "Start column : " << j << " start row : " << i;
					startRow = i;
				}
				else {
					// cout << "end column : " << j << " end row : " << i;
					endColumnInt = j;
					endRow = i;
					pieceName = boardConfig[i][j].substr(1,1);
				}
			}
		}
	}

	if (temp.getBoardConfig()[endRow][endColumnInt] == "empty") {
		result = "move";
	}
	else {
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "P"){
			result = "captures P";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "N"){
			result = "captures N";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "B"){
			result = "captures B";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "R"){
			result = "captures R";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "Q"){
			result = "captures Q";
		}
		if(temp.getBoardConfig()[endRow][endColumnInt].substr(1,1) == "K"){
			result = "captures K";
		}
	}


    if (startColumnInt == 1) {
        startColumn = "a";
    }
    if (startColumnInt == 2) {
        startColumn = "b";
    }
    if (startColumnInt == 3) {
        startColumn = "c";
    }
    if (startColumnInt == 4) {
        startColumn = "d";
    }
    if (startColumnInt == 5) {
        startColumn = "e";
    }
    if (endColumnInt == 1) {
        endColumn = "a";
    }
    if (endColumnInt == 2) {
        endColumn = "b";
    }
    if (endColumnInt == 3) {
        endColumn = "c";
    }
    if (endColumnInt == 4) {
        endColumn = "d";
    }
    if (endColumnInt == 5) {
		endColumn = "e";
    }
   
    cout << "Piece name (" << pieceName << ") startColumn(" << startColumn << ") startRow(" << startRow << ") endColumn(" <<
    endColumn << ") endRow(" << endRow << ") result(" << result << ")" << endl << endl;
	
	return result;
}


//member function "drawWinner"
//Pre-cond:	GameState is a state of the game after and endgame condition was met
//				stalematingColor is the color that has put the other color in stalemate
//Post-cond:	returns the score (score of white - score of black) based on the guidelines
int GameState::drawWinner(string stalematingColor){
	int totalPoints = 0;
	
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 6; j++) {
			if(boardConfig[i][j] == "WP"){
				totalPoints++;
			}
			
			if(boardConfig[i][j] == "BP"){
				totalPoints--;
			}
			
			if(boardConfig[i][j] == "WB"){
				totalPoints = totalPoints + 3;
			}
			
			if(boardConfig[i][j] == "BB"){
				totalPoints = totalPoints - 3;
			}
			if(boardConfig[i][j] == "WN"){
				totalPoints = totalPoints + 3;
			}
			if(boardConfig[i][j] == "BN"){
				totalPoints = totalPoints - 3;
			}
			if(boardConfig[i][j] == "WR"){
				totalPoints = totalPoints + 5;
			}
			if(boardConfig[i][j] == "BR"){
				totalPoints = totalPoints - 5;
			}
			if(boardConfig[i][j] == "WQ"){
				totalPoints = totalPoints + 9;
			}
			if(boardConfig[i][j] == "BQ"){
				totalPoints = totalPoints - 9;
			}
		}
	}
	
	if(stalematingColor == "white"){
		totalPoints = totalPoints + 14;
	}
	
	else if(stalematingColor == "black"){
		totalPoints = totalPoints - 14;
	}
	
	else{
		//do nothing, it was a draw
	}
	
	
	return totalPoints;
}




//member function "promotePawn"
//this function is for the human promotion
//Pre: Parameter is the human's color playing the game. Check to see if a user color Pawn
//     is in the row suitable for promotion then asks the user what piece they want if there are 
//     dead pieces
//Post: returns a boolean, true if a promotion has been made, false if a promotion was not made
bool GameState::promotePawn(string color){
	GameState dummyGameState;
	dummyGameState.setWhite(white);
	dummyGameState.setBlack(black);
	dummyGameState.setBoardConfig(boardConfig);
	bool rookDead = true;
	bool bishopDead = true;
	bool knightDead = true;
	bool queenDead = true;
	bool promotionMade = false;
	bool pawnFound = false;
	
	int column = 0;
	string choice;
	if(color == "white"){
	//find if any pawn is in column a-e row 1
		for(int i=1; i < 6; i++){
			if(dummyGameState.getBoardConfig()[1][i]== "WP"){
				column = i;
				pawnFound = true;
			}
		}
				//promote piece to a dead piece
				for(unsigned j=0; j<white.size(); j++){
					if(white[j]->getPieceName() == "R"){
						rookDead = false;
					}
					if(white[j]->getPieceName() == "N"){
						knightDead = false;
					}
					if(white[j]->getPieceName() == "B"){
						bishopDead = false;
					}
					if(white[j]->getPieceName() == "Q"){
						queenDead = false;
					}
				}
				
			if(pawnFound){
				if(rookDead == false && knightDead == false && bishopDead == false && queenDead == false){
					boardConfig[1][column] = "WQ";
					cout << endl;
					cout << "No valid captured pieces to draw from." << endl;
					cout << "Your Pawn has been promoted to a Queen!" << endl;
					promotionMade = true;
				}
				else{
					//Choose what piece you get to promote
					cout << "What piece would you like to promote your Pawn to?" << endl;
					cout << "Enter the first letter capitalized of the piece you choose: ";
					if(queenDead == true){
						cout << "Queen (Q)" << endl;
					}
					if(rookDead == true){
						cout << "Rook (R)" << endl;
					}
					if(knightDead == true){
						cout << "Knight (N)" << endl;
					}
					if(bishopDead ==  true){
						cout << "Bishop (B)" << endl;
					}
					
					cin >> choice;
					while(choice != "R" && choice != "N" && choice != "B" && choice != "Q"){
						cout << "Invalid input. Try again." << endl;
						cin.clear();
						cin.ignore();
						cin >> choice;
					}
					if(choice == "R"){
						boardConfig[1][column] = "WR";
						 promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Rook!" << endl;
					}
					if(choice == "N"){
						boardConfig[1][column] = "WN";
						 promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Knight!" << endl;
					}
					if(choice == "B"){
						boardConfig[1][column] = "WB";
						promotionMade = true;
						cout << "You have chosen to promote your Pawn to a knight!" << endl;
					}
					if(choice == "Q"){
						boardConfig[1][column] = "WQ";
						promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Queen!" << endl;
					}
				}
			}
				return promotionMade;
    }
	else{
			for(int i=1; i < 6; i++){
			if(dummyGameState.getBoardConfig()[6][i]== "BP"){
				column = i;
				pawnFound = true;
			}
			}
				//promote piece to a dead piece
				for(unsigned j=0; j<black.size(); j++){
					if(black[j]->getPieceName() == "R"){
						rookDead = false;
					}
					if(black[j]->getPieceName() == "N"){
						knightDead = false;
					}
					if(black[j]->getPieceName() == "B"){
						bishopDead = false;
					}
					if(black[j]->getPieceName() == "Q"){
						queenDead = false;
					}
				}
			if(pawnFound){
				if(rookDead == false && knightDead == false && bishopDead == false && queenDead == false){
					boardConfig[6][column] = "BQ";
					cout << endl;
					cout << "No valid captured pieces to draw from." << endl;
					cout << "Your Pawn has been promoted to a Queen!" << endl;
					promotionMade = true;
				}
				else{
					//Choose what piece you get to promote
					cout << "What piece would you like to promote your Pawn to?" << endl;
					cout << "Enter the first letter capitalized of the piece you choose: ";
					
					if(rookDead == true){
						cout << "Rook (R)" << endl;
					}
					if(knightDead == true){
						cout << "Knight (N)" << endl;
					}
					if(bishopDead ==  true){
						cout << "Bishop (B)" << endl;
					}
					
					cin >> choice;
					while(choice != "R" && choice != "N" && choice != "B" && choice != "Q"){
						cout << "Invalid input. Try again." << endl;
						cin.clear();
						cin.ignore();
						cin >> choice;
					}
					if(choice == "R"){
						boardConfig[6][column] = "BR";
						promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Rook!" << endl;
					}
					if(choice == "N"){
						boardConfig[6][column] = "BN";
						promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Knight!" << endl;
					}
					if(choice == "B"){
						boardConfig[6][column] = "BB";
						promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Bishop!" << endl;
					}
					if(choice == "Q"){
						boardConfig[6][column] = "BQ";
						promotionMade = true;
						cout << "You have chosen to promote your Pawn to a Queen!" << endl;
					}
				}
			}
				
				return promotionMade;
	}
}
//member function "progPromotePawn"
//this is for program Pawn promotion
//Pre: Parameter is the program's color. checks in the same way as the human promote pawn function.
//     It will always choose pieces in this order. 1. Queen 2. Rook 3. Knight 4. Bishop
//Post:Returns a bool if a promotion has been made
bool GameState::progPromotePawn(string color){
	GameState dummyGameState;
	dummyGameState.setWhite(white);
	dummyGameState.setBlack(black);
	dummyGameState.setBoardConfig(boardConfig);
	bool rookDead = true;
	bool bishopDead = true;
	bool knightDead = true;
	bool queenDead = true;
	bool promotionMade = false;
	bool pawnFound = false;
	int column = 0;
	
	if(color == "white"){
		for(int i=1; i < 6; i++){
				if(dummyGameState.getBoardConfig()[1][i]== "WP"){
					column = i;
					pawnFound = true;
				}
		}
					//find dead pieces: if no
					for(unsigned j=0; j<white.size(); j++){
						if(white[j]->getPieceName() == "R"){
							rookDead = false;
						}
						if(white[j]->getPieceName() == "N"){
							knightDead = false;
						}
						if(white[j]->getPieceName() == "B"){
							bishopDead = false;
						}
						if(white[j]->getPieceName() == "Q")
							queenDead = false;
					}
					
		if(pawnFound){
		if(rookDead == false && knightDead == false && bishopDead == false && queenDead == false){
					boardConfig[1][column] = "WQ";
					cout << endl;
					cout << "No valid captured pieces to draw from." << endl;
					cout << "The progam's Pawn has been promoted to a Queen!" << endl;
					promotionMade = true;
				}
		if(queenDead == true){
			boardConfig[1][column] = "WQ";
			cout << "The program chose to promote it's Pawn to a Queen" << endl;
			promotionMade =  true;
		}
		else if(rookDead == true){
			boardConfig[1][column] = "WR";
			cout << "The program chose to promote it's Pawn to a Rook" << endl;
			promotionMade =  true;
		}
		else if(knightDead == true){
			boardConfig[1][column] = "WN";
			cout << "The program chose to promote it's Pawn to a Knight" << endl;
			promotionMade =  true;
		}
		else if(bishopDead == true){
			boardConfig[1][column] = "WB";
			cout << "The program chose to promote it's Pawn to a Bishop" << endl;
			promotionMade =  true;
		}
		}
		return promotionMade;
	}
	else{
		for(int i=1; i < 6; i++){
				if(dummyGameState.getBoardConfig()[1][i]== "BP"){
					column = i;
					pawnFound = true;
				}
		}
					//promote piece to a dead piece
					for(unsigned j=0; j<white.size(); j++){
						if(black[j]->getPieceName() == "R"){
							rookDead = false;
						}
						if(black[j]->getPieceName() == "N"){
							knightDead = false;
						}
						if(black[j]->getPieceName() == "B"){
							bishopDead = false;
						}
						if(black[j]->getPieceName() ==  "Q"){
							queenDead = false;
						}
							
					}
		if(pawnFound){
		if(rookDead == false && knightDead == false && bishopDead == false && queenDead == false){
					boardConfig[6][column] = "BQ";
					cout << endl;
					cout << "No valid captured pieces to draw from." << endl;
					cout << "The progam's Pawn has been promoted to a Queen!" << endl;
					promotionMade = true;
				}
		if(queenDead == true){
			boardConfig[6][column] = "BQ";
			cout << "The program chose to promote it's Pawn to a Queen" << endl;
			promotionMade =  true;
		}
		else if(rookDead == true){
			boardConfig[6][column] = "BR";
			cout << "The program chose to promote it's Pawn to a Rook" << endl;
			promotionMade =  true;
		}
		else if(knightDead == true){
			boardConfig[6][column] = "BN";
			cout << "The program chose to promote it's Pawn to a Knight" << endl;
			promotionMade =  true;
		}
		else if(bishopDead == true){
			boardConfig[6][column] = "BB";
			cout << "The program chose to promote it's Pawn to a Bishop" << endl;
			promotionMade =  true;
		}
		}
	 return promotionMade;
	}
}
