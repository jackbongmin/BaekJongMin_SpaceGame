#include "Ending.h"
#include <Windows.h>
#include "Player.h"

// 10�� ���� �� ���� üũ
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

// �븻����
void Ending::SurvivalEnding()
{
    Sleep(2000);
    printf(" ����� 10�ϰ� ������ �����Ͽ����ϴ�.\n\n");
    Sleep(2000);
    printf(" ������ �������� ���������忡 �����Ͽ�\n\n");
    Sleep(2000);
    printf(" ������û�� ���½��ϴ�..\n\n");
    Sleep(2500);
    printf(" ����� �����Ͽ����ϴ�.");
    Sleep(1000);
    printf("[");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("]");
    Sleep(50);
    printf("\n\n\n");
}

// ���ǿ���(�ܰ��ε��� 3�� ����, ȣ���� 80�̻���ä 3���̻� Ŀ�´����̼� ����)
void Ending::HappyEnding()
{
    Sleep(2000);
    printf(" ����� 10�ϰ� ������ �����Ͽ����ϴ�.\n\n");
    Sleep(2000);
    printf(" ������ �������� ���������忡 �����Ͽ�\n");
    Sleep(2000);
    printf(" ������û�� ���½��ϴ�..\n\n");
    Sleep(2000);
    printf(" �����Ⱓ���� �ܰ����ü�� ���� ���� ������ �Լ��Ͽ�,\n");
    Sleep(2000);
    printf(" ������û�� ���ÿ� ���ο� �������� �Բ� �ۺ��߽��ϴ�.\n\n");
    Sleep(2000);
    printf(" ���� �ܰ����ü���� ������ ������������,\n");
    Sleep(2000);
    printf(" ������ ������ ū �⿩�� �ϰ� �Ǿ����ϴ�.\n\n");
    Sleep(2500);
    printf(" ����� �����Ͽ����ϴ�.");
    Sleep(1000);
    printf("[");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("]");
    Sleep(50);
    printf("\n\n\n");
}

// ���忣��(ȣ���� 20������ä 2���̻� Ŀ�´����̼� ����)
void Ending::BadEnding()
{
    Sleep(2000);
    printf(" ����� 10�ϰ� ������ �����Ͽ����ϴ�.\n\n");
    Sleep(2000);
    printf(" �������� ���� �����忡 ��ŷ�� �Ϸ��� ����,\n");
    Sleep(2000);
    printf(" �����Ⱓ���� ������ �����״� �ܰ��������� ���ƿ�\n");
    Sleep(2000);
    printf(" ���� �������� �����ϱ� �����մϴ�.\n\n");
    Sleep(2000);
    printf(" ��ŷ ������ ���¸� �˾ƺ� �� ���� �ν�����,\n");
    Sleep(2000);
    printf(" �μ����� ������������ ���� �ٶ� �� �� �ۿ� �����ϴ�.\n\n");
    Sleep(2000);
    printf(" ������������ �ν�����,\n");
    Sleep(2000);
    printf(" ���� ����� ���� Ÿ���� �Ǿ��׿�.\n\n");
    Sleep(2500);
    printf(" ����� �������� ���߽��ϴ�.");
    Sleep(1000);
    printf("[");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf(" ");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("��");
    Sleep(50);
    printf("]");
    Sleep(50);
    printf("\n\n\n");
}
