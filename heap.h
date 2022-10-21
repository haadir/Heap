#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;


private:

  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
  int numKids;
  PComparator comp;
  void trickleDown(int loc);
  void trickleUp(int loc);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  numKids = m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int loc) {
	//check if we are at bottom
  if((numKids*loc) + 1 >= heap.size()) return;
	//smaller child
  int smallerChild = numKids * loc + 1;
	//smallest child's index
  int smallIndex = smallerChild;
	//find smallest child
  for(int i = smallerChild; i < smallerChild + numKids; i++) {
    if(i >= heap.size()) break;
    if(comp(heap[i], heap[smallIndex])) smallIndex = i;
  }
	//if smallest child is less than parent, swap
  if(comp(heap[smallIndex], heap[loc])){
    std::swap(heap[loc], heap[smallIndex]);
    trickleDown(smallIndex);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc) {
  int parentIndex = (loc - 1)/numKids;
	//while we aren't at the first node
  while (loc > 0) {
		//if child is greater than parent, then swap
    if (comp(heap[loc], heap[parentIndex])) {
      std::swap(heap[loc], heap[parentIndex]);
    }
		//keep trickling up
    loc = parentIndex;
    parentIndex = (loc - 1)/numKids;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("empty");
  }
  return heap[0];
}

//PUSH
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  heap.push_back(item);
  trickleUp(heap.size()-1);
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("empty");
  }
  heap[0] = heap[heap.size()-1];
  heap.pop_back();
  trickleDown(0);
}

//EMPTY
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(heap.size() == 0){
    return true;
  }
  return false;
}

//SIZE
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap.size();
}



#endif

