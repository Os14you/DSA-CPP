It’s a part of some data structure like [[linked-lists|linked lists]], [[graphs|graphs]] and it varies from one data structure to another but the main idea is about it holds a **value** and a **pointer** to the another node. 

```cpp
struct Node {
    int data;
    Node* next;
    Node(): data(0) {}
    Node(int data): data(data) {
        next = nullptr;
    }
    // Destractor will be in the Main Data structure
};

...
// linking the node with each other
Node* node1 = new Node(6);
Node* node2 = new Node(6);

node1->next = node2;
node2->next = nullptr;

// Access any node from a previous one
std::cout << node1->next->data << " Node-2 value" << "\n";
std::cout << node2->data << " Node-2 value" << "\n";
std::cout << node1->data << " Node-1 value" << "\n";
```

Operations on Linked Nodes: [[display-nodes-chain|Display Nodes]], [[find-node-value|Find Node Value]]