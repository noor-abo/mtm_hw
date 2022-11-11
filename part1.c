#include <stdio.h>
#include <stdlib.h>

int readSize(){
    printf("Enter size of input:\n");
    int size;
    if(scanf("%d",&size) != 1)
    {
        return 0;
    }
    return size;
}


int* readNumbers(int size){
    printf("Enter numbers:\n");
    int *arr = malloc(sizeof(*arr)*size);
    if(!arr){
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        if(scanf("%d",arr+i) != 1)
        {
            printf("Invalid number\n");
            free(arr);
            return NULL;
        }
    }
    return arr;
}

void printResults(int* arr, int size){
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        int power = 0;
        int currentNum = arr[i];

        while (currentNum%2 == 0 && currentNum > 1)
        {
            power++;
            currentNum/= 2;
        }
        if (currentNum == 1)
        {
            printf("The number %d is a power of 2: %d = 2^%d\n",arr[i],arr[i], power);
            sum += power;
        }
    }
    printf("Total exponent sum is %d\n",sum);
}

int main() {
    int size = readSize();
    if (size < 1){
        printf("Invalid size\n");
        return 0;
    }
    int *arr = readNumbers(size);
    if(!arr){
        return 0;
    }
    printResults(arr,size);
    free(arr);
    return 0;
}
