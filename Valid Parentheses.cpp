class Solution {
public:

    bool left(char c){
        if(c=='(' || c=='{' || c=='[' ){
            return true;
        }
        else return false;
    }

    bool right(char c){
        if(c==')' || c=='}' || c==']') return true;
        else return false;
    }

    bool isValid(string s) {
        int len = s.size();
        stack<char> st;
        for( int i=0;i<len;i++ ){
            if(left(s[i])){
                st.push(s[i]);
            }
            else if(right(s[i])){
                if( st.empty() ){
                    //cout<<"~~~"<<endl;
                    return false;
                }

                char ch = st.top();
                st.pop();
                if(!( (ch=='('&&s[i]==')') || (ch=='{'&&s[i]=='}') || (ch=='['&&s[i]==']') ) ){
                    //cout<<"~~~"<<ch<<s[i]<<endl;
                    return false;
                }

            }
        }
        //cout<<"~~~"<<endl;
        return st.empty();
    }
};