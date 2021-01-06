#include "GamePackage.h"

// 콘솔 창의 시작화면

int intro()
{
    int n;
    printf("\t\t\t\t\t┌──────────────────┐ \n");
    printf("\t\t\t\t\t│ ! Game Package ! │ \n");
    printf("\t\t\t\t\t└──────────────────┘ \n");
    printf("\t\t\t\t\t  1. BaseBall Game\n");
    printf("\t\t\t\t   2. Rock , Scissor , Paper Game\n");
    printf("\t\t\t\t       3. Google Dinosaur Game\n");
    printf("\t\t\t\t\t    4. GAME END\n\n");
    printf("\t\t\t\t     ★ PUSH THE NUMBER  : ");
    scanf("%d", &n);
    return n;

}