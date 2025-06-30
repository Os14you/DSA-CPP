- Priority queue is a queue in which each element has a "priority" associated with it. Elements of higher priority are ALWAYS SERVED before elements of lower priority
- Assume that we have an OS comprised of tasks, each of priority 1, 2, or 3
	- Assume we enqueued them as follows:
	- Enqueue (task_id = 1131, priority = 1)
	- Enqueue (task_id = 3111, priority = 3)
	- Enqueue (task_id = 2211, priority = 2)
	- Enqueue (task_id = 3161, priority = 3)
	- Let’s print the tasks in order: 3111 3161 2211 1131
		- That is: to dequeue we must first get from priority 3, if nothing from 2, if nothing from 1
- Implement a priority queue class by **black box utilization** of linked-list queue.

```cpp title:solution folded:true

```