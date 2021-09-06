/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lexems_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:30 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 15:43:56 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

uint32_t	parse_pipe_lexem(t_data *data, char *str)
{
	push_back_lexem(&data->lexems, ft_substr(str, 0, 1), 2 - data->state);
	return (1);
}

uint32_t	parse_redirects_lexem(t_data *data, char *str)
{
	if (!ft_strncmp(">>", str, 2))
	{
		push_back_lexem(&data->lexems, ft_substr(str, 0, 2), 2 - data->state);
		return (2);
	}
	else if (!ft_strncmp("<<", str, 2))
	{
		push_back_lexem(&data->lexems, ft_substr(str, 0, 2), 2 - data->state);
		data->state = STATE_DLR;
		return (2);
	}
	else if (*str == '>')
	{
		push_back_lexem(&data->lexems, ft_substr(str, 0, 1), 2 - data->state);
		return (1);
	}
	else if (*str == '<')
	{
		push_back_lexem(&data->lexems, ft_substr(str, 0, 1), 2 - data->state);
		return (1);
	}
	return (0);
}

uint32_t	parse_spaces_lexem(t_data *data, char *str)
{
	uint32_t	len;

	len = 0;
	while (ft_isspace(str[len]))
		++len;
	push_back_lexem(&data->lexems, NULL, data->state);
	if (data->state == STATE_DLR)
		data->state = PLAIN_TEXT;
	return (len);
}

uint32_t	parse_variable_argument_lexem(t_data *data, char *str)
{
	uint32_t	len;
	char		*value;
	char		*key;

	len = 0;
	if (just_a_dollar_sign(str))
		push_back_lexem(&data->lexems, ft_strdup("$"), data->state);
	else
	{
		key = NULL;
		len++;
		len += parse_key_lexem(str + 1, &key);
		value = find_var_value(data, key);
		data->state = STATE_DLR;
		parse_lexems(data, value);
		data->state = PLAIN_TEXT;
	}
	return (len);
}

uint32_t	parse_var_dlr(t_data *data, char *str)
{
	uint32_t	len;

	len = 1;
	while (allowed_lexem_char(str[len]))
		++len;
	push_back_lexem(&data->lexems, ft_substr(str, 0, len), data->state);
	data->state = PLAIN_TEXT;
	return (len);
}
