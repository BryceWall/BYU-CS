#include <iostream>
#include <fstream> 
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <array>
#include "QSInterface.h"
using namespace std;


class QS: public QSInterface {

private:
  int* qsArray = nullptr;
  int qsIndex = 0;
  int currCapacity = 0;

public:

	QS();
	~QS(); //FIXME virtual?

  void sortAll();
  
  void quicksort(int left, int right);

	int medianOfThree(int left, int right);

	int partition(int left, int right, int pivotIndex);

  string getArray() const;

	int getSize() const;

	bool addToArray(int value);

	bool createArray(int capacity);

	void clear();
  
  // protected:
  // int* qsArray = nullptr;
  // int qsIndex = 0;
};