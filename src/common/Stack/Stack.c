
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"




/**
 * A simple stack, a LIFO structure
 */
struct Stack
{
	Stack * previous;
	STACK_TYPE value;
};




/**
 * Creates a stack element and returns it
 * 
 * @param value - the value to store in the element
 * 
 * @return - the created stack element
 */ 
static Stack * __createElement(STACK_TYPE value);




Stack * Stack_create(void)
{
	return NULL;
}


void Stack_delete(Stack ** this)
{
	Stack * top;

	if (NULL == this) {
		fprintf(stderr, "Warning, tried to delete NULL stack\n");
		return;
	}

	if (NULL == * this) {
		return; /* no warning intended, this is the end of the stack */
	}

	top = * this;
	* this = (* this)->previous;

	free(top);

	Stack_delete(this);
}


void Stack_push(Stack ** this, STACK_TYPE value)
{
	Stack * element;

	if (NULL == this) {
		fprintf(stderr, "Warning, tried to push in NULL stack\n");
		return;
	}

	element = __createElement(value);
	if (element) {
		element->previous = * this;
		* this = element;
	}
}


STACK_TYPE Stack_pop(Stack ** this)
{
	STACK_TYPE value;
	Stack * poppedElement;

	if (NULL == this) {
		fprintf(stderr, "Warning, tried to pop from NULL stack\n");
		return (STACK_TYPE)0;	
	}

	poppedElement = * this;
	* this = (* this)->previous;
	poppedElement->previous = NULL;

	value = poppedElement->value;

	Stack_delete(& poppedElement);

	return value;
}




static Stack * __createElement(STACK_TYPE value)
{
	Stack * this;
	
	this = malloc(sizeof(* this));
	if (NULL == this) {
		fprintf(stderr, "Stack allocation failed\n");
		return NULL;
	}

	this->previous = NULL;
	this->value = value;

	return this;
}
