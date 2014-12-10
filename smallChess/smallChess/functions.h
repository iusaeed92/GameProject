//
//H file for functions used in main
//

vector <GameState> makeBoards(GameState currBoard);
void makeHeuristicPairs(vector <GameState> boards, priority_queue <pair <int, GameState> > &worklist);
pair<Piece*, bool> retrievePiece(GameState currGame, string moveColor, string Name, pair<int, int> start);
bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result);
void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);
void searchMovePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);


/*int negaMax(Board b, int depth, int color, priority_queue <pair <int, vector <vector <string> > > worklist){
	if(GameOver(board) or time>timeLimit){
		return sign[color]*getHeuristic(b);
	}
	
	int BestHeuristic = -1000000;
	
	for(int i = 0; i < worklist.size(); i++){
		int x = negaMax(worklist.top(), depth+1, 1-color, worklist.pop());
		if(x>BestHeuristic){
			BestHeuristic = x;
		}
	}
	
	return BestHeuristic;
}*/


vector <GameState> makeBoards(GameState currBoard){
	
	vector <pair <unsigned, unsigned> > possibleMovesForI;
	vector <GameState> gameStates;
	
	GameState newBoard;
	newBoard=currBoard;
//	newBoard.setWhite(currBoard.getWhite());
//	newBoard.setBlack(currBoard.getBlack());
//	newBoard.setBoardConfig(currBoard.getBoardConfig());
	
	for(unsigned i = 0; i < currBoard.getWhite().size(); i++){
		possibleMovesForI = currBoard.getWhite()[i]->generatePossibleMoves(currBoard);
		pair<int, int> thisPieceCoords = newBoard.getWhite()[i]->getPieceCoordinates();
		
		for(unsigned j = 0; j < possibleMovesForI.size(); j++){
//			newBoard.setWhite(currBoard.getWhite());
//			newBoard.setBlack(currBoard.getBlack());
			newBoard.setBoardConfig(currBoard.getBoardConfig());
			searchMovePiece(newBoard, "white", thisPieceCoords, possibleMovesForI[j]);
			gameStates.push_back(newBoard);
		}
		
}
	
 return gameStates;
}


void makeHeuristicPairs(vector <GameState> boards, priority_queue <pair <int, vector< vector <string> > > > &worklist){

	int heuristicForI;

	for(unsigned i = 0; i < boards.size(); i++){
		heuristicForI = boards[i].whiteHeuristicValue() - boards[i].blackHeuristicValue();
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