// CREATED BY MUHAMMAD HANAN ASGHAR
// PYTHONIST
#include <iostream>
using namespace std;
class BinaryMinHeap{
  private:
  int *heap;
  int heapSize;
  int arraySize;
  int getParent(int index){
    return (index - 1) / 2;
  }
  int getRight(int index){
    return (2 * index) + 2;
  }
  int getLeft(int index){
    return (2 * index) + 1;
  }
  void swap(int i,int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
  }
  bool hasLeft(int index){
    return getLeft(index) < heapSize;
  }
  bool hasRight(int index){
    return getRight(index) < heapSize;
  }
  public:
  BinaryMinHeap(int size){
    heap = new int[size];
    heapSize = 0;
    arraySize = size;
  }
  void heapifyUP(int index){
    if(index!=0){
      int parent = getParent(index);
      if(heap[parent] > heap[index]){
        swap(parent,index);
        heapifyUP(parent);
      }
    }
  }
  void InsertData(int data){
    if(heapSize == arraySize){
      return;
    }else{
      heapSize++;
      heap[heapSize - 1] = data;
      heapifyUP(heapSize - 1);
    }
  }
  void Display(){
    for(int i = 0;i<heapSize;i++){
        cout<<heap[i]<<" - ";
    }
  }
  void heapifyDown(int index){
    int left = getLeft(index);
    int right = getRight(index);
    int min = index;
    if(heap[left] && heap[left] < heap[min]){
      min = left;
    }
    if(heap[right] && heap[right] < heap[min]){
      min = right;
    }
    if(min != index){
      swap(index,min);
      heapifyDown(min);
    }
  }
  int Remove(){
    if(heapSize == 0){
      return -1;
    }else{
      int root = heap[0];
      heap[0] = heap[heapSize - 1];
      heapSize--;
      if(heapSize > 1){
        heapifyDown(0);
        return root;
      }
    }
  }
};

int main() {
  BinaryMinHeap b(10);
  b.InsertData(12);
  b.InsertData(32);
  b.InsertData(124);
  b.InsertData(45);
  b.InsertData(34);
  b.InsertData(103);
  b.Display();
  cout<<endl;
  b.Remove();
  b.Display();
  cout<<endl;
  b.Remove();
  b.Display();
}
