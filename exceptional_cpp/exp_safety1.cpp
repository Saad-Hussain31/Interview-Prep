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

public:
  T *v_;         // ptr to a memory area big
  size_t vsize_; // enough for 'vsize_' T's
  size_t vused_; // # of T's actually in use
};

template <class T> T *NewCopy(T *src, size_t src_size, size_t dest_size) {
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
    : v_(NewCopy(other.v_, other.vsize_, other.vused_)), vsize_(other.vsize_),
      vused_(other.vused_) {}

template <class T> Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
  if (this != other) { // ensures safety and independence of the program's
                       // state.
    T *new_v = NewCopy(other.v_, other.vsize_, other.vused_);
    delete v_;
    v_ = new_v;
    vsize_ = other.vsize_;
    vsize_ = other.vused_;
  }
  return *this;
}
