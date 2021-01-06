#include "GamePackage.h"

int BaseBall()
{
    int computerBall[3], userBall[3];
    int i, j, temp; // temp�� ���� �ߺ� üũ�� ���� ����
    int count = 1; // ȸ���� Ȯ�� ����, 9���� ���� 
    int strike, ball;

    // ���� ���� �� �ߺ� üũ 
    srand((unsigned)time(NULL));

    for (i = 0; i < 3; i++)
    {
        temp = (rand() % 9) + 1; // temp������ ���� ���� ���� ���� 
        computerBall[i] = temp; // temp���� ��ǻ���� ���� ���� 

        for (j = 0; j < i; j++) // ���� �߰��� ��ŭ �ݺ� 
        {
            if (temp == computerBall[j] && i != j)
            {   // ���� ���� temp���� ������ ���� �� �� ������ �� �ִٸ� 
                i--;
            }   // i�� ���� �ٿ��������ν� �������� ���ư� �� �ֵ��� ��.
        }

    }

    while (1) // ���ھ߱� ���� ���� while ��
    {
        printf("�� %dȸ�� ���ھ߱� ��\n", count);

        while (1) // �������� ���ڸ� �Է¹ޱ� ���� while �� 
        {
            printf("1���� 9������ ���ڸ� 3���� ���⸦ �Ͽ� �Է��ϼ��� : ");
            scanf("%d %d %d", &userBall[0], &userBall[1], &userBall[2]);

            if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9)
            { // �Է��� ���ڰ� 1 ~ 9 ���ڰ� �ƴϸ� �ٽ� �Է¹ް� �� 
                printf("���� ���� ���ڸ� �Է����ּ���.\n");
                continue;
            }

            else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2])
            { // �Է��� ���� �߿� �ߺ��� ���ڰ� ������ �ٽ� �Է¹ް� ��
                printf("�ߺ��� ���ڸ� �Է��߽��ϴ�.\n");
                continue;
            }

            break; // ���ٸ� ���� ���� ��� �ݺ��� ���� 

        }

        ball = 0, strike = 0;

        for (i = 0; i < 3; i++) // computerBall 1~3��°�� ���� �� userBall 1~3��°�� Ȯ���ϱ� ���� �ݺ� 
        {
            for (j = 0; j < 3; j++)
            {
                if (computerBall[i] == userBall[j]) // computerBall�� userBall�� ���� ���ٸ� 
                {
                    if (i == j) // ���� ��ġ�� ��� 
                    {
                        strike++; // ��Ʈ����ũ ���� ���� 
                    }

                    else // �ٸ� ��ġ�� ��� 
                    {
                        ball++; // �� ���� ���� 
                    }
                }
            }
        }

        // Ȯ���� ����� ��� 

        printf("��result = Strike : %d ,  Ball : %d\n\n", strike, ball);

        if (strike == 3) // ���� ��Ʈ����ũ ������ 3���̸� �¸�
        {
            printf("�ڡڡڡڡ� YOU WIN. �ڡڡڡڡ�\n\n");
            break;
        }

        else if (count == 9) // ���� 9ȸ������ �¸����� ���ϸ� �й�
        {
            printf("�١١١١� YOU LOSE. �١١١١�\n\nANSWER : %d %d %d\n\n", computerBall[0], computerBall[1], computerBall[2]);
            break;
        }

        count++;

    }

    return 0;

}