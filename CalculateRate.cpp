#include "CalculateRate.hh"

int main()
{    
    TFile *outputFile = new TFile("output.root","RECREATE");
    
    TF1 *AlphaReducedWidth = new TF1("AlphaReducedWidth",&AlphaReducedWidthDistribution,0.1,1);
    AlphaReducedWidth->SetNpx(1.e6);
 
    TH1F *AlphaReducedWidthsRandom = new TH1F("AlphaReducedWidthsRandom","AlphaReducedWidthsRandom",1000,0,1);
    AlphaReducedWidthsRandom->FillRandom("AlphaReducedWidth",1000000);
    
    AlphaReducedWidth->Write();
    AlphaReducedWidthsRandom->Write();
    outputFile->Close();
}

double AlphaReducedWidthDistribution(double *x, double *pars)
{
    double result = 0;
    
    if(x[0] < 1 && x[0]>0)
    {
        result += 1./sqrt(x[0]) * exp( -0.5 * x[0] / ThetaAlphaSq);
        result += LinearAlphaDistribution;
    }
    return result;
}