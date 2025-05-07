#include <iostream>
#include <vector>
using namespace std;

// ------------------------ Max Heap Class ------------------------
class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

// ------------------------ Min Heap Class ------------------------
class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

// ------------------------ Main Function ------------------------
int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;

    int elements[] = {10, 4, 9, 1, 7, 5};

    for (int val : elements) {
        maxHeap.insert(val);
        minHeap.insert(val);
    }

    cout << "Max Heap: ";
    maxHeap.display();

    cout << "Min Heap: ";
    minHeap.display();

    cout << "Extracted Max: " << maxHeap.extractMax() << endl;
    cout << "Extracted Min: " << minHeap.extractMin() << endl;

    cout << "Max Heap after extraction: ";
    maxHeap.display();

    cout << "Min Heap after extraction: ";
    minHeap.display();

    return 0;
}
