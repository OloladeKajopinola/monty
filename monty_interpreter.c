#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global variable to hold the stack (you are allowed one global variable) */
stack_t *stack = NULL;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);

/* Main function to execute Monty ByteCode */
int main(int argc, char *argv[])
{
    /* Check if there is exactly one argument (the Monty file) */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* TODO: Open and read the Monty file, and process each line */

    return (EXIT_SUCCESS);
}

/* Implementation of the push opcode */
void push(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *new_node;

    /* Create a new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack pointer */
    *stack = new_node;
}

/* Implementation of the pall opcode */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; /* Unused parameter */

    /* Print all values on the stack */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

