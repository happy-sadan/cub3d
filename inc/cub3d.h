/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:07:06 by trcottam          #+#    #+#             */
/*   Updated: 2021/01/13 15:54:14 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ft_dprintf dprintf

# include "libft.h"

# include <fcntl.h>

typedef enum	e_err_id {
	E_CFGPATH = 3,
}				t_err_id;

extern const char	*const g_err[];

void	ft_err(t_err_id id);
int		get_conf_fd(char *path);

#endif
