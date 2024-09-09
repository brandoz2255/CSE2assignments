#include <stdio.h>


void magicSquare(int n) {


    int magic[n][n];
    int i = n / 2;
    int j = n - 1;
    int num = 1;


    for (int k = 0; k < n * n; k++) {

        magic[i][j] = num;
        num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (magic[newi][newj]) {
            i++;
        } else {
            i = newi;
            j = newj;
        }

    }



    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            printf("%3d ", magic[i][j]);
        }
        printf("\n");
    }

}



int main() {

    int n;
    printf("Enter the size of the magic square: ");
    scanf("%d", &n);
    magicSquare(n);
    return 0;

}