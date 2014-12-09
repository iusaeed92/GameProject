//
//H file for functions used in main
//

vector <vector <vector <string > > > makeBoards(GameState currBoard);
pair<Piece*, bool> retrievePiece(GameState currGame, string moveColor, string Name, pair<int, int> start);
bool validMove(GameState currGame, string moveColor, string Name, pair<unsigned, unsigned> start, pair<unsigned, unsigned> end, string result);
void movePiece(GameState &currState, string movingColor, pair <int, int> starting, pair<int, int> ending);


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


vector <vector <vector <string > > > makeBoards(GameState currBoard){
	
	vector <pair <unsigned, unsigned> > possibleMovesForI;
	vector <vector <vector <string> > > boards;
	GameState newBoard;
	newBoard.setWhite(currBoard.getWhite());
	newBoard.setBlack(currBoard.getBlack());
	newBoard.setBoardConfig(currBoard.getBoardConfig());

	for(unsigned i = 0; i < currBoard.getWhite().size(); i++){
		possibleMovesForI = currBoard.getWhite()[i]->generatePossibleMoves(currBoard);
		
		for(unsigned j = 0; j < possibleMovesForI.size(); j++){
			newBoard.setWhite(currBoard.getWhite());
			newBoard.setBlack(currBoard.getBlack());
			newBoard.setBoardConfig(currBoard.getBoardConfig());
			cout << "Row: " << possibleMovesForI[j].first << " Column: " << possibleMovesForI[j].second << endl;
			movePiece(newBoard, "white", newBoard.getWhite()[i]->getPieceCoordinates(), possibleMovesForI[j]);
			boards.push_back(newBoard.getBoardConfig());
		}
		
/*		for(unsigned k = 0; k < possibleMovesForI.size(); k++){
			cout << k << endl;
			cout << "Row: " << possibleMovesForI[k].first << " Column: " << possibleMovesForI[k].second << endl;
		
 */}
	
 return boards;
}

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
				cout << "made it" << currState.getWhite()[i]->getPieceName() << endl;
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