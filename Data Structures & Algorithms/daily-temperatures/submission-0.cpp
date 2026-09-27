class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; 
        vector<int> res(temperatures.size(), 0);
        
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                int prevIndex = st.top().second;
                res[prevIndex] = i - prevIndex;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        
        return res;
    }
};