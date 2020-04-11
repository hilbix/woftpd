#include "minilib/all.h"

typedef struct _woftpd
  {
    const char		*arg0;	/* cmdline:0		*/
    const char		*sock;	/* cmdline:1		*/
    const char		*dir;	/* cmdline:2 or .	*/
    const char * const	*cmd;	/* cmdline:3+ or NULL	*/
  } *F;

static const char *
arg0(F F)
{
  const char	*p;

  p	= strrchr(F->arg0, '/');
  return p ? p+1 : F->arg0;
}

void
usage(F F)
{
  if (!*F->sock)
    OOPS("Usage: ", basename(F->arg0), " socket|- [dir [cmd args..]]", OUTlf,
        "\tWrite Only FTP server version ", GIT_VER, " compiled ", __DATE__, OUTlf,
        "\tURL: ", GIT_URL);
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

