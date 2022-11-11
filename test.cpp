#include"game.h"

//游戏菜单
void menu()
{
	printf("************************************\n");
	printf("*************  1.play  *************\n");
	printf("*************  0.exit  *************\n");
	printf("************************************\n");
}

void game()
{
	//存储数据 - 二维数组
	char board[ROW][COL] = { 0 };
	//接受判断输赢的返回值
	char reason = 0;
	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);
	//打印下棋盘 - 本质是打印数组的内容
	DisplayBoard(board, ROW, COL);
	//下棋 - 电脑与玩家对弈
	while (1)
	{
		//玩家下棋，每次下棋后需重新打印棋盘
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		reason = IsWin(board, ROW, COL);
		if (reason != 'c')
		{
			break;
		}

		//电脑下棋，同样需要重新打印棋盘
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		reason = IsWin(board, ROW, COL);
		if (reason != 'c')
		{
			break;
		}
	}
	if (reason == '*')
	{
		printf("你赢了\n");
	}
	else if (reason == '#')
	{
		printf("电脑获胜，下次加油\n");
	}
	else
	{
		printf("平局");
	}
	system("pause");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		system("cls");
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n退出游戏\n");
			break;
		default:
			printf("\n选择错误，请重新选择\n");
			break;
		}
	} while (input);
}