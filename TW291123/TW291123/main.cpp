#include <iostream>
#include <list>
#include <queue>
using namespace std;
struct revpriority {
	bool operator() (const int& a, const int& b) {
		return a > b;  
	}
};

int minCostOfAddition(list<int>& numbers) {
	priority_queue<int, vector<int>, revpriority> pq;

	for (int num : numbers) {
		pq.push(num);
	}

	int totalCost = 0;

	while (pq.size() > 1) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		totalCost += first + second;
		pq.push(first + second);
	}

	return totalCost;
}

int main() {
	setlocale(LC_ALL, "RUS");
	list<int> nums = {3, 1 ,2};
	std::cout << "Ввод: ";
	for (int num : nums) {
		std::cout << num;
		std::cout << " ";
	}
	std::cout << std::endl;
	cout << "Минимальная стоимость сложения: " << minCostOfAddition(nums) << endl;
	return 0;
}