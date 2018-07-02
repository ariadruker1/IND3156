# IND3156
Computer Programming Block 2 Summer 2018

Using what we learned about binary being 1's and 0's in different powers of base 2 locations I will be looking at scores in order to know information. For C language I will be looking at knowing where students applied.

I found [here](https://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html) that in c I am able to use 0b as code for assigning values in binary. 

below is my experimentation with printing in binary:
``` c 
#include <stdio.h>

int main(void) {
    int i, b;
    i = 0b101010;
    b = 0b011;
    printf("i = %d \n", i);
    printf("b = %d \n", b);
    return 0;
}
```
my output was : i = 42 b = 3

### appplication to project

To then apply it to my problem I began to think of binary formating where if given a score I could extract information. Below is where Oxford = 1 Camebridge = 2 and Caltech = 3. 

Binary      8   4   2   1
Oxford      0   0   0   1
Camebridge  0   0   1   0
Caltech     0   0   1   1

I realized in order to ensure accuracy of information that I was concluding I would have to change my number distribution. I would have to have only 1 school be represented by each base 2. Say a student had a score of 3, the computer would not know if he had applied to both Oxford and Camedridge or if he had only applied to Caltech. Going forward I can only assign 1 base per university. There will only be one 1 and the rest zeros in order to code for each university, this is to ensure unique codes for each university and each comination of universities.

``` c
int main(void) {
    int Oxford, Camebridge, Caltech;
    Oxford = 0b1;
    Camebridge = 0b010;
    Caltech = 0b100;
    printf("Oxford = %d \n", Oxford);
    printf("Camebridge = %d \n", Camebridge);
    printf("Caltech = %d \n", Caltech);
    return 0;
}
```
### Accepting and reading values from command line

Next I wanted to be able to input scores from the command line to know where students applied. Looking to our [Monte Carlo](http://10.0.161.51/Su18B2/index.php/Monte_Carlo_integrator) for inspiration as to how 

``` c
#include <stdio.h>

int main(int argc, char *argv[]){
    int Oxford, Camebridge, Caltech, arg1;
    Oxford = 0b1;
    Camebridge = 0b010;
    Caltech = 0b100;
    sscanf(argv[1], "%d", &arg1);
    if (arg1 == Oxford) {
        printf("Oxford \n");
        return 0;
    }
    if (arg1 == Camebridge) {
        printf("Camebridge \n");
        return 0;
    }
    if (arg1 == Caltech) {
        printf("Caltech \n");
        return 0;
    }
    else
    printf("Oxford = %d \n", Oxford);
    printf("Camebridge = %d \n", Camebridge);
    printf("Caltech = %d \n", Caltech);
    return 0;
}
```
Finally I wanted to be able to have cominations of schools, so I added another condition that was an example.

``` c
    if (arg1 == (Oxford + Camebridge)) {
        printf("Oxford and Camebridge \n");
        return 0;
    }
```
### My final [code](https://github.com/ariadruker1/IND3156/blob/master/application.c):
``` c
#include <stdio.h>

int main(int argc, char *argv[]){
    int Oxford, Camebridge, Caltech, arg1;
    Oxford = 0b1;
    Camebridge = 0b010;
    Caltech = 0b100;
    sscanf(argv[1], "%d", &arg1);
    if (arg1 == Oxford) {
        printf("Oxford \n");
        return 0;
    }
    if (arg1 == Camebridge) {
        printf("Camebridge \n");
        return 0;
    }
    if (arg1 == Caltech) {
        printf("Caltech \n");
        return 0;
    }
    if (arg1 == (Oxford + Camebridge)) {
        printf("Oxford and Camebridge \n");
        return 0;
    }
    if (arg1 == (Oxford + Caltech)) {
        printf("Oxford and Caltech \n");
        return 0;
    }
    if (arg1 == (Camebridge + Caltech)) {
        printf("Caltech and Camebridge\n");
        return 0;
    }
    if (arg1 == (Camebridge + Caltech + Oxford)) {
        printf("Oxfortd, Caltech and Camebridge\n");
        return 0;
    }
    else {
        printf("Oxford = %d \n", Oxford);
        printf("Camebridge = %d \n", Camebridge);
        printf("Caltech = %d \n", Caltech);
        return 0;
    }
}
```
where at the command line 
command line:   ./a.out 1;  ./a.out 2;  ./a.out 3;              ./a.out 4   ./a.out 5           ./a.out 6
returned:       Oxford ;    Camebridge  Oxford and Camebridge   Caltech     Oxford and Caltech  Caltech and Camebridge

and ./a.out 7
Oxfortd, Caltech and Camebridge

The next possible integer being ./a.out 8 would mean we added the 1000 binary code and would therefore have to add another column of 1/0 options. This would allow us to then go up to ./a.out 15 before having to add another 1/0 to the 16 column of binary code.  

# Change Log


### Going forward
My final thoughts going forward are wondering if I would have to input every possible combinations score, or if there is a way the program could recognize the value of each schoool and know which values/schools sums would equal the value of arg 1 since there would only be 1 correct answer from the binary values. 

