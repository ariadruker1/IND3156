# IND3156
Computer Programming Block 2 Summer 2018


```python
a = [1,2,3]
b = (transpose) a
print('a=', a, 'b=', b)
```

I want to look at song lyrics and be able to compare the different scores but am having trouble getting VADER running on my computer. After running line:
```
pip install vaderSentiment
```
I have it on my computer but I keep gettng the error "'encoding' is an invalid keyword argument for this function"

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
 
Above shows my defining of integer arrays for students 1 and 2. I will be using the order of numbers in the array as each entity's preferences for the corresponding type. 


This problem exists because as seen above, Aaron's top pick will be r1, which is Boston University, and Boston University's top pick will s3 be Dan.  

The next stage is the application and acceptance process.
The students will apply to their top choice first. The residency's will accept the lowest possible x in their array choices of r[x]. The earlier in the array, the higher the pick the student is for that residency position. 
