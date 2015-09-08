#include <stdio.h>
#include <string.h>

/*
This program takes int and converts it into a corresponding alphabet number as seen in Excel columns.
This approach is equivalent to converting decimal (base 10) into one based on alphabet chars (base 26).
Our function works by identifying the biggest base alphabet and subtracting its value from the initial
integer and repeating this process until all numbers within the original integer is accounted for.
*/

char* convertToTitle(int n);

int main()
{
    //test cases
    printf("output:%s\n", convertToTitle(1));       //A
    printf("output:%s\n", convertToTitle(26));      //Z
    printf("output:%s\n", convertToTitle(27));      //AA
    printf("output:%s\n", convertToTitle(443));     //QA
    printf("output:%s\n", convertToTitle(626));     //XB
    printf("output:%s\n", convertToTitle(3323));    //DWU

    return 0;
}

char* convertToTitle(int n)
{
    static char columnTitle[10] = " ";  //stores output (excel column)
    char alphabets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int greatestDivisor = 1;
    int letter;                          //order from start of letter to be added (1 = A, 26 = Z)
    int i = 0;

    //find greatest multiple of 26 that fits into n
    while ((n > 26) && ((n / (greatestDivisor * 26)) >= 1))
    {
        greatestDivisor *= 26;
    }

    //repeat below until n == 0 (i.e. until every number in n is accounted for)
    while (n != 0)
    {
        letter = n / greatestDivisor;
        columnTitle[i] = alphabets[letter - 1];     //set first "digit" of alphabet
        n -= letter * greatestDivisor;              //subtract value of first alphabet from n

        greatestDivisor /= 26;                      //decrease the base (base 26)
        i++;                                        //move index to add next digit of alphabet
    }

    return columnTitle;
}
