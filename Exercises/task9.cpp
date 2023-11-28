#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& array){
    if(array.empty()){
        return 0;
    }
    int maxSum = array[0];
    int currentSum = array[0];

    for (int i = 1; i < array.size(); i++){
        currentSum = std::max(array[i], currentSum + array[i]);
        maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
}


void print(std::vector<int>& arr){
     for(int num : arr){
        std::cout << num << " ";
     }
     std::cout << std::endl;
}
int main(){
    std::vector<int> array = {-2, 1, -3, 4, -1};
    std::cout << "The given array is :";
    print(array);
     
    std::cout << "The maximum Sum is :" << maxSubArray(array);

}