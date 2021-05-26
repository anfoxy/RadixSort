#pragma once
#include <iostream>
#include <string>

using namespace std;
template <class T>

class TCBQueue

{

private:

  T *mem; // ������ ������ ��� �������

  int size_mem; // ����� ������� mem

  int iFirst; // ������ ������� �������� �������

  int iLast; // ������ ���������� �������� �������
  int count;

public:

  TCBQueue(int _size_mem = 10); //�����������

  ~TCBQueue(); //����������

  bool isEmpty(); //�������� �� �������

  bool isFull(); //�������� ����� �� �������������

  void Put(T temp); //��������� ������� � �������

  T Get(); //����� ������� �� �������

private:

  int getNextIndex(int _index); // ��� ������ ���������� ��������

public:

  void printQue(); // ������� ������� �� �������

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
