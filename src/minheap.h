#include <vector>
#include <pair>


/*expectation of a distance to a city and a City*/
class Heap {
    public:
    /*default constructor*/
    heap();
    /*constructor using our list of cities*/
    heap(const std::vector<std::pair<unsigned,Cities*>>& cities);
    /*removal of highest priority city*/
    Cities* pop();
    /*observance of highest priority city*/
    Cities* peek();
    /*checks if the heap is empty*/
    bool empty();

    size_t root();

    private:
    std::vector<std::pair<unsigned, Cities*>> elems;
    bool higherPriority(std::pair<unsigned, Cities*> a, std::pair<unsigned, Cities*> b);
    size_t leftChild(size_t currentIdx) const;
    size_t rightChild(size_t currentIdx) const;
    size_t parent(size_t currentIdx) const;
    bool hasChild(size_t currentIdx) const;
    /*returns index of highest priority child*/
    size_t maxPriorityChild(size_t currentIdx) const;
    void heapifyDown(size_t currentIdx);
    void heapifyUp(size_t currentIdx);
};