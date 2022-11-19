
#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#ifdef HAVE_ERRNO_H
#  include <errno.h>
#endif

#ifdef HAVE_ERRNO_H
# ifndef SYS_ERRLIST_DECLARED
extern int errno, sys_nerr;
extern char *sys_errlist[];
# endif
#endif

#ifdef dll
#include "dllfile.h"
#endif

extern char *progname;

void error( char *s1, char *s2 )
{
	if( progname != NULL )
		fprintf( stderr, "%s: ", progname );
	fprintf( stderr, s1, s2 );
#ifdef HAVE_ERRNO_H
# ifdef SYS_ERRLIST_DECLARED
	if( errno > 0 && sys_nerr > errno )
		fprintf( stderr, " (%s)", sys_errlist[errno] );
	fputc( '\n', stderr );
# endif
#endif
	exit( -1 );
}
