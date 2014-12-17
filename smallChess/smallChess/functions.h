//
//H file for functions used in main
//

pair <int, int> negaMax(vector <vector <string> > currBoard, int depth, string color);
vector <GameState> makeBoards(GameState currBoard, string color);
pair<Piece*, bool> retrievePiece(GameState currGame, string moveColor, string Name, pair<int, int> start);
bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result);
void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);
void searchMovePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);
bool isBoardEqual(vector <vector <string> > boardOne, vector <vector <string> > boardTwo);
vector <pair <unsigned, unsigned> > removeCheckMoves(vector <pair <unsigned, unsigned> > withCheckMoves, GameState currState, string color, pair <int, int> start, string name);

/* 
vector < vector <string > > (gameState &currentGameState, double moveTime) {
 
 
 <pair <unsigned, unsigned> bestMoveSoFar;
 vector < vector <vector <string> >  >expandedBoards;
 vector < vector < string > > doThis;
 int winner = 0;
 
 Here you start the clock.
 
 and while the timer is running, you go into the search. 
 when the timer runs out, leave the loop with the best move you have so far.
 
    while (secondsGone < moveTime) {
 
 
        expandedBoards = makeBoards(currentGameState); 
        makeHeuristicPairs(expandedBoards, worklist);
        winner = negamax((expandedBoards, ?, white, worklist);
        doThis = worklist.top();

 
 
    }
 return doThis;
 
 }
 
 
 */


//Negamax function for Quick Chess
//Pre-cond:	currBoard is the current board that negamax is determining a move for
//				depth is the int number of levels negamax will search in the game tree
//				color is the string (white/black) that negamax is finding a move for
//Post-cond:	returns a pair with the first element equal to the best heuristic found
//				the second element holds the number of the element of the vector produced
//				by makeBoards for the current board and color. i.e. It is the element
//				number that holds the best board that was determined by negamax
pair <int, int> negaMax(vector <vector <string> > currBoard, int depth, string color){
	GameState currState;
	currState.setBoardConfig(currBoard);
	currState.makeVectors();
	
	if(depth > 2){
		if(color == "white"){
			return make_pair(-currState.heuristicValue(), -1000);
		}
		else{
			return make_pair(currState.heuristicValue(), -1000);
		}
	}
	
	int bestHeuristic = -1000000;
	int boardNum;
	vector <GameState> movesForCurrBoard = makeBoards(currState, color);
	for(unsigned i = 0; i < movesForCurrBoard.size(); i++){
		pair <int, int> x;
		if(color == "white"){
			x.first = negaMax(movesForCurrBoard[i].getBoardConfig(), depth+1, "black").first;
		}
		else{
			x.first = negaMax(movesForCurrBoard[i].getBoardConfig(), depth+1, "white").first;
		}
		
		if(x.first > bestHeuristic){
			bestHeuristic = x.first;
			boardNum = i;
		}
	}
	
	return make_pair(-bestHeuristic, boardNum);
}


//makeBoards function to make all possible moves in currBoard for color
//Pre-cond:	currBoard is the current board of the game
//				color is the string (white/black) that makeBoards will
//					generate the boards from
//Post-cond:	returns a vector of GameStates with all the possible
//					boardConfigs based on all possible moves for color
//					in currBoard
vector <GameState> makeBoards(GameState currBoard, string color){
	vector <pair <unsigned, unsigned> > possibleMovesForI;
	vector <pair <unsigned, unsigned> > possibleMovesForI2;
	vector <GameState> gameStates;
	GameState newBoard;
	newBoard=currBoard;

    if (color == "white"){

		for(unsigned i = 0; i < currBoard.getWhite().size(); i++){
			possibleMovesForI = currBoard.getWhite()[i]->generatePossibleMoves(currBoard);
			possibleMovesForI2 = removeCheckMoves(possibleMovesForI, currBoard, color, currBoard.getWhite()[i]->getPieceCoordinates(), currBoard.getWhite()[i]->getPieceName());
			
			pair<int, int> thisPieceCoords = newBoard.getWhite()[i]->getPieceCoordinates();
			
			for(unsigned j = 0; j < possibleMovesForI2.size(); j++){
				newBoard.setBoardConfig(currBoard.getBoardConfig());
				searchMovePiece(newBoard, "white", thisPieceCoords, possibleMovesForI2[j]);
				gameStates.push_back(newBoard);
			}
		}
		
		return gameStates;
	}
	
    else {
        for(unsigned i = 0; i < currBoard.getBlack().size(); i++){
			possibleMovesForI = currBoard.getBlack()[i]->generatePossibleMoves(currBoard);
			possibleMovesForI2 = removeCheckMoves(possibleMovesForI, currBoard, color, currBoard.getBlack()[i]->getPieceCoordinates(), currBoard.getBlack()[i]->getPieceName());
			
            pair<int, int> thisPieceCoords = newBoard.getBlack()[i]->getPieceCoordinates();
			
            for(unsigned j = 0; j < possibleMovesForI2.size(); j++){
                newBoard.setBoardConfig(currBoard.getBoardConfig());
                searchMovePiece(newBoard, "black", thisPieceCoords, possibleMovesForI2[j]);
                gameStates.push_back(newBoard);
            }
     	}
        return gameStates;
    }
}

//retrievePiece function to find the piece being moved in validMove
//Pre-cond:	currGame is the current game of the program
//				moveColor is the string (white/black) of the color making a move
//				Name is the name input by the operator for the move (P, N, R, B, Q, K)
//				start is the pair containing the starting coordinates of the move input by the operator
//Post-cond:	returns a pair with the first member holding the Piece* of the retrieved piece
//					the piece that is being moved in validMove
//					The second member holds a bool = true if the a piece had the starting coordinates and false
//					if no piece with color "moveColor" had coordinates equal to start
pair<Piece*, bool> retrievePiece(GameState currGame, string moveColor, string Name, pair<int, int> start){
	if(moveColor=="black"){
		for(unsigned i = 0; i < currGame.getBlack().size(); i++){
			if(currGame.getBlack()[i]->getPieceName() == Name){
				if(currGame.getBlack()[i]->getPieceCoordinates() == start){
					return make_pair(currGame.getBlack()[i], true);
				}
			}
		}
	}
	
	else{
		for(unsigned j = 0; j < currGame.getWhite().size(); j++){
			if(currGame.getWhite()[j]->getPieceName() == Name){
				if(currGame.getWhite()[j]->getPieceCoordinates() == start){
					return make_pair(currGame.getWhite()[j], true);
				}
			}
		}
	}
	
	Pawn* notFound;
	return make_pair(notFound, false);
}


//validMove function to check the validity of a move input
//Pre-cond:	currGame is the current state of the game in the program
//				moveColor is the color (white/black) currently making a move
//				Name is the name of the piece input to be moved (P, N, R, B, Q, K)
//				start is the start coordinates of the move input
//				end is the end coordinates of the move input
//				result is the result of the move input
//Post-cond:	returns a bool = true if the move based on the parameters is valid
//					returns false if the move based on the parameters is an invalid move
bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result){
	pair<Piece*, bool> currPiece = retrievePiece(currGame, moveColor, Name, start);
	
	vector <pair <unsigned, unsigned> > validMoves;
	
	if(currPiece.second){
		validMoves = currPiece.first->generatePossibleMoves(currGame);
		for(unsigned i = 0; i < validMoves.size(); i++){
			if(end == validMoves[i]){
				movePiece(currGame, moveColor, start, end);
				bool check = currGame.kingInCheck(moveColor);
				if(check == false){
					movePiece(currGame, moveColor, end, start);
					return true;
				}
				else{
					movePiece(currGame, moveColor, end, start);
					return false;
				}
			}
		}
	}
	
	return false;
}


//movePiece function that moves the piece at "starting" coordinates to "ending" coordinates
//Pre-cond:	currState is the GameState the move will be made it
//				movingColor is the string (white/black) of the color making the move
//				starting is the pair of coordinates the Piece is at before the move
//				ending is the pair of coordinates the destination of the Piece after the move
//Post-cond:	currState's members have been updated according to the move of the Piece
void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending){
		vector< vector< string > > temp = currState.getBoardConfig();
		temp[ending.first][ending.second]=currState.getBoardConfig()[starting.first][starting.second];
		temp[starting.first][starting.second] = "empty";
		currState.setBoardConfig(temp);
		currState.makeVectors();
}

//movePiece function that moves the piece at "starting" coordinates to "ending" coordinates without updating the vectors
//Pre-cond:	currState is the GameState the move will be made it
//				movingColor is the string (white/black) of the color making the move
//				starting is the pair of coordinates the Piece is at before the move
//				ending is the pair of coordinates the destination of the Piece after the move
//Post-cond:	currState's boardConfig member has been updated according to the move of the Piece
//					the vectors (white and black) have not been updated
void searchMovePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending){
	if(movingColor == "white"){
		vector< vector< string > > temp = currState.getBoardConfig();
		temp[ending.first][ending.second]=currState.getBoardConfig()[starting.first][starting.second];
		temp[starting.first][starting.second] = "empty";
		currState.setBoardConfig(temp);
	}
	
	else{
		vector< vector< string > > temp = currState.getBoardConfig();
		temp[ending.first][ending.second]=currState.getBoardConfig()[starting.first][starting.second];
		temp[starting.first][starting.second] = "empty";
		currState.setBoardConfig(temp);
	}
}


//isBoardEqual function to determined if two boards are equivalent
//Pre-cond:	boardOne has a 2D vector of strings holding the strings
//					of piece names, "empty", or "outOfBounds"
//				boardTwo has a 2D vector of strings holding the strings
//					of piece names, "empty", or "outOfBounds"
//Post-cond:	returns a bool = true if each element of the 2D vector of boardOne
//					is equal to each element of boardTwo
bool isBoardEqual(vector <vector <string> > boardOne, vector <vector <string> > boardTwo){
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 6; j++) {
            if(boardOne[i][j] != boardTwo[i][j]){
                return false;
            }
        }
    }
    return true; 
}


//removeCheckMoves function to remove invalid moves that result in the moving color ending in check
//Pre-cond:	withCheckMoves is a vector of pairs of coordinates made by generatePossibleMoves which can
//					possibly have coordinates that would put the moving color in check
//				currState is the GameState the coordinates/moves are being generated from (the current GameState)
//				color is the string (white/black) of the color currently making a move
//				start is the pair of starting coordinates of the piece used to generate "withCheckMoves"
//				name is the string of the name of the piece used to generate "withCheckMoves" (P, N, B, R, Q, K)
//Post-cond:	returns a vector of pairs of coordinates of moves for piece with "Name" and "start" coordinates
//					None of these pairs will result in "color" being in check if the piece moves to those coordinates
vector <pair <unsigned, unsigned> > removeCheckMoves(vector <pair <unsigned, unsigned> > withCheckMoves, GameState currState, string color, pair <int, int> start, string name){
	GameState temp;
	temp.setBoardConfig(currState.getBoardConfig());
	temp.makeVectors();
	
	vector <pair <unsigned, unsigned> > removed;
	
	
	for(unsigned i = 0; i < withCheckMoves.size(); i++){
		if(validMove(temp, color, name, start, withCheckMoves[i], "notNeeded")){
			removed.push_back(withCheckMoves[i]);
		}
	}
	return removed;
	
}

