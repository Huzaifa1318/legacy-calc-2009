#include <gtest/gtest.h>
#include <stdexcept>
#include <cmath>     // REQUIRED for pow()

// ---------------------------------------------------------
// Stand-alone EMI function for testing
// (Rename to avoid conflict with your loan.h)
// ---------------------------------------------------------
double test_calculateEMI(double P, double rate, int years) {
    if (P <= 0 || rate < 0 || years <= 0)
        throw std::invalid_argument("Invalid input");

    double monthlyRate = rate / (12 * 100);
    int months = years * 12;

    double emi = (P * monthlyRate * pow(1 + monthlyRate, months)) /
                 (pow(1 + monthlyRate, months) - 1);

    return emi;
}

// ---------------------------------------------------------
// 1. Normal EMI calculation
// ---------------------------------------------------------
TEST(EMITest, NormalCalculation) {
    double emi = test_calculateEMI(100000, 10, 5);

    // Expected EMI ≈ 2124.70
    EXPECT_NEAR(emi, 2124.70, 0.5);
}

// ---------------------------------------------------------
// 2. Invalid Input Handling
// ---------------------------------------------------------
TEST(EMITest, InvalidInput) {
    EXPECT_THROW(test_calculateEMI(-50000, 10, 5), std::invalid_argument);
    EXPECT_THROW(test_calculateEMI(50000, -2, 5), std::invalid_argument);
    EXPECT_THROW(test_calculateEMI(50000, 10, 0), std::invalid_argument);
}

// ---------------------------------------------------------
// 3. Large Tenure Without Overflow
// ---------------------------------------------------------
TEST(EMITest, LargeTenureCalculation) {
    double emi = test_calculateEMI(200000, 8, 50);  // 50 years
    EXPECT_TRUE(std::isfinite(emi));
    EXPECT_GT(emi, 0);
}
