/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lexems_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:32 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:07:14 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

uint32_t	parse_key_lexem(char *str, char **key_str)
{
	uint32_t	i;

	i = 0;
	while (allowed_lexem_char(str[i]))
		++i;
	if (i == 0 && (*str == '?' || *str == '0'))
		++i;
	if (i != 0)
		*key_str = ft_substr(str, 0, i);
	return (i);
}

void	unfold_var_name_to_str(t_data *data, char **str, uint32_t var_pos)
{
	char	*key;
	char	*bfore_var;
	char	*after_var;
	char	*value;

	key = NULL;
	after_var = NULL;
	bfore_var = ft_substr(*str, 0, var_pos);
	var_pos += 1;
	var_pos += parse_key_lexem(*str + var_pos, &key);
	if (key)
		after_var = ft_substr(*str, var_pos, ft_strlen(*str));
	value = find_var_value(data, key);
	*str = ft_strjoin(bfore_var, value);
	*str = ft_strjoin(*str, after_var);
	free(value);
	free(after_var);
}

void	parse_vars_in_str(t_data *data, char **str)
{
	int32_t	sym;

	sym = symbol_position(*str, '$');
	if (sym == -1)
		return ;
	unfold_var_name_to_str(data, str, sym);
	parse_vars_in_str(data, str);
}

int	just_a_dollar_sign(char *in_quotes)
{
	int32_t	i;

	i = symbol_position(in_quotes, '$');
	if (i == -1)
		return (1);
	++i;
	if (!in_quotes[i] || in_quotes[i] == ' ')
		return (1);
	return (0);
}

void	free_one_lexem(t_lexem *to_free)
{
	if (!to_free)
		return ;
	if (to_free->data)
		free(to_free->data);
	free(to_free);
}
