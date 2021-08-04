#include <cstddef>
#include <initializer_list>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T>
void printFunc(const vector<T>& arr){
	for(const T &x: arr)
		cout<<x<<" ";
	cout<<endl;
}

template<typename T>
void generatePerm(size_t n, vector<T> arr){
	vector<unsigned> c(n,0);
	printFunc(arr);
	size_t i = 0;
	while(i<n){
		if(c[i]<i){
			if(i%2==0)
				swap(arr[0],arr[i]);
			else
				swap(arr[c[i]],arr[i]);
			printFunc(arr);
			c[i]++;
			i=0;
		}else{
			c[i]=0;
			i++;
		}
	}
}

template<typename T>
void generatePerm(size_t n, const initializer_list<T> &a){
	generatePerm(n,vector<T>{a});
}

int main(){
	string str;
	cout<<"Enter the string to permute: "<< endl;
	cin>>str;
	vector<char> arr;
	arr.insert(arr.end(),str.begin(),str.end());
	generatePerm(arr.size(),arr);
}
