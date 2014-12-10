//
// GameState.cpp
//

#include <vector>
#include <string>
#include "GameState.h"

using namespace std; 


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

int GameState::whiteHeuristicValue(){
	int heuristicValue = 0;
	
	for(unsigned i = 0; i < white.size(); i++){
		heuristicValue = white[i]->getPieceWeight() + heuristicValue;
	}
	
	return heuristicValue;
}

int GameState::blackHeuristicValue(){
	int heuristicValue = 0;
	
	for(unsigned i = 0; i < black.size(); i++){
		heuristicValue = black[i]->getPieceWeight() + heuristicValue;
	}
	
	return heuristicValue;
}

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
			cout << black[i]->getPieceName() << endl;
			cout << black.size() << endl;
			
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
			//traverse to see if any possible move matches the black kings coordinates
			vector< pair<unsigned,unsigned> > whiteMoves;
			for(unsigned i=0; i < white.size(); i++){
				whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
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
	
	if(color == "white"){
		//find king
		for(unsigned i=0; i < white.size(); i++){
			if(white[i]->getPieceName() == "K"){
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
			//iterate from the king's position out in all eight directions to find enemy piece path.
			//once found, iterate through path seeing if friendly pieces can occupy them.
			
			int path = findPath(kingCoords, "white", dummyGameState);
			
			if(path == 1){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first-1][localCoord.second] == "empty"){
					for(unsigned i=0; i < white.size(); i++){
						whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
						for(unsigned j=0; j < whiteMoves.size(); j++){
							if(make_pair(localCoord.first-1, localCoord.second) == whiteMoves[j]){
							canBlock = true;
				        }
					  }
				    }
				}
			}
			if(path == 2){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first+1][localCoord.second] == "empty"){
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 3){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second-1] == "empty"){
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first, localCoord.second-1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 4){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second+1] == "empty"){
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 5){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first-1][localCoord.second+1] == "empty"){
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first-1, localCoord.second+1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 6){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first+1][localCoord.second+1] == "empty"){
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 7){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first+1][localCoord.second-1] == "empty"){
				for(unsigned i=0; i < white.size(); i++){
					whiteMoves = white[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < whiteMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second-1) == whiteMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 8){
				vector< pair<unsigned,unsigned> > whiteMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first-1][localCoord.second-1] == "empty"){
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
		//now test all spaces around king to see if it can move to any without remaining in check
		if(dummyGameState.isThreatened(make_pair(kingCoords.first+1,kingCoords.second), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first-1,kingCoords.second), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first,kingCoords.second+1), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first,kingCoords.second-1), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first+1,kingCoords.second-1), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first+1,kingCoords.second+1), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first-1,kingCoords.second-1), "white") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first-1,kingCoords.second+1), "white") == false){
			canMove = true;
		}
		else{
			canMove =false;
		}
		if(capThreat == false || canBlock == false || canMove == false){
				return true;
			}
			else{
				return false;
			}
	}
	else{
		//find king
		for(unsigned i=0; i < black.size(); i++){
			if(black[i]->getPieceName() == "K"){
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
			
			int path = findPath(kingCoords, "black", dummyGameState);
			
			if(path == 1){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first-1][localCoord.second] == "empty"){
					for(unsigned i=0; i < black.size(); i++){
						blackMoves = black[i]->generatePossibleMoves(dummyGameState);
						for(unsigned j=0; j <blackMoves.size(); j++){
							if(make_pair(localCoord.first-1, localCoord.second) == blackMoves[j]){
							canBlock = true;
				        }
					  }
				    }
				}
			}
			if(path == 2){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first+1][localCoord.second] == "empty"){
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 3){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second-1] == "empty"){
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first, localCoord.second-1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 4){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first][localCoord.second+1] == "empty"){
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 5){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first-1][localCoord.second+1] == "empty"){
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first-1, localCoord.second+1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 6){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first+1][localCoord.second+1] == "empty"){
				for(unsigned i=0; i < black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second+1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 7){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first+1][localCoord.second-1] == "empty"){
				for(unsigned i=0; i <black.size(); i++){
					blackMoves = black[i]->generatePossibleMoves(dummyGameState);
					for(unsigned j=0; j < blackMoves.size(); j++){
						if(make_pair(localCoord.first+1, localCoord.second-1) == blackMoves[j]){
							canBlock = true;
					    }
				    }
			      }
				}
			}
			if(path == 8){
				vector< pair<unsigned,unsigned> > blackMoves;
				while(dummyGameState.getBoardConfig()[localCoord.first-1][localCoord.second-1] == "empty"){
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
		//now test all spaces around king to see if it can move to any without remaining in check
		if(dummyGameState.isThreatened(make_pair(kingCoords.first+1,kingCoords.second), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first-1,kingCoords.second), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first,kingCoords.second+1), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first,kingCoords.second-1), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first+1,kingCoords.second-1), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first+1,kingCoords.second+1), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first-1,kingCoords.second-1), "black") == false
		|| dummyGameState.isThreatened(make_pair(kingCoords.first-1,kingCoords.second+1), "black") == false){
			canMove = true;
		}
		else{
			canMove = false;
		}
		if(capThreat == false || canBlock == false || canMove == false){
				return true;
			}
			else{
				return false;
			}
	}
}
		
	
	
	

	
	