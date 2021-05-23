#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool balance(string s){
	int size = s.length();
	bool ans = true;
	stack<char> st;
	
	for(int i=0; i<size; i++){
		if(s[i]=='[' or s[i]=='(' or s[i]=='{'){
			st.push(s[i]);
		}
		else if( s[i]==']'){
			if(!st.empty() and st.top() == '['){
				st.pop();
			}
			else{
				ans = false;
				break;
			}
		}
		else if(s[i]==')'){
			if(!st.empty() and st.top() == '('){
				st.pop();
			}
			else{
				ans = false;
				break;
			}
		}
		else if(s[i]=='}'){
			if(!st.empty() and st.top() == '{'){
				st.pop();
			}
			else{
				ans = false;
				break;
			}
		}
	}
	if(!st.empty()){
		return false;
	}
	else{
		return ans;
	}
}

int main(){
	string s;
	getline(cin,s);

	if(balance(s)){
		cout<<"Balanced Parenthesis";
	}
	else{
		cout<<"Non Balanced Parenthesis";
	}
	return 0;
}
