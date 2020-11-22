#include <stdio.h>
#include <unistd.h>
/* 
 *Main - PID
 *
 *Return: Always 0
 */
int main(void) {
pid_t s_pid;
  
s_pid = getpid();
printf("%u\n", s_pid);
return 0;
}
