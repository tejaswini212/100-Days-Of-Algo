class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        for(auto m:moves){
            if(m=='U')
                y+=1;
            else if(m=='D')
                y-=1;
            else if(m=='L')
                x-=1;
            else
                x+=1;
        }
        return (x==0 && y==0);
    }
};