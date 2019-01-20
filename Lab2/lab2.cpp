//
// lab2.cpp
// Doga Ozkaracaabatlioglu, Kirill Vladimirov
// September 13, 2018
// Lab 2
// Testing pointers in different ways
//

#include <iostream>
using namespace std;

const int MAX = 100;
int main()
{

    char str[MAX] = "This is a simple C-string";
    char *pstr = "This is a declaration of a pointer to a C-string";
    char *qstr = pstr;
    char *rstr = str;

    cout << str[MAX] <<endl;
    cout << pstr<<endl;
    cout << "###qstr###"<<endl;
    cout << qstr<<endl;
    cout << "###rstr###"<<endl;
    cout << rstr<<endl;

    cout << "Can we change:" << flush;
    cout << "\n###(Q): str[10] to a new value?" << endl;
    cout << "###Modifying str[10] ###" << endl;
    str[10] = '#'; // This works
    cout << "###Printing str###" << endl;
    cout << str << endl;
    cout << "\n###(Q): pstr[10] to a new value?" << endl;
    //*pstr[10] = 'A';
    cout << "(A): error: assigning to 'char' from incompatible type 'const char"
         << "[2]'" << endl;
    cout << "(A): No - because it's constant variable and cannot be modified."
         << endl;

    cout << "\n###(Q) pstr to a different string?" << endl;
    //*pstr = "New String!!";
    cout << "(A): error: assigning to 'char' from incompatible type 'const char"
         << "[13]'" << endl;
    cout << "(A): No - because it's constant variable and cannot be modified."
         << endl;
    cout << "###Printing pstr###" << endl;
    cout << pstr << endl;
    cout << "\n###(Q) str to a different string?" << endl;
    cout << "(A): Yes - but modifying character one by one." << endl;
    cout << "###Before###\n" << flush;
    cout << str << endl;

    int i = 0;
    while (i < MAX - 1)
    {
        str[i] = 'A';
        i++;
    }

    cout << "###After###\n" << flush;
    cout << str << endl;
    cout << "\n###(Q): If we change pstr to point to a different string. "
         << "What happens to qstr?" << endl;
    cout <<"###Modifying pstr###" << endl;
    pstr = "Hello";
    cout << "###Printing changed pstr###" << endl;
    cout << pstr << endl;
    cout << "###Printing qstr###" << endl;
    cout << qstr << endl;
    cout << "(A): qstr will point to the old string" << endl;
    cout <<"\n###(Q):Can we assign str = \"Goodbye\" " << endl;
    //str = "Goodbye";
    cout << "(A): We cannot assign string to a pointer\n" << endl;
    cout <<"\n###(Q):If we change rstr[5] to '5', what happens to str?" << endl;
    cout <<"###Changing rstr[5]###" << endl;
    rstr[5]='5';
    cout << "###Printing changed str###" << endl;
    cout << str << endl;
    cout << "\n###(Q):If we change str[10] to '8', what happens to rstr?"
         << endl;
    cout << "###Changing str[10]###" << endl;
    str[10]='8';
    cout << "###Printing changed rstr###" << endl;
    cout << rstr <<endl;
    cout << "\n###(Q):What happens if you print: pstr" << endl;
    cout << "###Printing pstr###" << endl;
    cout << pstr << endl;
    cout << "(A): Prints the char values in the array" << endl;
    cout << "\n###(Q):What happens if you print: *pstr" << endl;
    cout << "###Printing *pstr###" << endl;
    cout << *pstr << endl;
    cout << "(A): Prints the first character in the array\n"
         << "because pointer points to the base of array." << endl;
    cout << "\n###(Q):What happens if you print: (void *)pstr" << endl;
    cout << "###Printing (void *)pstr###" << endl;
    cout << (void *)pstr << endl;
    cout << "(A): Prints the address" << endl;
    cout << "Address of all the variables" << endl;
    cout << "str:  " << (void *)str << endl;
    cout << "pstr: " << (void *)pstr << endl;
    cout << "qstr: " << (void *)qstr << endl;
    cout << "rstr: " << (void *)rstr << endl;

    cout << endl << endl << endl;

    return 0;
}
