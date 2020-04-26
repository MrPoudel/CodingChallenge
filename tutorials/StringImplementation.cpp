// Taken from stackoverflow: https://stackoverflow.com/questions/31713654/c-implementation-of-string-class

#include <iostream>
#include <cstring>

// using namespace std; DANGER! namespace std is huge. Including all of it can
// have tragic, unforeseen consequences. Just use what you need.
using std::cout;
using std::endl;


class MyString
{
private:
    char * content;
    int length;
// will use clone to reduce duplication in the copy constructor and operator =
    void copy(const MyString & source);
public:
    MyString();
// it is nice to name the variables in the definition. The header may be the
// only documentation the user gets.
    MyString(const char * source);
    ~MyString();
    MyString(const MyString &source);
    void print(void);
// changed prototype to match the expected format operator= format
    MyString & operator =(const MyString &source);
//OP asked about this in a previous question.
    friend std::ostream & operator<<(std::ostream & out,
                                     const MyString& towrite);
};

MyString::MyString()
{
//    content = 0;
//destructor needs something to delete[]. If content isn't set to something,
//you'll get a big ka-BOOM! when the MyString is destroyed

    content = new char[1];
    content[0] = '\0'; //this has the advantage of printing an empty MyString
                       // without crashing
    length = 0;
}


MyString::MyString(const char *source) // Variable names should describe their purpose
{
    //DANGER: strlen will fail horribly if passed an unterminated string. At a
    // loss at the moment for a good, safe solution. Look into strnlen, but
    // even it can't help you here.
    length = strlen(source);
    content = new char[length + 1]; //Needed one extra character to fit the NULL
/* If we got this far without dying, strcpy is no threat which makes this redundant:
    for (int i = 0; i < length; i++)
    {
        content[i] = n[i];
    }
    content[length] = '\0';
*/
    strcpy(content, source);
}

MyString::~MyString()
{
    delete[] content;
//    content = 0; string is gone. No need to clear this
}

void MyString::copy(const MyString & source)
{
    length = source.length;
    content = new char[length + 1];
// assuming that the source MyString is correctly formatted this is once again safe.
    strcpy(content, source.content);
}

MyString::MyString(const MyString & source)
{
    copy(source); // use the copy method
}

void MyString::print(void)
{
    cout << "" << content << endl;
}

MyString &MyString::operator =(const MyString &source)
{
    copy(source); // use the copy method again.
    return *this; // allows chaining operations
}

std::ostream & operator<<(std::ostream & out,
                          const MyString& towrite)
{
    out << towrite.content;
    return out;
}

int main()
{
    MyString word0;
    MyString word1("stackoverflow");
    MyString word2;
    word2 = word1;
    MyString word3(word2); //testing copy constructor
    word1.print();
    word2.print();
    cout << word3 << endl; //testing outstream overload
    // test output of empty string
    word0.print();
    cout << word0 << endl;
}
