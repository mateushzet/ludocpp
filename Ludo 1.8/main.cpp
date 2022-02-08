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

void menu(HANDLE color, int position, int playersNum)
{
    system("cls");
    SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    SetConsoleTextAttribute(color, FOREGROUND_RED | 0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << "\t\t\tL";
    SetConsoleTextAttribute(color, FOREGROUND_GREEN | 0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << "U";
    SetConsoleTextAttribute(color, FOREGROUND_BLUE | 0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << "D";
    SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | 0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << "O";
    SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << " in C++ \n\t\t     ~Mateusz Ziecina\n\n";
    if (position == 0)SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | 0);
    cout << "\t\t\t  START\n";
    SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    if (position == 1)SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | 0);
    cout << "\t\t    Players number: " << playersNum << endl << endl << endl;
    SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << "\t\t navigate WASD or arrows, spacebar or enter";
}

int main()
{
    int playersNum = 2;
    int position = 0;
	system("cls");
	system("COLOR 7B");
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
    menu(color, position, playersNum);
    cout << _getch();
    int Klawisz;
    for (; ; )
    {
        Klawisz = _getch();

        switch (Klawisz)
        {
        case 72:
            if (position == 0)position = 1; else position = 0;
            menu(color, position, playersNum);
            break;

        case 80:
            if (position == 0)position = 1; else position = 0;
            menu(color, position, playersNum);
            break;

        case 119:
            if (position == 0)position = 1; else position = 0;
            menu(color, position, playersNum);
            break;

        case 115:
            if (position == 0)position = 1; else position = 0;
            menu(color, position, playersNum);
            break;
        case 75:
            if (playersNum > 2 && position == 1)playersNum--;
            menu(color, position, playersNum);
            break;

        case 77:
            if (playersNum < 4 && position == 1)playersNum++;
            menu(color, position, playersNum);
            break;
        case 97:
            if (playersNum > 2 && position == 1)playersNum--;
            menu(color, position, playersNum);
            break;

        case 100:
            if (playersNum < 4 && position == 1)playersNum++;
            menu(color, position, playersNum);
            break;
        case 13:
            if (position == 0)
                start(playersNum);
            menu(color, position, playersNum);
            break;
        case 32:
            if (position == 0)
                start(playersNum);
            menu(color, position, playersNum);
            break;
        }
    }
	//start();
}