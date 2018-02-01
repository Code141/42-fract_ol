/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 22:22:26 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/16 11:48:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_check_base_atoi(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if ((base[i] == '+' || base[i] == '-')
					|| (base[i] == base[j])
					|| (base[i] < 32 || base[i] == 127))
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static int		ft_str_is_base(char *str, char *base, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '+' || str[i] == '-')
			i++;
		else
		{
			while (base[j])
			{
				if (str[i] != base[j])
					j++;
				else
					break ;
			}
			if (j == size)
				return (0);
			i++;
		}
	}
	return ((str[0]) ? 1 : 0);
}

static int		ft_find_index_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && c != base[i])
		i++;
	if (!base[i])
		return (-1);
	return (i);
}

static int		ft_convert(char *str, char *base, int size)
{
	int i;
	int nb;
	int current_based;

	i = 0;
	nb = 0;
	while (str[i])
	{
		current_based = ft_find_index_in_base(str[i], base);
		if (current_based != -1)
			nb = (nb * size) + current_based;
		else
			return (nb);
		i++;
	}
	return (nb);
}

int				ft_atoi_base(char *str, char *base)
{
	int i;
	int nb;
	int neg;
	int size;

	nb = 0;
	i = 0;
	size = ft_check_base_atoi(base);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	neg = (str[i] == '-') ? 1 : 0;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	if (!ft_str_is_base(str, base, size) || size < 2)
		return (0);
	nb = ft_convert(str + i, base, size);
	return ((!neg) ? nb : -nb);
}
