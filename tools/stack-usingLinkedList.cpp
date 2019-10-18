#include <iostream>
#include <limits>
using namespace std;

class Stack {
  private:
    class Node {
      public:
        int value;
        Node* nextNode;
        
        Node(const int& newVal, Node* newNode) : value(newVal), nextNode(newNode) {}
        Node(const int& newVal) : value(newVal) , nextNode(nullptr) {}
    };
    Node* headNode;
  
  public:
    Stack();
    ~Stack();
    Stack(const Stack& original);
    bool isEmpty() const;
    int top() const;
    int pop();
    void push(int newElement);
};

Stack::Stack() {
    headNode = nullptr;
}

Stack::~Stack() {
  while (!isEmpty()) pop();
}

Stack::Stack(const Stack& original) {
  if (original.isEmpty()) {
    headNode = nullptr;
  }
  else {
    Node* ptr = original.headNode;
    Node* tmp = new Node(ptr->value);
    headNode = tmp;
    Node* tailNode = tmp;
    
    while (ptr->nextNode != nullptr) {
      ptr = ptr->nextNode;
      tmp = new Node(ptr->value);
      tailNode->nextNode = tmp;
      tailNode = tmp;
    }
  }
}

bool Stack::isEmpty() const {
  return headNode == nullptr;
}

int Stack::top() const {
  if (isEmpty()) {
    throw runtime_error("error: stack is empty");
  }
  return headNode->value;
}

int Stack::pop() {
  int topElement = top();
  
  Node* tmp = headNode;
  headNode = headNode->nextNode;
  delete tmp;
  
  return topElement;
}

void Stack::push(int newElement) {
  Node* tmp = new Node(newElement, headNode);
  headNode = tmp;
}

void List(Stack S) {
  cout << '[';
  while (!S.isEmpty()) {
    cout << S.top();
    S.pop();
    if (!S.isEmpty()) {
      cout << ',';
    }
  }
  cout << "]\n";
}

int main() {
  Stack myStack;
  string Operation;
  int num;
  
  cout << "stack> \n";

  while (cin >> Operation) {
    try {
      
      if (Operation == "push") {
        cin >> num;
        
        if (cin.fail()) {
          throw runtime_error("error: not a number");
        }
        myStack.push(num);
      } 

      else if (Operation == "pop") {
        cout << myStack.pop() << '\n';
      }

      else if (Operation == "top") {
        cout << myStack.top() << '\n';
      }

      else if (Operation == "list") {
        List(myStack);
      }

      else if (Operation == "end") {
        break;
      }

      else {
        throw runtime_error("error: invalid command\n");
      }

    }

    catch (runtime_error& excpt) {
      cout << excpt.what() << '\n';
      cin.clear();
    }

    cin.ignore(numeric_limits<int>::max(), '\n');
    cout << "stack> \n";
  }
  return 0;
}
