class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int leftmax= height[0], rightmax=height[right];
        int res=0;
        while(left<right){
            if (leftmax>rightmax){
                res+= min(leftmax, rightmax)-height[right];

                right--;
                if (right>=0)
                    rightmax= max(rightmax,height[right]);
                
            }
                 else {
                res+= min(leftmax, rightmax)-height[left];

                left++;

                if (left>=0)
                    leftmax= max(leftmax,height[left]);

            }
        }        
        return res;
    }
};
