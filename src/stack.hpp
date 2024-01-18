constexpr int STK_MAX = 1000;

class Stack
{
	int _top;
	char buf[STK_MAX];

public:
	Stack();

	void push(char c){
		if (! isFull()){
			buf[_top] = c;
			_top++;
		} else {
			cout << "The stack is full" << endl;
		}
	}
		


	char pop(){
		if (! isEmpty()) {
			char res;
			res = buf[_top];
			_top--;
			return res;
		} else {
			cout << "The stack is empty already" << endl;
			return 'f';
		}
	}


	char top(){
		return buf[_top];
	}

	bool isEmpty(){
		return _top > 0;
	}


	bool isFull(){
		return _top < 1000;


}
};


void push_all(Stack & stk, string line){
	for (char c : line) {
		stk.push(c);
	}
}
	



void pop_all(Stack & stk)
{
	while (! stk.isEmpty()){
		char c = stk.pop();
		cout << c;
	}
	cout << endl;
}	


