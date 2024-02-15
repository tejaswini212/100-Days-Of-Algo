#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  int n=scores.size();
	vector<int> rew(n,1);
	for(int i=1;i<n;i++){
		if(scores[i]>scores[i-1])
			rew[i]=rew[i-1]+1;
	}
	for(int i=n-2;i>=0;i--){
		if(scores[i]>scores[i+1])
			rew[i]=max(rew[i],rew[i+1]+1);
	}
  return accumulate(rew.begin(),rew.end(),0);
}
