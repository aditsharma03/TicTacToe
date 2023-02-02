#include "TicTacToe.h"
#include <iostream>
#include <stdlib.h>
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
	system("clear");
	cout << endl << endl << endl;
	cout << "\t |\t1\t|\t2\t|\t3\t|\t" << endl;
	
	for (int i = 0; i < 3; i++) {
		cout << "\t--------------------------------------------------" << endl;
		cout << endl << "\t" << i+1 << "|\t" << board[i][0] << "\t" << "|\t" << board[i][1] << "\t" << "|\t" << board[i][2] << "\t" << "|" << endl << endl;
	}
	cout << "\t--------------------------------------------------" << endl << endl << endl;
}

void TicTacToe::playGame()
{
	char player1 = 'X', player2 = 'O';

	char current = player1;
	bool flag = false;

	int x,y;

	while( flag == false ){
		printBoard();
		getCoordinates( x, y );
		if( board[x-1][y-1] == 32 ){
			board[x-1][y-1] = current;

			if( checkVictory() ){
				printBoard();
				cout << "\tPlayer " << current << " has won!!!" << endl << endl << endl;
				return;
			}
			if( checkDraw() ){
				printBoard();
				cout << "\tThe match resulted in a draw!!" << endl << endl << endl;
				return;
			}

			if( current == player1 ) current = player2;
			else current = player1;
		}
	}

}

void TicTacToe::getCoordinates(int &x, int &y)
{
	cout << endl << "\tEnter Coordinates: ";
	cin >> x >> y;
}

bool TicTacToe::checkVictory()
{
	//Checking Rows
	if( board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][0] == board[0][2] ) return true;
	if( board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][0] == board[1][2] ) return true;
	if( board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][0] == board[2][2] ) return true;

	//Checking Columns
	if( board[0][0] != ' ' && board[0][0] == board[1][0] && board[0][0] == board[2][0] ) return true;
	if( board[0][1] != ' ' && board[0][1] == board[1][1] && board[0][1] == board[2][1] ) return true;
	if( board[0][2] != ' ' && board[0][2] == board[1][2] && board[0][2] == board[2][2] ) return true;

	//Checking Diagonals
	if( board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2] ) return true;
	if( board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0] ) return true;

	return false;
}

bool TicTacToe::checkDraw()
{
	int count = 0;

	for( int i=0; i<3; i++ ){
		for( int j=0; j<3; j++ ){
			if( board[i][j] != ' ' ) count++;
		}
	}

	if( count == 9 ) return true;
	else return false;
}
