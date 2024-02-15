class Solution {
public:
    bool isSubseq(string word,string s){
        int m=word.length();
        int n=s.length();
        int j=0;
        for(int i=0;i<n && j<m;i++)
            if(s[i]==word[j])
                j++;
        return j==m;
    }
    string findLongestWord(string s, vector<string>& d) {
        string max_str="";
        sort(d.begin(),d.end());
        for (string str: d) {
            if (isSubseq(str, s)) {
                if (str.length() > max_str.length())
                    max_str = str;
            }
        }
        return max_str;
    }
};