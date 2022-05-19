#include <stdlib.h>
#include <stddef.h>

/*
** ft_malloc allocates enough memory 
** to save the allocated size, to be able to use ft_realloc
** in case you want to set everything to 0 you could also call calloc
** or your own ft_calloc in case calloc is not allowed
*/
void	*ft_malloc(size_t s)
{
	size_t	*ret;

	ret = malloc(sizeof(size_t) + s);
	if (!ret)
		return (NULL);
	return (&ret[1]);
}

/*
** frees ptr allocated with ft_malloc or ft_realloc
*/
void	ft_free(void *ptr)
{
	free((size_t *)ptr - 1);
}

/*
** returns the allocated size of a pointer
*/
size_t	ft_malloc_size(void *ptr)
{
	return (((size_t *) ptr)[-1]);
}

/*
** reallocates a ptr to size, can be adjusted to use 
** ft_calloc instead of ft_malloc
** does not behave like the real realloc 
** it also resizes the pointer if size is smaller than the pointer size
** there are other differences to the real realloc (e.g.):
** in case ptr == NULL, or ft_malloc_size(ptr) == size
*/
void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;
	size_t	i;

	i = 0;
	if (size == ft_malloc_size(ptr))
		return (ptr);
	tmp = ft_malloc(size);
	if (!tmp)
	{
		ft_free(ptr);
		return (NULL);
	}
	while (i < ft_malloc_size(ptr) && i < size)
	{
		((unsigned char *)tmp)[i] = ((unsigned char *)ptr)[i];
		i++;
	}
	ft_free(ptr);
	return (tmp);
}
