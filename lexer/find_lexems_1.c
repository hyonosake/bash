/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lexems_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:23 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:12:21 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int	find_lexems(t_data *data)
{
	uint32_t	i;

	i = 0;
	data->state = PLAIN_TEXT;
	parse_lexems(data, data->str);
	if (data->go_next)
		return (0);
	return (1);
}

void	parse_lexems(t_data *data, char *str)
{
	uint32_t	i;

	i = 0;
	while (!data->go_next && str && str[i])
	{
		if (str[i] == '"')
			i += parse_double_quotes_lexem(data, str + i + 1);
		else if (str[i] == '\'')
			i += parse_single_quotes_lexem(data, str + i + 1);
		else if (allowed_lexem_char(str[i]))
			i += parse_word_lexem(data, str + i);
		else if (str[i] == '|')
			i += parse_pipe_lexem(data, str + i);
		else if (ft_isspace(str[i]))
			i += parse_spaces_lexem(data, str + i);
		else if (str[i] == '>' || str[i] == '<')
			i += parse_redirects_lexem(data, str + i);
		else if (str[i] == '$' && data->state == STATE_DLR)
			i += parse_var_dlr(data, str + i);
		else if (str[i] == '$')
			i += parse_variable_argument_lexem(data, str + i);
		else
			unexpected_token(data, SYNTAX_ERR, str[i]);
	}
}

uint32_t	parse_double_quotes_lexem(t_data *data, char *str)
{
	uint32_t	len;
	char		*inside_quotes;

	len = 0;
	while ((str[len]) && str[len] != '"')
		++len;
	if (str[len] != '"')
	{
		unexpected_token(data, SYNTAX_ERR, '\0');
		prev_exec = 2;
	}
	else
	{
		inside_quotes = ft_substr(str, 0, len);
		if (!just_a_dollar_sign(inside_quotes))
			parse_vars_in_str(data, &inside_quotes);
		push_back_lexem(&data->lexems, inside_quotes, data->state);
	}
	return (len + 2);
}

uint32_t	parse_single_quotes_lexem(t_data *data, char *str)
{
	uint32_t	len;

	len = 0;
	while (str[len] && str[len] != 39)
		++len;
	if (str[len] != 39)
	{
		unexpected_token(data, SYNTAX_ERR, '\0');
		prev_exec = 2;
	}
	else
		push_back_lexem(&data->lexems, ft_substr(str, 0, len), data->state);
	return (len + 2);
}

uint32_t	parse_word_lexem(t_data *data, char *str)
{
	uint32_t	len;

	len = 0;
	while (str && str[len] && allowed_lexem_char(str[len]))
		++len;
	push_back_lexem(&data->lexems, ft_substr(str, 0, len), data->state);
	return (len);
}
