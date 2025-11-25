/**
 * @file loan.cpp
 * @brief Implementation of the Loan class methods.
 */

#include <iostream>
#include "loan.h"
using namespace std;

/**
 * @brief Prompts the user to input loan details: amount, interest rate, and tenure.
 */
void Loan::input() {
    cout << "Enter the loan amount: ";
    cin >> loan_amount;

    cout << "Enter the interest rate: ";
    cin >> interest_rate;

    cout << "Enter the number of years: ";
    cin >> number_of_years;
}

/**
 * @brief Calculates total amount payable over the loan tenure.
 * 
 * Total amount includes principal and interest.
 * Formula: total = principal * years + (principal * years * rate / 100)
 * 
 * @return Total payable amount
 */
double Loan::getTotalAmount() {
    return (number_of_years * loan_amount) +
           (number_of_years * loan_amount * (interest_rate / 100.0));
}

/**
 * @brief Calculates the total interest to be paid over the loan tenure.
 * 
 * @return Total interest
 */
double Loan::getTotalInterest() {
    return getTotalAmount() - (number_of_years * loan_amount);
}

/**
 * @brief Calculates the monthly installment (EMI).
 * 
 * Formula: monthly amount = total amount / (number of years * 12)
 * 
 * @return Monthly payment amount
 */
double Loan::getMonthlyAmount() {
    return getTotalAmount() / (number_of_years * 12);
}
