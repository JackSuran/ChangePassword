#ifndef DATABASE_H
#define DATABASE_H

#include<vector>

class Database
{
public:
    Database()
    {
        this->m_Index=1;
        this->m_EmrTime=3;
        this->m_Certificate.clear();
        this->m_HaveEmr=false;
        this->LoadData();
    }

    //��ȡ����
    void LoadData();

    //����ƾ֤��д��
    void CreateCert();

    //�ṩӦ������
    int GiveEmrTime();

    //�ṩƾ֤��
    int GiveCert();

    //�Ƿ��н�������
    bool Is_Having();

    //���Ĵ���
    void ChangeEmrTime();

    //���ô���
    void ResetEmrTime();

    //��������
    void ResetIndex();

    //��������
    void IndexPlus();

    //��������
    void Save();

    ~Database()
    {
        this->m_Index=0;
        this->m_EmrTime=3;
        this->m_Certificate.clear();
        this->m_HaveEmr=false;
    }

private:
    int m_Index; //ƾ֤����
    int m_EmrTime; //Ӧ����ʱ����
    std::vector<int> m_Certificate; //ƾ֤
    bool m_HaveEmr;//�Ƿ��л���

};

#endif //DATABASE_H