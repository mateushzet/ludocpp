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

string nameTab[4] = { "YELLOW","RED","BLUE","GREEN" };
int playersOnTabs[40] = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 }; 
int pawnsOnTabs[40] = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };
Player yellow(39, 0, 0);
Player red(9, 10, 1);
Player blue(19, 20, 2);
Player green(29, 30, 3);
Player* playersTab[4] = { &yellow, &red, &blue, &green };
string podium[3] = { "0","0","0" };
int colorChange[4] = { -2,-2,-2,-2 };
int colorChangeMeta[4] = { -2,-2,-2,-2 };
int colorChangeMeta2[4] = { -2,-2,-2,-2 };
int colorId[4] = { 0,1,2,3 };

char fields[41] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };

char diceTab[7] = { ' ',' ',' ',' ',' ',' ',' ' };

char meta_red[4] = { ' ',' ', ' ', ' ' };
char meta_blue[4] = { ' ',' ', ' ', ' ' };
char meta_yellow[4] = { ' ',' ', ' ', ' ' };
char meta_green[4] = { ' ',' ', ' ', ' ' };
void grayBackground(HANDLE color)
{
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}
void whiteBackground(HANDLE color)
{
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
}
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
void colorMeta(HANDLE color, int x, int player)
{
	if (colorChangeMeta2[0] == player || colorChangeMeta2[1] == player || colorChangeMeta2[2] == player || colorChangeMeta2[3] == player) {
		int id;
		if ((colorChangeMeta[0] == x || colorChangeMeta[1] == x || colorChangeMeta[2] == x || colorChangeMeta[3] == x)) {
			if (colorChangeMeta[0] == x) id = 0; else if (colorChangeMeta[1] == x) id = 1; else if (colorChangeMeta[2] == x) id = 2; else if (colorChangeMeta[3] == x) id = 3;
			switch (colorId[id]) {
			case 3:
				if (colorChangeMeta2[id] == 1) {
					SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_BLUE); break;
				}
				else if (colorChangeMeta2[id] == 2) {
					SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE); break;
				}
				else if (colorChangeMeta2[id] == 3) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE); break;
				}
				else if (colorChangeMeta2[id] == 0) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_BLUE); break;
				}


			case 1:
				if (colorChangeMeta2[id] == 1) {
					SetConsoleTextAttribute(color, FOREGROUND_RED | 0); break;
				}
				else if (colorChangeMeta2[id] == 2) {
					SetConsoleTextAttribute(color, FOREGROUND_BLUE | 0); break;
				}
				else if (colorChangeMeta2[id] == 3) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | 0); break;
				}
				else if (colorChangeMeta2[id] == 0) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | 0); break;
				}

			case 2:
				if (colorChangeMeta2[id] == 1) {
					SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN); break;
				}
				else if (colorChangeMeta2[id] == 2) {
					SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN); break;
				}
				else if (colorChangeMeta2[id] == 3) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN); break;
				}
				else if (colorChangeMeta2[id] == 0) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN); break;
				}
			case 0:
				if (colorChangeMeta2[id] == 1) {
					SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
				}
				else if (colorChangeMeta2[id] == 2) {
					SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
				}
				else if (colorChangeMeta2[id] == 3) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
				}
				else if (colorChangeMeta2[id] == 0) {
					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY); break;
				}
			}

		}

	}
}
void map() {
	system("cls");
	system("COLOR 7B");
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "inBase = " << red.inBase << " | inEnded = " << red.inEnded << "| finalFields: " << red.final_fields[0] << red.final_fields[1] << red.final_fields[2] << red.final_fields[3] << endl << " P0: " << "inBase:" << red.pawns[0]->inBase << " inFinal:" << red.pawns[0]->inFinal << " ended:" << red.pawns[0]->ended << " position:" << red.pawns[0]->position << endl << " P1: " << "inBase:" << red.pawns[1]->inBase << " inFinal:" << red.pawns[1]->inFinal << " ended:" << red.pawns[1]->ended << " position:" << red.pawns[1]->position << endl << " P2: " << "inBase:" << red.pawns[2]->inBase << " inFinal:" << red.pawns[2]->inFinal << " ended:" << red.pawns[2]->ended << " position:" << red.pawns[2]->position << endl << " P3: " << "inBase:" << red.pawns[3]->inBase << " inFinal:" << red.pawns[3]->inFinal << " ended:" << red.pawns[3]->ended << " position:" << red.pawns[3]->position << endl;
	

	// UPPER WING... -------------------------------------------------------------------------------------------------------------   UPPER WING...
	grayBackground(color);
	cout << "\t\t    .___________." << endl << "\t\t    |";
	whiteBackground( color); colorField(color, 18);
	cout << " " << fields[18] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground( color); colorField(color, 19);
	cout << " " << fields[19] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY); colorField(color, 20);
	cout << " " << fields[20] << " ";
	grayBackground(color);
	cout << "|" << endl << "\t\t    |---|---|---|" << endl;
	grayBackground(color);
	cout << "\t\t    |";
	whiteBackground(color); colorField(color, 17);
	cout << " " << fields[17] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY); 
	colorMeta(color, 0,2);
	cout << " " << blue.final_fields[0] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 21);
	cout << " " << fields[21] << " ";
	grayBackground(color);
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

	grayBackground(color);
	cout << "  \t    |---|---|---|";

	// UPPER BLUE BASE -------------------------------------------------------------------------------------------------------------   UPPER BLUE BASE

	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |" << endl;

	// DOWNER RED BASE -------------------------------------------------------------------------------------------------------------   DOWNER RED BASE

	grayBackground(color);
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
	grayBackground(color);

	// ...UPPER WING... -------------------------------------------------------------------------------------------------------------   ...UPPER WING...

	cout << "\t    |";
	whiteBackground(color);
	colorField(color, 16);
	cout << " " << fields[16] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	colorMeta(color, 1,2);
	cout << " " << blue.final_fields[1] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 22);
	cout << " " << fields[22] << " ";
	grayBackground(color);
	cout << "|";

	// DOWNER BLUE BASE	-------------------------------------------------------------------------------------------------------------   DOWNER BLUE BASE	

	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";
	grayBackground(color);

	// ...UPPER WING -------------------------------------------------------------------------------------------------------------    ...UPPER WING	

	cout << endl << "\t\t    |---|---|---|" << endl << "    \t\t    |";
	whiteBackground(color); colorField(color, 15);
	cout << " " << fields[15] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);

	colorMeta(color, 2,2);
	cout << " " << blue.final_fields[2] << " ";

	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 23);
	cout << " " << fields[23] << " ";
	// LEFT AND RIGHT WING... ------------------------------------------------------------------------------------------------------    LEFT AND RIGHT WING...
	grayBackground(color);
	cout << "|" << endl << "    ._______________|---|---|---|_______________." << endl << "    |";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY); colorField(color, 10);
	cout << " " << fields[10] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 11);
	cout << " " << fields[11] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 12);
	cout << " " << fields[12] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 13);
	cout << " " << fields[13] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 14);
	cout << " " << fields[14] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	
	colorMeta(color, 3,2);
	cout << " " << blue.final_fields[3] << " ";

	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 24);
	cout << " " << fields[24] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 25);
	cout << " " << fields[25] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 26);
	cout << " " << fields[26] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 27);
	cout << " " << fields[27] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 28);
	cout << " " << fields[28] << " ";
	grayBackground(color);
	cout << "|";
	// DICE -----------------------------------------------------------------------------------------------------------         DICE & PODIUM
	cout << "\t\t";
	whiteBackground(color);
	cout << "  " << diceTab[1] << " " << diceTab[2] << "  ";
	grayBackground(color);
	if(podium[0]!="0")cout << "\t FIRST PLACE: "<<podium[0];
	// ...LEFT AND RIGHT WING... ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING...
	cout << endl << "    |---|---|---|---|---|---|---|---|---|---|---|";
	// DICE -----------------------------------------------------------------------------------------------------------         DICE & PODIUM
	cout << "\t\t";
	whiteBackground(color);
	cout << "  " << diceTab[3] << diceTab[0] << diceTab[4] << "  ";
	grayBackground(color);
	if (podium[1] != "0")cout << "\t SECOND PLACE: "<< podium[1];
	// ...LEFT AND RIGHT WING... ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING...
	cout << endl << "    |";
	whiteBackground(color); colorField(color, 9);
	cout << " " << fields[9] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
	 
	colorMeta(color, 0,1);
	cout << " " << red.final_fields[0] << " ";
	 
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
 
	colorMeta(color, 1,1);
	cout << " " << red.final_fields[1] << " ";
 
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
 
	colorMeta(color, 2,1);
	cout << " " << red.final_fields[2] << " ";
 
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
 
	colorMeta(color, 3,1);
	cout << " " << red.final_fields[3] << " ";
 
	grayBackground(color);
	cout << "|   |";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	 
	colorMeta(color, 3,3);
	cout << " " << green.final_fields[3] << " ";
 
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
 
	colorMeta(color, 2,3);
	cout << " " << green.final_fields[2] << " ";
 
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
 
	colorMeta(color, 1,3);
	cout << " " << green.final_fields[1] << " ";
 
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
 
	colorMeta(color, 1,3);
	cout << " " << green.final_fields[1] << " ";
 
	grayBackground(color);
	cout << "|";
	whiteBackground(color);
	cout << " " << fields[29] << " ";
	grayBackground(color);
	cout << "|";
	// DICE --------------------------------------------------------------------------------------------------------     DICE & PODIUM
	cout << "\t\t";
	whiteBackground(color);
	cout << "  " << diceTab[5] << " " << diceTab[6] << "  ";
	grayBackground(color);
	if (podium[2] != "0")cout << "\t THIRD PLACE: "<< podium[2];
	// ...LEFT AND RIGHT WING ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING
	cout << endl << "    |---|---|---|---|---|---|---|---|---|---|---|" << endl << "    |";
	whiteBackground(color); colorField(color, 8);
	cout << " " << fields[8] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 7);
	cout << " " << fields[7] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 6);
	cout << " " << fields[6] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 5);
	cout << " " << fields[5] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 4);
	cout << " " << fields[4] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
 
	colorMeta(color, 3,0);
	cout << " " << yellow.final_fields[3] << " ";
 
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 34);
	cout << " " << fields[34] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 33);
	cout << " " << fields[33] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 32);
	cout << " " << fields[32] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 31);
	cout << " " << fields[31] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY); colorField(color, 30);
	cout << " " << fields[30] << " ";
	grayBackground(color);
	cout << "|" << endl << "    ^---------------|---|---|---|---------------^" << endl << "\t\t    |";

	// DOWNER WING... -----------------------------------------------------------------------------------------------------------     DOWNER WING...

	whiteBackground(color); colorField(color, 3);
	cout << " " << fields[3] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
 
	colorMeta(color, 2,0);
	cout << " " << yellow.final_fields[2] << " ";
 
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 35);
	cout << " " << fields[35] << " ";
	grayBackground(color);
	cout << "|" << endl << "\t\t    |---|---|---|" << endl << "\t\t    |";
	whiteBackground(color); colorField(color, 2);
	cout << " " << fields[2] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
 
	colorMeta(color, 1,0);
	cout << " " << yellow.final_fields[1] << " ";
 
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 36);
	cout << " " << fields[36] << " ";
	grayBackground(color);
	cout << "|";
	//  UPPER YELOW BASE -------------------------------------------------------------------------------------------------------------      UPPER YELOW BASE

	cout << endl << "    ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";

	//  ...DOWNER WING... -------------------------------------------------------------------------------------------------------------      ...DOWNER WING...

	grayBackground(color);
	cout << "  \t    |---|---|---|";

	// UPPER GREEN BASE -------------------------------------------------------------------------------------------------------------      UPPER GREEN BASE

	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |" << endl;


	// DOWNER YELLOW BASE -------------------------------------------------------------------------------------------------------------       DOWNER YELLOW BASE

	grayBackground(color);
	cout << "    ";
	SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";
	grayBackground(color);

	// ...DOWNER WING... -------------------------------------------------------------------------------------------------------------      ...DOWNER WING...

	cout << "\t    |";
	whiteBackground(color); colorField(color, 1);
	cout << " " << fields[1] << " ";
	grayBackground(color);
	cout << "|";
	SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
 
	colorMeta(color, 0,0);
	cout << " " << yellow.final_fields[0] << " ";
 
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 37);
	cout << " " << fields[37] << " ";
	grayBackground(color);
	cout << "|";

	// DOWNER GREEN BASE -------------------------------------------------------------------------------------------------------------      DOWNER GREEN BASE		
	cout << "       ";
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "| O | O |";
	grayBackground(color);

	// ...DOWNER WING -------------------------------------------------------------------------------------------------------------     ...DOWNER WING		

	cout << endl << "\t\t    |---|---|---|" << endl << "    \t\t    |";
	SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY); colorField(color, 0);
	cout << " " << fields[0] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 39);
	cout << " " << fields[39] << " ";
	grayBackground(color);
	cout << "|";
	whiteBackground(color); colorField(color, 38);
	cout << " " << fields[38] << " ";
	grayBackground(color);
	cout << "|" << endl << "\t\t    ^-----------^" << endl;
}

bool goingToFinal(Player* player, int which_pawn, int x)
{
	if (!((player->pawns[which_pawn])->inFinal)
		&& (((player->pawns[which_pawn])->position + x) > player->meta
			&& ((player->pawns[which_pawn])->position <= player->meta)
			&& (((player->pawns[which_pawn])->position) >= ((player->meta) - 5))) && ((player->final_fields[((x - ((player->meta) - (player->pawns[which_pawn])->position)) - 1)] != 'O') && !((((player->pawns[which_pawn])->position) == player->meta) && x == 6)))
		return 1; else return 0;
}
bool isInFinal(Player* player, int which_pawn, int x)
{
	if (((player->pawns[which_pawn])->inFinal && (player->pawns[which_pawn])->ended == false) && ((((player->pawns[which_pawn])->position) + x) <= 4) && (player->final_fields[(((player->pawns[which_pawn])->position) + x)] != 'O') && (player->pawns[which_pawn])->ended == false)
		return 1; else return 0;
};
bool ifEndTab(Player* player, int which_pawn, int x)
{
	if (((player->pawns[which_pawn])->position + x) > 39 && fields[(x - 1) - (39 - (player->pawns[which_pawn])->position)] != '8')
		return 1; else return 0;
		
}
void changePosition(Player* player, int which_pawn, int x)
{

	if (!goingToFinal(player, which_pawn, x) || !isInFinal(player, which_pawn, x)) {
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (playersTab[j]->inBase == 0 && red.pawns[i]->inFinal == 0) 
				{
					playersOnTabs[playersTab[j]->pawns[i]->position] == red.id;
					pawnsOnTabs[playersTab[j]->pawns[i]->position] == i;
				}
			}
		}

		if (fields[(player->pawns[which_pawn])->position] == 'O')
			fields[(player->pawns[which_pawn])->position] = ' ';
		else fields[(player->pawns[which_pawn])->position] = 'O';
		if (ifEndTab(player, which_pawn, x))
			(player->pawns[which_pawn])->position = (x - 1) - (39 - (player->pawns[which_pawn])->position);
		else (player->pawns[which_pawn])->position = (player->pawns[which_pawn])->position + x;
		if (fields[(player->pawns[which_pawn])->position] == ' ')
			fields[(player->pawns[which_pawn])->position] = 'O';
		else {
			if (playersOnTabs[(player->pawns[which_pawn])->position] != 9 && playersOnTabs[(player->pawns[which_pawn])->position] != player->id)
			{
				playersTab[player->pawns[which_pawn]->position]->pawns[pawnsOnTabs[player->pawns[which_pawn]->position]]->inBase = 0;
				for (int i = 0; i < 40; i++)
				{
					playersOnTabs[i] = 9;
					pawnsOnTabs[i] = 9;
				}
				fields[(player->pawns[which_pawn])->position] = 'O';
			}
			else
			fields[(player->pawns[which_pawn])->position] = '8';
		}
		
	}
}
void ending(Player* player, int which_pawn, int x)
{
	if (((player->pawns[which_pawn])->position) == 4)
	{
		(player->pawns[which_pawn])->ended = true;
		player->inEnded = player->inEnded + 1;
		player->final_fields[(player->pawns[which_pawn])->position] = ' ';
		if (((player->pawns[0])->ended) && ((player->pawns[1])->ended) && ((player->pawns[2])->ended) && ((player->pawns[3])->ended))
		{
			if (podium[0] == "0")
				podium[0] = nameTab[player->id];
			else if (podium[1] == "0")
				podium[1] = nameTab[player->id];
			else if (podium[2] == "0")
				podium[2] = nameTab[player->id];
		}
	}
}
bool nextNotFull(Player* player, int which_pawn, int x)
{


	if ((player->pawns[which_pawn])->inBase == 0 && !(!((player->pawns[which_pawn])->inFinal)
		&& (((player->pawns[which_pawn])->position + x) > player->meta
			&& ((player->pawns[which_pawn])->position <= player->meta)
			&& (((player->pawns[which_pawn])->position) >= ((player->meta) - 5)))) && !((player->pawns[which_pawn])->inFinal)) {
		int pos = ((player->pawns[which_pawn])->position);
		if (ifEndTab(player, which_pawn, x)) {
			if (fields[(x - 1) - (39 - (player->pawns[which_pawn])->position)] == '8')
				return 0; else return 1;
		}
		else {
			if (fields[(player->pawns[which_pawn])->position + x] == '8')
				return 0; else return 1;
		}
	}
	else return 0;

}
void move_pawn(Player* player, int which_pawn, int x) {
	if (goingToFinal(player, which_pawn, x) || isInFinal(player, which_pawn, x)) 
	{
		if (goingToFinal(player, which_pawn, x)) // going to final
		{
			if (fields[(player->pawns[which_pawn])->position] = 'O')
				fields[(player->pawns[which_pawn])->position] = ' ';
			else fields[(player->pawns[which_pawn])->position] = 'O';
			
			(player->pawns[which_pawn])->position = ((x - ((player->meta) - (player->pawns[which_pawn])->position)) - 1);
			player->final_fields[(player->pawns[which_pawn])->position] = 'O';
			
			((player->pawns[which_pawn])->inFinal) = 1;
			player->inFinal++;
			ending(player, which_pawn, x);

		}
		else // is in final  error isInfinal position 3 dice 1 correct should = 1(not printed)
		{
			(player->final_fields[((player->pawns[which_pawn])->position)]) = ' ';
			
			((player->pawns[which_pawn])->position) = (((player->pawns[which_pawn])->position) + x);
			player->final_fields[(player->pawns[which_pawn])->position] = 'O';
			
			ending(player, which_pawn, x);
		}
		
	}
	else {
		changePosition(player, which_pawn, x);
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
			if(player->pawns[j]->inFinal == 0)
			colorChange[j] = (player->pawns[j])->position;
			else {
				colorChangeMeta[j] = (player->pawns[j])->position;
				colorChangeMeta2[j] = player->id;
			}
		}
	}
	map();
	// change numbers to pawns //
	for (int j = 0; j <= 3; j++)
	{
		if ((player->pawns[j])->inBase == 0)
		{
			colorChange[j] = -2;
			colorChangeMeta[j] = -2;
			colorChangeMeta2[j] = -2;
		}
	}
	header(player);
	cout << "Witch pawn do you want to move?" << endl;

	// cout pawns that can move //
	int number = 4;
	bool correct[4] = { 0 };
	for (int i = 0; i <= 3; i++)
	{
		if(goingToFinal(player, i, x) || isInFinal(player, i, x) || nextNotFull(player, i, x))
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
	int printed = 0;
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
							printed++;
							break;
						case 1:
							SetConsoleTextAttribute(color, 0);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i] == 1) cout << " - " << i+1 << " or " << banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							printed++;
							break;
						case 2:
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i] == 1) cout << " - " << i+1 << " or " << banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							printed++;
							break;
						case 3:
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE);
							cout << "[  ]";
							SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
							if (havePartner[i] == 1) cout << " - " << i+1 << " or " << banedPartner[i]+1 << endl;
							else cout << " - " << i+1 << endl;
							printed++;
							break;
						}
					}
		
		}
	}
	if (printed != 0) {
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
}
void turn(Player* player)
{
	int x;
	int y;
	header(player);
	x = roll();
	cout << "Press any key to roll";
	_getch();
	map();
	if ((x != 6) && ((player->inBase == 4) || (player->inBase == 3 && player->inEnded == 1) || (player->inBase == 2 && player->inEnded == 2) || (player->inBase == 1 && player->inEnded == 3)));			  //    0 PAWNS ON BOARD	|	dice 1-5
	else if (x == 6 && player->inBase == 4)       //    0 PAWNS ON BOARD	|	dice 6
	{
		fields[player->start] = 'O';
		player->inBase = player->inBase - 1;
		(player->pawns[0])->inBase = 0;
		(player->pawns[0])->position = player->start;
		cout << "2";
		_getch();
	}
	else if ((x == 6 && player->inBase > 0 && fields[player->start] != '8'))    //    1-4 PAWNS ON BOARD	|	dice 6	|	free starting position
	{
		header(player);
		if ((player->inBase == 3 && player->inFinal == 1) || (player->inBase == 2 && player->inFinal == 2) || (player->inBase == 1 && player->inFinal == 3))
			y = 1;
		else {
			cout << "leave base (1) \nmove pawn (2)";
			cin >> y;
			cout << "3";
			_getch();
		}
		if (fields[player->start] == ' ' && y == 1)
		{
			fields[player->start] = 'O';
			player->inBase = player->inBase - 1;
			(player->pawns[3-player->inBase])->inBase = 0;
			(player->pawns[3-player->inBase])->position = player->start;
			cout << "4";
			_getch();
		}
		else if (fields[player->start] == 'O' && y == 1)
		{
			fields[player->start] = '8';
			player->inBase = player->inBase - 1;
			(player->pawns[3-player->inBase])->inBase = 0;
			(player->pawns[3-player->inBase])->position = player->start;
			cout << "5";
			_getch();
		}
		else if (y == 2)
		{
			int which_pawn = print_active(player, x);
			move_pawn(player, which_pawn, x);
			cout << "6";
			_getch();
		}

	}
	else if (player->inBase == 3)																						//    1 PAWN ON BOARD	|	dice 1-5
	{

		int which_pawn =4;
		if ((player->pawns[0])->inBase == 0)
			which_pawn = 0;
		else if ((player->pawns[1])->inBase == 0)
			which_pawn = 1;
		else if ((player->pawns[2])->inBase == 0)
			which_pawn = 2;
		else if ((player->pawns[3])->inBase == 0)
			which_pawn = 3;
		if(which_pawn !=4)
		move_pawn(player, which_pawn, x);
		cout << "7";
		_getch();
	}
	else																												//    2-4 PAWN ON BOARD		|	dice 1-5
	{
		
		int which_pawn = print_active(player, x);
		move_pawn(player, which_pawn, x);
		cout << "8";
		_getch();
	}
}
void start()
{


	map();
	cout << "Press any key to start...";
	while (!(red.pawns[0]->ended == 1 && red.pawns[1]->ended == 1 && red.pawns[2]->ended == 1 && red.pawns[3]->ended == 1)) {
		if (!(red.pawns[0]->ended == 1 && red.pawns[1]->ended == 1 && red.pawns[2]->ended == 1 && red.pawns[3]->ended == 1))
		{
			map();
			turn(&red);
		}
		if (!(blue.pawns[0]->ended == 1 && blue.pawns[1]->ended == 1 && blue.pawns[2]->ended == 1 && blue.pawns[3]->ended == 1))
		{
			map();
			turn(&blue);
		}
		if (!(green.pawns[0]->ended == 1 && green.pawns[1]->ended == 1 && green.pawns[2]->ended == 1 && green.pawns[3]->ended == 1))
		{
			//map();
			//turn(&green);
		}
		if (!(yellow.pawns[0]->ended == 1 && yellow.pawns[1]->ended == 1 && yellow.pawns[2]->ended == 1 && yellow.pawns[3]->ended == 1))
		{
			//map();
			//turn(&yellow);
		}
		//map();
		//turn(&blue);
	}
	map(); cout << "koniec";
}
