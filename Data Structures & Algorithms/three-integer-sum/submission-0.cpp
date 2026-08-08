class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0, left=i+1, right= nums.size()-1;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        while (i<nums.size()-2)
        {
            while(left<right){
                if (nums[i]+nums[left]+nums[right]==0)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        res.push_back(temp);
                        left++;
                        right--;
                    }
                else if (nums[i]+nums[left]+nums[right]<0)
                    left++;
                else if (nums[i]+nums[left]+nums[right]>0)
                    right--;
            }
            i++;
            left=i+1;
            right=nums.size()-1;
        }
  
        sort(res.begin(), res.end());
        auto last= unique(res.begin(), res.end());

        res.erase(last, res.end());

        return res;

    }
};
