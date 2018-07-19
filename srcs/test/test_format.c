#include "../../includes/ft_printf.h"

#define INIT_DATA(X) t_data X = {.value = (void *)42, .type ='d', .buffer=NULL}

void test_format_01()
{
	INIT_DATA(test_data_01);
	ft_format_data_with_type(&test_data_01);
}






