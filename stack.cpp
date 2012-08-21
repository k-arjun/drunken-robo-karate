#include <iostream>
using namespace std;

template<class T>
class stack{
	private:
	T *data;
	int top;
	int size;

	public:

	stack(int sizet){
		data = new T[sizet];
		top = -1;
		size = sizet;
	}

	~stack(){
		delete [] data;
	}

	void push(T item);
	T pop();

};

template<class T>
void stack<T>::push(T item){
	if(top<size-1){
		data[++top] = item;
	}
	else{
	cout<<"\nThe stack is full\n";
	}
}

template<class T>
T stack<T>::pop(){
	if(top>-1){
		--top;
		return data[top+1];
	}
	else{
	cout<<"\nThe stack is empty\n";
	}
}

int main(){
	stack<int> s1(5);

	int temp;

	for(int i=1; i<8; ++i)
		s1.push(i);

	for(int i=0; i<5; ++i){
		temp = s1.pop();
		cout<<temp<<"\t";
	}
	cout<<endl;
	return 0;
}
