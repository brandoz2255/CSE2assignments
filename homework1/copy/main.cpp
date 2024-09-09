#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>

using namespace std;

pair<int, int> wrap(int, int, int);
pair<int, int> next_rc(vector<vector<int>> &, int, int);

vector<vector<int>> magic(int);

void print_magic(const vector<vector<int>> &);



vector<vector<int>> magic(int n) {
    assert(n % 2 == 1);



    vector<vector<int>> mag;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++)
            row.push_back(0);
        mag.push_back(row);
    }



    int r = n - 1;
    int c = n / 2;

    mag[r][c] = 1;
    pair<int, int> nextrc;

    for (int i = 2; i <= n * n; i++) {
        nextrc = next_rc(mag, r, c);
        mag[nextrc.first][nextrc.second] = i;  // Set i, not 1
        r = nextrc.first;
        c = nextrc.second;
        print_magic(mag);
    }
    return mag;


}



pair<int, int> next_rc(vector<vector<int>> &mag, int r, int c) {
    int r1 = r;
    int c1 = c;
    pair<int, int> nextrc;


    int n = mag.size();



    if (r1 == n - 1 && c1 == n - 1) {
        nextrc.first = r1 - 1;
        nextrc.second = c1;
        return nextrc;
    }

    r1 = r1 + 1;
    c1 = c1 + 1;

    // decide whether to use this NEXT field or make adjustments
    if (r1 < n && c1 < n) {
        // valid (row, col) ... check cases and adjust ...
        if (mag[r1][c1] == 0) {
            nextrc.first = r1;  // field empty, return this (row, col)
            nextrc.second = c1;
            return nextrc;
        } else {
            // field already filled; move to prev position, then one up
            r1 = r1 - 2;
            c1 = c1 - 1;
            nextrc = wrap(r1, c1, n);  // use field or wrap if needed
            return nextrc;
        }
    } else {
        nextrc = wrap(r1, c1, n);  // new field off grid, so wrap around
        return nextrc;
    }
}



pair<int, int> wrap(int r, int c, int n) {
    pair<int, int> rc;

    if (r >= n) {
        // row too high, wrap vertically around back
        rc.first = 0;        // into first row
        rc.second = c;
        return rc;
    }


    if (r < 0) {
        // row too low, wrap vertically around back
        rc.first = n - 1;    // into last row
        rc.second = c;
        return rc;
    }


    if (c >= n) {
        // col too high, wrap horizontally around back
        rc.first = r;
        rc.second = 0;       // into first column
        return rc;
    }


    if (c < 0) {
        // col too low, wrap horizontally around back
        rc.first = r;
        rc.second = n - 1;   // into last column
        return rc;
    }

    // row and col are fine; keep both
    rc.first = r;
    rc.second = c;

    return rc;
}



void print_magic(const vector<vector<int>> &mag) {
    cout << endl;

    for (int i = 0; i < mag.size(); i++) {
        for (int j = 0; j < mag.size(); j++)
            if (mag[i][j] == 0)
                cout << left << setw(6) << "~" << " ";
            else
                cout << left << setw(6) << mag[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return;
}



int main() {
    int n;
    cout << "Size of magic square [odd]: " << endl;
    cin >> n;
    cout << endl;
    vector<vector<int>> magicSQ = magic(n);
    print_magic(magicSQ);

    return 0;
}
