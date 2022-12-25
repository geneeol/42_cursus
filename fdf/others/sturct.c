#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_img
{
	void	*img_ptr;
	void	*addr;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_vertex
{
	double	x;
	double	y;
	double	z;
}	t_vertex;

typedef struct s_map
{
	int		width;
	int		height;
	int		**map_org;
	t_vertex	**map_proj;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
}	t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	mlx = malloc(sizeof(t_mlx));
//	memset(mlx, 0, sizeof(t_mlx));
	printf("mlx_ptr: %p\n", mlx->mlx_ptr);
	printf("mlx_ptr: %p\n", mlx->win_ptr);
	printf("img.img_ptr: %p\n", mlx->img.img_ptr);
	printf("img.size_l: %d\n", mlx->img.size_l);
}
