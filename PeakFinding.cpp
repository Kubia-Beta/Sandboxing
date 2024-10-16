//////////////////////////////////
// By:                         //
// Mia "Connor" Sculthorpe    //
// 16 October 2024           //
// TO: 16 October 2024      //
/////////////////////////////

/* This program was a one day exercise in practicing multithreading. Any commits after
*  16 Oct 2024 are either improvements or documentation, not fucntion.
*  This was a simple personal project to help me stay motivated during the job search.
*/

#include <vector>
#include <random> // how we generate our vectors
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono> // high res clock
#include <iomanip> // set precision
#include <algorithm> // for max
#include <future> // async
#include <thread> // multithreading
#include <math.h> // power function

using namespace std;

class OneDimVector {
private:
		int SmallSize = pow(2,23);
		int MedSize = pow(2,25);
		int LargeSize = pow(2,28);
		vector<int> ODVectorSmall = vector<int>(SmallSize);
		vector<int> ODVectorMed = vector<int>(MedSize);
		vector<int> ODVectorLarge = vector<int>(LargeSize);
		void CountPeaksInSegment(vector<int>& vectorToTraverse, int start, int end, promise<int> peakCountPromise);
		bool isPeak(const vector<int>& vec, int index);
public:
	void GenerateVector(int sizeOfVector, vector<int>& vector);
	void GenerateVectorHelper();
	double PeakFindStraightforward(vector<int> vectorToTraverse);
	double PeakFindCountMultithreaded(vector<int>& vectorToTraverse, int numThreads);
	vector<double> StraightForwardHelper();
	vector<double> MultithreadedHelper();
};


//FIXME: Document the asymptote of each of these
//FIXME: Give each function a @param and @return
void OneDimVector::CountPeaksInSegment(vector<int>& vectorToTraverse, int start, int end, promise<int> peakCountPromise) {
	int peakCount = 0;

	// Iterate over the segment to count peaks
	for (int i = start + 1; i < end - 1; i++) {
		if (isPeak(vectorToTraverse, i)) {
			peakCount++;
		}
	}
	peakCountPromise.set_value(peakCount); // Set the peak count result
}



bool OneDimVector::isPeak(const vector<int>& vec, int index) {
	if (index <= 0 || index >= vec.size() - 1) return false; // Out of bounds
	return vec[index] > vec[index - 1] && vec[index] > vec[index + 1]; // Peak condition
}



void OneDimVector::GenerateVector(int sizeOfVector, vector<int>& vectorToInitialize) {
	auto start = chrono::high_resolution_clock::now();
	//vectorToInitialize.reserve(sizeOfVector); // Reserve the memory in advance to massively cut compute time
	random_device rd; // seed
	mt19937 generator(rd()); // Mersenne Twister engine
	uniform_int_distribution<int> distribution(0, 99); // Numerical range

	for (int i = 0; i < sizeOfVector; i++) { // Fill the vector
		//vectorToInitialize.push_back(distribution(generator)); // slow
		vectorToInitialize[i] = distribution(generator); // Direct assignment, access the underlying array, fast
	} // on n = 204,800,000 push_back is ~20s, [i] is 12.4s.
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Finished generating vector of size " << vectorToInitialize.size() << " in " << elapsed.count()
		<< " seconds.\n";
	
}



void OneDimVector::GenerateVectorHelper() {
	GenerateVector(SmallSize, ODVectorSmall);
	GenerateVector(MedSize, ODVectorMed);
	GenerateVector(LargeSize, ODVectorLarge);
}



double OneDimVector::PeakFindStraightforward(vector<int> vectorToTraverse) {
	auto start = chrono::high_resolution_clock::now(); // Start high-res timer
	int previous = 0;
	int current = 0;
	int next = 0;
	int peakCount = 0;
	for (int i = 0; i < vectorToTraverse.size() - 1; i++) { // Traverse the entire vector
		current = vectorToTraverse.at(i);
		next = vectorToTraverse.at(i + 1);
		if (current > next && current > previous) { // Found a peak
			peakCount = peakCount++;
		}
		previous = current; // Move our current item to the backward comparison
	}



	auto end = chrono::high_resolution_clock::now();
	cout << "Total peaks found: " << peakCount << endl;
	return std::chrono::duration<double>(end - start).count();
}



double OneDimVector::PeakFindCountMultithreaded(vector<int>& vectorToTraverse, int numThreads) {
	auto startTime = chrono::high_resolution_clock::now();

	int vectorSize = vectorToTraverse.size();
	int segmentSize = vectorSize / numThreads;

	// Store futures for peak counts from each thread
	vector<future<int>> futures;

	// Launch threads to search each segment
	for (int i = 0; i < numThreads; ++i) {
		int start = i * segmentSize;
		int end = (i == numThreads - 1) ? vectorSize : start + segmentSize + 1; // Check overlap

		promise<int> peakCountPromise;
		futures.push_back(peakCountPromise.get_future());

		// Launch a thread to count peaks in the segment [start, end)
		thread t(&OneDimVector::CountPeaksInSegment, this, ref(vectorToTraverse), start, end, move(peakCountPromise));
		t.detach(); // Detach threads to allow parallel execution
	}

	// Accumulate the total number of peaks from all futures
	int totalPeaks = 0;
	for (auto& f : futures) {
		totalPeaks += f.get(); // Add up the peak counts from all segments
	}

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = endTime - startTime;

	cout << "Total peaks found: " << totalPeaks << endl;

	return elapsed.count(); // Return elapsed time in seconds
}



vector<double> OneDimVector::StraightForwardHelper() {
	vector<double> timePassed;
	cout << "Now running the straightforward algorithm.\n";
	timePassed.push_back(PeakFindStraightforward(ODVectorSmall));
	timePassed.push_back(PeakFindStraightforward(ODVectorMed));
	timePassed.push_back(PeakFindStraightforward(ODVectorLarge));

	return timePassed;
}



vector<double> OneDimVector::MultithreadedHelper() {
	vector<double> timePassed;
	int numThreads = thread::hardware_concurrency(); // This grabs your machines max number of threads
	cout << "Now running multithreaded algorithm with " << numThreads << " threads.\n";
	timePassed.push_back(PeakFindCountMultithreaded(ODVectorSmall, numThreads));
	timePassed.push_back(PeakFindCountMultithreaded(ODVectorMed, numThreads));
	timePassed.push_back(PeakFindCountMultithreaded(ODVectorLarge, numThreads));

	return timePassed;
}



int main() {
	unique_ptr<OneDimVector> oneDimVector = make_unique<OneDimVector>(); // Automatic memory management object
	cout << "Beginning Generation. This may take a while.\n";
	oneDimVector->GenerateVectorHelper();
	cout << "Generation finished.\n";
	vector<double> timePassed = oneDimVector->StraightForwardHelper();
	for (int i = 0; i < timePassed.size(); i++) {
		cout << fixed << setprecision(9) << timePassed.at(i) << endl;
	}
	cout << "Finished straightforward.\n";
	timePassed = oneDimVector->MultithreadedHelper();
	for (int i = 0; i < timePassed.size(); i++) {
		cout << fixed << setprecision(9) << timePassed.at(i) << endl;
	}

	return 0;
}