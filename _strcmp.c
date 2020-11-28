#include "header.h"
/**
 *_strcmp - function that compares two strings
 *@s1: st string to be compared
 *@s2: nd string to be compared
 *Return: returns to k
 */
int _strcmp(char *s1, char *s2)
{
  int i;
  int j = 0;
  int k;

  for (i = 0; s1[i] != '\0' && s2[i] != '\0' && j == 0; i++)
    {
      if (s1[i] == s2[i])
	{
	  k = 0;
	}
      else
	{
	  j = 1;
	  k = s1[i] - s2[i];
	}
    }
  return (k);
}
