/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:09:00 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/05 21:14:26 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define SQUARE_SIZE 100

void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1)
    {
        mlx_pixel_put(mlx, win, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_square(void *mlx, void *win, int x_center, int y_center, int size, int color)
{
    int half_size = size / 2;
    int x0 = x_center - half_size;
    int y0 = y_center - half_size;
    int x1 = x_center + half_size;
    int y1 = y_center + half_size;

    draw_line(mlx, win, x0, y0, x1, y0, color); // Top side
    draw_line(mlx, win, x1, y0, x1, y1, color); // Right side
    draw_line(mlx, win, x1, y1, x0, y1, color); // Bottom side
    draw_line(mlx, win, x0, y1, x0, y0, color); // Left side
}

int main()
{
    void *mlx;
    void *win;

    // Initialize MiniLibX
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Square");

    // Draw a square at the center of the window
    draw_square(mlx, win, WIN_WIDTH / 2, WIN_HEIGHT / 2, SQUARE_SIZE, 0x00FF0000);

    // Enter the event loop
    mlx_loop(mlx);

    return 0;
}