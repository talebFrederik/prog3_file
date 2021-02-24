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

	// Si c'est la premi�re insertion
	// faire pointer l'avant ET l'arri�re sur le nouveau noeud
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

	// Si on est au dernier �l�ment de la cha�ne
	// m_front devient nullptr et il faut mettre m_back � nullptr aussi
	// sinon m_back va continuer de pointer vers l'�l�ment que l'on va lib�rer de la m�moire
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
