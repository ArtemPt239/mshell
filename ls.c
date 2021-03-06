#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (int argc, char ** argv)
{
  DIR *dp;
  struct dirent *ep;
  if(argc < 2){
    perror("too few arguments");
    return 1;
  }
       
  dp = opendir (argv[1]);

  if (dp != NULL)
  {
    while (ep = readdir (dp))
      puts (ep->d_name);

    (void) closedir (dp);
  }
  else
    perror ("Couldn't open the directory");

  return 0;
}
