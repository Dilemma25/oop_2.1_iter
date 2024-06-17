#include<iostream>
#include<utility>
#include<stdexcept>
class List {
	int len;

	struct Node {
		
		int data;
		Node *next, *prev;

		Node();

		Node(int data);

		Node(const Node&) = delete;
	};

	Node * head, * tail;

public:
	
	friend std::ostream& operator <<(std::ostream& os, const Node& node);

	class Iterator;


	List();
	~List();

	void add(int value);

	void printList();
	void printListReverse();

	class Iterator {
		Node* ptr;

	public:
		Iterator(Node* value);

		Node& operator* ();

		Iterator& operator ++();
		Iterator& operator ++(int);
		Iterator& operator --();
		Iterator& operator --(int);

		bool operator == (Iterator f);
		bool operator != (Iterator f);
	};

	int getLen();

	Iterator begin();

	Node& front();

	Node& back();

	Iterator end();

	bool empty();

	void swap(int first, int second);

	Node* findElem(int position);
};

template<typename T>
class ListT {
    int len;

public:
    struct Node {
        T data;
        Node* next, * prev;

        Node() : prev(nullptr), next(nullptr) {};

        Node(T value) : Node() {
            this->data = value;
        };

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
    };

private:
    Node* head, * tail;

public:

    class Iterator {
        Node* ptr;
    public:
        Iterator(Node* value) : ptr(value) {};
        Node& operator*() { return *ptr; }
        Iterator& operator++() {
            if (ptr != nullptr) {
                ptr = ptr->next;
            }
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        Iterator& operator--() {
            if (ptr != nullptr) {
                ptr = ptr->prev;
            }
            return *this;
        }
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    friend std::ostream& operator<<(std::ostream& os, const typename ListT<T>::Node& node);

    ListT() : head(nullptr), tail(nullptr), len(0) {};

    ~ListT() {
        Node* node = head;
        while (node != nullptr) {
            Node* next = node->next;
            delete node;
            node = next;
        }
        head = tail = nullptr;
        len = 0;
    }

    void add(T value) {
        Node* newNode = new Node(value);
        if (!head || !tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++len;
    }

    void printList() {
        if (!head) {
            std::cout << "list is empty \n";
            return;
        }
        for (Node* node = head; node != nullptr; node = node->next) {
            std::cout << '[' << node->data << "] ";
        }
        std::cout << '\n';
    }

    void printListReverse() {
        if (!tail) {
            std::cout << "list is empty \n";
            return;
        }
        for (Node* node = tail; node != nullptr; node = node->prev) {
            std::cout << '[' << node->data << "] ";
        }
        std::cout << '\n';
    }

    int getLen() const {
        return this->len;
    }

    Iterator begin() const {
        return Iterator(head);
    }

    Node& front() {
        if (!head) {
            throw std::runtime_error("List is empty");
        }
        return *head;
    }

    Node& back() {
        if (!tail) {
            throw std::runtime_error("List is empty");
        }
        return *tail;
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    bool empty() const {
        return head == nullptr;
    }

    void swap(int first, int second) {
        Node* nodeFirst = findElem(first);
        Node* nodeSecond = findElem(second);
        std::swap(nodeFirst->data, nodeSecond->data);
    }

    Node* findElem(int position) {
        if (position >= len || position < 0) {
            throw std::runtime_error("Error");
        }
        Node* targetNode = head;
        for (int i = 0; targetNode != nullptr && i < position; targetNode = targetNode->next, ++i) {}
        return targetNode;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const typename ListT<T>::Node& node) {
    os << node.data;
    return os;
}
