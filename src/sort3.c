#include "../push_swap.h"

void sort3(list *stack)
{
    if (stack->first->val > stack->first->next->val && stack->first->val < stack->first->prev->val) //case 1 check
        swap(stack, 'a');
    else if (stack->first->val > stack->first->next->val && stack->first->next->val > stack->first->prev->val) //case 2
    {
        swap(stack, 'a');
        rotate_rev(stack, 'a');
    }
    else if (stack->first->val > stack->first->next->val && stack->first->val  > stack->first->prev->val) //case 3
        rotate(stack, 'a');
    else if (stack->first->val < stack->first->prev->val && stack->first->next->val > stack->first->prev->val) //case 4
    {    
        swap(stack, 'a');
        rotate(stack, 'a');
    }
    else if (stack->first->val < stack->first->next->val  && stack->first->val > stack->first->prev->val) //case 5
        rotate_rev(stack, 'a');
}
  