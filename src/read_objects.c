/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:50:36 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 00:53:01 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_lstobj	*lstobj_new(void *obj, t_objs obj_name)
{
	t_lstobj	*new;

	if(!(new = malloc(sizeof(t_lstobj))))
		return (NULL);
	new->obj_name = obj_name;
	new->obj = obj;
	new->next = NULL;
	return (new);
}

void		lstobj_append(t_lstobj **objs, t_lstobj *new_obj)
{
	t_lstobj	*last;

	if (!objs || !new_obj)
		return ;
	if (!*objs)
	{
		*objs = new_obj;
		return;
	}
	last = *objs;
	while (last->next)
		last = last->next;
	last->next = new_obj;
}

void		delete_objects(t_lstobj **objs)
{
	t_lstobj	*current;
	t_lstobj	*node;

	current = *objs;
	while (current)
	{
		free(current->obj);
		node = current;
		current = current->next;
		free(node);
	}
	*objs = NULL;
}
