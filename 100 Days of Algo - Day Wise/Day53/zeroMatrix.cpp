#include<iostream>
#include<vector>
using namespace std;

void zeroMat(vector<vector<int>>& m){
    int x=m.size();
    int y=m[0].size();
    vector<int> flag;
    int ct=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(m[i][j]==0){
                flag.push_back(ct);
                //cout<<ct;
            }
            ct++;
        }
    }
    int n=flag.size();
    for(int i=0;i<n;i++)
    {
        int p=(flag[i])/y;
        int q=(flag[i])%y;
        for(int i=0;i<y;i++)
            m[p][i]=0;
        for(int i=0;i<x;i++)
            m[i][q]=0;
    }
    return;
}

int main()
{
    vector<vector<int>> m={{3,5,1,3},
                           {2,6,1,2},
                           {7,1,8,3}};
    int p=m.size();
    int q=m[0].size();
    zeroMat(m);
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++)
            cout<<m[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
