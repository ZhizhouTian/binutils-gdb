extern "C" {
#include <stdio.h>
}


class A {
public:
  A();
  int foo (int x);
  int bar (int y);
  virtual int baz (int z);
  char c;
  int  j;
  int  jj;
  static int s;
};

class B {
public:
  static int s;
};

int A::s = 10;
int B::s = 20;

A::A()
{
  c = 'x';
  j = 5;
}

int A::foo (int dummy)
{
  j += 3;
  return j + dummy;
}

int A::bar (int dummy)
{
  int r;
  j += 13;
  r = this->foo(15);
  return r + j + 2 * dummy;
}

int A::baz (int dummy)
{
  int r;
  j += 15;
  r = this->foo(15);
  return r + j + 12 * dummy;
}

int fum (int dummy)
{
  return 2 + 13 * dummy;
}

typedef int (A::*PMF)(int);

typedef int A::*PMI;

int main ()
{
  A a;
  A * a_p;
  PMF pmf;

  PMF * pmf_p;
  PMI pmi;

  a.j = 121;
  a.jj = 1331;
  
  int k;

  a_p = &a;

  pmi = &A::j;
  pmf = &A::bar;
  pmf_p = &pmf;

  pmi = NULL;
  
  k = (a.*pmf)(3);

  pmi = &A::jj;
  pmf = &A::foo;
  pmf_p = &pmf;

  k = (a.*pmf)(4);

  k = (a.**pmf_p)(5);

  k = a.*pmi;
  

  k = a.bar(2);

  k += fum (4);

  B b;

  k += b.s;
  
}
