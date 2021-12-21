#include <iostream>
using namespace std;

class trieNode;
class LinkedList;
struct Node{

    char character;
    trieNode *nextChild;
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
    void printList()
    {
        Node *tmp= this->head;
        while (tmp != this->tail)
        {
            cout<<tmp->character;
            tmp=tmp->next;
        }
        cout<<tmp->character;
        cout<<endl;
    }
};

class trieNode
{
public:
    LinkedList *list;
    int index;

    trieNode()
    {
        list=new LinkedList();
        index = 0;
    }

};



int main() {
    trieNode *tn=new trieNode();
    tn->list->push_back('a');
    tn->list->push_back('h');
    tn->list->push_back('m');
    tn->list->push_back('e');
    tn->list->push_back('d');
    tn->list->printList();

    return 0;
}
