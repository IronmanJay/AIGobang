#pragma once
#include "Chess.h"

class Man
{

public:

	// 初始化
	void init(Chess *chess);

	// 下棋动作
	void go();
private:
	Chess* chess;
};