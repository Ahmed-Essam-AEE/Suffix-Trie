#include <iostream>
using namespace std;
struct Node
        {
    char character;
    Node *next;
        };
class LinkedList{
private:
    Node* head ,* tail;

public:
    LinkedList()
    {
        this->head=nullptr;
        this->tail=nullptr;
    }
    

    void printList()
    {
        Node *tmp= this->head;
        while (tmp != this->tail)
        {
           cout<<tmp->character<<" ";
           tmp=tmp->next;
        }
        cout<<tmp->character;
        cout<<endl;
    }
    void push_back(char value)
    {
        Node*tmp=new Node();
        tmp->character=value;
        tmp->next=nullptr;
        if(this->head==nullptr)
        {
            this->head=tmp;
            this->tail=tmp;
            tmp=nullptr;
        }
        else
        {
            this->tail->next=tmp;
            this->tail=tmp;
        }
    }
        };
int main() {
    LinkedList *list=new LinkedList();
    list->push_back('a');
    list->push_back('h');
    list->push_back('m');
    list->push_back('e');
    list->push_back('d');
    list->printList();

    return 0;
}
