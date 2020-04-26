// Stream insertion
#include <iostream>
using namespace std;

class Date
{
    int mo, da, yr;
public:
    Date(): mo(0), da(0), yr(0){}
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream& operator >> (istream& is, Date& dt);
};
//stream insertion
ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}
//stream extraction
istream& operator >> (istream& is, Date& dt)
{
    is >> dt.mo >> dt.da >> dt.yr;
    return is;
}

int main()
{    
    Date dt(5, 6, 92);
    cout << "Default date is:" << dt;
    
    Date dt1;
    cout << "\nEnter the new date" << endl;
    cin >> dt1;
    
    cout << "\nYou entered the date:" << dt1 << endl;
}
