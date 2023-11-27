#include "minHeap.h"

minHeap::minHeap(std::vector<int> data)
{
    // Initialize the heap with the provided data
    heap = data;

    // Build the heap from bottom-up
    for (int i = (heap.size() / 2) - 1; i >= 0; --i)
    {
        siftDown(i);
    }
}

void minHeap::siftUp(int pos)
{
    // Move the element up the heap until the heap property is satisfied
    while (pos > 0)
    {
        int parent = (pos - 1) / 2;
        if (heap[pos] < heap[parent])
        {
            // Swap the current element with its parent if the heap property is violated
            std::swap(heap[pos], heap[parent]);
            pos = parent;
        }
        else
        {
            break; // Break the loop if the heap property is satisfied
        }
    }
}

void minHeap::siftDown(int pos)
{
    // Move the element down the heap until the heap property is satisfied
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;
    int smallest = pos;

    if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
    {
        smallest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != pos)
    {
        // Swap the current element with its smallest child if the heap property is violated
        std::swap(heap[pos], heap[smallest]);
        siftDown(smallest);
    }
}

void minHeap::insert(int value)
{
    // Insert a new value into the heap and maintain the heap property
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

int minHeap::removeMin()
{
    if (heap.empty())
    {
        // Return -1 if the heap is empty (assuming -1 as an indicator of an error or an empty heap)
        return -1;
    }

    // Remove and return the minimum value from the heap
    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);

    return minValue;
}
