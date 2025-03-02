#include "LinkedList.hpp"

Node::Node(AMateria *data)
{
    this->data = data;
    next = NULL;
}

Node::~Node()
{
    delete data;
}

Node::Node(const Node &copy) : data(copy.data), next(NULL) {}


Node &Node::operator=(const Node &other)
{
    if(this != &other)
    {
        data = other.data;
        next = other.next;
    }
    return (*this);
}

LinkedList::LinkedList() : head(NULL) {}

LinkedList::~LinkedList()
{
    Node *current = head;
    while(current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

LinkedList::LinkedList(const LinkedList &copy) : head(NULL)
{
    Node *current = copy.head;
    while (current)
    {
        Node *newNode = new Node(current->data);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        current = current->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this != &other)
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;

        Node *currentOther = other.head;
        while (currentOther) {
            Node *newNode = new Node(currentOther->data);
            if (!head)
                head = newNode;
            else 
            {
                Node* temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
            }
            currentOther = currentOther->next;
        }
    }
    return (*this);
}


void LinkedList::addNode(AMateria* data)
{
    Node *newNode = new Node(data);
    if (!head)
        head = newNode;
    else 
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
