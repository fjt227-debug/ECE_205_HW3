//ECE205HW3_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cmath>
using namespace std;

//Computes area and perimeter of a triangle given sides a, b, c
//Sets area and perimeter by reference
//If sides do not form a valid triangle, sets both to 0
void triangleCalc(double a, double b, double c, double& area, double& perimeter) //Function used to calculate triange area and perimeter
{
    // Check if sides form a valid triangle
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) //These tests are used to see if the input data creates a valid traingle
    {
        area = 0; //Area and perimeter will be 0 if invalid
        perimeter = 0;
    }
    else
    {
        double s = (a + b + c) / 2.0; //This calculates semi perimeter for the area calculation
        area = sqrt(s * (s - a) * (s - b) * (s - c)); //Area calculation show on the homework
        perimeter = a + b + c; //Calculating perimiter
    }
}

int main()
{
    double a, b, c; //varibles for sides a, b, and c
    double area, perimeter; //varibles for area and perimeter
    char again; //Asks the user for Y/N input to see if they want they program to run again

    do
    {
        cout << "Enter side a: " << endl;
        cin >> a;
        cout << "Enter side b: " << endl;
        cin >> b;
        cout << "Enter side c: " << endl;
        cin >> c;

        triangleCalc(a, b, c, area, perimeter); //Calls the function to calculate the area and perimeter and check if the traingle is valid

        if (area == 0 && perimeter == 0) //Checks to see if its a valid triangle
        {
            cout << "Invalid triangle sides." << endl;
        }
        else
        {
            cout << "Area: " << area << endl; //Prints area and perimeter
            cout << "Perimeter: " << perimeter << endl;
        }

        cout << "Do you want to try again? (y/n): ";//Do while loop asking the user if they want to input again
        cin >> again;
        cout << endl;

    } while (again == 'y' || again == 'Y'); //Do while loop asking the user if they want to input again

    return 0;
}

