#include <wong.h>

void	init_tab_place(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			CASEX(x, y) = ((x + 1) + x) * (WINX(env) / 8);
			CASEY(x, y) = ((y + 1) + y) * (WINY(env) / 8);
			x++;
		}
		y++;
	}
}

void	init_case(t_env *env, int x, int y, int value)
{
	CASEV(x, y) = 0;
	CASESTR(x, y) = ft_itoa(value);
}

void	init_tab(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			CASEV(x, y) = 0;
			CASEC(x, y) = 0;
			CASESTR(x, y) = ft_itoa(0);
			x++;
		}
		y++;
	}
	init_tab_place(env);
}
