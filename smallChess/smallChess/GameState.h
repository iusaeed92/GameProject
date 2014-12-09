//
//	GameState.h
//

#include <iostream>
#include <vector>
#include "Piece.h"


#ifndef GameState_H
#define GameState_H

#include <iostream>
#include <vector>
#include <string>
#include "Piece.h"



using namespace std;

class Piece;

class GameState {
	
private:

	vector <Piece*> white;
	vector <Piece*> black;
	vector <vector <string > > boardConfig;
	
	
public:

    
	GameState gameState();
	void setWhite(vector <Piece*> x);
	void setBlack(vector <Piece*> y);
	void setBoardConfig(vector<vector<string> > board);
	bool kingInCheck(string color);
	bool isThreatened(pair<unsigned,unsigned> squareToCheck, string color);
	vector <Piece*> getWhite();
	vector <Piece*> getBlack();
	vector<vector<string> > getBoardConfig();
	void print();
	int whiteHeuristicValue();
	int blackHeuristicValue();

};


///////
///// Testing kingInCheck	
/*	string test = "white";
	if(initialGame.isThreatened(make_pair(6,3), test) == true){
		cout << "it worked" << endl;
	}
	
	else{
		cout << "Fuck me" << endl; 
	}
*/
#endif
