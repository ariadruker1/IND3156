# IND3156
Computer Programming Block 2 Summer 2018

I wanted to work more with binary in a coded language beyond just discussion, whiteboard or use of the BigDecimal. Using what we learned on the whiteboard about using binary's 1's and 0's in different powers of base 2 locations to relay information. I chose to explore how getting a number can relay information about categories and overlap of categories. I used the C language to explore a way of knowing where students applied for university.

I found [here](https://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html) that in c I am able to use 0b as code for assigning values in binary. 

below is my experimentation with printing and creating values in binary:
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
my output was: i = 42 b = 3

### Appplication to project

To then apply it to my problem of applications, I began to think of binary formatting where if given a score I could extract information. Below is where Oxford = 1 Cambridge = 2 and Caltech = 3. 

Binary      8   4   2   1
Oxford      0   0   0   1
Cambridge  0   0   1   0
Caltech     0   0   1   1

In order to ensure the accuracy of the concluding I was drawing based on the information given in a score, I realized I would have to change my definitions. The universities could not be labeled as 1, 2, 3, 4... they would have to be labeled in base 2 so referred to as 1,2,4,8,16... I would have to have only 1 school be represented by each base 2. This is because for the information obtained to be accurate each combination must be given a unique number. Say a student had an application number of 3, the program would not be able to know if the student had applied to both Oxford and Cambridge or if he had only applied to Caltech. Going forward I can only assign 1 base per university. There will only be one 1 and the rest zeros in order to code for each university, this is to ensure unique codes for each university and each combination of universities.

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

Next, I wanted to be able to input scores from the command line to know where students applied. Looking to our [Monte Carlo](http://10.0.161.51/Su18B2/index.php/Monte_Carlo_integrator) for inspiration as to how to accept arguments I wrote the following where the program scans what I wrote in the command line and stores the integer in the memory address of arg1.

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
Finally I wanted to be able to have cominations of schools, so I added other conditions.

``` c
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
Oxford, Caltech, and Cambridge

The next possible integer being ./a.out 8 would mean we added the 1000 binary code and would, therefore, have to add another column of 1/0 options. This would allow us to then go up to ./a.out 15 before having to add another 1/0 to the 16 column of binary code this is because I put the value of each university in terms of base 2.  

# GO Language Election


# Change Log

### June 30th, 2018
I wanted to use [VADER](https://github.com/ariadruker1/IND3156/blob/master/VADERmanual.py) to look at the positive and negative connotations of song lyrics and then be able to compare different genres. I began [playing around](https://github.com/ariadruker1/IND3156/blob/master/vaderplay.py) with trying to get the program working on the class computers and then switched to my own. My [first commit](https://github.com/ariadruker1/IND3156/commit/a1acced06d1efc88842daa4c17a7b0a9d7e428a6#diff-04c6e90faac2675aa89e2176d2eec7d8) was me trying to get the software working on my computer

After having a lot of trouble trying to get the VADER program imported and have the analysis working I decided to take my work in a different direction. I did a math problem in my Math Through Interesting Problems with Richard Hoshino where we explored the [Gale-Shapley stable matching problem](https://github.com/ariadruker1/IND3156/commit/bdbee5f0a75ca6a0146f5b4c2c94fe30423a7843#diff-04c6e90faac2675aa89e2176d2eec7d8). My goal was to take student's priorities and university priorities into account and create [n amount](https://github.com/ariadruker1/IND3156/blob/master/startofgaleshapely.c) of stable pairing where everyone got their highest possible number. I tried having the program take the amount of university residency opportunities which is equal to the number of students, from the command line. This was proving a lot harder when I had to factor in [shuffling](https://github.com/ariadruker1/IND3156/blob/master/howtoshuffle.c) the order of priorities per student/university. 

### July 1st, 2018
The next stage of the Gale-Shapely was [getting my program to recognize that the earlier in the array the number, the higher the priority to match](https://github.com/ariadruker1/IND3156/commit/2b1d7c9ca069decdacca71234259aeefe6385506#diff-04c6e90faac2675aa89e2176d2eec7d8). 

I really struggled with being able to [pair the universities and students to their desired partner](https://github.com/ariadruker1/IND3156/commit/73f1eb1e3a586d9f0732a38c96484ef6ca417301#diff-04c6e90faac2675aa89e2176d2eec7d8)  and then further struggled with having them recognize if there were 2 possible partners, how to know which one to take. I had a hard time naming the categories as not just numbers, and because there were 2 groups and numbers carry meaning, the program wasn't working. I tried [creating matrix's](https://github.com/ariadruker1/IND3156/commit/2c1150274f9b111f075cfa372c01f98716efba24#diff-04c6e90faac2675aa89e2176d2eec7d8) but that I still had a lot of trouble trying to connect and evaluate pairings.

[At this point I decided to transition my program once again](https://github.com/ariadruker1/IND3156/commit/6a9d7cc9b32d3b4b24eb8aba7808a9cdd826c56a#diff-04c6e90faac2675aa89e2176d2eec7d8).

I learned also that in adding code with the [apostrophe mark,](https://github.com/ariadruker1/IND3156/commit/be9b4bfb815feba5fc8cf780433999414947d5bb#diff-04c6e90faac2675aa89e2176d2eec7d8) I had to add the name of the language in order for the command words to appear special. 

As seen in my README project above, I was able to get a code to function where given a number I was able to know the which statements were made true due to the binary code. I wanted to use some code we'd worked with previously so I added being able to [dictate the number at the command line](https://github.com/ariadruker1/IND3156/commit/5e0c3f2e7df01cfa62050dc6c6921aca982e1193#diff-04c6e90faac2675aa89e2176d2eec7d8). I wanted a problem that could have many facets - this could be used for university applications, grocery shopping, or an efficient way of knowing which people someone voted for in an election, essentially it can be used for any kind of measurement of checked categories and their combinations.  

### July 2nd, 2018
Focussed on editing code and adding more details to text. Heavily edited my changelog, other minor edits can be seen along the way in the [history](https://github.com/ariadruker1/IND3156/commits/master/README.md) of this README page.

### July 3rd, 2018
I've been working on getting GO, the google coding language working. I found [here](https://golang.org/doc/install?download=go1.10.3.darwin-amd64.pkg) how to download and set up the language for my computer. Adam Achs helped show me how to get my different files running in terminal. Adam recomended TextMate and it was a great help, because rather than xcode or just a text editor I have access to writing in hundreds of languages. I then began running 'hello world' code in go, [this website](https://golang.org/#) has both the download and a section to begin playing with a hello world code in go. I began to [learn the different commands and ways to use the go language](https://github.com/ariadruker1/IND3156/blob/master/hellotest.go).

Things I learned: the go language is case sensitive, my program wasn't running initially because the print command wasn't capitalized properly. It also an amazing capacity to be similar to python or to c style languages. It can either be interpreted line by line like python or it can be compiled like c, fortran and java. This can be very helpful because beyond code for myself if I wished to share my program with someone I then have the option of sending them my whole code or I can keep my code and just send the executable. This is also simply decided at the command line which is convenient because it means I do not have to decide at the begining of my project what kind I need it to be. This can is done by writing at the command line either:
```go
$ go run hellotest.go
```
where writing 'run' means it will run similar to python and interpret the code.
Or we could compile the code by using the command:
``` go
go build hellotest.go
```
at the command line. The build call means it will be compiled to create and executable, this is the call similar to javac, gcc, or gfortran. 

Writing my above code.


### Going forward
My final thoughts going forward are wondering if I would have to input every possible combinations score, or if there is a way the program could recognize the value of each school and know which values/schools sums would equal the value of arg 1 since there would only be 1 correct answer from the binary values. 

