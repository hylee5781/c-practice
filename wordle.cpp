//
//  wordle.cpp
//  wordle
//
//  Created by Andrew Goodney on 2/9/25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

// 5 letter word in just 6 guesses
// 1) which letters are in the right place or 2) which letters appear in the word but are in the wrong place.
//1 "quit" to quit the program
//2 "new" to start a new round. Pick a new word and start over.
//3 or a 5 letter word as a guess
//4 Unable to parse input, please try again.


random_device rd;
default_random_engine rndengine(rd());

bool contains(vector<string>& words, string needle)
{
    
    //implement iterative binary search for needle on the sorted vector of words
    int start = 0;
    int end = (words.size() - 1);
    
    while(start <= end){
        int middle = (start+end)/2;
        
        if(words[middle] == needle){
            return true;
        }
        if(words[middle] < needle){
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // read the txt
    // for debug
    // ifstream wordList("miniwordlist");
    ifstream wordList("wordlist.txt");
    if(wordList.fail()){
        cout << "Unable to parse input, please try again." << endl;
        // continue from strat
        return 1;
    }
    
    // declare the vectore to save
    vector<string> words;
    string wordsInV;
    while(wordList >> wordsInV){
        words.push_back(wordsInV);
    }
    // close the file
    wordList.close();
    
    // let's pick a raondom word
    // prof gave the hint for random
    // dont need to make just declare
    uniform_int_distribution<int> randomNum(0, words.size() - 1);
    
    int targetIndex = randomNum(rndengine);
    string target = words[targetIndex];
    
    // empty the variables first
    string userInput;
    int howMany = 0;
    
    cout << "Welcome to Wordle!" << endl;
    cout << "*****" << endl;
    cout << "*****" << endl;
    cout << "*****" << endl;
    cout << "*****" << endl;
    cout << "*****" << endl;
    cout << "*****" << endl;
    cout << "Enter your guess: \n" << endl;

    
    while(howMany < 6){
        cout << "Enter 5 letter word; or type 'quit'; or 'new'" << endl;
        cin >> userInput;
        
        // quit
        if (userInput == "quit"){
            break;
        }
        
        // new
        if (userInput == "new"){
            // reset everything
            targetIndex = randomNum(rndengine);
            target = words[targetIndex];
            howMany = 0;
            cout << "Game is reset! Word is changed." << endl;
            continue;
        }
        
        // check the validity of a word
        if(userInput.length() != 5 || !contains(words, userInput)){
            cout << "Invalid word, please try again." << endl;
            continue;
        }
        
        // get it right by one chance
        if(userInput == target){
            cout << "You are correct! The answer is " << target << "." << endl;
            break;
        }
        
        // need to give a hint
        for(int i = 0; i < 5; i++){
            if(userInput[i] == target[i]){
                cout << userInput[i] << " is Green." << endl;
            }
            else{
                bool haveLetter = false;
            
                for (int k = 0; k < 5; k++){
                    if(userInput[i] == target [k]){
                        haveLetter = true;
                        break;
                    }
                }
                if(haveLetter){
                    cout << userInput[i] << " is Yellow." << endl;
                }
                else{
                    cout << userInput[i] << " is Grey." << endl;
                }
            }
        }
        howMany += 1;
        
        cout << endl;
        
    }
    
    // show real answer
    if(howMany >= 6 && userInput != target){
        cout << "\nThe correct answer is " << target << "." << endl;
    }
    
    return 0;
}
