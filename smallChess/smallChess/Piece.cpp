//
//  Piece.cpp
//  testingGit
//
//  Created by Ibrahim Saeed on 10/28/14.
//  Copyright (c) 2014 Ibrahim Saeed. All rights reserved.
//

#include<iostream>
#include<exception>

#include<string>
#include "Piece.h"

using namespace std; 






//constructors
//Piece::Piece(){};

/*Piece::Piece(string n, string c, int w, pair<int,int> coords){
	name = n;
	color = c;
	weight = w;
	pieceCoordinates = coords;
}*/

vector<pair<unsigned,unsigned> >  Piece::generatePossibleMoves (GameState currentGameState){
	vector<pair<unsigned, unsigned> > possiblePawnMoves;
	possiblePawnMoves.push_back(make_pair(1,1));
}


//mutators:
void Piece::setPieceName(string s){
    name = s;
}
void Piece::setPieceColor(string s){
    color = s;
}
void Piece::setPieceWeight(int w){
    weight = w;
}
void Piece::setPieceCoordinates(int x, int y){
    pieceCoordinates.first = x;
    pieceCoordinates.second = y;
}

//accessors
string Piece::getPieceName(){
    
    return name;
    
}

string Piece::getPieceColor(){
    return color;
}

int Piece::getPieceWeight(){
 
    return weight;
}

pair<int, int> Piece::getPieceCoordinates(){
    return pieceCoordinates;
}

//MemberFunction isSameColor
//Pre Conditions: Parameters are a GameState and a pair of coordinates
//Post Conditions: Returns a boolean true or false depending on if the piece in the coordinates
//                 being evaluated is the same color as the member piece.

bool Piece::isSameColor(GameState instance, pair<int, int> coordinates){
	
	if(instance.getBoardConfig()[coordinates.first][coordinates.second][0] == color[0]){
		return true;
	}
	else if(instance.getBoardConfig()[coordinates.first][coordinates.second] == "empty")
			return true;
			
	else if(instance.getBoardConfig()[coordinates.first][coordinates.second] == "outOfBounds")
			return true;
			
	else
		return false;
}



//Function diagonalMoves
//Pre Conditions: Parameters are a GameState, a Piece, and a direction integer 1 through 4
//Post Conditions: Returns an integer that tells how many spaces are valid for moves of that
// 					 piece in that certain direction.
int diagonalMoves(GameState instance, Piece* currPiece, int direction){
	int movesSoFar = 0;
	pair <int, int> localCoord = currPiece->getPieceCoordinates();
	
	
    if(direction == 1){
		localCoord.first = localCoord.first - 1;
		localCoord.second = localCoord.second + 1;
		
	while(instance.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
	
			movesSoFar = movesSoFar+1;
			localCoord.first = localCoord.first -1 ;
			localCoord.second = localCoord.second + 1;
			}
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] != "outOfBounds"){
			pair<int,int> test;
			test = make_pair(localCoord.first, localCoord.second);
		
			if(currPiece->isSameColor(instance, test) == false)
				movesSoFar =  movesSoFar+1;
			
		}
		
		return movesSoFar;
	}
    
    else if(direction == 2){
		localCoord.first = localCoord.first - 1;
		localCoord.second = localCoord.second - 1;
		
		while(instance.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
	
			movesSoFar = movesSoFar+1;
			localCoord.first = localCoord.first-1;
			localCoord.second = localCoord.second-1;
			}
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] != "outOfBounds"){
			pair<int,int> test;
			test = make_pair(localCoord.first, localCoord.second);
		
			if(currPiece->isSameColor(instance, test) == false)
				movesSoFar =  movesSoFar+1;
			
		}
		
		return movesSoFar;
	}
    else if(direction == 3){
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second-1;
		
		while(instance.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
	
			movesSoFar = movesSoFar+1;
			localCoord.first = localCoord.first+1;
			localCoord.second = localCoord.second-1;
			}
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] != "outOfBounds"){
			pair<int,int> test;
			test = make_pair(localCoord.first, localCoord.second);
		
			if(currPiece->isSameColor(instance, test) == false)
				movesSoFar =  movesSoFar+1;
			
		}
		
		return movesSoFar;
	}
    
    else if(direction == 4){
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second+1;
		
		while(instance.getBoardConfig()[localCoord.first][ localCoord.second] == "empty"){
	
			movesSoFar = movesSoFar+1;
			localCoord.first = localCoord.first+1;
			localCoord.second = localCoord.second+1;
			}
		
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] != "outOfBounds"){
			pair<int,int> test;
			test = make_pair(localCoord.first, localCoord.second);
		
			if(currPiece->isSameColor(instance, test) == false)
				movesSoFar =  movesSoFar+1;
			
		}
		
		return movesSoFar;
	}
}

//Function straightMoves
//Pre Conditions: Parameters are a GameState, a Piece, and a direction integer 1 through 4
//Post Conditions: Returns an integer that tells how many spaces are valid for moves of that
// 					 piece in that certain direction.
int straightMoves(GameState instance, Piece* currPiece, int direction){
	pair<int, int> localCoord = currPiece->getPieceCoordinates();
	int movesSoFar = 0;
	
	if(direction == 1){
		localCoord.first = localCoord.first-1;
		
		while(instance.getBoardConfig()[localCoord.first][localCoord.second] == "empty"){
			movesSoFar = movesSoFar+1;
			localCoord.first = localCoord.first-1;
			}
			
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] == "outOfBounds")
			return movesSoFar;
		
		if(currPiece->isSameColor(instance, make_pair(localCoord.first, localCoord.second)) == false)
			movesSoFar =  movesSoFar+1;
		
		return movesSoFar;
	}
    
    else if(direction == 2){
		localCoord.first = localCoord.first+1;
		
		while(instance.getBoardConfig()[localCoord.first][ localCoord.second] == "empty"){
			movesSoFar = movesSoFar+1;
			localCoord.first = localCoord.first+1;
			}
			
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] == "outOfBounds")
			return movesSoFar;
		
		if(currPiece->isSameColor(instance, make_pair(localCoord.first, localCoord.second)) == false)
			movesSoFar =  movesSoFar+1;
		
		return movesSoFar;
	}

    else if(direction == 3){
		
		localCoord.second = localCoord.second-1;

		while(instance.getBoardConfig()[localCoord.first][ localCoord.second] == "empty"){
			movesSoFar = movesSoFar+1;
			localCoord.second = localCoord.second-1;
			}
			
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] == "outOfBounds")
			return movesSoFar;
		
		if(currPiece->isSameColor(instance, make_pair(localCoord.first, localCoord.second)) == false)
			movesSoFar =  movesSoFar+1;
			
		return movesSoFar;
	}

    else if(direction == 4){
		localCoord.second = localCoord.second+1;
		
		while(instance.getBoardConfig()[localCoord.first][ localCoord.second] == "empty"){
	
			movesSoFar = movesSoFar+1;
			localCoord.second = localCoord.second+1;
			}
			
		if(instance.getBoardConfig()[localCoord.first][localCoord.second] == "outOfBounds")
			return movesSoFar;
		
		if(currPiece->isSameColor(instance, make_pair(localCoord.first, localCoord.second)) == false)
			movesSoFar =  movesSoFar+1;

		return movesSoFar;
	}
}









////////////////////////////////////////////
//SUBCLASSES
//
//	Each subclass contains a function called generate possible moves
// Pre Conditions: It takes gamestate and also takes member pieceCoordinates internally
// Post Conditions: Returns a vector of pairs of ints that is coordinates for possible (valid) moves
//                  for the piece in question                

//Pawn

vector<pair<unsigned,unsigned> >  Pawn::generatePossibleMoves (GameState currentGameState){
	
	vector<pair<unsigned, unsigned> > possiblePawnMoves;
	pair<int, int> localCoord = pieceCoordinates;
//	Pawn thisPawn(name, color, weight, pieceCoordinates);
	
		//check if space ahead is empty if it is then place that spaces coordinate on vector
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second] == "empty"){
		pair <int, int> test;
		test = make_pair(localCoord.first-1, localCoord.second);
		
		possiblePawnMoves.push_back(test);
		}
	
		//check the diagonal one space ahead, if it is opposing piece push on the vector
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second+1] != "empty"
		&& currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second+1] != "outOfBounds"){
		if(this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second+1)) == false){
			possiblePawnMoves.push_back(make_pair(localCoord.first-1, localCoord.second+1));
	
		}
	}
		
		//check other diagonal
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second-1] != "empty"
		&& currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second-1] != "outOfBounds"){
		if(this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second-1)) == false){
			possiblePawnMoves.push_back(make_pair(localCoord.first-1, localCoord.second-1));
	
		}
	}
		
	return possiblePawnMoves;
	}
	
	
	
	
	
	
	
/////////////////	
//Bishop	
	
vector<pair<unsigned,unsigned> >  Bishop::generatePossibleMoves (GameState currentGameState){
	vector<pair<unsigned, unsigned> > possibleBishopMoves;
	pair<int, int> localCoord = pieceCoordinates;
//	Piece thisBishop(name, color, weight, pieceCoordinates);
	
	int movesDiagUpRight = diagonalMoves(currentGameState, this, 1);
	int movesDiagUpLeft = diagonalMoves(currentGameState, this, 2);
	int movesDiagDownLeft = diagonalMoves(currentGameState, this, 3);
	int movesDiagDownRight = diagonalMoves(currentGameState, this, 4);
	
	for(int i = 0; i<movesDiagUpRight; i++){
		localCoord.first = localCoord.first-1;
		localCoord.second = localCoord.second+1;
		pair<int, int> temp;
		temp = make_pair(localCoord.first, localCoord.second);
		possibleBishopMoves.push_back(temp);
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDiagUpLeft; i++){
		
		localCoord.first = localCoord.first-1;
		localCoord.second = localCoord.second-1;
		pair<int, int> temp;
		temp = make_pair(localCoord.first, localCoord.second);
		possibleBishopMoves.push_back(temp);
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDiagDownLeft; i++){
		
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second-1;
		pair<int, int> temp;
		temp = make_pair(localCoord.first, localCoord.second);
		possibleBishopMoves.push_back(temp);
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDiagDownRight; i++){
		
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second+1;
		pair<int, int> temp;
		temp = make_pair(localCoord.first, localCoord.second);
		possibleBishopMoves.push_back(temp);
	}
	
	return possibleBishopMoves;
	
	
	
	

	}
	
//////////////////	
//Knight

vector<pair<unsigned,unsigned> >  Knight::generatePossibleMoves (GameState currentGameState){
	
	vector<pair<unsigned, unsigned> > possibleKnightMoves;
	pair<int, int> localCoord = pieceCoordinates;
//	Piece thisKnight(name, color, weight, pieceCoordinates);
	//-1,+2
	
	try{
		currentGameState.getBoardConfig()[localCoord.first-1].at(localCoord.second+2);
		if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second+2] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second+2)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first-1, localCoord.second+2));
		}
	}
	catch(exception& e){
		  //catches out of range exception
	  }
	
		
		 
	
	
	
	//+1,+2
	
	  try{
		currentGameState.getBoardConfig()[localCoord.first+1].at(localCoord.second+2);
		if(currentGameState.getBoardConfig()[localCoord.first+1][localCoord.second+2] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+1,localCoord.second+2)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first+1, localCoord.second+2));
		}
	  
	  }
	 catch(exception& e){
		  //catches out of range exception
	  }
		
	

	//-1, -2
	try{
		currentGameState.getBoardConfig()[localCoord.first-1].at(localCoord.second-2);
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second-2] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second-2)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first-1, localCoord.second-2));
		}
	}
	catch(exception& e){
		  //catches out of range exception
	  }
	
	//+1, -2
	try{
		currentGameState.getBoardConfig()[localCoord.first+1].at(localCoord.second-2);
	if(currentGameState.getBoardConfig()[localCoord.first+1][localCoord.second-2] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+1,localCoord.second-2)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first+1, localCoord.second-2));
		}
	}
	catch(exception& e){
//catches out of range exception
	  }
	
	//+2, +1
   try{
		currentGameState.getBoardConfig().at(localCoord.first+2).at(localCoord.second+1);
	if(currentGameState.getBoardConfig()[localCoord.first+2][localCoord.second+1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+2,localCoord.second+1)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first+2, localCoord.second+1));
		}
	}
	
	catch(exception& e){
		  //catches out of range exception
	  }
	
	//+2, -1
	try{
		currentGameState.getBoardConfig().at(localCoord.first+2).at(localCoord.second-1);
		if(currentGameState.getBoardConfig()[localCoord.first+2][localCoord.second-1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+2,localCoord.second-1)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first+2, localCoord.second-1));
		}
		
	}
	catch(exception& e){
		  //catches out of range exception
	  }
	
	//-2, +1
	try{
		currentGameState.getBoardConfig().at(localCoord.first-2).at(localCoord.second+1);
	if(currentGameState.getBoardConfig()[localCoord.first-2][localCoord.second+1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-2,localCoord.second+1)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first-2, localCoord.second+1));
		}
	}
	catch(exception& e){
		  //catches out of range exception
	  }
	
	//-2, -1
	try{
		currentGameState.getBoardConfig().at(localCoord.first-2).at(localCoord.second-1);
	if(currentGameState.getBoardConfig()[localCoord.first-2][localCoord.second-1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-2,localCoord.second-1)) == false){
		
		possibleKnightMoves.push_back(make_pair(localCoord.first-2, localCoord.second-1));
		}
	}
	catch(exception& e){
		  //catches out of range exception
	  }
	
	return possibleKnightMoves;
}
////////////////	
//Rook

vector<pair<unsigned,unsigned> >  Rook::generatePossibleMoves (GameState currentGameState){
	
	vector<pair<unsigned, unsigned> > possibleRookMoves;
	pair<int, int> localCoord = pieceCoordinates;
//	Piece thisRook(name, color, weight, pieceCoordinates);
	
	int movesUp = straightMoves(currentGameState, this, 1);
	int movesDown = straightMoves(currentGameState, this, 2);
	int movesLeft = straightMoves(currentGameState, this, 3);
	int movesRight = straightMoves(currentGameState, this, 4);
	
	for(int i = 0; i<movesUp; i++){
		localCoord.first = localCoord.first-1;
		possibleRookMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDown; i++){
		
		localCoord.first = localCoord.first+1;
		possibleRookMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesLeft; i++){
		
	
		localCoord.second = localCoord.second-1;
		possibleRookMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesRight; i++){
		
		
		localCoord.second = localCoord.second+1;
		possibleRookMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	return possibleRookMoves;
	
	
	
	

	}
///////////////	
//Queen

vector<pair<unsigned,unsigned> >  Queen::generatePossibleMoves (GameState currentGameState){
	
	vector<pair<unsigned, unsigned> > possibleQueenMoves;
	pair<int, int> localCoord = pieceCoordinates;
//	Piece thisQueen(name, color, weight, pieceCoordinates);
	
	int movesDiagUpRight = diagonalMoves(currentGameState, this, 1);
	int movesDiagUpLeft = diagonalMoves(currentGameState, this, 2);
	int movesDiagDownLeft = diagonalMoves(currentGameState, this, 3);
	int movesDiagDownRight = diagonalMoves(currentGameState, this, 4);
	int movesUp = straightMoves(currentGameState, this, 1);
	int movesDown = straightMoves(currentGameState, this, 2);
	int movesLeft = straightMoves(currentGameState, this, 3);
	int movesRight = straightMoves(currentGameState, this, 4);

	
	
	for(int i = 0; i<movesDiagUpRight; i++){
		localCoord.first = localCoord.first-1;
		localCoord.second = localCoord.second+1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDiagUpLeft; i++){
		
		localCoord.first = localCoord.first-1;
		localCoord.second = localCoord.second-1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDiagDownLeft; i++){
		
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second-1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDiagDownRight; i++){
		
		localCoord.first = localCoord.first+1;
		localCoord.second = localCoord.second+1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesUp; i++){
		localCoord.first = localCoord.first-1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesDown; i++){
		
		localCoord.first = localCoord.first+1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesLeft; i++){
		
	
		localCoord.second = localCoord.second-1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	localCoord = pieceCoordinates;
	for(int i = 0; i<movesRight; i++){
		
		
		localCoord.second = localCoord.second+1;
		possibleQueenMoves.push_back(make_pair(localCoord.first, localCoord.second));
	}
	
	return possibleQueenMoves;

	}

/////////////	
//King

vector<pair<unsigned,unsigned> >  King::generatePossibleMoves (GameState currentGameState){
	
	vector<pair<unsigned, unsigned> > possibleKingMoves;
//	Piece thisKing(name, color, weight, pieceCoordinates);
	pair<int, int> localCoord = pieceCoordinates;
	
		//check if space ahead is empty if it is then place that spaces coordinate on vector
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second] == "empty" 
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second)) == false){
		
		possibleKingMoves.push_back(make_pair(localCoord.first-1, localCoord.second));
		}
		
		//check if space behind is empty
	if(currentGameState.getBoardConfig()[localCoord.first+1][localCoord.second] == "empty" 
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+1,localCoord.second)) == false){
		
		possibleKingMoves.push_back(make_pair(localCoord.first+1, localCoord.second));
		}
		
		//check if space left is empty
	if(currentGameState.getBoardConfig()[localCoord.first][localCoord.second-1] == "empty" 
		|| this->isSameColor(currentGameState, make_pair(localCoord.first,localCoord.second-1)) == false){
		
		possibleKingMoves.push_back(make_pair(localCoord.first, localCoord.second-1));
		}
		
		//check if space right is empty
	if(currentGameState.getBoardConfig()[localCoord.first][localCoord.second+1] == "empty" 
		|| this->isSameColor(currentGameState, make_pair(localCoord.first,localCoord.second+1)) == false){
		
		possibleKingMoves.push_back(make_pair(localCoord.first, localCoord.second+1));
		}
		
		//check right diagonal(forward) 
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second+1] == "empty" 
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second+1)) == false){
	
		possibleKingMoves.push_back(make_pair(localCoord.first-1, localCoord.second+1));
		}
		
		//check left diagonal(foward)
	if(currentGameState.getBoardConfig()[localCoord.first-1][localCoord.second-1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first-1,localCoord.second-1)) == false){
	
		possibleKingMoves.push_back(make_pair(localCoord.first-1, localCoord.second-1));
		}
		
		//check back left diagonal
	if(currentGameState.getBoardConfig()[localCoord.first+1][localCoord.second-1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+1,localCoord.second-1)) == false){
	
		possibleKingMoves.push_back(make_pair(localCoord.first+1, localCoord.second-1));
		}
	
		//check back right diagonal
	if(currentGameState.getBoardConfig()[localCoord.first+1][localCoord.second+1] == "empty"
		|| this->isSameColor(currentGameState, make_pair(localCoord.first+1,localCoord.second+1)) == false){
	
		possibleKingMoves.push_back(make_pair(localCoord.first+1, localCoord.second+1));
		}
		
	return possibleKingMoves;
	}




