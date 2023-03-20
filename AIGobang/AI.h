#pragma once
#include "Chess.h"

class AI
{
public:

	// ��ʼ��
	void init(Chess *chess);

	// AI����
	void go();

private:
	// ���̶���
	Chess* chess;
	// ��������
	vector<vector<int>> scoreMap;

private:
	// AI����ֽ�������
	void calculateScore();
	// �ҳ���ֵ������ߵĵ�����
	ChessPos think();
};