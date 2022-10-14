#pragma once


#include "BaseOutEvent.h"

#pragma link C++ class fizikci0147::TreeDataPi0;

namespace fizikci0147{

  class TreeDataPi0 : public chanser::BaseOutEvent{

  public:
    TreeDataPi0(){SetName("Pi0");}
    ~TreeDataPi0() final =default;
      
    //data member for tree branches below here
    Double_t MissMass=0;
    Double_t MissMass2=0;
    Double_t thgg=0.;
    Double_t phigg=0;

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
      
    ClassDefOverride(TreeDataPi0,1);
  };
}
