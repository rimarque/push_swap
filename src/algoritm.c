#include "../push_swap.h"

void algoritm(list *stack_a, list *stack_b)
{
    node *element;

    push(stack_b, stack_a);
    push(stack_b, stack_a);
    while (stack_a->size > 3)
    {
        node    *element = find_cheap(*stack_a, *stack_b);
        FAZER OPERACOES
        push(stack_b, stack_a);
    }
    sort3(stack_a);
    ate ao b estar vazio mandar do b para o a;
}
