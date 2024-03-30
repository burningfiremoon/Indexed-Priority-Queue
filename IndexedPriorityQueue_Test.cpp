#include <iostream>
#include "IndexedPriorityQueue.h"

void testIndexedPriorityQueue() {
    // Test constructor and insert
    IndexedPriorityQueue<5> ipq;
    ipq.insert("task1", 5);
    ipq.insert("task2", 3);
    ipq.insert("task3", 7);
    ipq.insert("task4", 2);
    ipq.insert("task5", 6);

    // Test size and isEmpty
    std::cout << "Size: " << ipq.size() << ", Is empty: " << (ipq.isEmpty() ? "true" : "false") << std::endl;

    // Test getMin
    std::cout << "Min task: " << ipq.getMin() << std::endl;

    // Test deleteMin
    std::cout << "Deleting min task: " << ipq.deleteMin() << std::endl;
    std::cout << "Min task after deletion: " << ipq.getMin() << std::endl;

    // Test updatePriority
    ipq.updatePriority("task3", 1);
    std::cout << "Updated priority of task3" << std::endl;
    std::cout << "Min task after update: " << ipq.getMin() << std::endl;

    // Test remove
    ipq.remove("task2");
    std::cout << "Removed task2" << std::endl;
    std::cout << "Size after removal: " << ipq.size() << std::endl;

    // Test clear
    ipq.clear();
    std::cout << "Cleared IPQ" << std::endl;
    std::cout << "Size after clearing: " << ipq.size() << std::endl;

    // Test exceptions
    try {
        std::cout << "Attempting to delete from an empty IPQ" << std::endl;
        ipq.deleteMin();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to update priority of non-existent task" << std::endl;
        ipq.updatePriority("task10", 10);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    testIndexedPriorityQueue();
    return 0;
}