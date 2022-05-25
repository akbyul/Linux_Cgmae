#include "../H_FILES/set_struct_mecro.h"

int	 control_file_struct(void)
{
	SET_SCREEN_STRUCT(a, "map.txt", 0, 0);
	SET_SCREEN_STRUCT(b, "start_screen.txt", 10, 19);
	SET_SCREEN_STRUCT(c_1, "new_or_load.txt", 10, 11);
	SET_SCREEN_STRUCT(c_2, "press_the_arrow_keys.txt", 30, 20);
	SET_SCREEN_STRUCT(d_a_1, "new_game_1.txt", 10, 20);
	SET_SCREEN_STRUCT(d_a_2, "new_game_1_min.txt", 18, 20);
	SET_SCREEN_STRUCT(d_b, "new_game_2_check.txt", 10, 20);
	SET_SCREEN_STRUCT(d_c_1, "new_game_3.txt", 3, 11);
	SET_SCREEN_STRUCT(d_c_2_1, "new_game_3_slime.txt", 16, 14);
	SET_SCREEN_STRUCT(d_c_2_2, "new_game_3_slime_name.txt", 14, 18);
	SET_SCREEN_STRUCT(d_c_2_3, "new_game_3_slime_stats.txt", 16, 34);
	SET_SCREEN_STRUCT(d_c_3_1, "new_game_3_mung.txt", 16, 14);
	SET_SCREEN_STRUCT(d_c_3_2, "new_game_3_mung_name.txt", 14, 18);
	SET_SCREEN_STRUCT(d_c_3_3, "new_game_3_mung_stats.txt", 16, 34);
	SET_SCREEN_STRUCT(d_d, "new_game_4_check.txt", 10, 20);

	SET_SCREEN_STRUCT(x_1, "cursor_1.txt", 2, 2);
	SET_SCREEN_STRUCT(x_2, "cursor_2.txt", 2, 2);
	SET_SCREEN_STRUCT(y_1, "arrow_1.txt", 18, 3);
	SET_SCREEN_STRUCT(y_2, "arrow_2.txt", 18, 58);
	return (0);
}
