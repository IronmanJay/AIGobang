#pragma once
#include "Chess.h"

class Man
{

public:

	// ��ʼ��
	void init(Chess *chess);

	// ���嶯��
	void go();
private:
	Chess* chess;
};