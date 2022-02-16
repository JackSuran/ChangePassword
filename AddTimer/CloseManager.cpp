#include"CloseManager.h"
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

void CloseManager::ShowMenu()
{
    cout<<"欢迎来到加时小程序 (。?ω?。)"<<endl;
    cout<<"1.普通加时\n";
    cout<<"2.应急加时\n";
    cout<<"3.管理模式\n";
    cout<<"请输入你的选择：";

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
            cout<<"请输入加时凭证(退出请按0)"<<endl;
            int pwd;
            cin>>pwd;

            if(pwd==m_Data.GiveCert())
            {
                this->m_Timer.doAdd();
                cout<<"已设置为1小时后关闭"<<endl;
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
                cout<<"凭证输入错误"<<endl;
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
            cout<<"应急加时机会已耗尽,3秒后自动退出"<<endl;
            Sleep(3000);
            this->ExitSys();
        }

        while(true)
        {
            num1 = rand()%100 + 1;
            num2 = rand()%100 + 1;
            cout<<"\n你还有<"<<this->m_Data.GiveEmrTime()<<">次应急加时机会"<<endl;
            cout<<"请输入正确答案获取紧急加时："
                <<num1<<" × "<<num2<<" = ";
            cin>>asd;

            if(asd==num1*num2)
            {
                this->m_Timer.doEmrAdd();
                this->m_Data.ChangeEmrTime();
                cout<<"\n应急加时成功"<<endl;
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
                cout<<"验证答案输入错误"<<endl;
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
        cout<<"输入错误，即将退出程序"<<endl;
        Sleep(1000);
        this->ExitSys();
    }
    
}

void CloseManager::ExitSys()
{
    exit(0);
}