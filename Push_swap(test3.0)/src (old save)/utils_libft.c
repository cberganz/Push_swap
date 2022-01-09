#include "push_swap.h"

//static size_t	ft_strlen(const char *s)
//{
//	size_t	len;
//
//	len = 0;
//	while (s[len])
//		len++;
//	return (len);
//}
//
//static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
//{
//	size_t	i;
//
//	i = 0;
//	if (size == 0)
//		return (ft_strlen(src));
//	while (src[i] && i < size - 1)
//	{
//		dst[i] = src[i];
//		i++;
//	}
//	dst[i] = '\0';
//	while (src[i])
//		i++;
//	return (i);
//}
//
//char	*ft_strdup(const char *s)
//{
//	char	*sdup;
//	size_t	len;
//
//	len = ft_strlen(s) + 1;
//	sdup = malloc(len * sizeof(char));
//	if (!sdup)
//		return (NULL);
//	ft_strlcpy(sdup, s, len);
//	return (sdup);
//}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
