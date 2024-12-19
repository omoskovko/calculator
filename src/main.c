#include <stdio.h>
#include "calc.h"

int main()
{
    long int num1, num2, result;
    int choice;

    printf("Enter the operation you want to perform: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Square Root\n");
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    if (choice < 1 || choice > 6)
    {
        printf("Invalid choice\n");
        return 1;
    }

    printf("Enter the first number: ");
    if (scanf("%ld", &num1) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }
    if (choice != 5 && choice != 6)
    {
        printf("Enter the second number: ");
        if (scanf("%ld", &num2) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
    }

    switch (choice)
    {
    case 1:
        result = add(num1, num2);
        printf("The result of adding %ld and %ld is %ld\n", num1, num2, result);
        break;
    case 2:
        result = difference(num1, num2);
        printf("The result of subtracting %ld and %ld is %ld\n", num1, num2, result);
        break;
    case 3:
        result = product(num1, num2);
        printf("The result of multiplying %ld and %ld is %ld\n", num1, num2, result);
        break;
    case 4:
        printf("The result of dividing %ld by %ld is %.2f\n", num1, num2, num_fraction(num1, num2));
        break;
    case 5:
        result = factorial(num1);
        printf("The factorial of %ld is %ld\n", num1, result);
        break;
    case 6:
        printf("The square root of %ld is %.2f\n", num1, square_root(num1));
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}
