#include "GamePackage.h"

int main()
{
    switch (intro())
    {

    case 1:
        // clear screen = 새 창이 나오도록 함
        system("cls");
        BaseBall();
        system("cls");
        intro();

    case 2:
        system("cls");
        r_s_p_main();
        system("cls");
        intro();

    case 3:
        system("cls");
        main_Dinosaur();
        system("cls");
        intro();

    default :
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    GAME OVER");
    }
}