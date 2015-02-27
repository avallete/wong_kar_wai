#include <wong.h>


void	grep_window_value(t_env *env)
{
	getmaxyx(stdscr, env->win.win_y, env->win.win_x);
	env->win.win_y--;
	env->win.win_x--;
	if (WINX(env) < 12 || WINY(env) < 12)
	{
		ft_putsterr("Window size too small\n");
		env->infos.echap = 1;
	}
}

void	draw_cross(unsigned int x, unsigned int y, unsigned maxx, unsigned maxy)
{
	unsigned int tmp;

	tmp = x;
	while (tmp < maxx)
		mvprintw(y, tmp, "."), tmp++;
	while (y < maxy)
		mvprintw(y, maxx / 2, "."), y++;
	while (x < maxx)
		mvprintw(maxy / 2, x, "."), x++;
}

void	draw_tab(t_env *env)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (x < WINX(env))
		mvprintw(y, x, "."), x++;
	while (y < WINY(env))
		mvprintw(y, x, "."), y++;
	while (x > 0)
		mvprintw(y, x, "."), x--;
	while (y > 0)
		mvprintw(y, x, "."), y--;
	draw_cross(0, 0, WINX(env), WINY(env));
	draw_cross(0, (WINY(env) / 2), (WINX(env)), (WINY(env) / 2));
	draw_cross(0, (WINY(env) - WINY(env) / 4), (WINX(env)), (WINY(env) / 2));
	draw_cross(0, 0, (WINX(env) / 2), (WINY(env)));
	draw_cross(0, 0, (WINX(env) / 2) + WINX(env), (WINY(env)));
}

void	expose_term(t_env *env)
{
	clear();
	mvprintw(0, 0, "o");
	mvprintw(1, env->win.win_x, "o");
	mvprintw(env->win.win_y, 1, "o");
	mvprintw(env->win.win_y, env->win.win_x, "o");
	draw_tab(env);
	refresh();
}

void	new_window(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
}

void	grep_resize(int c)
{
	if (c)
		c = c;
}

void	key_hook(t_env *env, int c)
{
	if (c == K_ECHAP)
		env->infos.echap = 1;
}

void	play_it(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	while (1 && (!(env->infos.echap)))
	{
		expose_term(env);
		grep_window_value(env), expose_term(env);
		key_hook(env, getch());
	}
	if (env->infos.echap)
		endwin();
}

int	main(void)
{
	t_env	env;
	enum	WIN_VALUE;

	env.def = WIN_VALUE;
	env.infos.echap = 0;
	if (!((env.def) % 2))
	{
		new_window();
		grep_window_value(&env);
		play_it(&env);
	}
	else
		ft_printf("Error bad WIN_VALUE, not 2 pow");
	return (0);
}
