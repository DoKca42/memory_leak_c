/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:30:57 by loculy            #+#    #+#             */
/*   Updated: 2023/01/26 04:14:48 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "yy.h"

void	ft_rr(void)
{
	char	*r;
	char	*b;

	r = ftm_malloc(sizeof(char) * 14);
	b = malloc(sizeof(char) * 14);
	ftm_add_track(b);
	ftm_add_track(b);
	ftm_add_track(b);
}
