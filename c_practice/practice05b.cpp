#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#define TRY_NUM 100000

int main(int argc, char **argv){
  int sum_freq[13]={0};
  int face1_freq[7]={0};
  int face2_freq[7]={0};
  int i, face1, face2;
  srand(time(NULL));
  //TApplication app( "app", &argc, argv );
  TFile file( "practice05.root", "RECREATE" );
  //TCanvas *c1 = new TCanvas("c1");
  TH1I *hist_sum= new TH1I("hist_sum", "sum of 2 dice", 11 ,1.5, 12.5);
  TH2F *hist_2d = new TH2F("hist_2d","dice freqency", 6, 0.5, 6.5, 6, 0.5, 6.5);
  //TH1I *hist1= new TH1I("hist1", "Dice No.1", 6, 0.5, 6.5);
  //TH1I *hist2= new TH1I("hist2", "Dice No.2", 6, 0.5, 6.5);

  for (i = 0; i < TRY_NUM; i++) {
    face1 = rand()%6+1;
    face2 = rand()%6+1;
    hist_sum->Fill(face1+face2);
    hist_2d->Fill(face1, face2);
    //hist1->Fill(face1);
    //hist2->Fill(face2);
    ++face1_freq[face1];
    ++face2_freq[face2];
    ++sum_freq[face1+face2];
  }
  //hist_sum->FillRandom("gaus");
  hist_2d->GetZaxis()->SetRangeUser(0,6500);
  hist_2d->Draw("colz");
  //hist_sum->GetYaxis()->SetRangeUser(0,6500);
  hist_sum->Draw();
  hist_sum->SetLineColor(9);
	hist_sum->SetFillColor(8);
	hist_sum->SetFillStyle(1001);
  //hist1->Draw();
  //hist2->Draw();
  file.Write();
  file.Close();
  //c1->Draw();
  //c1->WaitPrimitive();

  printf("サイコロの和\n");
  for (i = 2; i <=12; i++) {
    printf("%4d%10d\n", i, sum_freq[i] );
  }

  printf("サイコロ1\n");
  for (i = 1; i <=6; i++) {
    printf("%4d%10d\n", i, face1_freq[i] );
  }

  printf("サイコロ2\n");
  for (i = 1; i <=6; i++) {
    printf("%4d%10d\n", i, face2_freq[i] );
  }
  return 0;
}
