#ifndef players_h
#define players_h
class Pawn
{
public:
	int position;
	bool inBase;
	bool inFinal;
	bool ended;
	Pawn();
};

class Player
{
public:
	int id;
	int inBase;
	int inEnded;
	int inFinal;
	int meta;
	int start;
	char final_fields[5];
	Pawn* pawns[4];
	Player(int m, int s, int id);
	~Player();
};
#endif