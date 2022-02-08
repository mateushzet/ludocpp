#include "players.h"
Player::Player(int m, int s, int id) {
	pawns[0] = new Pawn;
	pawns[1] = new Pawn;
	pawns[2] = new Pawn;
	pawns[3] = new Pawn;
	inBase = 4;
	meta = m;
	start = s;
	final_fields[0] = ' ';
	final_fields[1] = ' ';
	final_fields[2] = ' ';
	final_fields[3] = ' ';
	final_fields[4] = 'O';
	final_fields[5] = 'O';
	final_fields[6] = 'O';
	final_fields[7] = 'O';
	final_fields[8] = 'O';
	final_fields[9] = 'O';
	this->id = id;
	ended = 0;
	inFinal = 0;
}
Player::~Player()
{
	//delete pawns[0];
	//delete pawns[1];
	//delete pawns[2];
	//delete pawns[3];
}
Pawn::Pawn() {
	position = -1;
	inBase = true;
	inFinal = false;
	ended = 0;
}