#singlyLinkedList #problemsolving 

- Given a list, we would like to find the max value in it
- Consider the following coding constraints
	- You must use recursion
	- Don’t create more than a function
	- Function name: `{cpp}int max()`

```cpp title:solution folded:true
int max(Node* start = nullptr, bool isFirstCall = true) {
    if(isFirstCall)
        return this->max(this->head, false);

    if(!start) 
        return INT_MIN; // climits
    
    return std::max(start->data, this->max(start->next, false));
}
```
