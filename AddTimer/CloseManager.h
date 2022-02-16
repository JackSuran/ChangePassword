#ifndef CLOSEMANAGER_H
#define CLOSEMANAGER_H

#include"Database.h"
#include"addTimer.h"

class CloseManager
{
public:
    //提示菜单信息
    void ShowMenu();

    //对选择做出反应
    void CloseSys();

    //退出系统
    void ExitSys();

private:
    Database m_Data;
    AddTimer m_Timer;

};


#endif //CLOSEMANAGER_H