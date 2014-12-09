//
// GameState.cpp
//

#include <vector>
#include <string>
#include "GameState.h"

using namespace std; 

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
			pair<unsigned, unsigned> testSquare = squareToCheck;
			//create all possible moves for black
			//traverse to see if any possible move matches the white kings coordinates
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
	
	