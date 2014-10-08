/* The purpose of this program is to read scores from a file (one score per line)
 * and store the value of the lowest, highest, and average in a struct.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct statsT {
    int low;
    int high;
    double avrg;
};

statsT CalculateStats (string filename) {
    statsT stats;
    stats.high = -1;
    stats.low = 101;
    string number;
    int total = 0;
    double numOfLines = 0;
    ifstream file (filename);
    if (file.is_open()) {
        while (getline(file, number)) {
            total += stoi (number);
            numOfLines++;
            if (stoi(number) < stats.low) {
                stats.low = stoi(number);
            }
            if (stoi(number) > stats.high) {
                stats.high = stoi(number);
            }
        }
        file.close();
    } else {
        cout << "failed to open file";
        exit (EXIT_FAILURE);
    }
    stats.avrg = total/numOfLines;
    return stats;
}

int main() {
    string file = "/Users/yotamros/Documents/C++/Scores/Scores/numbers.txt";
    statsT stats = CalculateStats(file);
    cout << "The average score is: " << stats.avrg << endl;
    cout << "The lowest score is: " << stats.low << endl;
    cout << "The highest score is: " << stats.high << endl;
    return 0;
}

