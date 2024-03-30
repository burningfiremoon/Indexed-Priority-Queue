#include <iostream>
#include "IndexedPriorityQueue.h"
using namespace std;

void testIndexedPriorityQueue() {
    // Test constructor and insert
    IndexedPriorityQueue<10> ipq;

    ipq.insert("task1", 5);
    ipq.insert("task2", 3);
    ipq.insert("task3", 7);
    ipq.insert("task4", 2);
    ipq.insert("task5", 6);
    ipq.insert("task6", 10);
    ipq.insert("task7", 4);
    ipq.insert("task8", 9);
    ipq.insert("task9", 8);
    ipq.insert("task10", 15);
    ipq.insert("task11", 1);

    cout << "this is the capacity: " << ipq.capacity() << endl;

    // Test size, isEmpty and contains
    cout << endl;
    cout << "Size: " << ipq.size() << ", Is empty: " << (ipq.isEmpty() ? "true" : "false") << ", Contains task1?: " << (ipq.contains("task1") ? "true" : "false") << ", Contains task80?: " << (ipq.contains("task80") ? "true" : "false") << endl;

    // Test getMin
    cout << endl;
    cout << "Min task: " << ipq.getMin() << endl;

    // Test deleteMin
    cout << endl;
    cout << "Deleting min task: " << ipq.deleteMin() << endl;
    cout << "Min task after deletion: " << ipq.getMin() << endl;

    // Test updatePriority
    cout << endl;
    ipq.updatePriority("task3", 0);
    cout << "Updated priority of task3" << endl;
    cout << "Min task after update: " << ipq.getMin() << endl;

    // Test remove
    cout << endl;
    cout << "Contains task2?: " << (ipq.contains("task2") ? "true" : "false") << endl;
    cout << "Size before removal: " << ipq.size() << endl;
    ipq.remove("task2");
    cout << "Removed task2" << endl;
    cout << "Contains task2?: " << (ipq.contains("task2") ? "true" : "false") << endl;
    cout << "Size after removal: " << ipq.size() << endl;

    // Test clear
    cout << endl;
    ipq.clear();
    cout << "Cleared IPQ" << endl;
    cout << "Size after clearing: " << ipq.size() << endl;

    // Test exceptions
    cout << endl;
    cout << "Start of exception test" << endl;
    cout << endl;
    try {
        cout << "Attempting to delete from an empty IPQ" << endl;
        ipq.deleteMin();
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << endl;
    try {
        cout << "Attempting to update priority of non-existent task" << endl;
        ipq.updatePriority("task10", 10);
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }


    // Constructor test
    cout << endl;
    vector<string> v1 = {"Task1","Task2","Task3","Task4","Task5"};
    vector<int> v2 = {2,1,5,4,3};
    IndexedPriorityQueue<> ipqVectors(v1, v2);

    ipqVectors.ddisplay();

    cout << endl;
    IndexedPriorityQueue<15> ipqSize;
    cout << "Capacity: " << ipqSize.capacity() << endl;

    cout << endl;
    IndexedPriorityQueue<5> ipqSmallSize;
    cout << "Capacity: " << ipqSmallSize.capacity() << endl;
}

int main() {
    testIndexedPriorityQueue();
    return 0;
}