#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {
 private:
  // elements
  vector<T> elems;  
 public:
  // push element
  void push(T const&);  
  // pop element
  void pop();           
  // return top element
  T top() const;        
  bool empty() const {  
    // return true if empty.
    return elems.empty();
  }
};

template <class T>
void Stack<T>::push(T const& elem) {
  // append copy of passed element
  elems.push_back(elem);
}

template <class T>
void Stack<T>::pop() {
  if (elems.empty()) {
    throw out_of_range("Stack<>::pop(): empty stack");
  }
  // remove last element
  elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
  if (elems.empty()) {
    throw out_of_range("Stack<>::top(): empty stack");
  }
  // return copy of last element
  return elems.back();
}

int main() {
  try {
    // stack of ints
    Stack<int> intStack;        
    // stack of strings
    Stack<string> stringStack;  
    // manipulate int stack
    intStack.push(7);
    cout << intStack.top() << endl;
    // manipulate string stack
    stringStack.push("hello");
    cout << stringStack.top() << std::endl;
    stringStack.pop();
    stringStack.pop();
  } catch (exception const& ex) {
    clog << "Exception: " << ex.what() << endl;
    return -1;
  }
}
