class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> mp;
     
        for (int i = 0; i < position.size(); i++) {
            mp[position[i]] = speed[i];
        }
        
        stack<double> st;
     
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            double time = (double)(target - it->first) / it->second;
            
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        
        return st.size();
    }
};