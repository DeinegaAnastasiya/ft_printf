/*int				rec_flag(int *flag)
{
	*flag = 1;
	return (1);
}

int				check_flag(const char *arg, t_print *get)
{
	int i;

	i = 0;
	if (*arg == '%')
		return (0);
	else if (*arg != '\0' && ft_strchr("f", *arg))
	{
		if (*arg == '-' && get->align != 1)
			return (rec_flag(&get->align));
		else if (*arg == '+' && get->plus != 1)
			return (rec_flag(&get->plus));
		else if (*arg == ' ' && get->space != 1)
			return (rec_flag(&get->space));
		else if (*arg == '#' && get->oct != 1)
			return (rec_flag(&get->oct));
		else if (*arg == '0' && get->width_zero != 1)
			return (rec_flag(&get->width_zero));
	}
	return (0);
}

int				find_lenth(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		len++;
	}
	if (num > 0 && num < 10)
		return (len + 1);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int				check_width(const char *arg, t_print *get)
{
	int width;

	if (ft_isdigit(*arg) == 1)
	{
		width = ft_atoi(arg);
		if (width >= 0)
		{
			get->width = width;
			return (find_lenth(width));
		}
	}
	else if (*arg == '*')
	{
		width = va_arg(get->val, int);
		if (width < 0)
			width = width * (-1);
		get->width = width;
		return (1);
	}
	return (0);
}

int				check_prec(const char *arg, t_print *get)
{
	return (0);
}

int				check_format(t_print *get, const char *format)
{
	size_t 		i;
	size_t 		n;
	
	i = 0;
	n = ft_strlen(format);
	while (i < n)
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			get->out_ch += 1;
		}
		else if (format[i] == '%')
		{
			i++;
			i += check_flag(&format[i], get);
			i += check_width(&format[i], get);
			i += check_prec(&format[i], get);
			i += check_long(&format[i], get);
			i += check_type(&format[i], get);
			if (print_get(get))
				alloc_pf(get);
		}
		i++;
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	t_print				get;

	if (format == NULL)
		return (0);
	alloc_pf(&get);
	va_start(get.val, format);
	if (!(check_format(&get, format)))
	{
		alloc_pf(&get);
		return (-1);
	}
	va_end(get.val);
	return (get.out_ch);
}*/