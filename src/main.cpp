/**
 * @file main.cpp
 * @brief Entry point for the loan calculator program.
 *
 * This program creates a Loan object, prompts the user for input,
 * and displays the total amount, total interest, and monthly EMI.
 */

#include <iostream>
#include "loan.h"
using namespace std;

/**
 * @brief Main function that runs the loan calculator.
 * 
 * @return int Program exit status (0 on success)
 */
int main() {
    Loan obj;   /**< Loan object */

    obj.input();   /**< Take input from the user */

    cout << "Total amount to be paid: " << obj.getTotalAmount() << endl;
    cout << "Total interest: " << obj.getTotalInterest() << endl;
    cout << "Monthly amount to be paid: " << obj.getMonthlyAmount() << endl;

    return 0;
}
