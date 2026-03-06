//ECE205HW3_Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream> 
using namespace std;

// Calculates change in minutes between two military times 
int changeMinutes(int startTime, int endTime) //Function that takes two 4-digit military times and returns total change in minutes
{
    int startHours = startTime / 100; //Takes start time and divids by 100 to get hours 
    int startMinutes = startTime % 100; //Takes start time and takes the remainder to get minutes
    int endHours = endTime / 100; //Takes end time and divides by 100 to get hours
    int endMinutes = endTime % 100; //Takes end time and takes the remainder to get minutes
    int startTotal = startHours * 60 + startMinutes; //Convert start time to minutes 
    int endTotal = endHours * 60 + endMinutes; //Convert end time to minutes
    int change; //Time between start and end time
    if (endTotal >= startTotal) //If the endTotal is greater than or equal to start total do
    {
        change = endTotal - startTotal; //Take the difference from start and end time
     }
    else //End time is the next day 
    {
        change = (24 * 60 - startTotal) + endTotal; //Minutes from start to midnight plus minutes from midnight to end
    }
    return change; //Return the total change in minutes
}

int main()
{
    int startTime, endTime; //Variables to store the military time inputs from the user
    char again; //Varible for the user if they want to go again
    do 
    {
        cout << "Enter start time (0000 to 2359): " << endl; //Ask user for start time
        cin >> startTime; //Read start time from user

        cout << "Enter end time (0000 to 2359): " << endl; //Ask user for end time
        cin >> endTime; //Read end time from user

        int change = changeMinutes(startTime, endTime); //Call changeMinutes and stores the result
        cout << "Change in minutes: " << change << " minutes" << endl; //Print the total change in minutes
        cout << "Do you want to try again? (y/n): "; //Ask user if they want to run the program again

        cin >> again; 
        cout << endl; 

    } while (again == 'y' || again == 'Y'); //Do while loop for the y or capital Y response
    return 0; 
}






