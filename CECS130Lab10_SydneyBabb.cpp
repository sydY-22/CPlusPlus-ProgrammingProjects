#include <iostream>
#include <stdlib.h>
#include <time.h>

/*
Sydney Babb
Lab 10, Sec. B
4 - 15 - 22
Tic-Tac-Toe Part 2
*/

using namespace std;

//Game class
class Game {
	//public members of the Game class
	public:
		char board[3][3];
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

//3D Tic-Tac-Toe Class
//derived class derived from class Game
class Game3D : public Game {
	//public members of Game2
	public:
		//keep track of the total turns 
		int turns;
		//3x3x3 board
		char board[3][3][3];
		//height for 3D board
		int height;
		//keep track of the score
		int countPlayer;
		int countComputer;
		int k;
		//rows, columns, height
		//displays the 3D board
		void showBoard() {
			cout<< "___________________\n";
			cout<<"|__"<<board[0][0][2]<<"__|__"<<board[0][1][2]<<"__|__"<<board[0][2][2]<<"__|\n";
			cout<<"|__"<<board[1][0][2]<<"__|__"<<board[1][1][2]<<"__|__"<<board[1][2][2]<<"__|\n";
			cout<<"|__"<<board[2][0][2]<<"__|__"<<board[2][1][2]<<"__|__"<<board[2][2][2]<<"__|\n";
			
			cout<< "___________________\n";
			cout<<"|__"<<board[0][0][1]<<"__|__"<<board[0][1][1]<<"__|__"<<board[0][2][1]<<"__|\n";
			cout<<"|__"<<board[1][0][1]<<"__|__"<<board[1][1][1]<<"__|__"<<board[1][2][1]<<"__|\n";
			cout<<"|__"<<board[2][0][1]<<"__|__"<<board[2][1][1]<<"__|__"<<board[2][2][1]<<"__|\n";
			
			cout<< "___________________\n";
			cout<<"|__"<<board[0][0][0]<<"__|__"<<board[0][1][0]<<"__|__"<<board[0][2][0]<<"__|\n";
			cout<<"|__"<<board[1][0][0]<<"__|__"<<board[1][1][0]<<"__|__"<<board[1][2][0]<<"__|\n";
			cout<<"|__"<<board[2][0][0]<<"__|__"<<board[2][1][0]<<"__|__"<<board[2][2][0]<<"__|\n";
		}
		
		void playerMoves() {
		//ask the player which row/column/height to make a move
			cout<< "\nWhat row would you like to make your move?: "<<endl;
			cin>> row;
			cout<< "\nWhat column would you like to make your move?: "<<endl;
			cin>> col;
			cout<<"\nWhat height would you like to make your move?: "<<endl;
			cin>> height;
			//if the cell is already occupied to ask the user again for row/column/height
			if (board[row][col][height] == 'O' || board[row][col][height] == 'X') {
				cout<<"Row/Column/Height is already occupied. Please try again."<<endl;
				cout<< "\nWhat row would you like to make your move?: "<<endl;
				cin>> row;
				cout<< "\nWhat column would you like to make your move?: "<<endl;
				cin>> col;
				cout<<"\nWhat height would you like to make your move?: "<<endl;
				cin>> height;
				cout<<"\nYour Move!"<<endl;
				board[row][col][height] = 'X';
			}
			//else the player selected an unoccupied row to place an 'X' in the position
			else {
				cout<<"\nYour Move!"<<endl;
				board[row][col][height] = 'X';
			}
			//display the board
			showBoard();
			//add 1 to the turns
			turns++;
			cout<<"\nTotal Turns: "<<turns<<endl;
			//if turns = 27 
			if (turns == 27) {
				//display the score
				checkScore();
				//if the Computer has the highest score to print the Computer Wins
				if(countComputer > countPlayer) {
					cout<< "Computer Wins!\n"<<endl;
				}
				//if the Player has the highest score to print the Player Wins					
				if (countPlayer > countComputer) {
					cout<< "You Win!\n"<<endl;			
				}
				//if Player equals Computer to print Tie	
				if (countPlayer == countComputer) {
					cout<< "Tie!\n"<<endl;
				}
			}
			//else the total turns is not equal to 27 to switch turns	
			else {
				computerMoves();
			}
		}
		
		void computerMoves() {
				while(true) {
					//randomly select values for the computer
					srand(time(NULL));
					row = rand() % 3;
					col = rand() % 3;
					height = rand() % 3;
					//if space occupied to keep randomizing
					if(board[row][col][height] == 'X' || board[row][col][height] == 'O') {
						continue;
					}
					//put 'O' for the Computer's position
					else {
						board[row][col][height] = 'O';
						break;
					}
				}
			cout<<"Computer's Move!\n";
			cout<<"\nComputer's position: "<<row<<","<<col<<","<<height<<endl;
			showBoard();
			//adds 1 to the turns
			turns++;
			cout<<"\nTotal Turns: "<<turns<<endl;
			//if total turns equals 27 to check the score 
			if (turns == 27) {
				//display the score
				checkScore();
				//if computer has the highest score to print Computer Wins
				if(countComputer > countPlayer) {
					cout<< "Computer Wins!\n"<<endl;
					
				}
				//if the player has the highest score to print the You Win					
				if (countPlayer > countComputer) {
					cout<< "You Win!\n"<<endl;
					
				}
				//if the Player and Computers total score is equal to print Tie	
				if (countPlayer == countComputer) {
					tie = true;
					cout<< "Tie!\n"<<endl;
					
				}
			}
			//if the total turns is not equal to 27 to switch turns
			else {
				playerMoves();
			}
		}
		
		//count the total wins.
		void checkScore() {
			int i;
			int j;
			int k;
			//for loop to iterate through each row/column/height
			for (i = 0; i < 3; i++) { //0 to 2
				for (k = 2; k >= 0; k--) { //2 to 0
					//check horizontially
					if (board[i][0][k] == board[i][1][k] && board[i][1][k] == board[i][2][k]) {
						if (board[i][0][k] == 'X') {
							//adds 1 to score if the player got all X's in a row
							countPlayer ++;
						}
						else if (board[i][0][k] == 'O') {
							//else if equal 'O' adds 1 to the computer's score
							countComputer ++;
						}
					}
					//check vertically
					//include more winning possibilities
					//(0,0,2),(1,0,1),(2,0,0)/(0,1,2),(1,1,1),(2,1,0)/(0,2,2),(1,2,1),(2,2,0)
					//(0,0,2),(0,0,1),(0,0,0)/
					if (board[0][i][k] == board[1][i][k] && board[1][i][k] == board[2][i][k]) {
						if (board[0][i][k] == 'X') {
							countPlayer ++;
						}
						else if (board[0][i][k] == 'O') {
							countComputer ++;
						}
					}
					if (board[0][0][2] == board[1][0][1] && board[1][0][1] == board[2][0][0]) {
						if (board[0][0][2] == 'X') {
							countPlayer ++;
						}
						else if (board[0][0][2] == 'O') {
							countComputer ++;
						}
					}
					if (board[0][1][2] == board[1][1][1] && board[1][1][1] == board[2][1][0]) {
						if (board[0][1][2] == 'X') {
							countPlayer ++;
						}
						else if (board[0][1][2] == 'O') {
							countComputer ++;
						}
					}
					if (board[0][2][2] == board[1][2][1] && board[1][2][1] == board[2][2][0]) {
						if (board[0][2][2] == 'X') {
							countPlayer ++;
						}
						else if (board[0][2][2] == 'O') {
							countComputer ++;
						}
					}
					
					//check dialgonally 
					//(0,0,2),(1,1,1),(2,2,0)/(0,2,2),(1,1,1),(2,0,0)
					if (board[0][0][k] == board[1][1][k] && board[1][1][k] == board[2][2][k]) {
						if (board[0][0][k] == 'X') {
							countPlayer ++;
						}
						else if (board[0][0][k] == 'O') {
							countComputer ++;
							
						}
					}
					if (board[0][0][2] == board[1][1][1] && board[1][1][1] == board[2][2][0]) {
						if (board[0][0][2] == 'X') {
							countPlayer ++;
							
						}
						else if(board[0][0][2] == 'O') {
							countComputer ++;
						
						}
					}
					if (board[0][2][2] == board[1][1][1] && board[1][1][1] == board[2][0][0])
						if (board[0][2][2] == 'X') {
							countPlayer ++;
						}
						else if (board[0][2][2] == 'O') {
							countComputer ++;
						}
					//check dialgonally
					//(0,0,2),(1,1,1),(2,2,0)/(0,2,2),(1,1,1),(2,0,0)
					if (board[0][2][k] == board[1][1][k] && board[1][1][k] == board[2][0][k]) {
						if (board[0][2][k] == 'X') {
							countPlayer ++;
						}
						else if (board[0][2][k] == 'O') {
							countComputer ++;
							
						}
					}
				}
			}
			//displays the score of the Computer and Player	
			cout << "countComputer="<<countComputer<<" countPlayer="<<countPlayer<<endl;		
		}	
};




//Make TicTac an instance from the class
Game TicTac;
Game3D TicTac2;

//function definitions for the class Game
//display game board function
void Game::showBoard() {
	//row, column
	cout<< "___________________\n";
	cout<<"|__"<<board[0][0]<<"__|__"<<board[0][1]<<"__|__"<<board[0][2]<<"__|\n";
	cout<<"|__"<<board[1][0]<<"__|__"<<board[1][1]<<"__|__"<<board[1][2]<<"__|\n";
	cout<<"|__"<<board[2][0]<<"__|__"<<board[2][1]<<"__|__"<<board[2][2]<<"__|\n";
	
}




//player moves function
void Game::playerMoves() {
	TicTac.row;
	TicTac.col;
	TicTac.showBoard();
	//ask the player for a row and column
	cout<< "\nWhat row would you like to make your move?: "<<endl;
	cin>> TicTac.row;
	cout<< "\nWhat column would you like to make your move?: "<<endl;
	cin>> TicTac.col;
	//if the row/column/height is occupied to ask again
	if (board[TicTac.row][TicTac.col] == 'O' || board[TicTac.row][TicTac.col] == 'X') {
		cout<< "Sorry this row/column is already occupied. Please try again! \n"<<endl;
		cout<< "\nWhat row would you like to make your move?: "<<endl;
		cin>> TicTac.row;
		cout<< "\nWhat column would you like to make your move?: "<<endl;
		cin>> TicTac.col;
		//gives the selected row/column 'X'
		board[TicTac.row][TicTac.col] = 'X';
	}
	//else the selected row/column/height is not occupied
	else {
		board[TicTac.row][TicTac.col] = 'X';
	}
	cout<<"Your move!\n";
	//updates the board with the players move
	TicTac.showBoard();
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
	TicTac.showBoard();
	//while loop
	
	while (true) {
		srand(time(0));
		//randomly select a row/column
		TicTac.row = rand() % 3;
		TicTac.col = rand() % 3;
		//if the row/column/height is already occupied
		if (board[TicTac.row][TicTac.col] == 'X' || board[TicTac.row][TicTac.col] == 'O') {
			//continue the loop
			continue;
		}
		//else the row/column/height is not occupied to place 'O' in the position
		else {
			board[TicTac.row][TicTac.col] = 'O';
			//break the loop
			break;	
		}
	}
	
	cout<<"Computer's move!\n";
	//prints the computers row/column/height selection
	cout<<"\nComputer's position: "<<TicTac.row<<","<<TicTac.col<<endl;
	//updates the board with the computer's move
	TicTac.showBoard();
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

int main() {
	int choose;
	/*
	TicTac.row = 3;
	TicTac.col = 3;
	TicTac.start;
	TicTac.player;
	TicTac.computer;
	*/
	TicTac2.countComputer;
	TicTac2.countPlayer; 
	cout<< "Welcome to Tic-Tac-Toe! Rows/Columns/Height are 0-2.\n"<<endl;
	cout<<"\nHeight 2 to 0 from top to bottom"<<endl;
	cout<<"\nPress 1 to start or 2 to exit. : ";
	cin>>TicTac2.start;
	//if the user decides to exit the program
	if(TicTac2.start == 2) {
		return 0;
	}
	if (TicTac2.start == 1) {
		cout<<"\nComputer = 'O' and Player = 'X'"<<endl;
		while(TicTac2.turns != 27) {
	//while(TicTac.player != true && TicTac.computer != true && TicTac.tie != true) {
			//displays the board
			TicTac2.showBoard();
			srand(time(0));
			//randomly select who goes first
			choose = rand() % 2;
			//if the random selection is 1 the player goes first			
			if (choose == 1) {
				TicTac2.playerMoves();
			}
		//else the selection is 2 the computer goes first
			else {
				TicTac2.computerMoves();
			}
		}
		
	}

	return 0;
	}

