#include"changeSys.h"
#include<iostream>
#include<ctime>

int main()
{
    srand((unsigned int)time(NULL));

    system("title 自动修改密码程序");
    system("mode con cols=50 lines=10");

    //实例化
    ChangeSys c;

    //执行更改,需要搭配taskschd.msc并选取“以最高权限打开”使用
    c.DoChange();

    system("pause");

    return 0;
}