template <class T>
class Z {
 public:
  Z(){};
  ~Z(){};
  void f(){};
  void g(){};
};

int main() {
  //instantiation of class Z<int> not required
  [[maybe_unused]] Z<int>* p_zi;
  //instantiation of class Z<float> not required
  [[maybe_unused]] Z<float>* p_zf;
  return 0;
}
