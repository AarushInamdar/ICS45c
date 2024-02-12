#include <iostream>
#include "list.hpp"
//#include "string.hpp"


namespace list{

Node* from_string(const char* s) {
	if (!s || s[0]=='\0') {
		return nullptr;
	}

	Node* head = new Node{.data=*s};	
	Node* p = head;
	
	while (*s!='\0') {
		++s;
		p->next = new Node{.data=*s};
		p = p->next;	
		}
		
	return head;
}

// deletes all nodes of linked list
void free(Node* head){
	while (head!=nullptr) {
		Node* nextNode = head->next;
		delete head;
		head = nextNode;
	}
}

// prints linked list to ostream out
void print(std::ostream& out, Node* head) {
	for (Node* p=head; p!= nullptr; p=p->next) {
		out << p->data << ' ';
	}
}
// returns an exact duplicate of linked list starting at head
Node* copy(Node* head) {
	if (head!=nullptr) {
		Node* newHead = new Node{.data=head->data};
		Node* myPointer = newHead;	
		for (Node* p=head->next; p!=nullptr; p = p->next) {
			newHead->next = new Node{.data=p->data, .next=nullptr};
			newHead=newHead->next;
		}
		return myPointer;
	} else {
		return nullptr;
	}
	
}	
		

// similar to strcmp but for lists
int compare(Node* lhs, Node* rhs) {
	Node* lp = lhs;
	Node* rp = rhs;

	while (lp!=nullptr && rp!=nullptr) {
		if (lp->data != rp->data) {
			return lp->data-rp->data;
		}
		lp = lp->next;
		rp = rp->next;
	}

	if (lp==nullptr && rp==nullptr) {
		return 0;
	} else if (lp == nullptr) {
		return 'a'-rp->data-1;
	} else {
		return lp->data-'a'+1;
	}
}

// similar to strncmp but for lists
int compare(Node* lhs, Node* rhs, int n) {
	Node* lp = lhs;
	Node* rp = rhs;
	
	while (lp!=nullptr && rp!=nullptr && n!=0) {
		if (lp->data != rp->data) {
			return lp->data-rp->data;
		}
		lp = lp->next;
		rp = rp->next;
		n--;
	}
	return 0 ;
}

// counts number of nodes in linked list
int length(Node* head) {
	if (head==nullptr) return 0;
	
	int res = 0;
	for (Node*p = head; p!=nullptr; p=p->next) {
		++res;
	}
	return res-1;
}


// returns reversed copy of linked list
Node* reverse(Node* head) {
	Node* reversed = copy(head);
	
	Node* prev = nullptr;
	Node* rp = reversed;
	Node* next = nullptr;
	
	while (rp!= nullptr && rp->data != '\0') {
		next = rp->next;
		rp->next = prev;
		prev = rp;
		rp = next;
	}
	
	return prev;
	
}



// returns new list containing all nodes of lhs followed by all nodes of rhs
Node* append(Node* lhs, Node* rhs) {
	Node* lc = copy(lhs);
	Node* rc = copy(rhs);
	
	last(lc)->next = rc;

	return lc;
}

// returns index of node in list starting at head
int index(Node* head, Node* node){

	Node *p = head;
	int i = 0;
	while (compare(p, node, 1) != 0 && p!=nullptr) {
		p= p->next;
		i++;
	}
	return i;
}

// similar to strchr but for a linked list
Node* find_char(Node* head, char c) {
	Node *p = head;

	while (p!=nullptr) {
		if (p->data != c){
			p = p->next;
		} else {
		return p;
		}
	}
	return p;
}


// similar to strstr but for two linked lists
Node* find_list(Node* haystack, Node* needle) {
	Node* pH = haystack;
	Node* pN = needle;

	int needleLen = length(needle);

	while (pH!=nullptr) {
		if (compare(pH, pN, needleLen) == 0) {
			return pH;
		}
		pH = pH->next;
	}
	return nullptr;


}




// get the nth node of linked list
Node* nth(Node* head, int n){
	Node* p = head;
	int i = 1;
	while (i!=n && p!=nullptr) {
		p = p->next;
		i++;
	}
	return p;
}

// get the last node of linked list
Node* last(Node* head){
	if (head==nullptr) return nullptr;
	

	Node* rabbit = head;
	
	while (rabbit->next->next != nullptr) {
		rabbit = rabbit->next;
	}
	return rabbit;
}

}

