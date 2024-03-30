Charles Zhang
cza147@sfu.ca
301569010


Design Documentation: IndexedPriorityQueue.h

The IndexedPriorityQueue class is a template class designed to efficiently manage a collection of tasks (stored as strings) with associated integer priorities. 
It provides operations for inserting tasks, updating priorities, removing tasks, and querying the task with the highest priority.
The implementation is done based on a binary heap data structure along with an unordered map to map task IDs to its heap postion.
This allows for O(log(n)) times for task removal, insertion, priority updates, and deleting top priority.
Additionally the unordered map allows for O(1) value searching.

Testing Regimen: IndexedPriorityQueue_Test.cpp

Below is a summary of the testing performed:

1. Insertion Test: Inserts multiple tasks with different priorities into the queue to verify the insertion operation.
    - Inserted more than the default capacity, to test reserve();
    - Used capacity() to show that capacity increased

2. Size, isEmpty, and Contains Test: Checks the size of the queue, verifies if it's empty, and checks if specific tasks are contained in the queue.

3. getMin Test: Retrieves the task with the minimum priority from the queue to ensure correct functioning of getMin operation.

4. deleteMin Test: Deletes the task with the minimum priority from the queue and verifies the correctness of deletion by showing the new minimum priority.

5. updatePriority Test: Updates the priority of an existing task and verifies if the queue maintains the correct order.
    - Updates "Task3" to a priority of 0 to be moved to the top of the heap
    - using getMin() (shown to work earlier in test) to test if "Task3" was perculated up to root

6. remove Test: Removes a task from the queue and verifies the size of the queue after removal.
    - shows that "Task2" exists in priority queue, and priority queue size before removal
    - shows that "Task2" no longer exists in priority queue, and priority queue size decreased after removal

7. clear Test: Clears the queue and verifies if the queue is empty after clearing.
    - shows size of queue after clearing

8. Exception Handling Test: Tests exception handling by attempting to delete from an empty queue and updating the priority of a non-existent task, and verifies if the exceptions are caught and handled correctly.

9. Vector Constructor Test: Construct IPQ with 2 vectors of size 5, 1st one with task IDs, 2nd one with priority values.
    - Use ddisplay to show that every task and its priority is inserted into the queue

10. Capacity Template Test: Create a new IPQ with capacity 15.
    - Show capacity after construction is not the default 10.

11. Max size test: Show that max(i, 10) in the reserve function works.
    - Created a IPQ of size < 10 to show size will still be 10