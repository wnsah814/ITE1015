#ifndef __list__
#define __list__

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <class T>
class List {
private:
    Node<T> *head;
public:
    List() : head(NULL) {};
    ~List(); //free resources
    List(T* arr, int n_nodes); //create a list with n_nodes
    void insert_at(int idx, const T& data);
    void remove_at(int idx);
    void pop_back();
    void push_back(const T& val);
    void pop_front();
    void push_front(const T& val);
    friend ostream& operator<<(ostream& out, List& rhs) {
        Node<T>* now = rhs.head;
        while (now -> next != NULL) {
            out << now -> data << ",";
            now = now -> next;
        }
        out << now -> data;
        return out;
    } //print out nodes
};

template <class T>
List<T>::~List() {
    Node<T>* now = head;
    Node<T>* tmp;
    while (now -> next != NULL) {
        tmp = now -> next;
        delete now;
        now = tmp;
    }
    delete now;
}

template <class T>
List<T>::List(T* arr, int n_nodes) {
    head = new Node<T>;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    Node<T>* now = head;
    for (int i = 0; i < n_nodes - 1; i++) {
        now -> data = arr[i];
        now -> next = new Node<T>;
        now = now -> next;
    }

    now -> data = arr[n_nodes - 1];
    now -> next = NULL;
}

template <class T>
void List<T>::insert_at(int idx, const T& data) { //inx가 더 크거나 작은 경우?
    Node<T>* now = head;
    for (int i = 0; i < idx - 1; i++) {
        now = now -> next;
    }
    Node<T>* tmp = now -> next;
    now -> next = new Node<T>;
    now = now -> next;
    now -> data = data;
    now -> next = tmp;
}

template <class T>
void List<T>::remove_at(int idx) {
    Node<T>* now = head;
    for (int i = 0; i < idx - 1; i++) {
        now = now -> next;
    }
    Node<T>* tmp = now -> next -> next;
    delete now -> next;
    now -> next = tmp;
}

template <class T>
void List<T>::pop_back() {
    Node<T>* prev;
    Node<T>* now = head;
    while (now ->next != NULL) {
        prev = now;
        now = now -> next;
    }
    delete prev -> next;
    prev -> next = NULL;
}

template <class T>
void List<T>::push_back(const T& val) {
    Node<T>* now = head;
    while (now ->next != NULL) {
        now = now -> next;
    }
    now -> next = new Node<T>;
    now = now -> next;
    now -> data = val;
    now -> next = NULL;
}

template <class T>
void List<T>::pop_front() {
    Node<T>* tmp = head -> next;
    delete head;
    head = tmp;
}

template <class T>
void List<T>::push_front(const T& val) {
    Node<T>* tmp = new Node<T>;
    tmp -> data = val;
    tmp -> next = head;
    head = tmp;
}

#endif