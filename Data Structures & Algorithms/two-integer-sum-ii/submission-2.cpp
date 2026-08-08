class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right= numbers.size()-1;
      
        vector<int> sol;
        while (left<right){
            int sum= numbers[left]+numbers[right];
            if (sum==target)
                break;
            
            if (sum>target)
                right--;
            else if (sum<target)
                left++;
        }
        sol.push_back(left+1);
        sol.push_back(right+1);
        return sol;
    }
};
