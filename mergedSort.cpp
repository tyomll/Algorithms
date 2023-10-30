#include <iostream>

void merge (int array[], int const left , int const mid , int const right   ) {

int sizeOfLeftArr = mid - left +1;
int sizeOfRightArr = right - mid  ;


int * leftArr = new int [sizeOfLeftArr] ;
int * rightArr = new int [sizeOfRightArr] ;


for (int i = 0  ; i < sizeOfLeftArr ; i++ ) {
                leftArr[i] = array[left + i ] ;

      }
for (int j = 0 ; j < sizeOfRightArr ; j++ ) {
                rightArr[j] = array[right + j + 1 ]  ;
}



int indexOfLeftArr =0 , indexOfRightArr = 0 , indexOfMergedArr = left ;


while (indexOfLeftArr < sizeOfLeftArr && indexOfRightArr < sizeOfRightArr ) {

if (leftArr[indexOfLeftArr] <= rightArr[indexOfRightArr]) {
    array[indexOfMergedArr] = leftArr[indexOfLeftArr] ;
    indexOfLeftArr++ ;

} else {
 array[indexOfMergedArr] = rightArr[indexOfRightArr] ;
 indexOfRightArr++ ;


}

}

delete [] leftArr ;
delete [] rightArr ;

}

void mergedSort(int array[]  , int begin , int end ) {
 int mid   begin + ( end  - begin) /2  ;
 mergedSort(array , begin ,mid ) ;
 mergedSort(array , mid + 1 ; end) ;
merge(array , begin , mid  , end )


}
 ;
void print (int array[] , int size ) {
for (int i = 0 ; i < size ; i++ ) {
        std::cout<< array[i]<< " , " ;
}
std::cout<<std::endl ;
}
int main () {

int arr[] = {4,2,9,5,1,7,3} ;

int size  = sizeof(arr) / sizeof(int) ;
print(arr, size) ;
mergedSort(arr , 0 , size ) ;
print(arr , size) ;



}
~   
