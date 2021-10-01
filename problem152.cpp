typedef struct node N; 
N* partition(N *head,N *tail){
    if(head==NULL)
        return head;
    N *pivot=head;
    N *prev=head;
    N *cur=head->next;
    while(cur!=tail->next){
        if(cur->data<pivot->data){
            swap(prev->next->data,cur->data);
            prev=prev->next;
        }
        cur=cur->next;
    }
    swap(prev->data,pivot->data);
    return prev;
} 
void quicksortutil(N* head,N* tail){
    if(head==tail||tail==NULL||head==NULL)
        return;
    N* pivot = partition(head,tail);
    quicksortutil(head,pivot);
    quicksortutil(pivot->next,tail);
}
void quickSort(struct node **headRef) {
    N* tail=*headRef;
    while(tail->next!=NULL)
        tail=tail->next;
    quicksortutil(*headRef,tail);
}