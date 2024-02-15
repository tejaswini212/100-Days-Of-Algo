class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rotten;
        int fresh = 0;
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    rotten.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        while(!rotten.empty())
        {
            int n = rotten.size();
            for(int i=0;i<n;i++)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                if(x>0 && grid[x-1][y]==1)
                {
                    grid[x-1][y] = 2;
                    fresh--;
                    rotten.push({x-1,y});
                }
                if(y>0 && grid[x][y-1]==1)
                {
                    grid[x][y-1] = 2;
                    fresh--;
                    rotten.push({x,y-1});
                }
                if(x<r-1 && grid[x+1][y]==1)
                {
                    grid[x+1][y] = 2;
                    fresh--;
                    rotten.push({x+1,y});
                }
                if(y<c-1 && grid[x][y+1]==1)
                {
                    grid[x][y+1] = 2;
                    fresh--;
                    rotten.push({x,y+1});
                }
            }
            if(!rotten.empty())
                ans++;
        }
        return !fresh ?ans:-1; 
    }
};