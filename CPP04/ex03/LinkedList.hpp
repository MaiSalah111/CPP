#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "AMateria.hpp"

class Node{
    public:
    AMateria *data;
    Node *next;

    Node(AMateria *data);
    Node(const Node &copy);
    ~Node();

    Node &operator=(const Node &other);

};

class LinkedList{
    private:
    Node *head;

    public:
    LinkedList();
    LinkedList(const LinkedList &copy);
    ~LinkedList();

    LinkedList &operator=(const LinkedList &other);

    void addNode(AMateria *data);
};

#endif