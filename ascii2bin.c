#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <string.h>
#define byte unsigned char

int main (int argc, char * argv[], char ** envp)
 {

int retval = 1;
int digit;
byte ascii_value;

int offset = 0x30;
int number = 0; //=v

     retval = read(0, &ascii_value, 1);
    while ((retval == 1) && (ascii_value != '\n'))
 {
     digit = ascii_value - offset;
        if (ascii_value != '0' && ascii_value != '1' && ascii_value != '\n')
        {
return 1;
    }
        if ((digit == 1) || (digit == 0))
            number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);}

          if (number > pow(2,32))
 {
    return 1;
 }



    printf("%u\n", number);
    return 0;
}

//https://github.com/Bradx5/ascii2bin
