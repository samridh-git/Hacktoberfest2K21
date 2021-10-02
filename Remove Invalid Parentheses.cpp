class Solution {
public:
    unordered_set<string> st;
    set<tuple<int,int,string>> mp;
    
    bool check(string& s){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') c++;
            else if(s[i]==')'){
                c--;
                if(c<0) return 0;
            }
        }
        return c==0;
    }
    
    void ans(string& s,string t,int n,int cs,int cc){
        if(n>=s.size()){
            if(cs==0 && cc==0 && check(t)){
                st.insert(t);
            }
            return;
        }
        if(mp.find({cs,cc,t})!=mp.end()) return;
        else mp.insert({cs,cc,t});
        if(cs==0 && cc==0){
            t+=s.substr(n,s.size()-n);
            if(check(t)) st.insert(t);
            return;
        }
        if(s[n]=='('){
            if(cs>0)    ans(s,t,n+1,cs-1,cc);
            ans(s,t+'(',n+1,cs,cc);
        }
        else if(s[n]==')'){
            if(cc>0)    ans(s,t,n+1,cs,cc-1);
            ans(s,t+')',n+1,cs,cc);
        }
        else ans(s,t+s[n],n+1,cs,cc);
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
        st.clear();
        mp.clear();
        int cs=0,cc=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cs++;
            else if(s[i]==')'){
                cs--;
                if(cs<0){
                    cc++;
                    cs=0;
                }
            }
        }
        string t="";
        ans(s,t,0,cs,cc);
        vector<string> a;
        for(auto it=st.begin();it!=st.end();it++){
            a.push_back(*it);
        }
        return a;
    }
};
