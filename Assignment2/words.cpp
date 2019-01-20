//
// words.cpp
// Doga Ozkaracaabatlioglu
// September 23, 2018
// Assignment 2
// A program that reads lines of text from a file 
//

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#define DELIMS " .\n"
#define MAX 100

struct word
{
    char word[16] = "";
    int count = 0;
};
int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    word unique[100];
    char data[MAX] = "", tokdata[MAX] = "", *p1 = NULL, *p2 = NULL;
    char shortest_word[16] = "", longest_word[16] = "";
    int i = 0, line_cnt = 0, word_cnt = 0, z = 0;
    bool exists = false;

    if (argc < 3)
    {
        cout << "Use it like ./program_name input_file.txt output_file.txt" 
             << endl;
        return -1;
    }

    fin.open(argv[1]);
    fout.open(argv[2]);
    // Check for open failure.
    if( !fin || !fout )
    {
        cout << "Error opening files." << endl;
        return -1;
    }
    
    while (!fin.eof())
    {
        // get a line(where, how big, stop at)
        fin.getline( data, MAX-1, '\n' );
        fout << data << endl;
        // save for tokenization 
        // (only because strtok destroys the string passed in)
        p1 = strcpy( tokdata, data );
        p2 = strtok( tokdata, DELIMS );
        while(p2 != NULL)
        {
            // Check if the word is in unique words
            // add to count if it is already added
            for (int k = 0; k < MAX; k++)
            {
                if( strcmp(p2,unique[k].word) == 0 )
                {
                    unique[k].count += 1;
                    exists = true;
                }
            }
            // The word doesn't exist in unique list.
            if (exists == false)
            {
                // Add word into unique word array char by char
                strcpy(unique[i].word, p2);

                unique[i].count += 1;
                // increasing i to go to next field in unique words for the new
                // unique words found in next time in the loop
                i++;
            }
            exists = false;
            word_cnt++;
            p2 = strtok(NULL,DELIMS);
        }
        line_cnt++;
    }
    // Find longest word and shortest word while counting for unique words
    // Print stats
    fout << "Word Count: " << word_cnt << endl;
    fout << "Line Count: " << line_cnt << endl; 
    fout << "## Unique words ##" << endl;
    while(z < MAX && unique[z].count != 0)
    {
        fout << unique[z].word 
             << " | count = " << unique[z].count << endl;
        if ( (z == 0) ^ (strcmp(shortest_word, "") != 0
            && strlen(unique[z].word ) < strlen(shortest_word)) )
        {
            strcpy(shortest_word, unique[z].word);
        }
        if ( (z == 0) ^ (strcmp(longest_word, "") != 0
            && strlen(unique[z].word ) > strlen(longest_word)) )
        {
            strcpy(longest_word, unique[z].word);
        }
        z++;
    }
    fout << "Unique word count: " << z << endl;
    fout << "Shortest Word: " << shortest_word << endl;
    fout << "Longest Word: " << longest_word << endl;
    // Close Files
    fin.close();
    fout.close();
    return 0;
}