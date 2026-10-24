#include<stdio.h>
#include<stdbool.h>
int checkUniqueNumbers(int grid[5][5]) {
    int row, col;
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (grid[row][col] < 1 || grid[row][col] > 5 * 5) {
                return 0;
            }
        }
    }
    return 1;
}
int checkMainDiagonal(int grid[5][5]){
    for(int row=0;row<5;row++){
        int sum=0;
        for(int col=0;col<5;col++){
            if(row==col){
                sum+=grid[row][col];
            }
            if(row+col==4){
                sum+=grid[row][col];
            }
        }
    }
}
int checkAllRows(int grid[5][5]){
    for(int row=0;row<5;row++){
        int sum =0;
        for(int col=0;col<5;col++){
            sum+=grid[row][col];
        }
    }
}
int checkAllColumns(int grid[5][5]){
    for(int col=0;col<5;col++){
        int sum=0;
        for(int row=0;row<5;row++){
            sum+=grid[row][col];
        }
    }
}
bool isMagicSquare(int size, int grid[5][5]) {
    return true;
}	 
int main(){
    int square[5][5] = {
        {17, 24, 1, 8, 15},
        {23, 5, 7, 14, 16},
        {4, 6, 13, 20, 22},
        {10, 12, 19, 21, 3},
        {11, 18, 25, 2, 9}
    };

    if (isMagicSquare(5,square)) {
        printf("Valid magic square!\n");
    } else {
        printf("Not a valid magic square.\n");
    }
    return 0;
}
