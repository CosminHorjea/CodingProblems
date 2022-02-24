#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        set<char> accepted;
        map<char,int> freq;
        for(char c : s1){
            accepted.insert(c);
            freq[c]++;
        }
        map<char,int> curr;
        queue<char> seen;
        for(int i = 0; i<s2.size();i++){
            if(accepted.find(s2[i]) == accepted.end()){
                curr.clear();
                seen={};
            }else{
                curr[s2[i]]++;
                if(curr == freq){
                    return true;
                }
                while(curr[s2[i]]>freq[s2[i]]){
                    curr[seen.front()]--;
                    seen.pop();
                }
                if(curr == freq){
                    return true;
                }
                seen.push(s2[i]);
            }
        }
        if(curr == freq){
            return true;
        }
        return false;

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(pair<int,int> dir: dirs){
                int new_x = curr.first  + dir.first;
                int new_y = curr.second + dir.second;

                if(new_x >= 0 && new_x <m && new_y>=0 && new_y < n){
                    if(image[new_x][new_y] == startColor){
                        image[new_x][new_y] = newColor;
                        q.push({new_x,new_y});
                    }
                }

            }
        }
        return image;

    }
    int getArea(vector<vector<int>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=-1;
        int area = 1;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(pair<int,int> dir: dirs){
                int new_x = curr.first  + dir.first;
                int new_y = curr.second + dir.second;

                if(new_x >= 0 && new_x <m && new_y>=0 && new_y < n){
                    if(grid[new_x][new_y] == 1){
                        grid[new_x][new_y] = -1;
                        q.push({new_x,new_y});
                        area++;
                    }
                }

            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea,getArea(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};

int main(){
    Solution p;
    vector<vector<int>> aux =  {{1,1,1},{1,1,0},{1,0,1}};
    for(vector<int> i : p.floodFill(aux,1,1,2)){
        for(int c : i){
            cout<<c<<" ";
        }
        cout<<endl;

    }

}