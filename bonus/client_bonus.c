#include "../minitalk.h"

void handler_signal(int sig)
{
    if (sig == SIGUSR1)
        write(1, "✔ received\n", 14);
}

int ft_atoi(char *str)
{
    int result;
    int i;

    result = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        result *= 10;
        result += str[i] - '0';
        i++;
    }
    return (result);
}

void    send_char(int pid, char c)
{
    int    bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(500);
        bit++;
    }
}

int    main(int argc, char **argv)
{
    int    pid;
    int        i;

    if (argc != 3)
        return(write(2, "Error : Problem ARG\n", 20), 1);
    signal(SIGUSR1, handler_signal);
    pid = ft_atoi(argv[1]);
    if (pid <= 0)
        return (write(2, "Error: Invalid PID\n", 19), 1);
    i = 0;
    while (argv[2][i])
    {
        send_char(pid, argv[2][i]);
        i++;
    }
    send_char(pid, '\0');
}