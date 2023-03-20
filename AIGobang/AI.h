#pragma once
#include "Chess.h"

class AI
{
public:

	// 初始化
	void init(Chess *chess);

	// AI下棋
	void go();

private:
	// 棋盘对象
	Chess* chess;
	// 评分数组
	vector<vector<int>> scoreMap;

private:
	// AI对棋局进行评分
	void calculateScore();
	// 找出价值评分最高的点落子
	ChessPos think();
};