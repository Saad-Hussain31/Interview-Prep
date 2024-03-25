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
  T Pop(); // if empty, throws exception

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
    std::copy(src, src + src_size, dest_size);
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

template <class T> T Stack<T>::Pop() {}

template <class T> size_t Stack<T>::Count() const { return vused_; }

int main() {

  Stack<int> stk1;
  Stack<int> stk2 = stk1;

  Stack<int> stk3;
  stk3 = stk1;
}