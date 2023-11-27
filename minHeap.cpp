#include "minHeap.h"

minHeap::minHeap(std::vector<int> data)
{
    heap = data;

    // Build the heap from bottom-up
    for (int i = (heap.size() / 2) - 1; i >= 0; --i)
    {
        siftDown(i);
    }
}

void minHeap::siftUp(int pos)
{
    while (pos > 0)
    {
        int parent = (pos - 1) / 2;
        if (heap[pos] < heap[parent])
        {
            std::swap(heap[pos], heap[parent]);
            pos = parent;
        }
        else
        {
            break;
        }
    }
}

void minHeap::siftDown(int pos)
{
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
        std::swap(heap[pos], heap[smallest]);
        siftDown(smallest);
    }
}

void minHeap::insert(int value)
{
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

int minHeap::removeMin()
{
    if (heap.empty())
    {
        return -1;
    }

    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);

    return minValue;
}
