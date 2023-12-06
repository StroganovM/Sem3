#include "List.h"
int main() {
	TList<int> a;
	a.push_back_(1);
	a.push_front_(2);

	a.replace(a.front_node(), 3 );
	return 0;
}