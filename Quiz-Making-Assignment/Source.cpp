#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
*Main Function that will be running al the methods for the quiz
*/

	
int main(){
	
}

/* 1st Function - Go through txt file and writes all lines into a 2D vector
	- use function for both QuizTakers.txt QuizQuestion.txt
	- From that step only work with that array 
	- QuizQuestion vector = [[q1, a1, B1, c1, d1], [q2,2,b2,c2,D2], ...]

	StartQuiz 
	- sends first nested vector to a method called Find answer
	- stores the answer in a varible
	- Goes through array and starts to post the question and possible answers in all lower case 
	- give them the option to pick answer 1,2,3, or 4 
	- if they pick correct then add 1 tothe score if not then continue for loop
	- at the end of loop return final score


	Find Answer
	- go through the vector 
	- send back the number of the correct answer.

	Average Finder
	- have a function that  goes through the array and finds the average

	Feedback function
	- have a function that is called feedback that will post to the screen based on how 
	you did vs. the average 
			-> Higher than average & higher than 80 = You did very well and higher then average
			-> higher than 80 = you did very well but not better then average
			-> higher than 50 = you passed but did not get higher then average
			-> higher then average and higher than 50 = you passed and are higher then the average 
			but you can do better 
			-> lower than 50 = you failed please try again 
			-> lower than 50 and higher than avg = you failed, however this test wasnt easy because 
			you did better than the avg.
	- call this function after the start quiz, have in the parameter test score and avg score 
	give feedback on how the person did

	2nd function 
	- sort the 2D vector

	3rd function 
	- when we write back to the file we can clear the file and write the new 2D array to it
		

*/


string search(string firstName, string lastName) {
	vector<string> testTakers;
	/*
	*/
}

/*
This function will write what ever was put in the parameter to a file
*/
bool writing(string firstName,string lastName,int grade) {
	if (grade > 100)
	{
		cout << "Grade is to high";
		return false;
	}
	else if (grade < 0)
	{
		cout << "Grade is too low";
		return false;
	}
	else {
	string wordsToWrite = "";
	ofstream outputFile;
	outputFile.open("quiztakers.txt");
	cout << "Writing to the file" << endl;
	wordsToWrite = lastName +","+ firstName + ",";
	/* before we write to the file we need to know where to write because it needs to be sorted in the
	text file */
	outputFile << wordsToWrite;
	outputFile << grade << endl;
	outputFile.close();
	return true;
	}
}