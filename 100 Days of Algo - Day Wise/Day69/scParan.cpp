class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);
        for(int i=0;i<S.length();i++){
            if(S[i]=='(')
                st.push(0);
            else{
                int v = st.top();
                st.pop();
                int w = st.top();
                st.pop();
                st.push(w+max(2*v,1));
            }
        }
        return st.top();
    }
};