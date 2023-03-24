/*
    filename: mortgageCalculator.cpp
    summary: get mortgage
    author: Abdurrahman Alyajouri
    date: 2/21/2023
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void intro(); //introduce
void inputInfo(float& rate, int& years, int& mortgage); //pass by reference
void computeMortgage(float rate, int years, int mortgage); //calculate mortgage
void displayAll(float rate, int years, int mortgage, float monthlyPayment, float totalPayment);//display

int main() {
    float rate,
          monthlyPayment,
          totalPayment;
    int years,
        mortgage;
        
    displayAll(rate, years, mortgage, monthlyPayment, totalPayment);
    
    return 0;
}

void intro() {
    cout << "Welcome to the Mortgage Calculator Program!\n";
    cout << "Written by Abdurrahman Alyajouri\n\n";
}

void inputInfo(float& rate, int& years, int& mortgage) {
    cout << "Enter the annual interest rate: ";
    cin >> rate;
    cout << "Enter the number of years the mortgage will be held: ";
    cin >> years;
    cout << "Enter the mortgage amount borrowed from the bank: ";
    cin >> mortgage;
    return;
}

void computeMortgage(float rate, int years, int mortgage, float& monthlyPayment, float& totalPayment) {
    rate = rate / 12.0;
    monthlyPayment = (mortgage * rate * pow(1 + rate, years * 12)) / (pow(1 + rate, years * 12) - 1);
    totalPayment = monthlyPayment * 12.0 * years;
    return;
}

void displayAll(float rate, int years, int mortgage, float monthlyPayment, float totalPayment) {
    intro();
    inputInfo(rate, years, mortgage);
    computeMortgage(rate, years, mortgage, monthlyPayment, totalPayment);
    cout << "Annual Interest Rate: %" << rate * 100 << endl;
    cout << "Mortgage: $" << mortgage << endl;
    cout << "Monthly Payments: $" << fixed << setprecision(2) << monthlyPayment << endl;
    cout << "Total Payment: $" << fixed << setprecision(2) << totalPayment << endl;
}

