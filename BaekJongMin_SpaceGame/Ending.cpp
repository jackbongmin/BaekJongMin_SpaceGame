#include "Ending.h"
#include <Windows.h>
#include "Player.h"

// 10일 생존 후 엔딩 체크
void Ending::EndingCheck(Player& Inplayer, int InDay)
{
    if (InDay >= 10 && Inplayer.GetLowAffinityCount() >= 2)
    {
        BadEnding();
    }
    else if (InDay >= 10 && Inplayer.GetHighAffinityCount() >= 3 && Inplayer.GetAlienBook() >=3)
    {
        HappyEnding();
    }
    else if (InDay >= 10)
    {
        SurvivalEnding();
    }
}

// 노말엔딩
void Ending::SurvivalEnding()
{
    Sleep(2000);
    printf(" 당신은 10일간 생존에 성공하였습니다.\n\n");
    Sleep(2000);
    printf(" 무사히 목적지인 우주정거장에 도착하여\n\n");
    Sleep(2000);
    printf(" 구조요청을 보냈습니다..\n\n");
    Sleep(2500);
    printf(" 당신은 생존하였습니다.");
    Sleep(1000);
    printf("[");
    Sleep(50);
    printf("노");
    Sleep(50);
    printf("말");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("엔");
    Sleep(50);
    printf("딩");
    Sleep(50);
    printf("]");
    Sleep(50);
    printf("\n\n\n");
}

// 해피엔딩(외계인도감 3개 보유, 호감도 80이상인채 3번이상 커뮤니케이션 진행)
void Ending::HappyEnding()
{
    Sleep(2000);
    printf(" 당신은 10일간 생존에 성공하였습니다.\n\n");
    Sleep(2000);
    printf(" 무사히 목적지인 우주정거장에 도착하여\n");
    Sleep(2000);
    printf(" 구조요청을 보냈습니다..\n\n");
    Sleep(2000);
    printf(" 생존기간동안 외계생물체에 대한 많은 정보를 입수하여,\n");
    Sleep(2000);
    printf(" 구조요청과 동시에 새로운 정보들을 함께 송부했습니다.\n\n");
    Sleep(2000);
    printf(" 이제 외계생명체와의 소통이 가능해졌으며,\n");
    Sleep(2000);
    printf(" 지구의 발전에 큰 기여를 하게 되었습니다.\n\n");
    Sleep(2500);
    printf(" 당신은 생존하였습니다.");
    Sleep(1000);
    printf("[");
    Sleep(50);
    printf("해");
    Sleep(50);
    printf("피");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("엔");
    Sleep(50);
    printf("딩");
    Sleep(50);
    printf("]");
    Sleep(50);
    printf("\n\n\n");
}

// 베드엔딩(호감도 20이하인채 2번이상 커뮤니케이션 진행)
void Ending::BadEnding()
{
    Sleep(2000);
    printf(" 당신은 10일간 생존에 성공하였습니다.\n\n");
    Sleep(2000);
    printf(" 목적지인 우주 정거장에 도킹을 하려는 순간,\n");
    Sleep(2000);
    printf(" 생존기간동안 분쟁을 일으켰던 외계종족들이 날아와\n");
    Sleep(2000);
    printf(" 우주 정거장을 공격하기 시작합니다.\n\n");
    Sleep(2000);
    printf(" 도킹 구간은 형태를 알아볼 수 없이 부숴졌고,\n");
    Sleep(2000);
    printf(" 부셔지는 우주정거장을 그저 바라만 볼 수 밖에 없습니다.\n\n");
    Sleep(2000);
    printf(" 우주정거장은 부숴졌고,\n");
    Sleep(2000);
    printf(" 이제 당신이 다음 타겟이 되었네요.\n\n");
    Sleep(2500);
    printf(" 당신은 생존하지 못했습니다.");
    Sleep(1000);
    printf("[");
    Sleep(50);
    printf("베");
    Sleep(50);
    printf("드");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("엔");
    Sleep(50);
    printf("딩");
    Sleep(50);
    printf("]");
    Sleep(50);
    printf("\n\n\n");
}
