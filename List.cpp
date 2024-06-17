#include"List.h"


List::Node::Node() : prev(nullptr), next(nullptr), data(0) {};

List::Node::Node(int value) : Node() {
	this->data = value;
};

List::List() : head(nullptr), tail(nullptr), len(0) {};

List::~List() {
	Node* node = head;
	Node* next = node->next;
	
	while (next != nullptr) {
		delete node;
		node = next;

		next = node->next;
	}

	delete node;

	head = tail = nullptr;
}

void List::add(int value) {
	Node* newNode = new Node(value);

	if (!head || !tail) {
		if (value % 3 != 0) {
			std::cout << "First elem must be divisible by 3\n";
			return;
		}
		head = newNode;
		tail = head;
		++this->len;
		return;
	}

	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	++this->len;
}


void List::printList() {
	if (!head) {
		std::cout << "list is empty \n";
		return;
	}

	for (Node* node = head; node != nullptr; node = node->next)
		std::cout << '[' << node->data << "] ";
	std::cout << '\n';
}


void List::printListReverse() {
	if (!tail) {
		std::cout << "list is empty \n";
		return;
	}

	for (Node* node = tail; node != nullptr; node = node->prev)
		std::cout << '[' << node->data << "] ";
	std::cout << '\n';
}



List::Iterator::Iterator(Node* value) : ptr(value) {};

List::Node& List::Iterator::operator*() { return *ptr; }


List::Iterator& List::Iterator::operator++() {
	if (ptr == nullptr) {
		return *this;
	}

	if (ptr->next == nullptr) {
		ptr = nullptr;
		return *this;
	}

	while (ptr && ptr->next && ptr->next->data % 3 != 0) {
		ptr = ptr->next;
	}

	if (ptr && ptr->next && ptr->next->data % 3 == 0) {
		ptr = ptr->next;
	}

	if (ptr->data % 3 != 0) {
		ptr = nullptr;
	}

	return *this;
}

List::Iterator& List::Iterator::operator++(int) {
	Iterator& old = *this;
	++(*this);             
	return old;            
}


List::Iterator& List::Iterator::operator--() {
	if (ptr == nullptr) {
		return *this;
	}

	if (ptr->prev == nullptr) {
		ptr = nullptr;
		return *this;
	}

	while (ptr && ptr->prev && ptr->prev->data % 3 != 0) {
		ptr = ptr->prev;
	}

	if (ptr && ptr->prev && ptr->prev->data % 3 == 0) {
		ptr = ptr->prev;
	}

	if (ptr->data % 3 != 0) {
		ptr = nullptr;
	}

	return *this;
}

List::Iterator& List::Iterator::operator--(int) {
	Iterator& old = *this;
	--(*this);
	return old;
}


bool List::Iterator::operator ==(Iterator f) { return ptr == f.ptr; }

bool List::Iterator::operator !=(Iterator f) { return ptr != f.ptr; }


std::ostream& operator << (std::ostream& os, const List::Node& node) {
	return os << node.data;
}

int List::getLen()
{
	return this->len;
}

List::Iterator List::begin() {
	return Iterator(head);
}

List::Node& List::front() {
	return *head;
}

List::Node& List::back()
{
	return *tail;
}

List::Iterator List::end() {
	return nullptr;
}

bool List::empty()
{
	return (this->begin() == this->end());
}

void List::swap(int first, int second)
{
	Node* nodeFirst = findElem(first);
	Node* nodeSecond = findElem(second);

	
	int temp = nodeSecond->data;

	nodeSecond->data = std::move(nodeFirst->data);
	nodeFirst->data = std::move(temp);
}


List::Node* List::findElem(int position)
{
	if (position >= len || position < 0) {
		throw std::runtime_error("Error");
	}

	Node* targetNode = this->head;

	for (int i = 0; targetNode != nullptr && i < position; targetNode = targetNode->next, ++i) {}

	return targetNode;
}
