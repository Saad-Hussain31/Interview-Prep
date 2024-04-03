/*
exception-safe (works properly in the presence of exceptions)

exception-neutral (propagates all exceptions to the caller,
without causing integrity problems in a Stack object)

*/
#include <cassert>
#include <iostream>
using namespace std;

template <class T> class Stack {
public:
  Stack();
  ~Stack();
  Stack(const Stack<T> &other);
  Stack &operator=(const Stack<T> &other);
  size_t Count() const;
  void Push(const T &);
  void Pop();
  T &Top();

public:
  T *v_;         // ptr to a memory area big
  size_t vsize_; // enough for 'vsize_' T's
  size_t vused_; // # of T's actually in use
};

template <class T> T *NewCopy(const T *src, size_t src_size, size_t dest_size) {
  assert(dest_size >= src_size);
  // operator=() must guarantee that if it does throw,
  // then the assigned-to T object must be destructible.
  T *dest = new T[dest_size];
  try {
    std::copy(src, src + src_size, dest);
  } catch (...) {
    delete[] dest;
    throw;
  }
  return dest;
}

template <class T>
Stack<T>::Stack()
    : v_(0), vsize_(10), vused_(0) // nothing used yet
{
  v_ = new T[vsize_]; // initial allocation
}

template <class T> Stack<T>::~Stack() {
  delete[] v_; // this can't throw
}

template <class T>
Stack<T>::Stack(const Stack<T> &other)
    : v_(NewCopy(other.v_, other.vsize_, other.vsize_)), vsize_(other.vsize_),
      vused_(other.vused_) {}

template <class T> Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
  if (this != &other) { // ensures safety and independence of the program's
                        // state.
    T *v_new_ = NewCopy(other.v_, other.vsize_, other.vsize_);
    delete v_;
    v_ = v_new_;
    vsize_ = other.vsize_;
    vused_ = other.vused_;
  }
  return *this;
}

template <class T> void Stack<T>::Push(const T &t) {
  if (vsize_ == vused_) {
    size_t vsize_new_ = vsize_ * 2 + 1;
    T *v_new_ = NewCopy(v_, vsize_, vsize_new_);
    delete[] v_;
    v_ = v_new_;
    vsize_ = vsize_new_;
  }
  v_[vused_] = t;
  ++vused_;
}

template <class T> void Stack<T>::Pop() {
  if (vused_ == 0) {
    throw "pop from empty stack";
  } else {
    --vused_;
  }
}

template <class T> T &Stack<T>::Top() {
  if (vused_ == 0) {
    throw "empty stack";
  } else {
    return v_[vused_ - 1];
  }
}

template <class T> size_t Stack<T>::Count() const { return vused_; }

template <class T> class StackImpl {
public:
  StackImpl(size_t size = 0);
  ~StackImpl();
  void Swap(StackImpl &other) throw();
  T *v_;         // ptr to a memory area big
  size_t vsize_; // enough for 'vsize_' T's
  size_t vused_; // # of T's actually in use
private:
  // private and undefined: no copying allowed
  StackImpl(const StackImpl &);
  StackImpl &operator=(const StackImpl &);
};

template <class T>
StackImpl<T>::StackImpl(size_t size)
    : v_(static_cast<T *>(size == 0 ? 0 : operator new(sizeof(T) * size))),
      vsize_(size), vused_(0) {}

// construct() constructs a new object in
// a given location using an initial value
//
template <class T1, class T2> void construct(T1 *p, const T2 &value) {
  new (p) T1(value); // placement new
}

// destroy() destroys an object or a range 
// of objects
//
template <class FwdIter> void destroy(FwdIter first, FwdIter last) {
  while (first != last) {
    destroy(&*first);
    ++first;
  }
}

template <class T> void destroy(T *p) { p->~T(); }

template <class T> void swap(T &a, T &b) {
  T temp(a);
  a = b;
  b = temp;
}

int main() {
  // Stack<int> stk1;
  // Stack<int> stk2 = stk1;

  // Stack<int> stk3;
  // stk3 = stk1;

  Stack<int> stk1;

  // Push some elements onto stk1
  stk1.Push(10);
  stk1.Push(20);
  stk1.Push(30);

  // Access and print the top element of stk1
  std::cout << "Top element of stk1: " << stk1.Top() << std::endl;

  // Pop elements from stk1
  stk1.Pop();
  stk1.Pop();

  // Print the number of elements in stk1
  std::cout << "Number of elements in stk1: " << stk1.Count() << std::endl;

  // Create a copy of stk1 using the copy constructor
  Stack<int> stk2(stk1);

  // Create a stack object stk3
  Stack<int> stk3;

  // Assign stk1 to stk3 using the copy assignment operator
  stk3 = stk1;
  cout << "Top is " << stk3.Top() << endl;
}