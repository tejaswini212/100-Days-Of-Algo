class Solution {
public:
    bool checkPowersOfThree(int num) {
        if(num==1)
            return true;
        int n;
        int ct=0;
        while(num>=0){
            n = (int)(log(num)/log(3));
            cout<<num<<" "<<ct<<" "<<n<<"\n";
            if(ct==n || num==2)
                return false;
            if(ct!=n && (pow(3,n)==num || pow(3,n)+1==num))
                return true;
            num = num-pow(3,n);
            ct = n;            
        }
        cout<<"\n";
        return false;
    }
};