//Count of Number in range with unique digits(or no repeated digits)

#include <iostream>
using namespace std;

void countD(int l,int r){
    int count=0;
    
    for(int i=l;i<=r;++i){
        int num=i;
        bool visited[10]={false};
        while(num){
    if(visited[num%10]){
       break; 
    }
    else{
    visited[num%10]=true;
    num=num/10;
    }
}
if(num==0){
    count++;
}
}
cout<<count;
}


int main() {
	int l=11,r=15;
	countD(l,r);
	
	return 0;
}