#include <iostream>
#include <sstream>
#include<string>
using namespace std;

class Student
{
private:
    int age;
    int standard;
    string name;
    string surname;
public:
    int get_age()
    {
        return age;
    }
    string get_first_name()
    {
        return name;
    }
    string get_last_name()
    {
        return surname;
    }
    int get_standard()
    {
        return standard;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_first_name(string name)
    {
        this->name = name;
    }
    void set_last_name(string surname)
    {
        this->surname = surname;
    }
    void set_standard(int standard)
    {
        this->standard = standard;
    }
    string to_String()
    {

        return to_string(get_age()) + "," + get_first_name() + "," + get_last_name() + "," + to_string(get_standard());
    }
};
int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_String();

    return 0;
}