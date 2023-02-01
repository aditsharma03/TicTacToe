#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe()
{
	clearBoard();
}

void TicTacToe::clearBoard()
{
	for( int i=0; i<3; i++ ){
		for( int j=0; j<3; j++ ){
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard()
{
	cout << endl;
	cout << " |\t1\t|\t2\t|\t3\t|\t" << endl;
	
	for (int i = 0; i < 3; i++) {
		cout << "--------------------------------------------------" << endl;
		cout << endl << i+1 << "|\t" << board[i][0] << "\t" << "|\t" << board[i][1] << "\t" << "|\t" << board[i][2] << "\t" << "|" << endl << endl;
	}
	cout << "--------------------------------------------------" << endl;
}

void TicTacToe::playGame()
{
	printBoard();
}
