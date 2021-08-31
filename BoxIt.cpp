#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box
{
private:
    int l, b, h;
public:
    Box()//!default constructor
    {
        l = b = h = 0;
    }
    Box(int l, int b, int h)//!constructor with parameters
    {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    Box(const Box& B)//!copy constructor
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }
    long long CalculateVolume()
    {
        long long v = 1;
        v *= l; v *= b; v *= h;
        return v;
    }
    bool operator <(const Box B)//!operator overloading operation
    {
        if (this->l < B.l)
        {
            return true;
        }
        else if ((this->b < B.b) && (this->l == B.l))
        {
            return true;
        }
        else if ((this->h < B.h) && (this->l == B.l) && (this->b == B.b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream& operator<<(ostream& out, Box& B)//!operator overloading operation
    {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};
void check2()//control part
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}
int main()
{
    check2();
}

