#include "../push_swap.h"

void algorithm(list *stack_a, list *stack_b)
{
    node *element;
    int dif;
    int counter;
    //size_t tester = 2;

    push(stack_b, stack_a);
    push(stack_b, stack_a);
    //element = find_cheap(*stack_a, *stack_b);
    //printf("element_val:%d\nelement->flag_a:%d, flag:%d\nelement->flag_b:%d, flag:%d\n", element->val, element->nop_a, element->flag_a, element->nop_b, element->flag_b);

    while (stack_a->size > 3) 
    //while (tester--)
    {
        element = find_cheap(*stack_a, *stack_b);
        printf("element_val:%d\nelement->flag_a:%d, flag:%d\nelement->flag_b:%d, flag:%d\n", element->val, element->nop_a, element->flag_a, element->nop_b, element->flag_b);
        if (element->flag_a == element->flag_b) 
        {
            if (element->nop_a > element->nop_b)
            {
                dif = element->nop_a - element->nop_b;
                counter = 0;
                while (counter++ < dif)
                {
                    if (element->flag_a == 0)
                        rotate(stack_a, 'a');
                    if (element->flag_a == 1)
                        rotate_rev(stack_a, 'a');
                }
            
                counter = 0;
                while (counter++ < element->nop_b) //JUNTAR NUMA FUNCAO
                {
                    if (element->flag_a == 0)
                        rotate_rr(stack_a, stack_b);
                    if (element->flag_a == 1)
                        rotate_rev_rr(stack_a, stack_b);
                }
            }
            else
            {
                dif = element->nop_b - element->nop_a;
                counter = 0;
                while (counter++ < dif)
                {
                    if (element->flag_b == 0)
                        rotate(stack_b, 'b');
                    if (element->flag_b == 1)
                        rotate_rev(stack_b, 'b');
                }
                counter = 0;
                while (counter++ < element->nop_a) //JUNTAR NUMA FUNCAO
                {
                    if (element->flag_a == 0)
                        rotate_rr(stack_a, stack_b);
                    if (element->flag_a == 1)
                        rotate_rev_rr(stack_a, stack_b);
                }
            }
        }
        else
        {
            counter = 0;
            while (counter++ < element->nop_a)
            {
                if (element->flag_a == 0)
                    rotate(stack_a, 'a');
                if (element->flag_a == 1)
                    rotate_rev(stack_a, 'a');
            }
            counter = 0;
            while (counter++ < element->nop_b)
            {
                if (element->flag_b == 0)
                    rotate(stack_b, 'b');
                if (element->flag_b == 1)
                    rotate_rev(stack_b, 'b');
            }
        }
        push(stack_b, stack_a);
    }
    sort3(stack_a);
    //ate ao b estar vazio mandar do b para o a: igual a mandar do a para b;
    //find smalest number and bring it to top of stack_b;
}
