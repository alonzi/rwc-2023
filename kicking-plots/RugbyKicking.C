void RugbyKicking(){
  cout << "Hello World!" << endl;
  
  int   steps       =  500  ; // size of the grid
  float scale       =    0.7; // width/length
  float length      =   50. ; // lengt of field in metres
  float margin      =    0.15; // margin size
  float canvas_size = 1000. ; //canvas size

  float goal_width = 5.6; // [m]
  float goal_height = 3.0;//[m]

  gStyle->SetPadTopMargin(margin*scale);     // Set Margin Top
  gStyle->SetPadBottomMargin(margin*scale);  // Set Margin Bottom
  gStyle->SetPadRightMargin(margin);         // Set Margin Right
  gStyle->SetPadLeftMargin(margin);          // Set Margin Left
  gStyle->SetOptStat(0);

  TLine * halfway = new TLine(0,-35,0,35);
  halfway->SetLineColor(0);
  halfway->SetLineWidth(6);
  TLine * twenty2L = new TLine(-28,-35,-28,35);
  twenty2L->SetLineColor(0);
  twenty2L->SetLineWidth(4);
  TLine * twenty2R = new TLine(28,-35,28,35);
  twenty2R->SetLineColor(0);
  twenty2R->SetLineWidth(4);
  TLine * tenL = new TLine(10,-35,10,35);
  tenL->SetLineColor(0);
  tenL->SetLineWidth(4);
  tenL->SetLineStyle(7);
  TLine * tenR = new TLine(-10,-35,-10,35);
  tenR->SetLineColor(0);
  tenR->SetLineWidth(4);
  tenR->SetLineStyle(7);
  
  TLine * tramT = new TLine(-45,30,45,30);
  tramT->SetLineColor(0);
  tramT->SetLineWidth(4);
  tramT->SetLineStyle(9);
  TLine * tramB = new TLine(-45,-30,45,-30);
  tramB->SetLineColor(0);
  tramB->SetLineWidth(4);
  tramB->SetLineStyle(9);

  TLine * tramIT = new TLine(-45,20,45,20);
  tramIT->SetLineColor(0);
  tramIT->SetLineWidth(4);
  tramIT->SetLineStyle(9);
  TLine * tramIB = new TLine(-45,-20,45,-20);
  tramIB->SetLineColor(0);
  tramIB->SetLineWidth(4);
  tramIB->SetLineStyle(9);
  
  TLine * touchT = new TLine(-50,35,50,35);
  touchT->SetLineColor(0);
  touchT->SetLineWidth(6);
  TLine * touchB = new TLine(-50,-35,50,-35);
  touchB->SetLineColor(0);
  touchB->SetLineWidth(6);

  TLine * goalL = new TLine(-50,-35,-50,35);
  goalL->SetLineColor(0);
  goalL->SetLineWidth(6);
  TLine * goalR = new TLine(50,-35,50,35);
  goalR->SetLineColor(0);
  goalR->SetLineWidth(6);

  TEllipse * postT = new TEllipse(50,goal_width/2.,0.9,0.95,0,360);
  postT->SetFillColor(9);
  TEllipse * postB = new TEllipse(50,-goal_width/2.,0.9,0.95,0,360);
  postB->SetFillColor(9);

  TH2F * ph2_field = new TH2F("h2_field",";metres;metres;degrees",steps,-length,length,steps,-length*scale,length*scale);
  TH2F * ph2_max = new TH2F("h2_max",";metres;metres;degrees",steps,-length,length,steps,-length*scale,length*scale);

  for(int i=0;i<steps-steps*2.5/100.;i++){
    for(int j=0;j<steps;j++){
      float X = i*2.*length/steps-length;
      float Y = j*2.*length*scale/steps-length*scale;
      float r1x = -(X-length);
      float r2x = -(X-length);
      float r1y = Y-goal_width/2.;
      float r2y = Y+goal_width/2.;
      float weight = TMath::ACos((r1x*r2x+r1y*r2y)/sqrt(r1x*r1x+r1y*r1y)/sqrt(r2x*r2x+r2y*r2y))*180./3.14159;
      ph2_field->SetBinContent(i+1,j+1,weight);
    }
  }

    for(int j=0;j<steps;j++){
      ph2_max->SetBinContent(ph2_field->ProjectionX("",j+1,j+1)->GetMaximumBin(),j+1,180);
    }


  TCanvas *pcan = new TCanvas("Field of Play","",canvas_size,canvas_size*scale);
  pcan->SetFillColor(8);
  pcan->SetLogz(1);  ph2_field->Draw("colz");
  // ph2_max->Draw("same,col");
  halfway->Draw();
  twenty2L->Draw();
  twenty2R->Draw();
  tenL->Draw();
  tenR->Draw();
  tramT->Draw();
  tramB->Draw();
  tramIT->Draw();
  tramIB->Draw();
  touchT->Draw();
  touchB->Draw();
  goalL->Draw();
  goalR->Draw();
  postT->Draw();
  postB->Draw();
}
