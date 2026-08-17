class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> temp;

        if (s.length()!= t.length())
        return false;
        
        for (char x: s){
            if (temp[x]==0)
                temp[x]=1;
            else
                temp[x]++;
        }
        for (char x: t){            
                if (temp[x]==0)
                    return false;

                temp[x]--;
        }
        return true;
    }
};
