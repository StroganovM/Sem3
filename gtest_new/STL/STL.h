#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <list>
#include <stack>
//part 1
void null_vec(std::vector<int>& vec);
void random_vec(std::vector<int>& vec);
std::pair<int, int> min_max_vec(const std::vector<int> vec);
void push_back_mass_to_vec_sort(std::vector<int>& vec, int* mass, int mass_size);
void null_low_a_vec(std::vector<int>& vec, int a);
std::vector<int> elem_higer_a_vec(std::vector<int> vec, int a);
void mix_vec(std::vector<int>& vec);
void del_higer_a_vec(std::vector<int>& vec, int a);
int task_i_vec(std::vector<int>& vec);
void clear_vec(std::vector<int>& vec);
//part 2
void add_mass_list(std::list<int>& list, int* mass, int mass_size);
std::vector<int> n_vector_list(std::list<int>& list, int n);
void del_elem_list(std::list<int>& list, int pos);
void change_three_pos_list(std::list<int>& list);
bool in_vec(std::vector<int> vec, int a);
void del_recuring_list(std::list<int>& list);
//part 3
void reverse_lisr_stack(std::list<int>& list);
void print_stack(std::stack<int> stack);