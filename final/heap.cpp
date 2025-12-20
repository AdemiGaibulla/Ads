#include <iostream>
#include <vector>

using namespace std;

void heapifyUp(vector<int> &heap, int i){
    while(i > 0){
        int parent = (i - 1)/2;

        if(heap[i] > heap[parent]){
            swap(heap[i], heap[parent]);
            i = parent;
        }
        else break;
    }
}

void heapifyDown(vector<int> &heap, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && heap[left] > heap[largest]){
        largest = left;
    }

    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void buildHeap(vector<int> &a){
    int n = a.size();
    for(int i=n/2 - 1; i>=0; i--){
        heapifyDown(a, n, i);
    }
}

void heapSort(vector<int> &a){
    int n = a.size();

    buildHeap(a);

    for(int i = n-1; i>0; i--){
        swap(a[0], a[i]);
        heapifyDown(a, i, 0);
    }
}
