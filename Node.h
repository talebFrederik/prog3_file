#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int m_data;
	Node* m_next;
public:
	Node(int data);
	int getData();
	Node* getNext();
	void setNext(Node* next);
};

#endif