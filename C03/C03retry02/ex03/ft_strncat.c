/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:27:32 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/20 07:31:25 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int main()
{
	char str1[] = "salut";
	char str2[] = "salutabccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
	char str3[] = "salut";
	char str4[] = "salutabccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";

	printf("%s\n", ft_strncat(str1, str2, 88));
	printf("%s\n", strncat(str3, str4, 88));
}
