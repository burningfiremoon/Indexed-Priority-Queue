#ifndef IPQ_H
#define IPQ_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;

template <int Capacity = 10>
class IndexedPriorityQueue {
    private:
        class Heap {
            private:
                pair<int, string> * heap; // Priority, TaskID
                int theCapacity;
                int theSize;
                unordered_map<string, int> map; // TaskID, NodeIndex

                void percolateUp(int i){ // takes index
                    if (i <= 0) return; // if root base case

                    int parent = (i-1)/2; // index of parent
                    
                    if (heap[i].first < heap[parent].first){
                        // swap parent and child
                        swap(heap[parent], heap[i]);

                        // update map
                        map[heap[parent].second] = parent;
                        map[heap[i].second] = i;

                        // recursive part
                        percolateUp(parent);
                    }

                }

                void percolateDown(int i){ //takes index
                    int left = 2*i + 1;
                    int right = 2*i + 2;
                    int smallest = i;
                    if (left < theSize && heap[left].first < heap[i].first){
                        smallest = left;
                    }
                    if (right < theSize && heap[right].first < heap[i].first){
                        smallest = right;
                    }
                    if (smallest != i){
                        // swap smallest and i
                        swap(heap[smallest], heap[i]);
                        map[heap[smallest].second] = smallest;
                        map[heap[i].second] = i;
                        percolateDown(smallest); // recursive step
                    }

                }

            public:

                Heap() {
                    theCapacity = Capacity;
                    heap = new pair<int, string>[theCapacity];
                    theSize = 0;

                }

                // deconstructor
                ~Heap() {
                    delete[] heap;
                }

                void reserve(int newCapacity){
                    // Changes heap array capacity to newCapacity
                    int greatestValue = max(newCapacity, 10);
                    // only if it is larger than current size
                    if (greatestValue > theCapacity){
                        pair<int, string>* newArray = new pair<int, string> [greatestValue];

                    for (int i = 0; i < theSize; i++){
                        newArray[i] = heap[i];
                    }
                    delete[] heap;

                    heap = newArray;

                    theCapacity = greatestValue;

                    }
                    
                }

                void insert(const string& id, int priority){
                    if (theSize >= theCapacity){
                        reserve(theSize * 2);
                    }
                    heap[theSize] = make_pair(priority, id);
                    map[id] = theSize;
                    percolateUp(theSize);

                    theSize++;

                }

                void update(const string& id, int newPriority){
                    if (map.count(id) == 0){
                        throw invalid_argument("Task ID not found");
                    }
                    int idx = map[id];
                    if (heap[idx].first < newPriority){
                        heap[idx].first = newPriority;
                        percolateDown(idx);
                    } else if (heap[idx].first > newPriority){
                        heap[idx].first = newPriority;
                        percolateUp(idx);
                    }
                }

                bool contains(const string& id){
                    return map.count(id) == 1;
                }

                void remove(const string& id){
                    if (!contains(id)){
                        throw invalid_argument("Task ID not found");
                    }
                    // take index swap with last (theSize-1), then reduce size
                    int idx = map[id];
                    swap(heap[idx], heap[theSize-1]);

                    // update map
                    map[heap[idx].second] = idx;
                    map.erase(heap[theSize-1].second);
                    theSize--;
                    percolateDown(0);

                }

                void clear(){
                    theSize = 0;
                    map.clear();
                }

                int size(){
                    return theSize;
                }

                int capacity(){
                    return theCapacity;
                }

                bool isEmpty() const {
                    return (theSize == 0);
                }

                string& getMin() const {
                    if (isEmpty()){
                        throw out_of_range("Heap is empty");
                    }
                    return heap[0].second;
                }

                // vector contruction function
                void constructFromVectors(const vector<string>& v1, const vector<int>& v2){
                    if (v1.size() != v2.size()){
                        throw invalid_argument("Vectors must be the same size");
                    }
                    clear();
                    reserve(v1.size() * 2);
                    for (int i = 0; i < v1.size(); i++){
                        insert(v1[i], v2[i]);
                    }
                }

                void ddisplay(){
                    cout << "Size: " << theSize << ", Capacity: " << theCapacity << endl;
                    for (int i = 0; i<theSize; i++){
                        cout << heap[i].first << " " << heap[i].second << endl;
                    }

                }


        };
        Heap heap;


    public:
        // constructor
        IndexedPriorityQueue(){ }

        // constructor from 2 vectors
        IndexedPriorityQueue(const vector<string>& v1, const vector<int>& v2){
            heap.constructFromVectors(v1, v2);
        }

        // destructor not needed heap will be deleted and complier will delete the Umap

        void insert(const string& id, int priority){
            heap.insert(id, priority);
        }

        void updatePriority(const string& id, int newPriority){
            heap.update(id, newPriority);
        }

        void remove(const string& id) {
            heap.remove(id);
        }

        void clear(){
            heap.clear();
        }

        void reserve(int i){
            heap.reserve(i);
        }

        bool isEmpty() const {
            return heap.isEmpty();
        }

        int size(){
            return heap.size();
        }

        int capacity(){
            return heap.capacity();
        }

        bool contains(const string& id){
            return heap.contains(id);
        }

        string& getMin() const {
            if (isEmpty()){
                throw out_of_range("Heap is empty");
            }
            return heap.getMin();

        }

        string deleteMin(){
            if (isEmpty()){
                throw out_of_range("Heap is empty");
            }
            
            string min_ID = heap.getMin();

            heap.remove(min_ID);

            return min_ID;
        }

        void ddisplay(){
            heap.ddisplay();
        }


};


#endif