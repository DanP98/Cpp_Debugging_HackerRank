#include <iostream>
using namespace std;

int main() {
    try {
        int age = 18;
        if (age < 18) {
            throw (age);
        } else{
            cout << "Access granted - you are old enough." << endl;
        }
    }
    catch (int myNum) {
        cout << "Access denied - You must be at least 18 years old" << endl;
        cout << "Age is: " << myNum << endl;  
    }

    return 0;
}

// https://www.w3schools.com/cpp/cpp_exceptions.asp
