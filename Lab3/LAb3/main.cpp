//
// lab3.cpp
// Doga Ozkaracaabatlioglu, Kirill Vladimirov
// September 29, ARR_COL_MAX18
// Lab 3
// Creating spirals in array
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int ARR_ROW_MAX = 15;
const int ARR_COL_MAX = 20;

void makeSpiral (int spiral[ARR_ROW_MAX][ARR_COL_MAX], int row_size, int col_size)
{
    int curItemInCol = 0, curItemInRow = 0, i = 1;
    int left_bound = 0;
    int right_bound = row_size;
    int top_bound = 0;
    int bottom_bound = col_size;

    while (i < (row_size+1)*(col_size+1)) //problem
    {

        while (curItemInCol < bottom_bound)
        {
            spiral[curItemInCol][curItemInRow] = i;
            i++;
            curItemInCol++;
        }

        while (curItemInRow < right_bound)
        {
            spiral[curItemInCol][curItemInRow] = i;
            i++;
            curItemInRow++;
        }
        bottom_bound--;

        while (curItemInCol > top_bound)
        {
            spiral[curItemInCol][curItemInRow] = i;
            i++;
            curItemInCol--;
        }
        right_bound--;
        while (curItemInRow > left_bound)
        {
            spiral[curItemInCol][curItemInRow] = i;
            i++;
            curItemInRow--;
        }
        top_bound++;
        left_bound++;
        curItemInCol = top_bound;
        curItemInRow = left_bound;

     }


}

void printSpiral(int spiral[ARR_ROW_MAX][ARR_COL_MAX], int maxRow, int maxCol)
{
    /*cout<< "R/C"<<flush;
    for (int g=0; g < maxCol; g++)
    {
        cout<<'\t'<<g<<flush;

    }
    cout << endl;*/

    for (int i=0;i<maxRow;i++)
    {
        for (int j=0;j<maxCol;j++)
        {
            cout << spiral[i][j] << '\t' << flush;
        }
        cout << endl;
    }
}

int clearArray(int spiral[ARR_ROW_MAX][ARR_COL_MAX])
{
    for(int i=0;i<ARR_ROW_MAX;i++)
    {
        for (int j=0;j<ARR_COL_MAX;j++)
        {
            spiral[i][j] = 0;
        }
    }



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
    makeSpiral(mainSpiral, 2, 3);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 15, 20);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX);
    cout << endl << endl << endl;

    clearArray(mainSpiral);
    makeSpiral(mainSpiral, 4, 5);
    printSpiral(mainSpiral, ARR_ROW_MAX, ARR_COL_MAX);
    cout << endl << endl << endl;

    fout.close();
    return 0;
}
