#include <stdio.h>

struct _woftpd
  {
    const char		*arg0;	/* cmdline:0		*/
    const char		*sock;	/* cmdline:1		*/
    const char		*dir;	/* cmdline:2 or .	*/
    const char * const	*cmd;	/* cmdline:3+ or NULL	*/
  };

void
usage(struct _woftpd *F)
{
  if (!*F->sock)
    OOPS("Usage: ", arg0(F), " socket|- [dir [cmd args..]]", OOPS_LF,
	"\tWrite Only FTP server
}

/* no options
 * 1: socket or -
 * 2: directory (else current)
 * 3+: cmd args.. (missing: none)
 */
int
main(int argc, const char * const *argv)
{
  struct _woftpd	cfg;

  cfg.arg0	= argv[0];
  cfg.sock	= argc>1 ? argv[1] : "";
  cfg.dir	= argc>2 ? argv[2] : ".";
  cfg.cmd	= argc>3 ? argv+3 : 0;

  usage(&cfg);
  sock(&cfg);
  loop(&cfg);

  /* never reached	*/
  return 0;
}

