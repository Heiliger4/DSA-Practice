#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap {
private:
    vector<int> heap;

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }

    int getRightChildIndex(int index) {
        return 2 * index + 2;
    }

    void heapifyUp(int index) {
        if (index && heap[index] > heap[getParentIndex(index)]) {
            swap(heap[index], heap[getParentIndex(index)]);
            heapifyUp(getParentIndex(index));
        }
    }

    void heapifyDown(int index) {
        int left = getLeftChildIndex(index);
        int right = getRightChildIndex(index);
        int largest = index;

        if (left < heap.size() && heap[left] > heap[index]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryHeap heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);

    cout << "Max Heap representation:" << endl;
    heap.printHeap();

    heap.deleteMax();
    cout << "After deleting max element: " << endl;
    heap.printHeap();

    return 0;
}
/*This C++ code implements a binary heap data structure, specifically a max binary heap. 
The main concept behind this code is to maintain the heap property 
where the value of each node is greater than or equal to the values of its children. 
It provides operations to insert elements into the heap and delete the maximum element, 
while ensuring that the heap property is preserved.  */