#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include "game.h"
using namespace std;

//this is the main matrix
char matrix[3][3][3] = {'a', 'd', 'g', 'j', 'm', 'p', 's', 'v', 'y', 'b', 'e', 'h', 'k', 'n', 'q', 't', 'w', 'z', 'c', 'f', 'i', 'l', 'o', 'r', 'u', 'x', '!'};
int yscore = 0;
int nscore = 0;
int coinValue = 0;
int count = 0;
bool complete = false;
//this is the constructor and calls the menu, the beginning of the game
game::game(){
	menu();
}
//This is the turn system. "coinValue" determines turn order
void game::gather(){
	while(1){
		if(coinValue == 0){
			coinFlip();	
		}
		if(coinValue == 1){
			map(matrix);
			end();
			playeryou(matrix);
			isDone(matrix);
			playernot(matrix);
		}
		if(coinValue == 2){
			map(matrix);
			end();
			playernot(matrix);
			isDone(matrix);
			playeryou(matrix);
		}
		end();
	}
}
//checks if the game board is complete. Returns true if the board is empty of usable spaces.
void game::isDone(char matrix[3][3][3]){
	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){			
				if(matrix[x][y][z] != '@' && matrix[x][y][z] != '&'){
					count++;
				}
			}
		}		
	}
	if(count == 0){
		complete = true;
	}
}

//allows an interface to let the player quit
void game::exits(){
	cout << "Do you want to exit? " << endl << endl << endl;
	cout << " 1 - Yes " << " 2 - No " << endl;
	cin >> choices;
	if (choices == 1){
		exit(1);
	}else{
		menu();
	}
}
//prints a nice little how to
void game::tutorial(){
	cout << " This is 3D Tic-Tac-Toe for those looking for more of a challenge. " << endl;
	cout << " The board is presented as 3 3x3 arrays layered above each other. " << endl;
	cout << " These boards are lettered from a to z with one extra character." << endl;
	cout << " Enter a letter on your turn to enter a marker ('@' for your enemy and '&' for you)." << endl;
	cout << " Be sure to not cheat! The computer won't play with you anymore." << endl;
	cout << " Press 0 to exit to menu." << endl;
	cin >> press;
	if (press == 0){
		menu();
	}else{
		exit(1);
	}
}
//the beginning menu of the game
void game::menu(){
	cout << endl << endl;
	cout << " Tic-Tac-Toe " << endl << endl;
	cout << " (a) - Play Game " << endl << endl;
	cout << " (b) - Tutorial " << endl << endl;
	cout << " (c) - Exit " << endl << endl;
	cin >> choice2;
	switch (choice2){
		case 'a':
			gather();
			break;
		case 'b':
			tutorial();
			break;
		case 'c':
			exits();
			break;
	}
}
//the player's input
void game::playeryou(char matrix[3][3][3]){
	cout << " please enter the spot you want to mark " << endl;
	cin >> choice;
	//switch instead of drab else-if chains. Within each case is a check for if respective pieces are in array slots already. The user is notified with a bit more of sassiness : ^)
	switch (choice){
		case 'a':
			if(matrix[0][0][0] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[0][0][0] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[0][0][0] = '&';
			break;
		case 'b':
			if(matrix[1][0][0] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[1][0][0] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[1][0][0] = '&';
			break;
		case 'c':
			if(matrix[2][0][0] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[2][0][0] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[2][0][0] = '&';
			break;
		case 'd':
			if(matrix[0][0][1] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[0][0][1] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[0][0][1] = '&';
			break;
		case 'e':
			if(matrix[1][0][1] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[1][0][1] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[1][0][1] = '&';
			break;
		case 'f':
			if(matrix[2][0][1] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[2][0][1] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[2][0][1] = '&';
			break;
		case 'g':
			if(matrix[0][0][2] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[0][0][2] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[0][0][2] = '&';
			break;
		case 'h':
			if(matrix[1][0][2] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[1][0][2] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[1][0][2] = '&';
			break;
		case 'i':
			if(matrix[2][0][2] == '@'){
				cout << " To rob victory from a poor CPU! You know better than that! " << endl << endl;
				exit(1);
			}else if(matrix[2][0][2] == '&'){
				cout << " Don't worry! I've been keeping track of your spots for you! You've already played that spot. " << endl << endl;
				playeryou(matrix);
			}
			matrix[2][0][2] = '&';
			break;
		case 'j':
			if(matrix[0][1][0] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[0][1][0] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[0][1][0] = '&';
			break;
		case 'k':
			if(matrix[1][1][0] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[1][1][0] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[1][1][0] = '&';
			break;
		case 'l':
			if(matrix[2][1][0] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[2][1][0] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[2][1][0] = '&';
			break;
		case 'm':
			if(matrix[0][1][1] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[0][1][1] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[0][1][1] = '&';
			break;
		case 'n':
			if(matrix[1][1][1] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[1][1][1] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[1][1][1] = '&';
			break;
		case 'o':
			if(matrix[2][1][1] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[2][1][1] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[2][1][1] = '&';
			break;
		case 'p':
			if(matrix[0][1][2] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[0][1][2] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[0][1][2] = '&';
			break;
		case 'q':
			if(matrix[1][1][2] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[1][1][2] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[1][1][2] = '&';
			break;
		case 'r':
			if(matrix[2][1][2] == '@'){
				cout << " If I didn't know better, I'd think you were cheating. " << endl << endl;
				exit(1);
			}else if(matrix[2][1][2] == '&'){
				cout << " Wut? Why place a marker on a spot you've already placed? You lose a turn!" << endl << endl;
				playeryou(matrix);
			}
			matrix[2][1][2] = '&';
			break;
		case 's':
			if(matrix[0][2][0] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[0][2][0] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[0][2][0] = '&';
			break;
		case 't':
			if(matrix[1][2][0] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[1][2][0] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[1][2][0] = '&';
			break;
		case 'u':
			if(matrix[2][2][0] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[2][2][0] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[2][2][0] = '&';
			break;
		case 'v':
			if(matrix[0][2][1] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[0][2][1] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[0][2][1] = '&';
			break;
		case 'w':
			if(matrix[1][2][1] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[1][2][1] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[1][2][1] = '&';
			break;
		case 'x':
			if(matrix[2][2][1] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[2][2][1] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[2][2][1] = '&';
			break;
		case 'y':
			if(matrix[0][2][2] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[0][2][2] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[0][2][2] = '&';
			break;
		case 'z':
			if(matrix[1][2][2] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[1][2][2] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[1][2][2] = '&';
			break;
		case '!':
			if(matrix[2][2][2] == '@'){
				cout << " Just think of all the 'trouble' the programmer went through to make this game before cheating like that! " << endl << endl;
				exit(1);
			}else if(matrix[2][2][2] == '&'){
				cout << " I get that this is 3D Tic-Tac-Toe and it may be hard to keep track of, but it's ONLY 27 spaces. " << endl << endl;
				playeryou(matrix);
			}
			matrix[2][2][2] = '&';
			break;
	}
	
}
	

//this draws the gameboard
void game::map(char matrix[3][3][3]){
	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){			
				cout << matrix[z][x][y] << "	";
			}
		cout << endl << endl;
		}
		cout << endl << endl;		
	}
}
//this is player x. It will loop to check if a space is open, then play it to ensure it actually plays once per turn.
void game::playernot(char matrix[3][3][3]){
	srand (time(NULL));
	int xReady = 0;
	if(complete == false){
		while (xReady != 1){
			int randx = rand() % 3;
			int randy = rand() % 3;
			int randz = rand() % 3;
			if (matrix[randx][randy][randz] != '&' && matrix[randx][randy][randz] != '@'){
				matrix[randx][randy][randz] = '@';
				xReady = 1;
			}
		}
	}else{
		end();
	}
}

//Decides order of players
void game::coinFlip(){
	coinValue = rand() % 2;
}

//the end of the game and checks for all combos and counts up points
void game::end(){
	//checks for wins for you
	//You - layer 0 - horizontal checks
	if(matrix[0][0][0] == '&' && matrix[0][1][0] == '&' && matrix[0][2][0] == '&'){
		yscore++;
	}
	if(matrix[1][0][0] == '&' && matrix[1][1][0] == '&' && matrix[1][2][0] == '&'){
		yscore++;
	}
	if(matrix[2][0][0] == '&' && matrix[2][1][0] == '&' && matrix[2][2][0] == '&'){
		yscore++;
	}
	//You - layer 0 - vertical checks
	if(matrix[0][0][0] == '&' && matrix[1][0][0] == '&' && matrix[2][0][0] == '&'){
		yscore++;
	}
	if(matrix[0][1][0] == '&' && matrix[1][1][0] == '&' && matrix[2][1][0] == '&'){
		yscore++;
	}
	if(matrix[0][2][0] == '&' && matrix[1][2][0] == '&' && matrix[2][2][0] == '&'){
		yscore++;
	}
	//You - layer 0 - diagonal checks
	if(matrix[0][0][0] == '&' && matrix[1][1][0] == '&' && matrix[2][2][0] == '&'){
		yscore++;
	}
	if(matrix[2][0][0] == '&' && matrix[1][1][0] == '&' && matrix[0][2][0] == '&'){
		yscore++;
	}
	
	//You - layer 1 - horizontal checks
	if(matrix[0][0][1] == '&' && matrix[0][1][1] == '&' && matrix[0][2][1] == '&'){
		yscore++;
	}
	if(matrix[1][0][1] == '&' && matrix[1][1][1] == '&' && matrix[1][2][1] == '&'){
		yscore++;
	}
	if(matrix[2][0][1] == '&' && matrix[2][1][1] == '&' && matrix[2][2][1] == '&'){
		yscore++;
	}
	//You - layer 1 - vertical checks
	if(matrix[0][0][1] == '&' && matrix[1][0][1] == '&' && matrix[2][0][1] == '&'){
		yscore++;
	}
	if(matrix[0][1][1] == '&' && matrix[1][1][1] == '&' && matrix[2][1][1] == '&'){
		yscore++;
	}
	if(matrix[0][2][1] == '&' && matrix[1][2][1] == '&' && matrix[2][2][1] == '&'){
		yscore++;
	}
	//You - layer 1 - diagonal checks
	if(matrix[0][0][1] == '&' && matrix[1][1][1] == '&' && matrix[2][2][1] == '&'){
		yscore++;
	}
	if(matrix[2][0][1] == '&' && matrix[1][1][1] == '&' && matrix[0][2][1] == '&'){
		yscore++;
	}
	
	//You - layer 2 - horizontal checks
	if(matrix[0][0][2] == '&' && matrix[0][1][2] == '&' && matrix[0][2][2] == '&'){
		yscore++;
	}
	if(matrix[1][0][2] == '&' && matrix[1][1][2] == '&' && matrix[1][2][2] == '&'){
		yscore++;
	}
	if(matrix[2][0][2] == '&' && matrix[2][1][2] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	//You - layer 2 - vertical checks
	if(matrix[0][0][2] == '&' && matrix[1][0][2] == '&' && matrix[2][0][2] == '&'){
		yscore++;
	}
	if(matrix[0][1][2] == '&' && matrix[1][1][2] == '&' && matrix[2][1][2] == '&'){
		yscore++;
	}
	if(matrix[0][2][2] == '&' && matrix[1][2][2] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	//You - layer 2 - diagonal checks
	if(matrix[0][0][2] == '&' && matrix[1][1][2] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	if(matrix[2][0][2] == '&' && matrix[1][1][2] == '&' && matrix[0][2][2] == '&'){
		yscore++;
	}
	
	//You - face 0 - all checks from top of cube to bottom
	if(matrix[0][0][0] == '&' && matrix[0][0][1] == '&' && matrix[0][0][2] == '&'){
		yscore++;
	}
	if(matrix[0][1][0] == '&' && matrix[0][1][1] == '&' && matrix[0][1][2] == '&'){
		yscore++;
	}
	if(matrix[0][2][0] == '&' && matrix[0][2][1] == '&' && matrix[0][2][2] == '&'){
		yscore++;
	}
	
	if(matrix[1][0][0] == '&' && matrix[1][0][1] == '&' && matrix[1][0][2] == '&'){
		yscore++;
	}
	if(matrix[1][1][0] == '&' && matrix[1][1][1] == '&' && matrix[1][1][2] == '&'){
		yscore++;
	}
	if(matrix[1][2][0] == '&' && matrix[1][2][1] == '&' && matrix[1][2][2] == '&'){
		yscore++;
	}
	
	if(matrix[2][0][0] == '&' && matrix[2][0][1] == '&' && matrix[2][0][2] == '&'){
		yscore++;
	}
	if(matrix[2][1][0] == '&' && matrix[2][1][1] == '&' && matrix[2][1][2] == '&'){
		yscore++;
	}
	if(matrix[2][2][0] == '&' && matrix[2][2][1] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	
	//You - Vertical-diagonal checks
	if(matrix[0][0][0] == '&' && matrix[1][0][1] == '&' && matrix[2][0][2] == '&'){
		yscore++;
	}
	if(matrix[0][1][0] == '&' && matrix[1][1][1] == '&' && matrix[2][1][2] == '&'){
		yscore++;
	}
	if(matrix[0][2][0] == '&' && matrix[1][2][1] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	
	if(matrix[2][0][0] == '&' && matrix[1][0][1] == '&' && matrix[0][0][2] == '&'){
		yscore++;
	}
	if(matrix[2][1][0] == '&' && matrix[1][1][1] == '&' && matrix[0][1][2] == '&'){
		yscore++;
	}
	if(matrix[2][2][0] == '&' && matrix[1][2][1] == '&' && matrix[0][2][2] == '&'){
		yscore++;
	}
	
	//You - Horizontal-diagonal checks
	if(matrix[0][0][0] == '&' && matrix[0][1][1] == '&' && matrix[0][2][2] == '&'){
		yscore++;
	}
	if(matrix[1][0][0] == '&' && matrix[1][1][1] == '&' && matrix[1][2][2] == '&'){
		yscore++;
	}
	if(matrix[2][0][0] == '&' && matrix[2][1][1] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	
	if(matrix[0][2][0] == '&' && matrix[0][1][1] == '&' && matrix[0][0][2] == '&'){
		yscore++;
	}
	if(matrix[1][2][0] == '&' && matrix[1][1][1] == '&' && matrix[1][0][2] == '&'){
		yscore++;
	}
	if(matrix[2][2][0] == '&' && matrix[2][1][1] == '&' && matrix[2][0][2] == '&'){
		yscore++;
	}
	
	//You - Diagonal-diagonal checks
	if(matrix[0][0][0] == '&' && matrix[1][1][1] == '&' && matrix[2][2][2] == '&'){
		yscore++;
	}
	if(matrix[0][2][0] == '&' && matrix[1][1][1] == '&' && matrix[2][0][2] == '&'){
		yscore++;
	}
	if(matrix[2][2][0] == '&' && matrix[1][1][1] == '&' && matrix[0][0][2] == '&'){
		yscore++;
	}
	if(matrix[2][0][0] == '&' && matrix[1][1][1] == '&' && matrix[0][2][2] == '&'){
		yscore++;
	}
	
	
	
	//checks for wins for other player
	//other - layer 0 - horizontal checks
	if(matrix[0][0][0] == '@' && matrix[0][1][0] == '@' && matrix[0][2][0] == '@'){
		nscore++;
	}
	if(matrix[1][0][0] == '@' && matrix[1][1][0] == '@' && matrix[1][2][0] == '@'){
		nscore++;
	}
	if(matrix[2][0][0] == '@' && matrix[2][1][0] == '@' && matrix[2][2][0] == '@'){
		nscore++;
	}
	//other - layer 0 - vertical checks
	if(matrix[0][0][0] == '@' && matrix[1][0][0] == '@' && matrix[2][0][0] == '@'){
		nscore++;
	}
	if(matrix[0][1][0] == '@' && matrix[1][1][0] == '@' && matrix[2][1][0] == '@'){
		nscore++;
	}
	if(matrix[0][2][0] == '@' && matrix[1][2][0] == '@' && matrix[2][2][0] == '@'){
		nscore++;
	}
	//other - layer 0 - diagonal checks
	if(matrix[0][0][0] == '@' && matrix[1][1][0] == '@' && matrix[2][2][0] == '@'){
		nscore++;
	}
	if(matrix[2][0][0] == '@' && matrix[1][1][0] == '@' && matrix[0][2][0] == '@'){
		nscore++;
	}
	
	//other - layer 1 - horizontal checks
	if(matrix[0][0][1] == '@' && matrix[0][1][1] == '@' && matrix[0][2][1] == '@'){
		nscore++;
	}
	if(matrix[1][0][1] == '@' && matrix[1][1][1] == '@' && matrix[1][2][1] == '@'){
		nscore++;
	}
	if(matrix[2][0][1] == '@' && matrix[2][1][1] == '@' && matrix[2][2][1] == '@'){
		nscore++;
	}
	//other - layer 1 - vertical checks
	if(matrix[0][0][1] == '@' && matrix[1][0][1] == '@' && matrix[2][0][1] == '@'){
		nscore++;
	}
	if(matrix[0][1][1] == '@' && matrix[1][1][1] == '@' && matrix[2][1][1] == '@'){
		nscore++;
	}
	if(matrix[0][2][1] == '@' && matrix[1][2][1] == '@' && matrix[2][2][1] == '@'){
		nscore++;
	}
	//other - layer 1 - diagonal checks
	if(matrix[0][0][1] == '@' && matrix[1][1][1] == '@' && matrix[2][2][1] == '@'){
		nscore++;
	}
	if(matrix[2][0][1] == '@' && matrix[1][1][1] == '@' && matrix[0][2][1] == '@'){
		nscore++;
	}
	
	//other - layer 2 - horizontal checks
	if(matrix[0][0][2] == '@' && matrix[0][1][2] == '@' && matrix[0][2][2] == '@'){
		nscore++;
	}
	if(matrix[1][0][2] == '@' && matrix[1][1][2] == '@' && matrix[1][2][2] == '@'){
		nscore++;
	}
	if(matrix[2][0][2] == '@' && matrix[2][1][2] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	//other - layer 2 - vertical checks
	if(matrix[0][0][2] == '@' && matrix[1][0][2] == '@' && matrix[2][0][2] == '@'){
		nscore++;
	}
	if(matrix[0][1][2] == '@' && matrix[1][1][2] == '@' && matrix[2][1][2] == '@'){
		nscore++;
	}
	if(matrix[0][2][2] == '@' && matrix[1][2][2] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	//other - layer 2 - diagonal checks
	if(matrix[0][0][2] == '@' && matrix[1][1][2] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	if(matrix[2][0][2] == '@' && matrix[1][1][2] == '@' && matrix[0][2][2] == '@'){
		nscore++;
	}
	
	//other - face 0 - all checks from top of cube to bottom
	if(matrix[0][0][0] == '@' && matrix[0][0][1] == '@' && matrix[0][0][2] == '@'){
		nscore++;
	}
	if(matrix[0][1][0] == '@' && matrix[0][1][1] == '@' && matrix[0][1][2] == '@'){
		nscore++;
	}
	if(matrix[0][2][0] == '@' && matrix[0][2][1] == '@' && matrix[0][2][2] == '@'){
		nscore++;
	}
	
	if(matrix[1][0][0] == '@' && matrix[1][0][1] == '@' && matrix[1][0][2] == '@'){
		nscore++;
	}
	if(matrix[1][1][0] == '@' && matrix[1][1][1] == '@' && matrix[1][1][2] == '@'){
		nscore++;
	}
	if(matrix[1][2][0] == '@' && matrix[1][2][1] == '@' && matrix[1][2][2] == '@'){
		nscore++;
	}
	
	if(matrix[2][0][0] == '@' && matrix[2][0][1] == '@' && matrix[2][0][2] == '@'){
		nscore++;
	}
	if(matrix[2][1][0] == '@' && matrix[2][1][1] == '@' && matrix[2][1][2] == '@'){
		nscore++;
	}
	if(matrix[2][2][0] == '@' && matrix[2][2][1] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	
	//other - Vertical-diagonal checks
	if(matrix[0][0][0] == '@' && matrix[1][0][1] == '@' && matrix[2][0][2] == '@'){
		nscore++;
	}
	if(matrix[0][1][0] == '@' && matrix[1][1][1] == '@' && matrix[2][1][2] == '@'){
		nscore++;
	}
	if(matrix[0][2][0] == '@' && matrix[1][2][1] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	
	if(matrix[2][0][0] == '@' && matrix[1][0][1] == '@' && matrix[0][0][2] == '@'){
		nscore++;
	}
	if(matrix[2][1][0] == '@' && matrix[1][1][1] == '@' && matrix[0][1][2] == '@'){
		nscore++;
	}
	if(matrix[2][2][0] == '@' && matrix[1][2][1] == '@' && matrix[0][2][2] == '@'){
		nscore++;
	}
	
	//other - Horizontal-diagonal checks
	if(matrix[0][0][0] == '@' && matrix[0][1][1] == '@' && matrix[0][2][2] == '@'){
		nscore++;
	}
	if(matrix[1][0][0] == '@' && matrix[1][1][1] == '@' && matrix[1][2][2] == '@'){
		nscore++;
	}
	if(matrix[2][0][0] == '@' && matrix[2][1][1] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	
	if(matrix[0][2][0] == '@' && matrix[0][1][1] == '@' && matrix[0][0][2] == '@'){
		nscore++;
	}
	if(matrix[1][2][0] == '@' && matrix[1][1][1] == '@' && matrix[1][0][2] == '@'){
		nscore++;
	}
	if(matrix[2][2][0] == '@' && matrix[2][1][1] == '@' && matrix[2][0][2] == '@'){
		nscore++;
	}
	
	//other - Diagonal-diagonal checks
	if(matrix[0][0][0] == '@' && matrix[1][1][1] == '@' && matrix[2][2][2] == '@'){
		nscore++;
	}
	if(matrix[0][2][0] == '@' && matrix[1][1][1] == '@' && matrix[2][0][2] == '@'){
		nscore++;
	}
	if(matrix[2][2][0] == '@' && matrix[1][1][1] == '@' && matrix[0][0][2] == '@'){
		nscore++;
	}
	if(matrix[2][0][0] == '@' && matrix[1][1][1] == '@' && matrix[0][2][2] == '@'){
		nscore++;
	}
	//returns score after each turn
	cout << " Your score is: " << yscore << endl;
	cout << " Your opponent's score is: " << nscore << endl;
}


