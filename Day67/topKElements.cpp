class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        vector<string> res;
        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        multimap<int,string,greater<int>> mm;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
            mm.insert({itr->second,itr->first});
        for(auto itr=mm.begin();itr!=mm.end();itr++){
            if(k==0)
                break;
            res.push_back(itr->second);
            k--;
        }
        return res;
    }
};