#include <iostream>
#include <type_traits>

template <class T1, class T2>
void print_is_same()
{
  std::cout << std::is_same<T1, T2>() << "\n";
}

int main()
{
  std::cout << std::boolalpha;

  print_is_same<int, int>();
  print_is_same<int, int &>();
  print_is_same<int, int &&>();

  print_is_same<int, std::remove_reference<int>::type>();
  print_is_same<int, std::remove_reference<int &>::type>();
  print_is_same<int, std::remove_reference<int &&>::type>();
  return 0;
}
