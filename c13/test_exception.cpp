#include <iostream>

#include "DBConnection.h"

using namespace std;

void foo()
{
  DBConnection conn(4);
  cout << "conn.get = " << conn.get() << endl;
}

int main(int argc,char* argv[])
{
  foo();
  return 0;
}

