#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str[10], temp;

    cout << "Enter 5 words: " << endl;
    for(int i = 0; i < 5; ++i)
    {
      cin>>str[i];
    }
    //BUBBLE SORT -:
    bool isSorted=false;
    int sl=(sizeof(str)/sizeof(str[0]))-1;
    while(isSorted==false){
        isSorted=true;
        
    for (int i = 0; i < sl; ++i) { 
            if (str[i] > str[i+ 1]) {
                swap(str[i],str[i+1]);      
				
				isSorted=false;
        }
    }
    sl--;  //reducing for every iteration since last element(then second last n so on)
             //  will get sorted on every iteration. this decreases the no. of iteration n optimizes a bit
    }

    cout << "In lexicographical order: " << endl;

    for(int i = 0; i < 10; ++i)
    {
       cout << str[i] << endl;
    }
    return 0;
}

/* INPUT
C 
C++
Java
Python
Perl
R
Matlab
Ruby
JavaScript
PHP */
