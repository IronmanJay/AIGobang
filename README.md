#  项目资源下载
1. [基于C++的AI五子棋游戏项目源码压缩包下载地址](https://download.csdn.net/download/IronmanJay/87597170)
2. [基于C++的AI五子棋游戏项目源码Github下载地址](https://github.com/IronmanJay/AIGobang)
3. [基于C++的AI五子棋游戏项目所需素材](https://download.csdn.net/download/IronmanJay/87597137)
4. [基于C++的AI五子棋游戏项目所需要的EasyX](https://download.csdn.net/download/IronmanJay/87597153)
<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 项目简介
&nbsp;&nbsp;本项目基于C++开发，整体来说比较简单，实现了人与AI之间的五子棋对弈，并且可以判定胜负以及音效添加等等，按照我博客的详细教程一步一步做下去肯定没问题！
<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 项目开发软件环境
- Windows11
- VS2017
- EasyX
<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 项目开发硬件环境
- CPU：Intel® Core™ i7-8750H CPU @ 2.20GHz 2.20 GHz
- RAM：24GB
- GPU：NVIDIA GeForce GTX 1060
<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 前言
&nbsp;&nbsp;以下就是基于C++的AI五子棋游戏项目的详细开发教程，我对于每一步都进行了详细的注释以及图解，相信读者只要按照我的步骤一步一步做下去肯定也能实现自己的AI五子棋，当然，读者也可以根据自己的喜好调整游戏项目素材，以便达到最佳效果。下面就是本文的全部内容了！

<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 一、创建项目

1. 打开Microsoft Visual Studio（以下简称VS）后，点击“新建”->“项目”
									 
![请添加图片描述](https://img-blog.csdnimg.cn/1ddf99b12d894c85b77e0d9bbd823cf7.png#pic_center)

2. 然后输入项目名称与项目位置，然后点击“确定”
									 
![请添加图片描述](https://img-blog.csdnimg.cn/08ec3693220a490e9b0a9add53493a11.png#pic_center)

# 二、导入素材

1. 在项目内新建“resource”文件夹，准备存放项目的素材文件
									 
![请添加图片描述](https://img-blog.csdnimg.cn/e0e40fb0ecdb4267b23c5a337554af9b.png#pic_center)

2. 将项目所用素材导入项目中的“resource”文件夹中，读者可以用自己的素材，也可以用我的素材，我的素材的下载链接已经放在上面的博客中了
									 
![请添加图片描述](https://img-blog.csdnimg.cn/b2b9192796994b70a0dc311f928d3ec0.png#pic_center)

# 三、项目框架设计

## 3.1 设计项目框架

1. 整个项目的框架如下图所示，所有的代码都是根据以下四个类进行编写的：
									 
![请添加图片描述](https://img-blog.csdnimg.cn/80cc2a128fad48ff8d82684083dd4cdd.png#pic_center)
   - Man（棋手）：下棋的人
   - Chess（棋盘）：下棋的地方
   - AI（人工智能）：和棋手对弈的AI
   - ChessGame（游戏控制）：控制游戏的基本逻辑

## 3.2 根据项目框架设计类

1. 根据刚才设计好的项目框架，我们就要将其一一建立起来。首先创建Man（棋手）类，在“源文件”上右键，点击“添加”中的“类”：
									 
![请添加图片描述](https://img-blog.csdnimg.cn/c2d3efac481d440e925c223a50d8689b.png#pic_center)

2. 在“类名”中输入“Man”，点击“确定”就可以了，其余的文件自动生成
									 
![请添加图片描述](https://img-blog.csdnimg.cn/9afdf448fe47427fb3153816b78e62d4.png#pic_center)

3. 可以发现，已经成功生成了
									 
![请添加图片描述](https://img-blog.csdnimg.cn/cc2379b15dde4a329b75e8390c05fc6c.png#pic_center)

4. 按照创建Man（棋手）类同样的方法，创建其他三个类，最终效果如下图所示：
									 
![请添加图片描述](https://img-blog.csdnimg.cn/789c8c87f9184c2e96bc3db245102543.png#pic_center)

# 四、设计游戏主要接口

## 4.1 设计Chess（棋盘）类主要接口

1. 我们在Chess.h中设计Chess（棋盘）类的主要接口，这些主要接口不需要具体实现，只是暴露给外部的接口，等待外部使用的时候在进行个性化的实现即可。Chess.h中的代码如下：
   ```cpp
   #pragma once
   
   // 表示落子位置
   struct ChessPos
   {
   	int row;
   	int col;
   };
   
   // 表示棋子的种类
   typedef enum
   {
   	CHESS_WHITE = -1, // 白棋
   	CHESS_BLACK = 1 // 黑棋
   }chess_kind;
   
   class Chess
   {
   public:
   
   	// 棋盘初始化：加载棋盘的图片资源，初始化棋盘的相关数据
   	void init();
   
   	/*
   		判断在指定坐标(x,y)位置，是否是有效点击，
   		如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
   	*/
   	bool clickBoard(int x, int y, ChessPos *pos);
   
   	// 在棋盘的指定位置（pos）, 落子（chess）
   	void chessDown(ChessPos *pos, chess_kind chess);
   
   	// 获取棋盘的大小（13线、15线、19线）
   	int getGradeSize();
   
   	// 获取指定位置是黑棋，还是白棋，还是空白
   	int getChessData(ChessPos *pos);
   int getChessData(int row, int col);
   
   	// 检查棋局是否结束
   	bool checkOver();
   
   };
   ```

## 4.2 设计AI（人工智能）类主要接口

1. 同理，AI.h中的代码如下：

   ```cpp
   #pragma once
   #include "Chess.h"
   
   class AI
   {
   public:
   
   	// 初始化
   	void init(Chess *chess);
   
   	// AI下棋
   	void go();
   
   };
   ```

## 4.3 设计Man（棋手）类主要接口

1. 同理，Man.h中的代码如下：

   ```cpp
   #pragma once
   #include "Chess.h"
   
   class Man
   {
   
   public:
   
   	// 初始化
   	void init(Chess *chess);
   
   	// 下棋动作
   	void go();
   
   };
   ```

## 4.4 设计ChessGame（游戏控制）类主要接口

1. 同理，ChessGame.h中的代码如下：

   ```cpp
   #pragma once
   
   class ChessGame
   {
   
   public:
   
   	// 开始对局
   	void play();
   
   };
   ```

## 4.5 设计各个接口的具体实现

1. 我们现在已经把我们项目的基本主要接口生成了，但是我们还需要将这些接口实现一下，以助于后面项目开发的使用。此时我们可以看到，刚刚创建好的接口函数下面有一个绿色的波浪线：
		     
![请添加图片描述](https://img-blog.csdnimg.cn/cb79e53702c0430a83533e238b36a204.png#pic_center)

2. 这个绿色的波浪线就是VS在提示我们还没有生成该接口的具体实现，所以我们需要实现这个接口。我们只需要将鼠标放在绿色波浪线上，然后点击“显示可能的修补程序”：
		     
![请添加图片描述](https://img-blog.csdnimg.cn/949cdb580a3f41a7bdb23dceac46fc2a.png#pic_center)

3. 然后选择我红框标注的选项即可：
		     
![请添加图片描述](https://img-blog.csdnimg.cn/cb8db00327bf44c3b8a186678bcb8e56.png#pic_center)

4. 此时VS就帮我们自动地完成了接口的具体实现，当然，里面的具体内容需要根据不同项目需求自己填写。此时接口函数下面的绿色波浪线已经不存在了，那么我们只需要按“Ctrl+s”保存，然后关闭即可，此时VS就已经帮我们完成了：
		     
![请添加图片描述](https://img-blog.csdnimg.cn/ecda93aa2240439197eb11e51c4c3c66.png#pic_center)

5. 其余的所有接口函数都按照上面的步骤完成接口的具体实现，不再一一赘述。具体的接口函数实现后的项目结构如下图所示：
		     
![请添加图片描述](https://img-blog.csdnimg.cn/f4c33dcc69c84376864d45ee79c936fa.png#pic_center)

# 五、设计游戏基本框架

1. 此时我们已经创建好了整个游戏的基本接口并进行了初步的实现，但是游戏的框架我们目前还没有创建，所以下面的工作应该创建游戏的基本框架。因为游戏要由ChessGame类控制，所以应该由ChessGame类调用各个类的功能，所以首先在ChessGame.h加入如下代码，此时就完成了整个游戏的基本内容创建：

   ```c
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
   ```

2. 当游戏的基本内容创建好后，我们就要完成游戏的基本逻辑了，当然，此时只是简单的面向对象的逻辑实现，并不涉及具体的开发，具体的开发要到后面才具体实现。我们此时只需要在ChessGame.cpp中加入如下代码即可：

   ```c
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
   ```

3. 此时就完成了整个游戏的基本框架，下面我们就要往这个框架中添加具体内容了。当然，在这之前我们还需要使用一个主函数将刚刚创建的框架串联起来。首先创建main.cpp，这里面就是游戏的整体逻辑，具体内容后面再写，在“源文件”上右键，选择“添加”->“新建项”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/b9e1ff693a0147eb8a091701eb2e8fab.png#pic_center)

4. 选择C++文件(.cpp)后输入名字，最后点击“添加”即可：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/ee5cacea932343be89bdfc95efcd6fee.png#pic_center)

5. 在main.cpp中加入如下代码：

   ```cpp
   #include <iostream>
   #include "ChessGame.h"
   
   int main(void)
   {
   	Man man;
   	Chess chess;
   	AI ai;
   	ChessGame game(&man, &ai, &chess);
   
   	game.play();
   
   	return 0;
   
   }
   ```

6. 此时我们可以运行测试一下，点击“调试”中的“开始执行(不调试)(H)”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/4a0ddb3a1c43466a892f106da918da9c.png#pic_center)

7. 可以发现到目前为止，我们的程序没有问题：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/c941d9651d4b49ad86fae0623afdf777.png#pic_center)

# 六、棋盘初始化

## 6.1 EasyX的使用

1. 因为游戏要进行绘图，所以我们使用EasyX来完成游戏的绘图接口，可以帮助我们编写图形程序，EasyX的下载链接也在博客的上方。下载后双击打开：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/100973f59c5549a684aaf0f281e81ae9.png#pic_center)

2. 点击“下一步”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/9a0e12bc793d4468bf88d6b1d677fe7f.png#pic_center)

3. 然后选择你对应版本的编译器进行“安装”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/aa4d270645444d70913a852e2e392fe1.png#pic_center)

4. 然后会提示你安装成功：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/a1dc4a68f8254e5c815fc68079f788f7.png#pic_center)

## 6.2 设计棋盘的数据成员

1. 当我们安装好EasyX图形库后，就要在Chess.h中引入一些我们所需要的头文件了：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/f0a69f49631b48ed8563347d5c29d5b5.png#pic_center)

2. 然后需要添加一些棋盘初始化所需要的数据，我们只需要在Chess.h中加入如下代码：

   ```cpp
   private:
   	IMAGE chessBlackImg; // 黑棋棋子
   	IMAGE chessWhiteImg; // 白棋棋子
   	int gradeSize; // 棋盘的大小（13线、15线、17线、19线）
   	int margin_x; // 棋盘的左侧边界
   	int margin_y; // 棋盘的顶部边界
   	float chessSize; // 棋子的大小（棋盘的小方格的大小）
   	/*
   		存储当前棋局的棋子分布数据
   		例如：chessMap[3][5]表示棋盘的第3行第5列的落子情况（0：空白；1：黑子；-1：白子）
   	*/
   	vector<vector<int>> chessMap;
   	/*
   		表示现在该谁下棋（落子）
   		true：该黑子走；false：该白子走
   	*/
   	bool playerFlag;
   ```

## 6.3 构造棋盘

1. 我们需要利用刚才创建的棋盘类的数据进行棋盘的创建，首先就需要写一个函数来创建棋盘，所以我们在Chess.h中加入如下代码：

   ```cpp
   Chess(int gradeSize, int maiginX, int marginY, float chessSize);
   ```

2. 然后鼠标放在刚刚创建的函数上，点击“显示可能的修补程序”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/2c4b2ebb9811418f931786af31d0c2ef.png#pic_center)

3. 然后选择红框中的内容：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/9862810979314311a460a1ff7c4b2ffc.png#pic_center)

4. 然后按“Ctrl+S”保存：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/2ae48447a8284c938ab5fc2e9326c58f.png#pic_center)

5. 下面就要利用刚才创建的数据构造棋盘了，只需要在Chess.cpp中加入如下代码：

   ```cpp
   // 构造棋盘
   Chess::Chess(int gradeSize, int marginX, int marginY, float chessSize)
   {
   	this->gradeSize = gradeSize;
   	this->margin_x = marginX;
   	this->margin_y = marginY;
   	this->chessSize = chessSize;
   	playerFlag = CHESS_BLACK;
   	for (int i = 0; i < gradeSize; i++)
   	{
   		vector<int> row;
   		for (int j = 0; j < gradeSize; j++)
   		{
   			row.push_back(0);
   		}
   		chessMap.push_back(row);
   	}
   }
   ```

6. 然后来到main.cpp中，使用我们刚刚创建的构造函数，传入参数就构造好棋盘了：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/4f32c6d047724490a1cd0642ee47d75a.png#pic_center)

7. 然后我们还是来测试一下，点击“调试”中的“开始执行(不调试)(H)”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/73be54e106a54aee8fbdf55a9bd58de4.png#pic_center)

8. 可以发现，到目前为止，我们的程序没有任何问题：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/75f7e1a5e3d64b99824376316a3d93f9.png#pic_center)

## 6.4 棋盘初始化

1. 在项目上右键后，点击“属性”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/c8646c5d46624d5f9ffafb561e2a371a.png#pic_center)

2. 在“常规”的“字符集”中，选择“使用多字节字符集”：
			 
![请添加图片描述](https://img-blog.csdnimg.cn/eca22960712b49dcabc477ac8b30e03a.png#pic_center)

3. 在Chess.cpp中加入如下头文件和相关库，目的是可以播放音乐：

   ```cpp
   #include <mmsystem.h>
   #pragma comment(lib,"winmm.lib")
   ```

4. 在Chess.cpp中加入如下代码，目的是看到实际的棋盘并播放音乐：

   ```cpp
   // 棋盘初始化
   void Chess::init()
   {
   	// 创建游戏窗口
   	initgraph(897, 895);
   	// 显示棋盘图片
   	loadimage(0, "resource/棋盘2.jpg");
   	// 播放开始提示音
   	mciSendString("play resource/start.wav", 0, 0, 0);
   	// 加载黑棋和白棋棋子的图片
   	loadimage(&chessBlackImg, "resource/black.png", chessSize, chessSize, true);
   	loadimage(&chessWhiteImg, "resource/white.png", chessSize, chessSize, true);
   	// 棋盘清零
   	for (int i = 0; i < gradeSize; i++)
   	{
   		for (int j = 0; j < gradeSize; j++)
   		{
   			chessMap[i][j] = 0;
   		}
   	}
   	// 确定谁先下棋
   	playerFlag = true;
   }
   ```

5. 然后我们测试一下：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/cd65f9a50ef4481db3f3743fb805050c.png#pic_center)

6. 发现已经成功显示棋盘，并成功播放音乐了：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/ab12341368fa413d8cb30a81db28b89a.png#pic_center)

# 七、棋手下棋实现

## 7.1 棋手初始化

1. 给棋手类添加棋盘数据成员，在Man.h中加入如下代码：

   ```cpp
   private:
   	Chess* chess;
   ```

## 7.2 棋手下棋功能初始化

1. 在棋手类初始化时，传入棋盘类指针，只需要将Man.cpp中的init函数替换为如下代码：

   ```cpp
   // 棋手初始化
   void Man::init(Chess * chess)
   {
   	this->chess = chess;
   }
   ```

2. 为了实现棋手下棋功能，将Man.cpp中的go函数替换为如下代码：

   ```cpp
   // 棋手下棋
   void Man::go()
   {
   	// 鼠标函数
   	MOUSEMSG msg;
   	// 落子位置
   	ChessPos pos;
   	while (1)
   	{
   		// 获取鼠标点击消息
   		msg = GetMouseMsg();
   		// 通过chess对象，来判断落子位置是否有效
   		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos))
   		{
   			break;
   		}
   	}
   	// 落子
   	chess->chessDown(&pos, CHESS_BLACK);
   }
   ```

## 7.3 判断棋手下棋位置是否有效

1. 下棋最重要的一点就是让计算机知道棋下在了哪里，如何解决这个问题呢？我们可以看下面的图示：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/4643fb233a46415a8b74318878031cbf.png#pic_center)

2. 棋子肯定要落在两条线的交界处，一共四个点，所以我们首先要计算落子位置距离四个点的距离。这里我们需要设置一个“阈值”，如果落子位置距离某个点的距离小于此“阈值”，就认为这个点就是真正的落子位置，否则就不落子，这个“阈值”的大小要小于棋子大小的一半，还要注意棋盘在计算机中存储的二维数组下标从0开始。此时我们只需要将如下代码加入Chess.cpp中：

   ```cpp
   #include <math.h>
   
   // 判断落子是否有效
   bool Chess::clickBoard(int x, int y, ChessPos * pos)
   {
   	// 真实的落子列坐标
   	int col = (x - margin_x) / chessSize;
   	// 真实的落子行坐标
   	int row = (y - margin_y) / chessSize;
   	// 落子的左上角列坐标
   	int leftTopPosX = margin_x + chessSize * col;
   	// 落子的左上角行坐标
   	int leftTopPosY = margin_y + chessSize * row;
   	// 鼠标点击位置距离真实落子位置的阈值
   	int offset = chessSize * 0.4;
   	// 落子距离四个角的距离
   	int len;
   	// 落子是否有效
   	bool res = false;
   	do
   	{
   		// 落子距离左上角的距离
   		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
   		// 如果落子距离左上角的距离小于阈值并且当前位置没有棋子，就保存当前落子位置，并设置落子有效
   		if (len < offset)
   		{
   			pos->row = row;
   			pos->col = col;
   			if (chessMap[pos->row][pos->col] == 0)
   			{
   				res = true;
   			}
   			break;
   		}
   		// 落子距离右上角的距离
   		int x2 = leftTopPosX + chessSize;
   		int y2 = leftTopPosY;
   		len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
   		// 如果落子距离右上角的距离小于阈值并且当前位置没有棋子，就保存当前落子位置，并设置落子有效
   		if (len < offset)
   		{
   			pos->row = row;
   			pos->col = col + 1;
   			if (chessMap[pos->row][pos->col] == 0)
   			{
   				res = true;
   			}
   			break;
   		}
   		// 落子距离左下角的距离
   		x2 = leftTopPosX;
   		y2 = leftTopPosY + chessSize;
   		len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
   		// 如果落子距离右上角的距离小于阈值并且当前位置没有棋子，就保存当前落子位置，并设置落子有效
   		if (len < offset)
   		{
   			pos->row = row + 1;
   			pos->col = col;
   			if (chessMap[pos->row][pos->col] == 0)
   			{
   				res = true;
   			}
   			break;
   		}
   		// 落子距离右下角的距离
   		x2 = leftTopPosX + chessSize;
   		y2 = leftTopPosY + chessSize;
   		len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
   		// 如果落子距离右上角的距离小于阈值并且当前位置没有棋子，就保存当前落子位置，并设置落子有效
   		if (len < offset)
   		{
   			pos->row = row + 1;
   			pos->col = col + 1;
   			if (chessMap[pos->row][pos->col] == 0)
   			{
   				res = true;
   			}
   			break;
   		}
   	} while (0);
   	// 返回落子是否有效的判断结果
   	return res;
   }
   ```

3. 此时就可以判断落子的位置是否有效了，为了验证我们的代码没有问题，我们需要验证一下，我们在Chess.cpp中加入如下代码，测试成功后可以删除加入的代码：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/db66c107f0fd452c8d914f99f2295200.png#pic_center)

4. 在Man.cpp中加入如下代码，打印落子位置，同样，测试成功之后也可以删除加入的代码：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/d1fb5c511b4842c38c4b2f1b7bcc008a.png#pic_center)

5. 此时我们就可以来到main.cpp中进行测试了：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/6b38ebc28d3d4d1e879cc993748f0eaf.png#pic_center)

6. 可以发现正确获取落子位置了，这说明我们的代码没有任何问题。测试成功之后，要把上面加的两处代码删掉：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/7b546a6c40744a11b7e8e51ab970df7e.png#pic_center)

## 7.4 实现棋手下棋

1. 为了实现棋盘落子，首先在Chess.cpp中加入如下代码，需要注意绘图的左边是左上角，所以为了让棋子的中心点在行线和列线的交界处，棋子的行和列坐标都需要减0.5倍的棋格大小，这一点需要格外关注：

   ```cpp
   // 棋盘落子
   void Chess::chessDown(ChessPos * pos, chess_kind chess)
   {
   	// 加载落子音效
   	mciSendString("play resource/down7.wav", 0, 0, 0);
   	// 获取棋子的落子位置，需要注意绘图的左边是左上角，所以为了让棋子的中心点在行线和列线的交界处，棋子的行和列坐标都需要减0.5倍的棋格大小
   	int x = margin_x + chessSize * pos->col - 0.5 * chessSize;
   	int y = margin_y + chessSize * pos->row - 0.5 * chessSize;
   	// 根据棋子类型在对应位置生成棋子图片
   	if (chess == CHESS_WHITE)
   	{
   		putimage(x, y, &chessWhiteImg);
   	}
   	else
   	{
   		putimage(x, y, &chessBlackImg);
   	}
   }
   ```

2. 然后我们来测试一下，发现可以成功落子，而且音效也没问题，但是每个棋子周围都有黑边，这些黑边肯定是不应该存在的：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/5f9314ca06d24fd1abd841632a51ee68.png#pic_center)

3. 落子后的棋子出现黑边是因为Easyx不支持png格式图片，为了解决这个问题，我们只需要在Chess.cpp中加入如下函数：

   ```cpp
   // 解决Easyx不支持png格式图片的函数
   void putimagePNG(int x, int y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
   {
   	// 变量初始化
   	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
   	DWORD* draw = GetImageBuffer();
   	DWORD* src = GetImageBuffer(picture); // 获取picture的显存指针
   	int picture_width = picture->getwidth(); // 获取picture的宽度，EASYX自带
   	int picture_height = picture->getheight(); // 获取picture的高度，EASYX自带
   	int graphWidth = getwidth();       // 获取绘图区的宽度，EASYX自带
   	int graphHeight = getheight();     // 获取绘图区的高度，EASYX自带
   	int dstX = 0;    // 在显存里像素的角标
   
   	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
   	for (int iy = 0; iy < picture_height; iy++)
   	{
   		for (int ix = 0; ix < picture_width; ix++)
   		{
   			int srcX = ix + iy * picture_width; // 在显存里像素的角标
   			int sa = ((src[srcX] & 0xff000000) >> 24); // 0xAArrggbb;AA是透明度
   			int sr = ((src[srcX] & 0xff0000) >> 16); // 获取RGB里的R
   			int sg = ((src[srcX] & 0xff00) >> 8);   // G
   			int sb = src[srcX] & 0xff;              // B
   			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
   			{
   				dstX = (ix + x) + (iy + y) * graphWidth; // 在显存里像素的角标
   				int dr = ((dst[dstX] & 0xff0000) >> 16);
   				int dg = ((dst[dstX] & 0xff00) >> 8);
   				int db = dst[dstX] & 0xff;
   				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  // 公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
   					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         // αp=sa/255 , FP=sg , BP=dg
   					| (sb * sa / 255 + db * (255 - sa) / 255);              // αp=sa/255 , FP=sb , BP=db
   			}
   		}
   	}
   }
   ```

4. 然后修改Chess.cpp中的Chess::chessDown函数为如下图示：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/4069df495b974f2e8ebc5df0873a5678.png#pic_center)

5. 此时我们再来测试一下，可以发现黑边没有了，音效也没问题：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/aac6e674c4ad4aeeafc06c66d192b8f6.png#pic_center)

6. 现在虽然已经实现了落子效果，但是只是表现了出来，并没有将落子数据存储在计算机中，我们之前创建了二维数组，就是为了存储落子数据的，所以我们应该将我们的落子信息存储在二维数组中。首先在Chess.h的private中加入如下函数：

   ```cpp
   // 将落子信息存储到二维数组中
   void updateGameMap(ChessPos* pos);
   ```

7. 然后在Chess.cpp中加入如下函数：

   ```cpp
   // 将落子信息存储在二维数组中
   void Chess::updateGameMap(ChessPos * pos)
   {
   	// 存储落子信息
   	chessMap[pos->row][pos->col] = playerFlag ? CHESS_BLACK : CHESS_WHITE;
   	// 黑白方交换行棋
   	playerFlag = !playerFlag;
   }
   ```

8. 然后在Chess.cpp中的Chess::chessDown函数中调用Chess::updateGameMap：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/1ba95ba6ce944010bb7961b0f78c92cb.png#pic_center)

9. 此时就已经将棋手下棋的落子信息存储在了计算机的二维数组中，这样就方便我们后续操作了

# 八、AI下棋实现

## 8.1 AI初始化

1. 在进行AI初始化时，我们要考虑两个数据成员：

   - 棋盘对象：表示对哪个棋盘下棋
   - 评分数组：存储AI对棋盘所有落点的价值评估，以便AI做出最优决策

2. 基于以上分析，我们首先在AI.h中加入两个数据成员：

   ```cpp
   private:
   	// 棋盘对象
   	Chess* chess;
   	// 评分数组
   	vector<vector<int>> scoreMap;
   ```

3. 然后在AI.cpp中加入如下代码：

   ```cpp
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
   ```


## 8.2 AI下棋原理

1. AI的下棋原理要比棋手下棋原理复杂得多，因为棋手是人工下棋，不需要计算机程序计算，而AI下棋需要根据棋手下棋的落子位置来找到下棋落子的最优策略，也就是说，AI需要对棋盘的所有可能落子点进行评分计算，然后选择一个评分最高的点落子，对于某个可能的落子点的评分，我们可以这么理解：此位置既可能是黑棋落子，也可能是白棋落子，将此位置想象为一个兵家必争之地，我们要做的就是判断黑棋夺取此位置获取的价值多，还是白棋夺取此位置获得的价值多，如果黑棋夺取此位置获取的价值更多，那么我们就应该让白棋落在这里，也就是要让白棋破坏黑棋夺得更多的价值；如果是白棋夺取此位置获取的价值更多，那么就让白棋下载此位置，以获取更多的价值，因为此时是AI执白棋，所以我们要尽可能地让AI获取更多的价值

2. 对于AI来说，每一次落子后，此落子周围共有八个方向，对于每一个落子点，应该向该点的八个方向分别进行评分计算，评分计算的标准就是确定每个方向已经有几颗连续的棋子了。假设现在有一个可能的落子点如下图黑点所示：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/89ea5233c04b41f0a6c961e18d98cba2.png#pic_center)

4. 根据上图可以发现，此次落子周围一共有八个方向，AI首先计算如果棋手在这个可能的位置落子，会有多大的价值，然后再计算AI在同样的位置落子，有多大的价值。那么如何评判价值的大小呢？我们可以将连续的落子数量作为评判的标准，如果黑棋或者白棋在这个位置落子，那么在这个位置的八个方向的某个方向上，一共有多少个连续的黑棋或白棋就是我们评判的标准，如果连续的黑棋或者白棋数量越多，那么在此位置落子的价值就越大

5. 既然要根据连续的黑棋或者白棋数量进行价值的评判，所以我们应该对五子棋中常见的棋形有一个基本的了解，这样有助于我们对不同的情况进行价值的评判。五子棋中的常见棋形如下所示：

   - 连二：

     |                     第一种情况                      |                     第二种情况                      |
     | :-------------------------------------------------: | :-------------------------------------------------: |
     |![请添加图片描述](https://img-blog.csdnimg.cn/19d929611e6e4a3f99ee296387f339b6.png)|![请添加图片描述](https://img-blog.csdnimg.cn/c10e66b23ed74c619bbb65b7ce47c75b.png)|

   - 活三：

     |                     第一种情况                      |                     第二种情况                      |
     | :-------------------------------------------------: | :-------------------------------------------------: |
     |![请添加图片描述](https://img-blog.csdnimg.cn/3622e7ef624e404ea779122c9a5a9a75.png)|![请添加图片描述](https://img-blog.csdnimg.cn/51fbceb17c1e4b8ca6dbd094d8da4efa.png)|


   - 死三：

     |                     第一种情况                      |                     第二种情况                      |
     | :-------------------------------------------------: | :-------------------------------------------------: |
     | ![请添加图片描述](https://img-blog.csdnimg.cn/ef9395c095d34e18887e3b52109d4349.png)|![请添加图片描述](https://img-blog.csdnimg.cn/d8b7e54e98ce4f3bbab4bd18a6ca6972.png)|

   - 活四

     |                     第一种情况                      |                     第二种情况                      |
     | :-------------------------------------------------: | :-------------------------------------------------: |
     |  ![请添加图片描述](https://img-blog.csdnimg.cn/644b5785294a4c7ab0c3864a5a8c2d4c.png)| ![请添加图片描述](https://img-blog.csdnimg.cn/e1f520868ff94cbbbb2e2c8ff582c853.png)|

   - 死四

     |                     第一种情况                      |                     第二种情况                      |
     | :-------------------------------------------------: | :-------------------------------------------------: |
     | ![请添加图片描述](https://img-blog.csdnimg.cn/68ef6315bb5c45f1a2d6cfe58c292e18.png)|  ![请添加图片描述](https://img-blog.csdnimg.cn/0371b5781d49485f8309d1c10cd39bd7.png)|

   - 连五（获胜）

     |                     第一种情况                      |                                                     |
     | :-------------------------------------------------: | :-------------------------------------------------: |
     | ![请添加图片描述](https://img-blog.csdnimg.cn/0674a890aca745e09fe8e7a09c703967.png)|![请添加图片描述](https://img-blog.csdnimg.cn/d5cf2c6b0fce4578b3f3209026c8966a.png)|

6. 对于每种不同的落子情况导致的不同棋形，我们要给予对应评分，方便AI做出判断，从而选取最优落子点落子。不同棋色以及不同棋形的评分标准如下图所示，此评分标准可能不是最优的，但是根据此评分标准设计的AI下五子棋的水平已经超过了大部分棋手的水平，如果需要挑战更难度的五子棋棋手水平，后续可以进行迭代优化。另外需要注意，在我们的游戏中，棋手执黑棋，AI执白棋：

   |   目标棋形   | 黑棋  | 白棋  |
   | :----------: | :---: | :---: |
   |     连二     |  10   |  10   |
   |     死三     |  30   |  25   |
   |     活三     |  40   |  50   |
   |     死四     |  60   |  55   |
   |     活四     |  200  | 10000 |
   | 连五（获胜） | 20000 | 30000 |

## 8.3 AI对棋局进行评分计算

1. 有了以上对AI下棋原理的分析，下面我们就要根据分析的结果进行代码编写了，首先我们要定义一个函数，用来处理AI在下棋过程中落子点的价值评分计算，那么我们在AI.h中加入如下函数：

   ```cpp
   private:
   	// AI对棋局进行评分
   	void calculateScore();
   ```

2. 在AI.cpp中加入如下代码：

   ```cpp
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
   ```

## 8.4 实现AI下棋

1. 当每个可能的落子点各个方向的价值评分计算完成后，就可以让AI进行“思考”，选出价值评分最高的点进行落子。首先在AI.h中加入如下代码：

   ```cpp
   private:
   	// 找出价值评分最高的点落子
   	ChessPos think();
   ```

2. 然后在Chess.h中加入如下代码：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/dc64b35af8b0447bb663e52ec7f75d55.png#pic_center)

3. 然后在AI.cpp中加入如下代码：

   ```cpp
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
   ```

4. 然后在AI.cpp中加入如下代码：

   ```cpp
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
   ```

5. 将Chess.cpp中的Chess::getGradeSize函数和两个Chess::getChessData函数进行如下修改：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/c219444634e240dc9ff94eac4712cab4.png#pic_center)

6. 然后测试一下，发现可以正常下棋了，而且智力还不错。读者可以根据自己的经验调整价值评分的赋值，从而让AI有更高的智力：
					       
![请添加图片描述](https://img-blog.csdnimg.cn/a4ee260f9fb54a488ac5518761dad81d.png#pic_center)

# 九、胜负判定实现

## 9.1 对胜负进行处理

1. 首先在Chess.h中加入如下函数，目的是检查当前谁嬴谁输，然后根据检查结果来进行胜负后的处理：

   ```cpp
   private:
       // 检查当前谁嬴谁输，如果胜负已分就返回true，否则返回false
       bool checkWin();
   ```

2. 在Chess.cpp中加入如下头文件

   ```cpp
   #include <conio.h>
   ```

3. 将Chess.cpp中的Chess::checkOver函数修改为如下内容：

   ```cpp
   // 胜负判定
   bool Chess::checkOver()
   {
   	// checkWin()函数来检查当前谁嬴谁输，如果胜负已分就返回true，否则返回false
   	if (checkWin())
   	{
           // 暂停
   		Sleep(1500);![请添加图片描述](https://img-blog.csdnimg.cn/4dbfb593cf904d2dbf7a140e2a4bbb9c.png)

   		// 说明黑棋（棋手）赢
   		if (playerFlag == false)
   		{
   			mciSendString("play resource/不错.mp3", 0, 0, 0);
   			loadimage(0, "resource/胜利.jpg");
   		}
   		// 说明白棋（AI）赢
   		else
   		{
   			mciSendString("play resource/失败.mp3", 0, 0, 0);
   			loadimage(0, "resource/失败.jpg");
   		}
   		// 暂停
   		_getch();
   		return true;
   	}
   	return false;
   }
   ```

## 9.2 胜负判定原理

1. 上面对胜负进行处理的过程是我们胜负判定实现的一个基本框架，其核心部分是checkWin函数，也就是我们如何判断当然谁赢谁输。我们可以这样想：对于某一个落子位置，我们要判断其八个方向是否连成五子，但是每次判断我们都可以同时根据偏移的落子位置，将其反方向是否连成五子进行判断，所以只需要判断四个大方向，八个小方向即可。假设我们首先判断水平方向，如下图所示：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/49aa1f1c3ec64cc8bef6dd68e1a38cf7.png#pic_center)

2. 可以看到，对于某一落子位置，我们首先判断从此位置向右的连续五个位置是否是相同颜色，然后将起始落子点分别向左偏移一、二、三、四、五个位置再判断是否有连续的五个相同颜色的棋子，如果满足，就获胜，否则就没获胜。这样我们就可以在一个大方向的判断上同时判断两个小方向，就完成了我们的胜负判断，其余方向的胜负判断同理

## 9.3 胜负判定实现

1. 有了以上的原理分析后，我们就可以写代码了。首先在Chess.h中加入某一落子点位置的数据成员：

   ```cpp
   private:
   	// 某一落子点的位置
   	ChessPos lastPos;
   ```

2. 然后在Chess.cpp中的Chess::updateGameMap函数中加入如下代码：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/e5ba90ec29654aacb40b4f0d2ea6dee3.png#pic_center)

3. 然后在Chess.cpp中加入如下代码：

   ```cpp
   // 检查当前谁嬴谁输，如果胜负已分就返回true，否则返回false
   bool Chess::checkWin()
   {
   	// 某一落子点的位置
   	int row = lastPos.row;
   	int col = lastPos.col;
   	// 落子点的水平方向
   	for (int i = 0; i < 5; i++)
   	{
   		if (((col - i) >= 0) && ((col - i + 4) < gradeSize) && (chessMap[row][col - i] == chessMap[row][col - i + 1]) && (chessMap[row][col - i] == chessMap[row][col - i + 2]) && (chessMap[row][col - i] == chessMap[row][col - i + 3]) && (chessMap[row][col - i] == chessMap[row][col - i + 4]))
   		{
   			return true;
   		}
   	}
   	// 落子点的垂直方向
   	for (int i = 0; i < 5; i++)
   	{
   		if (((row - i) >= 0) && ((row - i + 4) < gradeSize) && (chessMap[row - i][col] == chessMap[row - i + 1][col]) && (chessMap[row - i][col] == chessMap[row - i + 2][col]) && (chessMap[row - i][col] == chessMap[row - i + 3][col]) && (chessMap[row - i][col] == chessMap[row - i + 4][col]))
   		{
   			return true;
   		}
   	}
   	// 落子点的右斜方向
   	for (int i = 0; i < 5; i++)
   	{
   		if (((row + i) < gradeSize) && (row + i - 4 >= 0) && (col - i >= 0) && ((col - i + 4) < gradeSize) && (chessMap[row + i][col - i] == chessMap[row + i - 1][col - i + 1]) && (chessMap[row + i][col - i] == chessMap[row + i - 2][col - i + 2]) && (chessMap[row + i][col - i] == chessMap[row + i - 3][col - i + 3]) && (chessMap[row + i][col - i] == chessMap[row + i - 4][col - i + 4]))
   		{
   			return true;
   		}
   	}
   	// 落子点的左斜方向
   	for (int i = 0; i < 5; i++)
   	{
   		if (((row - i + 4) < gradeSize) && (row - i >= 0) && (col - i >= 0) && ((col - i + 4) < gradeSize) && (chessMap[row - i][col - i] == chessMap[row - i + 1][col - i + 1]) && (chessMap[row - i][col - i] == chessMap[row - i + 2][col - i + 2]) && (chessMap[row - i][col - i] == chessMap[row - i + 3][col - i + 3]) && (chessMap[row - i][col - i] == chessMap[row - i + 4][col - i + 4]))
   		{
   			return true;
   		}
   	}
   	return false;
   }
   ```

4. 写完之后我们可以测试一下：
   - 黑棋（棋手）：
   		- 黑棋（棋手）胜的棋面：
						      ![在这里插入图片描述](https://img-blog.csdnimg.cn/27fa3d6f4a1a44f9a0b53bb19abffbb9.png#pic_center)
   		- 黑棋（棋手）胜的判定：
						      
![请添加图片描述](https://img-blog.csdnimg.cn/ea36b26264344aecbcb1cecf81eafbe4.png#pic_center)
   - 白棋（AI）：
  		- 白棋（AI）胜的棋面：
						      
![在这里插入图片描述](https://img-blog.csdnimg.cn/7795a0cf3bb44e37b113475e562f41a2.png#pic_center)  				
		- 白棋（AI）胜的判定：
						      ![请添加图片描述](https://img-blog.csdnimg.cn/74bfa9eee4f546a48d32bf1bd9eddc12.png#pic_center)

5. 可以看到，不管是黑棋（棋手）胜，还是白棋（AI）胜，都可以正常显示胜负的判定了。而且按回车（Enter）键还可以自动开启下一局

<hr style=" border:solid; width:100px; height:1px;" color=#000000 size=1">

# 总结
&nbsp;&nbsp;以上就是基于C++的AI五子棋游戏项目开发教程的全部内容了，可以看到我们已经实现了目标，但是后续仍旧可以进行一些优化，比如AI对于落子的价值评分的优化、悔棋功能、主界面菜单等等，后续如果我有时间仍会更新此博客，如果读者自己爱钻研、感兴趣也可以自己完成优化的部分，因为整体的思路都比较清晰，而且逻辑也没有什么太大变化，所以优化起来也比较简单。那这篇博客就暂时告一段落了，我们下篇博客见！
