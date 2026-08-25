class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> helper(2001,0);
        
        for (int i=0; i<nums.size(); i++){
            helper[nums[i]+1000]++;
        }
        vector <int> res;
        int lmax=0;
        while(k>0){
            int track=0;
            for (int i=0; i<2001; i++)
                if (lmax<helper[i]){
                    lmax=helper[i];
                    track=i;
                }
            res.push_back(track-1000);
            helper[track]=0;
            track=0;
            lmax=0;
            k--;
        }
        return res;
        
    }
};
