//
//  lab4.cpp
//  lab4
//
//  Created by Andrew Goodney on 2/9/25.
//

#include <iostream>
#include <vector>

using namespace std;

// Pass by reference
void mac(double* a, double* b, double* c)
{
  //implement multiply and accumulate operation
    // a = a + (b * c)
    // taking the input parameters by reference so you'll need to use proper de-referencing syntax to implement the operation.
    *a = *a + (*b * *c);
    
}

// Pass by reference and Python
void listinc(vector<int>* v)
{
    for(size_t i = 0; i < (*v).size(); i++)
    {
        (*v)[i]++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Exploring Pointers
    
    // Give x and z an initial value.
    int x = 100;
    double z = 5.5;
    
    // Declare a variable of type int* (p) & a variable of type double* (q).
    int* p;
    double* q;
    
    // Write the code to print out the value of x and z.
    cout << "The value of x is " << x << "." << endl;
    cout << "The value of z is " << z << "." << endl;

    // add this
    p = &x;
    q = &z;
    
    // write the code to dereference p and q
    cout << "Dereferencing p: " << *p << ", dereferencing q: " << *q << "." << endl;
    
    // add this
    *p = 99;
    *q = 3.1415;
    
    cout << "\nThis is after changing." << endl;
    
    cout << "The value of x is " << x << "." << endl; //99
    cout << "The value of z is " << z << "." << endl; //3.1415
    cout << "Dereferencing p: " << *p << ", dereferencing q: " << *q << "." << endl;

    // Pass by reference
    cout << "\nThis is for 'Pass by reference'.\n" << endl;
    
    double hereA = 10.0;
    double hereB = 25.5;
    double hereC = 30.2;
    
    cout << "Before, value of A is " << hereA << "." << endl;

    mac(&hereA, &hereB, &hereC);
    
    cout << "\nAfter, value of A is " << hereA << "." << endl;
    
    // Pass by reference and Python
    cout << "\nThis is for 'Pass by reference and Python'.\n" << endl;
    
    vector<int> vec({1, 2, 3, 4});
    listinc(&vec);
    for(size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    return 0;
}
