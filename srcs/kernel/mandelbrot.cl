__kernel void mandelbrot(__global double *cr, __global double *ci, __global int *i, __global size_t *r)
{
	__private int gid;

	gid = get_global_id(0);

	r[7*gid+0] = get_global_size(0);
	r[7*gid+1] = get_global_id(0);
	r[7*gid+2] = get_local_size(0);
	r[7*gid+3] = get_local_id(0);
	r[7*gid+4] = get_num_groups(0);
	r[7*gid+5] = get_group_id(0);
	r[7*gid+6] = get_global_offset(0);
}
