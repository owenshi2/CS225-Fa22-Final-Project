#include <vector>
#include <utility>


/*expectation of a distance to a city and a City*/
class Heap {
    public:
    /*default constructor*/
    Heap();
    /*constructor using our list of cities*/
    Heap(const std::vector<City*>& b);
    /*removal of highest priority city*/
    std::pair<unsigned, City*> pop();
    /*observance of highest priority city*/
    std::pair<unsigned, City*> peek();
    /*checks if the heap is empty*/
    bool empty();

    size_t root();

    void insert(unsigned dist, City const* c);

    private:
    std::vector<std::pair<unsigned, City*>> elems;
    bool higherPriority(std::pair<unsigned, City*> a, std::pair<unsigned, City*> b);
    size_t leftChild(size_t currentIdx) const;
    size_t rightChild(size_t currentIdx) const;
    size_t parent(size_t currentIdx) const;
    bool hasChild(size_t currentIdx) const;
    /*returns index of highest priority child*/
    size_t maxPriorityChild(size_t currentIdx) const;
    void heapifyDown(size_t currentIdx);
    void heapifyUp(size_t currentIdx);
};