#include "picture.hpp"
#include <iostream>
#include <utility>

// initializing constructor creates this as an empty picture
Picture::Picture() :head(nullptr), tail(nullptr) {

}

// copy and move constructors for Picture (good C++ practice)
Picture::Picture(const Picture& other): head(nullptr), tail(nullptr) {
	ListNode* current = other.head;
	while (current!=nullptr) {
		this->add(*(current->shape));
		current = current->next;
		}
}

Picture::Picture(Picture&& other): head(other.head), tail(other.tail) {
	other.head= nullptr;
	other.tail= nullptr;
}

// swap this Picture's list with other Picture's list
void Picture::swap(Picture& other) {
	/*ListNode* tempHead;
	ListNode* tempTail;

	tempHead = other.head;
	tempTail = other.tail;

	other.head = this->head;
	other.tail = this->tail;

	this->head = tempHead;
	this->tail = tempTail;i*/

	std::swap(head, other.head);
	std::swap(tail, other.tail);
}

// copy and move assignment for Picture (good C++ practice)
Picture& Picture::operator=(const Picture& other) {
	Picture temp(other);
	swap(temp);
	return *this;
}

Picture& Picture::operator=(Picture&& other) {
	if (this != &other) {
		ListNode* current=head;
		while(current!=nullptr) {
		ListNode* toDelete = current;
		current = current->next;
		delete toDelete->shape;
		delete toDelete;
	}


		this->head = other.head;
		this->tail = other.tail;

		other.head = nullptr;
		other.tail= nullptr;
	}
	return *this;
}

// adds a clone of shape to the end of this Picture’s linked list.
// Cloning allows us to create any number of shape objects
// at runtime, while Picture can own the newly created
// shape objects contained within it. Note this means
// Picture is responsible for deleting these clones when
// this Picture object dies.
void Picture::add(const Shape& shape) {
	Shape* newShape = shape.clone();
	ListNode* newNode = new ListNode;

	newNode->shape = newShape;
	newNode->next = nullptr;
	if (!head) {
		head= newNode;
		tail=newNode;
	} else{
		tail->next = newNode;
		tail = newNode;
	}
}

// calls method print() on each shape in the order they were added
void Picture::print_all(std::ostream& out) const {
	ListNode* myNode = head;
	while (myNode!=nullptr) {
		Shape* currentShape = myNode->shape;
		currentShape->print(out);
		currentShape->draw(out);
		myNode = myNode->next;
		//out << "Next shape\n";
	}
}

// draws the Shapes in this Picture in the order they were added
void Picture::draw_all(std::ostream& out) const {
	ListNode* myNode = head;
	while (myNode!=nullptr) {
		Shape* currentShape = myNode->shape;
		currentShape->draw(out);
		myNode = myNode->next;
		//out << "Next shape\n";
	}

}

// returns the sum of the areas of all the Shapes in this Picture
double Picture::total_area() const {
	ListNode* myNode = head;
	double totalArea = 0.0;
	while (myNode != nullptr) {
		Shape* currentShape = myNode->shape;
		totalArea += currentShape->area();
		myNode = myNode->next;
	}
	return totalArea;
}

// frees all storage owned by this Picture when it dies
Picture::~Picture() {
	ListNode* current=head;
	while(current!=nullptr) {
		ListNode* toDelete = current;
		current = current->next;
		delete toDelete->shape;
		delete toDelete;
	}
	head = nullptr;
	tail = nullptr;
}




