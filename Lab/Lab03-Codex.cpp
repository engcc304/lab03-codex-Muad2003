#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    char CustomerName[15], Name[10][15] ;
    int Quantity[10], NumberOfItems, i = 0; // เพิ่มตัวแปร i และกำหนดค่าเริ่มต้นเป็น 0
    float UnitPrice[10], TotalPrice[10], TotalAmount ;

    printf( "Enter customer name [QUIT to stop] : " ) ;
    scanf( "%s", CustomerName ) ;

    while( strcmp(CustomerName, "QUIT") != 0 ) { // เพิ่มเครื่องหมายวงเล็บในส่วนของ while
        printf( "Enter name, quantity, and price for item %d [END 0 0] : ", i + 1 ) ;
        scanf( "%s %d %f", Name[i], &Quantity[i], &UnitPrice[i] ) ;
        
        if( strcmp(Name[i], "END") == 0 ) // เพิ่มเงื่อนไขเพื่อตรวจสอบว่า Name[i] เป็น "END" หรือไม่
            break;

        i++ ; // เพิ่มค่า i เพื่อเลื่อนไปยังรายการสินค้าถัดไป
    }

    NumberOfItems = i ; // กำหนดค่า NumberOfItems จาก i ที่คำนวณไว้

    TotalAmount = 0.0 ;
    for( i = 0 ; i < NumberOfItems ; i++ ) {
        TotalPrice[i] = Quantity[i] * UnitPrice[i] ;
        TotalAmount += TotalPrice[i] ;
    }

    printf( "--------------------------------------------------------------\n" ) ;
    printf( "%-20s %11s %13s %17s\n", "Name", "Quantity", "Unit Price", "Total Price" ) ;
    printf( "--------------------------------------------------------------\n" ) ;
    
    for( i = 0 ; i < NumberOfItems ; i++ ) { 
        printf( "%-20s %11d %13.2f %17.2f\n", Name[i], Quantity[i], UnitPrice[i], TotalPrice[i] );
        printf( "--------------------------------------------------------------\n" ) ;
    }

    printf( "%52s %11.2f\n", "TOTAL AMOUNT : ", TotalAmount ) ;

    return 0 ;
}
