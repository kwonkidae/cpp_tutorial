#include <iostream>
using namespace std;

class Person
{
};

class Employee : public Person
{
public:
  Employee(string fName, string lName, double sal)
  {
    FirstName = fName;
    LastName = lName;
    salary = sal;
  }

  string FirstName;
  string LastName;
  double salary;

  void show()
  {
    cout << "First Name: " << FirstName << " Last Name: " << LastName;
  }

  void addBonus(double bonus)
  {
    salary += bonus;
  }
};

class Manager : public Employee
{
public:
  Manager(string fName, string lName, double sal, double comm) : Employee(fName, lName, sal)
  {
    Commission = comm;
  }

  double Commission;
  double getComm()
  {
    return Commission;
  }
};

class Clerk : public Employee
{
public:
  Clerk(string fName, string lName, double sal, Manager *man) : Employee(fName, lName, sal)
  {
    manager = man;
  };
  Manager *manager;
  Manager *getManager()
  {
    return manager;
  }
};

void congratulate(Employee *emp)
{
  cout << "Happy Birthday!!!" << endl;
  emp->addBonus(200);
  emp->show();
}

int main()
{
  Employee *emp;

  Manager m1("Steve", "Kent", 3000, 0.2);
  Clerk c1("Kevin", "Jones", 1000, &m1);

  emp = &m1;

  cout << emp->FirstName << endl;
  cout << emp->salary << endl;

  Employee e1("Peter", "Green", 1400);

  Manager *m3 = (Manager *)(&e1);
  m3->Commission = 4000;
  if (m3)
    cout << m3->getComm() << endl;
  else
    cout << "Can't cast from Employee to Manager" << endl;
  // cout << emp->getComm();

  congratulate(&c1);
  congratulate(&m1);

  cout << "Manager of " << c1.FirstName << " is " << c1.getManager()->FirstName;
}
