#include"game.h"

//��ʼ������
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

//��ӡ����
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

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("��ܰ��ʾ�������ÿո�ָ���ף��������\n");
		printf("�ֵ��������>\n");
		printf("���������������>");
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
				printf("\n�����ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("\n����Ƿ�������������\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("�ֵ���������>\n");
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

//ƽ���ж�
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

//�ж�ʤ��
//�����������
//*����һ�ʤ
//#�����Ի�ʤ
//f��ƽ��
//c������
char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		//����
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	for (int j = 0; j < row; j++)
	{
		//����
		if (board[0][j] == board[1][j] &&
			board[1][j] == board[2][j] &&
			board[1][j] != ' ')
		{
			return board[1][j];
		}
	}

	//б��
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

	//�ж��Ƿ�ƽ��
	if (Full(board, row, col) == 1)
	{
		return 'f';
	}

	return 'c';
}

