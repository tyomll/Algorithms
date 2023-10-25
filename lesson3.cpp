
#include <iostream>

void sort (int * arr , int size ) {
    int temp ; 
    for (int i = 1  ; i<size; i++) {
        for (int j = i-1; j>= 0 ; j--) {
        while  (*(arr+j) > *(arr+j+1) ) {
             temp = *(arr+j) ; 
             *(arr+j)= *(arr+j+1) ;
             *(arr+j+1) = temp ;  
             
        } 
      }
    }
}
void printArray (int *arr, int size ) {
 for(int  i = 0 ; i < size ; i++ ){
     std::cout<< *(arr + i ) << std::endl ; 
 }   
}




int main() {
int array[] = {11,8,3,7,2,10}; 
int size = sizeof(array) / sizeof(int) ; 

sort(array , size ) ;
printArray(array , size) ; 
    return 0;
}
