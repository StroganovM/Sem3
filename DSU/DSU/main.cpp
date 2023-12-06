#include"DSU.h"


int main() {
	int field[5][7] = {
	{1, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 0},
	{0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 1}
	};

	dsu island;

	// Iterate through the matrix to process each cell
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			// If the cell is part of an island (has a value of 1)
			if (field[i][j] == 1) {
				int currentIndex = i * 7 + j + 1;

				// Check neighboring cells and union if they are also part of the island
				if (i > 0 && field[i - 1][j] == 1) {
					int topIndex = (i - 1) * 7 + j + 1;
					island.Union(currentIndex, topIndex);
				}
				if (j > 0 && field[i][j - 1] == 1) {
					int leftIndex = i * 7 + (j - 1) + 1;
					island.Union(currentIndex, leftIndex);
				}
			}
		}
	}

	// Count the number of distinct islands
	int islandCount = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (field[i][j] == 1) {
				int currentIndex = i * 7 + j + 1;
				if (island.find(currentIndex) == currentIndex) {
					islandCount++;
				}
			}
		}
	}

	std::cout << "Number of islands: " << islandCount << std::endl;

	return 0;
}