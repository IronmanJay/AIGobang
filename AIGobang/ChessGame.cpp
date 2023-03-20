#include "ChessGame.h"

ChessGame::ChessGame(Man* man, AI* ai, Chess* chess)
{

	this->man = man;
	this->ai = ai;
	this->chess = chess;

	ai->init(chess);
	man->init(chess);

}

// 对局（开始五子棋游戏）
void ChessGame::play()
{

	// 棋盘初始化
	chess->init();

	// 开始对局
	while (1)
	{
		// 首先由棋手走
		man->go();
		if (chess->checkOver())
		{
			chess->init();
			continue;
		}

		// 再由AI走
		ai->go();
		if (chess->checkOver())
		{
			chess->init();
			continue;
		}
	}

}