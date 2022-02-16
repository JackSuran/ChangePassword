#include"Database.h"
#include<fstream>

#define CERTIFICA "COT_certifica.txt"
#define EMERGENCY_TIME "COT_emer.txt"
#define COT_INDEX "COT_index.txt"

using namespace std;

void Database::LoadData()
{
    ifstream ifs;

    ifs.open(COT_INDEX,ios::in);
    if(!ifs.is_open())
    {
        this->CreateCert();
        ifs.close();

        ifs.open(COT_INDEX,ios::in);
    }

    int index;
    ifs>>index;
    ifs.close();
    this->m_Index=(index-7)/3;
   
    //如果将要溢出
    if(this->m_Index>300)
    {
        //索引初始化
        this->m_Index=1;
    }
    
    ifs.open(CERTIFICA,ios::in);
    if(!ifs.is_open())
    {
        ifs.close();

        this->CreateCert();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        ifs.close();

        this->CreateCert();
        return;
    }
    ifs.putback(ch);

    int pwd;
    while(ifs>>pwd)
    {
        this->m_Certificate.push_back(pwd);
    }
    ifs.close();

    int choiceTime;
    ifs.open(EMERGENCY_TIME,ios::in);
    ifs>>choiceTime;
    this->m_EmrTime=choiceTime;
    if(choiceTime!=0)
    {
        this->m_HaveEmr=true;
    }
    ifs.close();
    
}

void Database::CreateCert()
{
    for(int i = 0;i < 300;i++)
    {
        int pwd1 = rand() % 1000 +101;
        int pwd2 = rand() % 100 +11;
        int pwd = pwd1*pwd2;

        this->m_Certificate.push_back(pwd);
    }

    ofstream ofs;
    ofs.open(CERTIFICA,ios::out|ios::trunc);
    
    for(vector<int>::iterator it=m_Certificate.begin();it<m_Certificate.end();it++)
    {
        ofs<< *it <<endl;
    }
    ofs.close();

    
    ofs.open(EMERGENCY_TIME,ios::out|ios::trunc);
    ofs<<this->m_EmrTime<<endl;
    ofs.close();
    this->m_HaveEmr=true;

    ofs.open(COT_INDEX,ios::out|ios::trunc);
    ofs<<this->m_Index*3+7<<endl;

}

int Database::GiveEmrTime()
{
    return this->m_EmrTime;
}

int Database::GiveCert()
{
    return this->m_Certificate[this->m_Index-1];
}

void Database::ChangeEmrTime()
{
    this->m_EmrTime--;
}

bool Database::Is_Having()
{
    return this->m_HaveEmr;
}

void Database::ResetEmrTime()
{
    this->m_EmrTime=3;
    this->m_HaveEmr=true;
}

void Database::ResetIndex()
{
    this->m_Index=1;
}

void Database::IndexPlus()
{
    this->m_Index++;
}

void Database::Save()
{
    ofstream ofs;
    ofs.open(COT_INDEX,ios::out|ios::trunc);
    ofs<<this->m_Index*3+7;
    ofs.close();

    ofs.open(EMERGENCY_TIME,ios::out|ios::out);
    ofs<<this->m_EmrTime;
    ofs.close();

}