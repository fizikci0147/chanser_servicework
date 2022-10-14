//////////////////////////////////////////////////////////////
///
///Class:		dvcs
///Description:
///
#pragma once


#include "CLAS12FinalState.h"
#include "CLAS12Particle.h"

#include "TreeDatadvcs.h"


namespace fizikci0147{

  using Particle=chanser::CLAS12Particle;

  class dvcs : public chanser::CLAS12FinalState{

       
  public :
    dvcs()=default;
      
   TString GetUSER() final {return _USER;};
 
    //create an instance of the class
    static std::unique_ptr<dvcs> Make(TString ch,TString inc) {
      return std::unique_ptr<dvcs>{new dvcs{ch,inc}};
    }
    //create an instance of the treedata, should be used to init unique_ptr
    chanser::base_outevt_uptr TreeDataFactory() final {
      return chanser::base_outevt_uptr{new TreeDatadvcs{}};
    }
    void SetOutEvent(BaseOutEvent* out) final{
      TD=static_cast<TreeDatadvcs*>(out);
    }
  
    ~dvcs() final =default;

    void Define() final;
      
    BaseOutEvent* GetOutEvent() noexcept final{return TD;}
    
    void DerivedChangeRun() final {
      //If databases are implemented you can
      //set the beam energy here
      /*      auto ebeam=GetRunInfo()->_BeamEnergy;
      auto mele = 0.00051099891;
      std::cout<<"Change beam energy to :"<<ebeam<<std::endl;
      _beam.SetXYZT(0,0,ebeam,TMath::Sqrt(ebeam*ebeam + mele*mele));
      */    
    }  
  protected :
    void Kinematics() final;
    void UserProcess() final;
      
      
   
  private:
    //constructor private so only create unique_ptr
    //using dvcs::Make(...)
    //auto fs = fizikci0147::dvcs::Make("NONE","ALL");
  dvcs(TString ch,TString inc) : chanser::CLAS12FinalState(std::move(ch),std::move(inc)){
      //Give object class name - namespace
      //Used for compiling and loading
      SetName(chanser::Archive::BareClassName(ClassName()));
      Define();
    }

    //Final Particles Detected
    Particle   _electron = Particle{"e-"};//!
    Particle   _proton = Particle{"proton"};//!
    Particle   _photon1 = Particle{"gamma"};//!
    //chanser::CLAS12Particle _PARTICLE=BaseParticle("PDG");//!
    
    //Final Parents


    //Initial state
    HSLorentzVector _beam{0,0,10.6,10.6};//!
    HSLorentzVector _target{0,0,0,0.938272};//!


    //Tree Output Data
    TreeDatadvcs* TD{nullptr};//!;

   
    
    const TString _USER="fizikci0147";
    ClassDefOverride(fizikci0147::dvcs,1); //class dvcs
  }; //end dvcs
  
}
