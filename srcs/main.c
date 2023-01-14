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
	ft_printf("F : %X\n", game.F_hex);
	ft_printf("C : %X\n", game.C_hex);
}
