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
