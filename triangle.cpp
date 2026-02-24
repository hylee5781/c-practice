//
//  triangle.cpp
//  triangle
//
//  Created by Andrew Goodney on 2/9/25.
//
//  Hannah Lee

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // infinite loop till "quit"
    // read line with getline
    // get input to line
    // check error
    
    // let's define readLine first
    // should be empty string for now
    string readLine;
    
    while(true){
        // let's get user input
        cout << "Enter 3 dots (x1, y1, x2, y2, x3, y3) of a triangle. Enter 'quit' to stop the program: " << endl;
        // if it is empty, break it
        if(!getline(cin, readLine)){
            break;
        }
        // if it is quit, break it
        if(readLine == "quit"){
            cout << "The program is over. Thank you." << endl;
            break;
        }
        
        // let's save the dots
        // declare first
        stringstream ss(readLine);
        double x1, y1, x2, y2, x3, y3;
        
        ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        // error check first
        if(ss.fail()){
            cout << "Error. Enter valid float numbers." << endl;
            // re-get input
            continue;
        }
        
        // calculate the area
        double triangleArea = 0.0;
        triangleArea = 0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
        triangleArea = abs(triangleArea);
        
        cout << "The area of a triangle is " << triangleArea << ". " << endl;
        
    }
    return 0;
}
