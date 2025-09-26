#include <iostream>
#include <Windows.h>
#include "Meet.h"
#include "Player.h"
#include "IIIntro.h"
#include "GameManager.h"
#include <random>

/*                         
                                                         ███╗   ██╗███████╗██╗  ██╗██████╗  █████╗  ██████╗███████╗    ██╗   ██╗███████╗
                                                         ████╗  ██║██╔════╝ ██╗██╗ ██╔══██╗██╔══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝
                                                         ██╔██╗ ██║█████╗    ███║  ██████╔╝███████║██║     █████╗      ██║   ██║███████╗
                                                         ██║╚██╗██║██╔══╝   ██═██║ ██╔═══╝ ██╔══██║██║     ██╔══╝      ██║   ██║ ╚═══██║
                                                         ██║ ╚████║███████╗██║  ██║██║     ██║  ██║╚██████╗███████╗     ╚████╔╝ ███████║
                                                         ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝      ╚═══╝  ╚══════╝
*/
int main()
{
    srand(time(0));
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

