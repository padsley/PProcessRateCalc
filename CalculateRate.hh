#include <TFile.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TF1.h>
#include <iostream>
#include <TH1.h>

int Z1 = 2, Z2 = 56; //Charges of beam and target
int A1 = 4, A2 = 160; //Masses of beam and target

double Qvalue = 0; //Q-value of the reaction

double ThetaAlphaSq = 0.01;
double LinearAlphaDistribution = 0.001;

double AlphaReducedWidthDistribution(double *x, double *pars);