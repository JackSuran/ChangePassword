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

    //读取数据
    void LoadData();

    //创建凭证并写入
    void CreateCert();

    //提供应急次数
    int GiveEmrTime();

    //提供凭证码
    int GiveCert();

    //是否有紧急次数
    bool Is_Having();

    //更改次数
    void ChangeEmrTime();

    //重置次数
    void ResetEmrTime();

    //重置索引
    void ResetIndex();

    //索引迭代
    void IndexPlus();

    //保存数据
    void Save();

    ~Database()
    {
        this->m_Index=0;
        this->m_EmrTime=3;
        this->m_Certificate.clear();
        this->m_HaveEmr=false;
    }

private:
    int m_Index; //凭证索引
    int m_EmrTime; //应急加时次数
    std::vector<int> m_Certificate; //凭证
    bool m_HaveEmr;//是否还有机会

};

#endif //DATABASE_H