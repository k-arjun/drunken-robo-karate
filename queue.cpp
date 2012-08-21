#include <iostream>
using namespace std;

template<class T>
class queue{
	private:
	int length;
	int front;
	int back;

	T *data;

	public:
	queue(int length){
		this->length = length;
		front = -1;
		back = -1;

		data = new T[length];
	}

	~queue(){
		delete [] data;
	}

	void enqueue(T item);
	T dequeue();
};

template<class T>
void queue<T>::enqueue(T item){
	if(front == -1){
		front = back = 0;
		data[front] = item;
	}
	else if(back < length-1){
		data[++back] = item;
	}
	else
		cout<<"\nThe queue is full\n";
}

template<class T>
T queue<T>::dequeue(){
	if(front == back && front==-1)
		cout<<"\nThe queue is empty\n";
	else if(front == back){
		int temp = front;
		front = back = -1;
		return data[temp];
	}
	else{
		++front;
		return data[front-1];
	}
}

int main(){
	queue<int> q1(5);

	int temp;

	for(int i=0; i<6; ++i){
		q1.enqueue(i);
	}

	for(int i=0; i<5; ++i){
		temp = q1.dequeue();
		cout<<temp<<"\t";
	}

	cout<<endl;
	return 0;
}
