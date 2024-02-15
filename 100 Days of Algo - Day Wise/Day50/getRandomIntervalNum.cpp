#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

int getRandomNum(vector<vector<int>>& interval){
    int num;
    int totalNum=0;
    int randomNumber;
    int currentRange;
    for(int i=0;i<interval.size();i++){
        totalNum+=interval[i][1]-interval[i][0]+1;
    }
    srand(time(0));
    randomNumber = rand() % (totalNum);
    cout<<randomNumber<<" ";
    for(int i=0;i<interval.size();i++){
        currentRange = interval[i][1]-interval[i][0]+1;
        if(randomNumber<currentRange){
            num = interval[i][0] + randomNumber;
            break;
        }
        else
            randomNumber = randomNumber - currentRange;
    }
    return num;
}

int main(){
    vector<vector<int>> interval={{12,15},{1,5},{21,30},{55,60}};
    cout<<getRandomNum(interval);
    return 0;
}
