#include"changeSys.h"
#include<iostream>
#include<ctime>

int main()
{
    srand((unsigned int)time(NULL));

    system("title �Զ��޸��������");
    system("mode con cols=50 lines=10");

    //ʵ����
    ChangeSys c;

    //ִ�и���,��Ҫ����taskschd.msc��ѡȡ�������Ȩ�޴򿪡�ʹ��
    c.DoChange();

    system("pause");

    return 0;
}