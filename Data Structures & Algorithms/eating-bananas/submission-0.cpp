class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     int low=1, high= *max_element(piles.begin(), piles.end());
      int fes=0; int res=INT_MAX;

      while (low<=high){
       int mid=low+ (high-low)/2;
        long long temphr=0;
        for (int i=0; i<piles.size(); i++){
            temphr+= (piles[i]+mid-1)/mid;
            }
        if (temphr<=h){
            res= min(mid, res);
            high=mid-1;
        }else
            low=mid+1;
      } 
      return res;
    }
};
