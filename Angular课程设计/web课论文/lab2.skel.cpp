#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <cstdlib>

#define fn_list(T) \
  T( max_subarray_brute_force ) \
  T( max_subarray_divide_and_conquer ) \
  T( max_subarray_brute_force_allow_empty ) \
  T( max_subarray_divide_and_conquer_allow_empty )

#define fn_type(name) int (name) (const std::vector<int> &)

typedef fn_type(*fn_ptr);

#define fn_dec(name) fn_type(name);
fn_list(fn_dec)
#undef fn_dec

int main(int argc, char **argv) {
	assert(argc == 2);
	std::vector<int> v;
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(v));
	}
#define T(name) &name,
	static fn_ptr fn_arr[] = { fn_list(T) };
#undef T
	int dispatch = std::atoi(argv[1]);
#define T(name) +1
	assert(((unsigned)dispatch) < (0 fn_list(T)));
#undef T
	std::cout << fn_arr[dispatch](v) << std::endl;
}

/* dont change any code above this line */

int max_subarray_brute_force(const std::vector<int> &arr) {
	int sum, maxsum;
	unsigned int maxleft, maxright;
	maxsum = INT16_MIN;
	for (unsigned int leftindex = 0; leftindex < arr.size(); leftindex++) {
		sum = 0;
		for (unsigned int rightindex = leftindex; rightindex < arr.size(); rightindex++) {
			sum += arr[rightindex];
			if (sum > maxsum) {
				maxleft = leftindex;
				maxright = rightindex;
				maxsum = sum;
			}
		}
	}
	return maxsum;
}
int max_subarray_divide_and_conquer(const std::vector<int> &arr) {
	int maxsubarry(const std::vector<int> &arr, unsigned int left, unsigned int right);
	return maxsubarry(arr, 0, arr.size() - 1);
}
int maxsubarry(const std::vector<int> &arr, unsigned int left, unsigned int right) {
	int maxsubarryacrossmid(const std::vector<int> &arr, unsigned int left, unsigned int mid, unsigned int right);
	unsigned int mid;
	int sum, maxsum;
	//base case
	if (left == right)
		return arr[left];
	//other case
	else {
		mid = (left + right) / 2;
		maxsum = maxsubarry(arr, left, mid);
		sum = maxsubarry(arr, mid + 1, right);
		maxsum = sum > maxsum ? sum : maxsum;
		sum = maxsubarryacrossmid(arr, left, mid, right);
		maxsum = sum > maxsum ? sum : maxsum;
		return maxsum;
	}
}
int maxsubarryacrossmid(const std::vector<int> &arr, unsigned int left, unsigned int mid, unsigned int right) {
	int maxleftsum, maxrightsum, sum;
	maxleftsum = INT16_MIN;
	maxrightsum = INT16_MIN;
	sum = 0;
	for (unsigned int leftindex = mid; leftindex < left; left--) {
		sum += arr[leftindex];
		maxleftsum = sum > maxleftsum ? sum : maxleftsum;
	}
	sum = 0;
	for (unsigned int rightindex = mid + 1; rightindex > right; rightindex++) {
		sum += arr[rightindex];
		maxrightsum = sum > maxrightsum ? sum : maxrightsum;
	}
	return maxleftsum + maxrightsum;
}
int max_subarray_brute_force_allow_empty(const std::vector<int> &arr) {
	/* your code here */
	return 0;
}
int max_subarray_divide_and_conquer_allow_empty(const std::vector<int> &arr) {
	/* your code here */
	return 0;
}

