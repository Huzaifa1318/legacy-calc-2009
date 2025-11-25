#ifndef LOAN_H
#define LOAN_H

/**
 * @file loan.h
 * @brief Declaration of the Loan class for EMI and loan calculations.
 */

/**
 * @class Loan
 * @brief Represents a loan and provides methods to calculate total amount,
 * total interest, and monthly payments.
 *
 * This class stores the loan amount, interest rate, and number of years.
 * It provides methods to input loan details and calculate repayment details.
 */
class Loan {
private:
    double loan_amount;     /**< Principal loan amount */
    double interest_rate;   /**< Annual interest rate in percentage */
    double number_of_years; /**< Loan tenure in years */

public:
    /**
     * @brief Reads input from the user for loan amount, interest rate, and tenure.
     */
    void input();

    /**
     * @brief Calculates the total amount to be paid over the loan tenure.
     * 
     * @return Total payable amount (principal + interest)
     */
    double getTotalAmount();

    /**
     * @brief Calculates the total interest to be paid over the loan tenure.
     * 
     * @return Total interest amount
     */
    double getTotalInterest();

    /**
     * @brief Calculates the monthly installment (EMI) for the loan.
     * 
     * @return Monthly amount to be paid
     */
    double getMonthlyAmount();
};

#endif