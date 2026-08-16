class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> temp;
        for (int i=0; i<nums.size(); i++)
            temp.insert(nums[i]);

        if (temp.size()!=nums.size())
        return true;
        else 
        return false;
    }
};