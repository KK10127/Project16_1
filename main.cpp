/*
 * CHAPTER 16, PROJECT 1
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 * PROBLEM STATEMENT:
 *     Write a class BCheckString that is derived from the STL string class. This new class
 *     will have two member functions:
 *          A) A BCheckString(string s) constructor that recieves a string object passed by value
 *          and passes it on to the base class constructor.
 *          B) An char operator[](int k) function that throws a BoundsException object if k is
 *          negative or is greater than or equal to the length of the string. If k is within the
 *          bounds of the string, this function will return the character at the position k in the
 *          strubg.
 *
 *      You will need to write the definition of the BoundsException class. Test your class with a
 *      main function that attempts to access characters that are within and outside the bounds of a
 *      suitable initialized BCheckString object.
 *
 *
 *
 */
#include <iostream>
#include<string>
using namespace std;

class BCheckString : public string
{
public:
    class BoundsException {
    public:
        BoundsException() {
            cout << "BOUNDS EXCEPTION THROWN" << endl;
        }
    };

    BCheckString(string s);
    ~BCheckString();

    // throws a boundsexception object if k is not an existing
    // index within the string.
    // this will also return the character at position k in the string
    char operator[](int k);

private:
};

BCheckString::BCheckString(string s):string(s)
{
}

BCheckString::~BCheckString()
{
}

// throws a boundsexception object if k is not an existing
// index within the string.
// this will also return the character at position k in the string
char BCheckString::operator[](int k) {

    string str = *this;

    if (k >= 0 && k < str.length()) {
        return str[k];
    } else {
        throw BoundsException();
    }

}

int main() {
    // create an object
    BCheckString bcs("A string!");

    int pos = 0;

    do {

        cout << "Enter an index to check: ";
        cin >> pos;

        try {
            cout << bcs.operator[](pos) << endl;
        } catch (BCheckString::BoundsException be) {
            cout << "A Bounds exception was thrown!" << endl;
        }

    } while (pos != -1);



    return 0;
}