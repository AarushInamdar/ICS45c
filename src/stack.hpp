constexpr int STK_MAX = 1000;

class Stack
{
	int _top;
	char buf[STK_MAX];

public:
	Stack() : _top(0) {}

	void push(char c){
		if (! isFull()){
			buf[_top] = c;
			_top++;
		}
	}
		


	char pop(){
		if (! isEmpty()) {
			return buf[_top--];
		
		} else {
			return '@';
		}
	}


	char top(){
		return buf[_top];
	}

	bool isEmpty(){
		return _top == 0;
	}


	bool isFull(){
		return _top == 1000;


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
		std::cout << stk.pop();
	}
	std::cout << std::endl;
}	


