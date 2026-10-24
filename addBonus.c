#include<stdio.h>
void addBonus(int grade[],int size,int bonus){
    for(int i=0;i<size;i++){
        grade[i]+=bonus;
    }
}
int main(){
    int grade[5]={90,85,78,92,88};
    int bonus=5;
    addBonus(grade,5,bonus);
    printf("grades after adding bonus:\\n");
    for(int i=0;i<5;i++){
        printf("%d " , grade[i]);
    }
    return 0;
}