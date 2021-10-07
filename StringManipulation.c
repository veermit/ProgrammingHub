#include <stdio.h>

void removeduplicate(char *str, int end)
{
	// Used as start in the modified string
	int start = 0;

	// Traverse through all characters
	for (int i=0; i<end; i++) 
	{

	// Check if str[i] is present before it 
	for (int j=0; j<i; j++)
	{
		if (str[i] == str[j])
			break;
	} 

	// If not present, then add it to
	// result.
	if (j == i)
		str[start++] = str[i];
 
	}
    
	return;
}

int main()
{
  char carrBuff[10] = "Veer";
  removeduplicate(carrBuff, 10);
  return;
  
}
