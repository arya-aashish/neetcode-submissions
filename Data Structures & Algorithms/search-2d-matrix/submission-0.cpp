class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        cout<<m<<" "<<n;
        for (int i=0; i<m; i++){
            int l=0, h=n-1;
            while (l<=h){
                int mid= l+(h-l)/2;
                if (matrix[i][mid]==target)
                return true;
                else if (matrix[i][mid]>target)
                    h=mid-1;
                else 
                    l=mid+1;
            }
        }
        return false;
    }
};
