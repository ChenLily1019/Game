#include"game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		if (i == 0)
		{
			for (int k = 0; k < col; k++)
			{
				if (k == 0)
				{
					printf("|");
				}
				printf("---|");
			}
			printf("\n");
		}
		for (int j = 0; j < col; j++)
		{
			if (j == 0)
			{
				printf("|");
			}
			printf(" %c ", board[i][j]);
			printf("|");
		}
		printf("\n");
		for (int k = 0; k < col; k++)
		{
			if (k == 0)
			{
				printf("|");
			}
			printf("---|");
		}
		printf("\n");
	}
	printf("\n");
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("温馨提示：坐标用空格分隔，祝您玩的愉快\n");
		printf("轮到玩家下棋>\n");
		printf("请输入下棋的坐标>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("\n坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("\n坐标非法，请重新输入\n");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("轮到电脑下棋>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//平局判断
int Full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断胜负
//返回四种情况
//*：玩家获胜
//#：电脑获胜
//f：平局
//c：继续
char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		//横向
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	for (int j = 0; j < row; j++)
	{
		//纵向
		if (board[0][j] == board[1][j] &&
			board[1][j] == board[2][j] &&
			board[1][j] != ' ')
		{
			return board[1][j];
		}
	}

	//斜向
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] &&
		board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] &&
		board[1][1] == board[2][0] &&
		board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局
	if (Full(board, row, col) == 1)
	{
		return 'f';
	}

	return 'c';
}

