#include "Ending.h"
#include <Windows.h>

void Ending::EndingCheck(Player& Inplayer, int InDay)
{
    if (InDay >= 10 && Inplayer.GetLowAffinityCount() >= 2)
    {
        BadEnding();
    }
    else if (InDay >= 10 && Inplayer.GetHighAffinityCount() >= 3)
    {
        HappyEnding();
    }
    else if (InDay >= 10)
    {
        SurvivalEnding();
    }
}

void Ending::SurvivalEnding()
{
    Sleep(1000);
    printf("����� 10�ϰ� ������ �����Ͽ����ϴ�.\n\n");
    Sleep(1000);
    printf("������ �������� ���������忡 �����Ͽ�\n\n");
    Sleep(1000);
    printf("������û�� ���½��ϴ�..\n\n");
    Sleep(2000);
    printf("����� �����Ͽ����ϴ�.");
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
}

void Ending::HappyEnding()
{
    Sleep(1000);
    printf("����� 10�ϰ� ������ �����Ͽ����ϴ�.\n\n");
    Sleep(1000);
    printf("������ �������� ���������忡 �����Ͽ�\n");
    Sleep(1000);
    printf("������û�� ���½��ϴ�..\n\n");
    Sleep(1000);
    printf("�����Ⱓ���� �ܰ����ü�� ���� ���� ������ �Լ��Ͽ�,\n ");
    Sleep(1000);
    printf("������û�� ���ÿ� ���ο� �������� �Բ� �ۺ��߽��ϴ�.\n\n ");
    Sleep(1000);
    printf("���� �ܰ����ü���� ������ ������������,\n ");
    Sleep(1000);
    printf("������ ������ ū �⿩�� �ϰ� �Ǿ����ϴ�.\n\n ");
    Sleep(2000);
    printf("����� �����Ͽ����ϴ�.");
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
}

void Ending::BadEnding()
{
    Sleep(1000);
    printf("����� 10�ϰ� ������ �����Ͽ����ϴ�.\n\n");
    Sleep(1000);
    printf("�������� ���� �����忡 ��ŷ�� �Ϸ��� ����,\n");
    Sleep(1000);
    printf("�����Ⱓ���� ������ �����״� �ܰ��������� ���ƿ�\n");
    Sleep(1000);
    printf("���� �������� �����ϱ� �����մϴ�.\n\n");
    Sleep(1000);
    printf("��ŷ ������ ���¸� �˾ƺ� �� ���� �ν�����,\n");
    Sleep(1000);
    printf("�μ����� ������������ ���� �ٶ� �� �� �ۿ� �����ϴ�.\n\n");
    Sleep(1000);
    printf("������������ �ν�����,\n");
    Sleep(1000);
    printf("���� ����� ���� Ÿ���� �Ǿ��׿�.\n\n");
    Sleep(2000);
    printf("����� �������� ���߽��ϴ�.");
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
}
