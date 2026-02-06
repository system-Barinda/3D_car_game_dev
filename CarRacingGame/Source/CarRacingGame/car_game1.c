#include <stdio.h>
#include <math.h>

int main() {
    float price, downPayment, interestRate, principal;
    int months;
    float monthlyRate, monthlyPayment, totalCost;

    printf("--- REAL CAR AFFORDABILITY CALCULATOR ---\n\n");

    // Input Data
    printf("Enter Car Purchase Price: $");
    scanf("%f", &price);

    printf("Enter Down Payment: $");
    scanf("%f", &downPayment);

    printf("Enter Annual Interest Rate (e.g., 5.5 for 5.5%%): ");
    scanf("%f", &interestRate);

    printf("Enter Loan Term (in months, e.g., 60): ");
    scanf("%d", &months);

    // Calculations
    principal = price - downPayment;
    monthlyRate = (interestRate / 100) / 12;

   
    monthlyPayment = (principal * monthlyRate * pow(1 + monthlyRate, months)) / 
                     (pow(1 + monthlyRate, months) - 1);

    totalCost = (monthlyPayment * months) + downPayment;

    // Output Results
    printf("\n--- LOAN SUMMARY ---\n");
    printf("Loan Amount:      $%.2f\n", principal);
    printf("Monthly Payment:  $%.2f\n", monthlyPayment);
    printf("Total Cost of Car: $%.2f\n", totalCost);
    printf("Total Interest:    $%.2f\n", totalCost - price);

    if (monthlyPayment > 500) {
        printf("\nWARNING: This payment is getting high! Ensure it's < 15%% of your income.\n");
    } else {
        printf("\nRESULT: This looks like a manageable budget!\n");
    }

    return 0;
}