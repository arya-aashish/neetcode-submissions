class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s;
        int res=0, maxr=0;
        if (nums.empty())
            return 0;

        for (int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        for (auto it= ++(s.begin()); it!=s.end(); it++)
            if (*it== *prev(it)+1)
                res++;
            else{
                maxr= max(res, maxr);
                res=0;
            }
      return max(res, maxr) + 1;
    }
};
