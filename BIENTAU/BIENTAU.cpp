#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream infile;
    ofstream outfile;
    int n, max_len = 0;
    int notes[5000];
    int diffs[5000];
    infile.open("BIENTAU.INP");
    outfile.open("BIENTAU.OUT");
    infile >> n;
    for (int i = 0; i < n; i++) {
        infile >> notes[i];
    }
    for (int i = 0; i < n - 1; i++) {
        diffs[i] = notes[i + 1] - notes[i];
    }
    for (int diff = 1; diff <= 100; diff++) {
        for (int i = 0; i < n - 1; i++) {
            int len = 2;
            int j = i + 1;
            while (j < n && diffs[j - 1] == diff && notes[j] == notes[j - 1] + diff) {
                len++;
                j++;
            }

            if (len > max_len) {
                max_len = len;
            }
        }
    }
    outfile << max_len << endl;
    infile.close();
    outfile.close();

    return 0;
}
