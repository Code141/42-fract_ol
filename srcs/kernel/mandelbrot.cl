__kernel void mandelbrot(__global int *i, __global int *r)
{
	__local int x;
	__local int width;
	__local int y;
	__local int height;

	x = get_global_id(0);
	width = get_global_size(0);
	y = get_global_id(1);
	height = get_global_size(1);

	r[x + (y * width)] = 0x0000ff;



//	printf("[KERNEL]	{G} x : %d; y : %d;\n", x, y);
}
