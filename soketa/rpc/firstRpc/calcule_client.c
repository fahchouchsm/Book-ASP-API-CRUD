#include "calcule.h"


void
maths_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	int  puiss2_1_arg;
	float  *result_2;
	operandes  multxy_1_arg;
	
	
	#ifndef	DEBUG
	clnt = clnt_create (host, MATHS_PROG, MATH_VERSION_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	
	#endif	/* DEBUG */
	
	puiss2_1_arg = 4;
	result_1 = puiss2_1(&puiss2_1_arg, clnt);
	printf("2 puissance %d = %d \n", puiss2_1_arg, *result_1);
	
	multxy_1_arg.x = 12;
	multxy_1_arg.y = 20;
	
	result_2 = multxy_1(&multxy_1_arg, clnt);
	
	
	printf("resultat de la multiplication = %f \n", *result_2);
	
	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 
}

int
main (int argc, char *argv[])
{
	char *host;
	
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	maths_prog_1 (host);
	exit (0);
}
