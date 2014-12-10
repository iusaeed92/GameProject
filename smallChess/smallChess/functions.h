//
//H file for functions used in main
//

int negaMax(vector <vector <string> > currBoard, int depth, string color);
vector <GameState> makeBoards(GameState currBoard, string color);
void makeHeuristicPairs(vector <GameState> boards, priority_queue <pair <int, vector <vector <string> > > > &worklist);
pair<Piece*, bool> retrievePiece(GameState currGame, string moveColor, string Name, pair<int, int> start);
bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result);
void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);
void searchMovePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);


int negaMax(vector <vector <string> > currBoard, int depth, string color){
	GameState currState;
	currState.setBoardConfig(currBoard);

	if(depth > 3){
		if(color == "white"){
			return currState.heuristicValue();
		}
		else{
			return - currState.heuristicValue();
		}
	}
	
	int bestHeuristic = -1000000;
	

	priority_queue <pair <int, vector <vector <string> > > > currWorklist;
	vector <GameState> movesForCurrBoard = makeBoards(currState, color);
	makeHeuristicPairs(movesForCurrBoard, currWorklist);
	for(unsigned i = 0; i < currWorklist.size(); i++){
		int x;
		if(color == "white"){
			x = - negaMax(currWorklist.top().second, depth+1, "black");
		}
		else{
			x = - negaMax(currWorklist.top().second, depth+1, "white");
		}
		
		currWorklist.pop();
		
		if(x > bestHeuristic){
			bestHeuristic = x;
		}
	}
	
	return bestHeuristic;
}


vector <GameState> makeBoards(GameState currBoard, string color){
	vector <pair <unsigned, unsigned> > possibleMovesForI;
	vector <GameState> gameStates;
	GameState newBoard;
	newBoard=currBoard;
	//	newBoard.setWhite(currBoard.getWhite());
	//	newBoard.setBlack(currBoard.getBlack());
	//	newBoard.setBoardConfig(currBoard.getBoardConfig());

    if (color == "white"){
   
	for(unsigned i = 0; i < currBoard.getWhite().size(); i++){
		possibleMovesForI = currBoard.getWhite()[i]->generatePossibleMoves(currBoard);
		pair<int, int> thisPieceCoords = newBoard.getWhite()[i]->getPieceCoordinates();
		
		for(unsigned j = 0; j < possibleMovesForI.size(); j++){
			//	newBoard.setWhite(currBoard.getWhite());
			//	newBoard.setBlack(currBoard.getBlack());
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
                //	newBoard.setWhite(currBoard.getWhite());
                //	newBoard.setBlack(currBoard.getBlack());
                newBoard.setBoardConfig(currBoard.getBoardConfig());
                searchMovePiece(newBoard, "black", thisPieceCoords, possibleMovesForI[j]);
                gameStates.push_back(newBoard);
            }
     	}
        return gameStates;
    }
}

void makeHeuristicPairs(vector <GameState> boards, priority_queue <pair <int, vector< vector <string> > > > &worklist){

	int heuristicForI;

	for(unsigned i = 0; i < boards.size(); i++){
		heuristicForI = boards[i].heuristicValue();
		worklist.push(make_pair(heuristicForI, boards[i].getBoardConfig()));
	}
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
	
	if(currPiece.second){
		validMoves = currPiece.first->generatePossibleMoves(currGame);
		for(unsigned i = 0; i < validMoves.size(); i++){
			if(end == validMoves[i]){
				return true;
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