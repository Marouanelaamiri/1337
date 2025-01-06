/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:24:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/05 22:25:59 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int main()
{
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;

    // Initialize MiniLibX
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Image Display");

    // Load the image (replace "path_to_image.xpm" with the actual path to your XPM image file)
    img = mlx_xpm_file_to_image(mlx, "background1.xpm", &img_width, &img_height);
    if (!img)
    {
        // Handle error if image loading fails
        return 1;
    }

    // Display the image at the center of the window
    int x_center = (WIN_WIDTH - img_width) / 2;
    int y_center = (WIN_HEIGHT - img_height) / 2;
    mlx_put_image_to_window(mlx, win, img, x_center, y_center);

    // Enter the event loop
    mlx_loop(mlx);

    return 0;
}