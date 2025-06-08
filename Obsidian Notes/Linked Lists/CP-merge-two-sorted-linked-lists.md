#recursion #singlyLinkedList #problemsolving 

```cpp title:solution folded:true
Node* merge(Node* head1, Node* head2) {
	if(!head1) return head2;
	if(!head2) return head1;

	if(head1->data < head2->data) {
		head1->next = merge(head1->next, head2);
		return head1;
	} else {
		head2->next = merge(head1, head2->next);
		return head2;
	}
}
```