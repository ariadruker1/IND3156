#include <stdio.h>

int main(int argc, char *argv[]){
    int Oxford, Cambridge, Caltech, arg1, remainder, check, failsafe;
    Oxford = 0b1;
    Cambridge = 0b010;
    Caltech = 0b100;
    sscanf(argv[1], "%d", &arg1);
    remainder = arg1-Caltech;
    check = arg1 - Cambridge;
    failsafe = arg1 - Oxford;
    if (remainder >=0) {
        printf("caltech \n");
        if (remainder - Cambridge >=0) {
            printf("Cambridge2 \n");
            if (remainder - Cambridge - Oxford ==0) {
                printf("Oxford3 \n");
                return 0;
            }
            if (remainder - Cambridge - Oxford > 0) {
                printf("too large a number - this is an error! \n");
                printf("retry with integer in range 1-7 \n");
                return 0;
            }
            return 0;
        }
        if (remainder - Oxford >=0) {
            printf("Oxford3 \n");
        }
    return 0;
    }
    if (check >=0) {
        printf("Cambridge1 \n");
        if (check-Oxford>=0) {
            printf("Oxford2 \n");
        }
        return 0;
    }
    if (failsafe ==0) {
        printf("Oxford1 \n");
        return 0;
    }
    if (remainder-Cambridge-Oxford >0) {
        printf("too large \n");
        return 0;
    }
    else {
        printf("Oxford = %d \n", Oxford);
        printf("Cambridge = %d \n", Cambridge);
        printf("Caltech = %d \n", Caltech);
        printf("Please retry entry with ./a.out integer between 1-7 \n");
        return 0;
    }
}
