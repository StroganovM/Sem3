#include "STL.h"
//part 1
void null_vec(std::vector<int>& vec) {
	int i = 0;
	while (i < vec.size()) {
		vec[i] = 0;
		i++;
	}
	if (vec.size() < 20) {
		while (i < 20) {
			vec.push_back(0);
			i++;
		}
	}
	else {
		while (i > 20) {
			vec.pop_back();
			i--;
		}
	}
}
void random_vec(std::vector<int>& vec) {
	srand(time(NULL));
	for (auto i = vec.begin(); i < vec.end(); i++) {
		*i = rand() % (-100 - 100 + 1) + 100;
		std::cout << *i << " ";
		
	}
	std::cout << std::endl;
}
std::pair<int, int> min_max_vec(const std::vector<int> vec) {
	std::pair<int, int> res;
	auto i = vec.begin();
	res = { *i, *i };
	for (auto i = vec.begin(); i < vec.end(); i++) {
		if (*i < res.first) {
			res.first = *i;
		}
		if (*i > res.second) {
			res.second = *i;
		}
	}
	
	return res;
}
void push_back_mass_to_vec_sort(std::vector<int>& vec, int* mass, int mass_size) {
	for (int i = 0; i < mass_size; i++) {
		vec.push_back(mass[i]);
	}
	std::sort(vec.begin(), vec.end());
}
void null_low_a_vec(std::vector<int>& vec, int a) {
	for (auto i = vec.begin(); i < vec.end(); i++) {
		if (*i < a) {
			*i = 0;
		}
	}
}
std::vector<int> elem_higer_a_vec(std::vector<int> vec, int a) {
	std::vector<int>res;
	for (auto i = vec.begin(); i < vec.end(); i++) {
		if (*i > a) {
			res.push_back(*i);
		}
	}
	return res;
}
void mix_vec(std::vector<int>& vec) {
	srand(time(NULL));
	for (auto i = vec.begin(); i < vec.end(); i++) {
		auto x = vec.begin() + rand() % (vec.begin() - vec.end() + 1);
		int t = *x;
		*x = *i;
		*i = t;
	}
}
void del_higer_a_vec(std::vector<int>& vec, int a) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > a) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
}
int task_i_vec(std::vector<int>& vec) {
	if (vec.size() % 2 == 1) {
		vec.pop_back();
		return vec.size();
	}
	else {
		for (int i = 0; i < vec.size() / 2; i++) {
			std::swap(vec[i], vec[vec.size() - i - 1]);
		}
		return vec.size();
	}
}
void clear_vec(std::vector<int>& vec) {
	vec.clear();
}
//part 2
void add_mass_list(std::list<int>& list, int* mass, int mass_size) {
	for (int i = 0; i < mass_size; i++) {
		list.push_back(mass[i]);
	}
}
std::vector<int> n_vector_list(std::list<int>& list, int n) {
	if (n - 1 > list.size()) { throw 0; }
	else {
		std::vector<int> res;
		auto list_i = list.begin();
		for (int i = 0; i < n; i++) {
			res.push_back(*list_i);
			std::advance(list_i, 1);
		}
		return res;
	}
}
void del_elem_list(std::list<int>& list, int pos) {
	auto i = list.begin();
	if (pos > list.size()) {
		throw 0;
	}
	else {
		if (pos > 0) {
			std::advance(i, pos);
			list.erase(i);
		}
		else {
			list.pop_front();
		}
	}
}

void change_three_pos_list(std::list<int>& list) {
	if (list.size() < 3) { throw 0; }
	else {
		srand(time(0));
		std::vector<int> pos_vec;
		for (int i = 0; i < 3; i++) {
			auto list_i = list.begin();
			int pos = rand() % list.size();
			while (in_vec(pos_vec, pos)) {
				pos = rand() % list.size();
			}
			pos_vec.push_back(pos);
			std::advance(list_i, pos);
			*list_i = -100 + rand() % 201;
		}
	}
}
bool in_vec(std::vector<int> vec, int a) {
	for (auto i = vec.begin(); i < vec.end(); i++) {
		if (*i == a) {
			return true;
		}
	}
	return false;
}
void del_recuring_list(std::list<int>& list) {
	std::vector<int> elements;

	for (int i = 0; i < list.size(); i++)
	{
		auto list_i = list.begin();
		std::advance(list_i, i);
		if (in_vec(elements, *list_i)) {
			list.erase(list_i);
			i--;
		}
		else {
			elements.push_back(*list_i);
		}
	}
}
//part 3
void reverse_lisr_stack(std::list<int>& list) {
	std::stack<int> tmp;
	while (list.size() > 0) {
		tmp.push(list.front());
		list.pop_front();
	}
	while (tmp.size() != 0) {
		list.push_back(tmp.top());
		tmp.pop();
	}
}
void print_stack(std::stack<int> stack) {
	std::cout << "\n|   |\n";
	while (stack.size() > 0) {
		std::cout << "| " << stack.top() << " |\n";
		stack.pop();
	}
	std::cout << " --- \n";
}