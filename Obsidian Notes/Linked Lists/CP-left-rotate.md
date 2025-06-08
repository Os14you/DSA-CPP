#singlyLinkedList #problemsolving 

Given a list, we would like left rotate it k steps (k up to $200000000$)
Takes the first k elements and shift to back
`{cpp}void left_rotate(int k)`: Your code should be $O(n)$ time
Below list rotated with $k = 3$ (nodes $(6), (10), (8)$ shifted back)
If $k = 1 ⇒ \{10, 8, 15, 6\}$
If $k = 2 ⇒ \{8, 15, 6, 10\}$

![[left-rotate.excalidraw|800]]
 
```cpp title:solution folded:true
void head_to_tail() {
    if(!head || !head->next) return;

    tail->next = head;
    tail = tail->next;
    head = head->next;
    tail->next = nullptr;
}

void left_rotate(int k) {
    if(!head || !head->next) return;

    k %= length;
    while(k--) {
        head_to_tail();
    }
}
```