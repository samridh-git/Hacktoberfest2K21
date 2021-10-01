struct Node* reverse(struct Node *head,int &n){
    if(!head||!head->next)
        return head;
    Node *prev=NULL,*cur=NULL,*nextnode=head;
    while(nextnode){
        n++;
        cur = nextnode;
        nextnode = nextnode->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}
struct Node* addutil(struct Node *add,struct Node *first,struct Node *second,int carry){
    struct Node* tmp=add;
    if(!second){
        if(!first && carry==0){
            return NULL;
        }
        //Right
        else if(!first && carry!=0){
            Node* nn = new Node(carry);
            return nn;
        }
        //Right
        else if(first && carry==0)
            return first;
        
        else if(first && carry!=0){
            int sum = first->data+carry;
            if(sum<10){
                tmp->data = sum;
                carry=0;
            }
            else{
                tmp->data = sum%10;
                carry = sum/10;
                tmp->next = addutil(tmp->next,first->next,second,carry);
            }
            return tmp;
        }
    }
    int k = first->data+second->data+carry;
    tmp->data = k%10;
    tmp->next = addutil(tmp->next,first->next,second->next,k/10);
    return tmp;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    int n1=0;
    int n2=0;
    struct Node*hold1 = reverse(first,n1); //0 1
    struct Node*hold2 = reverse(second,n2); //9
    struct Node *t1=NULL;
    if(n1>=n2)
        t1 = addutil(first,first,second,0);
    else
        t1 = addutil(second,second,first,0);
    return reverse(t1,n1);
}
/*
Iterative extra space working code

Node* reverse(Node* head)
{
    if(!head or !head->next)
        return head;
    Node *ptr = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return ptr;
}
int countnodes(Node*head)
{
    if(!head)
        return 0;
    return 1 + countnodes(head->next);
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
// code here
Node* head1=first;
Node* head2=second;
Node* head=NULL;
Node* newnd,*tempnd;
head1=reverse(head1);
head2=reverse(head2);
int sum,carry=0;
Node* current1=head1;
Node* current2=head2;
while(current1||current2)
{ if(current1==NULL)
sum=current2->data+carry;
else if(current2==NULL)
sum=current1->data+carry;
else
{
sum=current1->data+current2->data+carry;
}
carry=(sum>=10)?1:0;

sum=sum%10;
newnd=new Node(sum);
if(head==NULL)
{
head=tempnd=newnd;

}
else
{
tempnd->next=newnd;
tempnd=newnd;
}
if(current1)
current1=current1->next;
if(current2)
current2=current2->next;
}
if(carry)
tempnd->next=new Node(carry);
return reverse(head);
}


*/
