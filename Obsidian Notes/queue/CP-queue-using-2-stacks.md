#queue #problemsolving #stack

- Implement Queue functionalities using 2 stack objects
- However, the `{c}dequeue()` function must remain $O(1)$
- Implement only these requested functionalities

```cpp title:solution foled:true
void move(Stack &stack1, Stack &stack2) {
	while(!stack1.isEmpty()) {
		stack2.push(stack1.pop());
	}
}

int dequeue() {
	--num_elements;
	return stack1.pop();
}

void enqueue(int value) {
	move(stack1, stack2);
	stack1.push(value);
	move(stack2, stack1);
	num_elements++;
}
```

