#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

stack_t *stack = NULL; // Global stack

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @n: The integer to push
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

/**
 * pall - Prints all values in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char opcode[256];
    int argument;

    while (fscanf(file, "%s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &argument) == 1)
            {
                push(&stack, 0, argument);
            }
            else
            {
                fprintf(stderr, "L%d: usage: push integer\n", 0); // Replace 0 with the actual line number
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, 0); // Replace 0 with the actual line number
        }
        // Add more opcodes handling here
    }

    fclose(file);
    return 0;
}

