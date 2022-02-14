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
    this->m_Index=1;
    this->m_Pwd=0;
    this->m_Vec.clear();
    this->LoadData();
}

void ChangeSys::LoadData()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    if(!ifs.is_open())
    {
        cout<<" 未打开 ";
        this->CreatePwd();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        cout<<" 密码为空 ";
        this->CreatePwd();
        return;
    }
    ifs.putback(ch);

    // test code
    // cout<<"准备读取数据"<<endl;

    int pwd;
    while(ifs>>pwd)
    {
        this->m_Vec.push_back(pwd);
    }

    ifs.close();

    int index;
    ifs.open(PWD_INDEX,ios::in);
    if(!ifs.is_open())
    {
        // cout<<"索引丢失"<<endl;
        ifs.close();
        return;
    }
    ifs>>index;
    ifs.close();
    this->m_Index=(index - 2)/3;
    this->m_Pwd=this->m_Vec[this->m_Index];
    
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

    ofs.open(PWD_INDEX,ios::out|ios::trunc);
    ofs<<this->m_Index*3+2<<endl;
    ofs.close();
}

void ChangeSys::DoChange()
{
    char cmd1[] = "net user Administrator ";
    char *cmd = new char[strlen(cmd1) + sizeof(m_Vec[m_Index-1]) + 1];
    sprintf(cmd,"%s%d",cmd1,m_Vec[m_Index-1]);

    system(cmd);
    
    // cout<<"密码已修改"<<endl;
    // cout<<"输出结果为："<<cmd<<endl;

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
    this->m_Pwd=0;
    this->m_Vec.clear();
}
