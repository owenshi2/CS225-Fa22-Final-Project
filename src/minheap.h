#include <vector>
#include <utility>
#include <string>


/*expectation of a distance to a city and a City*/
class Heap {
    public:
    /*default constructor*/
    Heap();
    /*constructor using our list of cities*/
    Heap(const std::vector<std::string>& b);
    /*removal of highest priority city*/
    std::pair<unsigned, std::string> pop();
    /*observance of highest priority city*/
    std::pair<unsigned, std::string> peek();
    /*checks if the heap is empty*/
    bool empty();

    size_t root();

    void insert(unsigned dist, std::string c);

    private:
    std::vector<std::pair<unsigned, std::string>> elems;
    bool higherPriority(std::pair<unsigned, std::string> a, std::pair<unsigned, std::string> b) const;
    size_t leftChild(size_t idx) const;
    size_t rightChild(size_t idx) const;
    size_t parent(size_t idx) const;
    bool hasChild(size_t idx) const;
    /*returns index of highest priority child*/
    size_t maxPriorityChild(size_t idx) const;
    void heapifyDown(size_t currentIdx);
    void heapifyUp(size_t currentIdx);
};