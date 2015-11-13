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
