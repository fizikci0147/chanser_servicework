{
  
  clas12root::HipoChain chain;
  chain.Add("../../skim10_005038.hipo");
  chain.Add("../../skim1_004998.hipo");
  chain.SetReaderTags({0});
  // chain.GetC12Reader()->useFTBased();
    
  chanser::HipoProcessor processor(&chain,"finalstates.txt","./");
  processor.AddOption("HIPOPROCESSOR_MAXPARTICLES","8");
  //chain.GetNRecords();
  gProof->Process(&processor,chain.GetNRecords());
  //gProof->Process(&processor,1000);
 
}
