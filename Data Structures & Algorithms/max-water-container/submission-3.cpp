class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size()-1;
        int left=0, right= n;
        int res= 0;
        while (left<=right){
            int min_side= min(heights[left], heights[right]);
            int dist= right-left;
            res= max(res, dist*min_side);
            if (heights[left]<heights[right])
                left++;
            else 
                right--;
        }
        return res;
    }
};
