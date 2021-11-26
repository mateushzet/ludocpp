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
#include <string>
using namespace std;
string nameTab[4] = { "YELLOW","RED","BLUE","GEEN" };
Player yellow(39, 0, 0);
Player red(9, 10, 1);
Player blue(19, 20, 2);
Player green(29, 30, 3);
int colorChange[4] = { -2,-2,-2,-2 };
int colorId[4] = { 0,1,2,3 };
char fields[41] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
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
void colorField(HANDLE color, int x)
{
	int id;
	if (colorChange[0] == x || colorChange[1] == x || colorChange[2] == x || colorChange[3] == x) {
		if (colorChange[0] == x) id = 0; else if (colorChange[1] == x) id = 1; else if (colorChange[2] == x) id = 2; else if (colorChange[3] == x) id = 3;
		switch (colorId[id]) {
		case 3:
			if (red.pawns[0]->inFinal == 0 && red.pawns[0]->position == x || red.pawns[1]->inFinal == 0 && red.pawns[1]->position == x || red.pawns[2]->inFinal == 0 && red.pawns[2]->position == x || red.pawns[3]->inFinal == 0 && red.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_BLUE); break;
			}
			else if (blue.pawns[0]->inFinal == 0 && blue.pawns[0]->position == x || blue.pawns[1]->inFinal == 0 && blue.pawns[1]->position == x || blue.pawns[2]->inFinal == 0 && blue.pawns[2]->position == x || blue.pawns[3]->inFinal == 0 && blue.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE); break;
			}
			else if (green.pawns[0]->inFinal == 0 && green.pawns[0]->position == x || green.pawns[1]->inFinal == 0 && green.pawns[1]->position == x || green.pawns[2]->inFinal == 0 && green.pawns[2]->position == x || green.pawns[3]->inFinal == 0 && green.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE); break;
			}
			else if (yellow.pawns[0]->inFinal == 0 && yellow.pawns[0]->position == x || yellow.pawns[1]->inFinal == 0 && yellow.pawns[1]->position == x || yellow.pawns[2]->inFinal == 0 && yellow.pawns[2]->position == x || yellow.pawns[3]->inFinal == 0 && yellow.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_BLUE); break;
			}


		case 1:
			if (red.pawns[0]->inFinal == 0 && red.pawns[0]->position == x || red.pawns[1]->inFinal == 0 && red.pawns[1]->position == x || red.pawns[2]->inFinal == 0 && red.pawns[2]->position == x || red.pawns[3]->inFinal == 0 && red.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_RED | 0); break;
			}
			else if (blue.pawns[0]->inFinal == 0 && blue.pawns[0]->position == x || blue.pawns[1]->inFinal == 0 && blue.pawns[1]->position == x || blue.pawns[2]->inFinal == 0 && blue.pawns[2]->position == x || blue.pawns[3]->inFinal == 0 && blue.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | 0); break;
			}
			else if (green.pawns[0]->inFinal == 0 && green.pawns[0]->position == x || green.pawns[1]->inFinal == 0 && green.pawns[1]->position == x || green.pawns[2]->inFinal == 0 && green.pawns[2]->position == x || green.pawns[3]->inFinal == 0 && green.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | 0); break;
			}
			else if (yellow.pawns[0]->inFinal == 0 && yellow.pawns[0]->position == x || yellow.pawns[1]->inFinal == 0 && yellow.pawns[1]->position == x || yellow.pawns[2]->inFinal == 0 && yellow.pawns[2]->position == x || yellow.pawns[3]->inFinal == 0 && yellow.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | 0); break;
			}

		case 2:
			if (red.pawns[0]->inFinal == 0 && red.pawns[0]->position == x || red.pawns[1]->inFinal == 0 && red.pawns[1]->position == x || red.pawns[2]->inFinal == 0 && red.pawns[2]->position == x || red.pawns[3]->inFinal == 0 && red.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN); break;
			}
			else if (blue.pawns[0]->inFinal == 0 && blue.pawns[0]->position == x || blue.pawns[1]->inFinal == 0 && blue.pawns[1]->position == x || blue.pawns[2]->inFinal == 0 && blue.pawns[2]->position == x || blue.pawns[3]->inFinal == 0 && blue.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN); break;
			}
			else if (green.pawns[0]->inFinal == 0 && green.pawns[0]->position == x || green.pawns[1]->inFinal == 0 && green.pawns[1]->position == x || green.pawns[2]->inFinal == 0 && green.pawns[2]->position == x || green.pawns[3]->inFinal == 0 && green.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN); break;
			}
			else if (yellow.pawns[0]->inFinal == 0 && yellow.pawns[0]->position == x || yellow.pawns[1]->inFinal == 0 && yellow.pawns[1]->position == x || yellow.pawns[2]->inFinal == 0 && yellow.pawns[2]->position == x || yellow.pawns[3]->inFinal == 0 && yellow.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN); break;
			}
		case 0:
			if (red.pawns[0]->inFinal == 0 && red.pawns[0]->position == x || red.pawns[1]->inFinal == 0 && red.pawns[1]->position == x || red.pawns[2]->inFinal == 0 && red.pawns[2]->position == x || red.pawns[3]->inFinal == 0 && red.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
			}
			else if (blue.pawns[0]->inFinal == 0 && blue.pawns[0]->position == x || blue.pawns[1]->inFinal == 0 && blue.pawns[1]->position == x || blue.pawns[2]->inFinal == 0 && blue.pawns[2]->position == x || blue.pawns[3]->inFinal == 0 && blue.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
			}
			else if (green.pawns[0]->inFinal == 0 && green.pawns[0]->position == x || green.pawns[1]->inFinal == 0 && green.pawns[1]->position == x || green.pawns[2]->inFinal == 0 && green.pawns[2]->position == x || green.pawns[3]->inFinal == 0 && green.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
			}
			else if (yellow.pawns[0]->inFinal == 0 && yellow.pawns[0]->position == x || yellow.pawns[1]->inFinal == 0 && yellow.pawns[1]->position == x || yellow.pawns[2]->inFinal == 0 && yellow.pawns[2]->position == x || yellow.pawns[3]->inFinal == 0 && yellow.pawns[3]->position == x)
			{
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
			}
		}
	}
	else {
		if (red.pawns[0]->inFinal == 0 && red.pawns[0]->position == x || red.pawns[1]->inFinal == 0 && red.pawns[1]->position == x || red.pawns[2]->inFinal == 0 && red.pawns[2]->position == x || red.pawns[3]->inFinal == 0 && red.pawns[3]->position == x)
		{

			if (red.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (blue.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}
			
			else if (green.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}
			
			else if (yellow.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}
			else SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

		}
		else if (blue.pawns[0]->inFinal == 0 && blue.pawns[0]->position == x || blue.pawns[1]->inFinal == 0 && blue.pawns[1]->position == x || blue.pawns[2]->inFinal == 0 && blue.pawns[2]->position == x || blue.pawns[3]->inFinal == 0 && blue.pawns[3]->position == x)
		{
			if (red.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (blue.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}

			else if (green.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}

			else if (yellow.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}
			else SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);


			
		}
		else if (green.pawns[0]->inFinal == 0 && green.pawns[0]->position == x || green.pawns[1]->inFinal == 0 && green.pawns[1]->position == x || green.pawns[2]->inFinal == 0 && green.pawns[2]->position == x || green.pawns[3]->inFinal == 0 && green.pawns[3]->position == x)
		{
			if (red.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (blue.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}

			else if (green.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}

			else if (yellow.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}
			else SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

			
		}
		else if (yellow.pawns[0]->inFinal == 0 && yellow.pawns[0]->position == x || yellow.pawns[1]->inFinal == 0 && yellow.pawns[1]->position == x || yellow.pawns[2]->inFinal == 0 && yellow.pawns[2]->position == x || yellow.pawns[3]->inFinal == 0 && yellow.pawns[3]->position == x)
		{
			if (red.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY);
			}
			else if (blue.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}

			else if (green.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}

			else if (yellow.start == x) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			}
			else SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		}
	}

}
void map() {
	system("cls");
	system("COLOR 7B");
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	// UPPER WING... -------------------------------------------------------------------------------------------------------------   UPPER WING...
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "\t\t    .___________." << endl << "\t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 18);
	cout << " " << fields[18] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 19);
	cout << " " << fields[19] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 20);
	cout << " " << fields[20] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "\t\t    |---|---|---|" << endl;
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "\t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 17);
	cout << " " << fields[17] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << blue.final_fields[0] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 21);
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
	colorField(color, 16);
	cout << " " << fields[16] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << blue.final_fields[1] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 22);
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
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 15);
	cout << " " << fields[15] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << blue.final_fields[2] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 23);
	cout << " " << fields[23] << " ";
	// LEFT AND RIGHT WING... ------------------------------------------------------------------------------------------------------    LEFT AND RIGHT WING...
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "    ._______________|---|---|---|_______________." << endl << "    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY); colorField(color, 10);
	cout << " " << fields[10] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 11);
	cout << " " << fields[11] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 12);
	cout << " " << fields[12] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 13);
	cout << " " << fields[13] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 14);
	cout << " " << fields[14] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " " << blue.final_fields[0] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 24);
	cout << " " << fields[24] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 25);
	cout << " " << fields[25] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 26);
	cout << " " << fields[26] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 27);
	cout << " " << fields[27] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 28);
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
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 9);
	cout << " " << fields[9] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << red.final_fields[0] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << red.final_fields[1] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << red.final_fields[2] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << red.final_fields[3] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|   |";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << " " << green.final_fields[3] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << " " << green.final_fields[2] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << " " << green.final_fields[1] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << " " << green.final_fields[0] << " ";
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
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 8);
	cout << " " << fields[8] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 7);
	cout << " " << fields[7] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 6);
	cout << " " << fields[6] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 5);
	cout << " " << fields[5] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 4);
	cout << " " << fields[4] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << yellow.final_fields[3] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 34);
	cout << " " << fields[34] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 33);
	cout << " " << fields[33] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 32);
	cout << " " << fields[32] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 31);
	cout << " " << fields[31] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY); colorField(color, 30);
	cout << " " << fields[30] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "    ^---------------|---|---|---|---------------^" << endl << "\t\t    |";

	// DOWNER WING... -----------------------------------------------------------------------------------------------------------     DOWNER WING...

	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 3);
	cout << " " << fields[3] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << yellow.final_fields[2] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 35);
	cout << " " << fields[35] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "\t\t    |---|---|---|" << endl << "\t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 2);
	cout << " " << fields[2] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	cout << " " << yellow.final_fields[1] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 36);
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
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 1);
	cout << " " << fields[1] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << " " << yellow.final_fields[0] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 37);
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
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY); colorField(color, 0);
	cout << " " << fields[0] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 39);
	cout << " " << fields[39] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 38);
	cout << " " << fields[38] << " ";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|" << endl << "\t\t    ^-----------^" << endl;
}
void move_pawn(Player* player, int which_pawn, int x) {
	if ((!((player->pawns[which_pawn])->inFinal)
		&& (((player->pawns[which_pawn])->position + x) > player->meta
			&& ((player->pawns[which_pawn])->position <= player->meta)
			&& (((player->pawns[which_pawn])->position) >= ((player->meta) - 5)))) || ((player->pawns[which_pawn])->inFinal))
	{
		if ((!((player->pawns[which_pawn])->inFinal) && ((player->final_fields[((x - ((player->meta) - (player->pawns[which_pawn])->position)) - 1)] != 'O') && !((((player->pawns[which_pawn])->position) == player->meta) && x == 6)))
			|| (((player->pawns[which_pawn])->inFinal) && ((((player->pawns[which_pawn])->position) + x) <= 4) && (player->final_fields[(((player->pawns[which_pawn])->position) + x)] != 'O'))) // going to final or is in final
		{
			if (!((player->pawns[which_pawn])->inFinal)) // going to final
			{
				fields[(player->pawns[which_pawn])->position] = ' ';
				(player->pawns[which_pawn])->position = ((x - ((player->meta) - (player->pawns[which_pawn])->position)) - 1);
				player->final_fields[(player->pawns[which_pawn])->position] = 'O';
				((player->pawns[which_pawn])->inFinal) = 1;
				if (((player->pawns[which_pawn])->position) == 4)
				{
					(player->pawns[which_pawn])->ended = true;
					player->final_fields[(player->pawns[which_pawn])->position] = ' ';
				}

			}
			else  // is in final 
			{
				(player->final_fields[((player->pawns[which_pawn])->position)]) = ' ';
				((player->pawns[which_pawn])->position) = (((player->pawns[which_pawn])->position) + x);
				player->final_fields[(player->pawns[which_pawn])->position] = 'O';

			}
		}
	}
	else
	{
		if (((player->pawns[which_pawn])->position + x) > 39)    // if going to move from end of tab fields to begining of tab fields
		{
			if (fields[(player->pawns[which_pawn])->position] == 'O')
				fields[(player->pawns[which_pawn])->position] = ' ';
			else fields[(player->pawns[which_pawn])->position] = 'O';
			(player->pawns[which_pawn])->position = (x - 1) - (39 - (player->pawns[which_pawn])->position);
			if (fields[(player->pawns[which_pawn])->position] == ' ')
				fields[(player->pawns[which_pawn])->position] = 'O';
			else fields[(player->pawns[which_pawn])->position] = '8';

		}
		else														// normal turn
		{
			if ((fields[(((player->pawns[which_pawn])->position) + x)]) != '8') {
				if (fields[(player->pawns[which_pawn])->position] == 'O')
					fields[(player->pawns[which_pawn])->position] = ' ';
				else fields[(player->pawns[which_pawn])->position] = 'O';
				(player->pawns[which_pawn])->position = (player->pawns[which_pawn])->position + x;
				if (fields[(player->pawns[which_pawn])->position] == ' ')
					fields[(player->pawns[which_pawn])->position] = 'O';
				else fields[(player->pawns[which_pawn])->position] = '8';

			}
		}
	}
}
void header(Player* player) {
	HANDLE msgColor;
	msgColor = GetStdHandle(STD_OUTPUT_HANDLE);
	if (player->id == 1)
		SetConsoleTextAttribute(msgColor, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	if (player->id == 2)
		SetConsoleTextAttribute(msgColor, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	if (player->id == 3)
		SetConsoleTextAttribute(msgColor, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	if (player->id == 0)
		SetConsoleTextAttribute(msgColor, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << nameTab[player->id] << " TURN\n";
	SetConsoleTextAttribute(msgColor, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}
int print_active(Player* player, int x) {

	int which_pawn;

	// change pawns to colors //
	for (int j = 0; j <= 3; j++)
	{
		if ((player->pawns[j])->inBase == 0)
		{
			//if(((player->pawns[j])->inFinal) == 1)
			//player->final_fields[(player->pawns[j])->position] = '0' + (number);

			colorChange[j] = (player->pawns[j])->position;
		}
	}

	map();
	// change numbers to pawns //
	for (int j = 0; j <= 3; j++)
	{
		if ((player->pawns[j])->inBase == 0)
		{

			/*if (((player->pawns[j])->inFinal) == 1)
			{
				player->final_fields[(player->pawns[j])->position] = 'O';
			}*/

			colorChange[j] = -2;
		}
	}
	header(player);
	cout << "Witch pawn do you want to move?" << endl;

	// cout pawns that can move //
	int number = 4;
	bool correct[4] = { 0 };
	for (int i = 0; i <= 3; i++)
	{
		if ((((!((player->pawns[i])->inFinal) && (((player->pawns[i])->position + x) > player->meta && ((player->pawns[i])->position <= player->meta) && (((player->pawns[i])->position) >= ((player->meta) - 5)))) || ((player->pawns[i])->inFinal))
			&& ((!((player->pawns[i])->inFinal) && ((player->final_fields[((x - ((player->meta) - (player->pawns[i])->position)) - 1)] != 'O') && !((((player->pawns[i])->position) == player->meta) && x == 6))) || (((player->pawns[i])->inFinal) && ((((player->pawns[i])->position) + x) <= 4) && (player->final_fields[(((player->pawns[i])->position) + x)] != 'O'))))
			|| (!((player->pawns[i])->inFinal) && (!((player->pawns[i])->inBase))
				//			not in final		and					not in base
				&& !((((player->pawns[i])->position + x) > player->meta) && ((player->pawns[i])->position <= player->meta) && (((player->pawns[i])->position) >= ((player->meta) - 5)))
				//and not going to final
				&& (fields[(((player->pawns[i])->position) + x)]) != '8'))
			//and	next field is not full 		
		{

			correct[i] = 1;
		}
		number--;
	}
	bool havePartner[4] = { 0 };
	int partnerId[4] = { -1,-1,-1,-1 };
	int partnerId2[4] = { -1,-1,-1,-1 };
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 1 + i; j <= 3; j++)
		{
			if (i!=j) {
				if (((((player->pawns[i])->position)) == ((player->pawns[j])->position)) && ((correct[i] == 1 && fields[(player->pawns[i])->position] == '8')) && (correct[j] == 1 && fields[(player->pawns[j])->position] == '8'))
				{
					havePartner[j] = 1;
					partnerId[j] = i;
				}
			}
		}
	}



	int xSwitch;
	string banned = " ";
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	int banedPartner[4] = {-1,-1,-1,-1};
	for (int i = 3; i >= 0; i--)
	{
		if (correct[i] == 1 && i != banedPartner[partnerId[i]])
		{

			if (havePartner[i] == 1)
			{
				banedPartner[i] = partnerId[i];
			}
		}
	}
	for (int i = 3; i >= 0; i--)
	{
		if (correct[i] == 1)
		{
			
					if (i != banedPartner[0] && i != banedPartner[1] && i != banedPartner[2] && i != banedPartner[3])
					{
						if (havePartner[i] == 1) xSwitch = banedPartner[i]; else xSwitch = i;


						switch (xSwitch) {
						case 0:
							SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i]==1) cout << " - " << i+1 << " or "<< banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							break;
						case 1:
							SetConsoleTextAttribute(color, 0);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i] == 1) cout << " - " << i+1 << " or " << banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							break;
						case 2:
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i] == 1) cout << " - " << i+1 << " or " << banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							break;
						case 3:
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i] == 1) cout << " - " << i+1 << " or " << banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							break;
						}
					}
		
		}
	}

	cin >> which_pawn;
	switch (which_pawn)
		{

		case 1:
			if (correct[0] == 0) { print_active(player, x); break; }
			return 0; break;


		case 2:
			if (correct[1] == 0) { print_active(player, x); break; }
		 return 1; break;


		case 3:
			if (correct[2] == 0) { print_active(player, x); break; }
			 return 2; break;

		case 4: if (correct[3] == 0) { print_active(player, x); break; }
			 return 3; break;

		default: print_active(player, x); break;
		}
}
void turn(Player* player)
{
	int x;
	int y;
	header(player);
	cout << "Press any key to roll";
	_getch();
	x = roll();
	//x = 6;
	map();
	if (x != 6 && player->inBase == 4);			  //    0 PAWNS ON BOARD	|	dice 1-5
	else if (x == 6 && player->inBase == 4)       //    0 PAWNS ON BOARD	|	dice 6
	{
		fields[player->start] = 'O';
		player->inBase = player->inBase - 1;
		(player->pawns[0])->inBase = 0;
		(player->pawns[0])->position = player->start;
	}
	else if (x == 6 && player->inBase > 0 && fields[player->start] != '8')    //    1-4 PAWNS ON BOARD	|	dice 6	|	free starting position
	{
		header(player);
		cout << "leave base (1) \nmove pawn (2)";
		cin >> y;
		if (fields[player->start] == ' ' && y == 1)
		{
			fields[player->start] = 'O';
			player->inBase = player->inBase - 1;
			(player->pawns[3-player->inBase])->inBase = 0;
			(player->pawns[3-player->inBase])->position = player->start;
		}
		else if (fields[player->start] == 'O' && y == 1)
		{
			fields[player->start] = '8';
			player->inBase = player->inBase - 1;
			(player->pawns[3-player->inBase])->inBase = 0;
			(player->pawns[3-player->inBase])->position = player->start;
		}
		else if (y == 2)
		{
			int which_pawn = print_active(player, x);
			move_pawn(player, which_pawn, x);
		}

	}
	else if (player->inBase == 3)																						//    1 PAWN ON BOARD	|	dice 1-5
	{

		int which_pawn;
		if ((player->pawns[0])->inBase == 0)
			which_pawn = 0;
		if ((player->pawns[1])->inBase == 0)
			which_pawn = 1;
		if ((player->pawns[2])->inBase == 0)
			which_pawn = 2;
		if ((player->pawns[3])->inBase == 0)
			which_pawn = 3;
		move_pawn(player, which_pawn, x);
	}
	else																												//    2-4 PAWN ON BOARD		|	dice 1-5
	{
		int which_pawn = print_active(player, x);
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
		//map();
		//turn(&blue);
	}
}
