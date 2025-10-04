#include <iostream>
#include <string>
using namespace std;

struct Node {
    string val;
    Node* prev;
    Node* next;
    Node(string v) : val(v), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_front(string x) {
        Node* node = new Node(x);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        cout << "ok"<<endl;
    }

    void add_back(string x) {
        Node* node = new Node(x);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        cout << "ok"<<endl;
    }

    void erase_front() {
        if (!head) {
            cout << "error"<<endl;
            return;
        }
        cout << head->val << endl;
        Node* toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete toDelete;
    }

    void erase_back() {
        if (!tail) {
            cout << "error"<<endl;
            return;
        }
        cout << tail->val << endl;
        Node* toDelete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete toDelete;
    }

    void front() {
        if (!head) cout << "error"<<endl;
        else cout << head->val << endl;
    }

    void back() {
        if (!tail) cout << "error"<<endl;
        else cout << tail->val << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok"<<endl;
    }
};

int main() {
    DoublyLinkedList dll;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string x; 
            cin >> x;
            dll.add_front(x);
        } else if (command == "add_back") {
            string x; 
            cin >> x;
            dll.add_back(x);
        } else if (command == "erase_front") {
            dll.erase_front();
        } else if (command == "erase_back") {
            dll.erase_back();
        } else if (command == "front") {
            dll.front();
        } else if (command == "back") {
            dll.back();
        } else if (command == "clear") {
            dll.clear();
        } else if (command == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
}
