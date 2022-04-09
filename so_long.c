#include "header.h"

int	myF(int key, void *n)
{
	if (key == 0)
		write(1, "<==\n", 5);
	else if (key == 13)
		write(1, "^\n", 3);
	else if (key == 2)
		write(1, "==>\n", 5);
	else if (key == 1)
		write(1, "\\/\n", 4);
	else if (key == 53)
		exit(0);
	
	printf (";;;;;=? %d\n", key);
	return 0;
}
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*relative_path = "./img.png";
	int		img_width;
	int		img_height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hjrifi");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	mlx_key_hook(win_ptr, myF, "maroc");
	mlx_loop(mlx_ptr);
	return(0);
}

