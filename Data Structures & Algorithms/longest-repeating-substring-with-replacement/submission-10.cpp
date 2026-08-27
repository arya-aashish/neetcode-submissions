class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        for (char ch='A'; ch<='Z'; ch++){
             int l=0; int used_k=0;
            for (int r=0; r<s.length(); r++){

                if (s[r]!=ch)
                    used_k++;

                while (used_k>k){
                    if(s[l]!=ch)
                        used_k--;
                    l++;
                }
                
                res=max(res, r-l+1);
            }
                
        }
        return res;
    }
};
