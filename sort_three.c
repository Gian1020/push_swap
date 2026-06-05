#include "push_swap.h"

/* Ordina uno stack di 3 elementi in massimo 2 mosse.
 * 1. Identifica e sposta il valore massimo in terza posizione (bottom).
 * 2. Verifica se il valore minimo è in prima posizione. */
void sort_three(t_stack **l_stack)
{
    t_stack *a;
    t_stack *b;
    t_stack *c;

    if (!l_stack || list_size(*l_stack) != 3)
        return ;
    a = *l_stack;
    b = a->next;
    c = b->next;
    // [max, ?, ?]
    if (a->idx > b->idx && b->idx < c->idx && a->idx < c->idx)
        sa(l_stack);                        // [2,1,3] → sa
    else if (a->idx > b->idx && b->idx > c->idx)
        { sa(l_stack); rra(l_stack); }      // [3,2,1] → sa+rra
    else if (a->idx > b->idx && b->idx < c->idx && a->idx > c->idx)
        ra(l_stack);                        // [3,1,2] → ra
    else if (a->idx < b->idx && b->idx > c->idx && a->idx < c->idx)
        { sa(l_stack); ra(l_stack); }       // [1,3,2] → sa+ra
    else if (a->idx < b->idx && b->idx > c->idx && a->idx > c->idx)
        rra(l_stack);                       // [2,3,1] → rra
    // [1,2,3] già ordinato → niente
}
