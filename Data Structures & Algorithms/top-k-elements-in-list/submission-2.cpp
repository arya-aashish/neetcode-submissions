class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> mp;

        int n=nums.size();
        for (int i=0; i<n; i++){
            if (mp.find(nums[i])->second!=0)
                mp[nums[i]]++;
            else
                mp[nums[i]]=1;                
        }
        auto it= mp.begin();
        vector<int> res;
        int lmax=0;
        auto track=mp.begin();
        while (k>0){
            if (it->second>lmax){
                lmax= it->second;
                track=it;
            }

            it++;
            if (it==mp.end()){
                k--;
                res.push_back(track->first);
                lmax=0;
                mp.erase(track);
                it=mp.begin();
            }
        }
        return res;
    }
};
