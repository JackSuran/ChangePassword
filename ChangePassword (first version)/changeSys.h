#ifndef CHANGESYS_H
#define CHANGESYS_H

#include<vector>
using namespace std;

class ChangeSys
{
public:
    //��ĳ�ʼ��
    ChangeSys();

    //��ȡ����
    void LoadData();

    //�����������
    void CreatePwd();

    //�����������
    void SavePwd();

    //��������
    void DoChange();

    //��������
    void Save();

    //����
    ~ChangeSys();

// private:
    int m_Pwd;

    int m_Index;

    vector<int> m_Vec;

};

#endif //CHANGESYS_H