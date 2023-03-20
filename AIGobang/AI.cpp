#include "AI.h"

// AI初始化
void AI::init(Chess * chess)
{
	this->chess = chess;
	int size = chess->getGradeSize();
	for (int i = 0; i < size; i++)
	{
		vector<int> row;
		for (int j = 0; j < size; j++)
		{
			row.push_back(0);
		}
		scoreMap.push_back(row);
	}
}

// AI下棋
void AI::go()
{
	// AI计算后的落子点
	ChessPos pos = think();
	// AI假装思考，给棋手缓冲时间
	Sleep(1000);
	// 在AI计算后的落子点落子
	chess->chessDown(&pos, CHESS_WHITE);
}

// AI对棋局进行评分计算
void AI::calculateScore()
{
	// 棋手方（黑棋）有多少个连续的棋子
	int personNum = 0;
	// AI方（白棋）有多少个连续的棋子
	int aiNum = 0;
	// 该方向上空白位的个数
	int emptyNum = 0;
	// 将评分向量数组清零
	for (int i = 0; i < scoreMap.size(); i++)	
	{
		for (int j = 0; j < scoreMap[i].size(); j++)
		{
			scoreMap[i][j] = 0;
		}
	}
	// 获取棋盘大小
	int size = chess->getGradeSize();
	// 对可能的落子点的八个方向进行价值评分计算
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			// 只有当前位置没有棋子才是可能的落子点
			if (chess->getChessData(row, col) == 0)
			{
				// 控制八个方向
				for (int y = -1; y <= 0; y++)
				{
					for (int x = -1; x <= 1; x++)
					{
						// 重置棋手方（黑棋）有多少个连续的棋子
						personNum = 0;
						// 重置AI方（白棋）有多少个连续的棋子
						aiNum = 0;
						// 重置该方向上空白位的个数
						emptyNum = 0;
						// 消除重复计算
						if (y == 0 && x != 1)
						{
							continue;
						}
						// 原坐标不计算在内
						if (!(y == 0 && x == 0))
						{
							// 假设黑棋在该位置落子，会构成什么棋形？此时是黑棋的正向计算
							for (int i = 1; i <= 4; i++)
							{
								int curRow = row + i * y;
								int curCol = col + i * x;
								if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == 1)
								{
									personNum++;
								}
								else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
							// 黑棋的反向计算
							for (int i = 1; i <= 4; i++)
							{
								int curRow = row - i * y;
								int curCol = col - i * x;
								if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == 1)
								{
									personNum++;
								}
								else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
							// 连二
							if (personNum == 1)
							{
								scoreMap[row][col] += 10;
							}
							// 连三
							else if (personNum == 3)
							{
								// 死三
								if (emptyNum == 1)
								{
									scoreMap[row][col] += 30;
								}
								// 活三
								else if (emptyNum == 2)
								{
									scoreMap[row][col] += 40;
								}
							}
							// 连四
							else if (personNum == 3)
							{
								// 死四
								if (emptyNum == 1)
								{
									scoreMap[row][col] += 60;
								}
								// 活四
								else if (emptyNum == 2)
								{
									scoreMap[row][col] += 200;
								}
							}
							// 连五
							else if (personNum == 4)
							{
								scoreMap[row][col] += 20000;
							}
							// 清空空白棋子个数
							emptyNum = 0;
							// 假设白棋在该位置落子，会构成什么棋形？此时是白棋的正向计算
							for (int i = 1; i <= 4; i++)
							{
								int curRow = row + i * y;
								int curCol = col + i * x;
								if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == -1)
								{
									aiNum++;
								}
								else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
							// 白棋的反向计算
							for (int i = 1; i <= 4; i++)
							{
								int curRow = row - i * y;
								int curCol = col - i * x;
								if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == -1)
								{
									aiNum++;
								}
								else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chess->getChessData(curRow, curCol) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
							// 白色棋子无处可下
							if (aiNum == 0)
							{
								scoreMap[row][col] += 5;
							}
							// 连二
							else if (aiNum == 1)
							{
								scoreMap[row][col] += 10;
							}
							// 连三
							else if (aiNum == 3)
							{
								// 死三
								if (emptyNum == 1)
								{
									scoreMap[row][col] += 25;
								}
								// 活三
								else if (emptyNum == 2)
								{
									scoreMap[row][col] += 50;
								}
							}
							// 连四
							else if (aiNum == 3)
							{
								// 死四
								if (emptyNum == 1)
								{
									scoreMap[row][col] += 55;
								}
								// 活四
								else if (emptyNum == 2)
								{
									scoreMap[row][col] += 10000;
								}
							}
							// 连五
							else if (aiNum >= 4)
							{
								scoreMap[row][col] += 30000;
							}
						}
					}
				}
			}
		}
	}
}

// 找出价值评分最高的点落子
ChessPos AI::think()
{
	// 计算各个方向的价值评分
	calculateScore();
	// 获取棋盘大小
	int size = chess->getGradeSize();
	// 存储多个价值最大值的点
	vector<ChessPos> maxPoints;
	// 初始价值最大值
	int maxScore = 0;
	// 遍历搜索价值评分最大的点
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (chess->getChessData(row, col) == 0)
			{
				if (scoreMap[row][col] > maxScore)
				{
					maxScore = scoreMap[row][col];
					maxPoints.clear();
					maxPoints.push_back(ChessPos(row, col));
				}
				else if (scoreMap[row][col] == maxScore)
				{
					maxPoints.push_back(ChessPos(row, col));
				}
			}
		}
	}
	// 如果有多个价值最大值点，随机获取一个价值最大值点的下标
	int index = rand() % maxPoints.size();
	// 返回价值最大值点
	return maxPoints[index];
}