//
// Created by we7289 on 3/13/2024.
//

#include "Heap.h"

void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

template<class T>
Heap<T>::Heap() {

}

template<class T>
Heap<T>::Heap(int max_size) {

}

template<class T>
void Heap<T>::ReheapUp(T value) {
    if (size >= max_size) throw FullHeap;

    elements[size] = value;

    int curIdx = size;
    size++;


    while (curIdx != 0){
        int parentIdx = (curIdx - 1) / 2;

        if (elements[curIdx] > elements[parentIdx]) {
            // max heap: check if child > parent value
            // swap if so
            swap(elements, elements[curIdx], elements[parentIdx]);
            curIdx = parentIdx;
        } else break; // curIdx is in the right spot
    }
}

template<class T>
T Heap<T>::ReheapDown() {
    T priority_value = elements[0]; // value of root of the tree

    // Place last element at the root
    elements[0] = elements[size - 1];
    size--;

    T curIdx = 0;
    int bottom = size - 1;

    int leftIdx = 2 * curIdx + 1;
    int rightIdx = 2 * curIdx + 2;

    int maxChildIdx;

    while (curIdx <= size - 1) {



        T curEl = elements[curIdx];
        T leftEl = elements[leftIdx];
        T rightEl = elements[rightIdx];

        // Finding maxChildIdx
        if (leftIdx == size - 1) {
            // Second to last node has only a left node (complete but not full)
            maxChildIdx = leftIdx;
        }else {
            // If the second to last node has a left and right
            if (leftEl < rightEl) {
                maxChildIdx = rightIdx;
            } else {
                maxChildIdx = leftIdx;
            }
        }

        if (curEl < elements[maxChildIdx]) {
            swap(elements, curIdx, maxChildIdx);
            curIdx = maxChildIdx
        } else break;
    }

    return priority_value;
}
