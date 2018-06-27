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
#define Xsize 301
#define Ysize 301
string X="AACAGTTACCATCGTTGCTGAAAAAAAAAATTTTTTTTTTGGGGGGGGGGCCCCCCCCCCTTTTTTTTTTAAAAAAAAAAGGGGGGGGGGCCCCCCCCCCCCCCCCCCCCTTTTTTTTTTAAAAAAAAAAGGGGGGGGGGCCCCCCCCCCAACAGTTACCATCGTTGCTGAAAAAAAAAATTTTTTTTTTGGGGGGGGGGCCCCCCCCCCTTTTTTTTTTAAAAAAAAAAGGGGGGGGGGCCCCCCCCCCCCCCCCCCCCTTTTTTTTTTAAAAAAAAAAGGGGGGGGGGCCCCCCCCCC";
string Y="TAAGGTCATTACGTTAGCTAGGGGGGGGGGCCCCCCCCCCAAAAAAAAAACCCCCCCCCCGGGGGGGGGGCCCCCCCCCCAAAAAAAAAAGGGGGGGGGGAAAAAAAAAACCCCCCCCCCGGGGGGGGGGCCCCCCCCCCAAAAAAAAAATAAGGTCATTACGTTAGCTAGGGGGGGGGGCCCCCCCCCCAAAAAAAAAACCCCCCCCCCGGGGGGGGGGCCCCCCCCCCAAAAAAAAAAGGGGGGGGGGAAAAAAAAAACCCCCCCCCCGGGGGGGGGGCCCCCCCCCCAAAAAAAAAA";


int min(int x,int y,int z){
    int min=x>y?y:x;
    return min>z?z:min;
}
int opt(int i,int j,string X, string Y,int result[Xsize][Ysize]){
    if(result[i][j]!=-1){
        return result[i][j];
    }
    int penalty=0;
    if(i==X.size()) return 2*(Y.size()-j);
    else if(j==Y.size())return 2*(X.size()-i);
    else
    {
        if(X.at(i)==Y.at(j))
            penalty=0;
        else
            penalty=1;
        result[i][j]=min(opt(i+1,j+1,X,Y,result)+penalty,opt(i,j+1,X,Y,result)+2,opt(i+1,j,X,Y,result)+2);
    }
}


int main(){
    DWORD start_time = GetTickCount(); //开始计时
    int result[Xsize][Ysize]={-1};
    memset(result, -1, sizeof(result));
    //初始化gap对应的行和列

    for (int i = Y.size(); i >=0 ; i--) {
        result[X.size()][i]=2*(Y.size()-i);
    }
    for (int j = X.size(); j >=0 ; j--) {
        result[j][Y.size()]=2*(X.size()-j);
    }

    opt(0, 0, X, Y, result);
    DWORD end_time = GetTickCount(); //结束计时
    cout << "The run time is:" << (end_time - start_time) << "ms!" << endl; //输出时间
    return 0;
}