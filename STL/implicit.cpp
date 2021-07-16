template <class T>
class Z {
 public:
  Z(){};
  ~Z(){};
  void f(){};
  void g(){};
};

int main() {
  //implicit instantiation generates class Z<int>
  Z<int> zi;
  //and generates function Z<int>::f()
  zi.f();
  //implicit instantiation generates class Z<float>
  Z<float> zf;
  //and generates function Z<float>::g()
  zf.g();
  return 0;
}
