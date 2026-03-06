//ECE205HW3_Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream> 
using namespace std;

//Gets pounds and ounces from the user
void getInput(int& pounds, int& ounces) //function that takes the users entry of pounds and ounces
{
    cout << "Enter pounds: " << endl; //Ask user for pounds
    cin >> pounds; 
    cout << "Enter ounces: " << endl; //Ask user for ounces
    cin >> ounces;
}

//Converts pounds to kilograms and ounces to grams
void convert(int pounds, int ounces, int& kilograms, int& grams) //function that takes pounds and ounces, and converts them to kilograms and grams
{
    double totalOunces = pounds * 16 + ounces; //Convert everything to ounces 
    double totalPounds = totalOunces / 16.0; //Convert total ounces back to pounds
    double totalKilograms = totalPounds / 2.2046; //Convert pounds to kilograms 
    double totalGrams = totalKilograms * 1000; //Convert all of it to grams
    kilograms = (int)(totalGrams / 1000); //Divide by 1000 to get whole kilograms
    grams = (int)(totalGrams) % 1000; //Use remainder to get leftover grams
}

//Displays the converted weight in kilograms and grams
void displayOutput(int kilograms, int grams) //function that prints the result
{
    cout << "Equivalent weight: " << kilograms << "kg " << grams << "g" << endl; // Print the result 
}

int main()
{
    int pounds, ounces; //Variables to store the user's weight input in pounds and ounces
    int kilograms, grams; //Variables to store the converted weight in kilograms and grams
    char again; //Varible for the user if they want to go again
    do 
    {
        getInput(pounds, ounces); //Call getInput to read pounds and ounces from user
        convert(pounds, ounces, kilograms, grams); //Call convert to calculate kilograms and grams
        displayOutput(kilograms, grams); //Call displayOutput to print the result

        cout << "Do you want to run again? (y/n): "; //Ask user if they want to run the program again
        cin >> again; 
        cout << endl; 
    } while (again == 'y' || again == 'Y'); //Do while loop for the y or capital Y response
    return 0; 
}