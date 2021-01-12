#include <cctype>
#include<iostream>
#include <unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include <cmath>
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
    T pop(){
        stackptr--;
		return arr[stackptr];
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


bool isASymbol(string c){
	string arr[]={"^","+","-","/","*","%"};
	int size= 6;
	for(int i=0;i<size;i++){
		if(c==arr[i])
			return true;
	}
	return false;
}

bool isASymbol(char c){
	char arr[]={'^','+','-','/','*','%'};
	int size= 6;
	for(int i=0;i<size;i++){
		if(c==arr[i])
			return true;
	}
	return false;
}
int get_precedence(string c){
    if(c == "^")
        return 3;
    else if(c == "*"|| c =="/"|| c=="%")
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
}

vector<string> infix_to_postfix(vector<string> exp){
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
            while (!stack.empty() and (get_precedence(stack.peek()) >= get_precedence(exp[i]))) {
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

// given an operator,left and right operand returns the value
// of the calculation
string ans(string op, string lOperand,string rOperand){
	double a = atof(lOperand.c_str());
	double b = atof(rOperand.c_str());
	double ans;
	if(op=="+" || op=="-"){
		ans = op=="+"? a+b : a-b;
	}else if (op == "*" || op =="/") {
		ans = op=="*" ? a*b : a/b;
	}
	else if(op == "%"){
		ans =  fmod(a,b);
	}
	else{
		ans = pow(a,b);
	}
	return to_string(ans);
}

void evalPost(vector<string> postOrd){
	Stack<string> tmp ;
	for(int i=0;i<postOrd.size();i++){
		if(isASymbol(postOrd[i][0])){
			string r=tmp.pop();
			string l=tmp.pop();
			tmp.push(ans(postOrd[i],l,r));
		}else{
			tmp.push(postOrd[i]);
		}
	}
	cout<<tmp.pop()<<endl;
}


int main()
{
    string exp;
	getline(cin,exp);
//	exp = "(A-(B/C)*D+E) * F % G";
	vector<string> tmp = tokenize(exp);
	vector<string> out = infix_to_postfix(tmp);

	for(const auto & a: out)
		cout<<a<<" ";
	cout<<endl;
	//putting values for A B C D E F G	
//	exp = "(90 - (50/2) * 3 + 1) * 2 % 5";
//	tmp = tokenize(exp);
//	out = infix_to_postfix(tmp);
//	for(const auto & a: out)
//		cout<<a<<" ";
//	cout<<endl;
//
//	evalPost(out);

    return 0;
}
