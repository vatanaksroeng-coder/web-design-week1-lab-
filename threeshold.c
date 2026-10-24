#include<stdio.h>
int  countAboveThreshold(int grades[], int size , int threshold) {
    int countn =0;
    for(int i=0;i<size;i++){
        if(grades[i]>threshold){
            countn++;
        }
    }
    return countn;6
}