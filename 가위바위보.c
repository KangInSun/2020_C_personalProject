#include "GamePackage.h"

int r_s_p_main()
{
	int computer;
	int user;
	int wincount = 0;
	int losecount = 0;
	int samecount = 0;

	srand(time(NULL));

	printf("\n �� �ָ� : 0��\n �� ���� : 1��\n �� �� : 2��\n\n �ٰ��� ���� : 3��\n\n\n");

	while (1)
	{
		printf("\n �� ���ڸ� �Է����ּ��� : ");
		scanf(" %d", &user);
		computer = rand() % 3;
		printf("computer = %d\n", computer);

		if (user == 3)
		{
			printf("\n\n ���̱� Ƚ�� : %d\n ���� Ƚ�� : %d\n �ں�� Ƚ�� : %d", wincount, losecount, samecount);
			printf("\n\n==================================================================================================������. ");
			return 0;
		}

		if (computer == 0)
		{
			if (user == 0)
			{
				printf(" �ߴ���� (�ָ�) ���� , ��ǻ�ʹ� (�ָ�)���� : DRAW.\n");
				samecount++;
			}

			else if (user == 1)
			{
				printf(" �ߴ���� (����) ���� , ��ǻ�ʹ� (�ָ�)���� : YOU LOSE.\n");
				losecount++;
			}

			else if (user == 2)
			{
				printf(" �ߴ���� (��) ���� , ��ǻ�ʹ� (�ָ�)���� : YOU WIN.\n");
				wincount++;
			}
		}

		else if (computer == 1)
		{
			if (user == 0)
			{
				printf(" �ߴ���� (�ָ�) ���� , ��ǻ�ʹ� (����)���� : YOU WIN.\n");
				wincount++;
			}

			else if (user == 1)
			{
				printf(" �� ����� (����) ���� , ��ǻ�ʹ� (����)���� : DRAW.\n");
				samecount++;
			}

			else if (user == 2)
			{
				printf(" �� ����� (��) ���� , ��ǻ�ʹ� (����)���� : YOU LOSE.\n");
				losecount++;
			}
		}

		else if (computer == 2)
		{
			if (user == 0)
			{
				printf(" �� ����� (�ָ�) ���� , ��ǻ�ʹ� (��) ���� : YOU LOSE.\n");
				losecount++;
			}

			else if (user == 1)
			{
				printf(" �� ����� (����) ���� , ��ǻ�ʹ� (��) ���� : YOU WIN.\n");
				wincount++;
			}

			else if (user == 2)
			{
				printf(" �� ����� (��) ���� , ��ǻ�ʹ� (��) ���� : DRAW.\n");
				samecount++;
			}
		}
	}
}