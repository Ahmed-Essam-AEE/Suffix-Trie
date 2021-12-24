#include <iostream>
using namespace std;

class TrieNode;
class LinkedList;
class Node{
public:
    char character;
    TrieNode *nextChild;
    Node *next;
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

public:
    Node* head ,* tail;
    int size;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(Node* tmp)
    {

        if(this->head==nullptr)
        {
            this->head=tmp;
            this->tail=tmp;
            tmp = nullptr;
        }
        else
        {
            this->tail->next=tmp;
            this->tail=tmp;
        }
        size++;
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
            tmp = nullptr;
        }
        else
        {
            this->tail->next=tmp;
            this->tail=tmp;
        }
        size++;
    }

    Node* findNode(char c)
    {
        //Node *tmp= this->head;
        Node* cur;
        for (cur = head; cur; cur = cur->next)
        {
            if(cur->character == c)
            {
                break;
            }

            if(cur == this->tail && cur->character != c)
            {
                return nullptr;
            }

        }

        return cur;
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

class TrieNode
{
public:
    LinkedList list;

    TrieNode()
    {
        list = LinkedList();
    }

    void search(const char* pattern, int sourceLength)
    {
        int ptrnSize=0;
        while(pattern[ptrnSize] != '\0')
        {
            ptrnSize++;
        }

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

            depth(tmpNode, sourceLength - ptrnSize); // replace this 7 with length of original string
            cout<<endl;
        }
        else
        {
            cout<<"query not found"<<endl;
        }


    }

    int depth(Node* root, int prevCount)
    {
        if(root == nullptr)
        {
            cout<< prevCount << " ";
            return 0;
        }

        if(root->nextChild == nullptr)
        {
            return 0;
        }

        Node* nextRoot = root->nextChild->list.head;


        do
        {
            depth(nextRoot, prevCount-1);
            if(nextRoot == root->nextChild->list.tail)
            {
                break;
            }
            nextRoot= nextRoot->next;
        } while(true);

        return 0;
    }

    void insert(const char* str , TrieNode* root)
    {
        //Check if the char is not found i will insert it
        TrieNode* current = root;

        int strLength=0;
        while(str[strLength] != '\0')
        {
            strLength++;
        }

        for (int i = 0; i < strLength; ++i)
        {

            Node* temp = current->list.findNode(str[i]);

            if(temp != nullptr)
            {
                current = temp->nextChild;
            }
            else
            {
                TrieNode* newTrieNode = new TrieNode();
                Node* newNode = new Node(str[i]);
                current->list.push_back(newNode);
                newNode->nextChild = newTrieNode;
                current = newNode->nextChild;
            }



        }
    }

};

class SuffixTrie
{
private:
    TrieNode* root;
    int sourceLength;
public:
    SuffixTrie(const char* str)
    {
        // get str length
        sourceLength =0;
        while(str[sourceLength] != '\0')
        {
            sourceLength++;
        }


        root = new TrieNode();
        for (int i = 0; i <sourceLength; ++i)
        {

            char substr[sourceLength-i];
            //tmp[0] = str[i];

            for(int j= 0 ;j < sourceLength; j++)
            {
                substr[j] = str[i+j];
            }

            root->insert(substr , root);
        }

    }

    void Search(const char* str)
    {
        root->search(str, sourceLength+1);
    }
};


int main() {

    // Construct a suffix trie containing all suffixes of "bananabanaba$"
    //                0123456789012
    SuffixTrie t("bananabanaba$");
    t.Search("ana"); // Prints: 1 3 7
    t.Search("naba"); // Prints: 4 8
    return 0;
}