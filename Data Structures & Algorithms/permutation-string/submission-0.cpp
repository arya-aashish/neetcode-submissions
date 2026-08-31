class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length()> s2.length()){
            return false;
        }
        vector<int> fs1(26,0);
        vector<int> fs2(26,0);

        for (char ch: s1){
            int index= (int)(ch)-(int)'a';
            fs1[index]+=1;
        }

        for (int i=0; i<s1.length(); i++){
            int index= (int)s2[i]-(int)'a';
            fs2[index]+=1;
        }

        int l=0, matches=0;
        for (int i=0; i<26; i++)
            if (fs1[i]==fs2[i])
                matches++;

        for (int r=s1.length(); r<s2.length(); r++){
            if (matches==26)
                return true;

            int index= (int)(s2[r])-(int)'a';
            fs2[index]+=1;

            if (fs2[index]==fs1[index])
                matches++;
            else if (fs2[index]-1==fs1[index])
                matches--;

            index= (int)(s2[l])-(int)'a';
            fs2[index]-=1;

            if (fs2[index]==fs1[index])
                matches++;
            else if (fs2[index]+1==fs1[index])
                matches--;
            
            l++;
        }
        return matches==26;
        
    }
};
