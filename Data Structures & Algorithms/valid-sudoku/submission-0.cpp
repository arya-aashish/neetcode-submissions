class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9];
        bool cols[9][9];
        bool box[9][9];

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                int cbox= 3*(i/3)+(j/3);
                int val= board[i][j]-'1';
                if (board[i][j]=='.')
                continue;

                if (rows[i][val]||cols[j][val]||box[cbox][val])
                    return false;
                
                rows[i][val]=true;
                cols[j][val]=true;
                box[cbox][val]=true;
            }
        }
        return true;
    }
};
