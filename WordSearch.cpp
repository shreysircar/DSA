    #include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int index) {
        int m = board.size(), n = board[0].size();

        // Base case: entire word matched
        if (index == word.size()) return true;

        // Bounds check and character match
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[index])
            return false;

        char temp = board[r][c]; // Save the current character
        board[r][c] = '#';       // Mark visited

        // Explore all 4 directions
        bool found = dfs(board, r+1, c, word, index+1) ||
                     dfs(board, r-1, c, word, index+1) ||
                     dfs(board, r, c+1, word, index+1) ||
                     dfs(board, r, c-1, word, index+1);

        board[r][c] = temp; // Backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(board, i, j, word, 0)) return true;

        return false;
    }
        
int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
bool check=exist(board,"aab");
if(check==1){
    cout<<"word exists";
}
else{
    cout<<"word does'nt exist";
}

return 0;}

