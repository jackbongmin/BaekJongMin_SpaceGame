// BaekJongMin_SpaceGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*                         
                                                         ███╗   ██╗███████╗██╗  ██╗██████╗  █████╗  ██████╗███████╗    ██╗   ██╗███████╗
                                                         ████╗  ██║██╔════╝ ██╗██╗ ██╔══██╗██╔══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝
                                                         ██╔██╗ ██║█████╗    ███║  ██████╔╝███████║██║     █████╗      ██║   ██║███████╗
                                                         ██║╚██╗██║██╔══╝   ██═██║ ██╔═══╝ ██╔══██║██║     ██╔══╝      ██║   ██║ ╚═══██║
                                                         ██║ ╚████║███████╗██║  ██║██║     ██║  ██║╚██████╗███████╗     ╚████╔╝ ███████║
                                                         ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝      ╚═══╝  ╚══════╝
*/

#include <iostream>
#include <Windows.h>
#include "Meet.h"
#include "Player.h"
#include "IIIntro.h"
#include "GameManager.h"
#include <random>

int main()
{
    srand(time(0));
    //Player player;
    //player.PlayerStat();
    //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    IIIntro introstart;
    introstart.Intro_1();

    std::string PlayerName;
    printf("\n당신의 이름은 무엇인가요?\n");
    std::getline(std::cin, PlayerName);
    GameManager gm(PlayerName);
    introstart.Intro_2(gm.GetPlayer());
    
    gm.MainRoot();
    //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
  
    return 0;
}

