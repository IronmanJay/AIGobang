#include <iostream>
#include "ChessGame.h"

int main(void)
{
	Man man;
	// Chess chess;
	Chess chess(13, 44, 43, 67.3);
	AI ai;
	ChessGame game(&man, &ai, &chess);

	game.play();

	return 0;

}