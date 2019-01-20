//
// lab3.cpp
// Doga Ozkaracaabatlioglu, Kirill Vladimirov
// September 29, 18
// Lab 3
// Creating spirals in array
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int ARR_ROW_MAX = 15;
const int ARR_COL_MAX = 20;

void makeSpiral (int spiral[ARR_ROW_MAX][ARR_COL_MAX], int numbOfRows,
                 int numbOfColms)
{
    int curRow = 0, curCol = 0, i = 1;
    int left_border = 0, top_border = 0;
    int right_border = numbOfColms-1;
    int bottom_border = numbOfRows-1;

    while (i <= (numbOfRows)*(numbOfColms))
    {
        if (i == (numbOfRows)*(numbOfColms))
        {
            spiral[curRow][curCol] = i;
            break;
        }
        while (i <= (numbOfRows)*(numbOfColms) && curRow < bottom_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curRow++;
        }

        while (i <= (numbOfRows)*(numbOfColms) && curCol < right_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curCol++;
        }
        bottom_border--;

        while (i <= (numbOfRows)*(numbOfColms) && curRow > top_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curRow--;
        }
        right_border--;

        while (i <= (numbOfRows)*(numbOfColms) && curCol > left_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curCol--;
        }
        top_border++;
        left_border++;
        curRow = top_border;
        curCol = left_border;

   }

    return;
}

void printSpiral(int spiral[ARR_ROW_MAX][ARR_COL_MAX], int numbOfRows,
                 int numbOfColms, ostream &os)
{

    int limit = (numbOfColms*numbOfRows);

    if (limit < 10)
    {
        os << setw(2);
    }
    else if (limit < 100)
    {
        os << setw(3);
    }
    else if (limit < 1000)
    {
        os << setw(4);
    }
    for (int i=0;i<numbOfRows;i++)
    {
        for (int j=0;j<numbOfColms;j++)
        {
            os << spiral[i][j] << flush;
        }
        os << endl;
    }
}

void clearArray(int spiral[ARR_ROW_MAX][ARR_COL_MAX])
{
    for(int i=0;i<ARR_ROW_MAX;i++)
    {
        for (int j=0;j<ARR_COL_MAX;j++)
        {
            spiral[i][j] = 0;
        }
    }
    return;
}
int main()
{

    int mainSpiral[ARR_ROW_MAX][ARR_COL_MAX];

    //Open text file for output

    ofstream fout("output.txt");
    // Check for open failure.
    if( !fout )
    {
       cout << "Output file open failed\n";
       return -2;
    }
    cout << endl << endl << endl;

    // Clear Array, make, and print spiral
    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 1, 1);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 1, 2);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 2, 1);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

     clearArray(mainSpiral);
    makeSpiral(mainSpiral, 2, 2);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

     clearArray(mainSpiral);
    makeSpiral(mainSpiral, 5, 5);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

     clearArray(mainSpiral);
    makeSpiral(mainSpiral, 4, 7);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 4, 8);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 6, 4);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 15, 20);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX, fout);
    cout << endl << endl << endl;
    fout.close();
    return 0;
}
