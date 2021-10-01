void check(Node*root,int min,int max,bool &ans){
    if(!root)
        return;
    if((!root->left && !root->right) && (min == max || max == 1 || min == 1)){
        ans = true;
        return;
    }
    check(root->left,min,root->data-1,ans);
    check(root->right,root->data+1,max,ans);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans = false;
    check(root,INT_MIN,INT_MAX,ans);
    return ans;
}
