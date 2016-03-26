// 241392350_杨威 四则运算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;
int const n=10;
int const Max= 10;
enum enOp{Add,Subtract,Multiply,Divide};
int addFun(int l,int r)
{
    return l + r;
}
int subFun(int l,int r)
{
    return l - r;
}
int mulFun(int l,int r)
{
    return l * r;
}
int divFun(int l,int r)
{
    return l / r;
}
char enum2char(enOp op)
{
    switch (op)
    {
    case Add:
        return '+';
    case Subtract:
        return '-';
    case Multiply:
        return 'x';
    case Divide:
        return '/';
    }
    return ' ';
}
int myResult(int l,int r,enOp op)
{
    switch (op)
    {
    case Add:
        return addFun(l , r);
    case Subtract:
        return subFun(l , r);
    case Multiply:
        return mulFun(l , r);
    case Divide:
        return divFun(l , r);
    }
    return 0;
}
bool checkFormula(int l,int r,enOp op)
{
    switch (op)
    {
    case Add:
        return true;
    case Subtract:
    {
        if(l < r)
            return false;
        return true;
    }
    case Multiply:
        return true;
    case Divide:
    {
        if(double(l/r) != double(double(l)/double(r)))
            return false;
        return true;
    }
    }
    return false;
}
void getFormula(int* l,int*r,enOp op)
{
    for(;;)
    {
        *l = 1 + rand() % Max;
        *r = 1 + rand() % Max;
        if(checkFormula(*l,*r,op))
            break;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    int l [n];
    int r [n];
    int result[n];
    enOp oper[n];
    srand(time(NULL));
    for(int i = 0;i<n;i++)
    {
        oper[i] = enOp(rand()%4);
        getFormula(&l[i],&r [i],oper[i]);
		for(int m=0; m<i;m++){
		if(l[i]==l[m]&&r[i]==r[m]||l[i]==r[m]&&r[i]==l[m])
		{
			i--;
		}
		}
    }
    cout<<"计算题:"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<"第 "<<i+1<<" 题:";
        cout<<l[i]<<' '<<enum2char(oper[i])<<' '<<r[i]<< " = \n";
    }
	for(int j= 0;j<n;j++)
		cin>>result[j];
	for(int k = 0;k<n;k++)
	{
		if(result[k] == myResult(l[k],r[k],oper[k]))
        {
            cout<<k+1<<"正确";
        }
        else
        {
            cout<<k+1<<"错误";
        }
	}
	for(int i= 0;i<n;i++)
		cout<<i+1<<":"<<myResult(l[i],r[i],oper[i])<<" ";
    getch();
    return 0;
}

