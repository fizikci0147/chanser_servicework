#pragma once


#include "BaseOutEvent.h"

#pragma link C++ class fizikci0147::TreeDatadvcs;

namespace fizikci0147{

  class TreeDatadvcs : public chanser::BaseOutEvent{

  public:
    TreeDatadvcs(){SetName("dvcs");}
    ~TreeDatadvcs() final =default;
      
    //data member for tree branches below here
    Double_t MissMass=0;
    Double_t MissMass2=0;
    Double_t thgg=0.;
    Double_t phigg=0.;
    Double_t Bjx=0.;
    Double_t xie=0;
    Double_t xip=0;
    Int_t pid_e=0;
    Int_t pid_p=0;
    Double_t Vz_p=0;
    Double_t Vz_e=0;
    Double_t th_e =0;
    Double_t th_p =0;
    Double_t phi_e =0;
    Double_t phi_p =0;
    Int_t region_p =0;

    //example of e- kinematics
    //you can remove these if not using
    Double_t W=0;
    Double_t Q2=0;
    Double_t Pol=0;
    Double_t Egamma=0;
  


    ///////////////////////////////////////////////////////////
    //LEAVE THE FOLLOWING FUNCTIONS
    //Function required to set tree branches
    void Branches(TTree* tree) final{
      BaseOutEvent::Branches(tree,Class()->GetListOfDataMembers());
    }
    void Hipo(hipo::ntuple_writer* writer) final{
      BaseOutEvent::Hipo(writer,Class()->GetListOfDataMembers());
    }
      
    ClassDefOverride(TreeDatadvcs,1);
  };
}
