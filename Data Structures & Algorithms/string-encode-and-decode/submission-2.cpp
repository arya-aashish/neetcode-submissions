class Solution {
public:

    string encode(vector<string>& strs) {
        string str;
        for (string s: strs){
            str+= to_string(s.length())+'#'+s;        
        }
        return str;

    }

    vector<string> decode(string s) {
        vector <string> str;

        int i= 0;
        while (i<s.length()){
            int loc=s.find('#',i);
            int len= stoi(s.substr(i, loc-i));

          string temp= s.substr(loc+1, len);
          str.push_back(temp);
          i=loc+1+len;
        }
        
        return str;
    }
};
