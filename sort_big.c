#include "push_swap.h"

void    sort_big(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data, t_algo *algo)
{
    if (algo->simple)
        sort_max_min_extraction(l_stack_a, l_stack_b, data);
	else if (algo->medium)
		chunk_sort(l_stack_a, l_stack_b, data);
	else if (algo->complex)
		turk_sort(l_stack_a, l_stack_b, data);
    else
    {
        if (data->disorder < 0.2)
            sort_max_min_extraction(l_stack_a, l_stack_b, data);
        else if (data->disorder < 0.5)
            chunk_sort(l_stack_a, l_stack_b, data);
        else if (data->disorder <= 1)
            turk_sort(l_stack_a, l_stack_b, data);
    }
    if (algo->bench)
		bench_writer(data);
}