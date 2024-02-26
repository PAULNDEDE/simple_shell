#include "shell.h"

/**
 * display_prompt - function displays a  shell prompt using $ sign
 */
void display_prompt(void)
{
printf("$ ");
fflush(stdout);
}
/**
 * execute_cmd - Execute a given command from the user
 * @cmd: The command to be executed executed
 */
void execute_cmd(char *cmd)
{
pid_t pid;
int status;

pid = fork();

if (pid < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmd, cmd, (char *)NULL);
perror("Execution failed");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0( success)
 */
int main(void)
{
char buffer[BUFFER_SIZE];

while (1)
{
display_prompt();
if (!fgets(buffer, BUFFER_SIZE, stdin))
break;
char *newline = strchr(buffer, '\n');
if (newline)
*newline = '\0';

execute_cmd(buffer);
}

printf("\n");
return (0);
}
