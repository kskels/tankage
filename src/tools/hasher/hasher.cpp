
#include <md5/md5.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
 * Print a signature
 */
static	void	print_sig(const unsigned char *sig)
{
  const unsigned char	*sig_p;
  
  for (sig_p = sig; sig_p < sig + MD5_SIZE; sig_p++) {
    (void)printf("%02x", *sig_p);
  }
}

/*
 * Read in from stdin and run MD5 on the input
 */
static	void	read_file(const char *filename)
{
  unsigned char	sig[MD5_SIZE];
  char		buffer[4096];
  md5_t		md5;
  int		ret;
  FILE		*stream;
  
  if (strcmp(filename, "-") == 0) {
    stream = stdin;
  }
  else {
    stream = fopen(filename, "r");
    if (stream == NULL) {
      perror(filename);
      exit(1);
    }
  }
  
  md5_init(&md5);
  
  /* iterate over file */
  while (1) {
    
    /* read in from our file */
    ret = fread(buffer, sizeof(char), sizeof(buffer), stream);
    if (ret <= 0)
      break;
    
    /* process our buffer buffer */
    md5_process(&md5, buffer, ret);
  }
  
  md5_finish(&md5, sig); 
  
  if (stream != stdin) {
    (void)fclose(stream);
  }
  
  //(void)printf("%25s '", "Resulting signature:");
  //print_sig(sig);
  //(void)printf("'\n");

  //convert to string to print 
  md5_sig_to_string(sig, buffer, sizeof(buffer));
  (void)printf("%25s '%s'\n", "Results of md5_to_string:", buffer);
  
  //[> now we convert it from string back into the sig <]
  //md5_sig_from_string(sig, buffer);
  
  //(void)printf("%25s '", "After md5_from_string:");
  //print_sig(sig);
  //(void)printf("'\n");
}

int main(int argc, char* argv[]) {
  if (argc < 2 || !argv[1]) 
    return -1;
  read_file(argv[1]);
  return 0;
} // main

