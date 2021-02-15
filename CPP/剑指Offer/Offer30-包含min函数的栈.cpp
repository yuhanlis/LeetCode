#include <iostream>
#include <deque>
using namespace std;
class MinStack{
	public:
		MinStack(){

		};
		void push(int x){
			st[++topptr]=x;
			if(minque.empty()) minque.push_front(x);
			if(x<=minque.front()) minque.push_front(x);
		};
		void pop(){
			if(topptr==-1)return;
			if(st[topptr]==minque.front()) minque.pop_front();
			topptr--;
		};
		int top(){
			if(topptr==-1) return -1;
			return st[topptr];
		};
		int min(){
			return minque.front();
		};
	private:
		int st[20000];
		int topptr=-1;
		deque<int> minque;
};
int main()
{
	MinStack a;
	a.push(2147483646);
	a.push(2147483646);
	a.push(2147483647);
	cout<<a.top()<<endl;
	a.pop();
	cout<<a.min()<<endl;
	a.pop();
	cout<<a.min()<<endl;
	a.pop();
	a.push(2147483647);
	cout<<a.top()<<endl;
	cout<<a.min()<<endl;
	a.push(-2147483648);
	cout<<a.top()<<endl;
	cout<<a.min()<<endl;
	a.pop();
	cout<<a.min();
}
