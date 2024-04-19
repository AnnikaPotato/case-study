#include <stdio.h>

int weights[5] = {0, 0, 0, 0, 0};
int pcount[5] = {0, 0, 0, 0, 0};
int totalcount = 0;

void backtrack(int ptr, int remains, int matrix[6][5]);

int main(){
    static int EU[6][5] = {
        {96, 0, 100, 97, 22},
        {100, 73, 100, 100, 0},
        {82, 100, 7, 45, 100},
        {83, 100, 83, 100, 68},
        {100, 0, 50, 100, 50},
        {67, 50, 83, 67, 87}
    };

    backtrack(0, 100, EU);

    for (int i = 0; i < 5; i++){
        printf("%d\t%d\t%f\n", i, pcount[i], (double) pcount[i]/totalcount);
    }
    printf("Total count: %d\n", totalcount);
    return 0;
}

void backtrack(int ptr, int remains, int matrix[6][5]){
    if (ptr == 5){
        totalcount++;
        int t1 = 0;
        int t2 = 0;

        for (int i = 0; i < 5; i++){
            weights[i] += remains * matrix[ptr][i];
            if (weights[i] > t1){
                int temp = t1;
                t1 = weights[i];
                t2 = temp;
            }
            else if (weights[i] > t2){
                t2 = weights[i];
            }
        }

        for (int i = 0; i < 5; i++){
            if (weights[i] >= t2){
                pcount[i]++;            
            }
        }

        for (int i = 0; i < 5; i++){
            weights[i] -= remains * matrix[ptr][i];
        }

    }

    else {
        for (int i = 0; i <= remains; i++){
            for (int j = 0; j < 5; j++){
                weights[j] += i * matrix[ptr][j];
            }

            backtrack(ptr + 1, remains - i, matrix);

            for (int j = 0; j < 5; j++){
                weights[j] -= i * matrix[ptr][j];
            }
        }

    }

    return;
}