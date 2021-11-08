#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;

char diceTab[7] = { ' ',' ',' ',' ',' ',' ',' ' };
void dice(int x, char diceTab[7]){
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
void roll() {
	int x;
	srand(time(NULL));
	x = (std::rand() % 6) + 1;
	dice(x, diceTab);
}

void map(){
	system("cls");
system("COLOR 7B");
HANDLE color;
color = GetStdHandle(STD_OUTPUT_HANDLE);
// UPPER WING... -------------------------------------------------------------------------------------------------------------   UPPER WING...
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout <<"\t\t    .___________."<<endl << "\t\t    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|" << endl << "\t\t    |---|---|---|" << endl;
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout<<"\t\t    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|" << endl;

// UPPER RED BASE -------------------------------------------------------------------------------------------------------------   UPPER RED BASE

cout << "    ";
SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "| O | O |";

// ...UPPER WING... -------------------------------------------------------------------------------------------------------------   ...UPPER WING...

SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "  \t    |---|---|---|";

// UPPER BLUE BASE -------------------------------------------------------------------------------------------------------------   UPPER BLUE BASE

cout << "       ";
SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "| O | O |"<<endl;

// DOWNER RED BASE -------------------------------------------------------------------------------------------------------------   DOWNER RED BASE

SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "    ";
SetConsoleTextAttribute(color, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "| O | O |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

// ...UPPER WING... -------------------------------------------------------------------------------------------------------------   ...UPPER WING...

cout<<"\t    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";

// DOWNER BLUE BASE	-------------------------------------------------------------------------------------------------------------   DOWNER BLUE BASE	

cout << "       ";
SetConsoleTextAttribute(color, FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "| O | O |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

// ...UPPER WING -------------------------------------------------------------------------------------------------------------    ...UPPER WING	

cout << endl << "\t\t    |---|---|---|"<<endl << "    \t\t    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
// LEFT AND RIGHT WING... ------------------------------------------------------------------------------------------------------    LEFT AND RIGHT WING...
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|" << endl << "    ._______________|---|---|---|_______________." << endl << "    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY); 
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
// DICE -----------------------------------------------------------------------------------------------------------         DICE
cout << "\t\t";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "  "<<diceTab[1] << " " << diceTab[2] << "  ";
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
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
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
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
// DICE --------------------------------------------------------------------------------------------------------     DICE
cout << "\t\t";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "  " << diceTab[5] << " " << diceTab[6] << "  ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
// ...LEFT AND RIGHT WING ---------------------------------------------------------------------------------------------------------    ...LEFT AND RIGHT WING
cout<< endl << "    |---|---|---|---|---|---|---|---|---|---|---|" << endl << "    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout<<"|" << endl << "    ^---------------|---|---|---|---------------^" << endl << "\t\t    |";

// DOWNER WING... -----------------------------------------------------------------------------------------------------------     DOWNER WING...

SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|" << endl << "\t\t    |---|---|---|" << endl << "\t\t    |";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout<<"|";
//  UPPER YELOW BASE -------------------------------------------------------------------------------------------------------------      UPPER YELOW BASE

cout << endl<<"    ";
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
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
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
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
cout << "   ";
SetConsoleTextAttribute(color, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << "|" << endl << "\t\t    ^-----------^" << endl;
}
int main()
{
	cout << "Press any key to start...";
	while (true) {
		_getch();
		roll();
		map();
	}
}
