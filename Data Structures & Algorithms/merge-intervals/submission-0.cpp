bool mySort(vector <int> &a, vector <int> &b){
    return a[0]<b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end(), mySort);

        int res=0;
        for (int i=1; i<n; i++){
            if (intervals[res][1]>=intervals[i][0]){
                intervals[res][0]= min(intervals[res][0], intervals[i][0]);
                intervals[res][1]= max(intervals[res][1], intervals[i][1]);
            }
            else{
                res++;
                intervals[res]=intervals[i];
            }
        }
        intervals.resize(res+1);
        return intervals;
    }
};
