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
I found a code online where I could get random digits, I would want to get my program to the stage of accepting the amount of random digits (being the amount of students and the amount of residencies) to be given at the command line. 
As I am only begining this project, the above is my goal, for right now I am assigning the amount of residencies/students and am manually inputting their number preferences. 
```
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
The Outpu is: 
 s0[0]    = 1

 s1[0]    = 3

 r0[0]    = 0

 r1[0]    = 3


 s0[1]    = 3

 s1[1]    = 0

 r0[1]    = 1

 r1[1]    = 2
 
Above shows my defining of integer arrays for students 1 and 2. I will be using the order of numbers in the array as each entity's preferences for the corresponding type. 

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

This problem exists because as seen above, Aaron's top pick will be r1, which is Boston University, and Boston University's top pick will s3 be Dan.  
