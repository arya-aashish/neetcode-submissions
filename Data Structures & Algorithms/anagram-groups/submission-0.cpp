class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <vector<int>, vector<string>>temp;

        for (string s: strs){
            vector<int> count(26,0);
            for (char ch: s){
                count[ch-'a']++;
            }
            temp[count].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it= temp.begin(); it!=temp.end(); it++)
        res.push_back(it->second);

         return res;
    }
   
};
