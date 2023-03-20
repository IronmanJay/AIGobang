#pragma once
// EasyXͼ�ο��ͷ�ļ�
#include <graphics.h>
#include <vector>
using namespace std;

// ��ʾ����λ��
struct ChessPos
{
	int row;
	int col;
	ChessPos(int r = 0, int c = 0) :row(r), col(c) {};
};

// ��ʾ���ӵ�����
typedef enum
{
	CHESS_WHITE = -1, // ����
	CHESS_BLACK = 1 // ����
}chess_kind;

class Chess
{
public:

	// ��������
	Chess(int gradeSize, int maiginX, int marginY, float chessSize);

	// ���̳�ʼ�����������̵�ͼƬ��Դ����ʼ�����̵��������
	void init();

	/*
		�ж���ָ������(x,y)λ�ã��Ƿ�����Ч�����
		�������Ч���������Ч�����λ��(�У��У������ڲ���pos��
	*/
	bool clickBoard(int x, int y, ChessPos *pos);

	// �����̵�ָ��λ�ã�pos��, ���ӣ�chess��
	void chessDown(ChessPos *pos, chess_kind chess);

	// ��ȡ���̵Ĵ�С��13�ߡ�15�ߡ�19�ߣ�
	int getGradeSize();

	// ��ȡָ��λ���Ǻ��壬���ǰ��壬���ǿհ�
	int getChessData(ChessPos *pos);
	int getChessData(int row, int col);

	// �������Ƿ����
	bool checkOver();

private:
	IMAGE chessBlackImg; // ��������
	IMAGE chessWhiteImg; // ��������
	int gradeSize; // ���̵Ĵ�С��13�ߡ�15�ߡ�17�ߡ�19�ߣ�
	int margin_x; // ���̵����߽�
	int margin_y; // ���̵Ķ����߽�
	float chessSize; // ���ӵĴ�С�����̵�С����Ĵ�С��
	/*
		�洢��ǰ��ֵ����ӷֲ�����
		���磺chessMap[3][5]��ʾ���̵ĵ�3�е�5�е����������0���հף�1�����ӣ�-1�����ӣ�
	*/
	vector<vector<int>> chessMap;
	/*
		��ʾ���ڸ�˭���壨���ӣ�
		true���ú����ߣ�false���ð�����
	*/
	bool playerFlag;

	// ��������Ϣ�洢����ά������
	void updateGameMap(ChessPos* pos);

	// ��鵱ǰ˭��˭�䣬���ʤ���ѷ־ͷ���true�����򷵻�false
	bool checkWin();

	// ĳһ���ӵ��λ��
	ChessPos lastPos;

};