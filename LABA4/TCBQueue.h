#pragma once
#include <iostream>
#include <string>

using namespace std;
template <class T>

class TCBQueue

{

private:

  T *mem; // Массив памяти под очередь

  int size_mem; // Длина массива mem

  int iFirst; // Индекс первого элемента очереди

  int iLast; // Индекс последнего элемента очереди
  int count;

public:

  TCBQueue(int _size_mem = 10); //Конструктор

  ~TCBQueue(); //Деструктор

  bool isEmpty(); //Проверка на пустоту

  bool isFull(); //Проверка стека на наполненность

  void Put(T temp); //Поставить элемент в очередь

  T Get(); //Взять элемент из очереди

private:

  int getNextIndex(int _index); // Дай индекс следующего элемента

public:

  void printQue(); // Вывести очередь на консоль

};

template<class T>
TCBQueue<T>::TCBQueue(int _size_mem)
{
  size_mem = _size_mem;
  mem = new T[size_mem];
  iFirst = 0;
  iLast = -1;
  count = 0;

}

template<class T>
inline TCBQueue<T>::~TCBQueue()
{
  delete[]mem;
  size_mem = 0;
  iFirst = 0;
  iLast = 0;
  count = 0;
}

template<class T>
int TCBQueue<T>::getNextIndex(int _index) { return ++_index % size_mem; }

template<class T>
bool TCBQueue<T>::isEmpty(void) { return count == 0; }

template<class T>
bool TCBQueue<T>::isFull(void) { return count == size_mem; }

template<class T>
void  TCBQueue<T>::Put(T temp)
{

  count++;
  iLast=getNextIndex(iLast);
  
  mem[iLast] = temp;
}

template<class T>
T TCBQueue<T>::Get(void)
{
  count--;
  iFirst= getNextIndex(iFirst);
  return mem[iFirst-1];
}

template<class T>
void  TCBQueue<T>::printQue(void)
{

  for (int i = iFirst; i < count+1; i++)
    cout << " " << mem[i% size_mem];

}
