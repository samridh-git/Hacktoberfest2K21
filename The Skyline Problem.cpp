class Solution {
public:
    vector<vector<int>> v;
    struct Buld{
        int right;
        int height;
    };
    
    struct compare{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        }  
    };
    
    void update(int x,int y){
        if(v.empty() || y!=v.back()[1]) {
            vector<int> a={x,y};
            v.push_back(a);
        }
    }
    
    void remove(priority_queue<pair<int,int>,vector<pair<int,int>>,compare> &pq){
        int ct=pq.top().first;
        while(!pq.empty() && pq.top().first<=ct){
            pq.pop();
        }
        update(ct,pq.empty()? 0:pq.top().second);
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        v.clear();
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<a.size();){
            int x=a[i][0];
            while(!pq.empty() && pq.top().first<x){
                remove(pq);
            }
            
            while(i<a.size() && a[i][0]==x){
                pq.push({a[i][1],a[i][2]});
                i++;
            }
            update(x,pq.empty()? 0:pq.top().second);
        }
        while(!pq.empty()) remove(pq);
        return v;
    }
};