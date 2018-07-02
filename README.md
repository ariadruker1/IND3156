# IND3156
Computer Programming Block 2 Summer 2018

I wanted to play around with different ways of matching different entities. I wanted to try doing the Gale Shapely matching problem. 

In the problem I will be trying to match different students and their top choices of medical school residencies with the medical school's top choices of students for their residency program. 

I will be programming in the language C.
The first step will be creating a random order of preferences for however many students and residencies.
This code I found online shows a way that I can shuffle the vlaues in arrrays: https://stackoverflow.com/questions/44187061/how-to-shuffle-an-array-in-c

``` c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

#define N 6

int main() {
    int positions[N] = {0, 1, 2, 3, 4, 5};

    for (int j = 0; j < 10; j++) {
        shuffle(positions, N);
        for (int x = 0; x < N; x++) printf("%d ", positions[x]);
        printf("\n");
    }

    return 0;
}
```
I would want to get my program to the stage of accepting the amount of random digits (being 'n' the amount of students and residencies) to be given at the command line. This is the code that I reworked to try and give me a random order of numbers between 0 and the n given amount. For this problem there must be the same amount of med students as residency positions, so it is a matter of ranking preferences. I plane to do the ranking by assinging numbered names to correspond between students and residencies. Having student [0] (student #1) have their preferences be: n-4, n-1, n, n-2, n-3... (until n amount of terms -residency positions) then we see the preference by looking for the corresponding number to residencies. In the case below the n=4 and is starting at 0.

Say the students were:
s0 = Aaron
s1 = Byron
s2 = Cindy
s3 = Dan
s4 = Elen
and 
r0 = Alabama State University
r1 = Boston University
r2 = Cornell University
r3 = Dartmouth University
r4 = Edinburgh University

My goal would be to have n amount of elements determined at the command line, and then be able to randomize the order of numbers from 0--> n for every given student and residency - the order being their preference.
The code so far that I could rework it:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

int main(int argc, char *argv[]) {
    int arg1, N;
    sscanf(argv[1], "%d", &arg1);
    N = arg1;
    int positions[N];
    
    for (int j = 0; j < 1; j++) {
        shuffle(positions, N);
        for (int x = 0; x < N; x++) printf("%d ", positions[x]);
        printf("\n");
    }
    
    return 0;
}
```

When trying to compile the code however, I get a 'segmentation fault 11:' which from what I can tell means that somewhere in my program I am taking a lot of space. As I am only begining this project, the above is my goal, and so for right now, to keep working on this project I will just assigning the amount of residencies/students and will manually input the preferences. 

``` c
#include <stdio.h>
int main (void) {
    int s0[] = {1,3,4,0,2};
    int s1[] = {3,0,1,2,4};
    int r0[] = {0,1,2,3,4};
    int r1[] = {3,2,1,4,0};
    printf("\n s0[0]    = %d\n",s0[0]);
    printf("\n s1[0]    = %d\n",s1[0]);
    printf("\n r0[0]    = %d\n",r0[0]);
    printf("\n r1[0]    = %d\n\n",r1[0]);
    printf("\n s0[1]    = %d\n",s0[1]);
    printf("\n s1[1]    = %d\n",s1[1]);
    printf("\n r0[1]    = %d\n",r0[1]);
    printf("\n r1[1]    = %d\n",r1[1]);
    
    return 0;
}
```
The Output is: 

 s0[0]    = 1

 s1[0]    = 3

 r0[0]    = 0

 r1[0]    = 3


 s0[1]    = 3

 s1[1]    = 0

 r0[1]    = 1

 r1[1]    = 2
 
Above shows my defining of integer arrays for students 0 and 1. I will be using the order of numbers in the array as each entity's preferences for the corresponding type. 

This problem exists because as seen above, Aaron's top pick will be r1, which is Boston University, and Boston University's top pick will be s3, which is Dan.  

The next stage is the application and acceptance process.
The students will apply to their top choice residency first. The residency's will accept the lowest possible n in their array choices of r[n]. The lower the n value, the higher the pick the student is for that residency position and vice versa. 

The first round of proposals will be the student going to their number one choice. To know which school that is, we have to look at their s[0] value. for s0[0] the value is 1. This means I would want to try and pair r1 with s0[0]. 

I tried creating a function that would look at the values within the array and match it to the other array. My problem is that I'm not able to get the names of the numbers in the array be seen as digits, they are only part of the name. So the (num) value is not replacing the digit in res in order to find the first choice of the student.
``` c
int pairing(int student[], int res0[], int res1[])
    num = student[0]
    int pair[] = {student[], res(num))}
    printf("\n pair     = %d\n", pair[];
}
```
I really struggled getting the program to read values and be able to draw comparisons or find answers within data so I tried coming up with matrix's:

Students matrix:                         Residence matrix:  
 Aaron   0   0 1 2 3 4                    Alabama     0   2 3 4 1 2;  
 Byron   1   2 3 1 4 0                    Boston      1   3 1 4 2 0;  
 Cyndi   2   0 1 3 2 4                    Cornell     2   0 2 1 3 4;  
 Dan     3   1 3 2 4 0                    Dartmouth   3   4 1 0 2 3;  
 Ellen   4   3 2 4 0 1                    Edinburgh   4   1 0 3 2 4;  

I would have used the (1,:) column in both matrix's as the reference to the name have it be the reference for the other matrix. The matrix numbers beyond the first column would have their preferences listed, the number alligning to the other matrix (Alabama would be 0 in the student matrix and would be Cindi and Aaron's first choices, Cindi would be shown by the number 2 in the preferences list of the residence matrix, and Aaron by 0 in the residence matrix. Alamba's first choice would have been Cindi as well and that would have been a stable match. Cornell's first choice would have been Aaron, but Cornell was Aaron's third choice.)

I could not get the students preferences be able to pair with the resicency options. Once paired, I would still have to have the residences then evaluate if they got their first choice, and who they should propose/acceptance to that is their top stable choice. The different rounds and evaluating which is best for both parties is proving too hard for me in terms of programming.

I am shifting my focus to reverse engineering where students applied to. Using what we learned about binary being 1's and 0's in different powers of base 2 locations I will be looking at scores for students to tell where they applied.

I found from : https://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html
That in c I am able to use 0b as code for assigning values in binary.

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

To then apply it to my problem I began to think of binary formating

Binary      8   4   2   1
Oxford      0   0   0   1
Camebridge  0   0   1   0
Caltech     0   0   1   1

I realized in order to ensure accuracy I would have to have only 1 school be represented by each base 2. Say Aaron had a score of 3, the computer would not know if he had applied to both Oxford and Camedridge or if he had onl applied to Caltech. Going forward I can only assign 1 base per university.

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
Next I wanted to be able to take scores from the command line to know where people applied

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
My final code being:
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

The next possible integer being ./a.out 8 would mean we added 1000 binary wise we would have added another column. This would allow us to then go up to ./a.out 15 before having to add another 1 to the 16 column of binary code.  

My final thoughts going forward are wondering if I would have to input every answer option or if there is a way I could have arg 1 = what combination of schools and have the program recognize the value of each schoool and know which values/schools sums to equal the value of arg 1.

