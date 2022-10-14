{
//skeleton code maker

FSSkeleton s;

//Give your class a name

s.SetFinalState("dvcs");

//Define the possible detected particles in the final state
//Name1:species1,Name2:species2,...
//where species is given in $ROOTSYS/etc/pdg_table.txt
//e.g Electron:e-,Proton:proton,...
s.SetFinalStateParts("Electron:e-,Proton:proton,Photon1:gamma");

//Define possible topologies for this final state
//Note ',' seperates different topologies
// ':' seperates different particle within a topology
// Here we define 3 topologies, exclusive, 1 missin pi-, 2  missing pi-

s.SetFinalStateTopo("Electron:Proton,Electron:Proton:Photon1");

//Define short lived parent particles which decay to
//detected particles
//this should not include broad resonances
//But things like omega, phi, Lambda, K0
//':' seperates parent name from type
//';' seperates child particles
//',' seperates different parents

//s.SetFinalStateParents("Photon1:gamma;Photon2:gamma");

//produce the code

s.MakeCode();
}
