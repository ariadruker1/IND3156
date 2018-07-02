# IND3156
Computer Programming Block 2 Summer 2018

I have decided to switch to the Gale Shapely matching problem. Where I will be trying to match different medical school's top choices of students for their residency opportunity with different students and their top choices of medical school residencies. 

I will be starting this code in C language.
The first step will be creating a random order of preferences for however many students and residencies.
I found a code online where I could get random digits: https://stackoverflow.com/questions/44187061/how-to-shuffle-an-array-in-c
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
I would want to get my program to the stage of accepting the amount of random digits (being 'n' the amount of students and the amount of residencies) to be given at the command line. This is the code that I reworked to try and give me a random order of numbers between 0 and the n given amount. THe key in this problem is having the same amount of med students as residency positions, so it is a matter of ranking preferences of number that can correspond to the partner. Having student [0] (student #1) have their preferences be: n-4, n-1, n, n-2,n-3... until n amount of terms (residency positions) then we see the preference in comparison to a corresponding list.

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

My goal would be to have s[n] which is equal to r[n] have n come from the command line, randomize the order of numbers from 0--> n.
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

When trying to compile I get a 'segmentation fault 11:' which from what I can tell means that somewhere in my program I am taking a lot of space. As I am only begining this project, the above is my goal, and so for right now I am assigning the amount of residencies/students and am manually inputting their number preferences. 
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

This problem exists because as seen above, Aaron's top pick will be r1, which is Boston University, and Boston University's top pick will be s3, Dan.  

The next stage is the application and acceptance process.
The students will apply to their top choice first. The residency's will accept the lowest possible n in their array choices of r[n]. The lower the n value, the higher the pick the student is for that residency position and vice versa. 

The first round of proposals will be the student going to their number one choice. To know which school that is, we have to look at their s[0] value. for s0[0] the value is 1. This means I would want to try and pair r1 with s0[0]. 

I tried creating a function at the bottom that would look at the values within the array and match it to the other array. My problem is that I'm not able to get the names of the numbers in the array be seen as digits, they are only part of the name. So the (num) value is not replacing the digit in res in order to find the first choice of the student.
```
int pairing(int student[], int res0[], int res1[])
    num = student[0]
    int pair[] = {student[], res(num))}
    printf("\n pair     = %d\n", pair[];
}
```
I really struggled getting the program to read values and be able to draw comparisons or find answers within data so I tried coming up with matrix's:

Students matrix:                          Residence matrix:
Aaron   0  0 1 2 3 4;                    Alabama     0  2 3 4 1 2;
Byron   1  2 3 1 4 0;                    Boston      1  3 1 4 2 0;
Cyndi   2  0 1 3 2 4;                    Cornell     2  0 2 1 3 4;
Dan     3  1 3 2 4 0;                    Dartmouth   3  4 1 0 2 3;
Ellen   4  3 2 4 0 1;                    Edinburgh   4  1 0 3 2 4;

I would have use the (1,:) column in both matrix's as the reference to the name have it be the reference for the other matrix. The matrix numbers beyond the first column would have their preferences listed, the number alligning to the other matrix (Alabama would be 0 in the student matrix and would be Cindi and Aaron's first choices, Cindi would be shown by the number 2 in the preferences list of the residence matrix, and Aaron by 0 in the residence matrix. Alamba's first choice would have been Cindi as well and that would have been a stable match. Cornell's first choice would have been Aaron, but Cornell was Aaron's third choice.)

I'm having a really hard time getting the students preferences be able to pair with the resicency options. I would still ahve to, once paired, have hte residences then evaluate if they got their first choice, and who they should propose acceptance to that is their top choice. The different rounds and evaluating which is best for both parties is proving to hard for me in terms of programming.

I am shifting my focus to reverse engineering of where students applied to. Using what we learned about binary being 1's and 0's in different powers of base 2 locations I will be looking at and creating scores for students to tell where they applied.

Say:
Alabama     = 2
Berkley     = 4
Cornell     = 8
Dartmouth   = 16
Edinburgh   = 32

I will start by creating data for different students and their scores and try and use a program to tell me where they applied.


