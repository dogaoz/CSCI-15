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

//checks if both the letters are same or not
bool is_Equal(char word[], int i, int j)
{
    return (tolower(word[i]) == tolower(word[j]));
}

//checks if the character is letter or not and converts it into lower case
void check_lower(char word[], int &i)
{
    if (!isalpha(word[i]))
    {
        check_lower(word, ++i);
    }
}

//checks if the character is letter or not and converts it into lower case
void check_upper(char word[], int &j)
{
    if (!isalpha(word[j]))
    {
        check_lower(word, --j);
    }
}
//recursion version to check if word is palindrome or not
void IsPalindrome(char word[], int& i, int& j)
{
    check_lower(word, i);
    check_upper(word, j);
    if ( i >= j )
    {
        cout << "| " << word << " |   is a Palindrome.\n" << endl;
        return;
    }
    if(tolower(word[i]) == tolower(word[j]))
    {
        i++;
        j--;
        IsPalindrome(word, i, j);
    }
    else
        cout << "| " << word << " |   is not a Palindrome.\n" << endl;
}
//iterative version to check if word is palindrome or not
void IsPalindromeIterative(char word[], int i, int j)
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

int main()
{
    char word[200]; //stores the word
    cout << "Enter a word or a statement : \n" << flush;
    cin.getline(word, 199); //stores the input as a c string in "word[]"
    int i, j; //to store the upper and lower index
    do
    {
        i = 0;
        j = strlen(word);
        IsPalindromeIterative(word, i, j);  //iterative version
        IsPalindrome(word, i, j);           //recursive version
        cout << "\nIf you want to quit please write 'quit'\n" << flush;
        cin.getline(word, 199); //gets another word

    }while (strcmp(word, "quit") != 0); //continue till it gets the word "quit"
    return 0;
}

