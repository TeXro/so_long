	void	*mlx;
	void	*mlx_win;
	void	*g;
	void	*w;
	void	*p;
	int		z;
	int 	x;
	int 	y;
	int 	t;
	int 	ty;
	int 	move;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 64 * 10, 64 * 10, "mario");
	// g = mlx_xpm_file_to_image(mlx, "./asset/ground.xpm", &z, &z);
	// w = mlx_xpm_file_to_image(mlx, "./asset/wall.xpm", &z, &z);
	// p = mlx_xpm_file_to_image(mlx, "./asset/player.xpm", &z, &z);
	// x = 0;
	// move = 0;

	// mlx_put_image_to_window(mlx, mlx_win, p, 0, 0);
	// mlx_loop(mlx);


	// get_map();
	// mlx_put_image_to_window(mlx, mlx_win, pr, 0, 0);
	// mlx_destroy_image(mlx, p);
	// mlx_destroy_image(mlx, g);
	// mlx_destroy_image(mlx, w);
	// mlx_destroy_window(mlx, mlx_win);
	// mlx_destroy_display(mlx);
	// free(mlx);
	// mlx_hook(mlx, 17, (1L<<0), test, NULL);

int test(void *tt)
{
	(void)tt;
	exit(0);
}

// void get_map()
// {
// 	char *line;
// 	int fd;

// 	fd = open("map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
	
	
// }



#include "so_long.h"

char	*gen_line(char **saved, char *buffer)
{
	char	*new_saved;
	char	*line;
	char	*nline_pos;

	if (buffer)
		free(buffer);
	if (ft_strchs(*saved, '\n'))
	{
		nline_pos = ft_strchs(*saved, '\n');
		line = malloc(ft_strchi(*saved, '\n') + 2);
		ft_memcpy(line, *saved, ft_strchi(*saved, '\n') + 1);
		new_saved = ft_strjoin(NULL, nline_pos + 1);
		free(*saved);
		*saved = new_saved;
	}
	else
	{
		line = ft_strjoin(*saved, NULL);
		*saved = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		saved = ft_strjoin(saved, buffer);
		if (ft_strchs(saved, '\n'))
			return (gen_line(&saved, buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (saved && *saved && bytes_read == 0)
		return (gen_line(&saved, buffer));
	free(saved);
	saved = NULL;
	return (free(buffer), NULL);
}
