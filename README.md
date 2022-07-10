Write a program to calculate a bowling league's average bowling scores. 
You will need to read the input data from the file BowlingScores.txt)
Note: The file format is guaranteed to remain the same.
    
    • Your program must use one structure that contains the following member variables:
      • a string data type that will hold the name of the bowler.
      • a one-dimensional array of integers to store the bowler's 4 scores.
      • an integer to hold the average bowling score.
  
    • Your program must contain at least the following functions:
      • a Boolean returning function called GetBowlingData to read and store data into an array of structures. 
        The function should take as input parameters the file name and an empty array of structures,
        which it should fill from the file (BowlingScores.txt  download) 
        and return a status of either success or failure (i.e., true or false). 
      • a void function called GetAverageScore that is used to calculate the average bowling score. 
        The function should take as input the array of structures which it should fill with the average score of each bowler.
      • a void function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.
      
    • Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.
    • Use repetition structures (loops) in your functions to perform calculations and printing. 
      Remember "dimensions = loops". 
      So, a 2-dimensional array will require 2 loops to completely iterate over all of the elements 
      in the array.
    • Don't use magic numbers. Instead use global constants at the top of the program under the includes.

--------------------------------------------------------------------------------------------------------------------------------------

Added new bowler, "IssaHabeeb," and added fifth score to each bowler.
