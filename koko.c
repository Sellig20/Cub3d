int	ft_open_map(char **argv, t_data *x)
{
	char	*str;
	char	*join;
	char	*tmp_j;

	x->max = 0;
	if (ft_open_file(argv, x) == 1)
		return (1);
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	x->len = ft_strlen(str);
	join = NULL;
	tmp_j = NULL;
	while (str)
	{
		x->tmp_len = ft_strlen(str);
		if (x->tmp_len > x->len)
			x->len = x->tmp_len;
		x->max++;
		tmp_j = ft_strjoin(join, str);
		if (tmp_j == NULL)
		{
			free(str);
			get_next_line(x->file, 1);
		}
		free(tmp_j);
		free(str);
		str = get_next_line(x->file, 0);
	}
	free(join);
	free(str);
	ft_map_split(tmp_j, x);
	//free(tmp_j);
	get_next_line(x->file, 1);
	return (0);
}
