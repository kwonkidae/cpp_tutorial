#include <iostream>
#include <memory>
using namespace std;

struct Foo
{
  Foo() { std::cout << "Foo...\n"; }
  ~Foo() { std::cout << "~Foo...\n"; }
};

struct D
{
  void operator()(Foo *p)
  {
    std::cout << "Calling delete for Foo object... \n";
    delete p;
  }
};

int main(void)
{
  std::cout << "Creating new Foo...\n";
  std::unique_ptr<Foo, D> up(new Foo(), D());

  std::cout << "Replace owned Foo with a new Foo...\n";
  up.reset(new Foo());

  std::cout << "Relace and delete the owned Foo...\n";
  up.reset(nullptr);
  return 0;
}
