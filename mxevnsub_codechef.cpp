#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,s=0,f;
	    cin>>n;
	    if(n%4 == 0)
	    {
	        cout<<n<<endl;
	    }
	    else if((n+1)%4==0)
	    {
	        cout<<n<<endl;
	        
	    }
	    else 
	    {
	        cout<<n-1<<endl;
	    }
	}
	return 0;
}
