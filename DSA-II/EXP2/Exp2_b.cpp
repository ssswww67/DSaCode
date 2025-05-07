// Min Heap

#include <iostream>
#include <vector>
using namespace std;
class MinHeap {
    private:
    vector<int> heap;
    // Helper function to get parent index
    int parent(int i) { return (i - 1) / 2; }
    // Helper function to get left child index
    int leftChild(int i) { return (2 * i + 1); }
    // Helper function to get right child index
    int rightChild(int i) { return (2 * i + 2); }
    // Heapify down to maintain the min-heap property
    void heapifyDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    // Heapify up to maintain the min-heap property
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    public:
    // Insert a new value into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    // Remove and return the minimum element (root)
    int extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }
    // Get the minimum element (root) without removing it
    int getMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }
    // Print the heap elements
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main() {
    MinHeap minHeap;
    // Insert elements into the heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(30);
    cout << "Min-Heap elements: ";
    minHeap.printHeap();
    // Extract minimum element
    cout << "Extracted Min: " << minHeap.extractMin() << endl;
    cout << "Min-Heap elements after extraction: ";
    minHeap.printHeap();
    // Get the current minimum element
    cout << "Current Min: " << minHeap.getMin() << endl;
    return 0;
}