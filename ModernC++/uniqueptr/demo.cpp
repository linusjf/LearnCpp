#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

using namespace std;

// helper class for runtime polymorphism demo below
struct B {
  virtual void bar() { cout << "B::bar\n"; }
  virtual ~B() = default;
};
struct D : B
{
    D() { cout << "D::D\n";  }
    ~D() { cout << "D::~D\n";  }
    void bar() override { cout << "D::bar\n";  }
};
 
// a function consuming a unique_ptr can take it by value or by rvalue reference
unique_ptr<D> pass_through(unique_ptr<D> p)
{
    p->bar();
    return p;
}
 
// helper function for the custom deleter demo below
void close_file(FILE* fp) { fclose(fp); }
 
// unique_ptr-based linked list demo
struct List {
  struct Node {
    int data;
    unique_ptr<Node> next;
    Node(int data) : data{data}, next{nullptr} {}
  };
  List() : head{nullptr} {};
  // N.B. iterative destructor to avoid stack overflow on long lists
  ~List() { while(head) head = move(head->next); }
  // copy/move and other APIs skipped for simplicity
  void push(int data) {
    auto temp = make_unique<Node>(data);
    if(head) temp->next = move(head);
    head = move(temp);
  }
private:
  unique_ptr<Node> head;
};
 
int main()
{
  cout << "1) Unique ownership semantics demo\n";
  {
      auto p = make_unique<D>(); // p is a unique_ptr that owns a D
      auto q = pass_through(move(p)); 
      assert(!p); // now p owns nothing and holds a null pointer
      q->bar();   // and q owns the D object
  } // ~D called here
 
  cout << "2) Runtime polymorphism demo\n";
  {
    unique_ptr<B> p = make_unique<D>(); // p is a unique_ptr that owns a D
                                                  // as a pointer to base
    p->bar(); // virtual dispatch
 
    vector<unique_ptr<B>> v;  // unique_ptr can be stored in a container
    v.push_back(make_unique<D>());
    v.push_back(move(p));
    v.emplace_back(new D);
    for(auto& p: v) p->bar(); // virtual dispatch
  } // ~D called 3 times
 
  cout << "3) Custom deleter demo\n";
  ofstream("demo.txt") << 'x'; // prepare the file to read
  {
      unique_ptr<FILE, decltype(&close_file)> fp(fopen("demo.txt", "r"),
                                                           &close_file);
      if(fp) // fopen could have failed; in which case fp holds a null pointer
        cout << (char)fgetc(fp.get()) << '\n';
  } // fclose() called here, but only if FILE* is not a null pointer
    // (that is, if fopen succeeded)
 
  cout << "4) Custom lambda-expression deleter demo\n";
  {
    unique_ptr<D, function<void(D*)>> p(new D, [](D* ptr)
        {
            cout << "destroying from a custom deleter...\n";
            delete ptr;
        });  // p owns D
    p->bar();
  } // the lambda above is called and D is destroyed
 
  cout << "5) Array form of unique_ptr demo\n";
  {
      unique_ptr<D[]> p(new D[3]);
  } // calls ~D 3 times
 
  cout << "6) Linked list demo\n";
  {
    List l;
    for(long n = 0; n != 1'000'000; ++n) l.push(n);
    cout << "destroying 1'000'000 nodes... ";
  } // destroys all 1 million nodes
  cout << "Done.\n";
}
