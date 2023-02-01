#pragma once

class TicTacToe
{
	public:
		TicTacToe();
		void playGame();
	private:
		char board[3][3];
		void clearBoard();
		void printBoard();
		void getCoordinates( int&, int& );
		bool checkVictory();
		bool checkDraw();
};
