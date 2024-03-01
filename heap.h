#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  PComparator comp;
  std::vector<T> data_;//using vector as the underlying data structure for our heap
  int type_;//to store what type of heap
  void heapify(int idx);//defining helper function heapify for tricle down
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  type_=m;
  comp = c;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data_.push_back(item);
  int child = data_.size()-1;
  int parent = (child-1)/type_;
  while(child>0&&comp(data_[child],data_[parent]))//trickling down to maintain heap property
  {
    //swaping and updating parent and child
    std::swap(data_[child],data_[parent]);
    child = parent;
    parent = (child-1)/type_;
  }

}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data_.empty();

}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>:: size() const
{
  return data_.size();

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty");//throwing underflow error if heap is empty
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");//throwing underflow error if heap is empty
  }
  std::size_t i = 0;
  std::swap(data_[i],data_[data_.size()-1]);//swaping the tree root with a leaf
  data_.pop_back();//popping 
  if(!empty())
  {
    heapify(0);//calling heapify to tricle down and maintain the heap property
  }
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
    if(idx==data_.size()-1)//base case
    {
      return;
    }
    int no_child = 1;
    int best_child= idx;
    while(no_child<=type_)//looping through all the children of the current node
    {
      int currentchild = (type_*idx)+no_child;//setting the current child
      if(currentchild<data_.size())//seeing if the current child exists
      {
        if(comp(data_[currentchild],data_[best_child]))
        {
          best_child = currentchild;//changing the best_child if the compartor returns true
        }
      }
      no_child++;//updating the child
    }
    if(best_child!=idx)//checking if the best child index is different from the parent index
    {
      std::swap(data_[idx],data_[best_child]);//swapping parent and best child
      heapify(best_child);//recursively calling heapify on the best child
    }
}



#endif

