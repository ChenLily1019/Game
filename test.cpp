#include"game.h"

//��Ϸ�˵�
void menu()
{
	printf("************************************\n");
	printf("*************  1.play  *************\n");
	printf("*************  0.exit  *************\n");
	printf("************************************\n");
}

void game()
{
	//�洢���� - ��ά����
	char board[ROW][COL] = { 0 };
	//�����ж���Ӯ�ķ���ֵ
	char reason = 0;
	//��ʼ������ - ��ʼ���ո�
	InitBoard(board, ROW, COL);
	//��ӡ������ - �����Ǵ�ӡ���������
	DisplayBoard(board, ROW, COL);
	//���� - ��������Ҷ���
	while (1)
	{
		//������壬ÿ������������´�ӡ����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		reason = IsWin(board, ROW, COL);
		if (reason != 'c')
		{
			break;
		}

		//�������壬ͬ����Ҫ���´�ӡ����
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
		printf("��Ӯ��\n");
	}
	else if (reason == '#')
	{
		printf("���Ի�ʤ���´μ���\n");
	}
	else
	{
		printf("ƽ��");
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
		printf("��ѡ��>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n�˳���Ϸ\n");
			break;
		default:
			printf("\nѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}