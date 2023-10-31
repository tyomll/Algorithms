
#include <iostream>
#include <vector>



void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void heapTree(std::vector<int> &hT, int i)
{
  int size = hT.size();
  int largest = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;

  if (left < size && hT[left] > hT[largest])
  {
    largest = left;
  }
  if (right < size && hT[right] > hT[largest])
  {

    largest = right;
  }

  if (largest != i)
  {
    swap(&hT[i], &hT[largest]);
    heapTree(hT, largest);
  }
}

void insert(std::vector<int> &hT, int newNum)
{
  int size = hT.size() + 1;
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapTree(hT, i);
    }
  }
}

void deleteNum(std::vector<int> &hT, int num)
{
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
    {
      break;
    }
    else if (i == size - 1 && hT[i] != num)
    {
      return;
    }
  }
  swap(&hT[i], &hT[size - 1]);
  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapTree(hT, i);
  }
}

void printHeap(std::vector<int> &hT)
{
  for (int i = 0; i < hT.size(); i++)
  {
    std::cout << hT[i] << ",";
  }
  std::cout << std::endl;
}

void heapSort(std::vector<int> &hT, std::vector<int> &sH)
{
  int size = hT.size();

  for (int i = 0; i < size; i++)
  {

    sH.push_back(hT[0]);
    deleteNum(hT, hT[0]);
  }
}

int main()
{
  std::vector<int> heap;
  std::vector<int> sortedHeap;

  insert(heap, 10);
  insert(heap, 1);
  insert(heap, 2);
  insert(heap, 11);
  insert(heap, 0);
  insert(heap, 19);
  insert(heap, 20);

  printHeap(heap);

  heapSort(heap, sortedHeap);
  
  printHeap(sortedHeap);
}
