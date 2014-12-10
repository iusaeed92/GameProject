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

int GameState::blackHeuristicValue(){
	int heuristicValue = 0;
	
	for(unsigned i = 0; i < black.size(); i++){
		heuristicValue = black[i]->getPieceWeight() + heuristicValue;
	}
	
	return heuristicValue;
}

