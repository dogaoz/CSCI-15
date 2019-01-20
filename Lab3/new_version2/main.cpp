//
// lab3.cpp
// Doga Ozkaracaabatlioglu, Kirill Vladimirov
// October 2, 18
// Lab 3
// Creating spirals in array
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int ARR_ROW_MAX = 15;
const int ARR_COL_MAX = 20;
const int Table_Elem_MAX = 13;
const int Table_Col_MAX = 2;

void makeSpiral (int spiral[ARR_ROW_MAX][ARR_COL_MAX], int numbOfRows,
                 int numbOfColms)
{
    int curRow = 0, curCol = 0, i = 1;
    int left_border = 0, top_border = 0;
    int right_border = numbOfColms-1;
    int bottom_border = numbOfRows-1;

    int total_spaces = (numbOfRows)*(numbOfColms);
    while (i <= total_spaces)
    {
        curRow = top_border;
        curCol = left_border;
        if (i == total_spaces)
        {
           spiral[curRow][curCol] = i;
            break;
       }
        while (i <= total_spaces && (curRow < bottom_border) )
        {
            spiral[curRow][curCol] = i;
            i++;
            curRow++;
        }

        while (i <= total_spaces && curCol < right_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curCol++;
        }

        while (i <= total_spaces && curRow > top_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curRow--;
        }

        while (i <= total_spaces && curCol > left_border)
        {
            spiral[curRow][curCol] = i;
            i++;
            curCol--;
        }

        bottom_border--;
        right_border--;
        top_border++;
        left_border++;
   }

    return;
}

void printSpiral(int spiral[ARR_ROW_MAX][ARR_COL_MAX], int numbOfRows,
                 int numbOfColms, ostream &os)
{

    int limit = (numbOfColms*numbOfRows);
    int n = 1;
    while (limit /= 10)
    {
        n++;
    }
    for (int i=0;i<ARR_ROW_MAX;i++)
    {
        for (int j=0;j<ARR_COL_MAX;j++)
        {
            os << setw(n+1) << spiral[i][j] << flush;
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
    const int table[Table_Elem_MAX][Table_Col_MAX] = {{1,1},{1,2},{2,1},{4,4},
                {5,5},{4,7},{7,4},{4,8},{6,4},{15,20}, {7,7}, {10,13}, {13,3}};
    int mainSpiral[ARR_ROW_MAX][ARR_COL_MAX];
    //Open text file for output
    ofstream fout("output.txt");
    // Check for open failure.
    if( !fout )
    {
       cout << "Output file open failed\n";
       return -2;
    }
    // Clear Array, make, and print spiral
    for (int i = 0; i<Table_Elem_MAX; i++)
    {
        cout << "Table with corners: " << table[i][0] << " by " << table[i][1];
        cout << endl << endl;
        clearArray(mainSpiral);
        makeSpiral(mainSpiral, table[i][0], table[i][1]);
        printSpiral(mainSpiral, table[i][0],  table[i][1], cout);
        cout << endl << endl << endl;
    }
    fout.close();
    return 0;
}
