#include <initializer_list>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    unsigned long prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev); // finds the position of delim starting from index prev
        if (pos == string::npos) pos = str.length(); // if no delim found make pos = strlen
        string token = str.substr(prev, pos-prev); // get the substr from prev of length (pos - prev)
        if (!token.empty()) tokens.push_back(token); // if its not an empty string then add it to array
        prev = pos + delim.length(); // change prev value to current pos + length of delimiter
    }
    while (pos < str.length() && prev < str.length()); // we do this until we're within the length of str
    return tokens; // return all the strings as a vector
}


template<typename T>
void generatePerm(int k, vector<T> &arr){
	if(k==1){
		for(const T &x : arr)
			cout<<x<<" ";
		cout<<endl;
	}else{
		generatePerm(k-1,arr);
		for(int i=0; i<k-1; i++){
			if( k%2 == 0)
				swap(arr[i],arr[k-1]);
			else
				swap(arr[0],arr[k-1]);
			generatePerm(k-1,arr);
		}
	}
}
template<typename T>
void generatePerm(int k, initializer_list<T> arr){
	vector<T> x = arr;
	generatePerm(k,x);
}

int main(){
	cout<<"Enter the strings to permute: "<< endl;
	string a;
	getline(cin,a);
	vector<string> arr = split(a," ");
	cout<<endl;
	cout<<"The permutations are:"<<endl;
	generatePerm(arr.size(),arr);

}
