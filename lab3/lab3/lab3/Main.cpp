/*
Ian Sitienei
C++ Fall 2020
Due September 28 2020 11:59pm
Lab 3 
This lab is to compute  an output and mean population using c++
*/


#include <iostream>
#include <fstream> // file input and output
#include <string> //string input
#include <iomanip> //used for  fixed resrved word
#include <cmath> // used for power function

using namespace std;

float meanFunction(int, int, int, int); // prototype for mean function
float stdFunction(int, int, int, int, float); //prototype for standard deviation

int main()
{
	int value1;
	int value2;
	int value3;
	int value4;

	ifstream inputFilename; // input identififiers 
	ofstream outputFilename;

	inputFilename.open("inMeanStd.dat.txt");  // open the files
	outputFilename.open("outMeanStd.dat.txt");

	inputFilename >> value1 >> value2 >> value3 >> value4;  //Reads integers from inMeanstd.dat.txt into num input variables

	outputFilename << "The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << fixed << setprecision(6) << endl;
	// the  calcualtion
	outputFilename << "The mean of the integers user entered: " << meanFunction(value1, value2, value3, value4) << endl;
	outputFilename << "The population standard deviation : " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4));

	inputFilename.close();
	outputFilename.close();

	// prompt for user
	cout << "Enter four integers. Kindly make sure to then hit enter between your integers" << endl;
	cin >> value1 >> value2 >> value3 >> value4;

	cout << "The program calculated the following values:" << endl;
	cout << " The mean of the four integers is: " << meanFunction(value1, value2, value3, value4) << fixed << setprecision(4) << endl;
	cout << " The population standard deviation of the four integers: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << fixed << setprecision(6) << endl;

	return 0;

}

float meanFunction(int value1, int value2, int value3, int value4) //function defianation  for mean
{
	return (float(value1 + value2 + value3 + value4) / float(4));
}

float stdFunction(int value1, int value2, int value3, int value4, float average) // function defination for standard deviation
{
	return sqrt((float(pow((value1 - average), 2) + pow((value2 - average), 2) + pow((value3 - average), 2) + pow((value4 - average), 2)) / 4));
}