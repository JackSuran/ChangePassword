#ifndef CLOSEMANAGER_H
#define CLOSEMANAGER_H

#include"Database.h"
#include"addTimer.h"

class CloseManager
{
public:
    //��ʾ�˵���Ϣ
    void ShowMenu();

    //��ѡ��������Ӧ
    void CloseSys();

    //�˳�ϵͳ
    void ExitSys();

private:
    Database m_Data;
    AddTimer m_Timer;

};


#endif //CLOSEMANAGER_H