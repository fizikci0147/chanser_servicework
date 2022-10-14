installing chanser on MAC

1))  /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskCalorSplitOffs.cpp:91:40: error: missing default argument on parameter 'rmin'
        (const Short_t charge=0,const Float_t rmin,TH1F& hR){


        function was changed to 


   -->     (const Short_t charge,const Float_t rmin,TH1F& hR){


2))/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskCalorSplitOffs.cpp:91:51: error: missing default argument on parameter 'hR'
        (const Short_t charge=0,const Float_t rmin,TH1F& hR){

changed to 

--->>>      (const Short_t charge,const Float_t rmin,TH1F& hR){

3)) warning :

/Users/fizikci0147/work/clas_work/chanser/chanser/core/ParticleIter.cpp:95:14: warning: enumeration value 'MultiRem' not handled in switch [-Wswitch]
     switch (_type) {
             ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ParticleIter.cpp:95:14: note: add missing switch cases
     switch (_type) {


4)linking library issues for CLAS12ROOT

CMAKE changes :

1) "-lTMVA -lTMVAGui chanser " added to  /tmva/CMakeLists.txt

target_link_libraries(${CHANZER} ${ROOT_LIBRARIES} -lTMVA -lTMVAGui chanser )


2)changes in  /core/CMakeLists.txt : 


target_link_libraries(${CHANZER} ${ROOT_LIBRARIES} -lEG -lTMVA -lTMVAGui)
target_link_libraries(${CHANZER} -lClas12Banks)
target_link_libraries(${CHANZER} -L${CLAS12ROOT}/lib)

3)in rga_action/CMakeLists.txt

add

target_link_libraries(${CHANZER} ${ROOT_LIBRARIES} chanseractions)

4)in skeleton/CMakeList
add
target_link_libraries(${SKEL} ${ROOT_LIBRARIES} )


5)in macrod/Load.C and SkeletonLoad.C remove .so from all loaded libraries



6) When running the skeleton example 37 warning due to initilization or varibale not being used :


====================================================================================================================================
nfo in <TMacOSXSystem::ACLiC>: creating shared library /Users/fizikci0147/work/clas_work/chanser/work/test/Pi4/./Pi4_cpp.so
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/Pi4/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/Pi4/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/Pi4/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:8:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventParticles.h:10:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/BaseParticle.h:218:83: warning: unused parameter 'andPDG' [-Wunused-parameter]
  inline void chanser::BaseParticle::CopyParticle(const BaseParticle* part,Bool_t andPDG){
                                                                                  ^
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:24:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:54:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:55:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
    virtual  traj_ptr traj(ushort det,ushort layer=0) const{_traj->setIndex(-1);return _traj;};
                                  ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:108:46: warning: unused parameter 'layer' [-Wunused-parameter]
    virtual  traj_ptr traj(ushort det,ushort layer=0) const{_traj->setIndex(-1);return _traj;};
                                             ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:109:34: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  cher_ptr che(ushort lay) const{_cher->setIndex(-1);return _cher;};
                                 ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:110:31: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  ft_ptr ft(ushort lay) const{_ft->setIndex(-1);return _ft;};
                              ^
                                              ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:65: warning: unused parameter 'pidInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                                                ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:82: warning: unused parameter 'incInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                                                                 ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:48:40: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void ChangeRun(FinalState* fs) {};
                                       ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/Pi4/Pi4_cpp_ACLiC_dict.cxx:41:
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:126:27: warning: variable 'mp' may be uninitialized when used here [-Wconditional-uninitialized]
                pattern = mp;
                          ^~
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:102:22: note: initialize the variable 'mp' to silence this warning
        char *cp, *mp;
                     ^
                      = nullptr
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:127:26: warning: variable 'cp' may be uninitialized when used here [-Wconditional-uninitialized]
                source = cp++;

====================================================================================================================================


warnings generated during running : 



In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:8:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventParticles.h:10:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/BaseParticle.h:218:83: warning: unused parameter 'andPDG' [-Wunused-parameter]
  inline void chanser::BaseParticle::CopyParticle(const BaseParticle* part,Bool_t andPDG){
                                                                                  ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:20:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/calorimeter.h:17:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/particle_detector.h:66:30: warning: unused parameter 'index' [-Wunused-parameter]
    virtual int getLayer(int index)  const noexcept{return 0;}
                             ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:24:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:20:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/ftbevent.h:35:23: warning: unused parameter 'ind' [-Wunused-parameter]
    void setEntry(int ind){}
                      ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/ftbevent.h:36:27: warning: unused parameter 'ind' [-Wunused-parameter]
    void setBankEntry(int ind){}
                          ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:24:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:54:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:55:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:105:33: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  cal_ptr cal(ushort lay) const{_cal->setIndex(-1);return _cal;};
                                ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:106:35: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  scint_ptr sci(ushort lay) const{_scint->setIndex(-1);return _scint;};
                                  ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:107:34: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  trck_ptr trk(ushort lay) const{_trck->setIndex(-1);return _trck;};
                                 ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:108:35: warning: unused parameter 'det' [-Wunused-parameter]
    virtual  traj_ptr traj(ushort det,ushort layer=0) const{_traj->setIndex(-1);return _traj;};
                                  ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:108:46: warning: unused parameter 'layer' [-Wunused-parameter]
    virtual  traj_ptr traj(ushort det,ushort layer=0) const{_traj->setIndex(-1);return _traj;};
                                             ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:109:34: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  cher_ptr che(ushort lay) const{_cher->setIndex(-1);return _cher;};
                                 ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:110:31: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  ft_ptr ft(ushort lay) const{_ft->setIndex(-1);return _ft;};
                              ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:47: warning: unused parameter 'topoInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                              ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:65: warning: unused parameter 'pidInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                                                ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:82: warning: unused parameter 'incInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                                                                 ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:48:40: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void ChangeRun(FinalState* fs) {};
                                       ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:13:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ActionManager.h:27:35: warning: unused parameter 'ti' [-Wunused-parameter]
    virtual Bool_t Execute(UInt_t ti){return kTRUE;} //per combitorial
                                  ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ActionManager.h:31:41: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void  Configure(FinalState* fs){};//run initialisation
                                        ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ActionManager.h:32:45: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void  PostConfigure(FinalState* fs){}; //post initialisation (access other actions)
                                            ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:14:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/OutEventManager.h:8:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/BaseOutEvent.h:18:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/hipo4/ntuple_writer.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/hipo4/writer.h:118:
/Users/fizikci0147/work/clas_work/chanser/clas12root/hipo4/reader.h:219:30: warning: unused parameter 'r' [-Wunused-parameter]
        reader(const reader &r){}
                             ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:16:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/DataManager.h:37:38: warning: unused parameter 'entry' [-Wunused-parameter]
    virtual void WriteEvent(Long64_t entry=-1){};//by default do nothing
                                     ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:71:54: warning: unused parameter 'part' [-Wunused-parameter]
    virtual Bool_t CheckParticle(const BaseParticle* part) const{return kTRUE;}
                                                     ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:84:52: warning: unused parameter 'evi' [-Wunused-parameter]
    virtual void SetEventInfo(const BaseEventInfo* evi){};
                                                   ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:85:48: warning: unused parameter 'rui' [-Wunused-parameter]
    virtual void SetRunInfo(const BaseRunInfo* rui){};
                                               ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:208:44: warning: unused parameter 'out' [-Wunused-parameter]
    virtual void SetOutEvent(BaseOutEvent* out){};
                                           ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12databases.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/rcdb_reader.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/Connection.h:20:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/MySqlProvider.h:17:
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:126:27: warning: variable 'mp' may be uninitialized when used here [-Wconditional-uninitialized]
                pattern = mp;
                          ^~
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:102:22: note: initialize the variable 'mp' to silence this warning
        char *cp, *mp;
                     ^
                      = nullptr
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:127:26: warning: variable 'cp' may be uninitialized when used here [-Wconditional-uninitialized]
                source = cp++;
                         ^~
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:102:17: note: initialize the variable 'cp' to silence this warning
        char *cp, *mp;
                ^
                 = nullptr
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12databases.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/ccdb_reader.h:5:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/ccdb/include/CCDB/CalibrationGenerator.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/ccdb/include/CCDB/Calibration.h:12:
/Users/fizikci0147/work/clas_work/chanser/clas12root/ccdb/include/CCDB/Providers/DataProvider.h:121:25: warning: 'const' type qualifier on return type has no effect [-Wignored-qualifiers]
    virtual Directory * const GetRootDirectory();
                        ^~~~~~
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:23:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/runconfig.h:52:23: warning: unused parameter 'i' [-Wunused-parameter]
    void setEntry(int i){}
                      ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/runconfig.h:53:27: warning: unused parameter 'ind' [-Wunused-parameter]
    void setBankEntry(int ind){}
                          ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:29:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helonline.h:45:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helonline.h:46:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:30:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helflip.h:52:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helflip.h:53:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:33:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_fdet.h:47:25: warning: unused parameter 'lay' [-Wunused-parameter]
    trck_ptr trk(ushort lay) const final
                        ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:34:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_cdet.h:46:25: warning: unused parameter 'lay' [-Wunused-parameter]
    trck_ptr trk(ushort lay) const final{_trck->setIndex(_ptrck);return _trck;};
                        ^
37 warnings generated.

In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:8:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventParticles.h:10:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/BaseParticle.h:218:83: warning: unused parameter 'andPDG' [-Wunused-parameter]
  inline void chanser::BaseParticle::CopyParticle(const BaseParticle* part,Bool_t andPDG){
                                                                                  ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:20:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/calorimeter.h:17:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/particle_detector.h:66:30: warning: unused parameter 'index' [-Wunused-parameter]
    virtual int getLayer(int index)  const noexcept{return 0;}
                             ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:24:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:20:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/ftbevent.h:35:23: warning: unused parameter 'ind' [-Wunused-parameter]
    void setEntry(int ind){}
                      ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/ftbevent.h:36:27: warning: unused parameter 'ind' [-Wunused-parameter]
    void setBankEntry(int ind){}
                          ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:24:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:54:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/event.h:55:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12Particle.h:9:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:105:33: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  cal_ptr cal(ushort lay) const{_cal->setIndex(-1);return _cal;};
                                ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:106:35: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  scint_ptr sci(ushort lay) const{_scint->setIndex(-1);return _scint;};
                                  ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:107:34: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  trck_ptr trk(ushort lay) const{_trck->setIndex(-1);return _trck;};
                                 ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:108:35: warning: unused parameter 'det' [-Wunused-parameter]
    virtual  traj_ptr traj(ushort det,ushort layer=0) const{_traj->setIndex(-1);return _traj;};
                                  ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:108:46: warning: unused parameter 'layer' [-Wunused-parameter]
    virtual  traj_ptr traj(ushort det,ushort layer=0) const{_traj->setIndex(-1);return _traj;};
                                             ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:109:34: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  cher_ptr che(ushort lay) const{_cher->setIndex(-1);return _cher;};
                                 ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_particle.h:110:31: warning: unused parameter 'lay' [-Wunused-parameter]
    virtual  ft_ptr ft(ushort lay) const{_ft->setIndex(-1);return _ft;};
                              ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:9:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:47: warning: unused parameter 'topoInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                              ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:65: warning: unused parameter 'pidInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                                                ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:46:82: warning: unused parameter 'incInfo' [-Wunused-parameter]
    virtual void UseTopoInfo(TopologyManager& topoInfo, TString pidInfo, TString incInfo){};
                                                                                 ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/MaskedEventParticles.h:48:40: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void ChangeRun(FinalState* fs) {};
                                       ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:13:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ActionManager.h:27:35: warning: unused parameter 'ti' [-Wunused-parameter]
    virtual Bool_t Execute(UInt_t ti){return kTRUE;} //per combitorial
                                  ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ActionManager.h:31:41: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void  Configure(FinalState* fs){};//run initialisation
                                        ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/ActionManager.h:32:45: warning: unused parameter 'fs' [-Wunused-parameter]
    virtual void  PostConfigure(FinalState* fs){}; //post initialisation (access other actions)
                                            ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:14:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/OutEventManager.h:8:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/BaseOutEvent.h:18:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/hipo4/ntuple_writer.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/hipo4/writer.h:118:
/Users/fizikci0147/work/clas_work/chanser/clas12root/hipo4/reader.h:219:30: warning: unused parameter 'r' [-Wunused-parameter]
        reader(const reader &r){}
                             ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:16:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/DataManager.h:37:38: warning: unused parameter 'entry' [-Wunused-parameter]
    virtual void WriteEvent(Long64_t entry=-1){};//by default do nothing
                                     ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:3:
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:71:54: warning: unused parameter 'part' [-Wunused-parameter]
    virtual Bool_t CheckParticle(const BaseParticle* part) const{return kTRUE;}
                                                     ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:84:52: warning: unused parameter 'evi' [-Wunused-parameter]
    virtual void SetEventInfo(const BaseEventInfo* evi){};
                                                   ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:85:48: warning: unused parameter 'rui' [-Wunused-parameter]
    virtual void SetRunInfo(const BaseRunInfo* rui){};
                                               ^
/Users/fizikci0147/work/clas_work/chanser/chanser/core/FinalState.h:208:44: warning: unused parameter 'out' [-Wunused-parameter]
    virtual void SetOutEvent(BaseOutEvent* out){};
                                           ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12databases.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/rcdb_reader.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/Connection.h:20:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/MySqlProvider.h:17:
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:126:27: warning: variable 'mp' may be uninitialized when used here [-Wconditional-uninitialized]
                pattern = mp;
                          ^~
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:102:22: note: initialize the variable 'mp' to silence this warning
        char *cp, *mp;
                     ^
                      = nullptr
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:127:26: warning: variable 'cp' may be uninitialized when used here [-Wconditional-uninitialized]
                source = cp++;
                         ^~
/Users/fizikci0147/work/clas_work/chanser/clas12root/rcdb/cpp/include/RCDB/StringUtils.h:102:17: note: initialize the variable 'cp' to silence this warning
        char *cp, *mp;
                ^
                 = nullptr
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:11:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12databases.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/ccdb_reader.h:5:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/ccdb/include/CCDB/CalibrationGenerator.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/ccdb/include/CCDB/Calibration.h:12:
/Users/fizikci0147/work/clas_work/chanser/clas12root/ccdb/include/CCDB/Providers/DataProvider.h:121:25: warning: 'const' type qualifier on return type has no effect [-Wignored-qualifiers]
    virtual Directory * const GetRootDirectory();
                        ^~~~~~
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:23:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/runconfig.h:52:23: warning: unused parameter 'i' [-Wunused-parameter]
    void setEntry(int i){}
                      ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/runconfig.h:53:27: warning: unused parameter 'ind' [-Wunused-parameter]
    void setBankEntry(int ind){}
                          ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:29:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helonline.h:45:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helonline.h:46:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:30:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helflip.h:52:22: warning: unused parameter 'ind' [-Wunused-parameter]
   void setEntry(int ind){}
                     ^
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/helflip.h:53:26: warning: unused parameter 'ind' [-Wunused-parameter]
   void setBankEntry(int ind){}
                         ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:33:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_fdet.h:47:25: warning: unused parameter 'lay' [-Wunused-parameter]
    trck_ptr trk(ushort lay) const final
                        ^
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4_cpp_ACLiC_dict.cxx:41:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/./Pi4.cpp:2:
In file included from /Users/fizikci0147/work/clas_work/chanser/work/test/rga/Pi4.h:9:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/CLAS12FinalState.h:4:
In file included from /Users/fizikci0147/work/clas_work/chanser/chanser/core/EventInfo.h:10:
In file included from /Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/clas12reader.h:34:
/Users/fizikci0147/work/clas_work/chanser/clas12root/Clas12Banks/region_cdet.h:46:25: warning: unused parameter 'lay' [-Wunused-parameter]
    trck_ptr trk(ushort lay) const final{_trck->setIndex(_ptrck);return _trck;};
