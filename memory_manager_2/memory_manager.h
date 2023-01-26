/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:09:20 by loculy            #+#    #+#             */
/*   Updated: 2023/01/26 04:13:57 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGER_H
# define MEMORY_MANAGER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_memng
{
	void			*mem;
	int				type;
	int				fd;
	struct s_memng	*next;
}	t_memng;

t_memng	**ft_head_lst(void);
t_memng	*ft_memnew_manager(void *mem, int type, int fd);
void	ft_memadd_back_manager(t_memng **lst, t_memng *new);
int		ft_is_in_lst(void *mem);
void	*ftm_malloc(size_t sz);
void	ftm_free(void *mem);
int		ftm_open(char *pathname, int flags);
void	ftm_close(int fd);
void	ftm_free_all(void);
void	ftm_add_track(void *mem);
void	ftm_rm_track(void *mem);

#endif