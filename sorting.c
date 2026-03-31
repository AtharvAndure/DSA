//insertion sort program
#include<stdio.h>
int main(){
    int arr[]={5,5,5,4,4,3,2,1};
    int uniq[sizeof(arr)/sizeof(arr[0])];
    int size=8,key;

    for(int i=1;i<size;i++){
        key=uniq[i];
        int j=i-1;
        while(j>=0&&uniq[j]>key){
            arr[j+1]=uniq[j];
            j--;
        }
        uniq[j+1]=key;
    }
    for(int i=0;i<size;i++){
        printf("%d ",uniq[i]);
    }

    return 0;
}