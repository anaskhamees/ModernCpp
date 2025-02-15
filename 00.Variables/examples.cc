#include<iostream>


int main()
{
	int arr[5]={1,2,3,4,5};
		
	
	for(const int& num: arr)
	{
		num*=2;
		std::cout<<num<<" ";
	}
	
	std::cout<<std::endl;

	
	
	return 0;
}
