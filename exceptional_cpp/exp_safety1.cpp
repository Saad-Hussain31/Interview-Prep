/*
exception-safe (works properly in the presence of exceptions)

exception-neutral (propagates all exceptions to the caller,
without causing integrity problems in a Stack object)

*/
#include <iostream>
using namespace std;

template <class T> class Stack {
public:
  Stack();
  ~Stack();

private:
  T *v_;         // ptr to a memory area big
  size_t vsize_; // enough for 'vsize_' T's
  size_t vused_; // # of T's actually in use
};

template <class T>
Stack<T>::Stack()
    : v_(0), vsize_(10), vused_(0) // nothing used yet
{
  v_ = new T[vsize_]; // initial allocation
}

template <class T> Stack<T>::~Stack() {
  delete[] v_; // this can't throw
}
