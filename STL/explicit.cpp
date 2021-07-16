template <class T>
class Z {
 public:
  Z(){};
  ~Z(){};
  void f(){};
  void g(){};
};

int main() {
  //explicit instantiation of class Z<int>
  [[maybe_unused]] typedef Z<int> ZInt;    
  //explicit instantiation of class Z<float>
  [[maybe_unused]] typedef Z<float> ZFloat;  
  return 0;
}
