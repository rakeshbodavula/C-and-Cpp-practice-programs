#include<iostream>
#include<vector>
using namespace std;

int main(){
	string arr;
	cout<<"Enter a sequence od parentheses: ";
	cin>>arr;
	int i=0,top=0;
	vector<char> stack;
        while(arr[i]){
		switch(arr[i]){
		case '(':
			stack.push_back(arr[i]);
            top++;
			break;
		case '[':
			stack.push_back(arr[i]);
			top++;
            break;
		case '{':
			stack.push_back(arr[i]);
			top++;
            break;
		case ')':
			if(top<1 || stack[top-1]!='('){
                i=-1;
                goto exit;
            }
			else if(stack[top-1]=='(') stack.pop_back(),top--;
			break;
		case ']':
			if(top<1 || stack[top-1]!='['){
                i=-1;
                goto exit;
            }
			else if(stack[top-1]=='[') stack.pop_back(),top--;
			break;
		case '}':
			if(top<1 || stack[top-1]!='{'){
                i=-1;
                goto exit;
            }
			else if(stack[top-1]=='{') stack.pop_back(),top--;
			break;
		}
		i++;
	}
	exit:
	if(top==0 && i!=-1) cout<<"Valid"<<endl;
	else cout<<"Not Valid"<<endl;
	return 0;
}
