{
  clas12databases::SetCCDBLocalConnection("../../ccdb.sqlite");
  clas12databases::SetRCDBRootConnection("../../rcdb.root");
  ////Set hipo file to be analysed
  HipoData hdata;
  hdata.SetFile("../../rec_clas_005045.evio.00140-00144.hipo");
  //hdata.SetFile("../../rec_clas_005432.evio.00230-00234.hipo");
  //hdata.SetFile("../../DeltaVCS/DeltaVCS_004989.hipo");
  //hdata.SetFile("/input/dir/file.hipo");
   hdata.LoadAnaDB("$CHANSER/anadbs/RunPeriodPass1.db");
   hdata.SetRunPeriod("fall_2018");

  ////create FinalStateManager
  ////we can load as many saved final states as we like
  FinalStateManager fsm;
 fsm.SetBaseOutDir("output/directory");
  ////Connect the data to the manager
  fsm.LoadData(&hdata);

  ////load one or more FinalStates
  fsm.LoadFinalState("Pi0",
		     "dir/fs/gamma_t.root");
  // fsm.LoadFinalState("Pi0",
  //		     "/dir/fs/file_name_for_this_configuration_2.root");

  //Max number of particles of any 1 species
  //Whole event disgarded if this not met.
  fsm.GetEventParticles().SetMaxParticles(6);

  ////Run through all events
  fsm.ProcessAll();
  ////Run through N events
  //fsm.ProcessAll(N);


}
