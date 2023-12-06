#include<iostream>
#include <cstdlib>
#include <ctime>
#define MAX_SIZE 1000
class dsu {
    int* data;
    int* rank;
public:
    friend class MazeGenerator;

    dsu() {
        data = new int[MAX_SIZE];
        rank = new int[MAX_SIZE];
        for (int i = 1; i < MAX_SIZE; i++) {
            data[i] = i;
            rank[i] = 0;
        }
    }
    ~dsu() {
        delete[] data;
        delete[] rank;
        rank = nullptr;
        data = nullptr;
    }
    int getrang(int val) {
        return rank[val];
    }
    void Union (int x, int y) {
        if (x > MAX_SIZE ||  x <= 0 ||  y > MAX_SIZE || y <= 0)
            throw std::out_of_range("x or y not inside sets");
        int parent_x = find(x);
        int parent_y = find(y);
        if (rank[parent_x] == rank[parent_y]) {
            data[parent_x] = parent_y;
            rank[parent_y]++;
        }
        else if (rank[parent_x] > rank[parent_y]) {
            //
            data[parent_y] = parent_x;
        }
        else if (rank[parent_x] < rank[parent_y]) {
            //
            data[parent_x] = parent_y;
        }
    }
    int find(int val) {
        if (val == data[val]) {
            return val;
        }
        return find(data[val]); // Added return statement
    }

    int getSetSize(int val) {
        int parent = find(val);
        int setSize = 0;
        for (int i = 1; i < MAX_SIZE; i++) {
            if (find(i) == parent) {
                setSize++;
            }
        }
        return setSize;
    }

    friend std::ostream& operator<<(std::ostream& os, const dsu& d);

};
std::ostream& operator<<(std::ostream& os, const dsu& d) {
    for (int i = 1; i < MAX_SIZE; ++i) {
        os << "inf " << i << " -> father: " << d.data[i] << ", rank: " << d.rank[i] << "\n";
    }
    return os;
}

