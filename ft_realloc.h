#ifndef FT_REALLOC_H
# define FT_REALLOC_H

# include <stddef.h>

void	*ft_malloc(size_t s);
void	ft_free(void *ptr);
size_t	ft_malloc_size(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

#endif