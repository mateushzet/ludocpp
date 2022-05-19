#include "variables.h"
Variables::Variables() {

	for (int i = 0; i < 4; i++){

		colorChange[i] = -2;
		colorChangeMeta[i] = -2;
		colorChangeMeta2[i] = -2;
		colorId[i] = i;
		meta_red[i] = ' ';
		meta_blue[i] = ' ';
		meta_green[i] = ' ';
		meta_yellow[i] = ' ';
	}

	for (int i = 0; i < 40; i++){

		playersOnTabs[i] = 9;
		pawnsOnTabs[i] = 9;
		fields[i] = ' ';
	}

	nameTab[0] = "YELLOW";
	nameTab[1] = "RED";
	nameTab[2] = "BLUE";
	nameTab[3] = "GREEN";
	fields[40] = ' ';
	podium[0] = "0";
	podium[1] = "0";
	podium[2] = "0";
}