class String{
public:	
	string str;
	String(string s){str = s;}
	void Erase(int i){
		int n = str.size();
		string op = "";
		for(int k=0;k<n;k++)
			if(k!=i)
				op+=str[k];
		str = op;
	}
};
int main(){
	string str; cin>>str;
	String S = String(str);
	int hash[26]={0};

	for(int i=0;i<S.str.size();i++){
		if(hash[S.str[i]-'a'] == 0)
			hash[S.str[i]-'a'] = 1;
		else{
			S.Erase(i);i--;
		}
	}
	cout<<S.str<<"\n";
}
