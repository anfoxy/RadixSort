#include <iostream>
#include <string>
#include <cstring>
#include"TRadixSort.h"
using namespace std;
void printArray(int ar[], int arCount)
{
  for (int i = 0; i < arCount; ++i)
    cout << ar[i] << " ";
  cout << endl;

}
void main() 
{
  setlocale(LC_ALL, "Russian");
#define TESTS3
#ifdef TESTS3
// 3. TCBQueue tests
cout << "3. TCBQueue tests:" << endl;
{
  TCBQueue<int> queue(3);
  cout << "Test 1. queue.isEmpty(). Expected: " << true << " , actual: " << queue.isEmpty() << endl;
  queue.Put(10);
  cout << "Test 2. queue.isEmpty(). Expected: " << false << " , actual: " << queue.isEmpty() << endl;
  cout << "Test 3. queue.Get(). Expected: " << 10 << " , actual: " << queue.Get() << endl;
  cout << "Test 4. queue.isEmpty(). Expected: " << true << " , actual: " << queue.isEmpty() << endl;
  queue.Put(10);
  queue.Put(20);
  queue.Put(30);
  cout << "Test 5. queue.printQue()." << endl;
  cout << "\tExpected: 10 20 30" << endl;
  cout << "\tActual:  ";
  queue.printQue();
  cout << endl;
  cout << "Test 6. queue.isFull(). Expected: " << true << " , actual: " << queue.isFull() << endl;
  cout << "Test 7. queue.Get(). Expected: " << 10 << " , actual: " << queue.Get() << endl;

  TCBQueue<double> queue2;
  queue2.Put(10.5);
  cout << "Test 8. queue2.Get(). Expected: " << 10.5 << " , actual: " << queue2.Get() << endl;
  cout << endl;
}
#else
#endif
#define TESTS4
#ifdef TESTS4
  // 4. TRadixSort tests
  cout << "3. TRadixSort tests:" << endl;
  {
    int arSRT[7] = { 301, 102, 127, 453, 874, 472, 311 };
    int arCNT = 7;

    cout << "Исходный массив: ";
    printArray(arSRT, arCNT);

    TRadixSort<int> radixSort(arSRT, arCNT, 9);


    cout << "Сортированный массив: ";
    radixSort.doRadixSort();
    cout << endl;
  }
  {
    int arSRT[7] = { 1, 10, 7, 53, 8, 47, 311 };
    int arCNT = 7;

    cout << "Исходный массив: ";
    printArray(arSRT, arCNT);

    TRadixSort<int> radixSort(arSRT, arCNT, 9);


    cout << "Сортированный массив: ";
    radixSort.doRadixSort();
    cout << endl;
  }
#else
#endif
  getchar();
  getchar();
}