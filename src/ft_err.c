/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:19:47 by trcottam          #+#    #+#             */
/*   Updated: 2021/01/13 11:10:06 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_err.h"

const char	*const g_err[] = {
	[E_CFGPATH] = "Error opening configuration",
};

void	ft_err(t_err_id id)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", g_err[id]);
	exit(id);
}
