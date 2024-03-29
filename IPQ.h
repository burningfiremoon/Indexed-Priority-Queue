#ifndef IPQ_H
#define IPQ_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
using namespace std;

template <int Capacity>
class IndexedPrioityQueue {
    private:
        class Heap {
            private:

                unordered_map<string, int> Map; // TaskID, NodeIndex
                vector<pair<int, string>>heap(Capacity); // Priority, TaskID

                void percolateUp(int i){

                }

                void percolateDown(int i){

                }

                void reserve(int i){
                    
                }
            public:
                void insert(const string& id, int priority){

                }

                void update(int index, int newPriority){

                }

                void remove(const string& id){

                }

                bool isEmpty() const {
                    return heap.empty();
                }

                pair<int, string> getMin() {
                    if (isempty()){
                        throw out_of_range("Heap is empty");
                    }
                    return heap[0];
                }


        };
        Heap heap;


    public:
        // constructor


        // destructor



        void insert(const string& id, int priority){

        }

        void updatePriority(const string& id, int newPriority){

        }

        void remove(const string& id) {

        }

        void clear(){

        }

        bool isEmpty() const {
            return heap.isEmpty();
        }

        int size(){

        }

        string& deleteMin(){

        }

        string& getMin() const {

        }


    

};








#endif