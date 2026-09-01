class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& ans, int delrows[], int delcols[], int new_color, int initial_color) {
        ans[sr][sc] = new_color;
        int n = ans.size();
        int m = ans[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrows[i];
            int ncol = sc + delcols[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != new_color && image[nrow][ncol] == initial_color) {
                dfs(nrow, ncol, image, ans, delrows, delcols, new_color, initial_color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrows[] = {-1,1,0,0};
        int delcols[] = {0,0,-1,1};
        dfs(sr,sc,image,ans,delrows,delcols,color, initial_color);
        return ans;
    }
};