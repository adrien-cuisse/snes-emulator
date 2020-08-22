
/**
 * Stack instructions header, a basic LIFO structure
 */


#ifndef STACK_HEADER
#define STACK_HEADER


#define STACK_TYPE unsigned short




/**
 * Forward declaration, @see Stack.c
 */
typedef struct Stack Stack;




/**
 * Creates a new stack and returns it
 * 
 * @return - the created stack
 */
Stack * Stack_create(void);


/**
 * Deletes the stack and sets it to NULL
 * 
 * @param this - the stack to delete
 */
void Stack_delete(Stack ** this);


/**
 * Adds a value at the end of the stack
 *
 * @param this - the stack to add the value in
 * @param value - the value to add in the stack
 */
void Stack_push(Stack ** this, STACK_TYPE value);


/**
 * Removes the value at the end of the stack and returns it
 * 
 * @param this - the stack to remove value from
 * 
 * @return - the removed value, or 0 if it was empty
 */
STACK_TYPE Stack_pop(Stack ** this);




#endif /* STACK_HEADER */
