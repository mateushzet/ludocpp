#include "players.h"
Player::Player(int m) {
	pawns[0] = new Pawn;
	pawns[1] = new Pawn;
	pawns[2] = new Pawn;
	pawns[3] = new Pawn;
	inBase = 4;
	meta = m;
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
}