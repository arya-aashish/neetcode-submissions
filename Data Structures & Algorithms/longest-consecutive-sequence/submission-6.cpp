class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s; 
        if (nums.size()==0)
            return 0;
        for (int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        
        int res=0;
        for (auto it= s.begin(); it!=s.end(); it++){
            int tempres=0;
            if (s.find((*it)-1)==s.end()){
                int currentnum= *it;
                tempres=1;
                while (s.find(currentnum+1)!=s.end()){
                    tempres++;
                    currentnum++;
                }
                res=max(tempres,res);
            }
        }
        return res;
    }
};
