#include <stdio.h>
#include <stdlib.h>
#include <tirpc/rpc/clnt.h>

#include "fac.h"

void fac_prog( CLIENT *cl) {
    int  *x;
	printf("entrer un number : \n");
	scanf("%d",&x);
    int *result = calcfac_1(&x, cl);
    printf("le resultat est " + *result);
}

void
fac_prog_1(char *host)
{
	CLIENT *clnt;
	facArgs  calcmult_1_arg;

	clnt = clnt_create (host, FAC_PROG, FAC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	int choice;
	while (1) {
		printf("choisie une function a executer\n");
		printf("[1] factorielle(int x)\n");
		printf("[2] multip(int x, int y)\n");
		printf("[0] exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				exit(0);
			case 1:
				fac_prog(clnt);
				break;
		}
	}

	// result_1 = calcfac_1(&calcfac_1_arg, clnt);
	// result_2 = calcmult_1(&calcmult_1_arg, clnt);

}

int main(int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	fac_prog_1(host);

	exit(0);
}

