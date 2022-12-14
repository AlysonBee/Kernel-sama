#include "../cpu/types.h"
#include "string.h"

int	hexlength(int number)
{
	int length;

	length = 0;
	while (number > 0)
	{
		number /= 16;
		length++;
	}
	return (length);
}

void	int_to_hex(int number)
{
	static char	hexadecimal[] = "0123456789abcdef";
	int		c;
	char		str[hexlength(number)];
	int		size;

	size = hexlength(number);
	str[size] = '\0';
	size--;
	while (number > 0)
	{
		c = number % 16;
		str[size] = hexadecimal[c];
		size--;
		number /= 16;
	}
	kprint("0x");
	kprint(str);
}


void	print_bin(int n) 
{
	char s[20];
	int i = 0;
	while (n > 0) {
		if (n % 2 == 0) {
			s[i] = '0';
		} else {
			s[i] = '1';
		}
		n /= 2;
		i++;
	}
	print_num(n);
	s[i] = '\0';
	reverse(s);
}


void	print_num(int n)
{
	char s[20];
	int_to_ascii(n, s);
	kprint(s);
}

void hex_to_ascii(int n, char str[]) {
    append(str, '0');
    append(str, 'x');
    char zeros = 0;

    s32 tmp;
    int i;
    for (i = 28; i > 0; i -= 4) {
        tmp = (n >> i) & 0xF;
        if (tmp == 0 && zeros == 0) continue;
        zeros = 1;
        if (tmp > 0xA) append(str, tmp - 0xA + 'a');
        else append(str, tmp + '0');
    }

    tmp = n & 0xF;
    if (tmp >= 0xA) append(str, tmp - 0xA + 'a');
    else append(str, tmp + '0');
}

void int_to_ascii(int n, char str[]) {
	int i, sign;
	if ((sign = n) < 0) n = -n;
	i = 0;
	do {
		str[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0) str[i++] = '-';
	str[i] = '\0';

	reverse(str);
}

void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int strlen(char s[]) {
	int i = 0;
	while (s[i] != '\0') 
		++i;
	return i;
}

void append(char s[], char n) {
	int len = strlen(s);
	s[len] = n;
	s[len+1] = '\0';
}

void backspace(char s[]) {
	int len = strlen(s);
	s[len-1] = '\0';
}


int strcmp(char s1[], char s2[]) {
	int i;
	for (i = 0; s1[i] == s2[i]; i++) {
		if (s1[i] == '\0') 
			return 0;
	}
	return s1[i] - s2[i];
}
