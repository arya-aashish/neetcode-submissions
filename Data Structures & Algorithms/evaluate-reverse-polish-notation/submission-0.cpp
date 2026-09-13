int eva(int a, int b, string op){
    if (op=="+")    return b+a;
    else if (op=="*") return b*a;
    else if (op=="-") return b-a;
    else {
        if (a==0)  
        return -1;
        return b/a;
    }
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        if (tokens.size()==0)  return 0;
        
        for (int i=0; i< tokens.size(); i++){
            string ch= tokens[i];
            if (ch=="+" || ch=="-" || ch=="*" || ch=="/"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int temp= eva(num1, num2, tokens[i]);
                st.push(temp);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
