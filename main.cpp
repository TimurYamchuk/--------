#include <iostream>
#include <sstream>

using namespace std;

class ArraySizeException : public exception {
private:
    int bool_;
public:
    ArraySizeException(bool a) {
        bool_ = a;
    }
    void ExceptioNPrint1()
    {
        cout << "Array has an invalid size" << endl;
    }
};

class ArrayDataException : public exception {
private:
    int row, col;
public:
    ArrayDataException(int row, int col) : row(row), col(col) {}

    void ExceptioNPrint2() const {
        cout << "Invalid data at row " << row << ", column " << col;
    }
};

class ArrayValueCalculator{
public:
    int doCalc(const char* arr[4][4], int row, int col) {
        if (row != col)
        {
            throw ArraySizeException(0);
        }
        int sum = 0;
        int value;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (isCharNumeric(arr[i][j])) {
                    value = stoi(arr[i][j]);
                    sum += value;
                }
                else {
                    throw ArrayDataException(i, j);
                }
            }
        }
        return sum;
    }

private:
    bool isCharNumeric(const char* str) {
        for (int i = 0; str[i] != '\0'; ++i) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    try {
        const int row = 4;
        const int col = 4;
        const char* arr[row][col] = {
        {"1", "1", "1", "1"},
        {"1", "1", "1", "1"},
        {"1", "1", "1", "1"},
        {"1", "1", "1", "1"}
        };

        ArrayValueCalculator calculator;
        int result = calculator.doCalc(arr, row, col);
        cout << "Sum of array values: " << result << endl;
    }

    catch (ArraySizeException& a) {
        cout << "ArraySizeException: ";
        a.ExceptioNPrint1();
    }

    catch (ArrayDataException& a) {
        cout << "ArrayDataException: ";
        a.ExceptioNPrint2();
    }

    return 0;
}
