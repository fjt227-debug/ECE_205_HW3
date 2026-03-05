// ECE205HW3_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;
// Function prototypes
void Input(int& hours, int& minutes); //Inputs function
void convert24to12(int hours, int& hours12, char& AmPm); //Convert Function from 24 hr to 12 hr time
int elapsedMinutes(int startHours, int startMinutes, int endHours, int endMinutes); //Calcualtes difference in time from End and Start time
void displayOutput(int hours12, int minutes, char AmPm); //Displays the output 
int main()
{
    int startHours, startMinutes, endHours, endMinutes; //Stores times and minutes entered by user
    int startHours12, endHours12; //Stores the converted 12 hour values
    char startAmPm, endAmPm; //Stores the AM and PM characters
    char again; //Asks user if they want to go again
    do
    {
        cout << "Enter start time in (hours_minutes): " << endl; //Asks the user for start hours space minutes
        Input(startHours, startMinutes); //Calls Input to read start hours and start minutes

        cout << "Enter end time in (hours_minutes): " << endl; //Ask the user for end hours spsace minutes
        Input(endHours, endMinutes); //Calls Input to read emd hours and start minutes

        convert24to12(startHours, startHours12, startAmPm); //Converts the start time from 24Hr to 12Hr, sets startHours12 and startAmPm
        convert24to12(endHours, endHours12, endAmPm); //Converts the end time from 24Hr to 12Hr, sets endHours12 and endAmPm
        int elapsed = elapsedMinutes(startHours, startMinutes, endHours, endMinutes); //Calculate the difference in time between the start time and end time

        cout << "Start time: " << endl; //Prints Start time
        displayOutput(startHours12, startMinutes, startAmPm); //Function Print Start time

        cout << "End time: " << endl; //Prints End time
        displayOutput(endHours12, endMinutes, endAmPm); //Function Prints End time

        cout << "Elapsed time: " << elapsed << " minutes" << endl; //Prints elasped time
        cout << "Do you want to input again? (y/n): "; //Asks user if they want to go again
        cin >> again;
        cout << endl;
    } while (again == 'y' || again == 'Y'); //Do while loop for the y or capital Y response 
    return 0;
}
// Gets hours and minutes from the user
void Input(int& hours, int& minutes)
{
    cin >> hours >> minutes;
}
// Converts 24 hour time to 12 hour time
// Sets AmPm to 'A' for AM, 'P' for PM
void convert24to12(int hours, int& hours12, char& AmPm)
{
    if (hours < 12) //If hours are less than 12 print A
    {
        AmPm = 'A';
        if (hours == 0)
            hours12 = 12;
        else
            hours12 = hours;
    }
    else //If hours are greater than 12 print P
    {
        AmPm = 'P';
        if (hours == 12)
            hours12 = 12;
        else
            hours12 = hours - 12;
    }
}
// Calculates elapsed time in minutes between start and end times
int elapsedMinutes(int startHours, int startMinutes, int endHours, int endMinutes)
{
    int elapsed;
    if (startHours<endHours && startMinutes<=endMinutes) //If start hours are less than end hours and start minutes are less than or equal to end minutes
    {
        elapsed = ((endHours - startHours) * 60) + (endMinutes - startMinutes);
    }
    else if (startHours<endHours && startMinutes>endMinutes) //If start hours are less than end hours and start minutes are greater than or equal to end minutes
    {
        elapsed = ((endHours - startHours - 1) * 60) + (60 - startMinutes + endMinutes);
    }
    else if (startHours>endHours && startMinutes<=endMinutes) //If start hours are greater than end hours and start minutes are less than or equal to end minutes
    {
        elapsed = ((24 - startHours) + endHours) * 60 + (endMinutes - startMinutes);
    }
    else //If start hours are greater than end hours and start minutes are greater than or equal to end minutes
    {
        elapsed = ((24 - startHours) + endHours - 1) * 60 + (60 - startMinutes + endMinutes);
    }
    return elapsed;
}
// Displays the 12 hour formatted time with AM/PM
void displayOutput(int hours12, int minutes, char AmPm) 
{
    cout << hours12 << ":"; //Prints hours in the 12 hour format then a semicolon 
    if (minutes < 10) //If the minutes are less then 10 it will print a zero. So the code at this point would be 12:0 then the next line
        cout << "0";
    cout << minutes << " " << AmPm << "M" << endl; //Prints minutes then a space then "A" or "P" then M
}