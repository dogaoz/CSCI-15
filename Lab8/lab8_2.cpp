//
//lab8.cpp
//
//Prasoon Shakya & Doga Ozkaracaabatlioglu
//11/30/2018
//Lab 8
//it checks if a word or a sentence is palindrome or not.
//

#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

bool is_Equal(char word[], int i, int j)
{
    return (tolower(word[i]) == tolower(word[j]));
}

void check_lower(char word[], int &i)
{
    if (!isalpha(word[i]))
    {
        i++;
        check_lower(word, i);
    }
}

void check_upper(char word[], int &j)
{
    if (!isalpha(word[j]))
    {
        j--;
        check_lower(word, j);
    }
}
void IsPalindromeIterative(char word[], int& i, int& j)
{
        
        while (i < j)
        {
            while(!isalpha(word[i]))
            {
                i++;
            }
            while(!isalpha(word[j]))
            {
                j--;
            }
            if(!is_Equal(word, i, j))
            {
                cout << "| " << word << " |   is not a Palindrome.\n" << endl;
                break;
            }
            i++;
            j--;
            if( i >= j)
                cout << "| " << word << " |   is a Palindrome.\n" << endl;
        }
}

void IsPalindrome(char word[], int& i, int& j)
{
    check_lower(word, i);
    check_upper(word, j);
    if(tolower(word[i]) == tolower(word[j]))
    {
        if ( i >= j )
        {
                        cout << "| " << word << " |   is a Palindrome.\n" << endl;
            return;
        }
        i++;
        j--;
        IsPalindrome(word, i, j);
    }
    else
        cout << "| " << word << " |   is not a Palindrome.\n" << endl;
}

int main()
{
    char word[200];
    cout << "Enter a word or a statement : \n" << flush;
    cin.getline(word, 199);
    int i, j;
    do
    {
        i = 0;
        j = strlen(word);
        IsPalindromeIterative(word, i, j);
        IsPalindrome(word, i, j);
        cout << "\nIf you want to quit please write 'quit'\n" << flush;
        cin.getline(word, 199);
    }
    while (strcmp(word, "quit") != 0);
    return 0;
}

