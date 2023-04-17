#include "../push_swap.h"

void algorithm(list *stack_a, list *stack_b)
{
    node *element_a;
    node *element_b;
    int dif;
    int counter;
    int size;
    //size_t tester = 2;

    if (stack_a->size > 3)
    {
        push(stack_b, 'b', stack_a);
        push(stack_b, 'b', stack_a);
    }
    print_val_index(*stack_a, *stack_b);
    //element_a = find_cheap(*stack_a, *stack_b);
    //printf("element_a_val:%d\nelement_a->flag_a:%d, flag:%d\nelement_a->flag_b:%d, flag:%d\n", element_a->val, element_a->nop_a, element_a->flag_a, element_a->nop_b, element_a->flag_b);

    while (stack_a->size > 3)
    //while (tester--)
    {
        //ft_printf("NAO ENTRA AQUI\n");
        //print_val_index(*stack_a, *stack_b);
        element_a = find_cheap(*stack_a, *stack_b);
        //print_val_index(*stack_a, *stack_b);
        //printf("element_a_val:%d\nelement_a->flag_a:%d, flag:%d\nelement_a->flag_b:%d, flag:%d\n", element_a->val, element_a->nop_a, element_a->flag_a, element_a->nop_b, element_a->flag_b);
        if (element_a->flag_a == element_a->flag_b) 
        {
            if (element_a->nop_a > element_a->nop_b)
            {
                dif = element_a->nop_a - element_a->nop_b;
                counter = 0;
                while (counter++ < dif)
                {
                    if (element_a->flag_a == 0)
                        rotate(stack_a, 'a');
                    if (element_a->flag_a == 1)
                        rotate_rev(stack_a, 'a');
                }
                counter = 0;
                while (counter++ < element_a->nop_b) //JUNTAR NUMA FUNCAO
                {
                    if (element_a->flag_a == 0)
                        rotate_rr(stack_a, stack_b);
                    if (element_a->flag_a == 1)
                        rotate_rev_rr(stack_a, stack_b);
                }
            }
            else
            {
                dif = element_a->nop_b - element_a->nop_a;
                counter = 0;
                while (counter++ < dif)
                {
                    if (element_a->flag_b == 0)
                        rotate(stack_b, 'b');
                    if (element_a->flag_b == 1)
                        rotate_rev(stack_b, 'b');
                }
                counter = 0;
                while (counter++ < element_a->nop_a) //JUNTAR NUMA FUNCAO
                {
                    if (element_a->flag_a == 0)
                        rotate_rr(stack_a, stack_b);
                    if (element_a->flag_a == 1)
                        rotate_rev_rr(stack_a, stack_b);
                }
            }
        }
        else
        {
            counter = 0;
            while (counter++ < element_a->nop_a)
            {
                if (element_a->flag_a == 0)
                    rotate(stack_a, 'a');
                if (element_a->flag_a == 1)
                    rotate_rev(stack_a, 'a');
            }
            counter = 0;
            while (counter++ < element_a->nop_b)
            {
                if (element_a->flag_b == 0)
                    rotate(stack_b, 'b');
                if (element_a->flag_b == 1)
                    rotate_rev(stack_b, 'b');
            }
        }
        push(stack_b, 'b', stack_a);
    }
    //print_val_index(*stack_a, *stack_b);
    sort3(stack_a);
    //print_val_index(*stack_a, *stack_b);
    if (stack_b->size == 0)
        return ;
    
    counter = 0;
    size = stack_b->size;
    while (counter++ < size)
    {
        element_b = stack_b->first;
        rotate_a(element_b->val, stack_a);
        //printf("NBR_B:%d\n", element_b->val);
        //print_val_index(*stack_a, *stack_b);
        push(stack_a, 'a', stack_b);
        //print_val_index(*stack_a, *stack_b);
    }
    final_rotation(stack_a);
}