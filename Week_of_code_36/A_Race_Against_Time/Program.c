#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int raceAgainstTime(long int n, long int mason_height, long int heights_size, long int* heights, long int prices_size, long int* prices) {
    long int *costCaused = malloc(sizeof(long int) * n+1),i,j,temp1,temp2;
    costCaused[0] = 0;
    for(i=1;i<=n;i++)
        costCaused[i] = INT_MAX;
    //travel(0,-1,mason_height,heights_size,heights,prices,0,answers);
    long int curHeight,curPrice;
    for(i=-1;i<heights_size;i++) {
        if(i==-1){
            curHeight = mason_height;
            curPrice = 0;
        } else {
            curHeight = heights[i];
            curPrice = prices[i];
        }
        //printf("From %ld costCaused = %ld\n",i,costCaused[i+1]);
        j = i+1;
        while(j<heights_size) {
            temp1 = abs(heights[j]-curHeight) + (j-i) + prices[j] + costCaused[i+1];
            //printf("<%ld> Temp1 = %ld ",j,temp1);
            //printf("\t (%ld < %ld)  ",temp1,costCaused[j+1]);
            if(temp1 < costCaused[j+1]) {
                //printf("<<Assigning value>from %ld to %ld>",costCaused[j+1],temp1);
                costCaused[j+1] = temp1;
            }
            //printf("\n");
            if(heights[j] > curHeight) {                
                break;
            }
            j++;
        }
        if(j == heights_size) {
            temp1 = (j-i) + costCaused[i+1];
            if(temp1 < costCaused[j+1]) {
                //printf("<<Last>from %ld to %ld>\n",costCaused[j+1],temp1);
                costCaused[j+1] = temp1;
            }
        }
        
    }        
    return costCaused[n];
    // Complete this function
}

int main() {
    long int n; 
    scanf("%ld", &n);
    long int mason_height; 
    scanf("%ld", &mason_height);
    long int *heights = malloc(sizeof(long int) * n-1);
    for (long int heights_i = 0; heights_i < n-1; heights_i++) {
       scanf("%ld",&heights[heights_i]);
    }
    long int *prices = malloc(sizeof(long int) * n-1);
    for (long int prices_i = 0; prices_i < n-1; prices_i++) {
       scanf("%ld",&prices[prices_i]);
    }
    long int result = raceAgainstTime(n, mason_height, n-1, heights, n-1, prices);
    printf("%ld\n", result);
    return 0;
}
