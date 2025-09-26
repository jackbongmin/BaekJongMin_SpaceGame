#include <iostream>
#include <Windows.h>
#include "GameManager.h"
#include "IIIntro.h"
#include "Meet.h"

// 시작 인트로
void IIIntro::Intro_1()
{
	printf("\n                                                            /^\\                      \n");
	printf("                                                           /   \\                     \n");
	printf("                                                          /  o  \\                    \n");
	printf("                                                         /   o   \\                   \n");
	printf("                                                        /    o    \\                  \n");
	printf("                                                       |-_________-|                  \n");
	printf("                                                       |           |                  \n");
	printf("                      __                               |   __      |                  \n");
	printf("                     (__)                             /|  [  ]     |\\                \n");
	printf("                      ||                             / |  [  ]     | \\               \n");
	printf("                   .------.                         /__|  [__]     |__\\              \n");
	printf("                .-'        `-.                          \\         /                  \n");
	printf("              .'_     _     _ `.                         \\       /                   \n");
	printf("             / [_]   [ ]   [_] \\                         /=======\\                   \n");
	printf("          __|  [_]   [_]   [_]  |__                     /=========\\                  \n");
	printf("        /    \\                 /     \\                 /===========\\                 \n");
	printf("       I      `. ._________. .'       I                  ||  ||  ||                   \n");
	printf("       \\                             /                   VV  VV  VV                   \n");
	printf("        '-'-----------------------'-'                   vvv  vv  vvv                  \n");
	printf("           I_I       I_I       I_I                     vvvv  vv  vvvv                 \n\n");

	printf(" _   _  ______  __   __  _____             _____  ______      _    _    _____        \n");
	printf("| \\ | ||  ____| \\ \\ / / |  __ \\    /\\     / ____||  ____|    | |  | |  / ____|  \n");
	printf("|  \\| || |__     \\ V /  | |__) |  /  \\   | |     | |__       | |  | | | (___      \n");
	printf("| . ` ||  __|     > <   | |___/  / /\\ \\  | |     |  __|      | |  | |  \\___ \\    \n");
	printf("| |\\  || |____   / . \\  | |     / ____ \\ | |___  | |____     | |__| |  ____) |    \n");
	printf("|_| \\_||______| /_/ \\_\\ |_|    /_/    \\_\\ \\_____||______|     \\____/  |_____/ \n\n");

	Meet meet;
	meet.aaaaa();

}

// 이름 입력 후 스토리 인트로
void IIIntro::Intro_2(Player& player)
{
	Sleep(1000);
	printf("\n안녕하세요, %s씨.\n\n", player.GetName().c_str());
	Sleep(2000);
	printf("정신이 드셨군요. 당신은 현재 우주에 있습니다.\n\n");
	Sleep(2000);
	printf("당신의 동료들은 모두 죽었고, 우주선에 남아있는 보급품도 얼마 없네요.\n\n");
	Sleep(2000);
	printf("당신의 목적지인 우주정거장까진");
	Sleep(2000);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf("10일이 남았네요.");
	Sleep(2500);
	printf(" \n\n");
	printf("살아 남으세요.\n");
	Sleep(2000);
	printf("그리고 당신이 연구한 자료를 지구에 송부하세요.\n\n");
	Sleep(2000);
	printf("당신이 지구의 희망이 될 수 있습니다.\n\n");
	Sleep(2000);
	printf("      N");
	Sleep(400);
	printf("E");
	Sleep(400);
	printf("X");
	Sleep(400);
	printf("P");
	Sleep(400);
	printf("A");
	Sleep(400);
	printf("C");
	Sleep(400);
	printf("E");
	Sleep(400);
	printf(" ");
	Sleep(400);
	printf("U");
	Sleep(400);
	printf("S");
	Sleep(400);
	printf(" \n\n");
}

// 날짜 경계선
void IIIntro::ReportDay(int InDay)
{
	Sleep(500);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf(" ");
	Sleep(25);
	printf("D");
	Sleep(25);
	printf("a");
	Sleep(25);
	printf("y");
	Sleep(25);
	printf(" ");
	Sleep(25);
	printf("%d", InDay);
	Sleep(25);
	printf(" ");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=\n\n");
	Sleep(25);
}

// 다음날 경계선
void IIIntro::ReportNextDay()
{
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=");
	Sleep(25);
	printf("=\n\n");
	Sleep(25);
	printf("       ");
	Sleep(25);
	printf("다");
	Sleep(50);
	printf("음");
	Sleep(50);
	printf("날\n\n");
	Sleep(500);
}
