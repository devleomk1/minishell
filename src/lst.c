/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:12:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/10/25 13:43:14 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_lst
{
	char			*value;
	struct s_lst	*next;
}					t_lst;

/* linked list
 * ----------------
 * - lst_insert
 * - lst_clear
 * - lst_print
 * - lst_new
 * - lst_del
 * ... 등등드읃응
 * */

t_lst	*lst_new(int value)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
	{
		ft_putstr_fd("Malloc error\n", 2);
		return (NULL);
	}
	new->value = value;
	new->next = new;
	return (new);
}

void	lst_insert(t_lst *before, t_lst *new)
{
	new->prev = before;
	new->next = before->next;
	before->next->prev = new;
	before->next = new;
}

void	dlst_clear(t_lst *head)
{
	t_lst	*curr;
	t_lst	*next;

	curr = head;
	if (!curr)
		return ;
	while (1)
	{
		next = curr->next;
		free(curr);
		curr = next;
		if (curr == head)
			return ;
	}
}

/* list -> **str function */
/* list <- **str function */
