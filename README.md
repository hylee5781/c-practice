## CSCI 114 Assignment #1
For this assignment you will develop three programs that will help give you practice with simple I/O in C++.

### Program 1: Triangle Area Calculation
There is a formula from coordinate geometry that allows for the calculation of the area of a triangle given the coordinates of the three corners:

`|(1/2)*(x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|`

where `(x1, y1)` `(x2, y2)` and `(x3, y3)` are the coordinates of the three corners. We need the magnitude bars because the formula may return a negative area depending on the order of the points, but of course all areas are positive.

#### Your task

Finish the `triangle.cpp` program that prompts users to enter the points of a triangle and then print out the answer. The prompt should describe how the user should input the points and how to quit the program.

The points are floating-point, so use type `double` to store the values. Use `cin` to read in the values. The points will be entered as 6 values on one line separated by whitespace:

```
11.1 1.0 49.3 15.1 66.2 -8.0
```

If the input is the single word `quit` on one line, the program should quit, displaying a nice "quit message". Hint: read in one line using `getline()` and use that line to either detect the word "quit" or parse the six values.

Assuming all six values are read correctly (see below), print out a message with the area of the triangle and prompt the user to enter another set of six points. The program should loop until the the word `quit` is entered as described above.

You may use any data structures you deem necessary to solve this problem.

#### Error checking

Use the `.fail()` method to verify that all 6 values entered were type `double`. If there are any issues parsing a value, the program should detect this, print out an informative message, ignore any values input and give the user the option to re-enter the values.

### Program 2: Reading and Processing Data
The Iris Dataset is an early data set (1936) that dispite it's age is very useful for testing machine learning algorithms. For this part of the assignment you will read in and do some simple processing of the data.

#### The Iris Data
The Iris data contains measurements of the length and width of the sepal and petal of various specimins along with an identifier for which of three species the flower belonged. A file called `iris.txt` is included in your starter code, the lines look like:

```
5.1,3.5,1.4,0.2,Iris-setosa
7.0,3.2,4.7,1.4,Iris-versicolor
7.6,3.0,6.6,2.1,Iris-virginica
```
There are 150 records (lines) total. The dataset is often used to see if a classifier can be build that can accurately predict the species of a specimin based on the length and width values.

#### Your Task
Your task is to write a program called `iris.cpp` that reads in the Iris data and computes the min, max, mean and std. deviation of the 4 values for each of the three species.

Your program should then present this data in a table with the columns in order: sepal length, sepal width, petal length, and petal width. The three rows should be setosa, versicolor and virginica. In each cell print out the min, max, mean, std. dev.

#### Formatting the table
You have some flexibility to make the formatting of the table nice, but you should include a header, column names, and row names. There should be seperators like `|` or `*` between the columns and rows. You should print the values with two decimal places only and the values should be centered in the cells. You probably want to review the `setw` and `setprecision` iomanipulators that you get when you `#include <iomanip>`. These will help you format your table without hardcoding values or spacing, though you may need to hardcode the total width. Other data structures like `stringstreams` might be helpful too.

An example table (with the correct answers, view in wide-format to see the proper formatting):

```
                                                   Iris Data
----------------------------------------------------------------------------------------------------------------------
|      Species       | Sepal Length          | Sepal Width           | Petal Length          | Petal Width           |
----------------------------------------------------------------------------------------------------------------------
| Iris-setosa        |4.30, 5.80, 5.01, 0.35 |2.30, 4.40, 3.42, 0.38 |1.00, 1.90, 1.46, 0.17 |0.10, 0.60, 0.24, 0.11 |
----------------------------------------------------------------------------------------------------------------------
| Iris-versicolor    |4.90, 7.00, 5.94, 0.51 |2.00, 3.40, 2.77, 0.31 |3.00, 5.10, 4.26, 0.47 |1.00, 1.80, 1.33, 0.20 |
----------------------------------------------------------------------------------------------------------------------
| Iris-virginica     |4.90, 7.90, 6.59, 0.63 |2.20, 3.80, 2.97, 0.32 |4.50, 6.90, 5.55, 0.55 |1.40, 2.50, 2.03, 0.27 |
----------------------------------------------------------------------------------------------------------------------
```
### Program 3: Wordle

For the final program you will implement a text version of the word game Wordle. Wordle is a word-guessing game where the player is trying to guess a 5 letter word in just 6 guesses. After each guess the game will show which letters are in the right place or which letters appear in the word but are in the wrong place.

#### Your Task

We have provided a list of 5 letter words to use for your game. When you program starts you should read this list of words into a `vector` of strings. The user will be able to play multiple times, so we'll need this list to pick the words.

Use a random number to pick one of the 5 letter words (for debugging at first you can just pick the first word). After  your program should automatically start a round by printing 6 lines of the '*' character 5 times and then prompting for the users guess:

```
Welcome to Wordle!
*****
*****
*****
*****
*****
*****
Enter your guess:
```

At the prompt users can enter one of the following:

* "quit" to quit the program
* "new" to start a new round. Pick a new word and start over.
* or a 5 letter word as a guess

If the user enters anything other than the options above, ignore the input after printing a message (e.g "Unable to parse input, please try again.")

If the user enters a 5 letter "word", but it is not in the word list then print out a message (e.g. "Invalid word, please try again"). Finish the `contains()`function by implementing binary search on the sorted `vector` of words.

##### Handling Guesses

To handle a guess you need to determine which letters in the guess are in the target word and if they are in the correct location as you print out the guess. One suggestion is to model the "board" as 6 strings that you modify after each guess. Each guess then only requires you to modify one string. Think about how to use string concatenation or a `stringstream` to do this. After each guess print all six strings, including the '*' placeholder strings for their upcoming guesses.

When building the string to print for a guess, letters that are in the correct location should be printed in green, letters that appear in the word but are in the incorrect place should be printed in yellow, otherwise the letter should be normal. You don't need to worry about repeated letters, just follow the instructions above. See the `color.cpp` example program for help with printing green and yellow.

If the user gets the word correct, print the entire word in green and give the user the option for a new game or quit.

If the user guesses 6 times without getting the word correct, print the correct word after printing their last guess and then give the user the option for a new game or to quit.

##### Random Numbers

Working with random numbers can be tricky, so we've given you the code to generate an index you can use to randomly choose a word.

#### Testing/Debugging

When testing/debugging feel free to hardcode the word. This will make it eaiser to figure out if your code is correct. Also, we've included a second file with only 10 words that will also make it eaiser to test/debug your code. Another idea is that once you switch to the big word list you print out the target word once before the game begins so you know what the answer is.
