#include "calcule.h"

int *
puiss2_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;
	
	result = 2;
	
	for(int i = 1; i < argp; i++ ) {
		result = result * 2;
	}
	
	return &result;
}

float *
multxy_1_svc(operandes *argp, struct svc_req *rqstp)
{
	static float  result;
	
	result = argp->x * argp->y;
	
	return &result;
}
