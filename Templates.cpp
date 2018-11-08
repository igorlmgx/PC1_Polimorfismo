#include <iostream>
using namespace std;

template <typename Tgenerico>
Tgenerico Maior (Tgenerico x, Tgenerico y) {
  if(x > y)
    return x;
  else
    return y;
}

template <class T>
void printArray(const T *array, const int n) {
  for(int i = 0; i < n; i++) {
    cout << array[i] << " \n";
  }
}

int main() {

  int x[7] = {1, 3, 2, 6, 1, 3, 6};

  char c[3] = {'h', 'u', 'e'};

  printArray(x, 7);

  printArray(c, 3);


  return 0;
}
