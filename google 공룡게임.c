#include "GamePackage.h"

// �ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{	
	// (" mode con cols = ������ ���� line = ������ ���� | title : ���� " )
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaur Game");
}

// Ŀ���� ��ġ�� x , y �� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// Ű����� ���� �Է��� �ް� , �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyboard()
{
	if (_kbhit() != 0) // kbhit()�� Ű���忡 ���� �ԷµǸ� 0�̿��� ���� ��ȯ�ϴ� �Լ��̴�. _�� ���޽����� ������� �ʱ� ����? �� �Ͱ���.
	{
		return _getch(); // getchar()�� ��������� Ű����� �Էµ� ���� ȭ�鿡 ������� �ʴ´�.
	}
	return 0;
}

// ���� �׸� �Լ�
void Dinosaur(int Dinosaur_Y)
{
	GotoXY(0, Dinosaur_Y);
	static bool legFlag = true;

	printf("        $$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$    \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}

	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}

}

// ��ֹ� (����) �׸� �Լ�
void Tree(int Tree_X)
{
	GotoXY(Tree_X, TREE_BOTTOM_Y);
	printf("####");
	for (int i = 1; i <= 4; i++)
	{
		GotoXY(Tree_X, TREE_BOTTOM_Y + i);
		printf(" ## ");
	}
}

// �浹�� �ϸ� ��µǴ� GAME OVER
void GameOver(const int score)
{
	system("cls");
	int x = 17, y = 12;
	GotoXY(x, y);
	GotoXY(x, y + 1);
	printf("====== G A M E O V E R ======");
	GotoXY(x, y + 2);
	printf("=============================");
	GotoXY(x, y + 8);
	printf("\t    SCORE : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

// bool �Լ��� �̿��Ͽ� �浹�ϸ� true , �浹���� ������ false
bool isCollision(const int Tree_X, const int Dinosaur_Y)
{
	GotoXY(0, 0);

	if (Tree_X <= 8 && Tree_X >= 4 && Dinosaur_Y > 8)
	{
		return true;
	}

	return false;
}

int main_Dinosaur()
{
	SetConsoleView();

	// ���� ������ �� �ʱ�ȭ
	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;

	int Dinosaur_Y = DINO_BOTTOM_Y;
	int Tree_X = TREE_BOTTOM_X;

	int score = 0;
	// ���� ���� �ʱ�ȭ
	clock_t start, t;
	// ���۽ð� �ʱ�ȭ
	start = clock();

	// ���� �� �� ����
	while (true)
	{
		// �浹üũ : Ʈ���� x���� ������ y������ �Ǵ�
		if (isCollision(Tree_X, Dinosaur_Y))
		{
			break;
		}

		// zŰ�� �����鼭 �ٴ��� �ƴ� ��� ����
		if (GetKeyboard() == 'z' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		// ���� ���� ���� Y���� ���ҽ�Ű�� 
		if (isJumping)
		{
			Dinosaur_Y = Dinosaur_Y - gravity;
		}

		// ������ �������� Y���� ������Ų��.
		else
		{
			Dinosaur_Y = Dinosaur_Y + gravity;
		}

		// Y���� ����ؼ� �����ϴ� ���� �����ϱ� ���� �ٴ��� �����Ѵ�
		if (Dinosaur_Y >= DINO_BOTTOM_Y)
		{
			Dinosaur_Y = DINO_BOTTOM_Y;
			isBottom = true;
		}

		// ���� ���� �Ѱ� (Y �ּڰ�) ����
		if (Dinosaur_Y <= 3)
		{
			isJumping = false;
		}

		// ������ ���� (X�� ����)�� ���� ��
		Tree_X -= 2;

		// ������ ��ġ�� ���� ������ ���� �ٽ� ������ ������ ������ ��
		if (Tree_X <= 0)
		{
			Tree_X = TREE_BOTTOM_X;
		}

		// ����׸� �׸��� �Լ� ȣ��
		Dinosaur(Dinosaur_Y);

		// ��ֹ� (����) �׸��� �Լ� ȣ��
		Tree(Tree_X);

		// ���� �ð��� ��Ÿ���� �Լ� ȣ��
		t = clock();

		// �ð��� 1�ʰ� �Ѿ��� ���
		if ((t - start) / (CLOCKS_PER_SEC) >= 1)
		{
			// score ���� ++ ����
			score++;
			// ���۽ð��� �ʱ�ȭ ���ش�.
			start = clock();
		}

		// (time)��ȣ �� time��ŭ ���α׷��� �Ͻ����� �Ѵ�.
		_sleep(60);
		// clear screen = �� â�� �������� ��
		system("cls");

		// ��������� 1�ʸ��� �ϴ� ���� �ƴ϶� , ��� ����ϸ鼭 1�ʰ� ������ �� ++��.
		GotoXY(22, 0);
		// ��ֹ��� �ε����� ������ ����� �ش�.
		printf("SCORE : %d ", score);
	}

	// �浹�� �ϸ� ��µǴ� GAME OVER �Լ� ȣ��
	GameOver(score);

	return 0;

}		