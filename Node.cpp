#include "Node.h"

Node::Node(int data) : m_data{ data }, m_next{ nullptr }{}

int Node::getData()
{
	return m_data;
}

Node* Node::getNext()
{
	return m_next;
}

void Node::setNext(Node* next)
{
	m_next = next;
}
