#pragma once
template <class T>
class Stack {
 public:
  Stack(int = 10);
  ~Stack() {
    delete[] stackPtr;
  }
  int push(const T&);
  // pop an element off the stack
  int pop(T&);
  int isEmpty() const {
    return top == -1;
  }
  int isFull() const {
    return top == size - 1;
  }

 private:
  // Number of elements on Stack
  int size;
  int top;
  T* stackPtr;
};

//constructor with the default size 10
template <class T>
Stack<T>::Stack(int s) : size(s) {
  // initialize stack
  top = -1;
  stackPtr = new T[size];
}
// push an element onto the Stack
template <class T>
int Stack<T>::push(const T& item) {
  if (!isFull()) {
    stackPtr[++top] = item;
    // push successful
    return 1;
  }
  // push unsuccessful
  return 0;
}

// pop an element off the Stack
template <class T>
int Stack<T>::pop(T& popValue) {
  if (!isEmpty()) {
    popValue = stackPtr[top--];
    // pop successful
    return 1;
  }
  // pop unsuccessful
  return 0;
}
