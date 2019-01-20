//
// lab4.cpp
// Doga Ozkaracaabatlioglu, Kirill Vladimirov
// October 16, 18
// Lab 4
// Creating spirals in array with
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int Table_Elem_MAX = 13;
const int Table_Col_MAX = 2;

void makeSpiral (int *spiral, int numbOfRows,
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
            *(spiral + numbOfColms * curRow + curCol) = i;
            break;
        }
        while (i <= (numbOfRows)*(numbOfColms) && curRow < bottom_border)
        {
            *(spiral + numbOfColms * curRow + curCol) = i;
            i++;
            curRow++;
        }
        while (i <= (numbOfRows)*(numbOfColms) && curCol < right_border)
        {
            *(spiral + numbOfColms * curRow + curCol) = i;
            i++;
            curCol++;
        }
        while (i <= (numbOfRows)*(numbOfColms) && curRow > top_border)
        {
            *(spiral + numbOfColms * curRow + curCol) = i;
            i++;
            curRow--;
        }
        while (i <= (numbOfRows)*(numbOfColms) && curCol > left_border)
        {
            *(spiral + numbOfColms * curRow + curCol) = i;
            i++;
            curCol--;
        }
        bottom_border--;
        right_border--;
        top_border++;
        left_border++;
        curRow = top_border;
        curCol = left_border;
   }

    return;
}

void printSpiral(int *spiral, int numbOfRows,
                 int numbOfColms, ostream &os)
{
    int limit = (numbOfColms*numbOfRows);
    int n = 1;
    while (limit /= 10)
    {
        n++;
    }
    for (int i=0;i<numbOfRows;i++)
    {
        for (int j=0;j<numbOfColms;j++)
        {
            os << setw(n+1) << *(spiral + numbOfColms * i + j) << flush;
        }
        os << endl;
    }
}

void clearArray(int *spiral, int numbOfRows, int numbOfColms)
{
    for(int i=0;i<numbOfRows;i++)
    {
        for (int j=0;j<numbOfColms;j++)
        {
            *(spiral + j * numbOfColms + j) = 0;
        }
    }
    return;
}

int main(int argc, const char* argv[])
{

    const int table[Table_Elem_MAX][Table_Col_MAX] = {{1,1},{1,2},{2,1},{4,4},
                {5,5},{4,7},{7,4},{4,8},{6,4},{15,20}, {7,7}, {10,13}, {13,3}};
    if (argc<2)
    {
        cout << "No output file name specified. "
             << "Please run the program \"lab4 filename.txt\"" << endl;
        return -1;
    }
    else
    {
    //Open text file for output
    ofstream fout(argv[1]);
    // Check for open failure.
    if( !fout )
    {
       cout << "Output file open failed." << flush;
       return -2;
    }
    fout << "Output file name: " << argv[1] << endl;
    // Clear Array, make, and print spiral
    for (int i = 0; i<Table_Elem_MAX; i++)
    {
        int arr_row = table[i][0];
        int arr_col = table[i][1];
        int mainSpiral[arr_row][arr_col];
        fout << "Table with corners: " << arr_row << " by " << arr_col;
        fout << endl << endl;
        clearArray(&mainSpiral[0][0], arr_row, arr_col);
        makeSpiral(&mainSpiral[0][0], arr_row, arr_col);
        printSpiral(&mainSpiral[0][0], arr_row, arr_col, fout);
        fout << endl << endl << endl;
    }
    fout.close();
    return 0;
    }
}
