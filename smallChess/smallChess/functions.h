//
//H file for functions used in main
//




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


/*vector <vector <vector <string > > > makeBoards(GameState currBoard){

	vector <pair <unsigned, unsigned> > possibleMoveForI;
	vector <vector <vector <string> > > boards;
	GameState firstBoard = currBoard;

	for(int i = 0; i < currBoard.getWhite().size(); i++){
		possibleMovesForI= whitePieces[i]->generatePossibleMoves(currBoard);
		
		for(int j = 0; j < possibleMovesForI.size(); j++){
			vector <vector <string> > newBoard = movePiece(firstBoard, "white", whitePieces[i]->getPieceCoordinates(), possibleMovesForI[j]);
			boards.push_back(newBoard);
		}
 }
	
 return boards;
}*/

/*void makeHeuristicPairs(vector<vector<string> > boards, priority_queue <pair <int, vector<vector <string> > > &worklist){

	int heuristicForI;

	for(int i = 0; i < boards.size(); i++){
		heuristicForI = boards[i].getHeuristic();
		worklist.push(make_pair(heuristicForI, boards[i]));
	}

}*/

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