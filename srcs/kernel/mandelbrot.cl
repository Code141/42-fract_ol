__kernel void mandelbrot(__global double *cr, __global double *ci, __global int *i, __global size_t *r)
{
	__private int global_id;
	global_id = get_global_id();
	r[global_id][0] = get_global_size(0);
	r[global_id][1] = get_global_id(0);
	r[global_id][2] = get_local_size(0);
	r[global_id][3] = get_local_id(0);
	r[global_id][4] = get_num_groups(0);
	r[global_id][5] = get_group_id(0);
	r[global_id][6] = get_global_offset(0);
}
