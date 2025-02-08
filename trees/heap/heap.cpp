#include <iostream>
#include <limits.h>
#define swap(a,b) if((&a)!=(&b))((a)^=(b)^=(a)^=(b))

class MaxHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i+1); }
    int right(int i) { return (2*i+2); }
    int getMax() { return harr[0]; }
    MaxHeap(int capacity);

    void MaxHeapify(int n);
    void insertKey(int k);
    int extractMax();
    void increaseKey(int i, int new_val);
    void deleteKey(int i);
};

MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MaxHeap::MaxHeapify(int n)
{
    int l = left(n), r = right(n);
    int larg = n;
    if(l < heap_size && harr[l] > harr[larg])
        larg = l;
    if(r < heap_size && harr[r] > harr[larg])
        larg = r;
    if(larg != n) {
        swap(harr[larg], harr[n]);
        MaxHeapify(larg);
    }
}

void MaxHeap::insertKey(int k)
{
    if(heap_size != capacity)
    {
        harr[heap_size++] = k;
        int i = heap_size - 1;
        while(i!=0 && harr[parent(i)] < harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
}

int MaxHeap::extractMax()
{
    if(heap_size <= 0)
        return INT_MIN;
    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

void MaxHeap::increaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while(i!=0 && harr[parent(i)] < harr[i])
    {
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}

void MaxHeap::deleteKey(int k)
{
    increaseKey(k, INT_MAX);
    extractMax(); 
}
