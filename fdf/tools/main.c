#include "./minilibx_mms_20210621/mlx.h"
#include <unistd.h>
#include <stdio.h>

int	deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1200, 720, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 251, 250, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 251, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 249, 250, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 249, 0xFF0000);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
