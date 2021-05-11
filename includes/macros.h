/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:24:08 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 15:02:10 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
**	Costum errors corresponding (int) values
*/

# define INVALID_CUB -1
# define INVALID_MAP -2
# define TOO_MANY_ARGUMENTS -3

/*
**	Display related (int) values 
*/

# define MAX_RESOLUTION_X 2560
# define MAX_RESOLUTION_Y 1440
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define WALL '1'
# define SPACE ' '
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEAST 'W'
# define SPRITE '2'

# define TEXTURES_AMOUNT 5

/*
**  key (int) values for mlx
*/

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

# define PI 3.1415926535

/*
**  parameters for scaling and moving the sprites
*/
# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.05

#endif