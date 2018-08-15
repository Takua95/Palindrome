#pragma once
#ifndef H_LinkedStackType
#define H_LinkedStackType

template <class Type>
struct stackNode
{
	Type info;
	stackNode<Type> *link;
};

template <class Type>
class linkedStackType
{
public:
	const linkedStackType<Type>& operator=(const linkedStackType<Type>&);
	void initializeStack();
	bool isFullStack() const;
	bool isEmptyStack() const;
	void push(const Type&);
	void pop();
	Type top() const;
	linkedStackType();
	linkedStackType(const linkedStackType<Type> &);
	~linkedStackType();

private:
	stackNode<Type> *stackTop;
	void copyStack(const linkedStackType<Type>&);
};

template <class Type>
void linkedStackType<Type>::initializeStack()
{
	stackNode<Type> *temp;
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
	return false;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
	return (stackTop == NULL);
}

template <class Type>
void linkedStackType<Type>::push(const Type& newItem)
{
	stackNode<Type> *newNode;
	newNode = new stackNode<Type>;
	newNode->info = newItem;
	newNode->link = stackTop;
	stackTop = newNode;
}

template <class Type>
void linkedStackType<Type>::pop()
{
	stackNode<Type> *temp;
	if (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
	else
		cout << "Can't remove from an empty stack";
}

template <class Type>
Type linkedStackType<Type>::top() const
{
	assert(stackTop != NULL);
	return stackTop->info;
}

template <class Type>
linkedStackType<Type>::linkedStackType()
{
	stackTop = NULL;
}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}

template <class Type>
linkedStackType<Type>::~linkedStackType()
{
	initializeStack();
}

template <class Type>
const linkedStackType<Type>&
linkedStackType<Type>::operator=(const linkedStackType<Type> &otherStack)
{
	if (this != &otherStack)
		copyStack(otherStack);
	return *this;
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &otherStack)
{
	stackNode<Type> *newNode, *current, *last;
	if (stackTop != NULL)
		initializeStack();
	if (otherStack.stackTop == NULL)
		stackTop = NULL;
	else
	{
		current = otherStack.stackTop;
		stackTop = new stackNode<Type>;
		stackTop->info = current->info;
		stackTop->link = NULL;
		last = stackTop;
		current = current->link;
		while (current != NULL)
		{
			newNode = new stackNode<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}
#endif