# ft_realloc
 a simple none accurate and probably naive implementation of realloc

# about
One of the most annoying things of the 42-core-curriculum was handling reallocation properly, because realloc
is forbidden in almost every c-project.
Because of that I've written a small library that mirrors the purpose of realloc. It does not follow the STD and
is not a real implementation of realloc. It's purpose is more to simply handle reallocation more easily, norme compilant and
only using free and malloc.

# usage

clone the repo
```bash
git clone https://github.com/JeremieSiller/ft_realloc
```

ft_realloc only works on pointers that have been allocated by ft_malloc:
```c
int *ptr;

ptr = ft_malloc(100);
if (!ptr) //malloc failed
  exit(1);
```

ft_realloc creates a new pointer and ft_frees the old pointer:
```c
int *tmp;

tmp = ft_realloc(ptr, 150);
if (!tmp) //malloc failed
  exit(1);
```
every pointer allocated with either ft_malloc or ft_realloc has to
be properly freed by ft_free
```c
ft_free(tmp);
```



understand the code!!!

I won't tell you to not copy the code in to your libft, but the best thing
would probably be to write your own implementation e.g. using a struct to save the size.
You could also write a garbage collector by keeping track of all allocated nodes.

# How it works?

Why is reallocation horrible without realloc?
When reallocation you usually want to copy the old data to the newliy allocated memory. Inorder to do that, you
need to know the size of the pointer which can make your code messy.
Malloc saves the size of the pointer internally which allows realloc to work without needing the size as a parameter.

This implementation allocates the a bit more than the reall malloc / realloc. 
It then saves the size of the pointer in that extra allocated memory. Ft_realloc is able to read that and copy
everything from the older pointer to the newily allocated memory.


