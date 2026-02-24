//
//  iris.cpp
//  iris
//
//  Created by Andrew Goodney on 2/9/25.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>


using namespace std;

// let's make struct so i can use for three
struct Iris {
    vector<double> sepalLength;
    vector<double> sepalWidth;
    vector<double> petalLength;
    vector<double> petalWidth;
};

// find the minimum
double findMin (vector<double> values){
    double minValue = 0.0;
    
    // if there is not data, return value 0
    if(values.empty()){
        return minValue;
    }
    
    // let's say the first one is min for now and cheeck the others
    minValue = values[0];
    
    for (int i = 0 ; i < values.size(); i++){
        if(values[i] <= minValue){
            minValue = values[i];
        }
    }
    return minValue;
}

// find the maximum
double findMax (vector<double> values){
    double maxValue = 0.0;
    
    // if there is not data, return value 0
    if(values.empty()){
        return maxValue;
    }
    
    // let's say the first one is max for now and cheeck the others
    maxValue = values[0];
    
    for (int i = 0 ; i < values.size(); i++){
        if(values[i] >= maxValue){
            maxValue = values[i];
        }
    }
    return maxValue;
}

// find the mean
double findMean (vector<double> values){
    double meanValue = 0.0;
    
    // if there is not data, return value 0
    if(values.empty()){
        return meanValue;
    }
    
    // let's add everything and divide it later
    for (int i = 0 ; i < values.size(); i++){
        meanValue += values[i];
    }
    
    meanValue = double (meanValue/values.size());
    
    return meanValue;
}


// find the std
double findStd (vector<double> values){
    double stdValue = 0.0;
    
    // if there is not data, return value 0
    if(values.empty()){
        return stdValue;
    }
    
    // sqrt ((sum of x - mean) ^2)/number
    
    double meanValue = findMean(values);
    
    double sumOfXMean = 0.0;
    
    for (int i = 0; i < values.size(); i++){
        sumOfXMean += pow(values[i] - meanValue, 2);
    }
    
    stdValue = sqrt(sumOfXMean / values.size());
    
    return stdValue;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // reads in the Iris data
    // computes the min, max, mean & std. deviation
    // of the 4 values for each of the three species
    
    // column in order
    // sepal length, sepal width, petal length & petal width
    
    // rows
    // 3 - setosa, versicolor and virginica

    
    // make three structs
    Iris setosa, versicolor, virginica;
    double sl, sw, pl, pw;
    string species;
    char comma;
    
    // declare the string to read
    string readIris;
    
    ifstream inputFile("iris.txt");
    
    // chekc the error
    if(inputFile.fail()){
        cout << "Error. Cannot open the file." << endl;
        // end the program
        return 1;
    }
    
    // ex. 5.1,3.5,1.4,0.2,Iris-setosa
    while(inputFile >> sl >> comma >> sw >> comma >> pl >> comma >> pw >> comma >> species){
        // add it to values vector
        // 3 branch here
        if(species == "Iris-setosa"){
            setosa.sepalLength.push_back(sl);
            setosa.sepalWidth.push_back(sw);
            setosa.petalLength.push_back(pl);
            setosa.petalWidth.push_back(pw);
        }
        else if(species == "Iris-versicolor"){
            versicolor.sepalLength.push_back(sl);
            versicolor.sepalWidth.push_back(sw);
            versicolor.petalLength.push_back(pl);
            versicolor.petalWidth.push_back(pw);
        }
        else if(species == "Iris-virginica"){
            virginica.sepalLength.push_back(sl);
            virginica.sepalWidth.push_back(sw);
            virginica.petalLength.push_back(pl);
            virginica.petalWidth.push_back(pw);
        }
    
        
    }
    
    
    inputFile.close();
    
    // print out table here
    
    // float number
    cout << fixed << setprecision(2);
    
    cout << "                                                            Iris Data" << endl;
    cout <<"--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|      Species       | Sepal Length           | Sepal Width            | Petal Length           | Petal Width            |" << endl;
    cout <<"--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(18) << left << "Iris-setosa" << " | ";
    cout << findMin(setosa.sepalLength) << ", "
         << findMax(setosa.sepalLength) << ", "
         << findMean(setosa.sepalLength) << ", "
         << findStd(setosa.sepalLength) << " | "
         << findMin(setosa.sepalWidth) << ", "
         << findMax(setosa.sepalWidth) << ", "
         << findMean(setosa.sepalWidth) << ", "
         << findStd(setosa.sepalWidth) << " | "
         << findMin(setosa.petalLength) << ", "
         << findMax(setosa.petalLength) << ", "
         << findMean(setosa.petalLength) << ", "
         << findStd(setosa.petalLength) << " | "
         << findMin(setosa.petalWidth) << ", "
         << findMax(setosa.petalWidth) << ", "
         << findMean(setosa.petalWidth) << ", "
         << findStd(setosa.petalWidth) << " | "
         << endl;
    cout << "| " << setw(18) << left << "Iris-versicolor" << " | ";
    cout << findMin(versicolor.sepalLength) << ", "
         << findMax(versicolor.sepalLength) << ", "
         << findMean(versicolor.sepalLength) << ", "
         << findStd(versicolor.sepalLength) << " | "
         << findMin(versicolor.sepalWidth) << ", "
         << findMax(versicolor.sepalWidth) << ", "
         << findMean(versicolor.sepalWidth) << ", "
         << findStd(versicolor.sepalWidth) << " | "
         << findMin(versicolor.petalLength) << ", "
         << findMax(versicolor.petalLength) << ", "
         << findMean(versicolor.petalLength) << ", "
         << findStd(versicolor.petalLength) << " | "
         << findMin(versicolor.petalWidth) << ", "
         << findMax(versicolor.petalWidth) << ", "
         << findMean(versicolor.petalWidth) << ", "
         << findStd(versicolor.petalWidth) << " | "
         << endl;
    cout << "| " << setw(18) << left << "Iris-virginica" << " | ";
    cout << findMin(virginica.sepalLength) << ", "
         << findMax(virginica.sepalLength) << ", "
         << findMean(virginica.sepalLength) << ", "
         << findStd(virginica.sepalLength) << " | "
         << findMin(virginica.sepalWidth) << ", "
         << findMax(virginica.sepalWidth) << ", "
         << findMean(virginica.sepalWidth) << ", "
         << findStd(virginica.sepalWidth) << " | "
         << findMin(virginica.petalLength) << ", "
         << findMax(virginica.petalLength) << ", "
         << findMean(virginica.petalLength) << ", "
         << findStd(virginica.petalLength) << " | "
         << findMin(virginica.petalWidth) << ", "
         << findMax(virginica.petalWidth) << ", "
         << findMean(virginica.petalWidth) << ", "
         << findStd(virginica.petalWidth) << " | "
         << endl;
    
    cout <<"--------------------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}
