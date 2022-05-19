#include <string>
#ifndef variables_h
#define variables_h
#pragma once
using std::string;
class Variables {
	public:
		Variables();
		int colorChange[4];
		int colorChangeMeta[4];
		int colorChangeMeta2[4];
		int colorId[4];
		string nameTab[4];
		int playersOnTabs[40];
		int pawnsOnTabs[40];
		int playerTurn;
		char fields[41];
		char meta_red[4];
		char meta_blue[4];
		char meta_yellow[4];
		char meta_green[4];
		string podium[3];
};
#endif