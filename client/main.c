#include "client.h"

static void free_converted(char **str, size_t len)
{
	while (len)
	{
		len--;
		free(str[len]);
	}
	free(str);
}
// TO_DO: remove "+48" in final version to have only 0 and 1 in values
static char *convert_char(char c)
{
	char *character;
	int i;

	i = 7;
	character = malloc(9);
	if (!character)
		return NULL;
	while (i >= 0 && c > 0)
	{
		character[i] = (c % 2) + 48; 
		c /= 2;
		i--;
	}
	while (i >= 0)
	{
		character[i] = 48;
		i--;
	}
	character[8] = 0;
	return (character);
}

static char **convert_str(char *str)
{
	size_t len;
	size_t i;
	char **converted;

	i = 0;
	len = ft_strlen(str);
	converted = malloc((sizeof(char *) * len) + 1);
	if (!converted)
		exit(EXIT_FAILURE);
	while (str[i])
	{
		converted[i] = convert_char(str[i]);
		if (!converted[i])
		{
			free_converted(converted, i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	converted[len] = NULL;
	return (converted);
}

int	main(int argc, char **argv)
{
	char **converted;
	size_t i;

	i = 0;
	if (argc != 3)
		ft_printf("usage: ./client [pid] [message]");
	else
	{
		converted = convert_str(argv[2]);
		while (converted[i])
		{
			ft_printf("%s\n", converted[i]);
			i++;
		}
		send_converted(ft_atoi(argv[1]), converted);
		free_converted(converted, ft_strlen(argv[2]));
	}
	return (EXIT_SUCCESS);
}