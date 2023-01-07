#include <iostream>

using namespace std;

const char *Q = " W ";
const char *S = " * ";

void setQ(int*, int, int, int);
bool tryQ(int*, int, int, int);
void print(const char*, const int*, int, int, int);

static int results;
static int steps;

int main()
{
    results = steps = 0;

    const int n = 8;
    int array[n] = {};

    setQ(array, 0, 0, n);

    cout << "Results count: " << (results) << endl;
}

void setQ(int *array, int row, int column, int size)
{
    if(row < 0) return;

    if(row == size)
    {
        print("Result: ", array, row, size, ++results);
        setQ(array,  row - 1, array[row - 1] + 1, size);
        return;
    }

    int i = -1;
    while(column < size && i == -1)
    {
        if(tryQ(array, row - 1, row, column))
            i = column;

        if(i == -1) column++;
    }

    if(i != -1) array[row] = i;

    print("Step: ", array, row, size, ++steps);

    int j = (i == -1 && row > 0) ? 1 : 0;

    i = (i != -1) ? 1 : -1;

    setQ(array, row + i, (array[row - 1] + 1) * j, size);
}

bool tryQ(int *array, int step, int row, int column)
{
    if(step < 0) return true;

    if(array[step] == column|| abs(array[step] - column) == abs(step - row))
        return false;

    return tryQ(array, step - 1, row, column);
}

void print(const char* msg, const int *array, int row, int column, int counter)
{
    cout << msg << counter << endl;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            cout << ((*(array + i) == j) ? Q : S);

        cout << endl;
    }

    cout << "------" << endl;
}