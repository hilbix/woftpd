#include <stdio.h>
#include <stdarg.h>

#include "FORMAT.h"

#define	_LF		"\n"

#define	FORMAT(...)	FORMAT_(__VA_LIST__, NULL)
static void

#define	OOPS(...)	OOPS_(__VA_LIST__, NULL)
static void
_OOPS(const char *s, ...)
{
  va_start(list, s);
  FORMAT(stdout, NULL, s, list);
  va_end(list, s);
}

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
    OOPS("Usage: ", arg0(F), " socket|- [dir [cmd args..]]", FORMAT_LF,
	"\tWrite Only FTP server version ", WOFTPD_VER, " compiled ", __DATE__, FORMAT_LF
	"\tURL: ", WOFTPD_URL);
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
