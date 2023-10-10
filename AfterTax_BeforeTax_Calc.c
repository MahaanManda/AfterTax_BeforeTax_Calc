#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// define your functions here

void priceInput(double* userInput, int numElements) {
    int i;
    printf("Enter the price for 100 items:\n");
    for (i = 0; i < numElements; ++i) {

        printf("%d.  ", i + 1);
        scanf("%lf", &userInput[i]);
    }

}

void afterTax(const double* userInput, double* afterTax, int numElements) {
    int i;
    double calc;

    for (i = 0; i < numElements; ++i) {

        afterTax[i] = (userInput[i] * 0.05) + userInput[i];
    }

}

void printArrayBeforeTax(double* userInput, int numElements) {

    int i;
    printf("Before Tax:\n");
    for (i = 0; i < numElements; ++i) {
        printf("%d.  ", i + 1);
        printf("%lf\n", userInput[i]);

    }

}

void printArrayAfterTax(double* afterTax, int numElements) {

    int i;
    printf("After Tax:\n");
    for (i = 0; i < numElements; ++i) {
        printf("%d.  ", i + 1);
        printf("%lf\n", afterTax[i]);

    }

}



int main() {

    int elements = 100;
    double currentPrice[elements];
    double afterTax1[elements];
    double sumBeforeTax = 0;
    double sumAfterTax = 0;

    bool isQuit = false;
    char quitChar = 'c';

    int i;


    

    priceInput(currentPrice, elements);
    afterTax(currentPrice, afterTax1, elements);

    printArrayAfterTax(afterTax1, elements);
    
    // cumulative price before tax

    for (i = 0; i < elements; ++i) {

        sumBeforeTax = sumBeforeTax + currentPrice[i];

    }

    // cumulative price after tax

    for (i = 0; i < elements; ++i) {

        sumAfterTax = sumAfterTax + afterTax1[i];

    }

    printf("The cumulative sum before tax is: %lf\n", sumBeforeTax);
    printf("The cumulative sum after tax is: %lf\n", sumAfterTax);

    
    while (isQuit != true) { 

        printf("Type q to quit");
        scanf(" %c", quitChar);

        if(quitChar == 'q'){
            isQuit = true;
            break;

        }

    }
    



    return 0;
}