#include"CloseManager.h"
#include<iostream>
#include<ctime>

int main()
{
    system("title ��ʱС����");
    system("mode con cols=50 lines=10");
    srand((unsigned int)time(NULL));

    CloseManager c;
    c.ShowMenu();
    c.CloseSys();

    return 0;
}