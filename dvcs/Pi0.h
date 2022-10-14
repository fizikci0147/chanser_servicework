//////////////////////////////////////////////////////////////
///
///Class:		Pi0
///Description:
///
#pragma once


#include "CLAS12FinalState.h"
#include "CLAS12Particle.h"

#include "TreeDataPi0.h"


namespace fizikci0147{
using  HSMomentum=ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< Double_t >, ROOT::Math::DefaultCoordinateSystemTag >;
  using Particle=chanser::CLAS12Particle;

  class Pi0 : public chanser::CLAS12FinalState{

       
  public :
    Pi0()=default;
      
   TString GetUSER() final {return _USER;};
 
    //create an instance of the class
    static std::unique_ptr<Pi0> Make(TString ch,TString inc) {
      return std::unique_ptr<Pi0>{new Pi0{ch,inc}};
    }
    //create an instance of the treedata, should be used to init unique_ptr
    chanser::base_outevt_uptr TreeDataFactory() final {
      return chanser::base_outevt_uptr{new TreeDataPi0{}};
    }
    void SetOutEvent(BaseOutEvent* out) final{
      TD=static_cast<TreeDataPi0*>(out);
    }
  
    ~Pi0() final =default;

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
    //using Pi0::Make(...)
    //auto fs = fizikci0147::Pi0::Make("NONE","ALL");
  Pi0(TString ch,TString inc) : chanser::CLAS12FinalState(std::move(ch),std::move(inc)){
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
    TreeDataPi0* TD{nullptr};//!;

   
    
    const TString _USER="fizikci0147";
    ClassDefOverride(fizikci0147::Pi0,1); //class Pi0
  }; //end Pi0
  
}
