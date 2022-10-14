void plot(){

    auto r2d =TMath::RadToDeg();
    TString rootFile = "output/directory/fizikci0147/dvcs_dvcs_t__/FinalState.root";
    TFile *RFile = new TFile(rootFile);
    TTreeReader rReader("FINALOUTTREE",RFile);

    TTreeReaderValue<Double_t> W(rReader, "dvcsW");
    TTreeReaderValue<Double_t> MM2(rReader, "dvcsMissMass2");
    TTreeReaderValue<Double_t> Q2(rReader, "dvcsQ2");
    TTreeReaderValue<Double_t> Bjx(rReader, "dvcsBjx");
    TTreeReaderValue<Double_t> th_e(rReader, "dvcsth_e");
    TTreeReaderValue<Double_t> phi_e(rReader, "dvcsphi_e");
    TTreeReaderValue<Double_t> th_p(rReader, "dvcsth_p");
    TTreeReaderValue<Double_t> phi_p(rReader, "dvcsphi_p");
    TTreeReaderValue<Double_t> vz_e(rReader, "dvcsVz_e");
    TTreeReaderValue<Double_t> vz_p(rReader, "dvcsVz_p");
    TTreeReaderValue<Int_t> pid_e(rReader, "dvcspid_e");
    TTreeReaderValue<Int_t> pid_p(rReader, "dvcspid_p");
    TTreeReaderValue<Double_t> xi_e(rReader, "dvcsxie");
    TTreeReaderValue<Double_t> xi_p(rReader, "dvcsxip");
    TTreeReaderValue<Int_t> region_p(rReader, "dvcsregion_p");



    TH1F *hthgg = new TH1F("hthgg","hthgg",200,0,180);
    TH1F *hphigg = new TH1F("hphigg","hphigg",200,-280,280);
    TH1F *hW = new TH1F("hW","hW",100,0,10);
    TH1F *hQ2 = new TH1F("hQ2","hQ2",100,0.,5.);
    TH1F *hMM = new TH1F("hMM","hMM",100,-0.2,0.2);
    TH2F *hQ2x = new TH2F("hQ2x","hQ2x",100,0.,1.,100,0.,10.0);
    TH1F *hx = new TH1F("hx","hx",100,0.,1.);
    TH1F *hvz_e = new TH1F("hvz_e","hvz_e",100,-8,6.);
    TH1F *hvz_p = new TH1F("hvz_p","hvz_p",100,-8,6.);
    TH1F *hxi_e = new TH1F("hxi_e","hxi_e",100,-3,3.);
    TH1F *hxi_p = new TH1F("hxi_p","hxi_p",100,-3,3.);
    TH1F *hth_e = new TH1F("hth_e","hth_e",100,0,100.);
    TH1F *hth_p = new TH1F("hth_p","hth_p",100,0,100.);
    TH1F *hth_p2 = new TH1F("hth_p2","hth_p2",100,0,100.);

    hth_p->SetLineColor(2);

    int f=0;
	while(rReader.Next()) {
		if (f % 100000 == 0) cout << "processing event:  " << f << endl;

               // if(*W>1.0&&*W<1.3){
               // if(*W>0.1){
                    if(*Q2>0.){
                if(*pid_e==11&&*pid_p==2212&&(*th_e*r2d)<50.&&fabs(*MM2)<0.9){
                hW->Fill(*W);
                hQ2->Fill(*Q2);
                hQ2x->Fill(*Bjx,*Q2);
                hx->Fill(*Bjx);
                hMM->Fill(*MM2);
              //  }
                  //  if(*pid_e==11){
                hvz_e->Fill(*vz_e);
                hxi_e->Fill(*xi_e);
                hth_e->Fill(*th_e*r2d);
                    //}
             //   if(*pid_p==2212){
                hxi_p->Fill(*xi_p);
                hvz_p->Fill(*vz_p);
                if(*region_p==2000){
                hth_p->Fill(*th_p*r2d);
                   }
                if(*region_p==3000){
                hth_p2->Fill(*th_p*r2d);
                   }



                   }
        }
		f++;
        }

        TCanvas *c1 =new TCanvas("c1","c1");
        c1->Divide(3,2);
        c1->cd(1);
        hW->Draw("hist");
        c1->cd(2);
        hQ2->Draw("hist");
        c1->cd(3);
        hMM->Draw("hist");
        c1->cd(4);
        hQ2x->Draw("colz");
        c1->cd(5);
        hx->Draw("hist");

        TCanvas *c2 =new TCanvas("c2","c2");
        c2->Divide(2,2);
        c2->cd(1);
        hxi_e->Draw("hist");
        c2->cd(2);
        hxi_p->Draw("hist");
        c2->cd(3);
        hvz_e->Draw("hist");
        c2->cd(4);
        hvz_p->Draw("hist");



        TCanvas *c3 =new TCanvas("c3","c3");
        c3->Divide(1,2);
        c3->cd(1);
        hth_e->Draw("hist");
        c3->cd(2);
        hth_p2->Draw("hist");
        hth_p->Draw("histsame");
        c3->cd(3);
//        hvz_e->Draw("hist");
        c3->cd(4);
//        hvz_p->Draw("hist");
















}
