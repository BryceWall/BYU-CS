#include <iostream>
#include <fstream> 
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <array>
#include "QS.h"
using namespace std;


QS::QS() {}


QS::~QS() { 
  delete[]qsArray;
  qsArray = nullptr;
}


void QS::sortAll(){
  quicksort(0,qsIndex-1);
}


void QS::quicksort(int left, int right){
  int pivot = medianOfThree(left, right);
  if(pivot < 0) {
    return;
  }
  
  pivot = partition(left, right, pivot);
  quicksort(left, pivot - 1);
  quicksort(pivot + 1, right);
}


int QS::medianOfThree(int left, int right){
    
  int middle = (left + right)/2;
  
  if(qsIndex == 0 || right >= qsIndex || left < 0 || left >= right) {
    return -1;
  }
  
  else{
    if(qsArray[left] > qsArray[middle]) {
      swap(qsArray[left],qsArray[middle]);
    }
    if(qsArray[right] < qsArray[left]) {
      swap(qsArray[right],qsArray[left]);
   }
    if(qsArray[middle] > qsArray[right]) {
      swap(qsArray[middle],qsArray[right]);
    }
    return middle;
  }
}


int QS::partition(int left, int right, int pivotIndex){

  if(right >= qsIndex || left >= right || left < 0 || qsArray == 0 || pivotIndex < left || pivotIndex > right) { 
			return -1;
  }

  swap(qsArray[left], qsArray[pivotIndex]);
  int up = left + 1;
  int down = right;

  do {
    while(qsArray[up] <= qsArray[left] && up != right) {
      up++;
    }
    while(qsArray[down] > qsArray[left] && down != left) {
      down--;
    }
    if(up < down) {
      swap(qsArray[up], qsArray[down]);
    }
  } while (up < down);
  swap(qsArray[left], qsArray[down]);

  return down;
}


string QS::getArray() const{
  string arrayStr = "";

    for(int i = 0; i < qsIndex; i++) {
      if(i < qsIndex-1) {
        arrayStr += to_string(qsArray[i]) + ",";
      }
      else {
        arrayStr += to_string(qsArray[i]);
      }
    }
  return arrayStr; 
}


int QS::getSize() const{
  // int qsSize = sizeof(qsArray)/sizeof(qsArray[0]);
  return qsIndex;
}


bool QS::addToArray(int value){

  if(qsIndex == currCapacity || qsArray == 0) {
    return false;
  }

  qsArray[qsIndex] = value;
  qsIndex++;
  return true;
}


bool QS::createArray(int capacity) {
  clear();
      
  if(capacity <= 0) {
    return false;
  }
  else {
    currCapacity = capacity;
    qsArray = new int[capacity];
    qsIndex = 0;
    return true;
  }
}


void QS::clear(){
  if(qsArray != 0){
    delete[]qsArray;
  }

  qsArray = 0;
  qsIndex = 0;
  currCapacity = 0;
}