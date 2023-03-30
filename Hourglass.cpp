// simulates an hourglass

#include <iostream>

using namespace std;

void displayTime(int rows, int maxTime, int fullTime, int passedTime);
void printGlassHour(int rows);

int main() {
    // int rows;
    // cout << "Enter number of rows: " << endl;
    // cin >> rows;
    // printGlassHour(rows);


    int rows, fullTime, passedTime;
    cout << "Enter number of rows: ";
    cin >> rows;
    // find maxTime according to nb of rows
    // instead of having a fixed nb of rows (17)
    int maxTime = 0;
    for (int i = 3, inc = 0; i < rows; i++) {
        if (i % 2 == 0)
            inc++;
        maxTime += inc;
    }
    cout << "Enter the full time units: "
         << "(minimum 0 and maximum "
         << maxTime << "): ";
    cin >> fullTime;
    cout << "Enter the passed time units: "
         << "(minimum 0 and maximum "
         << fullTime << "): ";
    cin >> passedTime;
    displayTime(rows, maxTime, fullTime, passedTime);

    return 0;
}

void displayTime(int rows, int maxTime, int fullTime, int passedTime) {
    int upperCounter = 0, lowerCounter = 0;
    for (int i = 0; i < rows; i++) {
        if (i == 0 || i == rows - 1) {
            for (int j = 0; j < rows; j++)
                cout << "* ";
            cout << endl;
        }
        else if (i < rows/2) {
            for (int j = 0; j < i; j++)
                cout << "  ";
            cout << "* ";
            for (int j = 0; j < rows - 2*(i+1); j++, upperCounter++)
                if (upperCounter >= maxTime - (fullTime - passedTime))
                    cout << "+ ";
                else
                    cout << "  ";
            cout << "*" << endl;
        }
        else if (i == rows/2) {
            for (int j = 0; j < rows; j++)
                if (j == rows/2 - 1 && rows % 2 == 0)
                    cout << "* ";
                else if (j == rows/2)
                    cout << "* ";
                else
                    cout << "  ";
            cout << endl;
        }
        else if (i > rows/2) {
            for (int j = 0; j < rows - i - 1; j++)
                cout << "  ";
            cout << "* ";
            for (int j = 0; j < 2*i - rows; j++, lowerCounter++)
                if (lowerCounter >= maxTime - (passedTime))
                    cout << "+ ";
                else
                    cout << "  ";
            cout << "*" << endl;
        }
    }
}

void printGlassHour(int rows) {
    for (int i = 0; i < rows; i++) {
        if (i == 0 || i == rows - 1) {
            for (int j = 0; j < rows; j++)
                cout << "* ";
            cout << endl;
        }
        else if (i < rows/2) {
            for (int j = 0; j < i; j++)
                cout << "  ";
            cout << "* ";
            for (int j = 0; j < rows - 2*(i+1); j++)
                cout << "+ ";
            cout << "*" << endl;
        }
        else if (i == rows/2) {
            for (int j = 0; j < rows; j++)
                if (j == rows/2 - 1 && rows % 2 == 0)
                    cout << "* ";
                else if (j == rows/2)
                    cout << "* ";
                else
                    cout << "  ";
            cout << endl;
        }
        else if (i > rows/2) {
            for (int j = 0; j < rows - i - 1; j++)
                cout << "  ";
            cout << "* ";
            for (int j = 0; j < 2*i - rows; j++)
                cout << "+ ";
            cout << "*" << endl;
        }
    }
}
