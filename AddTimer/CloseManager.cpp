#include"CloseManager.h"
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

void CloseManager::ShowMenu()
{
    cout<<"��ӭ������ʱС���� (��?��?��)"<<endl;
    cout<<"1.��ͨ��ʱ\n";
    cout<<"2.Ӧ����ʱ\n";
    cout<<"3.����ģʽ\n";
    cout<<"���������ѡ��";

    //this->CloseSys();
}

void CloseManager::CloseSys()
{
    int choice=0;
    cin>>choice;

    if(choice==1)
    {
        while (true)
        {
            cout<<"�������ʱƾ֤(�˳��밴0)"<<endl;
            int pwd;
            cin>>pwd;

            if(pwd==m_Data.GiveCert())
            {
                this->m_Timer.doAdd();
                cout<<"������Ϊ1Сʱ��ر�"<<endl;
                this->m_Data.IndexPlus();
                this->m_Data.Save();
                system("pause");
                this->ExitSys();
            }
            else if (pwd == 0)
            {
                this->ExitSys();
            }            
            else
            {
                cout<<"ƾ֤�������"<<endl;
                Sleep(1000);
                //system("cls");
                //this->ShowMenu();
                this->ExitSys();
            }
        }
        
        
    }
    else if (choice==2)
    {
        int num1,num2,asd;

        if(!this->m_Data.Is_Having())
        {
            cout<<"Ӧ����ʱ�����Ѻľ�,3����Զ��˳�"<<endl;
            Sleep(3000);
            this->ExitSys();
        }

        while(true)
        {
            num1 = rand()%100 + 1;
            num2 = rand()%100 + 1;
            cout<<"\n�㻹��<"<<this->m_Data.GiveEmrTime()<<">��Ӧ����ʱ����"<<endl;
            cout<<"��������ȷ�𰸻�ȡ������ʱ��"
                <<num1<<" �� "<<num2<<" = ";
            cin>>asd;

            if(asd==num1*num2)
            {
                this->m_Timer.doEmrAdd();
                this->m_Data.ChangeEmrTime();
                cout<<"\nӦ����ʱ�ɹ�"<<endl;
                system("pause");
                this->m_Data.Save();
                this->ExitSys();
            }
            else if(asd==0)
            {
                this->ExitSys();
            }
            else
            {
                cout<<"��֤���������"<<endl;
                Sleep(1000);
                system("cls");
                this->ShowMenu();
            }
        }
    }
    else if(choice==3)
    {
        cout<<"Please put down the code to ensure you is the people who can manage the system"<<endl;
        string pwd;
        cin>>pwd;

        if(pwd=="hjhhjt")
        {
            system("cls");
            cout<<"1.reset the Emr_time\n"
            <<"2.STOP_THE_TIMER\n"
            <<"3.reset the Index"<<endl;

            int test;
            cout<<"Select: ";
            cin>>test;

            if(test==1)
            {
                this->m_Data.ResetEmrTime();
                this->m_Data.Save();
                cout<<"Done"<<endl;
                Sleep(1500);
                this->ExitSys();
            }
            else if(test==2)
            {
                system("shutdown /a");
                cout<<"Done"<<endl;
                Sleep(1500);
                this->ExitSys();
            }
            else if(test==3)
            {
                this->m_Data.ResetIndex();
                this->m_Data.Save();
                Sleep(1500);
                this->ExitSys();
            }
            else this->ExitSys();
            
        }
        else
        {
            for (int i=0;i<9999;i++)
            {
                cout<<"WORMING ";
            }
            Sleep(900);
            this->ExitSys();
        }


    }
    else
    {
        cout<<"������󣬼����˳�����"<<endl;
        Sleep(1000);
        this->ExitSys();
    }
    
}

void CloseManager::ExitSys()
{
    exit(0);
}