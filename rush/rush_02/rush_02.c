#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rush.h"
#include <stdio.h>
​ long long int read_num(char *str);
char *get_number_word(char *dict, int nb);
void print_num(char *number, int highest);
int is_numeric(char c);

​ int does_contain(long long int num)
{
    int i;
    int count;
    ​
        i = 0;
    count = 0;
    while (numlist[i] != -2)
    {
        if (numlist[i] == num)
            count++;
        i++;
    }
    return (count);
}
​ int get_full_num(char *str)
{
    int i;
    ​
        i = 0;
    while (str[i] && is_numeric(str[i]))
        i++;
    return (i);
}
​ int get_num_length(int nb)
{
    int i;
    int total;
    ​
        total = 1;
    i = 0;
    if (nb == 0)
        return (0);
    while (i < nb - 1)
    {
        total *= 10;
        i++;
    }
    return (total);
}
​ int validate_line(char *line)
{
    int i;
    long long int num;
    int printable;
    int column;
    ​
        i = 0;
    num = read_num(line);
    column = -1;
    printable = -1;
    if (num == -1 || !does_contain(num))
    {
        return (-1);
    }
    while (line[i] && line[i] != '\n')
    {
        if (line[i] == ':')
            column = 1;
        if (column == 1 && line[i] <= 126 && line[i] >= 33)
            printable = 1;
        i++;
    }
    if (column == -1 || printable == -1)
        return (-1);
    return (1);
}
​ int put_line(char *line, char *buff)
{
    int i;
    int printable;
    int count;
    int column;
    ​
        i = 0;
    count = 0;
    printable = 0;
    column = 0;
    if (validate_line(line) == -1)
    {
        return (0);
    }
    while (line[i] && line[i] != '\n' && is_numeric(line[i]))
    {
        buff[count] = line[i];
        i++;
        count++;
    }
    while (line[i] && line[i] != '\n')
    {
        if (line[i] == ':')
        {
            buff[count] = line[i];
            buff[count + 1] = ' ';
            i++;
            count += 2;
            break;
        }
        i++;
    }
    while (line[i] != 0 && line[i] != '\n')
    {
        if ((line[i] >= 33 && line[i] <= 126) || (printable && line[i] >= 32 && line[i] <= 126))
        {
            buff[count] = line[i];
            count++;
            printable = 1;
        }
        i++;
    }
    buff[count] = '\n';
    return (count + 1);
}
​ int get_file_size(int fildes)
{
    int readsz;
    char tempbuf[128];
    int total;
    ​
        readsz = -1;
    total = 0;
    while (readsz != 0)
    {
        readsz = read(fildes, tempbuf, 128);
        total += readsz;
    }
    return (total);
}
​ int reset_file(char *file, int fildes)
{
    close(fildes);
    return (open(file, O_RDONLY));
}
​ char *get_dict(int size, int fildes)
{
    char *dict;
    int i;
    char *temp;
    int count;
    ​
        temp = malloc(size + 1);
    dict = malloc(size + 1);
    read(fildes, temp, size);
    temp[size] = 0;
    i = 0;
    count = 0;
    while (temp[i])
    {
        if (i == 0 || temp[i - 1] == '\n')
        {
            count += put_line(&temp[i], &dict[count]);
        }
        i++;
    }
    return (dict);
}
​ int get_offset(int number, char *dict)
{
    int count;
    int last;
    int i;
    ​
        i = -1;
    last = 0;
    count = 0;
    while (dict[++i])
    {
        if (i == 0 || dict[i] == '\n')
        {
            if (i != 0)
                i++;
            while (dict[i] && dict[i] != ':' && dict[i] != '\n')
            {
                count++;
                i++;
            }
            i--;
            if (count < number && count >= last)
                last = count;
            count = 0;
        }
    }
    printf("%d \n", last);
    printf("%d \n", number);
    return (number - last);
}
​ void print_multiple(char *dict, int multi)
{
    char *number;
    ​
        number = get_number_word(dict, multi);
    print_num(number, multi);
}
​ void print_unit(char c, char *number, char *dict, int highest)
{
    int i;
    char *unit;
    ​
        i = 0;
    if (c > 47 && c <= 57)
    {
        if (c != 48)
        {
            unit = get_number_word(dict, c - 48);
            print_num(unit, highest);
            if (highest != 1)
                i = 0;
        }
        if (highest != 1)
            print_num(number, highest);
    }
}
​ void print_num(char *number, int highest)
{
    int i;
    ​
        i = 0;
    while (number[i] && number[i] != '\n')
    {
        write(1, &number[i], 1);
        i++;
    }
    if (highest != 1)
        write(1, " ", 1);
}
​ int print_offset(int offset, char *dict, char *num, int highest)
{
    int number;
    char *printnum;
    int retval;
    ​
        number = (num[0] - 48);
    retval = 0;
    if (offset == 1 && num[0] != '0')
    {
        if (num[0] == '1')
        {
            number = ((num[0] - 48) * 10) + (num[1] - 48);
            retval = 1;
        }
        else
            number = (num[0] - 48) * 10;
        printnum = get_number_word(dict, number);
    }
    else if (offset == 2 && num[0] != '0')
    {
        printnum = get_number_word(dict, number);
        print_num(printnum, highest);
        printnum = get_number_word(dict, 100);
    }
    else if (num[0] != '0')
        printnum = get_number_word(dict, number);
    if (num[0] != '0')
        print_num(printnum, highest);
    return (retval);
}
​ void find_number(char *num, char *dict)
{
    int i;
    int offset;
    int highest;
    char *number;
    ​
        highest = get_num_length(get_full_num(num));
    i = 0;
    if (highest == 1 && num[i] == '0')
    {
        print_num(get_number_word(dict, 0), highest);
        return;
    }
    while (i < get_full_num(num))
    {
        if (highest == 10)
        {
            if (num[i] == '1')
            {
                print_num(get_number_word(dict, 10 + (num[i + 1] - 48)), highest);
                i++;
            }
            else if (num[i] >= '2')
                print_num(get_number_word(dict, highest * (num[i] - 48)), highest);
            i++;
            highest = get_num_length(get_full_num(&num[i]));
        }
        if (highest == 1)
            number = get_number_word(dict, highest * (num[i] - 48));
        else
            number = get_number_word(dict, highest);
        if (number != NULL)
        {
            if (num[i] != '0')
            {
                print_unit(num[i], number, dict, highest);
            }
            i++;
            highest = get_num_length(get_full_num(&num[i]));
        }
        else
        {
            offset = get_offset(get_full_num(&num[i]), dict);
            printf("%d", offset);
            if (offset != 2 && offset != 1)
            {
                write(1, "Error\n", 6);
                return;
            }
            while (offset != -1)
            {
                if (print_offset(offset, dict, &num[i], highest))
                {
                    i++;
                    offset--;
                }
                i++;
                offset--;
            }
            i--;
            highest = get_num_length(get_full_num(&num[i]));
            number = get_number_word(dict, highest);
            if (num[i] != '0' || num[i - 1] != '0' || num[i - 2] != '0')
                print_multiple(dict, highest);
            i++;
            highest = get_num_length(get_full_num(&num[i]));
        }
    }
}
​ char *get_number_word(char *dict, int nb)
{
    int i;
    ​
        i = 0;
    while (dict[i])
    {
        if (i == 0 || dict[i - 1] == '\n')
        {
            if (read_num(&dict[i]) == nb)
            {
                while (dict[i] && dict[i] != ':')
                    i++;
                return (&dict[i + 2]);
            }
        }
        i++;
    }
    return (NULL);
}
​ long long int read_num(char *str)
{
    int i;
    long long int total;
    long long int pow;
    ​
        i = 0;
    pow = 1;
    total = -1;
    while (str[i] && str[i] != '\n' && is_numeric(str[i]))
    {
        i++;
    }
    if (i != 0)
        total = 0;
    i--;
    while (i > -1)
    {
        total += (str[i] - 48) * pow;
        pow *= 10;
        i--;
    }
    return (total);
}
​ int is_numeric(char c)
{
    if (c <= 57 && c >= 48)
        return (1);
    else
        return (0);
}
​ long long int ft_atoi(char *number)
{
    long long int ret;
    int i;
    long long int index;
    int start;
    ​
        ret = 0;
    index = 1;
    i = 0;
    while (number[i] != '+' && !is_numeric(number[i]))
    {
        if (number[i] != ' ' && number[i] != '	')
            return (-1);
        i++;
    }
    if (number[i] == '+' && !is_numeric(number[i + 1]))
        return (-1);
    if (number[i] == '+')
        start = i + 1;
    else
        start = i;
    i++;
    while (is_numeric(number[i]))
        i++;
    i--;
    while (is_numeric(number[i]))
    {
        ret += index * (number[i] - 48);
        index *= 10;
        i--;
    }
    if (ret > 4294967295)
        return (-1);
    return (start);
}
​ int main(int argc, char **argv)
{
    int fildes;
    char *k;
    int filesize;
    int i;
    ​
        i = 0;
    if (argc >= 2 && argc <= 3)
    {
        if (argc == 3)
            fildes = open(argv[1], O_RDONLY);
        else
            fildes = open("numbers.dict", O_RDONLY);
        i = ft_atoi(argv[1]);
        if (i == -1)
        {
            write(1, "Error\n", 6);
            return (1);
        }
        filesize = get_file_size(fildes);
        fildes = reset_file("numbers.dict", fildes);
        k = get_dict(filesize, fildes);
        find_number(&argv[1][i], k);
    }
}