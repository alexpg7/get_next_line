# :eye: get_next_line ![Static Badge](https://img.shields.io/badge/Barcelona-black?style=for-the-badge&logo=42&logoColor=%23FFFFFF)
![Static Badge](https://img.shields.io/badge/C-grey?style=flat)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

A function to read file descriptors' content. 

## :book: How to use it

1. Choose a standard file descriptor or open a file:
```C
fd = open("path", O_RDONLY);
```

2. Call ``get_next_line(fd)`` into a string:

```C
char  *str;
str = get_next_line(fd)
```
3. Use your string as you please.
> [!CAUTION]
> Remember to free `str` after using it, `get_next_line` uses malloc.
