#include <iostream>
using namespace std;
class Base
{
public:
  virtual ~Base()
  {
    std::cout << "Base destructor!" << std::endl;
  }
};

class Derived : public Base
{
public:
  char *largeBuffer;
  Derived()
  {
    largeBuffer = new char[3000];
  }

  ~Derived()
  {
    std::cout << "Derived destructor!" << endl;
  }
};

int main()
{
  cout << "---Derived* der1 = new Derived()---" << endl;
  Derived *der1 = new Derived();
  delete der1;

  cout << "\n\n---Base* der2 = new Derived()---" << endl;
  Base *der2 = new Derived();
  delete der2;
}
