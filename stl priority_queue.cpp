#include<iostream>
#include<queue>

using namespace std;

 struct process
 {
     int arr_t,b_t;
 };
 struct CompareHeight {
    bool operator()(process const& p1, process const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.arr_t > p2.arr_t;
    }
 };

 int main()
 {
     int a;
     priority_queue<process,vector<process>,CompareHeight> pq;
     process p;
     cout<<"enter three number::";
     for(int i=0;i<3;i++)
     {
         cin>>p.arr_t>>p.b_t;
         pq.push(p);
     }
     while(!pq.empty())
     {
         p=pq.top();
         cout<<p.arr_t<<" "<<p.b_t<<endl;
         pq.pop();
     }
     return 0;
 }
