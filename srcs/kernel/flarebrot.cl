__kernel void	flarebrot(__global double *params, __global int *r)
{
	__private int	x;
	__private int	width;
	__private int	y;
	__private int	height;

	width = get_global_size(0);
	height = get_global_size(1);
	x = get_global_id(0);
	y = get_global_id(1);

/* PARAMETRAGE */

	__private double	zoom;
	__private double	pos_x;
	__private double	pos_y;
	__private int		max_iter;
	__private double	color_indice;

	max_iter = params[0];
	zoom = params[1];
	pos_x = params[2];
	pos_y = params[3];
	color_indice = params[4];

	__private double	c_r_e;
	__private double	c_i_e;

	c_r_e = (params[5] - pos_x) * zoom / 24;
	c_i_e = (params[6] - pos_y) * zoom / 24;

	__private double	c_r;
	__private double	c_i;

	c_r = (-(width / 2) + x) / zoom + pos_x;
	c_i = (-(height / 2) + y) / zoom + pos_y;

	__private double	z_r;
	__private double	z_i;
	__private double	z_r_c;
	__private double	z_i_c;
	__private int		i;

	i = 0;
	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;

	z_i = c_i_e * z_r * z_i + c_i;
	z_r = z_r_c - z_i_c + c_r * c_r_e ;

	while (z_r_c + z_i_c <= 4 && i < max_iter)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = c_i_e * z_r * z_i + c_i;
		z_r = z_r_c - z_i_c + c_r * c_r_e;
		i++;
	}









	__private	unsigned int color;
	__private	float pos;

	pos = (float)i / (float)max_iter;

	color = 0;
// B G R A
	if (pos == 1)
		color = 0xffffff;
	else
	{
		color += (unsigned int)(255 * ((sinpi((pos + M_PI_F * 2 * color_indice) * 8) + 1) / 2)) << 16;
		color += (unsigned int)(255 * ((sinpi(pos * 6) + 1) / 2)) << 8;
		color += 0x0000ff * (1 - ((sinpi(pos * 3 * color_indice) + 1) / 2));
	}
	r[x + (y * width)] = color;
}
