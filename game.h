#include <iostream>
using namespace std;

class game{
//these are all the variables and functions used in "game.cpp"
private:
	char choice;
	int choices;
	char choice2;
	int choice3;
	int press;
	char type;
public:
	game();
	void map(char matrix[3][3][3]);
	void playeryou(char matrix[3][3][3]);
	void playernot(char matrix[3][3][3]);
	void placing();
	void winner();
	void menu();
	void tutorial();
	void gather();
	void exits();
	void end();
	void coinFlip();
	void isDone(char matrix[3][3][3]);
};
