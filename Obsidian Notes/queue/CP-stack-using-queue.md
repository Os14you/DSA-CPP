#queue #problemsolving 

- Let’s practice aggregations
- Using Linked-list queue, implement stack functionalities
	- You may add a few extra functionalities to the queue code to make your stack code proper
- What is the time complexity of your push/pop?
- Don’t implement display

```cpp title:solution folded:true
void push(int value) {
	int sz = num_elements;
	q.enqueue(value);
	
	while (sz--) q.enqueue(q.dequeue());
	num_elements++;
}
```