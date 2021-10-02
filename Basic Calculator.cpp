class Solution {
public:
    
    map<int,int> mp;
    
    int ans(string& s,int l,int r){
        for(int i=l;i<=r;i++){
            if(s[i]!=' '){
                l=i;
                break;
            }
        }
        int sum=0,in=l;
        if(s[l]=='('){
            sum=ans(s,l+1,mp[l]-1);
            in=mp[l]+1;
        }
        else{
            string a;
            for(int i=l;i<=r;i++){
                if(s[i]>='0' && s[i]<='9') a+=s[i];
                if(s[i]=='(' || s[i]=='+' || s[i]=='-') {
                    in=i;
                    break;
                }
            }
            if(a.size()>0)
            sum+=stoi(a);
        }
        for(int i=in;i<=r;i++){
            if(s[i]=='+' || s[i]=='-'){
                string a="";
                int j;
                for(j=i+1;j<=r;j++){
                    if(s[j]>='0' && s[j]<='9') a+=s[j];
                    if(s[j]=='+' || s[j]=='-'){
                        break;
                    }
                    if(s[j]=='('){
                        int x=ans(s,j+1,mp[j]-1);
                        if(s[i]=='+') sum+=x;
                        else sum-=x;
                        j=mp[j]+1;
                        break;
                    }
                }
                if(a.size()>0) {
                    if(s[i]=='+')
                        sum+=stoi(a);
                    else sum-=stoi(a);
                }
                i=j-1;
            }
        }
        return sum;
    }
    
    int calculate(string s) {
        mp.clear();
        stack<int> q;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') q.push(i);
            if(s[i]==')'){
                mp[q.top()]=i;
                q.pop();
            }
        }
        return ans(s,0,s.size()-1);
    }
};