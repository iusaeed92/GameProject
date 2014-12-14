//
//H file for functions used in main
//

int negaMax(vector <vector <string> > currBoard, int depth, string color, int &bestBoardNum);
vector <GameState> makeBoards(GameState currBoard, string color);
priority_queue <pair <int, vector <vector <string> > > > makeHeuristicPairs(vector <GameState> boards);
pair<Piece*, bool> retrievePiece(GameState currGame, string moveColor, string Name, pair<int, int> start);
bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result);
void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);
void searchMovePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);
bool isBoardEqual(vector <vector <string> > boardOne, vector <vector <string> > boardTwo);


/* 
vector < vector <string >> (gameState &currentGameState, double moveTime) {
 
 
 <pair <unsigned, unsigned> bestMoveSoFar;
 vector < vector <vector <string> >  >expandedBoards;
 priority_queue <pair <int, vector<vector <string> > > > &worklist
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


int negaMax(vector <vector <string> > currBoard, int depth, string color, int &bestBoardNum){
	GameState currState;
	currState.setBoardConfig(currBoard);
	currState.makeVectors();

	if(depth > 2){
		if(color == "white"){
			return - currState.heuristicValue();
		}
		else{
			return currState.heuristicValue();
		}
	}
	
	int bestHeuristic = -1000000;
	priority_queue <pair <int, vector <vector <string> > > > currWorklist;
	vector <GameState> movesForCurrBoard = makeBoards(currState, color);
//	currWorklist = makeHeuristicPairs(movesForCurrBoard);
//	unsigned listSize = currWorklist.size();
	for(unsigned i = 0; i < movesForCurrBoard.size(); i++){
		int x;
		if(color == "white"){
			x = negaMax(movesForCurrBoard[i].getBoardConfig(), depth+1, "black", bestBoardNum);
		}
		else{
			x = negaMax(movesForCurrBoard[i].getBoardConfig(), depth+1, "white", bestBoardNum);
		}
		
//		if(!currWorklist.empty()){
//			currWorklist.pop();
//		}
		
		if(x > bestHeuristic){
			bestHeuristic = x;
			bestBoardNum = i;
//			best = currWorklist.top();
		}
	}
	
	return - bestHeuristic;
}


vector <GameState> makeBoards(GameState currBoard, string color){
	vector <pair <unsigned, unsigned> > possibleMovesForI;
	vector <GameState> gameStates;
	GameState newBoard;
	newBoard=currBoard;

    if (color == "white"){

		for(unsigned i = 0; i < currBoard.getWhite().size(); i++){
			possibleMovesForI = currBoard.getWhite()[i]->generatePossibleMoves(currBoard);
			pair<int, int> thisPieceCoords = newBoard.getWhite()[i]->getPieceCoordinates();
			
			for(unsigned j = 0; j < possibleMovesForI.size(); j++){
				newBoard.setBoardConfig(currBoard.getBoardConfig());
				searchMovePiece(newBoard, "white", thisPieceCoords, possibleMovesForI[j]);
				gameStates.push_back(newBoard);
			}
		}
		
		return gameStates;
	}
	
    else {
        for(unsigned i = 0; i < currBoard.getBlack().size(); i++){
            possibleMovesForI = currBoard.getBlack()[i]->generatePossibleMoves(currBoard);
            pair<int, int> thisPieceCoords = newBoard.getBlack()[i]->getPieceCoordinates();
			
            for(unsigned j = 0; j < possibleMovesForI.size(); j++){
                newBoard.setBoardConfig(currBoard.getBoardConfig());
                searchMovePiece(newBoard, "black", thisPieceCoords, possibleMovesForI[j]);
                gameStates.push_back(newBoard);
            }
     	}
        return gameStates;
    }
}


priority_queue <pair <int, vector <vector <string> > > > makeHeuristicPairs(vector <GameState> boards){

	int heuristicForI;
	priority_queue <pair <int, vector <vector <string> > > > worklist;

	for(unsigned i = 0; i < boards.size(); i++){
		heuristicForI = boards[i].heuristicValue();
		worklist.push(make_pair(heuristicForI, boards[i].getBoardConfig()));
	}
	
	return worklist;
}


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

bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result){
	pair<Piece*, bool> currPiece = retrievePiece(currGame, moveColor, Name, start);
	
	vector <pair <unsigned, unsigned> > validMoves;
	
//	cout << currPiece.first->getPieceCoordinates().first << ", " << currPiece.first->getPieceCoordinates().first << endl;
	
	if(currPiece.second){
		validMoves = currPiece.first->generatePossibleMoves(currGame);
//		cout << "size of valid moves: " << validMoves.size() << endl;
//		for(int j = 0; j < validMoves.size(); j++){
//			cout << validMoves[j].first << ", " << validMoves[j].second << endl;
//		}
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

void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending){
	if(movingColor == "white"){
		for(unsigned i = 0; i < currState.getWhite().size(); i++){
			if(currState.getWhite()[i]->getPieceCoordinates().first == starting.first &&
			currState.getWhite()[i]->getPieceCoordinates().second == starting.second){
				currState.getWhite()[i]->setPieceCoordinates(ending.first, ending.second);
			}
		}
		
		vector< vector< string > > temp = currState.getBoardConfig();
		temp[ending.first][ending.second]=currState.getBoardConfig()[starting.first][starting.second];
		temp[starting.first][starting.second] = "empty";
		currState.setBoardConfig(temp);
	}
	
	else{
		for(unsigned i = 0; i < currState.getBlack().size(); i++){
			if(currState.getBlack()[i]->getPieceCoordinates().first == starting.first &&
			currState.getBlack()[i]->getPieceCoordinates().second == starting.second){
				currState.getBlack()[i]->setPieceCoordinates(ending.first, ending.second);
			}
		}
		
		vector< vector< string > > temp = currState.getBoardConfig();
		temp[ending.first][ending.second]=currState.getBoardConfig()[starting.first][starting.second];
		temp[starting.first][starting.second] = "empty";
		currState.setBoardConfig(temp);
	}
	
}


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



