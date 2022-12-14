{
  auto FS = fizikci0147::dvcs::Make("ANY","ANY");
  FS->AddTopology("Electron:Proton:Photon1");
  // FS->AddTopology(OTHER_TOPOLOGY);
  //
  
  ////Save TreeDatadvcs
  FS->UseOutputRootTree();
  //FS->UseOutputHipoNtuple();

  /////Make particle trees first in case want to add cut flags
  //ParticleDataManager pdm{"particle",1};
  //pdm.SetParticleOut(new CLAS12ParticleOutEvent0);
  //FS->RegisterPostTopoAction(pdm);
   RGA(FS.get());
  ////
  ParticleCutsManager pcm{"EBCuts",1};
  pcm.AddParticleCut("e-",new EventBuilderCut());
  pcm.AddParticleCut("proton",new EventBuilderCut());
  //pcm.AddParticleCut("pi+",new EventBuilderCut());
  //pcm.AddParticleCut("pi-", new DeltaTimeCut(2));//Apply a Delta Time cut of 2ns
  // FS->RegisterPostTopoAction(pcm);
  
  /*ParticleCutsManager zVertex{"ZVertexCut",1}; //0 as we do not want to apply these cuts to output file
  zVertex.AddParticleCut("e-", new Cut_ZVertexCut());
  FS->RegisterPostKineAction(zVertex);*/
 
  ////Write to file for later processing
  FS->WriteToFile("dir/fs/dvcs_t.root");

  FS->Print();


  //Delete the final state rather than let ROOT try
  FS.reset();
}
