#include "minheap.h"
#include <cstddef>
#include <iostream>

size_t Heap::root() {
    return 1;
}

size_t Heap::leftChild(size_t idx) const {
    return idx * 2;
}

size_t Heap::rightChild(size_t idx) const {
    return idx * 2 + 1;
}

size_t Heap::parent(size_t idx) const {
    return idx / 2;
}

bool Heap::hasChild(size_t idx) const {
    return (idx * 2) < elems.size();
}

bool Heap::higherPriority(std::pair<unsigned, std::string> a, std::pair<unsigned, std::string> b) const {
    if (a.first < b.first) return true;
    return false;
}

size_t Heap::maxPriorityChild(size_t idx) const {
    size_t left = leftChild(idx);
    size_t right = rightChild(idx);
    if (right >= elems.size()) return left;
    if (higherPriority(elems.at(left), elems.at(right))) return left;
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
    elems.push_back(std::make_pair(0, "lasagna"));
}

bool Heap::empty() {
    return elems.size() == 1;
}

std::pair<unsigned, std::string> Heap::peek() {
    return elems[1];
}

std::pair<unsigned, std::string> Heap::pop() {
    if (elems.size() == 1) {
        std::pair<unsigned, std::string> contingency = std::make_pair(0, "lasagna");
        return contingency;
    }
    auto temp = elems.at(1);
    std::swap(elems.at(1), elems.back());
    elems.pop_back();
    heapifyDown(1);
    return temp;
}

void Heap::insert(unsigned dist, std::string c) {
    std::pair<unsigned, std::string> ins = std::make_pair(dist, c);
    elems.push_back(ins);
    heapifyUp(elems.size() - 1);
}