#include "GamePackage.h"

// 콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{	
	// (" mode con cols = 가로의 길이 line = 세로의 길이 | title : 제목 " )
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaur Game");
}

// 커서의 위치를 x , y 로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 키보드로 부터 입력을 받고 , 입력된 키의 값을 반환하는 함수
int GetKeyboard()
{
	if (_kbhit() != 0) // kbhit()는 키보드에 무언가 입력되면 0이외의 값을 반환하는 함수이다. _는 경고메시지를 출력하지 않기 위함? 인 것같다.
	{
		return _getch(); // getchar()와 비숫하지만 키보드로 입력된 값을 화면에 출력하지 않는다.
	}
	return 0;
}

// 공룡 그림 함수
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

// 장애물 (나무) 그림 함수
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

// 충돌을 하면 출력되는 GAME OVER
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

// bool 함수를 이용하여 충돌하면 true , 충돌하지 않으면 false
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

	// 게임 시작할 때 초기화
	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;

	int Dinosaur_Y = DINO_BOTTOM_Y;
	int Tree_X = TREE_BOTTOM_X;

	int score = 0;
	// 점수 변수 초기화
	clock_t start, t;
	// 시작시간 초기화
	start = clock();

	// 게임 한 판 루프
	while (true)
	{
		// 충돌체크 : 트리의 x값과 공룡의 y값으로 판단
		if (isCollision(Tree_X, Dinosaur_Y))
		{
			break;
		}

		// z키가 눌리면서 바닥이 아닐 경우 점프
		if (GetKeyboard() == 'z' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		// 점프 중일 때는 Y값를 감소시키고 
		if (isJumping)
		{
			Dinosaur_Y = Dinosaur_Y - gravity;
		}

		// 점프가 끝났으면 Y값을 증가시킨다.
		else
		{
			Dinosaur_Y = Dinosaur_Y + gravity;
		}

		// Y값이 계속해서 증가하는 것을 방지하기 위해 바닥을 지정한다
		if (Dinosaur_Y >= DINO_BOTTOM_Y)
		{
			Dinosaur_Y = DINO_BOTTOM_Y;
			isBottom = true;
		}

		// 점프 높이 한계 (Y 최솟값) 지정
		if (Dinosaur_Y <= 3)
		{
			isJumping = false;
		}

		// 나무가 왼쪽 (X값 음수)로 가게 함
		Tree_X -= 2;

		// 나무의 위치가 왼쪽 끝으로 가면 다시 오른쪽 끝으로 가도록 함
		if (Tree_X <= 0)
		{
			Tree_X = TREE_BOTTOM_X;
		}

		// 공룡그림 그리는 함수 호출
		Dinosaur(Dinosaur_Y);

		// 장애물 (나무) 그리는 함수 호출
		Tree(Tree_X);

		// 현재 시간을 나타내는 함수 호출
		t = clock();

		// 시간이 1초가 넘었을 경우
		if ((t - start) / (CLOCKS_PER_SEC) >= 1)
		{
			// score 값을 ++ 해줌
			score++;
			// 시작시간을 초기화 해준다.
			start = clock();
		}

		// (time)괄호 속 time만큼 프로그램을 일시정지 한다.
		_sleep(60);
		// clear screen = 새 창이 나오도록 함
		system("cls");

		// 점수출력을 1초마다 하는 것이 아니라 , 계속 출력하면서 1초가 지났을 때 ++함.
		GotoXY(22, 0);
		// 장애물에 부딪히면 점수를 출력해 준다.
		printf("SCORE : %d ", score);
	}

	// 충돌을 하면 출력되는 GAME OVER 함수 호출
	GameOver(score);

	return 0;

}		