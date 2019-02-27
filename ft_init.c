#include "fillit.h"


t_feel		*ft_tfeelnew(char *content, size_t content_size)
{
	t_feel	*new_lst;

	if (!(new_lst = (t_feel*)malloc(sizeof(t_feel))))
		return (NULL);
	if (!content)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		if (!(new_lst->content = ft_memalloc(content_size)))
		{
			free(new_lst);
			return (NULL);
		}
		new_lst->content = ft_memcpy(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}

void	ft_tfeel_iter(t_feel *lst, void (*f)(t_feel *elem))
{
	t_feel		*current_lst;

	current_lst = lst;
	while (current_lst != NULL)
	{
		f(current_lst);
		current_lst = current_lst->next;
	}
}

void	ft_print_tfeel(t_feel *elem)
{
	if (!elem)
		return ;
	write(1, elem->content, elem->content_size);
	write(1, "\n\n", 2);
}
