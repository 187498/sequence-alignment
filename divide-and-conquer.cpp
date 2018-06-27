//
// Created by 18749 on 2018/6/17.
//
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <cstring>
#include<windows.h>

using namespace std;
string X="AACAATCGACAG";
string Y="TAAAGTCCATCG";

int min(int x,int y,int z){
    int min=x>y?y:x;
    return min>z?z:min;
}
int opt(int i,int j,string X, string Y,int key){
    int penalty=0;
    if(i==X.size()) return 2*(Y.size()-j);
    else if(j==Y.size())return 2*(X.size()-i);
    else
    {
        if(X.at(i)==Y.at(j))
            penalty=0;
        else
            penalty=1;
        key+=min(opt(i+1,j+1,X,Y,key)+penalty,opt(i,j+1,X,Y,key)+2,opt(i+1,j,X,Y,key)+2);
        return key;
    }
}


int main(){
    DWORD start_time = GetTickCount(); //开始计时

    //初始化gap对应的行和列
    int key;
    key=opt(0, 0, X, Y,0);

    DWORD end_time = GetTickCount(); //结束计时
    cout << "The run time is:" << (end_time - start_time) << "ms!" << endl; //输出时间
    cout<<key<<endl;
    return 0;
}