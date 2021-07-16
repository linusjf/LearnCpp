template <class T>
class Z {
 public:
  Z(){};
  ~Z(){};
  void f(){};
  void g(){};
};

template class Z<int>;
  //explicit instantiation of class Z<float>
template class Z<float>;

template <class T>
void Test([[maybe_unused]] T r_t){};

template void Test<int>(int);

int main() {
  //explicit instantiation of class Z<int>
  return 0;
}
