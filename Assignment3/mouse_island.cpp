//
// mouse_island.cpp
// Doga Ozkaracaabatlioglu
// October 3, 2018
// Assignment 3
// A mouse tries to escape from an island. The code demonstrates
// the usage of two-dimensional arrays.
//

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

struct arrayLoc
{
    int x;
    int y;
};

void moveMouse(int &x, int &y)
{
    int which_way = rand() % 4;
    // up, right, down, left
    static int go[4][2] = {{0,-1}, {+1,0}, {0,+1}, {-1,0}};
    x += go[which_way][0];
    y += go[which_way][1];
    return;
}

void clearArray(int arr[21][21])
{
    for(int i=0;i<21;i++)
    {
        for (int j=0;j<21;j++)
        {
            arr[i][j] = 0;
        }
    }
    return;
}
void printArray(int arr[][21], int map_sizeX, int map_sizeY, ostream &fout)
{
    int limit = (map_sizeX*map_sizeY);
    int n = 1;
    while (limit /= 10)
    {
        n++;
    }
    for (int cur_y=0;cur_y < map_sizeY;cur_y++)
    {
        for (int cur_x=0;cur_x < map_sizeX;cur_x++)
        {
          fout << setw(n+1) << arr[cur_x][cur_y] << flush;
        }
          fout << endl;
    }
}
int main(int argc, char *argv[])
{
    // Parse Command Line Parameters
    if (argc < 3)
    {
        cout << "Error. Please run the program like: "
             << "this_program input_map_file.txt "
             << "output_file.txt seed_value(optional)" << endl;
        return -1;
    }
    else if (argc > 3)
    {
        int seed = atoi(argv[3]);
        if (seed == 0)
            srand(time(nullptr)); // Seed with time
        else
            srand(seed); // Seed with any other value

        // or not seed at all if not provided.
    }
    // Open Files
    ifstream fin;
    fin.open(argv[1]);
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
       return -2;
    }
    ofstream fout;
    fout.open(argv[2]);
    // Check for open failure.
    if( !fout )
    {
       cout << "Output file open failed\n";
       return -2;
    }
    //read the map && save initial position of the mouse and bridges
    int map_sizeX = 0, map_sizeY = 0, temp = 0,
        the_map[21][21], count_map[21][21];
    arrayLoc mouse, bridges[2], curLocation;
    clearArray(the_map);
    fin >> map_sizeY;
    fin >> map_sizeX;
    int bridge = 0;
    for (int cur_y=0;cur_y < map_sizeY;cur_y++)
    {
        for (int cur_x=0;cur_x < map_sizeX;cur_x++)
        {
        fin >> temp;
        if (temp == 1) // Mouse
        {
            mouse.x = cur_x;
            mouse.y = cur_y;
            fout << "Mouse Location:" << cur_x << " " << cur_y << endl;
            temp = 0; // Change mouse location with land space.
        }
        else if (temp == 0 && (cur_x == map_sizeX-1 || cur_y == map_sizeY-1
                               || cur_x == 0 || cur_y == 0) ) // Bridge
        {
            bridges[bridge].x = cur_x;
            bridges[bridge].y = cur_y;
            bridge++;
        }
        the_map[cur_x][cur_y] = temp;

        }
    }
    fin.close(); // Map is read, so close the input file.

    //initialize the count map to all zeros
    clearArray(count_map);
    //print the initialization values
    fout << "Supplied Parameters:" << endl;
    for (int i=0;i<argc;i++)
    {
        fout << i << " : " << argv[i] << endl;
    }
    fout << "Input File: " << argv[1] << endl;
    fout << "Output File: " << argv[2] << endl;
    fout << "Map: " << endl;
    printArray(the_map,map_sizeX,map_sizeY, fout);

    //loop to 100 lives
    int total_escaped = 0,total_drowned = 0, total_starved = 0;
    for (int i=0;i < 100;i++)
    {
        int escaped=0, drowned=0;
        // put mouse at starting point on map
        curLocation.x = mouse.x;
        curLocation.y = mouse.y;
        // loop to 100 moves or until escaped or drowned
        for (int j=0;j < 100;j++)
        {
            // move mouse
            moveMouse(curLocation.x,curLocation.y);
            //fout << "x: " << curLocation.x << " y:" << curLocation.y << endl;
            // count move to target square
            count_map[curLocation.x][curLocation.y]++;

            if (the_map[curLocation.x][curLocation.y] == -1)
            {
                // if( drowned )
                // handle drowning
               fout << "drowning" << endl;
               drowned = 1;
               total_drowned++;
               break;
            }
            else if (the_map[curLocation.x][curLocation.y] == 0
                && ((curLocation.x == bridges[0].x &&
                      curLocation.y ==  bridges[0].y)
                     || (curLocation.x == bridges[1].x &&
                          curLocation.y ==  bridges[1].y))
                    )
            {
                // else if( escaped )
                // handle escaping
                fout << "escaped at " << curLocation.x << " "
                     << curLocation.y << endl;
                escaped = 1;
                total_escaped++;
                break;
            }
        }
        // end for 100 moves, still in island
         if(escaped == 0 && drowned == 0)
         {
            // handle starving
            fout << "starving" << endl;
            total_starved++;
         }
    } //end for 100 lives

    //print lives statistics and count map
    fout << "Total Escaped: " << total_escaped << "\n"
         << "Total Drowned: " << total_drowned << "\n"
         << "Total Starved: " << total_starved << "\n"
         << endl;
     printArray(count_map,map_sizeX,map_sizeY, fout);

    fout.close();
    return 0;
}
