//////////////////////////////////
// By:                         //
// Mia "Connor" Sculthorpe    //
// 16 October 2024           //
// TO: 16 October 2024      //
/////////////////////////////

#include <vector>
#include <random>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class OneDimVector {
private:
		vector<int> ODVectorSmall;
		vector<int> ODVectorMed;
		vector<int> ODVectorLarge;
		int SmallSize = 64;
		int MedSize = 256;
		int LargeSize = 2048;
public:
	void GenerateVector(int sizeOfVector, vector<int> vector);
	void GenerateVectorHelper();
	clock_t PeakFindStraightforward();
	clock_t PeakFindRecursive();
	void PrintVectorToWindow();
};



void OneDimVector::GenerateVector(int sizeOfVector, vector<int> vectorToInitialize) {
	for (int i = 0; i < sizeOfVector; i++) {
		int temp = rand();
		vectorToInitialize.push_back(temp);
	}
}

void OneDimVector::GenerateVectorHelper() {
	GenerateVector(SmallSize, ODVectorSmall);
	GenerateVector(MedSize, ODVectorMed);
	GenerateVector(LargeSize, ODVectorLarge);
}



clock_t OneDimVector::PeakFindStraightforward() {
	clock_t ticks = clock(); // Create our clock




	ticks = clock() - ticks; // The difference between the start and finish
	return ticks;
}



clock_t OneDimVector::PeakFindRecursive() {

	return clock_t();
}



void OneDimVector::PrintVectorToWindow() {

}
