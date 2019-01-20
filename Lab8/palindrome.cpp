//
// palindrome.cpp
//
// Doga Ozkaracaabatlioglu, Prasoon Shakya
// November 29, 2018
// Lab 8 - Palindrome
// reads a series of lines of text and tests each line,
// using both an iterative and recursive version of palindrome function
//
#include <iostream>
#include <cctype>

using namespace std;

bool isIterativePalindrome(char str[255]);

int main(int argc, char *argv[])
{
    //char str[255] = "madam";
    char str[255] = "Madam, I'  m Adam.";
    char str2[255] = "no way yaw ond ssfgf df";
    char str3[255] = "Madam";

    cout << "### is Iterative Palindrome:\n" << isIterativePalindrome(str) << endl;
    cout << "### is Iterative Palindrome:\n" << isIterativePalindrome(str2) << endl;
    cout << "### is Iterative Palindrome:\n" << isIterativePalindrome(str3) << endl;
    return 0;
}

bool isIterativePalindrome(char str[255])
{
    for(int i=0,j=strlen(str)-1; i < j; i++,j--)
    {
        if ( tolower(str[i]) != tolower(str[j]) )
            return false;
        else
            return true;
    }
}

