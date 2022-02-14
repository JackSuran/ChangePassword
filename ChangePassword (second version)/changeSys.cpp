#include"changeSys.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<Windows.h>

#define FILENAME "PASSWORD.txt"
#define PWD_INDEX "index.txt"

using namespace std;

ChangeSys::ChangeSys()
{
    this->initialize();
    this->LoadData();
}

void ChangeSys::initialize()
{
    this->m_Index=1;
    this->m_Vec.clear();
}

void ChangeSys::initIndexF()
{
    this->m_Index=1;
    ofstream ofs;
    ofs.open(PWD_INDEX,ios::out|ios::trunc);
    ofs<<this->m_Index*3+2<<endl;
    ofs.close();
}

void ChangeSys::LoadData()
{
    ifstream ifs;  
      
    ifs.open(PWD_INDEX,ios::in);
    if(!ifs.is_open())
    {
        this->initIndexF();
        ifs.close();

        ifs.open(PWD_INDEX,ios::in);
    }

    int index;
    ifs>>index;
    ifs.close();
    this->m_Index=(index - 2)/3;
   
    //如果将要溢出
    if(this->m_Index>150)
    {
        //索引初始化
        this->initialize();
    }

    //如果数据安全
    ifs.open(FILENAME,ios::in);

    if(!ifs.is_open())
    {
        ifs.close();
        this->CreatePwd();
        
        return;//执行完后数据都有所指，故return
    }

    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        ifs.close();
        this->CreatePwd();
        return;
    }
    ifs.putback(ch);


    int pwd;
    while(ifs>>pwd)
    {
        this->m_Vec.push_back(pwd);
    }

    ifs.close();

}

void ChangeSys::CreatePwd()
{
    for(int i = 0;i < 150;i++)
    {
        int pwd1 = rand() % 1000 +101;
        int pwd2 = rand() % 100 +11;
        int pwd = pwd1*pwd2;

        this->m_Vec.push_back(pwd);
    }

    this->SavePwd();
}

void ChangeSys::SavePwd()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out|ios::trunc);
    
    for(vector<int>::iterator it=m_Vec.begin();it<m_Vec.end();it++)
    {
        ofs<< *it <<endl;
    }

    ofs.close();

    this->initIndexF();
}

void ChangeSys::DoChange()
{
    char cmd1[] = "net user Administrator ";
    char *cmd = new char[strlen(cmd1) + sizeof(m_Vec[m_Index-1]) + 1];
    sprintf(cmd,"%s%d",cmd1,m_Vec[m_Index-1]);

    system(cmd);
    
    cout<<"密码已修改"<<endl;

    this->m_Index++;

    this->Save();
}   

void ChangeSys::Save()
{
    ofstream ofs;
    ofs.open(PWD_INDEX,ios::out|ios::trunc);

    ofs << this->m_Index * 3 + 2 << endl;
    ofs.close();

}

ChangeSys::~ChangeSys()
{
    this->m_Index=0;
    this->m_Vec.clear();
}
