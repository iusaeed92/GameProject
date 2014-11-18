//
// GameState.cpp
//

#include <vector>
#include <string>
#include "GameState.h"

using namespace std; 

void GameState::setWhite(vector <Piece> x){
	white = x;
}

void GameState::setBlack(vector <Piece> y){
	black = y;
}

void GameState::setBoardConfig(vector<vector<string> > board){
	boardConfig = board;
}

vector <Piece> GameState::getWhite(){
	return white;
}

vector <Piece> GameState::getBlack(){
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
				cout << "--" << " | ";
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