#include "Node.h"
#include "NodeQueue.h"
#include <iostream>

NodeQueue::NodeQueue() : m_front{ nullptr }, m_back{ nullptr }, m_size{ 0 }{}

bool NodeQueue::isEmpty()
{
	if (m_front == nullptr)
	{
		return true;
	}

	return false;
}

int NodeQueue::getFront()
{
	if (isEmpty())
	{
		std::cout << "\nFile vide!";
		return -1;
	}

	return m_front->getData();
}

int NodeQueue::getBack()
{
	if (isEmpty())
	{
		std::cout << "\nFile vide!";
		return -1;
	}

	return m_back->getData();
}

void NodeQueue::enqueue(int data)
{
	Node* temp{ new Node{data} };

	// Si c'est la première insertion
	// faire pointer l'avant ET l'arrière sur le nouveau noeud
	if (isEmpty())
	{
		m_front = temp;
		m_back = temp;
	}

	m_back->setNext(temp);
	m_back = temp;
}

void NodeQueue::dequeue()
{
	if (isEmpty())
	{
		std::cout << "\nFile vide!";
		return;
	}

	Node* temp = m_front;
	m_front = m_front->getNext();

	// Si on est au dernier élément de la chaîne
	// m_front devient nullptr et il faut mettre m_back à nullptr aussi
	// sinon m_back va continuer de pointer vers l'élément que l'on va libérer de la mémoire
	if (m_front == nullptr)
	{
		m_back = nullptr;
	}

	temp->setNext(nullptr);
	delete temp;
}

void NodeQueue::afficherFile()
{
	std::cout << "FRONT ";
	Node* temp = m_front;
	while (temp != nullptr)
	{
		std::cout << temp->getData() << "->";
		temp = temp->getNext();
	}
	std::cout << " BACK\n";
}
