/*
Sydney Babb
Lab 9, Sec. B
3 - 31 - 22
Tic-Tac-Toe Part 1
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//chooses who goes first the player or computer
int choose;
//game board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
//Game class
class Game {
	//public members of the Game class
	public:
		int start;
		int row;
		int col;
		void showBoard();
		void playerMoves();
		void computerMoves();
		void checkWinner();
		bool tie;
		bool player;
		bool computer;
};

//Make TicTac an instance from the class
Game TicTac;

//display game board function
void Game::showBoard() {
	cout<< "___________________\n";
	cout<<"|__"<<board[0][0]<<"__|__"<<board[0][1]<<"__|__"<<board[0][2]<<"__|\n";
	cout<<"|__"<<board[1][0]<<"__|__"<<board[1][1]<<"__|__"<<board[1][2]<<"__|\n";
	cout<<"|__"<<board[2][0]<<"__|__"<<board[2][1]<<"__|__"<<board[2][2]<<"__|\n"<<endl;
}

//player moves function
void Game::playerMoves() {
	TicTac.row;
	TicTac.col;
	//ask the player for a row and column
	cout<< "\nWhat row would you like to make your move?: "<<endl;
	cin>> TicTac.row;
	cout<< "\nWhat column would you like to make your move?: "<<endl;
	cin>> TicTac.col;
	//if the row and column is occupied to ask again
	if (board[TicTac.row][TicTac.col] == 'O' || board[TicTac.row][TicTac.col] == 'X') {
		cout<< "Sorry this row/column is already occupied. Please try again! \n"<<endl;
		cout<< "\nWhat row would you like to make your move?: "<<endl;
		cin>> TicTac.row;
		cout<< "\nWhat column would you like to make your move?: "<<endl;
		cin>> TicTac.col;
		//gives the selected row/column 'X'
		board[TicTac.row][TicTac.col] = 'X';
	}
	//else the selected row/column is not occupied
	else {
		board[TicTac.row][TicTac.col] = 'X';
	}
	cout<<"Your move!\n";
	//updates the board with the players move
	showBoard();
	//checks for a winner
	TicTac.checkWinner();
	//if player, computer, tie are not true to switch turns
	if (player == 0 && computer == 0 && tie == 0) {
		computerMoves();
	}
}

//computerMoves function
void Game::computerMoves() {
	TicTac.row;
	TicTac.col;
	//while loop
	while (true) {
		srand(time(0));
		//randomly select a row/column
		TicTac.row = rand() % 3;
		TicTac.col = rand() % 3;
		//if the row/column is already occupied
		if (board[TicTac.row][TicTac.col] == 'X' || board[TicTac.row][TicTac.col] == 'O') {
			//continue the loop
			continue;
		}
		//else the row/column is not occupied to place 'O' in the position
		else {
			board[TicTac.row][TicTac.col] = 'O';
			//break the loop
			break;	
		}
	}
	cout<<"Computer's move!\n";
	//prints the computers row/column selection
	cout<<"\nComputer's position: "<<TicTac.row<<","<<TicTac.col<<endl;
	//updates the board with the computer's move
	showBoard();
	//check for a winner
	TicTac.checkWinner();
	//if player, computer, tie are equal to zero to switch turns
	if (player == 0 && computer == 0 && tie == 0) {
		playerMoves();
	}
}

//checkWinner function
void Game::checkWinner() {
	TicTac.row;
	TicTac.col;
	//int totalWins;
	int i;
	int j;
	//for loop to iterate through each row/column
	for (i = 0; i < 3; i++) {
		//check horizontially
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			//if it is all "X' the player wins is true
			if (board[i][0] == 'X') {
				player = true;
			}
			//else the computer wins is true
			else {
				computer = true;
			}
		}
		//check vertically
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			//if it is all 'X' then the player wins is true
			if (board[0][i] == 'X') {
				player = true;
			}
			//else the computer wins is true
			else {
				computer = true;
			}
		}
		//check dialgonally
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			//if it is all 'X' then the player wins is ture
			if (board[0][0] == 'X') {
				player = true;
			}
			//else the computer wins is true
			else {
				computer = true;
			}
		}
		//check dialgonally
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			//if it is all 'X' then the player wins is true
			if (board[0][2] == 'X') {
				player = true;
			}
			//else the computer wins is true
			else {
				computer = true;
			}
			
		}
	}
	//for loops to iterate through each row/column
		for(i = 0; i < 3; i++) 
			for(j = 0; j < 3; j++) 
				//check if the board does not have X and O to return false
				if(board[i][j] != 'X' && board[i][j] != 'O') {
					return;
				} 
				//else statement
				else {
					//if the board does have X and O and the computer is true and tie is false to return the computer wins
					if (computer == true && tie == false) {
						cout<< "Computer Wins!\n"<<endl;
						return;
					}
					//if the board does have X and O and the player is true and tie is false to return You Win
					if (player == true && tie == false) {
						cout<< "You Win!\n"<<endl;
						return;
					}
				}
	//if the game ends and there is no winner to return tie is true
	tie = true;
	cout<< "Tie!\n"<<endl;
	return;
}

//main function
int main() {
	TicTac.row = 3;
	TicTac.col = 3;
	TicTac.start;
	TicTac.player;
	TicTac.computer;
	
	cout<< "Welcome to Tic-Tac-Toe! Rows/Columns are 0-2.\n"<<endl;
	cout<<"\nPress 1 to start or 2 to exit. : ";
	cin>>TicTac.start;
	//if the user decides to exit the program
	if(TicTac.start == 2) {
		return 0;
	}
	//while TicTac.player, TicTac.computer, TicTac.tie are not true to continue looping
	while(TicTac.player != true && TicTac.computer != true && TicTac.tie != true) {
		if(TicTac.start == 1) {
			//displays the board
			TicTac.showBoard();
			srand(time(0));
			//randomly select who goes first
			choose = rand() % 2;
			//if the random selection is 1 the player goes first			
			if (choose == 1) {
				TicTac.playerMoves();
			}
			//else the selection is 2 the computer goes first
			else {
				TicTac.computerMoves();
			}
		}
	}	
	return 0;
}


