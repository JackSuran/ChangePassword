#include"changeSys.h"
#include<iostream>
#include<ctime>

int main()
{
    srand((unsigned int)time(NULL));

    system("title �Զ��޸��������");

    //ʵ����
    ChangeSys c;

    //ִ�и���,��Ҫ����taskschd.msc��ѡȡ�������Ȩ�޴򿪡�ʹ��
    c.DoChange();

    //test code
    // std::cout << "ִ����� ";
    // std::cout << "��ʱ������Ϊ��"<<c.m_Index-1<<endl;
    // std::cout << "�´ε�����Ϊ��"<<c.m_Pwd;

    system("pause");

    return 0;
}