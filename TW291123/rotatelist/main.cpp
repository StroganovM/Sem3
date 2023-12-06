#include <iostream>
#include <list>
void sdwiglist(std::list<int>& lst, int n) {
	int size = lst.size();
	n = n % size;
	if (n < 0) {
		n += size;
	}
	for (int i = 0; i < n; i++) {
		if (n < size/2){
			int firstElem = lst.front();
			lst.pop_front();
			lst.push_front(firstElem);
		}
		else {
			int lastElem = lst.back();
			lst.pop_back();
			lst.push_front(lastElem);
		}
	}
}
int main() {
	std::list<int> nums = { 1, 3, 4, 5, 8 };
	int sdwig = -2;
	sdwiglist(nums, sdwig);
	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout<<std::endl;
	return 0;
}