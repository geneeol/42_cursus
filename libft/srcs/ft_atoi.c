int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

int	is_sign(char ch)
{
	if (ch == '+' || ch == '-')
		return (1);
	else
		return (0);
}

int	is_number(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	else
		return (0);
}

//NULL_PTR segmentation fault 
int	ft_atoi(const char *str)
{
