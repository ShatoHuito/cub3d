#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list	*tmp;

    tmp = lst;
    if (lst)
        while (tmp->next)
            tmp = tmp->next;
    return (tmp);
}
