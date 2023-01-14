#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_game game;

	init_game_struct(&game);
	validate_arg(&game, argc, argv);
	parsing_cub_file(&game, argv[1]);
	ft_printf("texture_no : %s\n", game.texture_no);
	ft_printf("texture_so : %s\n", game.texture_so);
	ft_printf("texture_we : %s\n", game.texture_we);
	ft_printf("texture_ea : %s\n", game.texture_ea);
	ft_printf("F :");
	for (int i = 0 ; i< 3; i++)
		ft_printf(" %d,", game.F[i]);
	ft_printf("C :");
	for (int i = 0 ; i< 3; i++)
		ft_printf(" %d,", game.C[i]);
	
}
