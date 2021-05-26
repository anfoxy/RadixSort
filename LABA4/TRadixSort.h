#pragma once
#include"TCBQueue.h"
// Класс TRadixSort - поразрядная сортировка ++++++++++++++++++++++++++++++++

template <class T>

class TRadixSort // Поразрядная сортировка

{

private:

  T* arValue; // Массив сортируемых значений

  int arCount; // Количество сортируемых значений

  int valCount; // Максимальное значение разряда

  int digCount; // Максимальное количество разрядов

  TCBQueue<T>** queArr; // Массив очередей для представления карманов

public:

  TRadixSort(T* _arValue, int _arCount, int _valCount); // Конструктор

  ~TRadixSort(); // Деструктор

  void doRadixSort(); // Выполнить поразрядную сортировку

private:

  int setDigCount(T* arValue, int _arCount); // Установить Максимальное количество разрядов

  void countSort(T * _arValue, int _arCount, int _digCount);

  void printARR(); // Вывести массив

};

template<class T>
TRadixSort<T>::TRadixSort(T *_arValue, int _arCount, int _valCount)
{
  arCount = _arCount;
  valCount = _valCount;
  arValue = new T[arCount];

  for (int i = 0; i < arCount; i++) 
  {
    arValue[i] = _arValue[i];
  }
  digCount = 1;
  queArr = new  TCBQueue<T>*[arCount];

}

template<class T>
TRadixSort<T>::~TRadixSort()
{
  delete[]queArr;
  arValue = 0;
  arCount = 0;
  valCount = 0;
  digCount = 0;
}

template<class T>
void TRadixSort<T>::doRadixSort()
{
  int m = setDigCount(arValue, arCount);
  for (digCount = 1; m / digCount > 0; digCount *= 10)
    countSort(arValue, arCount, digCount);
  printARR();
}

template<class T>
int TRadixSort<T>::setDigCount(T* arValue, int _arCount)
{
  int mx = arValue[0];
  for (int i = 1; i < _arCount; i++)
    if (arValue[i] > mx)
      mx = arValue[i];
  return mx;
}

template<class T>
void TRadixSort<T>::countSort(T* _arValue, int _arCount, int _digCount)
{
  int* output = new int[_arCount]; 
  int i, count[10] = { 0 };
  for (i = 0; i < _arCount; i++)
    count[(_arValue[i] / _digCount) % 10]++;
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (i = _arCount - 1; i >= 0; i--) {
    output[count[(_arValue[i] / _digCount) % 10] - 1] = _arValue[i];
    count[(_arValue[i] / _digCount) % 10]--;
  }
  for (i = 0; i < _arCount; i++)
    _arValue[i] = output[i];
  delete[] output;
}

template<class T>
 void TRadixSort<T>::printARR()
{
   for (int i = 0; i < arCount; ++i)
     cout << arValue[i] << " ";
   cout << endl;
}
