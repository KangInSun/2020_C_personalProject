#include "GamePackage.h"

int r_s_p_main()
{
	int computer;
	int user;
	int wincount = 0;
	int losecount = 0;
	int samecount = 0;

	srand(time(NULL));

	printf("\n ■ 주먹 : 0번\n ■ 가위 : 1번\n ■ 보 : 2번\n\n ☆게임 종료 : 3번\n\n\n");

	while (1)
	{
		printf("\n ○ 숫자를 입력해주세요 : ");
		scanf(" %d", &user);
		computer = rand() % 3;
		printf("computer = %d\n", computer);

		if (user == 3)
		{
			printf("\n\n ★이긴 횟수 : %d\n ★진 횟수 : %d\n ★비긴 횟수 : %d", wincount, losecount, samecount);
			printf("\n\n==================================================================================================▶종료. ");
			return 0;
		}

		if (computer == 0)
		{
			if (user == 0)
			{
				printf(" ◆당신은 (주먹) 선택 , 컴퓨터는 (주먹)선택 : DRAW.\n");
				samecount++;
			}

			else if (user == 1)
			{
				printf(" ◆당신은 (가위) 선택 , 컴퓨터는 (주먹)선택 : YOU LOSE.\n");
				losecount++;
			}

			else if (user == 2)
			{
				printf(" ◆당신은 (보) 선택 , 컴퓨터는 (주먹)선택 : YOU WIN.\n");
				wincount++;
			}
		}

		else if (computer == 1)
		{
			if (user == 0)
			{
				printf(" ◆당신은 (주먹) 선택 , 컴퓨터는 (가위)선택 : YOU WIN.\n");
				wincount++;
			}

			else if (user == 1)
			{
				printf(" ◆ 당신은 (가위) 선택 , 컴퓨터는 (가위)선택 : DRAW.\n");
				samecount++;
			}

			else if (user == 2)
			{
				printf(" ◆ 당신은 (보) 선택 , 컴퓨터는 (가위)선택 : YOU LOSE.\n");
				losecount++;
			}
		}

		else if (computer == 2)
		{
			if (user == 0)
			{
				printf(" ◆ 당신은 (주먹) 선택 , 컴퓨터는 (보) 선택 : YOU LOSE.\n");
				losecount++;
			}

			else if (user == 1)
			{
				printf(" ◆ 당신은 (가위) 선택 , 컴퓨터는 (보) 선택 : YOU WIN.\n");
				wincount++;
			}

			else if (user == 2)
			{
				printf(" ◆ 당신은 (보) 선택 , 컴퓨터는 (보) 선택 : DRAW.\n");
				samecount++;
			}
		}
	}
}