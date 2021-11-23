#include "map.h"
#include "players.h"
#include<iostream>
#include <windows.h>
#include <thread>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <chrono>
using namespace std;
Player yellow(39);
Player red(9);
Player blue(19);
Player green(29);
char fields[72] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char diceTab[7] = { ' ',' ',' ',' ',' ',' ',' ' };
char meta_red[4] = { ' ',' ', ' ', ' ' };
void fillDice(int x, char diceTab[7]) {
	switch (x) {
	case 0:
		diceTab[0] = ' ';
		diceTab[1] = ' ';
		diceTab[2] = ' ';
		diceTab[3] = ' ';
		diceTab[4] = ' ';
		diceTab[5] = ' ';
		diceTab[6] = ' ';
		break;
	case 1:
		diceTab[0] = '*';
		diceTab[1] = ' ';
		diceTab[2] = ' ';
		diceTab[3] = ' ';
		diceTab[4] = ' ';
		diceTab[5] = ' ';
		diceTab[6] = ' ';
		break;
	case 2:
		diceTab[0] = ' ';
		diceTab[1] = '*';
		diceTab[2] = ' ';
		diceTab[3] = ' ';
		diceTab[4] = ' ';
		diceTab[5] = ' ';
		diceTab[6] = '*';
		break;
	case 3:
		diceTab[0] = '*';
		diceTab[1] = '*';
		diceTab[2] = ' ';
		diceTab[3] = ' ';
		diceTab[4] = ' ';
		diceTab[5] = ' ';
		diceTab[6] = '*';
		break;
	case 4:
		diceTab[0] = ' ';
		diceTab[1] = '*';
		diceTab[2] = '*';
		diceTab[3] = ' ';
		diceTab[4] = ' ';
		diceTab[5] = '*';
		diceTab[6] = '*';
		break;
	case 5:
		diceTab[0] = '*';
		diceTab[1] = '*';
		diceTab[2] = '*';
		diceTab[3] = ' ';
		diceTab[4] = ' ';
		diceTab[5] = '*';
		diceTab[6] = '*';
		break;
	case 6:
		diceTab[0] = ' ';
		diceTab[1] = '*';
		diceTab[2] = '*';
		diceTab[3] = '*';
		diceTab[4] = '*';
		diceTab[5] = '*';
		diceTab[6] = '*';
		break;
	}
}
int roll() {
	int x;
	srand(time(NULL));
	x = (std::rand() % 6) + 1;
	fillDice(x, diceTab);
	return x;

}
void map() {
	system("cls");
	system("COLOR 7B");
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	// UPPER WING... -------------------------------------------------------------------------------------------------------------   UPPER WING...
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "\t\t    .___________." << endl << "\t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[18] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[19] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[20] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "\t\t    |---|---|---|" << endl;
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "\t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[17] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[21] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl;

	// UPPER RED BASE -------------------------------------------------------------------------------------------------------------   UPPER RED BASE

	cout << "    ";
	SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	
	if (red.inBase == 4)
	{
		cout << "| O | O |";
	}
	else if (red.inBase == 3)
	{
		cout << "|   | O |";
	}
	else if (red.inBase <= 2)
	{
		cout << "|   |   |";
	}

	// ...UPPER WING... -------------------------------------------------------------------------------------------------------------   ...UPPER WING...

	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "  \t    |---|---|---|";

	// UPPER BLUE BASE -------------------------------------------------------------------------------------------------------------   UPPER BLUE BASE

	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |" << endl;

	// DOWNER RED BASE -------------------------------------------------------------------------------------------------------------   DOWNER RED BASE

	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "    ";
	SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	if (red.inBase >= 2)
	{
		cout << "| O | O |";
	}
	else if (red.inBase == 1)
	{
		cout << "|   | O |";
	}
	else if (red.inBase == 0)
	{
		cout << "|   |   |";
	}
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

	// ...UPPER WING... -------------------------------------------------------------------------------------------------------------   ...UPPER WING...

	cout << "\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[16] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[22] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";

	// DOWNER BLUE BASE	-------------------------------------------------------------------------------------------------------------   DOWNER BLUE BASE	

	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

	// ...UPPER WING -------------------------------------------------------------------------------------------------------------    ...UPPER WING	

	cout << endl << "\t\t    |---|---|---|" << endl << "    \t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[15] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[23] << " ";
	// LEFT AND RIGHT WING... ------------------------------------------------------------------------------------------------------    LEFT AND RIGHT WING...
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "    ._______________|---|---|---|_______________." << endl << "    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << fields[10] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[11] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[12] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[13] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[14] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[24] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[25] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[26] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[27] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[28] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	// DICE -----------------------------------------------------------------------------------------------------------         DICE
	cout << "\t\t";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "  " << diceTab[1] << " " << diceTab[2] << "  ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// ...LEFT AND RIGHT WING... ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING...
	cout << endl << "    |---|---|---|---|---|---|---|---|---|---|---|";
	// DICE -----------------------------------------------------------------------------------------------------------         DICE
	cout << "\t\t";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "  " << diceTab[3] << diceTab[0] << diceTab[4] << "  ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// ...LEFT AND RIGHT WING... ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING...
	cout << endl << "    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[9] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " "<< fields[40] <<" ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << fields[41] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << fields[42] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << fields[43] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|   |";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[29] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	// DICE --------------------------------------------------------------------------------------------------------     DICE
	cout << "\t\t";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "  " << diceTab[5] << " " << diceTab[6] << "  ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// ...LEFT AND RIGHT WING ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING
	cout << endl << "    |---|---|---|---|---|---|---|---|---|---|---|" << endl << "    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[8] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[7] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[6] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[5] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[4] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[34] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[33] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[32] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[31] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << " " << fields[30] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "    ^---------------|---|---|---|---------------^" << endl << "\t\t    |";

	// DOWNER WING... -----------------------------------------------------------------------------------------------------------     DOWNER WING...

	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[3] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[35] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "\t\t    |---|---|---|" << endl << "\t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[2] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[36] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	//  UPPER YELOW BASE -------------------------------------------------------------------------------------------------------------      UPPER YELOW BASE

	cout << endl << "    ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";

	//  ...DOWNER WING... -------------------------------------------------------------------------------------------------------------      ...DOWNER WING...

	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "  \t    |---|---|---|";

	// UPPER GREEN BASE -------------------------------------------------------------------------------------------------------------      UPPER GREEN BASE

	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |" << endl;


	// DOWNER YELLOW BASE -------------------------------------------------------------------------------------------------------------       DOWNER YELLOW BASE

	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "    ";
	SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

	// ...DOWNER WING... -------------------------------------------------------------------------------------------------------------      ...DOWNER WING...

	cout << "\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[1] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "   ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[37] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";

	// DOWNER GREEN BASE -------------------------------------------------------------------------------------------------------------      DOWNER GREEN BASE		
	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

	// ...DOWNER WING -------------------------------------------------------------------------------------------------------------     ...DOWNER WING		

	cout << endl << "\t\t    |---|---|---|" << endl << "    \t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << fields[0] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[39] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << fields[38] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "\t\t    ^-----------^" << endl;
}
void move_pawn(Player *player, int which_pawn, int x){
	if (fields[(player->pawns[which_pawn - 1])->position] == 'O')
	{
		if (((player->pawns[which_pawn - 1])->position + x) > 39)
		{
			fields[(player->pawns[which_pawn - 1])->position] = ' ';
			(player->pawns[which_pawn - 1])->position = (x - 1) - (39 - (player->pawns[which_pawn - 1])->position);
			if (fields[(player->pawns[which_pawn - 1])->position] == ' ')
				fields[(player->pawns[which_pawn - 1])->position] = 'O';
			else fields[(player->pawns[which_pawn - 1])->position] = '8';
		}
		else
		{
			fields[(player->pawns[which_pawn - 1])->position] = ' ';
			(player->pawns[which_pawn - 1])->position = (player->pawns[which_pawn - 1])->position + x;
			if (fields[(player->pawns[which_pawn - 1])->position] == ' ')
				fields[(player->pawns[which_pawn - 1])->position] = 'O';
			else fields[(player->pawns[which_pawn - 1])->position] = '8';
		}

	}
	else if (fields[(player->pawns[which_pawn - 1])->position] == '8')
	{
		if (((player->pawns[which_pawn - 1])->position + x) > 39)
		{
			fields[(player->pawns[which_pawn - 1])->position] = 'O';
			(player->pawns[which_pawn - 1])->position = (x - 1) - (39 - (player->pawns[which_pawn - 1])->position);
			if (fields[(player->pawns[which_pawn - 1])->position] == ' ')
				fields[(player->pawns[which_pawn - 1])->position] = 'O';
			else fields[(player->pawns[which_pawn - 1])->position] = '8';
		}
		else
		{
			fields[(player->pawns[which_pawn - 1])->position] = 'O';
			(player->pawns[which_pawn - 1])->position = (player->pawns[which_pawn - 1])->position + x;
			if (fields[(player->pawns[which_pawn - 1])->position] == ' ')
				fields[(player->pawns[which_pawn - 1])->position] = 'O';
			else fields[(player->pawns[which_pawn - 1])->position] = '8';
		}

	}
}
void print_active(Player* player, int x) {
	cout << "Pionkiem z ktorego pola chcesz ruszyc?";
	if (!(player->pawns[0])->inBase && fields[(player->pawns[0])->position + x] != '8')
		cout << "1) " << (player->pawns[0])->position << endl;
	if (!(player->pawns[1])->inBase && fields[(player->pawns[1])->position + x] != '8')
		cout << "2) " << (player->pawns[1])->position << endl;
	if (!(player->pawns[2])->inBase && fields[(player->pawns[2])->position + x] != '8')
		cout << "3) " << (player->pawns[2])->position << endl;
	if (!(player->pawns[3])->inBase && fields[(player->pawns[3])->position + x] != '8')
		cout << "4) " << (player->pawns[3])->position << endl;
}


void turn(Player *player)
{
	int x;
	int y;
	cout << "Press any key to roll";
	_getch();
	x = roll();
	//x = 6;
	map();
	if (x != 6 && player->inBase == 4);			  //    0 PAWNS ON BOARD	|	dice 1-5
	else if (x == 6 && player->inBase == 4)       //    0 PAWNS ON BOARD	|	dice 6
	{
		fields[10] = 'O';
		player->inBase = player->inBase - 1;
		(player->pawns[3])->inBase = 0;
		(player->pawns[3])->position = 10;
	}
	else if (x == 6 && player->inBase>0 && fields[10]!='8')    //    1-4 PAWNS ON BOARD	|	dice 6	|	free starting position
	{
		cout << "\twyjdz z bazy 1) ruch pionkiem 2)";
		cin >> y;
		if (fields[10] == ' ' && y==1)
		{
			fields[10] = 'O';
			player->inBase = player->inBase - 1;
			(player->pawns[player->inBase])->inBase = 0;
			(player->pawns[player->inBase])->position = 10;
		}
		else if (fields[10] == 'O' && y == 1)
		{
			fields[10] = '8';
			player->inBase = player->inBase - 1;
			(player->pawns[player->inBase])->inBase = 0;
			(player->pawns[player->inBase])->position = 10;
		}
		else if (y == 2)
		{
			int which_pawn;
			print_active(player, x);
			cin >> which_pawn;
			move_pawn(player, which_pawn, x);
		}
		
	}else if(player->inBase == 3)																						//    1 PAWN ON BOARD	|	dice 1-5
	{
	
		int which_pawn;
		if ((player->pawns[0])->inBase == 0)
			which_pawn = 1;
		if ((player->pawns[1])->inBase == 0)
			which_pawn = 2;
		if ((player->pawns[2])->inBase == 0)
			which_pawn = 3;
		if ((player->pawns[3])->inBase == 0)
			which_pawn = 4;
		move_pawn(player, which_pawn, x);
	}
	else																												//    2-4 PAWN ON BOARD		|	dice 1-5
	{
		int which_pawn;
		print_active(player, x);
		cin >> which_pawn;
		move_pawn(player, which_pawn, x);
	}
}
void start()
{


	map();
	cout << "Press any key to start...";
	while (true) {
		map();
		turn(&red);
	}
}
