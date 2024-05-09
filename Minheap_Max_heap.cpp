#include<bits/stdc++.h>
#include<vector> 

using namespace std;

struct MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown() {
        int index = 0;
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest])
                largest = leftChild;
            if (rightChild < size && heap[rightChild] > heap[largest])
                largest = rightChild;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

  
    int deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown();
        return maxValue;
    }

  
    void printHeap() {
        cout << "Maxheap Tree: ";
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

 
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);

    maxHeap.printHeap();

    cout << "Deleted max value: " << maxHeap.deleteMax() << endl;

    maxHeap.printHeap();

    return 0;
}
