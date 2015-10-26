/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 ranking.cpp
* @version:
* @Time: 		 2015-09-13 11:14:12
* @Description:
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


class Users
{
public:
	int id;
	vector<int> scores;
	int perfect_num;
	vector<bool> pass_i;
	vector<bool> submit_i;
	int totalscore;
public:
	Users(int problem_num): id(0), scores(problem_num + 1, 0), perfect_num(0), pass_i(problem_num + 1, false), submit_i(problem_num + 1, false) , totalscore(0) {}
	~Users() {}
	bool NotShow() {
		for (int i = 0; i < pass_i.size(); i++)
			if (pass_i[i] == true)
				return false;
		return true;
	}
	bool operator<(const Users& user) {
		if (totalscore > user.totalscore)
			return true;
		else if (totalscore == user.totalscore && perfect_num > user.perfect_num)
			return true;
		else if (totalscore == user.totalscore && perfect_num == user.perfect_num && id < user.id)
			return true;
		else
			return false;
	}
};

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int user_num, problem_num, submittion_num;
	cin >> user_num >> problem_num >> submittion_num;
	vector<int> marks(problem_num);
	vector<Users> users(user_num, Users(problem_num)) ;
	for (int i = 0; i < user_num; i++)
		users[i].id = i + 1;

	for (int i = 1; i <= problem_num; i++)
		cin >> marks[i];
	int uid, pid, mark;
	for (int i = 0; i < submittion_num; i++) {
		cin >> uid >> pid >> mark;
		if (users[uid - 1].scores[pid] <= mark) {
			if (users[uid - 1].scores[pid] != marks[pid] && mark == marks[pid])
				users[uid - 1].perfect_num++;
			users[uid - 1].totalscore += (mark - users[uid - 1].scores[pid]);
			users[uid - 1].scores[pid] = mark;
			users[uid - 1].pass_i[pid] = true;
		}
		users[uid - 1].submit_i[pid] = true;
	}
	QuickSort2(users);
	int rank = 0, buffer = 1;
	for (int i = 0; i < user_num; i++) {
		if (i == 0 || users[i].totalscore != users[i - 1].totalscore) {
			rank += buffer;
			buffer = 1;
		}
		else buffer++;
		if (!users[i].NotShow()) {
			cout << rank << " " << setfill('0') << setw(5) << users[i].id << " " << users[i].totalscore ;
			for (int j = 1; j <= problem_num; j++)
				if (users[i].submit_i[j])
					cout << " " << users[i].scores[j]  ;
				else
					cout << " -";
			cout << endl;
		}
	}

	// cout << endl;
	// system("pause");
	return 0;
}


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
			while (bound < data[upper] )
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
		if (data[max] < data[i] )
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

