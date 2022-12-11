#include <iostream>

using namespace std;

const char *Q = " W ";
const char *S = " * ";

void setQ(int*, int, int, int);
bool tryQ(int*, int, int, int);
void print(const char*, const int*, int, int);

static int iters;

int main()
{
    iters = 0;

    const int n = 8;
    int array[n] = {};

    print("Start: ", array, n, n);

    setQ(array, 0, 0, n);

    cout << "Results count: " << (iters) << endl;
}

void setQ(int *array, int row, int column, int size)
{
    if(row < 0)
        return;

    if(row == size)
    {
        iters ++;

        print("Result: ", array, row, size);

        setQ(array,  row - 1, array[row - 1] + 1, size);

        return;
    }

    int i = -1;

    while(column < size && i == -1)
    {
        if(tryQ(array, row - 1, row, column))
            i = column;

        if(i == -1)
            column++;
    }

    if(i != -1)
        array[row] = i;

    int j = (i == -1 && row > 0)
            ? 1
            : 0;

    i = (i != -1) ? 1 : -1;

    setQ(array, row + i, (array[row - 1] + 1) * j, size);
}

bool tryQ(int *array, int step, int row, int column)
{
    bool f = true;

    if(step >= 0)
    {
        int i = abs(array[step] - column);
        int j = abs(step - row);

        f = array[step] == -1 || (i != j && array[step] != column);

        if(f) f = tryQ(array, step - 1, row, column);
    }

    return f;
}

void print(const char* msg, const int *array, int row, int column)
{
    cout << msg << iters << endl;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            cout << ((*(array + i) == j) ? Q : S);

        cout << endl;
    }

    cout << "------" << endl;
}