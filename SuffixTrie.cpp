#include <iostream>
using namespace std;

class trieNode;
class LinkedList;
class Node{
public:
    char character;
    trieNode *nextChild = nullptr;
    Node *next = nullptr;
    Node(){
        nextChild = nullptr;
        next = nullptr;
    }
    Node(char c)
    {
        this->character = c ;
        nextChild = nullptr;
        next = nullptr;
    }
};


class LinkedList{
private:
    

public:
    Node* head ,* tail;
    LinkedList()
    {
        this->head=nullptr;
        this->tail=nullptr;
    }

    void push_back(Node* tmp)
    {
       
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

    Node* findNode(char c)
    {
        Node *tmp= this->head;
        while (tmp->character != c)
        {
            if(tmp == this->tail && tmp->character != c)
            {
                return nullptr;
            }
            tmp=tmp->next;
        }

        return tmp;
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
};

class trieNode
{
public:
    LinkedList list;
    

    trieNode(){}

    void search(string str)
    {
        char pattern[str.length()];
        for(int i=0; i<str.length(); i++)
        {
            pattern[i] = str[i];
        }

        //cout<< pattern[0]<<" "<< pattern[1]<< " "<<pattern[2]<<endl;

        int ptrnSize = sizeof(pattern);
        Node* tmpNode = list.findNode(pattern[0]);
        int size = ptrnSize;
        bool found = true;
        
        while(size > 0)
        {
            size--;
            if(tmpNode == nullptr)
            {
                found = false;
                break;
            }
            
            if(size == 0)
            {
                break;
            }
            tmpNode = tmpNode->nextChild->list.findNode(pattern[ptrnSize-size]);
            
        }
        
        if(found)
        {
            // tmpNode is the last node in pattern
            // now we will start from tmpNode to find indexes
            
            depth(tmpNode, 7 - ptrnSize); // replace this 7 with length of original string

        }
        else
        {
            cout<<"query not found"<<endl;
        }

        
        //return tmpCharArr;
    }

    int depth(Node* root, int prevCount)
    {
        if(root == nullptr)
        {
            return 0;
        }

        if(root->nextChild == nullptr)
        {
            cout<< prevCount << " ";
            //cout<< mainStrSize - prevCount<< " ";
            return 0;
        }

        Node* nextRoot = root->nextChild->list.head;

        
        do{
            depth(nextRoot, prevCount-1);
            if(nextRoot == root->nextChild->list.tail)
            {
                break;
            }
            nextRoot= nextRoot->next;
        } while(true);

        return 0;
    }
};



int main() {

    trieNode *root=new trieNode();
    trieNode* tn1;
    trieNode *tn2=new trieNode();
    
    // put node 'a' in lList of root
    Node* n1 = new Node();
    n1->character = 'a';
    n1->nextChild = tn2;
    root->list.push_back(n1);

    // put node 'n' in lList of trie node of 'a'
    tn1 = new trieNode();
    n1 = new Node();
    n1->character = 'n';
    n1->nextChild = tn1;
    tn2->list.push_back(n1);

    // put node 'a' in lList of trie node of 'n'
    tn2 = new trieNode();
    n1 = new Node();
    n1->character = 'a';
    n1->nextChild = tn2;
    tn1->list.push_back(n1);

    // put node '$' in first place of lList of trie node of 'a'
    tn1 = new trieNode();
    n1 = new Node();
    n1->character = '$';
    n1->nextChild = nullptr;
    tn2->list.push_back(n1);
    // put node 'n' in second place of lList of trie node of 'a' 
    n1 = new Node();
    n1->character = 'n';
    n1->nextChild = tn1;
    tn2->list.push_back(n1);

    // put node 'a' in lList of trie node of 'n'
    tn2 = new trieNode();
    n1 = new Node();
    n1->character = 'a';
    n1->nextChild = tn2;
    tn1->list.push_back(n1);

    // put node '$' in lList of trie node of 'a'
    tn1 = new trieNode();
    n1 = new Node();
    n1->character = '$';
    n1->nextChild = nullptr;
    tn2->list.push_back(n1);

    root->search("ana");

    delete root;
    delete tn1;
    delete tn2;
    delete n1;

    return 0;
}