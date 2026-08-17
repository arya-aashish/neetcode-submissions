class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> temp;
        vector <int> res;
        int n= nums.size();
        for (int i=0; i<n; i++)
            temp[nums[i]]=i;

        for (int i=0; i<n; i++)
            if (temp.find(target-nums[i])!=temp.end()&& temp[target-nums[i]]!=i)
                {
                    res.push_back(i);
                    res.push_back (temp[target-nums[i]]);
                    return res;
                }
            return res;
    }
};
