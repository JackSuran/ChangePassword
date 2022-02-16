#include"addTimer.h"
#include<iostream>

void AddTimer::doAdd()
{
    system("shutdown /a");
    system("shutdown /s /t 3600");
}

void AddTimer::doEmrAdd()
{
    system("shutdown /a");
    system("shutdown /s /t 1800");
}