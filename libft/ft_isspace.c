/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:21:27 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:21:44 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int sym)
{
	return (sym == '\t' || sym == '\n' || sym == '\v'
		|| sym == '\f' || sym == '\r' || sym == ' ');
}