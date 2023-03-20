#pragma once
#include "Man.h"
#include "AI.h"
#include "Chess.h"

class ChessGame
{

public:

	ChessGame(Man*, AI*, Chess*);

	// 开始对局
	void play();

// 添加数据成员
private:
	Man* man;
	AI* ai;
	Chess* chess;
};