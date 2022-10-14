  
#include "Pi0.h"
 
namespace fizikci0147{
  
  ///////////////////////$$$$$$$$$$$$$$$$$$$$$$$$$$//////////////////////  
  void Pi0::Define(){
    //Set final state detected particles
    //Note if particle is added to final with a valid genID it will be used
    //to determine the correct permutation of the simulated event
      
    AddParticle("Electron",&_electron,kTRUE,-1);
    AddParticle("Proton",&_proton,kTRUE,-1);
    AddParticle("Photon1",&_photon1,kTRUE,-1);
    //AddParticle("Name",particle,true/false you want to write in final vector, genID for linking to generated truth value)
    // AddParticle("PARTICLE",&_PARTICLE,kTRUE,-1);

    //Set final state parents


    //_doToTopo["TOPOLOGY"]=[&](){
      //TOPOLOGY Define your topology dedendent code in here
      ///////+++++++++++++++++++++++++++++++++++///////
    ////auto miss= _beam + _target - _electron.P4() - _proton.P4()
    ////  -_pip1.P4()-_pim1.P4();
    ////TD->MissMass=miss.M();
    ////TD->MissMass2=miss.M2();
    
      ///////------------------------------------///////
    // };

    //Set Possible Topologies
    _doToTopo["Electron:Proton:Photon1"]=[&](){
        //TOPOLOGY Define your topology dedendent code in here
        ///////+++++++++++++++++++++++++++++++++++///////
        auto miss= _beam + _target - _electron.P4() - _proton.P4();
        auto qv = _beam-_electron.P4();
        auto boost4v =qv+_target;

    
        HSMomentum boost = (boost4v).BoostToCM();
        HSLorentzVector boo_elec=ROOT::Math::VectorUtil::boost(_electron.P4(),boost);
        HSLorentzVector boo_prot=ROOT::Math::VectorUtil::boost(_proton.P4(),boost);
        HSLorentzVector boo_qv  =ROOT::Math::VectorUtil::boost(qv,boost);
        HSLorentzVector boo_beam=ROOT::Math::VectorUtil::boost(_beam,boost);
        HSLorentzVector boo_miss=ROOT::Math::VectorUtil::boost(miss,boost);

        TD->thgg = ROOT::Math::VectorUtil::Angle(boo_qv.Vect(),boo_miss.Vect())*TMath::RadToDeg();
        TD->phigg = boo_miss.Phi()*TMath::RadToDeg();
        TD->MissMass=boo_miss.M();
        TD->MissMass2=boo_miss.M2();

        ///////------------------------------------///////
    };
      
  }

 
  ///////////////////////$$$$$$$$$$$$$$$$$$$$$$$$$$//////////////////////  
  void Pi0::Kinematics(){
    //Define reaction specific kinematic calculations here
    //Assign to tree data TD.var=

    //Use Kinematics to calculate electron variables
    //Note this assumes you called your electron "electron" or "Electron"
    _kinCalc.SetElecsTarget(_beam,_electron.P4(),_target);
    TD->W=_kinCalc.W(); //photon bem energy
    TD->Q2=_kinCalc.Q2();
    TD->Pol=_kinCalc.GammaPol();
    TD->Egamma=_kinCalc.GammaE();
    
  }
    
  ///////////////////////$$$$$$$$$$$$$$$$$$$$$$$$$$//////////////////////  
  void Pi0::UserProcess(){
    //Optional additional steps
    //This is called after the Topo function
    //and before the kinematics function
    _counter++;


    //Must call the following to fill Final trees etc.
    //Fill Final data output at the end
    FinalState::UserProcess();

  }
  
  
}
