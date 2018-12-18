#include "CRF.h"

SEXP Infer_RBP(SEXP _crf, SEXP _maxIter, SEXP _cutoff, SEXP _verbose)
{
	int maxIter = INTEGER_POINTER(AS_INTEGER(_maxIter))[0];
	double cutoff = NUMERIC_POINTER(AS_NUMERIC(_cutoff))[0];
	int verbose = INTEGER_POINTER(AS_INTEGER(_verbose))[0];

	CRF crf(_crf);
	crf.Init_Belief();
	crf.Infer_RBP(maxIter, cutoff, verbose);

	return(crf._belief);
}

void CRF::Infer_RBP(int maxIter, double cutoff, int verbose)
{
	ResidualBP(maxIter, cutoff, verbose);
	Messages2EdgeBel();
	BetheFreeEnergy();
}
