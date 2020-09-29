// Kamrin Chizek
// C++ Fall 2020
// Lab 3


#include <fstream> //including all the libraries necessary for this lab
#include <string>
#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std; //using namespace for lack of repeated use

float dig1, dig2, dig3, dig4; //creating the values for the data pieces inside the file
float avg = 5.25; //avg of integers in the file
float Meanfile(); //prototypes for my functions
float Stdfile(); 
float userStd();
float userMean();

float usernum1, usernum2, usernum3, usernum4; //created identifiers for the user inputted values

string inputFile = "C:/Users/kchiz/source/repos/New_Lab3/inMeanStd.dat"; //creating the file location as a string
string outputFile = "outMeanStd.dat";

int main()
{

	ifstream inFile;
	ofstream outFile;

	inFile.open(inputFile); //opening the input and output files
	outFile.open(outputFile);

	inFile >> dig1 >> dig2 >> dig3 >> dig4; //Program grabs the integers that are in the file and gives them identifiers

	//creating a statement to be outputted to the console and the output file that tells the user the inputted values from the input file
	cout << "The four integers in the file are: " << dig1 << ", " << dig2 << ", " << dig3 << ", and " << dig4 << endl;
	outFile << "The four integers in the file are: " << dig1 << ", " << dig2 << ", " << dig3 << ", and " << dig4 << endl;
	
	cout << "The mean of the 4 filed integers is: "; //gives you a statement on the mean of the four filed integers to the console and output file
	outFile << "The mean of the 4 filed integers is: "; 
	
	Meanfile(); //Running the Mean function for the integers in the input file that outputs the mean value to the console
	
	outFile << (dig1 + dig2 + dig3 + dig4) / (4); //outputting the mean value to the output file

	cout << endl;
	outFile << endl;

	cout << "The standard deviation of the 4 filed integers is: "; //giving you the statement of the standard deviation of the four filed integers outputted to the console and the output file
	outFile << "The standard deviation of the 4 filed integers is: ";

	Stdfile(); //Running the Std function that calculates and outputs the value to the console

	//outputting the std value to the output file
	outFile << setprecision(4) << sqrt((((dig1 - avg) * (dig1 - avg)) + ((dig2 - avg) * (dig2 - avg)) + ((dig3 - avg) * (dig3 - avg)) + ((dig4 - avg) * (dig4 - avg))) / (4));
	
	cout << endl<<endl;
	outFile << endl << endl;

	//Statement to the console asking the user for inputs
	cout << "Please type four integers, with 3 or less digits, with a space between each one." << endl;
	
	cin >> usernum1 >> usernum2 >> usernum3 >> usernum4; //grabs the integers given by the user and gives them identifiers

	//statement giving you again the values that you chose, outputted to the console and the output file
	cout << endl << "You chose the integers: " << usernum1 << ", " << usernum2 << ", " << usernum3 << ", and " << usernum4 << endl << endl;
	outFile << endl << "You chose the integers: " << usernum1 << ", " << usernum2 << ", " << usernum3 << ", and " << usernum4 << endl << endl;
	
	//statements giving you the mean of the chosen integers to the console and the output file
	cout << "The mean of the integers you chose is: ";
	outFile << "The mean of the integers you chose is: ";

	userMean(); //running the user inputted value mean function that calculates and outputs the value to the console

	outFile << (usernum1 + usernum2 + usernum3 + usernum4) / (4); //outputting the mean value to the output file
	
	//statements giving you the standard deviation to both the console and output file
	cout << endl << "The standard deviation of the integers you chose is: ";
	outFile << endl << "The standard deviation of the integers you chose is: ";

	userStd(); //running the user inputted value standard deviation function that calculates and outputs the values to the console
	
	cout << endl;
	outFile << endl;
   

	inFile.close(); //closing the input and output files
	outFile.close();
	return 0;

}

float Meanfile() //Mean function that calculates and outputs the value to the console from the input file
{
	cout << (dig1 + dig2 + dig3 + dig4) / (4);

	return 0;
}

float Stdfile() //standard deviation function that calculates and outputs the value to the console from the input file
{
	cout << setprecision(4) << sqrt((((dig1 - avg) * (dig1 - avg)) + ((dig2 - avg) * (dig2 - avg)) + ((dig3 - avg) * (dig3 - avg)) + ((dig4 - avg) * (dig4 - avg))) / (4));

	return 0;
}

float userMean() //Mean function for the user inputted data pieces that calculates and outputs the value to the console
{
	cout<<(usernum1 + usernum2 + usernum3 + usernum4) / (4);

	return 0;
}

float userMean(float usernum1,float usernum2,float usernum3,float usernum4) //function creating an identifier for the user inputted mean function to use in the Std calculation
{
	float Meanoutcome = (usernum1 + usernum2 + usernum3 + usernum4) / (4);

	return Meanoutcome;
}

float userStd() //Std function for the user inputted data pieces that calculates and outputs the value to the console and the output file
{
	ofstream outFile;
	
	float Meanoutcome = userMean(usernum1, usernum2, usernum3, usernum4);

	//Standard deviation equation for output to the console and output file
	outFile << setprecision(4) << sqrt((((usernum1 - Meanoutcome) * (usernum1 - Meanoutcome)) + ((usernum2 - Meanoutcome) * (usernum2 - Meanoutcome)) + ((usernum3 - Meanoutcome) * (usernum3 - Meanoutcome)) + ((usernum4 - Meanoutcome) * (usernum4 - Meanoutcome))) / (4));
	cout << setprecision(4) << sqrt((((usernum1 - Meanoutcome) * (usernum1 - Meanoutcome)) + ((usernum2 - Meanoutcome) * (usernum2 - Meanoutcome)) + ((usernum3 - Meanoutcome) * (usernum3 - Meanoutcome)) + ((usernum4 - Meanoutcome) * (usernum4 - Meanoutcome))) / (4));

	return 0;
}