#include <stdio.h>
#include <string.h>

int main() {
    char CustomerName[15], Name[10][15];
    int Quantity[10], NumberOfItems, i;
    float UnitPrice[10], TotalPrice[10], TotalAmount;

    NumberOfItems = 0;

    printf("Enter customer name [QUIT to stop] : ");
    scanf("%s", CustomerName);

    while (strcmp(CustomerName, "QUIT") != 0 && NumberOfItems < 10) {
        printf("Enter name, quantity, and price for item %d [END 0 0] : ", NumberOfItems + 1);
        scanf("%s %d %f", Name[NumberOfItems], &Quantity[NumberOfItems], &UnitPrice[NumberOfItems]);

        if (strcmp(Name[NumberOfItems], "END") == 0) {
            break;
        }

        TotalPrice[NumberOfItems] = Quantity[NumberOfItems] * UnitPrice[NumberOfItems];
        TotalAmount += TotalPrice[NumberOfItems];

        NumberOfItems++;
    }

    printf("--------------------------------------------------------------\n");
    printf("%-20s %11s %13s %17s\n", "Name", "Quantity", "Unit Price", "Total Price");
    printf("--------------------------------------------------------------\n");

    for (i = 0; i < NumberOfItems; i++) {
        printf("%-20s %11d %13.2f %17.2f\n", Name[i], Quantity[i], UnitPrice[i], TotalPrice[i]);
        printf("--------------------------------------------------------------\n");
    }

    printf("%52s %11.2f\n", "TOTAL AMOUNT : ", TotalAmount);

    return 0;
}