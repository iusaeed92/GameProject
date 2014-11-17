//
//  main.cpp
//  testingGit
//
//  Created by Ibrahim Saeed on 10/8/14.
//  Copyright (c) 2014 Ibrahim Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Piece.h"
#include "GameState.h"

using namespace std;

int main()
{
    
    ////
    ////Initial configuration
    ////
    ////Variables for the white pieces
    ////
    int rowWP1;
    char letterWP1;
    int columnWP1;
    Pawn whitePawn1;
    
    int rowWP2;
    char letterWP2;
    int columnWP2;
    Pawn whitePawn2;
    
    int rowWP3;
    char letterWP3;
    int columnWP3;
    Pawn whitePawn3;
    
    int rowWP4;
    char letterWP4;
    int columnWP4;
    Pawn whitePawn4;
    
    int rowWP5;
    char letterWP5;
    int columnWP5;
    Pawn whitePawn5;
    
    int rowWN;
    char letterWN;
    int columnWN;
    Knight whiteKnight;
    
    int rowWB;
    char letterWB;
    int columnWB;
    Bishop whiteBishop;
    
    int rowWR;
    char letterWR;
    int columnWR;
    Rook whiteRook;
    
    int rowWQ;
    char letterWQ;
    int columnWQ;
    Queen whiteQueen;
    
    int rowWK;
    char letterWK;
    int columnWK;
    King whiteKing;
    
    ////
    ////Variables for the black pieces
    ////
    int rowBP1;
    char letterBP1;
    int columnBP1;
    Pawn blackPawn1;
    
    int rowBP2;
    char letterBP2;
    int columnBP2;
    Pawn blackPawn2;
    
    int rowBP3;
    char letterBP3;
    int columnBP3;
    Pawn blackPawn3;
    
    int rowBP4;
    char letterBP4;
    int columnBP4;
    Pawn blackPawn4;
    
    int rowBP5;
    char letterBP5;
    int columnBP5;
    Pawn blackPawn5;
    
    int rowBN;
    char letterBN;
    int columnBN;
    Knight blackKnight;
    
    int rowBB;
    char letterBB;
    int columnBB;
    Bishop blackBishop;
    
    int rowBR;
    char letterBR;
    int columnBR;
    Rook blackRook;
    
    int rowBQ;
    char letterBQ;
    int columnBQ;
    Queen blackQueen;
    
    int rowBK;
    char letterBK;
    int columnBK;
    King blackKing;
    
    ////
    ////Input of coordinates for all pieces
    ////
    cout << "Input the position of white pawn (1). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP1;
    cin >> letterWP1;
    columnWP1 = letterWP1 - 96;
    whitePawn1.setPieceCoordinates(rowWP1, columnWP1);
    
    cout << "Input the position of white pawn (2). First enter the row (1-6). Then the column(a-e):" << endl;
    cin >> rowWP2;
    cin >> letterWP2;
    columnWP2 = letterWP2 - 96;
    whitePawn2.setPieceCoordinates(rowWP2, columnWP2);
    
    
    return 0;
}
