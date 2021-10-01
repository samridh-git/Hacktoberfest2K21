struct node* rec_mod(struct node*cur,struct node*prev){
	if(!cur)
		return cur;

	if(!cur->next){
		cur->next = prev;
		return cur;
	}

	node* nn = cur->next;
	cur->next = prev;

	return rec_mod(nn,cur);
}

struct node* Recursive_reverse(struct node* head){
	node* prev = NULL;
	node* cur = head;

	return rec_mod(head,prev);
}
