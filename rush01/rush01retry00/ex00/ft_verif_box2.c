int	ft_line_left_right2(char *str, int size, int x)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = 1;
	if (str[i] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = str[i];
	while (i < size - 1 && i <= x)
	{
		if (str[i] > max_value)
		{
			vue_count++;
			max_value = str[i];
		}
		i++;
	}
	if (vue_count <= str[0] - '0')
		return (1);
	return (0);
}

int	ft_line_right_left2(char *str, int size, int x)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = size - 2;
	if (str[i] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = str[i];
	while (i > 0 && i <= size - 1 - x)
	{
		if (str[i] > max_value)
		{
			vue_count++;
			max_value = str[i];
		}
		i--;
	}
	if (vue_count <= str[size - 1] - '0')
		return (1);
	return (0);
}

int	ft_column_up_down2(char **tab, int x, int size, int y)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = 1;
	if (tab[i][x] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = tab[i][x];
	while (i < size - 1 && i <= y)
	{
		if (tab[i][x] > max_value)
		{
			vue_count++;
			max_value = tab[i][x];
		}
		i++;
	}
	if (vue_count <= tab[0][x] - '0')
		return (1);
	return (0);
}

int	ft_column_down_up2(char **tab, int x, int size, int y)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = size - 2;
	if (tab[i][x] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = tab[i][x];
	while (i > 0 && i <= size - 1 - y)
	{
		if (tab[i][x] > max_value)
		{
			vue_count++;
			max_value = tab[i][x];
		}
		i--;
	}
	if (vue_count <= tab[size - 1][x] - '0')
		return (1);
	return (0);
}
