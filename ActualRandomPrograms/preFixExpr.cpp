#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template <typename T>
class Stack {
    int MAX_SIZE;
    int stackptr;
    T * arr;
public:
    Stack(){
        MAX_SIZE = 500;
        arr = new T[MAX_SIZE];
        stackptr = 0;
    }
	void print(){
		if(stackptr==0){
			cout<<"Empty Stack    "<<endl;
			return;
		}
		cout<<"Stack content: ";
		for(int i=0;i<stackptr;i++)
			cout<<arr[i]<<" ";
		cout<<endl;

	}
    void push(T x){
        arr[stackptr] = x;
        stackptr++;
    }
    void pop(){
        stackptr--;
    }
    T peek(){
        return arr[stackptr-1];
    }
    bool empty(){
        return stackptr == 0;
    }
   ~Stack(){
       delete [] arr;
   }
};

int power(int a, int b)
{
    int ans = 1, x = a;
    while (b > 0) {
        if (b&1) {
            ans = (ans * x);
        }
        x=(x*x);
        b >>= 1;
    }
    return ans;
}

bool isASymbol(string c){
	string arr[]={"^","+","-","/","*"};
	int size= 5;
	for(int i=0;i<size;i++){
		if(c==arr[i])
			return true;
	}
	return false;
}

bool isASymbol(char c){
	char arr[]={'^','+','-','/','*'};
	int size= 5;
	for(int i=0;i<size;i++){
		if(c==arr[i])
			return true;
	}
	return false;
}
int get_precedence(string c){
    if(c == "^")
        return 3;
    else if(c == "*"|| c =="/")
        return 2;
    else if(c == "+"|| c =="-")
        return 1;
    else
        return -1;
}

vector<string> tokenize(string expr){
	vector<string> tokens;
	string str="";
	for(int i=0;i<expr.size();i++){
		if(expr[i]=='(' or expr[i] ==')' ||  isASymbol(expr[i])){
			str+=expr[i];
			tokens.push_back(str);
			str="";
			continue;
		}else if(isdigit(expr[i])){
			while(i<expr.size()&& isdigit(expr[i])){
				str+=expr[i++];
			}
			tokens.push_back(str);
			str="";
			i--;
		}else if(isalpha(expr[i])){
			while(i<expr.size() && isalpha(expr[i])){
				str.push_back(expr[i++]);
			}
			tokens.push_back(str);
			str="";
			i--;
		}
		else if(expr[i]==' ')
			continue;
		else{
			cout<<"Not a number or /,-,+,*,),("<<endl;
			throw "Invalid token";
		}
	}
	return tokens;
}

void printVec(const vector<string> & a){
	if(a.size()==0){
		cout<<"Empty     "<<endl;
		return;
	}
	cout<<"Output content: ";
	for(auto x: a)
		cout<< x << " ";
	cout<<endl;
	cout<<endl;
	cout<<endl;
}

vector<string> reverse_prefix(vector<string> exp){
    Stack<string> stack;
	vector<string> out;
    int len = (int)exp.size();
    for(int i = 0; i < len; i++){
		cout<<exp[i]<<endl;
        if(! isASymbol(exp[i]) && exp[i]!="(" && exp[i]!=")"){
			out.push_back(exp[i]);
        } else if(exp[i] == "("){
            stack.push("(");
        } else if(exp[i] == ")"){
            while (!stack.empty() and stack.peek() != "(") {
                out.push_back(stack.peek());
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.empty() and (get_precedence(stack.peek()) > get_precedence(exp[i]))) {
                out.push_back(stack.peek());
                stack.pop();
            }
            stack.push(exp[i]);
        }
		stack.print();
		printVec(out);
    }
    while(!stack.empty()){
        out.push_back(stack.peek());
        stack.pop();
		stack.print();
		printVec(out);
    }
    return out;
}

vector<string> reverse_string(vector<string> exp){
    reverse(exp.begin(), exp.end());
    for(auto &c : exp){
        if (c == "(") {
            c = ")";
        } else if(c == ")"){
            c = "(";
        }
    }
    return exp;
}

double evaluate_prefix(vector<string> exp){
    Stack<double> val;
    int len = (int)exp.size();
    for(int i=len-1;i>=0;i--){
        if(! isASymbol(exp[i])){
            val.push(stoi(exp[i]));
        } else {
            double val1 = val.peek();
            val.pop();
            double val2 = val.peek();
            val.pop();
            switch (exp[i][0]) {
                case '+':
                    val.push(val1 + val2);
                    break;
                case '-':
                    val.push(val1 - val2);
                    break;
                case '*':
                    val.push(val1 * val2);
                    break;
                case '/':
                    val.push(val1 / val2);
                    break;
                case '^':
                    val.push((int) power(val1 , val2));
            }
        }
    }
    return val.peek();
}
int main()
{
    string exp;
//	exp = "2+3-4*5+(6^2)*8/9/10*4+5";
	getline(cin,exp);
	vector<string> tmp = tokenize(exp);
    vector<string> temp = reverse_string(tmp);
	cout<<"Reversed Vector: ";
	for(auto x: temp)
		cout<<x<<" ";
	cout<<endl<<endl;
	cout<<endl;
	vector<string> out = reverse_prefix(temp);

    reverse(out.begin(), out.end());
	
	cout<<endl<<"After reversing reverse prefix"<<endl;
	for(const auto & a: out)
		cout<<a<<" ";
	cout<<endl;
   // cout<<evaluate_prefix(out)<<endl;
    return 0;
}
