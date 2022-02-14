#ifndef CHANGESYS_H
#define CHANGESYS_H

#include<vector>
using namespace std;

class ChangeSys
{
public:
    //类的初始化
    ChangeSys();

    //读取数据
    void LoadData();

    //创建随机密码
    void CreatePwd();

    //保存随机密码
    void SavePwd();

    //更改密码
    void DoChange();

    //储存索引
    void Save();

    //析构
    ~ChangeSys();

// private:
    int m_Pwd;

    int m_Index;

    vector<int> m_Vec;

};

#endif //CHANGESYS_H