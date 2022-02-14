#include"changeSys.h"
#include<iostream>
#include<ctime>

int main()
{
    srand((unsigned int)time(NULL));

    system("title 自动修改密码程序");

    //实例化
    ChangeSys c;

    //执行更改,需要搭配taskschd.msc并选取“以最高权限打开”使用
    c.DoChange();

    //test code
    // std::cout << "执行完毕 ";
    // std::cout << "此时的索引为："<<c.m_Index-1<<endl;
    // std::cout << "下次的密码为："<<c.m_Pwd;

    system("pause");

    return 0;
}