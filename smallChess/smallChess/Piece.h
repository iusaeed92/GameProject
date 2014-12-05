//
//  Piece.h
//  testingGit
//
//  Created by Ibrahim Saeed on 10/28/14.
//  Copyright (c) 2014 Ibrahim Saeed. All rights reserved.
//

#ifndef Piece_H
#define Piece_H

#include <stdio.h>
#include <string>
#include <utility> 
#include <vector>
#include "GameState.h"

using namespace std;

class Piece {

private:
public:
    
    string name;
    string color;
    int weight;
    pair<int, int> pieceCoordinates;
    
	bool isSameColor(GameState instance, pair<int, int> coordinates);
	
//	Piece();
//	Piece(string n, string c, int w, pair<int,int> coords);

	//mutators:
    void setPieceName(string s);
    void setPieceColor(string s);
    void setPieceWeight(int w);
    void setPieceCoordinates(int x, int y);
    
    //accessors
	string getPieceName();
	string getPieceColor();
	int getPieceWeight();
	pair<int, int> getPieceCoordinates();
	virtual vector<pair<unsigned, unsigned> > generatePossibleMoves(GameState currentGameState);
	
    //move
    //virtual void movePiece(
    
    
    
};



////////////////////////////////////////////
// SUBCLASSES

////////////////
//PAWN

class Pawn: public Piece{
	
public:
	
	
	virtual vector<pair<unsigned,unsigned> > generatePossibleMoves (GameState currentGameState);
	
	
	 
};

//////////////////
//Bishop

class Bishop: public Piece{
	
public:
	
	
	virtual vector<pair<unsigned,unsigned> > generatePossibleMoves (GameState currentGameState);
	
	
	 
};

//////////////////
//Knight

class Knight: public Piece{
	
public:
	
	
	virtual vector<pair<unsigned,unsigned> > generatePossibleMoves (GameState currentGameState);
	
	
	 
};

//////////////////
//Castle


class Rook: public Piece{

	
public:
	
	
	virtual vector<pair<unsigned,unsigned> > generatePossibleMoves (GameState currentGameState);
	
	
	 
};

/////////////////
//Queen

class Queen: public Piece{
	
public:
	
	
	virtual vector<pair<unsigned,unsigned> > generatePossibleMoves (GameState currentGameState);
	
	
	 
};

////////////////
//King

class King: public Piece{
	
public:
	
	
	virtual vector<pair<unsigned,unsigned> > generatePossibleMoves (GameState currentGameState);
	
	
	 
};


#endif /* defined(__testingGit__Piece__) */








