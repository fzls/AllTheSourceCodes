/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 sorts.cpp
* @version:
* @Time: 		 2015-09-11 08:57:02
* @Description:  Bubble/Insertion/Shell/Selection/Heap/Merge/Quick/Table/Bucket/Radix sort
*
+----------------------------------------------------------
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
#include <functional>
#include <queue>

using namespace std;

class SortTime
{
public:
	string algorithm;
	clock_t time;
public:
	SortTime(string s = "", clock_t t = 0): algorithm(s), time(t) {}
	~SortTime() {}
	bool operator<(const SortTime &st) const {
		return time < st.time;
	}

};

template<typename T> void InsertionSort(vector<T> &data) noexcept ;
template<typename T> void SelectionSort(vector<T> &data) noexcept ;
template<typename T> void BubbleSort(vector<T> & data) noexcept ;
template<typename T> void BubbleSort2(vector<T> & data) noexcept ;
template<typename T> void CombSort(vector<T> &data) noexcept ;
template<typename T> void ShellSort(vector<T> &data) noexcept ;
template<typename T> void moveDown(vector<T> &data, int first, int last) noexcept;
template<typename T> void HeapSort(vector<T> &data) noexcept ;
template<typename T> void QuickSort2(vector<T> &data, int first, int last) noexcept ;
template<typename T> void QuickSort2(vector<T> &data) noexcept ;
template<typename T> void QuickSort(vector<T> &data, int first, int last) noexcept;
template<typename T> void QuickSort(vector<T> &data) noexcept;
template<typename T> void MergeSort(vector<T> &data) noexcept;
template<typename T> void MergeSort(vector<T> &data, vector<T> &temp, int first, int last) noexcept;
template<typename T> void Merge(vector<T> &data, vector<T> &temp, int first, int last) noexcept;
template<typename T> void MergeSort_iter(vector<T> &data) noexcept;
template<typename T> void Merge_iter(vector<T> &data, vector<T> &temp, int size, int length) noexcept;
template<typename T> void Merge_iter(vector<T> &data, vector<T> &temp, int first, int mid, int last) noexcept;
//intenger only
void RadixSort(vector<int> &data);
void bitRadixsort(vector<int> &data);
void bitRadixsort(vector<int> &data, int b);
void CountingSort(vector<int> &data);//used only if the largest number in data is not too big, or it will be to expensive, for example, if the largest is 9999 9999 9999, then the required the space would be too much for a vector with that much elements, even if the elements are all ints;

//rethink the following two version of radixsort, which shows the beauty of the data structure
void inline clear(int& q) ;
int inline isEmpty(int q) ;
void radixsort2(vector<int> &data) ;
void bitRadixsort2(vector<int> &data);
void bitRadixsort2(vector<int> &data,  int b) ;

// int main() {
// 	int n;
// 	cin >> n;
// 	vector<int> tosort(n, 0);
// 	for (int i = 0; i < n; i++)
// 		cin >> tosort[i];

// 	// InsertionSort(tosort);
// 	// SelectionSort(tosort);
// 	// BubbleSort(tosort);
// 	// BubbleSort2(tosort);
// 	// QuickSort2(tosort);
// 	// QuickSort(tosort);
// 	// ShellSort(tosort);
// 	// std::sort(tosort);
// 	// bitRadixsort2(tosort);
// 	// stable_sort(tosort);
// 	// MergeSort_iter(tosort);
// 	// CountingSort(tosort);
// 	// CombSort(tosort);
// 	// bitRadixsort(tosort);
// 	// radixsort2(tosort);
// 	// HeapSort(tosort);
// 	// partial_sort(tosort);
// 	// RadixSort(tosort);
// 	MergeSort(tosort);

// 	for (int i = 0; i < n - 1; i++)
// 		cout << tosort[i] << " ";
// 	cout << tosort[n - 1] << endl;
// 	system("pause");

// }


int main() {
	freopen("sorts.in", "r", stdin);
	freopen("sorts.out", "w", stdout);
	clock_t time = = clock();
	default_random_engine e(time);
	int times;
	cin >> times;
	for (int t = 0; t < times; t++) {
		int n;
		cin >> n;
		vector<int> tosort, test_average, test_best, test_worst, test;
		vector<vector<int>> tests;
		time = clock();

		for (int i = 0; i < n; i++)
			tosort.push_back(e() % 1000000);
		test_average = tosort;
		sort(tosort.begin(), tosort.end());
		test_best = tosort;
		sort(tosort.begin(), tosort.end(), greater<int>());
		test_worst = tosort;
		tests.push_back(test_average);
		tests.push_back(test_best);
		tests.push_back(test_worst);
		time = clock() - time;
		cout << "        " << left << setw(15) << "prepaer time for" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" ;

		cout << endl << "-------------------------------the " << t + 1 << (t == 0 ? "st" : t == 1 ? "nd" : t == 2 ? "rd" : "th") << " test----------------------------------";

		for (int sort_or_not = 0; sort_or_not < 3; sort_or_not++) {
			cout << endl << "                           ****" << (sort_or_not == 0 ? " average" : sort_or_not == 1 ? " best" : " worst") << " case test****" << endl << endl;
			vector<SortTime> sorttime;


			test = tests[sort_or_not];
			time = clock();
			sort(test.begin(), test.end());
			time = clock() - time;
			sorttime.push_back(SortTime("sort", time));

			test = tests[sort_or_not];
			time = clock();
			stable_sort(test.begin(), test.end());
			time = clock() - time;
			sorttime.push_back(SortTime("stable_sort", time));

			test = tests[sort_or_not];
			time = clock();
			make_heap(test.begin(), test.end());
			sort_heap(test.begin(), test.end());
			time = clock() - time;
			sorttime.push_back(SortTime("sort_heap", time));

			test = tests[sort_or_not];
			time = clock();
			partial_sort(test.begin(), test.end() , test.end());
			time = clock() - time;
			sorttime.push_back(SortTime("partial_sort", time));


			test = tests[sort_or_not];
			time = clock();
			CombSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("CombSort", time));

			test = tests[sort_or_not];
			time = clock();
			CountingSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("CountingSort", time));

			test = tests[sort_or_not];
			time = clock();
			RadixSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("RadixSort", time));

			test = tests[sort_or_not];
			time = clock();
			radixsort2(test);
			time = clock() - time;
			sorttime.push_back(SortTime("radixsort2", time));

			test = tests[sort_or_not];
			time = clock();
			bitRadixsort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("bitRadixsort", time));

			test = tests[sort_or_not];
			time = clock();
			bitRadixsort2(test);
			time = clock() - time;
			sorttime.push_back(SortTime("bitRadixsort2", time));

			test = tests[sort_or_not];
			time = clock();
			MergeSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("MergeSort", time));

			test = tests[sort_or_not];
			time = clock();
			MergeSort_iter(test);
			time = clock() - time;
			sorttime.push_back(SortTime("MergeSort_iter", time));

			test = tests[sort_or_not];
			time = clock();
			QuickSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("QuickSort", time));

			test = tests[sort_or_not];
			time = clock();
			QuickSort2(test);
			time = clock() - time;
			sorttime.push_back(SortTime("QuickSort2", time));

			test = tests[sort_or_not];
			time = clock();
			ShellSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("ShellSort", time));

			test = tests[sort_or_not];
			time = clock();
			HeapSort(test);
			time = clock() - time;
			sorttime.push_back(SortTime("HeapSort", time));

			// test = tests[sort_or_not];
			// time = clock();
			// InsertionSort(test);
			// time = clock() - time;
			// sorttime.push_back(SortTime("InsertionSort", time));

			// test = tests[sort_or_not];
			// time = clock();
			// SelectionSort(test);
			// time = clock() - time;
			// sorttime.push_back(SortTime("SelectionSort", time));

			// test = tests[sort_or_not];
			// time = clock();
			// BubbleSort(test);
			// time = clock() - time;
			// sorttime.push_back(SortTime("BubbleSort", time));

			// test = tests[sort_or_not];
			// time = clock();
			// BubbleSort2(test);
			// time = clock() - time;
			// sorttime.push_back(SortTime("BubbleSort2", time));

			sort(sorttime.begin(), sorttime.end());
			for (SortTime k : sorttime)
				cout << left << setw(15) << k.algorithm << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << k.time << "    " << setw(8) << ((float)k.time) / CLOCKS_PER_SEC << " seconds" << endl;





		}
	}


	// system("pause");
	return 0;
}

// int main() {
// 	freopen("sorts.in", "r", stdin);
// 	freopen("sorts.out", "w", stdout);
// 	clock_t time;
// 	default_random_engine e(time);
// 	int times;
// 	cin >> times;
// 	for (int t = 0; t < times; t++) {
// 		int n;
// 		cin >> n;
// 		vector<int> tosort, test_average, test_best, test_worst, test;
// 		vector<vector<int>> tests;
// 		time = clock();

// 		for (int i = 0; i < n; i++)
// 			tosort.push_back(e() % 1000000);
// 		test_average = tosort;
// 		sort(tosort.begin(), tosort.end());
// 		test_best = tosort;
// 		sort(tosort.begin(), tosort.end(), greater<int>());
// 		test_worst = tosort;
// 		tests.push_back(test_average);
// 		tests.push_back(test_best);
// 		tests.push_back(test_worst);
// 		time = clock() - time;
// 		cout << "        " << left << setw(15) << "prepaer time for" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" ;

// 		cout << endl << "-------------------------------the " << t + 1 << (t == 0 ? "st" : t == 1 ? "nd" : t == 2 ? "rd" : "th") << " test----------------------------------";

// 		for (int sort_or_not = 0; sort_or_not < 3; sort_or_not++) {
// 			cout << endl << "                           ****" << (sort_or_not == 0 ? " average" : sort_or_not == 1 ? " best" : " worst") << " case test****" << endl << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			sort(test.begin(), test.end());
// 			time = clock() - time;
// 			cout << left << setw(15) << "sort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			stable_sort(test.begin(), test.end());
// 			time = clock() - time;
// 			cout << left << setw(15) << "stable_sort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			make_heap(test.begin(), test.end());
// 			sort_heap(test.begin(), test.end());
// 			time = clock() - time;
// 			cout << left << setw(15) << "sort_heap" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			partial_sort(test.begin(), test.end() , test.end());
// 			time = clock() - time;
// 			cout << left << setw(15) << "partial_sort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;



// 			test = tests[sort_or_not];
// 			time = clock();
// 			CombSort(test);
// 			time = clock() - time;
// 			cout << endl << left << setw(15) << "CombSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;


// 			test = tests[sort_or_not];
// 			time = clock();
// 			CountingSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "CountingSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			RadixSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "RadixSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			radixsort2(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "radixsort2" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			bitRadixsort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "bitRadixsort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			bitRadixsort2(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "bitRadixsort2" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			MergeSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "MergeSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			MergeSort_iter(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "MergeSort_iter" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			QuickSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "QuickSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			QuickSort2(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "QuickSort2" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			ShellSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "ShellSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			HeapSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "HeapSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			InsertionSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "InsertionSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			SelectionSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "SelectionSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			BubbleSort(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "BubbleSort" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

// 			test = tests[sort_or_not];
// 			time = clock();
// 			BubbleSort2(test);
// 			time = clock() - time;
// 			cout << left << setw(15) << "BubbleSort2" << " numbers: " << setw(5) << n << " : Clicks: " << setw(5) << time << "    " << setw(8) << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;



// 		}
// 	}


// 	// system("pause");
// 	return 0;
// }

template<typename T>
void InsertionSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	for (int i = 1, j; i < n; i++) {
		T temp = data[i];
		for (j = i; j > 0 && temp < data[j - 1]; j--)
			data[j] = data[j - 1];
		data[j] = temp;
	}
}

template<typename T>
void SelectionSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	for (int i = 0, j, least; i < n - 1; i++) {
		for (j = i + 1, least = i; j < n; j++)
			if (data[j] < data[least])
				least = j;
		if (least != i)
			swap(data[i], data[least]);
	}
}

template<typename T>
void BubbleSort(vector<T> & data) noexcept {
	int n = static_cast<int>(data.size());
	for (int i = 0, j; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (data[j] < data[j - 1])
				swap(data[j], data[j - 1]);
}

template<typename T>
void BubbleSort2(vector<T> & data) noexcept {
	int n = static_cast<int>(data.size());
	bool done = false;
	for (int i = 0, j; i < n - 1 && !done; i++)
		for (j = n - 1, done = true; j > i; j--)
			if (data[j] < data[j - 1]) {
				swap(data[j], data[j - 1]);
				done = false;
			}
}

template<typename T>
void CombSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	int step = n, j, k;
	while ((step = static_cast<int>(step / 1.3)) > 1) {
		for (j = n - 1; j >= step; j--) {
			k = j - step;
			if (data[j] < data[k])
				swap(data[j], data[k]);
		}
	}
	bool done = false;
	for (int i = 0; i < n - 1 && !done; i++)
		for (j = n - 1, done = true; j > i; j--)
			if (data[j] < data[j - 1]) {
				swap(data[j], data[j - 1]);
				done = false;
			}

}

template<typename T>
void ShellSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	int i, j, step, stepCnt, k;
	vector<int> increments;

	//define the step increments
	for (step = 1; step < n;) {
		increments.push_back(step);
		step = 3 * step + 1;
	}

	// increments version 2  2^k-1
	// for (step = 1; step < n;) {
	// 	increments.push_back(step);
	// 	step = 2 * step + 1;
	// }

	// increments version 3   2^k+1
	// increments.push_back(1);
	// for (step = 3; step < n;) {
	// 	increments.push_back(step);
	// 	step = 2 * step - 1;
	// }
	//
	// incremnets version 4 Fibonacci numbers
	// int temp = 1;
	// increments.push_back(1);
	// for (step = 2; step < n;) {
	// 	increments.push_back(step);
	// 	step = temp + step;
	// 	temp = step - temp;
	// }
	//
	// // incremnets version 5 step0 = n/2, and next is n/0.75
	// for (step = 1; step <n;) {
	// 	increments.push_back(step);
	// 	step=static_cast<int>(4.0/3*step);
	// }

	for (i = static_cast<int>(increments.size() - 1); i >= 0; i--) {
		step = increments[i];
		for (stepCnt = step; stepCnt < 2 * step; stepCnt++) {
			for (j = stepCnt; j < n; j += step) {
				T temp = data[j];
				for (k = j; k >= step && temp < data[k - step]; k -= step)
					data[k] = data[k - step];
				data[k] = temp;
			}
		}
	}
}

template<typename T>
void moveDown(vector<T> &data, int first, int last) noexcept {
	int larger = 2 * first + 1;
	while (larger <= last) {
		if (larger < last && data[larger] < data[larger + 1])
			larger++;
		if (data[larger] > data[first]) {
			swap(data[larger], data[first]);
			first = larger;
			larger = 2 * first + 1;
		}
		else
			larger = last + 1;
	}
}

template<typename T>
void HeapSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		moveDown(data, i, n - 1); //use maxHeap
	for (int i = n - 1; i >= 1; i--) {
		swap(data[0], data[i]);
		moveDown(data, 0, i - 1);
	}
}

//Second, it is inappropriate to use quicksort for small arrays. For arrays with fewer than 30 items, insertion sort is more efficient than quicksort (Cook and Kim 1980).

template<typename T>
void QuickSort2(vector<T> &data, int first, int last) noexcept {
	if (last - first + 1 > 30) {
		int lower = first + 1, upper = last;
		//choose the pivot
		// 1、middle
		swap(data[first], data[(first + last) / 2]);
		// // 2、middle of the data[first],data[middle] and data[last];  seems to not work better than the first
		// int middle = (first+last)/2;
		// if(data[first]<=data[middle]&&data[middle]<=data[last]||data[last]<=data[middle]&&data[middle]<=data[first])
		// 	swap(data[first],data[middle]);
		// else if(data[first]<=data[last]&&data[last]<=data[middle]||data[middle]<=data[last]&&data[last]<=data[first])
		// 	swap(data[first],data[last]);
		// //3. data[first] as pivot

		T bound = data[first];
		while (lower <= upper) {
			while (data[lower] < bound)
				lower++;
			while (data[upper] > bound)
				upper--;
			if (lower < upper)
				swap(data[lower++], data[upper--]);
			else
				lower++;
		}
		swap(data[first], data[upper]);
		if (first < upper - 1)
			QuickSort2(data, first, upper - 1);
		if (upper + 1 < last)
			QuickSort2(data, upper + 1, last);
	}
	else {
		for (int i = first + 1, j; i <= last; i++) {
			T temp = data[i];
			for (j = i; j > first && temp < data[j - 1]; j--)
				data[j] = data[j - 1];
			data[j] = temp;
		}
	}
}

template<typename T>
void QuickSort2(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	if (n < 2)
		return;
	int i, max;
	for (i = 1, max = 0; i < n; i++) //preprocess the data[]
		if (data[i] > data[max])
			max = i;
	swap(data[max], data[n - 1]);
	QuickSort2(data, 0, n - 2);
}

template<typename T>
void QuickSort(vector<T> &data, int first, int last) noexcept {
	int lower = first + 1, upper = last;
	//choose the pivot
	// 1、middle
	swap(data[first], data[(first + last) / 2]);
	// // 2、middle of the data[first],data[middle] and data[last];  seems to not work better than the first
	// int middle = (first+last)/2;
	// if(data[first]<=data[middle]&&data[middle]<=data[last]||data[last]<=data[middle]&&data[middle]<=data[first])
	// 	swap(data[first],data[middle]);
	// else if(data[first]<=data[last]&&data[last]<=data[middle]||data[middle]<=data[last]&&data[last]<=data[first])
	// 	swap(data[first],data[last]);
	// //3. data[first] as pivot

	T bound = data[first];
	while (lower <= upper) {
		while (data[lower] < bound)
			lower++;
		while (data[upper] > bound)
			upper--;
		if (lower < upper)
			swap(data[lower++], data[upper--]);
		else
			lower++;
	}
	swap(data[first], data[upper]);
	if (first < upper - 1)
		QuickSort(data, first, upper - 1);
	if (upper + 1 < last)
		QuickSort(data, upper + 1, last);

}

template<typename T>
void QuickSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	if (n < 2)
		return;
	int i, max;
	for (i = 1, max = 0; i < n; i++) //preprocess the data[]
		if (data[i] > data[max])
			max = i;
	swap(data[max], data[n - 1]);
	QuickSort(data, 0, n - 2);
}

template<typename T>
void MergeSort(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	vector<T> temp(n);
	MergeSort(data, temp, 0, n - 1);
}

template<typename T>
void MergeSort(vector<T> &data, vector<T> &temp, int first, int last) noexcept {
	if (first < last) {
		int mid = (first + last) / 2;
		MergeSort(data, temp, first, mid);
		MergeSort(data, temp, mid + 1, last);
		Merge(data, temp, first, last);
	}
}

template<typename T>
void Merge(vector<T> &data, vector<T> &temp, int first, int last) noexcept {
	int mid = (first + last) / 2;
	int i = first, j = mid + 1, index = first;
	while (i <= mid && j <= last) {
		if (data[i] < data[j])
			temp[index++] = data[i++];
		else
			temp[index++] = data[j++];
	}
	while (i <= mid)
		temp[index++] = data[i++];
	while (j <= last)
		temp[index++] = data[j++];

	for (int k = first; k <= last; k++)
		data[k] = temp[k];
}

template<typename T>
void MergeSort_iter(vector<T> &data) noexcept {
	int n = static_cast<int>(data.size());
	vector<T> temp;
	temp.reserve(n);
	int length = 1;
	while (length < n) {
		Merge_iter(data, temp, n, length);
		length *= 2;
		Merge_iter(temp, data, n, length);
		length *= 2;
	}
}

template<typename T>
void Merge_iter(vector<T> &data, vector<T> &temp, int size, int length) noexcept {
	int i;
	for (i = 0; i <= size - 2 * length; i += 2 * length)
		Merge_iter(data, temp, i, i + length - 1, i + 2 * length - 1);
	if (i + length < size)
		Merge_iter(data, temp, i, i + length - 1, size - 1);
	else
		for (int j = i; j < size; j++)
			temp[j] = data[j];
}

template<typename T>
void Merge_iter(vector<T> &data, vector<T> &temp, int first, int mid, int last) noexcept {
	int i = first, index = first , j = mid + 1;
	while (i <= mid && j <= last) {
		if (data[i] < data[j])
			temp[index++] = data[i++];
		else
			temp[index++] = data[j++];
	}
	while (i <= mid)
		temp[index++] = data[i++];
	while (j <= last)
		temp[index++] = data[j++];
}
void RadixSort(vector<int> &data) {
	int n = static_cast<int>(data.size());
	int d, j, k, factor;
	const int radix = 10;
	const int digits = 10;
	queue<int> queues[radix];
	for (d = 0, factor = 1; d < digits; factor *= radix, d++) {
		for (j = 0; j < n; j++)
			queues[(data[j] / factor) % radix].push(data[j]);
		for (j = k = 0; j < radix; j++)
			while (!queues[j].empty()) {
				data[k++] = queues[j].front();
				queues[j].pop();
			}
	}
}

void bitRadixsort(vector<int> &data) {
	// int b = 8;
	int b = 11;
	bitRadixsort(data, b);
}
//see data as a 2^b base number, and then do the same thing as above one
void bitRadixsort(vector<int> &data, int b) {
	const int bits = 31;
	const int n = static_cast<int>(data.size());
	int pow2b = 1;
	pow2b <<= b;//get 2^b
	int i, j, k, pos = 0, mask = pow2b - 1;
	int last = (bits % b == 0) ? (bits / b) : (bits / b + 1);//find out the 2^b based number's total digit
	vector<queue<int>> queues(pow2b);//get a queue array consist of 2^b queue
	for (i = 0; i < last; i++) {// the circulation part can be implemented with counting sort, which will be more efficient;
		for (j = 0; j < n; j++)
			queues[(data[j] & mask) >> pos].push(data[j]);//get the i th digit of the 2^b based number
		mask <<= b;//multipy by 2^b, same as after each circulation, the factor is multipy by 10(the base of number);
		pos = pos + b;//rember the current digit position
		for (j = k = 0; j < pow2b; j++)
			while (!queues[j].empty()) {//put the result back to the array
				data[k++] = queues[j].front();
				queues[j].pop();
			}
	}
}


void inline clear(int& q) {
	q = -1;
}
int inline isEmpty(int q) {
	return q == -1;
}

template<class T>
class RadixSortNode {
public:
	vector<T> arr;
	RadixSortNode *next;
};

void radixsort2(vector<int> &data) {
	const int radix = 10;
	const int digits = 10;
	const int n = static_cast<int>(data.size());
	register int d, j, k, factor, where;
	RadixSortNode<int> n1, n2, *p1, *p2;
	n1.arr = data;
	n2.arr = data;
	vector<int> queue(n), queueHeads(radix), queueTails(radix);
	p1 = n2.next = &n1;
	p2 = n1.next = &n2;
	for (d = 0, factor = 1; d < digits; factor *= radix, d++) {
		for (j = 0; j < radix; j++)
			clear(queueHeads[j]);//initialize
		for (j = 0; j < n; j++) {
			where = (p1->arr[j] / factor) % radix;//find the digit number
			if (isEmpty(queueHeads[where]))//if first meet a digit,set heads and tails to it
				queueTails[where] = queueHeads[where] = j;
			else {//renew the content of last position in queue to the new tail, and renew the tail queue;
				queue[queueTails[where]] = j;
				queueTails[where] = j;
			}
		}
		for (j = 0; j < radix; j++)
			if (!(isEmpty(queueHeads[j])))
				clear(queue[queueTails[j]]);//set the end of each digit in queue, if heads exists
		for (j = k = 0; j < radix; j++)
			while (!(isEmpty(queueHeads[j]))) {//copy form p1 to p2
				p2->arr[k++] = p1->arr[queueHeads[j]];
				queueHeads[j] = queue[queueHeads[j]];
			}
		p2 = p2->next;//change p1 and p2, so the p1 always point to the sorted version
		p1 = p1->next;
	}
	// if (digits % 2 != 0) // if digits is an odd number;
	for (d = 0; d < n; d++)
		data[d] = p1->arr[d];
}

class RadixsortNode {
public:
	vector<int> arr;
	RadixsortNode *next;
	RadixsortNode() {
		next = 0;
	}
	RadixsortNode(vector<int> a) {
		arr = a;
		next = 0;
	}
	RadixsortNode(int n) {
		arr.reserve(n);
		next = 0;
	}
};

void bitRadixsort2(vector<int> &data) {
	// int b = 8;
	int b = 11;
	bitRadixsort2(data, b);
}

void bitRadixsort2(vector<int> &data , int b) {
	const int bits = 31;
	const int n = static_cast<int>(data.size());
	int pow2b = 1;
	pow2b <<= b;
	int d, j, k, where, pos = 0, mask = pow2b - 1;
	int last = (bits % b == 0) ? (bits / b) : (bits / b + 1);
	vector<int> queues(n) , queueHeads(pow2b), queueTails(pow2b);
	RadixsortNode *n2 = new RadixsortNode(data), *n1 = new RadixsortNode(data);
	n2->next = n1;
	n1->next = n2;
	for (d = 0; d < last; d++) {
		for (j = 0; j < pow2b; j++)
			clear(queueHeads[j]);
		for (j = 0; j < n; j++) {
			where = (n1->arr[j] & mask) >> pos;
			if (isEmpty(queueHeads[where]))
				queueTails[where] = queueHeads[where] = j;
			else {
				queues[queueTails[where]] = j;
				queueTails[where] = j;
			}
		}
		mask <<= b;
		pos = pos + b;
		for (j = 0; j < pow2b; j++)
			if (!(isEmpty(queueHeads[j])))
				clear(queues[queueTails[j]]);
		for (j = k = 0; j < pow2b; j++)
			while (!(isEmpty(queueHeads[j]))) {
				n2->arr[k++] = n1->arr[queueHeads[j]];
				queueHeads[j] = queues[queueHeads[j]];
			}
		n2 = n2->next;
		n1 = n1->next;
	}
	// if (last % 2 != 0) // if bits is an odd number;
	for (d = 0; d < n; d++)
		data[d] = n1->arr[d];
}

void CountingSort(vector<int> &data) {
	int n = static_cast<int>(data.size());
	int largest = data[0];
	vector<int> temp(n);
	for (int i = 1; i < n; i++)
		if (data[i] > largest)
			largest = data[i];
	vector<int> count(largest + 1, 0);
	for (int i = 0; i < n; i++)
		count[data[i]]++;
	for (int i = 1; i <= largest; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		temp[count[data[i]] - 1] = data[i];
		count[data[i]]--;
	}
	data = temp;
}




// test result
//         prepaer time for numbers: 1000  : Clicks: 1        0.001    seconds
// -------------------------------the 1st test----------------------------------
//                            **** average case test****

// sort            numbers: 1000  : Clicks: 0        0        seconds
// stable_sort     numbers: 1000  : Clicks: 0        0        seconds
// partial_sort    numbers: 1000  : Clicks: 0        0        seconds
// MergeSort       numbers: 1000  : Clicks: 0        0        seconds
// MergeSort_iter  numbers: 1000  : Clicks: 0        0        seconds
// QuickSort2      numbers: 1000  : Clicks: 0        0        seconds
// ShellSort       numbers: 1000  : Clicks: 0        0        seconds
// HeapSort        numbers: 1000  : Clicks: 0        0        seconds
// sort_heap       numbers: 1000  : Clicks: 1        0.001    seconds
// CombSort        numbers: 1000  : Clicks: 1        0.001    seconds
// RadixSort       numbers: 1000  : Clicks: 1        0.001    seconds
// radixsort2      numbers: 1000  : Clicks: 1        0.001    seconds
// bitRadixsort2   numbers: 1000  : Clicks: 1        0.001    seconds
// QuickSort       numbers: 1000  : Clicks: 1        0.001    seconds
// bitRadixsort    numbers: 1000  : Clicks: 8        0.008    seconds
// CountingSort    numbers: 1000  : Clicks: 9        0.009    seconds

//                            **** best case test****

// sort            numbers: 1000  : Clicks: 0        0        seconds
// stable_sort     numbers: 1000  : Clicks: 0        0        seconds
// sort_heap       numbers: 1000  : Clicks: 0        0        seconds
// CombSort        numbers: 1000  : Clicks: 0        0        seconds
// radixsort2      numbers: 1000  : Clicks: 0        0        seconds
// MergeSort       numbers: 1000  : Clicks: 0        0        seconds
// MergeSort_iter  numbers: 1000  : Clicks: 0        0        seconds
// QuickSort       numbers: 1000  : Clicks: 0        0        seconds
// QuickSort2      numbers: 1000  : Clicks: 0        0        seconds
// HeapSort        numbers: 1000  : Clicks: 0        0        seconds
// partial_sort    numbers: 1000  : Clicks: 1        0.001    seconds
// RadixSort       numbers: 1000  : Clicks: 1        0.001    seconds
// bitRadixsort2   numbers: 1000  : Clicks: 1        0.001    seconds
// ShellSort       numbers: 1000  : Clicks: 1        0.001    seconds
// bitRadixsort    numbers: 1000  : Clicks: 8        0.008    seconds
// CountingSort    numbers: 1000  : Clicks: 10       0.01     seconds

//                            **** worst case test****

// stable_sort     numbers: 1000  : Clicks: 0        0        seconds
// sort_heap       numbers: 1000  : Clicks: 0        0        seconds
// CombSort        numbers: 1000  : Clicks: 0        0        seconds
// RadixSort       numbers: 1000  : Clicks: 0        0        seconds
// MergeSort       numbers: 1000  : Clicks: 0        0        seconds
// MergeSort_iter  numbers: 1000  : Clicks: 0        0        seconds
// QuickSort       numbers: 1000  : Clicks: 0        0        seconds
// QuickSort2      numbers: 1000  : Clicks: 0        0        seconds
// HeapSort        numbers: 1000  : Clicks: 0        0        seconds
// sort            numbers: 1000  : Clicks: 1        0.001    seconds
// partial_sort    numbers: 1000  : Clicks: 1        0.001    seconds
// radixsort2      numbers: 1000  : Clicks: 1        0.001    seconds
// bitRadixsort2   numbers: 1000  : Clicks: 1        0.001    seconds
// ShellSort       numbers: 1000  : Clicks: 1        0.001    seconds
// bitRadixsort    numbers: 1000  : Clicks: 7        0.007    seconds
// CountingSort    numbers: 1000  : Clicks: 10       0.01     seconds
//         prepaer time for numbers: 10000 : Clicks: 12       0.012    seconds
// -------------------------------the 2nd test----------------------------------
//                            **** average case test****

// bitRadixsort2   numbers: 10000 : Clicks: 2        0.002    seconds
// QuickSort       numbers: 10000 : Clicks: 2        0.002    seconds
// QuickSort2      numbers: 10000 : Clicks: 2        0.002    seconds
// sort            numbers: 10000 : Clicks: 3        0.003    seconds
// stable_sort     numbers: 10000 : Clicks: 3        0.003    seconds
// MergeSort_iter  numbers: 10000 : Clicks: 3        0.003    seconds
// ShellSort       numbers: 10000 : Clicks: 3        0.003    seconds
// CombSort        numbers: 10000 : Clicks: 4        0.004    seconds
// radixsort2      numbers: 10000 : Clicks: 4        0.004    seconds
// sort_heap       numbers: 10000 : Clicks: 6        0.006    seconds
// partial_sort    numbers: 10000 : Clicks: 6        0.006    seconds
// RadixSort       numbers: 10000 : Clicks: 6        0.006    seconds
// MergeSort       numbers: 10000 : Clicks: 6        0.006    seconds
// HeapSort        numbers: 10000 : Clicks: 6        0.006    seconds
// bitRadixsort    numbers: 10000 : Clicks: 9        0.009    seconds
// CountingSort    numbers: 10000 : Clicks: 11       0.011    seconds

//                            **** best case test****

// QuickSort2      numbers: 10000 : Clicks: 0        0        seconds
// sort            numbers: 10000 : Clicks: 1        0.001    seconds
// bitRadixsort2   numbers: 10000 : Clicks: 1        0.001    seconds
// MergeSort_iter  numbers: 10000 : Clicks: 1        0.001    seconds
// QuickSort       numbers: 10000 : Clicks: 1        0.001    seconds
// ShellSort       numbers: 10000 : Clicks: 1        0.001    seconds
// stable_sort     numbers: 10000 : Clicks: 2        0.002    seconds
// CombSort        numbers: 10000 : Clicks: 2        0.002    seconds
// radixsort2      numbers: 10000 : Clicks: 4        0.004    seconds
// HeapSort        numbers: 10000 : Clicks: 4        0.004    seconds
// sort_heap       numbers: 10000 : Clicks: 5        0.005    seconds
// partial_sort    numbers: 10000 : Clicks: 5        0.005    seconds
// RadixSort       numbers: 10000 : Clicks: 6        0.006    seconds
// MergeSort       numbers: 10000 : Clicks: 7        0.007    seconds
// bitRadixsort    numbers: 10000 : Clicks: 10       0.01     seconds
// CountingSort    numbers: 10000 : Clicks: 11       0.011    seconds

//                            **** worst case test****

// MergeSort_iter  numbers: 10000 : Clicks: 1        0.001    seconds
// QuickSort       numbers: 10000 : Clicks: 1        0.001    seconds
// QuickSort2      numbers: 10000 : Clicks: 1        0.001    seconds
// ShellSort       numbers: 10000 : Clicks: 1        0.001    seconds
// stable_sort     numbers: 10000 : Clicks: 2        0.002    seconds
// bitRadixsort2   numbers: 10000 : Clicks: 2        0.002    seconds
// CombSort        numbers: 10000 : Clicks: 3        0.003    seconds
// HeapSort        numbers: 10000 : Clicks: 3        0.003    seconds
// radixsort2      numbers: 10000 : Clicks: 4        0.004    seconds
// sort_heap       numbers: 10000 : Clicks: 5        0.005    seconds
// partial_sort    numbers: 10000 : Clicks: 6        0.006    seconds
// MergeSort       numbers: 10000 : Clicks: 6        0.006    seconds
// sort            numbers: 10000 : Clicks: 7        0.007    seconds
// RadixSort       numbers: 10000 : Clicks: 7        0.007    seconds
// bitRadixsort    numbers: 10000 : Clicks: 9        0.009    seconds
// CountingSort    numbers: 10000 : Clicks: 10       0.01     seconds
//         prepaer time for numbers: 25000 : Clicks: 32       0.032    seconds
// -------------------------------the 3rd test----------------------------------
//                            **** average case test****

// bitRadixsort2   numbers: 25000 : Clicks: 4        0.004    seconds
// QuickSort2      numbers: 25000 : Clicks: 5        0.005    seconds
// QuickSort       numbers: 25000 : Clicks: 6        0.006    seconds
// MergeSort_iter  numbers: 25000 : Clicks: 7        0.007    seconds
// sort            numbers: 25000 : Clicks: 8        0.008    seconds
// stable_sort     numbers: 25000 : Clicks: 8        0.008    seconds
// radixsort2      numbers: 25000 : Clicks: 10       0.01     seconds
// ShellSort       numbers: 25000 : Clicks: 10       0.01     seconds
// HeapSort        numbers: 25000 : Clicks: 11       0.011    seconds
// CombSort        numbers: 25000 : Clicks: 12       0.012    seconds
// CountingSort    numbers: 25000 : Clicks: 12       0.012    seconds
// bitRadixsort    numbers: 25000 : Clicks: 12       0.012    seconds
// partial_sort    numbers: 25000 : Clicks: 15       0.015    seconds
// RadixSort       numbers: 25000 : Clicks: 15       0.015    seconds
// sort_heap       numbers: 25000 : Clicks: 16       0.016    seconds
// MergeSort       numbers: 25000 : Clicks: 16       0.016    seconds

//                            **** best case test****

// QuickSort       numbers: 25000 : Clicks: 2        0.002    seconds
// QuickSort2      numbers: 25000 : Clicks: 2        0.002    seconds
// ShellSort       numbers: 25000 : Clicks: 2        0.002    seconds
// sort            numbers: 25000 : Clicks: 3        0.003    seconds
// MergeSort_iter  numbers: 25000 : Clicks: 3        0.003    seconds
// stable_sort     numbers: 25000 : Clicks: 4        0.004    seconds
// bitRadixsort2   numbers: 25000 : Clicks: 4        0.004    seconds
// CombSort        numbers: 25000 : Clicks: 5        0.005    seconds
// HeapSort        numbers: 25000 : Clicks: 10       0.01     seconds
// CountingSort    numbers: 25000 : Clicks: 11       0.011    seconds
// radixsort2      numbers: 25000 : Clicks: 11       0.011    seconds
// bitRadixsort    numbers: 25000 : Clicks: 11       0.011    seconds
// sort_heap       numbers: 25000 : Clicks: 14       0.014    seconds
// partial_sort    numbers: 25000 : Clicks: 14       0.014    seconds
// RadixSort       numbers: 25000 : Clicks: 15       0.015    seconds
// MergeSort       numbers: 25000 : Clicks: 17       0.017    seconds

//                            **** worst case test****

// QuickSort2      numbers: 25000 : Clicks: 1        0.001    seconds
// QuickSort       numbers: 25000 : Clicks: 2        0.002    seconds
// bitRadixsort2   numbers: 25000 : Clicks: 3        0.003    seconds
// MergeSort_iter  numbers: 25000 : Clicks: 3        0.003    seconds
// stable_sort     numbers: 25000 : Clicks: 4        0.004    seconds
// ShellSort       numbers: 25000 : Clicks: 4        0.004    seconds
// CombSort        numbers: 25000 : Clicks: 8        0.008    seconds
// HeapSort        numbers: 25000 : Clicks: 9        0.009    seconds
// CountingSort    numbers: 25000 : Clicks: 11       0.011    seconds
// radixsort2      numbers: 25000 : Clicks: 11       0.011    seconds
// bitRadixsort    numbers: 25000 : Clicks: 12       0.012    seconds
// sort_heap       numbers: 25000 : Clicks: 15       0.015    seconds
// partial_sort    numbers: 25000 : Clicks: 16       0.016    seconds
// sort            numbers: 25000 : Clicks: 17       0.017    seconds
// RadixSort       numbers: 25000 : Clicks: 17       0.017    seconds
// MergeSort       numbers: 25000 : Clicks: 17       0.017    seconds
//         prepaer time for numbers: 50000 : Clicks: 68       0.068    seconds
// -------------------------------the 4th test----------------------------------
//                            **** average case test****

// bitRadixsort2   numbers: 50000 : Clicks: 7        0.007    seconds
// QuickSort       numbers: 50000 : Clicks: 11       0.011    seconds
// QuickSort2      numbers: 50000 : Clicks: 11       0.011    seconds
// CountingSort    numbers: 50000 : Clicks: 14       0.014    seconds
// MergeSort_iter  numbers: 50000 : Clicks: 15       0.015    seconds
// sort            numbers: 50000 : Clicks: 16       0.016    seconds
// bitRadixsort    numbers: 50000 : Clicks: 16       0.016    seconds
// stable_sort     numbers: 50000 : Clicks: 18       0.018    seconds
// radixsort2      numbers: 50000 : Clicks: 21       0.021    seconds
// ShellSort       numbers: 50000 : Clicks: 24       0.024    seconds
// HeapSort        numbers: 50000 : Clicks: 24       0.024    seconds
// CombSort        numbers: 50000 : Clicks: 26       0.026    seconds
// RadixSort       numbers: 50000 : Clicks: 30       0.03     seconds
// partial_sort    numbers: 50000 : Clicks: 33       0.033    seconds
// sort_heap       numbers: 50000 : Clicks: 34       0.034    seconds
// MergeSort       numbers: 50000 : Clicks: 34       0.034    seconds

//                            **** best case test****

// QuickSort2      numbers: 50000 : Clicks: 3        0.003    seconds
// QuickSort       numbers: 50000 : Clicks: 4        0.004    seconds
// ShellSort       numbers: 50000 : Clicks: 5        0.005    seconds
// sort            numbers: 50000 : Clicks: 6        0.006    seconds
// bitRadixsort2   numbers: 50000 : Clicks: 7        0.007    seconds
// stable_sort     numbers: 50000 : Clicks: 8        0.008    seconds
// MergeSort_iter  numbers: 50000 : Clicks: 8        0.008    seconds
// CountingSort    numbers: 50000 : Clicks: 11       0.011    seconds
// CombSort        numbers: 50000 : Clicks: 13       0.013    seconds
// bitRadixsort    numbers: 50000 : Clicks: 16       0.016    seconds
// radixsort2      numbers: 50000 : Clicks: 21       0.021    seconds
// HeapSort        numbers: 50000 : Clicks: 21       0.021    seconds
// sort_heap       numbers: 50000 : Clicks: 30       0.03     seconds
// partial_sort    numbers: 50000 : Clicks: 30       0.03     seconds
// RadixSort       numbers: 50000 : Clicks: 30       0.03     seconds
// MergeSort       numbers: 50000 : Clicks: 36       0.036    seconds

//                            **** worst case test****

// QuickSort2      numbers: 50000 : Clicks: 3        0.003    seconds
// QuickSort       numbers: 50000 : Clicks: 4        0.004    seconds
// bitRadixsort2   numbers: 50000 : Clicks: 8        0.008    seconds
// MergeSort_iter  numbers: 50000 : Clicks: 8        0.008    seconds
// ShellSort       numbers: 50000 : Clicks: 9        0.009    seconds
// stable_sort     numbers: 50000 : Clicks: 10       0.01     seconds
// CountingSort    numbers: 50000 : Clicks: 12       0.012    seconds
// CombSort        numbers: 50000 : Clicks: 14       0.014    seconds
// bitRadixsort    numbers: 50000 : Clicks: 17       0.017    seconds
// HeapSort        numbers: 50000 : Clicks: 20       0.02     seconds
// radixsort2      numbers: 50000 : Clicks: 21       0.021    seconds
// RadixSort       numbers: 50000 : Clicks: 30       0.03     seconds
// sort_heap       numbers: 50000 : Clicks: 31       0.031    seconds
// partial_sort    numbers: 50000 : Clicks: 32       0.032    seconds
// MergeSort       numbers: 50000 : Clicks: 34       0.034    seconds
// sort            numbers: 50000 : Clicks: 37       0.037    seconds
//         prepaer time for numbers: 100000 : Clicks: 141      0.141    seconds
// -------------------------------the 5th test----------------------------------
//                            **** average case test****

// bitRadixsort2   numbers: 100000 : Clicks: 15       0.015    seconds
// CountingSort    numbers: 100000 : Clicks: 19       0.019    seconds
// QuickSort2      numbers: 100000 : Clicks: 23       0.023    seconds
// QuickSort       numbers: 100000 : Clicks: 24       0.024    seconds
// bitRadixsort    numbers: 100000 : Clicks: 27       0.027    seconds
// sort            numbers: 100000 : Clicks: 32       0.032    seconds
// MergeSort_iter  numbers: 100000 : Clicks: 32       0.032    seconds
// stable_sort     numbers: 100000 : Clicks: 38       0.038    seconds
// radixsort2      numbers: 100000 : Clicks: 43       0.043    seconds
// CombSort        numbers: 100000 : Clicks: 50       0.05     seconds
// HeapSort        numbers: 100000 : Clicks: 52       0.052    seconds
// ShellSort       numbers: 100000 : Clicks: 55       0.055    seconds
// RadixSort       numbers: 100000 : Clicks: 59       0.059    seconds
// sort_heap       numbers: 100000 : Clicks: 71       0.071    seconds
// partial_sort    numbers: 100000 : Clicks: 71       0.071    seconds
// MergeSort       numbers: 100000 : Clicks: 73       0.073    seconds

//                            **** best case test****

// QuickSort2      numbers: 100000 : Clicks: 6        0.006    seconds
// QuickSort       numbers: 100000 : Clicks: 9        0.009    seconds
// ShellSort       numbers: 100000 : Clicks: 11       0.011    seconds
// CountingSort    numbers: 100000 : Clicks: 13       0.013    seconds
// sort            numbers: 100000 : Clicks: 14       0.014    seconds
// bitRadixsort2   numbers: 100000 : Clicks: 15       0.015    seconds
// stable_sort     numbers: 100000 : Clicks: 17       0.017    seconds
// MergeSort_iter  numbers: 100000 : Clicks: 17       0.017    seconds
// bitRadixsort    numbers: 100000 : Clicks: 26       0.026    seconds
// CombSort        numbers: 100000 : Clicks: 27       0.027    seconds
// radixsort2      numbers: 100000 : Clicks: 45       0.045    seconds
// HeapSort        numbers: 100000 : Clicks: 46       0.046    seconds
// RadixSort       numbers: 100000 : Clicks: 59       0.059    seconds
// partial_sort    numbers: 100000 : Clicks: 66       0.066    seconds
// sort_heap       numbers: 100000 : Clicks: 76       0.076    seconds
// MergeSort       numbers: 100000 : Clicks: 77       0.077    seconds

//                            **** worst case test****

// QuickSort2      numbers: 100000 : Clicks: 6        0.006    seconds
// QuickSort       numbers: 100000 : Clicks: 9        0.009    seconds
// CountingSort    numbers: 100000 : Clicks: 13       0.013    seconds
// bitRadixsort2   numbers: 100000 : Clicks: 16       0.016    seconds
// MergeSort_iter  numbers: 100000 : Clicks: 16       0.016    seconds
// ShellSort       numbers: 100000 : Clicks: 17       0.017    seconds
// stable_sort     numbers: 100000 : Clicks: 20       0.02     seconds
// bitRadixsort    numbers: 100000 : Clicks: 27       0.027    seconds
// CombSort        numbers: 100000 : Clicks: 31       0.031    seconds
// radixsort2      numbers: 100000 : Clicks: 43       0.043    seconds
// HeapSort        numbers: 100000 : Clicks: 44       0.044    seconds
// RadixSort       numbers: 100000 : Clicks: 62       0.062    seconds
// sort_heap       numbers: 100000 : Clicks: 67       0.067    seconds
// partial_sort    numbers: 100000 : Clicks: 67       0.067    seconds
// MergeSort       numbers: 100000 : Clicks: 72       0.072    seconds
// sort            numbers: 100000 : Clicks: 78       0.078    seconds
//         prepaer time for numbers: 200000 : Clicks: 300      0.3      seconds
// -------------------------------the 6th test----------------------------------
//                            **** average case test****

// CountingSort    numbers: 200000 : Clicks: 27       0.027    seconds
// bitRadixsort2   numbers: 200000 : Clicks: 30       0.03     seconds
// bitRadixsort    numbers: 200000 : Clicks: 45       0.045    seconds
// QuickSort2      numbers: 200000 : Clicks: 48       0.048    seconds
// QuickSort       numbers: 200000 : Clicks: 51       0.051    seconds
// sort            numbers: 200000 : Clicks: 67       0.067    seconds
// MergeSort_iter  numbers: 200000 : Clicks: 67       0.067    seconds
// stable_sort     numbers: 200000 : Clicks: 77       0.077    seconds
// radixsort2      numbers: 200000 : Clicks: 86       0.086    seconds
// CombSort        numbers: 200000 : Clicks: 110      0.11     seconds
// HeapSort        numbers: 200000 : Clicks: 110      0.11     seconds
// RadixSort       numbers: 200000 : Clicks: 118      0.118    seconds
// ShellSort       numbers: 200000 : Clicks: 122      0.122    seconds
// MergeSort       numbers: 200000 : Clicks: 151      0.151    seconds
// sort_heap       numbers: 200000 : Clicks: 153      0.153    seconds
// partial_sort    numbers: 200000 : Clicks: 155      0.155    seconds

//                            **** best case test****

// QuickSort2      numbers: 200000 : Clicks: 13       0.013    seconds
// CountingSort    numbers: 200000 : Clicks: 17       0.017    seconds
// QuickSort       numbers: 200000 : Clicks: 19       0.019    seconds
// ShellSort       numbers: 200000 : Clicks: 23       0.023    seconds
// sort            numbers: 200000 : Clicks: 26       0.026    seconds
// stable_sort     numbers: 200000 : Clicks: 34       0.034    seconds
// MergeSort_iter  numbers: 200000 : Clicks: 34       0.034    seconds
// bitRadixsort2   numbers: 200000 : Clicks: 37       0.037    seconds
// bitRadixsort    numbers: 200000 : Clicks: 45       0.045    seconds
// CombSort        numbers: 200000 : Clicks: 56       0.056    seconds
// radixsort2      numbers: 200000 : Clicks: 87       0.087    seconds
// HeapSort        numbers: 200000 : Clicks: 97       0.097    seconds
// RadixSort       numbers: 200000 : Clicks: 119      0.119    seconds
// sort_heap       numbers: 200000 : Clicks: 135      0.135    seconds
// partial_sort    numbers: 200000 : Clicks: 137      0.137    seconds
// MergeSort       numbers: 200000 : Clicks: 161      0.161    seconds

//                            **** worst case test****

// QuickSort2      numbers: 200000 : Clicks: 15       0.015    seconds
// CountingSort    numbers: 200000 : Clicks: 16       0.016    seconds
// QuickSort       numbers: 200000 : Clicks: 19       0.019    seconds
// bitRadixsort2   numbers: 200000 : Clicks: 32       0.032    seconds
// MergeSort_iter  numbers: 200000 : Clicks: 35       0.035    seconds
// ShellSort       numbers: 200000 : Clicks: 39       0.039    seconds
// stable_sort     numbers: 200000 : Clicks: 41       0.041    seconds
// bitRadixsort    numbers: 200000 : Clicks: 47       0.047    seconds
// CombSort        numbers: 200000 : Clicks: 72       0.072    seconds
// radixsort2      numbers: 200000 : Clicks: 89       0.089    seconds
// HeapSort        numbers: 200000 : Clicks: 96       0.096    seconds
// RadixSort       numbers: 200000 : Clicks: 122      0.122    seconds
// partial_sort    numbers: 200000 : Clicks: 146      0.146    seconds
// MergeSort       numbers: 200000 : Clicks: 150      0.15     seconds
// sort_heap       numbers: 200000 : Clicks: 152      0.152    seconds
// sort            numbers: 200000 : Clicks: 164      0.164    seconds
//         prepaer time for numbers: 1000000 : Clicks: 1683     1.683    seconds
// -------------------------------the 7th test----------------------------------
//                            **** average case test****

// CountingSort    numbers: 1000000 : Clicks: 121      0.121    seconds
// bitRadixsort    numbers: 1000000 : Clicks: 279      0.279    seconds
// bitRadixsort2   numbers: 1000000 : Clicks: 300      0.3      seconds
// QuickSort2      numbers: 1000000 : Clicks: 344      0.344    seconds
// QuickSort       numbers: 1000000 : Clicks: 370      0.37     seconds
// sort            numbers: 1000000 : Clicks: 373      0.373    seconds
// stable_sort     numbers: 1000000 : Clicks: 452      0.452    seconds
// radixsort2      numbers: 1000000 : Clicks: 527      0.527    seconds
// MergeSort_iter  numbers: 1000000 : Clicks: 535      0.535    seconds
// CombSort        numbers: 1000000 : Clicks: 646      0.646    seconds
// RadixSort       numbers: 1000000 : Clicks: 661      0.661    seconds
// sort_heap       numbers: 1000000 : Clicks: 939      0.939    seconds
// partial_sort    numbers: 1000000 : Clicks: 970      0.97     seconds
// MergeSort       numbers: 1000000 : Clicks: 1245     1.245    seconds
// HeapSort        numbers: 1000000 : Clicks: 1874     1.874    seconds
// ShellSort       numbers: 1000000 : Clicks: 2052     2.052    seconds

//                            **** best case test****

// CountingSort    numbers: 1000000 : Clicks: 79       0.079    seconds
// QuickSort2      numbers: 1000000 : Clicks: 82       0.082    seconds
// QuickSort       numbers: 1000000 : Clicks: 123      0.123    seconds
// ShellSort       numbers: 1000000 : Clicks: 176      0.176    seconds
// MergeSort_iter  numbers: 1000000 : Clicks: 206      0.206    seconds
// bitRadixsort2   numbers: 1000000 : Clicks: 250      0.25     seconds
// sort            numbers: 1000000 : Clicks: 276      0.276    seconds
// bitRadixsort    numbers: 1000000 : Clicks: 366      0.366    seconds
// stable_sort     numbers: 1000000 : Clicks: 454      0.454    seconds
// CombSort        numbers: 1000000 : Clicks: 514      0.514    seconds
// HeapSort        numbers: 1000000 : Clicks: 715      0.715    seconds
// radixsort2      numbers: 1000000 : Clicks: 788      0.788    seconds
// MergeSort       numbers: 1000000 : Clicks: 1038     1.038    seconds
// RadixSort       numbers: 1000000 : Clicks: 1214     1.214    seconds
// sort_heap       numbers: 1000000 : Clicks: 1383     1.383    seconds
// partial_sort    numbers: 1000000 : Clicks: 1569     1.569    seconds

//                            **** worst case test****

// CountingSort    numbers: 1000000 : Clicks: 55       0.055    seconds
// QuickSort2      numbers: 1000000 : Clicks: 94       0.094    seconds
// QuickSort       numbers: 1000000 : Clicks: 124      0.124    seconds
// bitRadixsort2   numbers: 1000000 : Clicks: 188      0.188    seconds
// MergeSort_iter  numbers: 1000000 : Clicks: 218      0.218    seconds
// bitRadixsort    numbers: 1000000 : Clicks: 242      0.242    seconds
// stable_sort     numbers: 1000000 : Clicks: 264      0.264    seconds
// ShellSort       numbers: 1000000 : Clicks: 269      0.269    seconds
// CombSort        numbers: 1000000 : Clicks: 445      0.445    seconds
// radixsort2      numbers: 1000000 : Clicks: 522      0.522    seconds
// HeapSort        numbers: 1000000 : Clicks: 698      0.698    seconds
// RadixSort       numbers: 1000000 : Clicks: 769      0.769    seconds
// partial_sort    numbers: 1000000 : Clicks: 902      0.902    seconds
// sort_heap       numbers: 1000000 : Clicks: 937      0.937    seconds
// MergeSort       numbers: 1000000 : Clicks: 1019     1.019    seconds
// sort            numbers: 1000000 : Clicks: 1140     1.14     seconds
//         prepaer time for numbers: 10000000 : Clicks: 21802    21.802   seconds
// -------------------------------the 8th test----------------------------------
//                            **** average case test****

// CountingSort    numbers: 10000000 : Clicks: 1255     1.255    seconds
// bitRadixsort    numbers: 10000000 : Clicks: 2149     2.149    seconds
// bitRadixsort2   numbers: 10000000 : Clicks: 2882     2.882    seconds
// QuickSort2      numbers: 10000000 : Clicks: 3439     3.439    seconds
// QuickSort       numbers: 10000000 : Clicks: 3561     3.561    seconds
// sort            numbers: 10000000 : Clicks: 4319     4.319    seconds
// radixsort2      numbers: 10000000 : Clicks: 4726     4.726    seconds
// MergeSort_iter  numbers: 10000000 : Clicks: 5029     5.029    seconds
// stable_sort     numbers: 10000000 : Clicks: 5379     5.379    seconds
// RadixSort       numbers: 10000000 : Clicks: 6891     6.891    seconds
// CombSort        numbers: 10000000 : Clicks: 7997     7.997    seconds
// MergeSort       numbers: 10000000 : Clicks: 10299    10.299   seconds
// HeapSort        numbers: 10000000 : Clicks: 13128    13.128   seconds
// sort_heap       numbers: 10000000 : Clicks: 14656    14.656   seconds
// partial_sort    numbers: 10000000 : Clicks: 16660    16.66    seconds
// ShellSort       numbers: 10000000 : Clicks: 17249    17.249   seconds

//                            **** best case test****

// CountingSort    numbers: 10000000 : Clicks: 354      0.354    seconds
// QuickSort2      numbers: 10000000 : Clicks: 1058     1.058    seconds
// QuickSort       numbers: 10000000 : Clicks: 1419     1.419    seconds
// bitRadixsort2   numbers: 10000000 : Clicks: 1533     1.533    seconds
// bitRadixsort    numbers: 10000000 : Clicks: 2265     2.265    seconds
// MergeSort_iter  numbers: 10000000 : Clicks: 2586     2.586    seconds
// ShellSort       numbers: 10000000 : Clicks: 2619     2.619    seconds
// stable_sort     numbers: 10000000 : Clicks: 2706     2.706    seconds
// CombSort        numbers: 10000000 : Clicks: 4233     4.233    seconds
// radixsort2      numbers: 10000000 : Clicks: 4847     4.847    seconds
// sort            numbers: 10000000 : Clicks: 4962     4.962    seconds
// RadixSort       numbers: 10000000 : Clicks: 6613     6.613    seconds
// HeapSort        numbers: 10000000 : Clicks: 7189     7.189    seconds
// partial_sort    numbers: 10000000 : Clicks: 10524    10.524   seconds
// MergeSort       numbers: 10000000 : Clicks: 10531    10.531   seconds
// sort_heap       numbers: 10000000 : Clicks: 10983    10.983   seconds

//                            **** worst case test****

// CountingSort    numbers: 10000000 : Clicks: 337      0.337    seconds
// QuickSort2      numbers: 10000000 : Clicks: 1505     1.505    seconds
// bitRadixsort2   numbers: 10000000 : Clicks: 1756     1.756    seconds
// QuickSort       numbers: 10000000 : Clicks: 1833     1.833    seconds
// bitRadixsort    numbers: 10000000 : Clicks: 2213     2.213    seconds
// MergeSort_iter  numbers: 10000000 : Clicks: 2488     2.488    seconds
// stable_sort     numbers: 10000000 : Clicks: 2930     2.93     seconds
// ShellSort       numbers: 10000000 : Clicks: 3635     3.635    seconds
// CombSort        numbers: 10000000 : Clicks: 4902     4.902    seconds
// radixsort2      numbers: 10000000 : Clicks: 5522     5.522    seconds
// HeapSort        numbers: 10000000 : Clicks: 7045     7.045    seconds
// RadixSort       numbers: 10000000 : Clicks: 7632     7.632    seconds
// partial_sort    numbers: 10000000 : Clicks: 10448    10.448   seconds
// MergeSort       numbers: 10000000 : Clicks: 10497    10.497   seconds
// sort_heap       numbers: 10000000 : Clicks: 11535    11.535   seconds
// sort            numbers: 10000000 : Clicks: 12544    12.544   seconds
//         prepaer time for numbers: 20000000 : Clicks: 42509    42.509   seconds
// -------------------------------the 9th test----------------------------------
//                            **** average case test****

// CountingSort    numbers: 20000000 : Clicks: 2682     2.682    seconds
// bitRadixsort    numbers: 20000000 : Clicks: 5304     5.304    seconds
// bitRadixsort2   numbers: 20000000 : Clicks: 5991     5.991    seconds
// QuickSort2      numbers: 20000000 : Clicks: 6121     6.121    seconds
// QuickSort       numbers: 20000000 : Clicks: 6545     6.545    seconds
// sort            numbers: 20000000 : Clicks: 9863     9.863    seconds
// radixsort2      numbers: 20000000 : Clicks: 10060    10.06    seconds
// MergeSort_iter  numbers: 20000000 : Clicks: 10851    10.851   seconds
// stable_sort     numbers: 20000000 : Clicks: 11830    11.83    seconds
// RadixSort       numbers: 20000000 : Clicks: 14737    14.737   seconds
// CombSort        numbers: 20000000 : Clicks: 16335    16.335   seconds
// MergeSort       numbers: 20000000 : Clicks: 23381    23.381   seconds
// HeapSort        numbers: 20000000 : Clicks: 30611    30.611   seconds
// sort_heap       numbers: 20000000 : Clicks: 36226    36.226   seconds
// partial_sort    numbers: 20000000 : Clicks: 36777    36.777   seconds
// ShellSort       numbers: 20000000 : Clicks: 41267    41.267   seconds

//                            **** best case test****

// CountingSort    numbers: 20000000 : Clicks: 697      0.697    seconds
// QuickSort2      numbers: 20000000 : Clicks: 2093     2.093    seconds
// QuickSort       numbers: 20000000 : Clicks: 2795     2.795    seconds
// bitRadixsort2   numbers: 20000000 : Clicks: 2829     2.829    seconds
// bitRadixsort    numbers: 20000000 : Clicks: 3928     3.928    seconds
// MergeSort_iter  numbers: 20000000 : Clicks: 5156     5.156    seconds
// ShellSort       numbers: 20000000 : Clicks: 5366     5.366    seconds
// stable_sort     numbers: 20000000 : Clicks: 5501     5.501    seconds
// CombSort        numbers: 20000000 : Clicks: 8608     8.608    seconds
// radixsort2      numbers: 20000000 : Clicks: 9385     9.385    seconds
// RadixSort       numbers: 20000000 : Clicks: 12783    12.783   seconds
// HeapSort        numbers: 20000000 : Clicks: 14079    14.079   seconds
// sort            numbers: 20000000 : Clicks: 14130    14.13    seconds
// sort_heap       numbers: 20000000 : Clicks: 19089    19.089   seconds
// partial_sort    numbers: 20000000 : Clicks: 19188    19.188   seconds
// MergeSort       numbers: 20000000 : Clicks: 20758    20.758   seconds

//                            **** worst case test****

// CountingSort    numbers: 20000000 : Clicks: 638      0.638    seconds
// QuickSort2      numbers: 20000000 : Clicks: 2211     2.211    seconds
// QuickSort       numbers: 20000000 : Clicks: 2940     2.94     seconds
// bitRadixsort2   numbers: 20000000 : Clicks: 2975     2.975    seconds
// bitRadixsort    numbers: 20000000 : Clicks: 3962     3.962    seconds
// MergeSort_iter  numbers: 20000000 : Clicks: 4832     4.832    seconds
// stable_sort     numbers: 20000000 : Clicks: 4975     4.975    seconds
// ShellSort       numbers: 20000000 : Clicks: 7082     7.082    seconds
// CombSort        numbers: 20000000 : Clicks: 9320     9.32     seconds
// radixsort2      numbers: 20000000 : Clicks: 9345     9.345    seconds
// RadixSort       numbers: 20000000 : Clicks: 12580    12.58    seconds
// HeapSort        numbers: 20000000 : Clicks: 13802    13.802   seconds
// MergeSort       numbers: 20000000 : Clicks: 19564    19.564   seconds
// sort_heap       numbers: 20000000 : Clicks: 20052    20.052   seconds
// partial_sort    numbers: 20000000 : Clicks: 20170    20.17    seconds
// sort            numbers: 20000000 : Clicks: 23078    23.078   seconds
//         prepaer time for numbers: 30000000 : Clicks: 59808    59.808   seconds
// -------------------------------the 10th test----------------------------------
//                            **** average case test****

