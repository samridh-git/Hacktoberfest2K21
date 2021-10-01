static bool cmp(Interval a,Interval b){
    return a.start < b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    sort(A.begin(),A.end(),cmp);
    vector<Interval>op;
    int i=1,s=A[0].start,e = A[0].end,j=0;
    for(int i=0;i<n-1;i++){
        if(A[i+1].start <= A[i].end){
           A[i+1].start = min(A[i].start,A[i+1].start);
           A[i+1].end = max(A[i].end,A[i+1].end);
        }
        else{
            op.push_back(A[i]);
        }
    }
    op.push_back(A[n-1]);
    return op;
}
