#include <iostream>
#include <Windows.h>
#include "GameManager.h"
#include "IIIntro.h"
#include "Meet.h"

// ���� ��Ʈ��
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

// �̸� �Է� �� ���丮 ��Ʈ��
void IIIntro::Intro_2(Player& player)
{
	Sleep(1000);
	printf("\n�ȳ��ϼ���, %s��.\n\n", player.GetName().c_str());
	Sleep(2000);
	printf("������ ��̱���. ����� ���� ���ֿ� �ֽ��ϴ�.\n\n");
	Sleep(2000);
	printf("����� ������� ��� �׾���, ���ּ��� �����ִ� ����ǰ�� �� ���׿�.\n\n");
	Sleep(2000);
	printf("����� �������� �������������");
	Sleep(2000);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf("10���� ���ҳ׿�.");
	Sleep(2500);
	printf(" \n\n");
	printf("��� ��������.\n");
	Sleep(2000);
	printf("�׸��� ����� ������ �ڷḦ ������ �ۺ��ϼ���.\n\n");
	Sleep(2000);
	printf("����� ������ ����� �� �� �ֽ��ϴ�.\n\n");
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

// ��¥ ��輱
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

// ������ ��輱
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
	printf("��");
	Sleep(50);
	printf("��");
	Sleep(50);
	printf("��\n\n");
	Sleep(500);
}
