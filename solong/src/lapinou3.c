/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapinou3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:04 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/05 15:31:06 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lapinou_eat(t_param *param)
{
	if (param->map[param->lapinou->y][param->lapinou->x]->type == 1)
	{
		param->lapinou->carrots++;
		param->map[param->lapinou->y][param->lapinou->x]->type = 4;
		if (param->lapinou->carrots != param->lapinou->want)
			ft_printf("Lapinou a deja mange %d carottes.\nIl en veut %d.\n",
				param->lapinou->carrots, param->lapinou->want);
		else
			ft_printf("Lapinou a mange toutes les carottes (%d) "
				"!\nIl peut y aller.\n",
				param->lapinou->want);
	}
}

void	lapinou_exit(t_param *param)
{
	if (param->map[param->lapinou->y][param->lapinou->x]->type == 3)
	{
		if (param->lapinou->carrots == param->lapinou->want)
			mlx_close_window(param->mlx);
		else
			ft_printf("Il faut manger toutes les carottes avant de sortir !\n");
	}
}
