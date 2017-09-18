#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct cell {
    int x, y;
    int distance;
    cell(int x, int y, int distance) :
        x(x), y(y), distance(distance) {}
};

bool operator<(const cell& a, const cell& b) {
    if (a.distance == b.distance) {
        if (a.x != b.x) {
            return (a.x < b.x);
        }
        else {
            return (a.y < b.y);
        }
    }
    return (a.distance < b.distance);
}

bool insideGrid(int i, int j, int row, int column) {
    return (i >= 0 && i < column && j >= 0 && j < row);
}

int shortest(int** grid, int row, int column) {
    int sum[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            sum[i][j] = INT_MAX;
        }
    }
    int neighborx[] = {-1, 0, 1, 0};
    int neighbory[] = {0, 1, 0, -1};
    set<cell> st;
    st.insert(cell(0, 0, 0));
    sum[0][0] = grid[0][0];
    while (!st.empty()) {
        cell k = *st.begin();
        st.erase(st.begin());
        for (int i = 0; i < 4; i++) {
            int x = k.x + neighborx[i];
            int y = k.y + neighbory[i];
            if (!insideGrid(x, y, row, column)) {
                continue;
            }
            if (sum[x][y] > sum[k.x][k.y] + grid[x][y]) {
                if (sum[x][y] != INT_MAX) {
                    st.erase(st.find(cell(x, y, sum[x][y])));
                }
                sum[x][y] = sum[k.x][k.y] + grid[x][y];
                st.insert(cell(x, y, sum[x][y]));
            }
        }
    }
    return sum[row - 1][column - 1];
}

int main() {
    ifstream input;
    ofstream output;
    input.open ("sum.in");
    output.open ("sum.out");
    int row, column;
    input >> row >> column;
    int **grid=new int*[row];
    for(int i=0;i<row;i++) {
        grid[i]=new int[column];
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<column;j++) {
            input>>grid[i][j];
        }
    }
    output << shortest(grid, row, column) << endl;
    return 0;
}

