#include "minheap.h"
#include <cstddef>

size_t Heap::root() {
    return 1;
}

size_t Heap::leftChild(size_t idx) {
    return idx * 2;
}

size_t Heap::rightChild(size_t idx) {
    return idx * 2 + 1;
}

size_t Heap::parent(size_t idx) {
    return idx / 2;
}

bool Heap::hasChild(size_t idx) {
    return (idx * 2) < elems.size();
}

bool Heap::higherPriority(std::pair<unsigned, City*> a, std::pair<unsigned, City*> b) {
    if (a.first < b.first) return true;
    return false;
}

size_t Heap::maxPriorityChild(size_t idx) {
    size_t left = leftChild(idx);
    size_t right = rightChild(idx);
    if (right > elems.size()) return left;
    if higherPriority(elems[left], elems[right]) return left;
    return right;
}

void Heap::heapifyDown(size_t currentIdx) {
    if (currentIdx * 2 >= elems.size()) return;
    size_t childIdx = maxPriorityChild(currentIdx);
    if (higherPriority(elems[childIdx], elems[currentIdx])) {
        std::swap(elems[childIdx], elems[currentIdx]);
        heapifyDown(childIdx);
    }
}

void Heap::heapifyUp(size_t currentIdx) {
    if (currentIdx == root()) return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(elems[currentIdx], elems[parentIdx])) {
        std::swap(elems[currentIdx], elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

Heap::Heap() {
    elems.push_back(std::make_pair(0, nullptr));
}

Heap::Heap(const std::vector<City*>& b) {
    elems.push_back(std::make_pair(0, nullptr));
    for (unsigned i = 1; i < b.size(); ++i) {
    	elems.push_back(std::make_pair((unsigned)-1, elem);
    }
    for (size_t idx = elems.size() - 1; idx > 0; idx--) {
    	heapifyDown(idx);
    }
}

bool Heap::empty() {
    return elems.size() == 1;
}

std::pair<unsigned, City*> Heap::peek() {
    return elems[1];
}

std::pair<unsigned, City*> Heap::pop() {
    if (elems.size() == 1) {
        return std::make_pair(0, nullptr);
    }
    auto temp = elems[1];
    std::swap(elems[1], elems.back());
    elems.pop_back();
    heapifyDown(1);
    return temp;
}

void Heap::insert(unsigned dist, City const* c) {
    std::pair<unsigned, City*> ins = std::make_pair(dist, c);
    elems.push_back(ins);
    heapifyUp(elems.size() - 1);
}


