class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subs;
        int l=0, r=0; size_t res=0;
        while(r<s.length()){
            if (subs.find(s[r])==string::npos){
                subs+=s[r];
                res= max(res, subs.length());
                r++;
            }else{
                subs=subs.erase(0,1);
                l++;
            }
        }
        return res;
    }
};
