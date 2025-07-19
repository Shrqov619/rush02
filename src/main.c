/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed.mansour <ahmed.mansour@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:01:37 by ahmed.mansour     #+#    #+#             */
/*   Updated: 2025/07/19 12:45:56 by ahmed.mansour    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_tens(int nbr)
{
	if (nbr >= 90)
		return (90);
	else if (nbr >= 80)
		return (80);
	else if (nbr >= 70)
		return (70);
	else if (nbr >= 60)
		return (60);
	else if (nbr >= 50)
		return (50);
	else if (nbr >= 40)
		return (40);
	else if (nbr >= 30)
		return (30);
	else if (nbr >= 20)
		return (20);
	else if (nbr <= 20)
		return (nbr);
	else
		return (0);
}

int	get_decimal_classes(int nbr)
{
	if (nbr >= 1000000000)
		return (1000000000);
	else if (nbr >= 1000000)
		return (1000000);
	else if (nbr >= 1000)
		return (1000);
	else if (nbr >= 100)
		return (100);
	else
		return (get_tens(nbr));
}

void	ft_print(int n, t_list *list, int *first)
{
	int	i;
	int	decimal_class;

	i = 0;
	decimal_class = get_decimal_classes(n);
	ft_print(n / decimal_class, list, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (list[i].nbr != decimal_class)
		i++;
	ft_putstr(list[i].number_name);
	if (decimal_class != 0 && n % decimal_class != 0)
		ft_print(n % decimal_class, list, first);
}

int	main(int ac, char **av)
{
	t_list	*list;
	int		first;

	first = 1;
	if (ac == 2)
	{
		if (ft_atoi(av[1]) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		list = create_list("dict.txt");
		ft_print(ft_atoi(av[1]), list, &first);
		ft_putchar('\n');
	}
	return (0);
}
