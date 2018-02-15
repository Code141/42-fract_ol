__kernel void mandelbrot(__global double *cr, __global double *ci, __global int *i, __global int *r)
{
	*r = (int)(*cr+*ci)+*i;
}
