#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* ============================================================
   COMPLETE NUMBER SYSTEM CONVERTER
   Binary | Decimal | Octal | Hexadecimal
   ============================================================ */

long int Bin_to_Dec(long int);
long int Bin_to_Oct(long int);
long int Bin_to_Hex(long int);
long int Dec_to_Bin(long int);
long int Dec_to_Oct(long int);
long int Dec_to_Hex(long int);
long int Oct_to_Bin(long int);
long int Oct_to_Dec(long int);
long int Oct_to_Hex(long int);
void Hex_to_Bin(char[]);
void Hex_to_Dec(char[]);
void Hex_to_Oct(char[]);

/* -------------------- UI FUNCTIONS -------------------- */

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void line()
{
    printf("======================================================================\n");
}

void doubleLine()
{
    printf("======================================================================\n");
}

void smallLine()
{
    printf("----------------------------------------------------------------------\n");
}

void title()
{
    printf("\n");
    doubleLine();
    printf("                 COMPLETE NUMBER SYSTEM CONVERTER\n");
    printf("                     Binary | Decimal | Octal | Hex\n");
    doubleLine();
    printf("\n");
}

void showMenu()
{
    printf("\n");
    printf("                         CONVERSION MENU\n");
    smallLine();

    printf("\n");
    printf("  +---------------- BINARY CONVERSIONS ----------------+\n");
    printf("  |  [ 1 ]  Binary      -> Decimal                      |\n");
    printf("  |  [ 2 ]  Binary      -> Octal                        |\n");
    printf("  |  [ 3 ]  Binary      -> Hexadecimal                  |\n");
    printf("  +-----------------------------------------------------+\n");

    printf("\n");
    printf("  +--------------- DECIMAL CONVERSIONS ----------------+\n");
    printf("  |  [ 4 ]  Decimal     -> Binary                       |\n");
    printf("  |  [ 5 ]  Decimal     -> Octal                        |\n");
    printf("  |  [ 6 ]  Decimal     -> Hexadecimal                  |\n");
    printf("  +-----------------------------------------------------+\n");

    printf("\n");
    printf("  +----------------- OCTAL CONVERSIONS ----------------+\n");
    printf("  |  [ 7 ]  Octal       -> Binary                       |\n");
    printf("  |  [ 8 ]  Octal       -> Decimal                      |\n");
    printf("  |  [ 9 ]  Octal       -> Hexadecimal                  |\n");
    printf("  +-----------------------------------------------------+\n");

    printf("\n");
    printf("  +------------ HEXADECIMAL CONVERSIONS ---------------+\n");
    printf("  |  [10 ]  Hexadecimal -> Binary                       |\n");
    printf("  |  [11 ]  Hexadecimal -> Decimal                      |\n");
    printf("  |  [12 ]  Hexadecimal -> Octal                        |\n");
    printf("  +-----------------------------------------------------+\n");

    printf("\n");
    printf("  [ 0 ]  Exit Program\n");
    smallLine();
}

void conversionTitle(const char text[])
{
    printf("\n");
    line();
    printf("                       %s\n", text);
    line();
}

void resultLine()
{
    printf("\n");
    smallLine();
}

void goodbye()
{
    printf("\n\n");
    doubleLine();
    printf("                 THANK YOU FOR USING THE\n");
    printf("                NUMBER SYSTEM CONVERTER!\n");
    doubleLine();
    printf("\n");
}

/* -------------------- VALIDATION FUNCTIONS -------------------- */

int isBinary(long int number)
{
    if (number == 0)
        return 1;

    while (number != 0)
    {
        if (number % 10 > 1)
            return 0;

        number /= 10;
    }

    return 1;
}

int isOctal(long int number)
{
    if (number == 0)
        return 1;

    while (number != 0)
    {
        if (number % 10 > 7)
            return 0;

        number /= 10;
    }

    return 1;
}

int isHexadecimal(const char hex[])
{
    int i;

    if (hex[0] == '\0')
        return 0;

    for (i = 0; hex[i] != '\0'; i++)
    {
        if (!((hex[i] >= '0' && hex[i] <= '9') ||
              (hex[i] >= 'A' && hex[i] <= 'F') ||
              (hex[i] >= 'a' && hex[i] <= 'f')))
        {
            return 0;
        }
    }

    return 1;
}

/* ============================================================
                         MAIN PROGRAM
   ============================================================ */

int main()
{
    int input;
    int num = 1;
    long int bin, oct, dec;
    char hex[1000];

    system("COLOR 0B");

    title();

    while (num != 0)
    {
        showMenu();

        printf("\n  ENTER YOUR CHOICE: ");

        if (scanf("%d", &input) != 1)
        {
            clearInputBuffer();
            printf("\n  [ ERROR ] Invalid input. Please enter a number.\n");
            continue;
        }

        switch (input)
        {
            case 0:
                num = 0;
                break;

            /* ---------------- BINARY ---------------- */

            case 1:
                conversionTitle("BINARY  ->  DECIMAL");

                printf("\n  Enter Binary Number (0s & 1s): ");
                scanf("%ld", &bin);

                if (!isBinary(bin))
                {
                    printf("\n  [ ERROR ] %ld is NOT a binary number.\n", bin);
                    printf("  [ INFO  ] Binary numbers contain only 0 and 1.\n");
                    break;
                }

                Bin_to_Dec(bin);
                break;

            case 2:
                conversionTitle("BINARY  ->  OCTAL");

                printf("\n  Enter Binary Number (0s & 1s): ");
                scanf("%ld", &bin);

                if (!isBinary(bin))
                {
                    printf("\n  [ ERROR ] %ld is NOT a binary number.\n", bin);
                    printf("  [ INFO  ] Binary numbers contain only 0 and 1.\n");
                    break;
                }

                Bin_to_Oct(bin);
                break;

            case 3:
                conversionTitle("BINARY  ->  HEXADECIMAL");

                printf("\n  Enter Binary Number (0s & 1s): ");
                scanf("%ld", &bin);

                if (!isBinary(bin))
                {
                    printf("\n  [ ERROR ] %ld is NOT a binary number.\n", bin);
                    printf("  [ INFO  ] Binary numbers contain only 0 and 1.\n");
                    break;
                }

                Bin_to_Hex(bin);
                break;

            /* ---------------- DECIMAL ---------------- */

            case 4:
                conversionTitle("DECIMAL  ->  BINARY");

                printf("\n  Enter Decimal Number: ");
                scanf("%ld", &dec);

                if (dec < 0)
                {
                    printf("\n  [ ERROR ] Negative numbers are not supported.\n");
                    break;
                }

                Dec_to_Bin(dec);
                break;

            case 5:
                conversionTitle("DECIMAL  ->  OCTAL");

                printf("\n  Enter Decimal Number: ");
                scanf("%ld", &dec);

                if (dec < 0)
                {
                    printf("\n  [ ERROR ] Negative numbers are not supported.\n");
                    break;
                }

                Dec_to_Oct(dec);
                break;

            case 6:
                conversionTitle("DECIMAL  ->  HEXADECIMAL");

                printf("\n  Enter Decimal Number: ");
                scanf("%ld", &dec);

                if (dec < 0)
                {
                    printf("\n  [ ERROR ] Negative numbers are not supported.\n");
                    break;
                }

                Dec_to_Hex(dec);
                break;

            /* ---------------- OCTAL ---------------- */

            case 7:
                conversionTitle("OCTAL  ->  BINARY");

                printf("\n  Enter Octal Number (0-7): ");
                scanf("%ld", &oct);

                if (!isOctal(oct))
                {
                    printf("\n  [ ERROR ] %ld is NOT an octal number.\n", oct);
                    printf("  [ INFO  ] Octal numbers contain digits from 0 to 7.\n");
                    break;
                }

                Oct_to_Bin(oct);
                break;

            case 8:
                conversionTitle("OCTAL  ->  DECIMAL");

                printf("\n  Enter Octal Number (0-7): ");
                scanf("%ld", &oct);

                if (!isOctal(oct))
                {
                    printf("\n  [ ERROR ] %ld is NOT an octal number.\n", oct);
                    printf("  [ INFO  ] Octal numbers contain digits from 0 to 7.\n");
                    break;
                }

                Oct_to_Dec(oct);
                break;

            case 9:
                conversionTitle("OCTAL  ->  HEXADECIMAL");

                printf("\n  Enter Octal Number (0-7): ");
                scanf("%ld", &oct);

                if (!isOctal(oct))
                {
                    printf("\n  [ ERROR ] %ld is NOT an octal number.\n", oct);
                    printf("  [ INFO  ] Octal numbers contain digits from 0 to 7.\n");
                    break;
                }

                Oct_to_Hex(oct);
                break;

            /* ---------------- HEXADECIMAL ---------------- */

            case 10:
                conversionTitle("HEXADECIMAL  ->  BINARY");

                printf("\n  Enter Hexadecimal Number: ");
                scanf("%999s", hex);

                if (!isHexadecimal(hex))
                {
                    printf("\n  [ ERROR ] \"%s\" is NOT a hexadecimal number.\n", hex);
                    printf("  [ INFO  ] Use digits 0-9 and letters A-F.\n");
                    break;
                }

                Hex_to_Bin(hex);
                break;

            case 11:
                conversionTitle("HEXADECIMAL  ->  DECIMAL");

                printf("\n  Enter Hexadecimal Number: ");
                scanf("%999s", hex);

                if (!isHexadecimal(hex))
                {
                    printf("\n  [ ERROR ] \"%s\" is NOT a hexadecimal number.\n", hex);
                    printf("  [ INFO  ] Use digits 0-9 and letters A-F.\n");
                    break;
                }

                Hex_to_Dec(hex);
                break;

            case 12:
                conversionTitle("HEXADECIMAL  ->  OCTAL");

                printf("\n  Enter Hexadecimal Number: ");
                scanf("%999s", hex);

                if (!isHexadecimal(hex))
                {
                    printf("\n  [ ERROR ] \"%s\" is NOT a hexadecimal number.\n", hex);
                    printf("  [ INFO  ] Use digits 0-9 and letters A-F.\n");
                    break;
                }

                Hex_to_Oct(hex);
                break;

            default:
                printf("\n  [ ERROR ] Invalid menu choice.\n");
                printf("  [ INFO  ] Please select an option from 0 to 12.\n");
                break;
        }

        if (input != 0)
        {
            printf("\n\n");
            smallLine();
            printf("  Do you want to perform another conversion?\n");
            printf("  Enter 1 = YES    |    0 = NO\n");
            printf("  YOUR CHOICE: ");

            if (scanf("%d", &num) != 1)
            {
                clearInputBuffer();
                num = 0;
            }
        }
    }

    goodbye();

    return 0;
}

/* ============================================================
                    CONVERSION FUNCTIONS
   ============================================================ */

long int Bin_to_Dec(long int bin)
{
    int rem;
    long int sum = 0;
    int i = 0;

    while (bin != 0)
    {
        rem = bin % 10;
        bin = bin / 10;
        sum = sum + rem * (long int)pow(2, i);
        i++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Decimal Number : %ld\n", sum);
    smallLine();

    return sum;
}

long int Bin_to_Oct(long int bin)
{
    int i = 0, rem;
    long int sum = 0;
    int remain[100], len = 0;

    while (bin != 0)
    {
        rem = bin % 10;
        bin = bin / 10;
        sum = sum + rem * (long int)pow(2, i);
        i++;
    }

    if (sum == 0)
    {
        printf("\n  RESULT\n");
        printf("  Equivalent Octal Number : 0\n");
        smallLine();
        return 0;
    }

    i = 0;

    while (sum != 0)
    {
        remain[i] = sum % 8;
        sum = sum / 8;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Octal Number : ");

    for (i = len - 1; i >= 0; i--)
        printf("%d", remain[i]);

    printf("\n");
    smallLine();

    return 0;
}

long int Bin_to_Hex(long int bin)
{
    int rem, i = 0;
    long int sum = 0;
    int remain[100], len = 0;

    while (bin != 0)
    {
        rem = bin % 10;
        bin = bin / 10;
        sum = sum + rem * (long int)pow(2, i);
        i++;
    }

    if (sum == 0)
    {
        printf("\n  RESULT\n");
        printf("  Equivalent Hexadecimal Number : 0\n");
        smallLine();
        return 0;
    }

    i = 0;

    while (sum != 0)
    {
        remain[i] = sum % 16;
        sum = sum / 16;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Hexadecimal Number : ");

    for (i = len - 1; i >= 0; i--)
    {
        switch (remain[i])
        {
            case 10: printf("A"); break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D"); break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
            default: printf("%d", remain[i]);
        }
    }

    printf("\n");
    smallLine();

    return 0;
}

long int Dec_to_Bin(long int dec)
{
    int rem[100];
    int i = 0, len = 0;

    if (dec == 0)
    {
        resultLine();
        printf("  RESULT\n");
        printf("  Equivalent Binary Number : 0\n");
        smallLine();
        return 0;
    }

    while (dec != 0)
    {
        rem[i] = dec % 2;
        dec = dec / 2;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Binary Number : ");

    for (i = len - 1; i >= 0; i--)
        printf("%d", rem[i]);

    printf("\n");
    smallLine();

    return 0;
}

long int Dec_to_Oct(long int dec)
{
    int rem[100];
    int i = 0, len = 0;

    if (dec == 0)
    {
        resultLine();
        printf("  RESULT\n");
        printf("  Equivalent Octal Number : 0\n");
        smallLine();
        return 0;
    }

    while (dec != 0)
    {
        rem[i] = dec % 8;
        dec = dec / 8;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Octal Number : ");

    for (i = len - 1; i >= 0; i--)
        printf("%d", rem[i]);

    printf("\n");
    smallLine();

    return 0;
}

long int Dec_to_Hex(long int dec)
{
    int rem[100];
    int i = 0, len = 0;

    if (dec == 0)
    {
        resultLine();
        printf("  RESULT\n");
        printf("  Equivalent Hexadecimal Number : 0\n");
        smallLine();
        return 0;
    }

    while (dec != 0)
    {
        rem[i] = dec % 16;
        dec = dec / 16;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Hexadecimal Number : ");

    for (i = len - 1; i >= 0; i--)
    {
        switch (rem[i])
        {
            case 10: printf("A"); break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D"); break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
            default: printf("%d", rem[i]);
        }
    }

    printf("\n");
    smallLine();

    return 0;
}

long int Oct_to_Bin(long int oct)
{
    int rem[100], len = 0;
    long int decimal = 0;
    int i = 0, ans;

    while (oct != 0)
    {
        ans = oct % 10;
        oct = oct / 10;
        decimal = decimal + ans * (long int)pow(8, i);
        i++;
    }

    if (decimal == 0)
    {
        resultLine();
        printf("  RESULT\n");
        printf("  Equivalent Binary Number : 0\n");
        smallLine();
        return 0;
    }

    i = 0;

    while (decimal != 0)
    {
        rem[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Binary Number : ");

    for (i = len - 1; i >= 0; i--)
        printf("%d", rem[i]);

    printf("\n");
    smallLine();

    return 0;
}

long int Oct_to_Dec(long int oct)
{
    long int decimal = 0;
    int i = 0, ans;

    while (oct != 0)
    {
        ans = oct % 10;
        decimal = decimal + ans * (long int)pow(8, i);
        i++;
        oct = oct / 10;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Decimal Number : %ld\n", decimal);
    smallLine();

    return decimal;
}

long int Oct_to_Hex(long int oct)
{
    int rem[100], len = 0;
    long int decimal = 0;
    int i = 0, ans;

    while (oct != 0)
    {
        ans = oct % 10;
        oct = oct / 10;
        decimal = decimal + ans * (long int)pow(8, i);
        i++;
    }

    if (decimal == 0)
    {
        resultLine();
        printf("  RESULT\n");
        printf("  Equivalent Hexadecimal Number : 0\n");
        smallLine();
        return 0;
    }

    i = 0;

    while (decimal != 0)
    {
        rem[i] = decimal % 16;
        decimal = decimal / 16;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Hexadecimal Number : ");

    for (i = len - 1; i >= 0; i--)
    {
        switch (rem[i])
        {
            case 10: printf("A"); break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D"); break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
            default: printf("%d", rem[i]);
        }
    }

    printf("\n");
    smallLine();

    return 0;
}

/* ============================================================
                    HEXADECIMAL FUNCTIONS
   ============================================================ */

void Hex_to_Bin(char hex[])
{
    int i;

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Binary Number : ");

    for (i = 0; i < (int)strlen(hex); i++)
    {
        switch (hex[i])
        {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;

            case 'A':
            case 'a': printf("1010"); break;

            case 'B':
            case 'b': printf("1011"); break;

            case 'C':
            case 'c': printf("1100"); break;

            case 'D':
            case 'd': printf("1101"); break;

            case 'E':
            case 'e': printf("1110"); break;

            case 'F':
            case 'f': printf("1111"); break;
        }
    }

    printf("\n");
    smallLine();
}

void Hex_to_Dec(char hex[])
{
    int i, num = 0;
    int power = 0;
    long int decimal = 0;

    for (i = (int)strlen(hex) - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
            num = hex[i] - '0';
        else if (hex[i] == 'A' || hex[i] == 'a')
            num = 10;
        else if (hex[i] == 'B' || hex[i] == 'b')
            num = 11;
        else if (hex[i] == 'C' || hex[i] == 'c')
            num = 12;
        else if (hex[i] == 'D' || hex[i] == 'd')
            num = 13;
        else if (hex[i] == 'E' || hex[i] == 'e')
            num = 14;
        else if (hex[i] == 'F' || hex[i] == 'f')
            num = 15;

        decimal = decimal + num * (long int)pow(16, power);
        power++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Decimal Number : %ld\n", decimal);
    smallLine();
}

void Hex_to_Oct(char hex[])
{
    int i, len = 0, num = 0;
    int power = 0;
    long int decimal = 0;
    int rem[100];

    for (i = (int)strlen(hex) - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
            num = hex[i] - '0';
        else if (hex[i] == 'A' || hex[i] == 'a')
            num = 10;
        else if (hex[i] == 'B' || hex[i] == 'b')
            num = 11;
        else if (hex[i] == 'C' || hex[i] == 'c')
            num = 12;
        else if (hex[i] == 'D' || hex[i] == 'd')
            num = 13;
        else if (hex[i] == 'E' || hex[i] == 'e')
            num = 14;
        else if (hex[i] == 'F' || hex[i] == 'f')
            num = 15;

        decimal = decimal + num * (long int)pow(16, power);
        power++;
    }

    if (decimal == 0)
    {
        resultLine();
        printf("  RESULT\n");
        printf("  Equivalent Octal Number : 0\n");
        smallLine();
        return;
    }

    i = 0;
    len = 0;

    while (decimal != 0)
    {
        rem[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
        len++;
    }

    resultLine();
    printf("  RESULT\n");
    printf("  Equivalent Octal Number : ");

    for (i = len - 1; i >= 0; i--)
        printf("%d", rem[i]);

    printf("\n");
    smallLine();
}
