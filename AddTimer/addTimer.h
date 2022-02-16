#ifndef ADDTIMER_H
#define ADDTIMER_H

class AddTimer
{
public:
    AddTimer(){}
    
    //执行一般加时
    void doAdd();

    //执行应急加时
    void doEmrAdd();
    
    ~AddTimer(){}
};


#endif //ADDTIMER_H