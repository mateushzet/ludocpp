#ifndef players_h
#define players_h
class Pawn
{
public:
	int position;
	bool inBase;
	Pawn();
};

class Player
{
public:
	int inBase;
	int meta;
	Pawn* pawns[4];
	Player(int m);
	~Player();
};
#endif