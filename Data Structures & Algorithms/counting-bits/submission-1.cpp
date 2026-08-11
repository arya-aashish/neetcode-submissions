class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i=0; i<=n; i++)
        {
            int temp=i;
            int count;
            while (temp>0){
                if (temp&1)
                    count++;
                temp/=2;
            }
            res.push_back(count);
            count=0;
        }
        return res;
        
    }
};
