 #include <iostream>

//void mult(int *A, int m, int n, int *B, int k, int l){
/*void mult(int n, int m, int k, int l, int A[], int B[]){
	int C[n][l];

	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){
			for(int h=0;h<m;h++){
				C[i][j]+=A[i][h]*B[h][j]; 
			}
		}
	}
	
	for(int i=0;i<k;i++){
		for(int j=0;j<l;j++){	
		std::cout<<C[i][j]<< std::endl;
		}
	}
}*/

int main(){
	int n,m,k,l,i,j;

	//enter the FIRST matrix;
	std::cout<<"Enter the first matrix:"<<std::endl;
	std::cout << "enter n:" << std::endl;
	std::cin >> n;
	std::cout << "enter m:" << std::endl;
        std::cin >> m;
	int arr1[n][m];
	std::cout << "enter numbers:" << std::endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			std::cin >> arr1[i][j];
		}
	}
	std::cout<<"\nthe first matrix is:"<<std::endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){	
		std::cout<<arr1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	//enter the SECOND matrix;
	std::cout<<"\nEnter the second matrix:"<<std::endl;
	std::cout << "enter k:" << std::endl;
        std::cin >> k;
		if(k!=m){
			std::cout<<"k must be equal to  n. Enter again!"<<std::endl;
			std::cin>>k;
		}
        std::cout << "enter l:" << std::endl;
        std::cin >> l;
        int arr2[k][l];
	std::cout << "enter numbers:" << std::endl;
	for(int i=0;i<k;i++){
		for(int j=0;j<l;j++){
			std::cin >> arr2[i][j];
		}
	}
	std::cout<<"\nthe second matrix is:"<<std::endl;
	for(int i=0;i<k;i++){
		for(int j=0;j<l;j++){	
		std::cout<<arr2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	//MULTIPLY matrixs;
	int C[n][l];
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){
			C[i][j]=0;
			for(int h=0;h<m;h++){
				C[i][j]+=arr1[i][h]*arr2[h][j]; 
			}
		}
	}
	std::cout<<"\nthe multipy matrix is:"<<std::endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){	
		std::cout<<C[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	//mult(n, m, k, l, arr1, arr2);
	//mult((int*)arr1, n, m,  (int*)arr2, k, l);
		
		return 0;
}















