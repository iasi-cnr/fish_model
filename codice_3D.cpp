
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>        
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <complex>


#define Dxx 3600.0 // m^2/h
#define Dyy 3600.0 // m^2/h
#define Dzz 1.2 // m^2/h
#define vz0 0.0 // m/h
#define kDSPM0 pow(10.0,4.7) // l/Kg
#define kD0 pow(10.0,4.7) //210000 // l/Kg
#define kDIIsilt 3000 // l/Kg
#define kDMMsilt 1000 // l/Kg
#define	kDIIsed pow(10.0,5.0) //l/Kg
#define	kDMMsed pow(10.0,2.5) //l/Kg
#define SDsed 2.6 // g/cm3
#define vset 0.208 // m/h
#define kPhde 0.00216 // 1/h
#define kmeth 0.000272 //0.000126  //0.00138 // 1/h
#define kdemeth 0.014940 // 1/h
#define k1phox 0.0000066 // m^2/W*s
#define k2phre 0.0000016 // m^2/W*s
#define k3bio 140.0 // m^3/mol
#define k4bio 86.0 // m^3/mol
#define det 24.0 // h
#define depmed 0.0000013356 // m/h
#define H1 0.479 // dimensionless
#define uwind 3.83 // m/s 
#define PMCO2 44.01 // g/mol
#define PMHg0 200.59 // g/mol
#define PMH2O 18.02 // g/mol
#define PMHgII 200.59 // g/mol
#define PMMMHg 215.63 // g/mol
#define Qs 0.0 // m^3/h
#define As 1.0 // m^2
#define SLII 0.0 // ng/(l * h)
#define lambda1 0.52 //0.99 // dimensionless 
#define Dwin 0.000002534 // m^2/h
#define Dwor 0.000002534 // m^2/h
#define delsed 0.00009 // m
#define delsedMM 0.00030 // m
#define delw 0.0001 // m
#define Kdeme 0.007177 // 1/h
#define Kme 0.000503 // 1/h
#define kMM 0.004 // dimensionless 
#define alfa  0.0000001    // 1/h
#define DHgextb27 0.26 // ng/l
#define DHgextb26 0.26 // ng/l
#define DHgextm27 0.26 // ng/l
#define DHgextm26 0.26 // ng/l
#define DHgexts27 0.26 // ng/l
#define DHgexts26 0.26 // ng/l
#define THgextb27 0.31 // ng/l
#define THgextb26 0.31 // ng/l
#define THgextm27 0.31 // ng/l
#define THgextm26 0.31 // ng/l
#define THgexts27 0.31 // ng/l
#define THgexts26 0.31 // ng/l
#define SPMextb27 0.00001870 // Kg/l
#define SPMextb26 0.00001865 // Kg/l
#define SPMextm27 0.00001870 // Kg/l
#define SPMextm26 0.00001865 // Kg/l
#define SPMexts27 0.00001830 // Kg/l
#define SPMexts26 0.00001865 // Kg/l
#define Lsci 300.0 // m
#define Llev 400.0 // m
#define SLMM 0.0 // ng/(l * h)
#define MMHgatm 0.0 // ng/m^3
#define DrydepHgII 0.000456 // microg/(m^-2 * h)  
#define ws 0.174  // m/h
#define Td 1814400.0 // Kg/(m*h^2)
#define Tr 4147200.0 // Kg/(m*h^2)
#define emax 111.25 // g/(m^2*h)
#define lambdac 0.000208 // 1/h
#define delhu 0.02 // m 
#define g 9.80665 // m/sec^2
#define ks 36.0 // m^(1/3)/s
#define romw 1025.0 // Kg/m^3
#define Vpce1 14.00 // microm^3/cell
#define Wp1 0.000014 // microg
#define ag 0.22 // dimensionless
#define bg 0.15 // dimensionless
#define kp 0.25 // dimensionless
#define pcap 0.29 // dimensionless
#define kpII 0.57 // dimensionless
#define kpMM 0.57 // dimensionless
#define rowat 0.0028 //  d/Kg^(kal)
#define rolip 0.21 //  (d/Kg^(kal))*(microg/Kg)^(-kp)
#define rolipexc 0.30 // d/Kg^(kal)
#define rowatfood 0.000011 //  d/Kg^(kal)
#define rolipfood  0.006 //  (d/Kg^(kal))*(microg*Kg)^(-kp)
#define gamwat 200.0 //  Kg^(kal)/d
#define gamfoodphy 0.0 //  Kg^(kal)/d
#define gamfood 0.005 //  Kg^(kal)/d
#define gamgrow 0.0006 //  Kg^(kal)/d
#define logKow 2.54 // dimensionless
#define logBCFMM 4.4 // l/Kg
#define hlmet  250.0 //?  d
#define Twat  20.0 // °C
#define Wzbiv 0.004300 // Kg
#define Wzpol 0.000162 //  Kg
#define Wzamp 0.000038 // ? Kg
#define Wzdec 0.013300 // Kg
#define Wzmys 0.000100 // Kg
#define Wzost 0.016000 // Kg
#define kzgr 0.016 // 1/d
#define kzurII 1.14 // l/g*d
#define kzurMM 1.59 // l/g*d
#define kzexrII 0.005 // 1/d
#define kzexrMM 0.00003 // 1/d
#define kzegII 0.089 // 1/d
#define kzegMM 0.052 // 1/d
#define plipPhy 0.02 // ? dimensionless
#define plipZoo 0.04 // ? dimensionless
#define plipFish 0.09 //  dimensionless
#define logKoc 5.00 //  dimensionless
#define blip 0.41 // dimensionless
#define logkdII 5.4 // dimensionless
#define logkdMM 5.0 // dimensionless
#define Lfinf  235.0  // mm
#define Lfish0  96.02  // mm
#define to  -1.91  // year
#define aWf 0.0090   // dimensionless
#define bWf 3.07     //  dimensionless
#define Kfish  0.275  // 1/year
#define aBCF 2.03    //  dimensionless
#define bBCF -0.57    //  dimensionless
#define kal 0.25    //  dimensionless
#define tfish  730.0 // d
#define kzinII 0.104 // g/g*d
#define kzinMM 0.151 // g/g*d
#define AssFoodbiv 0.4 //  dimensionless
#define AssFoodpol 0.2 //  dimensionless
#define AssFoodamp 0.2 //  dimensionless
#define AssFooddec 0.8 //  dimensionless
#define AssFoodmys 0.4 //  dimensionless
#define AssFoodost 0.8 //  dimensionless
#define AssFood 0.8 //  dimensionless
#define AssFoodbivII 0.03 //  dimensionless
#define AssFoodbivMM 0.65 //  dimensionless
#define AssFoodpolII 0.01 //  dimensionless
#define AssFoodpolMM 0.99 //  dimensionless
#define AssFoodampII 0.16 //  dimensionless
#define AssFoodampMM 0.60 //  dimensionless
#define AssFooddecII 0.16 //  dimensionless
#define AssFooddecMM 0.60 //  dimensionless
#define AssFoodmysII 0.16 //  dimensionless
#define AssFoodmysMM 0.60 //  dimensionless
#define AssFoodostII 0.01 //  dimensionless
#define AssFoodostMM 0.88 //  dimensionless
#define AssFoodII 0.01 //  dimensionless
#define AssFoodMM 0.88 //  dimensionless
#define KtwII 5500.0 //  l/Kg dry
#define KtwMM 11000.0 //  l/Kg dry
#define qT 1.0 // Kg/Kg
#define ak -0.18 // dimensionless
#define bk -2.30 // dimensionless
#define PrefPhydec  0.21  // dimensionless
#define PrefPhymys  0.80  // dimensionless
#define PrefPhybiv  0.61  // dimensionless
#define PrefPhyamp  0.25  // dimensionless
#define PrefPhyost  0.0  // dimensionless
#define PrefZoobivdec  0.16 // dimensionless
#define PrefZoopoldec  0.0  // dimensionless
#define PrefZoomysdec  0.0  // dimensionless
#define PrefZoodecdec  0.29  // dimensionless
#define PrefZooostdec  0.15  // dimensionless
#define PrefZoopolmys  0.0  // dimensionless
#define PrefZooampmys  0.20  // dimensionless
#define PrefZooamppol  0.33  // dimensionless
#define PrefZoopolpol  0.17  //? dimensionless
#define PrefZoobivost  0.23  // dimensionless
#define PrefZoopolost  0.26  // dimensionless
#define PrefZooampost  0.07  // dimensionless
#define PrefZoodecost  0.29  // dimensionless
#define PrefZoomysost  0.10  // dimensionless
#define PrefZooostost  0.05  // dimensionless
#define Prefseddec  0.0  // dimensionless
#define Prefsedmys  0.0  // dimensionless
#define Prefsedost  0.0  // dimensionless
#define Prefsedbiv  0.39  // dimensionless
#define Prefsedamp  0.75  // dimensionless
#define Prefsedbotdec  0.19  // dimensionless
#define Prefsedbotpol  0.50  // dimensionless
#define PrefZoobiv  0.23    // dimensionless
#define PrefZoopol  0.26    // dimensionless
#define PrefZooamp  0.07    // dimensionless
#define PrefZoodec  0.29    // dimensionless
#define PrefZoomys  0.10    // dimensionless
#define PrefZooost  0.05    // dimensionless
#define Prefsed  0.0    // dimensionless
#define PrefZoobiv1  0.03    // dimensionless
#define PrefZoopol1  0.03    // dimensionless
#define PrefZooamp1  0.05    // dimensionless
#define PrefZoodec1  0.10    // dimensionless
#define PrefZoomys1  0.58    // dimensionless
#define PrefZooost1  0.21    // dimensionless
#define Prefsed1  0.0    // dimensionless
#define epsilon1 0.52 // dimensionless
#define r1 0.096 // 1/h
#define m1 0.010  // 1/h
#define Y1 500000000000 // cell/mmol phosphorus
#define abg 0.060 // 1/m
#define a1 0.012 // m^2/mg chl-a
#define a2 0.020 // m^2/mg chl-a
#define KR1 0.200 // mmol phosphorus/m^3
#define KI1 67.50 // micromol photons/(m^2 * s)
#define v1 0.000098 // m/h
#define Rin 0.010000 // mmol phosphorus/m^3
#define Rbot 0.100000 // mmol phosphorus/m^3
#define chla2 0.041  // mg/m^3
#define tempo 8760 // h
#define M 105120 // 1/12 h
#define Msep 78624 // 1/12 h
#define Mmay 43488 // 1/12 h
#define Mfeb 16992 // 1/12 h
#define Mmar 25920 // 1/12 h
#define Mjun 52128 // 1/12 h
#define Moct 87552 // 1/12 h
#define Mnov 96192 // 1/12 h
#define Mjan 8928 // 1/12 h
#define Mjul 61056 // 1/12 h
#define Maug 69984 // 1/12 h
#define N 13 // years
#define NF 3 // years
#define NF2 10 // years
#define AGE 5 // years
#define AGE2 3 // years
#define I 10  // nodes along x axis
#define J 18  // nodes along y axis
#define K 6   // vertical layers number in seawater
#define RL 10   // vertical layers number in sediments
#define T 4  // Mullus Barbatus lifetime
#define T1 8
#define SUR 128 // pixel number within the basin
#define klev 5  // inlet 1 (Levante) depth
#define ksci 2  // inlet 2 (Scirocco) depth
#define L 12 // y-position of inlet 1
#define C 7  // x-position of inlet 2
#define H 9  // position external area 3 
#define iext1 9  // x-position of external area 1
#define iext2 9  // x-position of external area 2
#define iext3 9  // x-position of external area 3
#define jext1 8  // y-position of external area 1
#define jext2 16 // y-position of external area 2
#define jext3 17 // y-position of external area 3
#define P 528700 //
#define Q 365 // d
#define S 2
#define	dx 454.6 // m
#define	dy 454.6 // m
#define	dz 5.0 // m
#define	dz1 0.1 // m
#define	dz2 0.2 // m
#define B1 600000000.0 // cell/m^3
#define B1ext 600000000.0 // cell/m^3
#define dlHg  1.9 // ng/l  (detection limit for DHg and THg)



int main(int argc, char *argv[])
{

    FILE *fb1, *fct, *fR, *fI, *fHg0, *fHgII, *fMMHg, *fDHg, *fTHg, *fHgIIpw, *fMMHgpw; 
    FILE *fHgIIfluxsed, *fMMHgfluxsed;
    FILE *fHg0fluxatm, *fHg0fluxdep, *fHgIIfluxdep, *fMMHgfluxdep, *fP, *fPhy, *fZbiv, *fZpol, *fZamp, *fZdec, *fZmys, *fZost, *fFi, *fFisptmean, *fu, *fRelease, *fOutflow, *fEvasion, *fRecycled;
    FILE *fv5, *fv10, *fv20, *fv30, *fero, *fero2;
    FILE *fIin, *fPrec, *fTatm, *fHggas, *fHgIIatm, *fRin1,  *fRin2,  *fRin3,  *fRin4, *fRin5, *fRin6;
    FILE *fSPMin1, *fSPMin2, *fSPMin3, *fSPMin4, *fSPMin5, *fSPMin6, *fSPOMin1, *fSPOMin2, *fSPOMin3, *fSPOMin4, *fSPOMin5, *fSPOMin6;
    FILE *fTHgsedin,  *fTHgsedin2, *fTHgsedin3, *fTHgsedin4,  *fTHgsedin5, *fTHgsedin6, *fTHgsedin7,  *fTHgsedin8, *fTHgsedin9, *fTHgsedin10;
    FILE *fTHgsed, *ftotdep;
    FILE *fSWsed;
    FILE *fporsed;
    FILE *fporsed2, *fporsed3, *fporsed4, *fporsed5, *fporsed6, *fporsed7, *fporsed8, *fporsed9, *fporsed10;

    int i, j, k, m, n, p, q, r, idt, idtb;
    double Hg0[I+2][J+2][K+2], HgII[I+2][J+2][K+2], MMHg[I+2][J+2][K+2], DHg[I+2][J+2][K+2], THg[I+2][J+2][K+2], SPIM[I+2][J+2][K+2], SPOM[I+2][J+2][K+2], SPM[I+2][J+2][K+2], forg[I+2][J+2][K+2];
    double k1[I+2][J+2][K+2], k2[I+2][J+2][K+2];
    double Rin1[I+2][J+2], Rin2[I+2][J+2], Rin3[I+2][J+2], Rin4[I+2][J+2], Rin5[I+2][J+2], Rin6[I+2][J+2];
    double SPMin1[I+2][J+2], SPMin2[I+2][J+2], SPMin3[I+2][J+2], SPMin4[I+2][J+2], SPMin5[I+2][J+2], SPMin6[I+2][J+2], SPOMin1[I+2][J+2], SPOMin2[I+2][J+2], SPOMin3[I+2][J+2], SPOMin4[I+2][J+2], SPOMin5[I+2][J+2], SPOMin6[I+2][J+2];
    double THgsedin[I+2][J+2], SWsedin[I+2][J+2], porsedin[I+2][J+2], Iinin[Q+1][S+1], Tatmin[Q+1][S+1], Prin[Q+1][S+1], HgIIatmin[Q+1][S+1], Hggasin[Q+1][S+1];  
    double porsedin2[I+2][J+2], porsedin3[I+2][J+2], THgsedin2[I+2][J+2],  THgsedin3[I+2][J+2];
    double porsedin4[I+2][J+2], porsedin5[I+2][J+2], porsedin6[I+2][J+2], porsedin7[I+2][J+2], porsedin8[I+2][J+2], porsedin9[I+2][J+2], porsedin10[I+2][J+2];
    double THgsedin4[I+2][J+2], THgsedin5[I+2][J+2], THgsedin6[I+2][J+2], THgsedin7[I+2][J+2], THgsedin8[I+2][J+2], THgsedin9[I+2][J+2], THgsedin10[I+2][J+2];    
    double PHgII[I+2][J+2][K+2], PMMHg[I+2][J+2][K+2], PHg[I+2][J+2][K+2], PhyHgII[I+2][J+2][K+2], PhyMMHg[I+2][J+2][K+2], PHgIIfinal[I+2][J+2][K+2], PMMHgfinal[I+2][J+2][K+2], PHgIIfinal2[I+2][J+2][K+2], PMMHgfinal2[I+2][J+2][K+2];
    double Wfish, WfishAGE1, WfishAGE2, kfgr, kfinII, kfegr, logBCFII[I+2][J+2], kfurII[I+2][J+2], kfurMM[I+2][J+2], kfexrII, kfexrMM, lambmetII, lambmetMM, kfelimtot, kzbivelimtot, kzpolelimtot, kzampelimtot, kzdecelimtot, kzmyselimtot;
    double kzbivexrII, kzpolexrII, kzampexrII, kzdecexrII, kzmysexrII, kzostexrII, kzbivexrMM, kzpolexrMM, kzampexrMM, kzdecexrMM, kzmysexrMM, kzostexrMM, kzbivegrII, kzpolegrII, kzampegrII, kzdecegrII, kzmysegrII, kzostegrII, kzbivegrMM, kzpolegrMM, kzampegrMM, kzdecegrMM, kzmysegrMM, kzostegrMM, kzbivgr, kzpolgr, kzampgr, kzdecgr, kzostgr, kzmysgr;
    double lambmetbivII, lambmetpolII, lambmetampII, lambmetdecII, lambmetmysII, lambmetostII, lambmetbivMM, lambmetpolMM, lambmetampMM, lambmetdecMM, lambmetmysMM, lambmetostMM;
    double plipfood, kfinMM, pcarsed[I+2][J+2], kfinMMsed[I+2][J+2], kfegrMMsed[I+2][J+2];
    double FiHgIIre[I+2][J+2], FiHgIIGIT[I+2][J+2], FiHgIIGITdet[I+2][J+2], FiMMHgre[I+2][J+2], FiMMHgGIT[I+2][J+2], FiMMHgGITdet[I+2][J+2], FiHgII[I+2][J+2], FiMMHg[I+2][J+2], FiHgIIfinal[I+2][J+2], FiMMHgfinal[I+2][J+2], FiHgIIfinal2[I+2][J+2], FiMMHgfinal2[I+2][J+2];
    double PhyHgIIsptmean, PhyMMHgsptmean, ZbivHgIIsptmean, ZbivMMHgsptmean, ZpolHgIIsptmean, ZpolMMHgsptmean, ZampHgIIsptmean, ZampMMHgsptmean, ZdecHgIIsptmean, ZdecMMHgsptmean, ZmysHgIIsptmean, ZmysMMHgsptmean, ZostHgIIsptmean, ZostMMHgsptmean, FiHgIIsptmean, FiMMHgsptmean;
    double PhyHgIIsptmean2, PhyMMHgsptmean2, ZbivHgIIsptmean2, ZbivMMHgsptmean2, ZpolHgIIsptmean2, ZpolMMHgsptmean2, ZampHgIIsptmean2, ZampMMHgsptmean2, ZdecHgIIsptmean2, ZdecMMHgsptmean2, ZmysHgIIsptmean2, ZmysMMHgsptmean2, ZostHgIIsptmean2, ZostMMHgsptmean2, FiHgIIsptmean2, FiMMHgsptmean2;
    double MTCwaw[I+2][J+2], MTCwag[I+2][J+2], MTCwa[I+2][J+2]; 
    double SIIDOM[I+2][J+2][K+2], SIISPM[I+2][J+2][K+2], MTCIIsw[I+2][J+2], Dinsed[I+2][J+2][RL+2];
    double HgIIpw[I+2][J+2][RL+2];
    double SMMDOM[I+2][J+2][K+2], SMMSPM[I+2][J+2][K+2], MTCMMsw[I+2][J+2], Dorsed[I+2][J+2][RL+2];
    double MMHgpw[I+2][J+2][RL+2];
    double fluxHgIIsed[I+2][J+2], fluxMMHgsed[I+2][J+2];
    double fluxHg0atm[I+2][J+2], fluxHg0dep[I+2][J+2], fluxHgIIdep[I+2][J+2], fluxMMHgdep[I+2][J+2];
    double SLSPM[I+2][J+2][K+2];
    double b1[I+2][J+2][K+2], chla1[I+2][J+2][K+2], chlatot[I+2][J+2][K+2];
    double R[I+2][J+2][K+2], Rini[I+2][J+2][K+2], Iin, Tatm, Pr, HgIIatm, It[I+2][J+2][K+2], THgsed[I+2][J+2][RL+2], SWsed[I+2][J+2], porsed[I+2][J+2][RL+2];
    double THgsedold[I+2][J+2][RL+2];
    double G1[I+2][J+2][K+2], sommab1[I+2][J+2], sommab2[I+2][J+2];
    double F1R[I+2][J+2][K+2], F1I[I+2][J+2][K+2];
    double sumfluHg0x[I+2][J+2], sumfluHgIIx[I+2][J+2], sumfluMMHgx[I+2][J+2], sumfluTHgx[I+2][J+2], sumfluvx[I+2][J+2];
    double sumfluHg0xs[I+2][J+2], sumfluHgIIxs[I+2][J+2], sumfluMMHgxs[I+2][J+2], sumfluTHgxs[I+2][J+2], sumfluvxs[I+2][J+2];
    double sumfluHg0y[I+2][J+2], sumfluHgIIy[I+2][J+2], sumfluMMHgy[I+2][J+2], sumfluTHgy[I+2][J+2], sumfluvy[I+2][J+2];
    double **value1, **value2, **value3, **value5, **ero, **ero2;
    double vxc[I+2][J+2][K+2], vyc[I+2][J+2][K+2], vx[I+2][J+2][K+2], vy[I+2][J+2][K+2], vxold[I+2][J+2][K+2], vyold[I+2][J+2][K+2], vz[I+2][J+2][K+2], dep[I+2][J+2], depold[I+2][J+2], Totdep[I+2][J+2], Totdepold[I+2][J+2];
    double fluHg0x[I+2][J+2][K+2], fluHg0y[I+2][J+2][K+2], fluHg0z[I+2][J+2][K+2], fluHgIIx[I+2][J+2][K+2], fluHgIIy[I+2][J+2][K+2], fluHgIIz[I+2][J+2][K+2];
    double fluMMHgx[I+2][J+2][K+2], fluMMHgy[I+2][J+2][K+2], fluMMHgz[I+2][J+2][K+2];
    double flub1x[I+2][J+2][K+2], flub1y[I+2][J+2][K+2], flub1z[I+2][J+2][K+2], fluRx[I+2][J+2][K+2], fluRy[I+2][J+2][K+2], fluRz[I+2][J+2][K+2];
    double kphupII[I+2][J+2][K+2], kphexII, kphupMM[I+2][J+2][K+2], kphexMM, kphgr;
    double PHgIIexts26, PMMHgexts26, PHgexts26;
    double PHgIIextm26, PMMHgextm26, PHgextm26;
    double PHgIIextb26, PMMHgextb26, PHgextb26;
    double PHgIIexts27, PMMHgexts27, PHgexts27;
    double PHgIIextm27, PMMHgextm27, PHgextm27;
    double PHgIIextb27, PMMHgextb27, PHgextb27;
    double TotfluHg0xlev, fluHg0xlev, TotfluHgIIxlev, fluHgIIxlev, TotfluMMHgxlev, fluMMHgxlev, fluTHgxlev, Totlev;
    double TotfluHg0xysci, fluHg0xsci, fluHg0ysci, TotfluHgIIxysci, fluHgIIxsci, fluHgIIysci, TotfluMMHgxysci, fluMMHgxsci, fluMMHgysci, fluTHgxsci, fluTHgysci, Totsci;
    double fluHgIIzsed, fluMMHgzsed, fluHgIIzsedext1, fluHgIIzsedext2, fluHgIIzsedext3, fluMMHgzsedext1, fluMMHgzsedext2, fluMMHgzsedext3;
    double fluHgIIzbur, fluHgIIzburext1, fluHgIIzburext2, fluHgIIzburext3;
    double fluMMHgzbur, fluMMHgzburext1, fluMMHgzburext2, fluMMHgzburext3;
    double fluHgIIzbur2, fluHgIIzburext12, fluHgIIzburext22, fluHgIIzburext32;
    double fluMMHgzbur2, fluMMHgzburext12, fluMMHgzburext22, fluMMHgzburext32;
    double fluxHg0zatm, fluxHg0zdep, fluxHgIIzdep, fluxMMHgzdep, fluxHg0zatmext1, fluxHg0zdepext1, fluxHgIIzdepext1, fluxMMHgzdepext1;
    double fluxHg0zatmext2, fluxHg0zdepext2, fluxHgIIzdepext2, fluxMMHgzdepext2, fluxHg0zatmext3, fluxHg0zdepext3, fluxHgIIzdepext3, fluxMMHgzdepext3;
    double TotfluHgIIzsed, TotfluMMHgzsed, TotfluHgIIzsedext1, TotfluHgIIzsedext2, TotfluHgIIzsedext3, TotfluMMHgzsedext1, TotfluMMHgzsedext2, TotfluMMHgzsedext3;
    double TotHgIIsed, TotMMHgsed, TotHgsed, TotSIISPM, TotSMMSPM, TotSIIDOM, TotSMMDOM;
    double TotHgIIbur, TotfluHgIIzbur, TotfluHgIIzburext1, TotfluHgIIzburext2, TotfluHgIIzburext3;
    double TotMMHgbur, TotfluMMHgzbur, TotfluMMHgzburext1, TotfluMMHgzburext2, TotfluMMHgzburext3;
    double TotHgIIbur2, TotfluHgIIzbur2, TotfluHgIIzburext12, TotfluHgIIzburext22, TotfluHgIIzburext32;
    double TotMMHgbur2, TotfluMMHgzbur2, TotfluMMHgzburext12, TotfluMMHgzburext22, TotfluMMHgzburext32;
    double TotfluHg0atm, TotfluHg0zatm, TotfluHg0zatmext1, TotfluHg0zatmext2, TotfluHg0zatmext3;
    double TotfluHg0dep, TotfluHg0zdep, TotfluHg0zdepext1, TotfluHg0zdepext2, TotfluHg0zdepext3;
    double TotfluHgIIdep, TotfluHgIIzdep, TotfluHgIIzdepext1, TotfluHgIIzdepext2, TotfluHgIIzdepext3;
    double TotfluMMHgdep, TotfluMMHgzdep, TotfluMMHgzdepext1, TotfluMMHgzdepext2, TotfluMMHgzdepext3;
    double TotfluHgdep, TotHgbur, TotHgbur2;
    double NPP[I+2][J+2][K+2], peratio[I+2][J+2][K+2], Hggas, OCRR[I+2][J+2][K+2], k3[I+2][J+2][K+2], k4[I+2][J+2][K+2], dt;
    double psphy, psbiv, pspol, psamp, psdec, psmys, psost, pssed, psfish, psfoodfish1, psfoodfisht, psfoodfish, psfoodbiv, psfoodpol, psfoodamp, psfooddec, psfoodost, psfoodmys;
    double kfegrII, kfegrMM;
    double kfinbivII, kfinpolII, kfinampII, kfindecII, kfinmysII, kfinostII, kfinsedII;
    double kfinbivMM, kfinpolMM, kfinampMM, kfindecMM, kfinmysMM, kfinostMM, kfinsedMM;
    double kzbivurII[I+2][J+2], kzpolurII[I+2][J+2], kzampurII[I+2][J+2], kzdecurII[I+2][J+2], kzosturII[I+2][J+2], kzmysurII[I+2][J+2];
    double kzbivurMM[I+2][J+2], kzpolurMM[I+2][J+2], kzampurMM[I+2][J+2], kzdecurMM[I+2][J+2], kzosturMM[I+2][J+2], kzmysurMM[I+2][J+2];
    double kzbivinphyII, kzbivinsedII, kzpolinsedII, kzampinphyII, kzampinsedII, kzdecinphyII, kzmysinphyII, kzdecinpolII, kzostinphyII, kzostinbivII, kzostinampII, kzostinmysII, kzostinpolII, kzostindecII, kzostinostII, kzostinsedII, kzdecinbivII, kzmysinpolII, kzmysinampII, kzdecinsedII, kzmysinsedII, kzpolinampII, kzpolinpolII, kzdecindecII, kzdecinostII;
    double kzbivinphyMM, kzbivinsedMM, kzpolinsedMM, kzampinphyMM, kzampinsedMM, kzdecinphyMM, kzmysinphyMM, kzdecinpolMM, kzostinphyMM, kzostinbivMM, kzostinampMM, kzostinmysMM, kzostinpolMM, kzostindecMM, kzostinostMM, kzostinsedMM, kzdecinbivMM, kzmysinpolMM, kzmysinampMM, kzdecinsedMM, kzmysinsedMM, kzpolinampMM, kzpolinpolMM, kzdecindecMM, kzdecinostMM;
    double ZbivHgII[I+2][J+2],  ZpolHgII[I+2][J+2],  ZampHgII[I+2][J+2], ZdecHgII[I+2][J+2], ZostHgII[I+2][J+2], ZmysHgII[I+2][J+2];
    double ZbivMMHg[I+2][J+2],  ZpolMMHg[I+2][J+2],  ZampMMHg[I+2][J+2], ZdecMMHg[I+2][J+2], ZostMMHg[I+2][J+2], ZmysMMHg[I+2][J+2]; 
    double Mbir1, Mbir2, Madu1, Madu2, deprefbivdet, deprefpoldet, deprefampdet, deprefdecdet, deprefmysdet, deprefostdet;
	double PrefZoobivt, PrefZoopolt, PrefZooampt, PrefZoodect, PrefZoomyst, PrefZooostt;
    
    char *tmp,buf[20],buf1[50]; 

	
    value1= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value1[p]=(double*)malloc(2 * sizeof(double));
    } 

    value2= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value2[p]=(double*)malloc(2 * sizeof(double));
    } 

    value3= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value3[p]=(double*)malloc(2 * sizeof(double));
    }    

    value5= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        value5[p]=(double*)malloc(2 * sizeof(double));
    } 

    ero= (double**)malloc(528700 * sizeof(double*));
    for (p=1; p<=528700; p++){
        ero[p]=(double*)malloc(1 * sizeof(double));
    }
    
    ero2= (double**)malloc(180 * sizeof(double*));
    for (p=1; p<=180; p++){
        ero2[p]=(double*)malloc(1 * sizeof(double));
    }

	if((fb1=fopen("Phyto_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fct=fopen("Chlor_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fR=fopen("Nutrient_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fI=fopen("Light_int.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}


	if((fHg0=fopen("Hg0_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fHgII=fopen("HgII_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fMMHg=fopen("MMHg_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

	if((fDHg=fopen("DHg_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fTHg=fopen("THg_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

	if((fHgIIpw=fopen("HgIIpw_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

    if((fMMHgpw=fopen("MMHgpw_conc.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fTHgsed=fopen("THgsed.txt", "wb+"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  
  	if((ftotdep=fopen("Totdep.txt", "wb+"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fHgIIfluxsed=fopen("FluxHgIIsed.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}

    if((fMMHgfluxsed=fopen("FluxMMHgsed.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  		
  	if((fHg0fluxatm=fopen("FluxHg0atm.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fHg0fluxdep=fopen("FluxHg0dep.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fHgIIfluxdep=fopen("FluxHgIIdep.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fMMHgfluxdep=fopen("FluxMMHgdep.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");
  		exit(1);
  	}
  	
  	if((fu=fopen("mass-balance.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fRelease=fopen("R_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fOutflow=fopen("O-I_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fEvasion=fopen("V-AD_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fRecycled=fopen("D_time.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fP=fopen("Mercury-Phyto.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fPhy=fopen("Mercury-Phyto.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
    if((fZbiv=fopen("Mercury-Zoo-Bivalvia.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fZpol=fopen("Mercury-Zoo-Polychaeta.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fZamp=fopen("Mercury-Zoo-Amphipoda.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fZdec=fopen("Mercury-Zoo-Decapoda.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fZmys=fopen("Mercury-Zoo-Mysidacea.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
  	if((fZost=fopen("Mercury-Zoo-Osteichthyes.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

    if((fFi=fopen("Mercury-Fish.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}

  	if((fFisptmean=fopen("Spatio-temp_mean_mercury_fish.txt", "wb+"))==NULL)
  	{
  		printf("Impossibile aprire il file di dati\n");    
  		exit(1);
  	}
  	
	if((fRin1=fopen("Rin1.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPMin1=fopen("SPMin1.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin1=fopen("SPOMin1.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
 
	if((fRin2=fopen("Rin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPMin2=fopen("SPMin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPOMin2=fopen("SPOMin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin3=fopen("Rin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fSPMin3=fopen("SPMin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin3=fopen("SPOMin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin4=fopen("Rin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPMin4=fopen("SPMin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin4=fopen("SPOMin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin5=fopen("Rin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPMin5=fopen("SPMin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin5=fopen("SPOMin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fRin6=fopen("Rin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPMin6=fopen("SPMin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSPOMin6=fopen("SPOMin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fTHgsedin=fopen("THgsedin.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin2=fopen("THgsedin2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin3=fopen("THgsedin3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin4=fopen("THgsedin4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin5=fopen("THgsedin5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin6=fopen("THgsedin6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin7=fopen("THgsedin7.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin8=fopen("THgsedin8.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin9=fopen("THgsedin9.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTHgsedin10=fopen("THgsedin10.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fSWsed=fopen("SWsed.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

    if((fporsed=fopen("porsed.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed2=fopen("porsed2.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed3=fopen("porsed3.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed4=fopen("porsed4.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed5=fopen("porsed5.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed6=fopen("porsed6.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed7=fopen("porsed7.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed8=fopen("porsed8.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed9=fopen("porsed9.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fporsed10=fopen("porsed10.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fIin=fopen("Iin.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fTatm=fopen("Tatm.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fPrec=fopen("Prec.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}
  	
  	if((fHggas=fopen("Hg0gas.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

	if((fHgIIatm=fopen("HgIIatm.txt", "r"))==NULL)
  	{
  		printf("Errore di apertura  file\n");
  		exit(1);
  	}

  	
    if((fv5=fopen("newlev_0_5.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
	
	if((fv10=fopen("newlev_5_10.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
 
	if((fv20=fopen("newlev_10_20.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
		
	if((fv30=fopen("newlev_20_30.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}

    if((fero=fopen("erosion.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
	
	if((fero2=fopen("erosion2.txt","r"))==NULL)
	{
		printf("Errore di apertura  file\n");
		exit(1);
	}
	
	dt=(double) tempo/M; // h
	Iin=339.83; // micromol photons/(m^2*sec)
	Tatm=13.17; // °C
	Pr=0.00268; // m
	HgIIatm=21000.000; //ng/m^3
	Hggas=1.59; // ng/m^3
	idt=(int) 3*pow(dt,-1);
	idtb=12;
	
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x

     fscanf(fRin1,"%lf", &Rin1[i][j]); 
     fscanf(fSPMin1,"%lf", &SPMin1[i][j]); 
     fscanf(fSPOMin1,"%lf", &SPOMin1[i][j]); 
                
     Rini[i][j][1]=Rin1[i][j];
     SPM[i][j][1]=SPMin1[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][1]=SPOMin1[i][j]*pow(10.0,-6.0); //Kg/l
     
     } 
  } 
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin2,"%lf", &Rin2[i][j]); 
     fscanf(fSPMin2,"%lf", &SPMin2[i][j]); 
     fscanf(fSPOMin2,"%lf", &SPOMin2[i][j]);
                
     Rini[i][j][2]=Rin2[i][j];
     SPM[i][j][2]=SPMin2[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][2]=SPOMin2[i][j]*pow(10.0,-6.0); //Kg/l
     
     } 
  }
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin3,"%lf", &Rin3[i][j]); 
     fscanf(fSPMin3,"%lf", &SPMin3[i][j]); 
     fscanf(fSPOMin3,"%lf", &SPOMin3[i][j]);

     Rini[i][j][3]=Rin3[i][j]; 
     SPM[i][j][3]=SPMin3[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][3]=SPOMin3[i][j]*pow(10.0,-6.0); //Kg/l     
     
     } 
  }                       
               
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin4,"%lf", &Rin4[i][j]);
     fscanf(fSPMin4,"%lf", &SPMin4[i][j]); 
     fscanf(fSPOMin4,"%lf", &SPOMin4[i][j]); 

     Rini[i][j][4]=Rin4[i][j];  
     SPM[i][j][4]=SPMin4[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][4]=SPOMin4[i][j]*pow(10.0,-6.0); //Kg/l       
     
     } 
  }           
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin5,"%lf", &Rin5[i][j]); 
     fscanf(fSPMin5,"%lf", &SPMin5[i][j]); 
     fscanf(fSPOMin5,"%lf", &SPOMin5[i][j]); 

     Rini[i][j][5]=Rin5[i][j]; 
     SPM[i][j][5]=SPMin5[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][5]=SPOMin5[i][j]*pow(10.0,-6.0); //Kg/l        
     
     } 
  }            
                      
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fRin6,"%lf", &Rin6[i][j]); 
     fscanf(fSPMin6,"%lf", &SPMin6[i][j]); 
     fscanf(fSPOMin6,"%lf", &SPOMin6[i][j]); 

     Rini[i][j][6]=Rin6[i][j]; 
     SPM[i][j][6]=SPMin6[i][j]*pow(10.0,-6.0); //Kg/l
     SPOM[i][j][6]=SPOMin6[i][j]*pow(10.0,-6.0); //Kg/l              
     
     } 
  } 
  
  
  for(i=0; i<=I; i++){ // rispetto allo spazio y 
     for(k=0; k<=K; k++){ // rispetto allo spazio x
                     
     Rini[i][0][k]=0.000000;         
     b1[i][0][k]=0.000000; 
     Hg0[i][0][k]=0.000000; 
     HgII[i][0][k]=0.000000;  
     MMHg[i][0][k]=0.000000;
     DHg[i][0][k]=0.000000;
     SPM[i][0][k]=0.000000;
     SPOM[i][0][k]=0.000000;
     R[i][0][k]=0.000000;
     vxc[i][0][k]=0.000000;
     vyc[i][0][k]=0.000000;
     
     } 
  } 
  
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(k=0; k<=K; k++){ // rispetto allo spazio x
                     
     Rini[0][j][k]=0.000000;
     b1[0][j][k]=0.000000;
     Hg0[0][j][k]=0.000000;
     HgII[0][j][k]=0.000000; 
     MMHg[0][j][k]=0.000000;
     DHg[0][j][k]=0.000000;
     SPM[0][j][k]=0.000000;
     SPOM[0][j][k]=0.000000;
     R[0][j][k]=0.000000; 
     vxc[0][j][k]=0.000000;
     vyc[0][j][k]=0.000000;   
     
     } 
  } 
 
  for(j=1; j<=J; j++){ // rispetto allo spazio y 
     for(i=1; i<=I; i++){ // rispetto allo spazio x
     
     fscanf(fTHgsedin,"%lf", &THgsedin[i][j]); 
     fscanf(fTHgsedin2,"%lf", &THgsedin2[i][j]); 
     fscanf(fTHgsedin3,"%lf", &THgsedin3[i][j]); 
     fscanf(fTHgsedin4,"%lf", &THgsedin4[i][j]); 
     fscanf(fTHgsedin5,"%lf", &THgsedin5[i][j]); 
     fscanf(fTHgsedin6,"%lf", &THgsedin6[i][j]); 
     fscanf(fTHgsedin7,"%lf", &THgsedin7[i][j]); 
     fscanf(fTHgsedin8,"%lf", &THgsedin8[i][j]); 
     fscanf(fTHgsedin9,"%lf", &THgsedin9[i][j]); 
     fscanf(fTHgsedin10,"%lf", &THgsedin10[i][j]); 
     fscanf(fSWsed,"%lf", &SWsedin[i][j]);
     fscanf(fporsed,"%lf", &porsedin[i][j]);
     fscanf(fporsed2,"%lf", &porsedin2[i][j]);
     fscanf(fporsed3,"%lf", &porsedin3[i][j]);
     fscanf(fporsed4,"%lf", &porsedin4[i][j]);
     fscanf(fporsed5,"%lf", &porsedin5[i][j]);
     fscanf(fporsed6,"%lf", &porsedin6[i][j]);
     fscanf(fporsed7,"%lf", &porsedin7[i][j]);
     fscanf(fporsed8,"%lf", &porsedin8[i][j]);
     fscanf(fporsed9,"%lf", &porsedin9[i][j]);
     fscanf(fporsed10,"%lf", &porsedin10[i][j]);
     
     THgsed[i][j][1]=THgsedin[i][j];
     THgsed[i][j][2]=THgsedin2[i][j]; 
     THgsed[i][j][3]=THgsedin3[i][j]; 
     THgsed[i][j][4]=THgsedin4[i][j];
     THgsed[i][j][5]=THgsedin5[i][j]; 
     THgsed[i][j][6]=THgsedin6[i][j]; 
     THgsed[i][j][7]=THgsedin7[i][j];
     THgsed[i][j][8]=THgsedin8[i][j]; 
     THgsed[i][j][9]=THgsedin9[i][j]; 
     THgsed[i][j][10]=THgsedin10[i][j]; 
     SWsed[i][j]=SWsedin[i][j];
     porsed[i][j][1]=porsedin[i][j]; 
     porsed[i][j][2]=porsedin2[i][j]; 
     porsed[i][j][3]=porsedin3[i][j]; 
     porsed[i][j][4]=porsedin4[i][j]; 
     porsed[i][j][5]=porsedin5[i][j]; 
     porsed[i][j][6]=porsedin6[i][j]; 
     porsed[i][j][7]=porsedin7[i][j]; 
     porsed[i][j][8]=porsedin8[i][j]; 
     porsed[i][j][9]=porsedin9[i][j]; 
     porsed[i][j][10]=porsedin10[i][j]; 
     
     } 
  } 
  
  Mbir1=Mmay;
  Mbir2=Mmar;
  Madu1=Mmay;
  Madu2=Mmar;
  deprefbivdet=(PrefZoobiv-PrefZoobiv1)/(105120*dt);
  deprefpoldet=(PrefZoopol-PrefZoopol1)/(105120*dt);
  deprefampdet=(PrefZooamp-PrefZooamp1)/(105120*dt);
  deprefmysdet=(PrefZoomys-PrefZoomys1)/(105120*dt);
  deprefdecdet=(PrefZoodec-PrefZoodec1)/(105120*dt);
  deprefostdet=(PrefZooost-PrefZooost1)/(105120*dt);
  
  psphy=0.20*pow(Wp1*pow(10.0,-9.0),0.03); //Kg dry/Kg wet
  kphexII=(1.0/(psphy*KtwII))*(pow(Wp1*pow(10.0,-9.0),-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kphexMM=(1.0/(psphy*KtwMM))*(pow(Wp1*pow(10.0,-9.0),-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kphgr=qT*gamgrow*pow(Wp1*pow(10.0,-9.0),-1.0*kal); //1/d
  
  psbiv=0.20*pow(Wzbiv,0.03); //Kg dry/Kg wet
  pspol=0.20*pow(Wzpol,0.03); //Kg dry/Kg wet
  psamp=0.20*pow(Wzamp,0.03); //Kg dry/Kg wet
  psdec=0.20*pow(Wzdec,0.03); //Kg dry/Kg wet
  psmys=0.20*pow(Wzmys,0.03); //Kg dry/Kg wet
  psost=0.20*pow(Wzost,0.03); //Kg dry/Kg wet
  pssed=1.0;
  psfoodbiv=PrefPhybiv*psphy+Prefsedbiv*pssed;  //Kg dry/Kg wet
  psfoodpol=Prefsedbotpol*pssed+PrefZooamppol*psamp+PrefZoopolpol*pspol;  //Kg dry/Kg wet
  psfoodamp=PrefPhyamp*psphy+Prefsedamp*pssed;  //Kg dry/Kg wet
  psfooddec=PrefPhydec*psphy+PrefZoobivdec*psbiv+PrefZoopoldec*pspol+Prefsedbotdec*pssed+PrefZooostdec*psost+PrefZoodecdec*psdec;  //Kg dry/Kg wet
  psfoodmys=PrefPhymys*psphy+PrefZoopolmys*pspol+PrefZooampmys*psamp+Prefsedmys*pssed;
  psfoodost=PrefPhyost*psphy+PrefZoobivost*psbiv+PrefZooampost*psamp+PrefZoomysost*psmys+PrefZoodecost*psdec+PrefZoopolost*pspol+PrefZooostost*psost+Prefsedost*pssed; 
  kzbivinphyII=AssFoodbivII*qT*gamfood*pow(Wzbiv,-1.0*kal);
  kzbivinsedII=AssFoodbivII*qT*gamfood*pow(Wzbiv,-1.0*kal);
  kzpolinsedII=AssFoodpolII*qT*gamfood*pow(Wzpol,-1.0*kal); // 1/d
  kzpolinampII=AssFoodpolII*qT*gamfood*pow(Wzpol,-1.0*kal); // 1/d
  kzpolinpolII=AssFoodpolII*qT*gamfood*pow(Wzpol,-1.0*kal); // 1/d
  kzampinphyII=AssFoodampII*qT*gamfood*pow(Wzamp,-1.0*kal);
  kzampinsedII=AssFoodampII*qT*gamfood*pow(Wzamp,-1.0*kal);
  kzdecinphyII=AssFooddecII*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecinpolII=AssFooddecII*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecinbivII=AssFooddecII*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecinostII=AssFooddecII*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecindecII=AssFooddecII*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d 
  kzdecinsedII=AssFooddecII*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d  
  kzmysinphyII=AssFoodmysII*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d
  kzmysinpolII=AssFoodmysII*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d
  kzmysinampII=AssFoodmysII*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d
  kzmysinsedII=AssFoodmysII*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d               
  kzostinphyII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinbivII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinampII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinmysII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinpolII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostindecII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinostII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinsedII=AssFoodostII*qT*gamfood*pow(Wzost,-1.0*kal);
  kzbivinphyMM=AssFoodbivMM*qT*gamfood*pow(Wzbiv,-1.0*kal);
  kzbivinsedMM=AssFoodbivMM*qT*gamfood*pow(Wzbiv,-1.0*kal);
  kzpolinsedMM=AssFoodpolMM*qT*gamfood*pow(Wzpol,-1.0*kal); // 1/d
  kzpolinampMM=AssFoodpolMM*qT*gamfood*pow(Wzpol,-1.0*kal); // 1/d
  kzpolinpolMM=AssFoodpolMM*qT*gamfood*pow(Wzpol,-1.0*kal); // 1/d
  kzampinphyMM=AssFoodampMM*qT*gamfood*pow(Wzamp,-1.0*kal);
  kzampinsedMM=AssFoodampMM*qT*gamfood*pow(Wzamp,-1.0*kal);
  kzdecinphyMM=AssFooddecMM*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecinpolMM=AssFooddecMM*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecinbivMM=AssFooddecMM*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecinostMM=AssFooddecMM*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzdecindecMM=AssFooddecMM*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d 
  kzdecinsedMM=AssFooddecMM*qT*gamfood*pow(Wzdec,-1.0*kal); // 1/d
  kzmysinphyMM=AssFoodmysMM*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d
  kzmysinpolMM=AssFoodmysMM*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d
  kzmysinampMM=AssFoodmysMM*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d
  kzmysinsedMM=AssFoodmysMM*qT*gamfood*pow(Wzmys,-1.0*kal); // 1/d               
  kzostinphyMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinbivMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinampMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinmysMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinpolMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostindecMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinostMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzostinsedMM=AssFoodostMM*qT*gamfood*pow(Wzost,-1.0*kal);
  kzbivexrII=(1.0/(psbiv*KtwII))*(pow(Wzbiv,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzpolexrII=(1.0/(pspol*KtwII))*(pow(Wzpol,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzampexrII=(1.0/(psamp*KtwII))*(pow(Wzamp,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzdecexrII=(1.0/(psdec*KtwII))*(pow(Wzdec,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzmysexrII=(1.0/(psmys*KtwII))*(pow(Wzmys,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzostexrII=(1.0/(psost*KtwII))*(pow(Wzost,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzbivexrMM=(1.0/(psbiv*KtwMM))*(pow(Wzbiv,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzpolexrMM=(1.0/(pspol*KtwMM))*(pow(Wzpol,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzampexrMM=(1.0/(psamp*KtwMM))*(pow(Wzamp,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzdecexrMM=(1.0/(psdec*KtwMM))*(pow(Wzdec,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzmysexrMM=(1.0/(psmys*KtwMM))*(pow(Wzmys,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzostexrMM=(1.0/(psost*KtwMM))*(pow(Wzost,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
  kzbivegrII=(1.0/(psbiv*KtwII))*(pow(Wzbiv,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodbiv*KtwII*(1.0-AssFoodbiv)*qT*gamfood)))); // 1/d
  kzpolegrII=(1.0/(pspol*KtwII))*(pow(Wzpol,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodpol*KtwII*(1.0-AssFoodpol)*qT*gamfood)))); // 1/d
  kzampegrII=(1.0/(psamp*KtwII))*(pow(Wzamp,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodamp*KtwII*(1.0-AssFoodamp)*qT*gamfood)))); // 1/d
  kzdecegrII=(1.0/(psdec*KtwII))*(pow(Wzdec,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfooddec*KtwII*(1.0-AssFooddec)*qT*gamfood)))); // 1/d
  kzmysegrII=(1.0/(psmys*KtwII))*(pow(Wzmys,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodmys*KtwII*(1.0-AssFoodmys)*qT*gamfood)))); // 1/d
  kzostegrII=(1.0/(psost*KtwII))*(pow(Wzost,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodost*KtwII*(1.0-AssFoodost)*qT*gamfood)))); // 1/d
  kzbivegrMM=(1.0/(psbiv*KtwMM))*(pow(Wzbiv,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodbiv*KtwMM*(1.0-AssFoodbiv)*qT*gamfood)))); // 1/d
  kzpolegrMM=(1.0/(pspol*KtwMM))*(pow(Wzpol,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodpol*KtwMM*(1.0-AssFoodpol)*qT*gamfood)))); // 1/d
  kzampegrMM=(1.0/(psamp*KtwMM))*(pow(Wzamp,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodamp*KtwMM*(1.0-AssFoodamp)*qT*gamfood)))); // 1/d
  kzdecegrMM=(1.0/(psdec*KtwMM))*(pow(Wzdec,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfooddec*KtwMM*(1.0-AssFooddec)*qT*gamfood)))); // 1/d
  kzmysegrMM=(1.0/(psmys*KtwMM))*(pow(Wzmys,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodmys*KtwMM*(1.0-AssFoodmys)*qT*gamfood)))); // 1/d
  kzostegrMM=(1.0/(psost*KtwMM))*(pow(Wzost,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodost*KtwMM*(1.0-AssFoodost)*qT*gamfood)))); // 1/d
  kzbivgr=qT*gamgrow*pow(Wzbiv,-1.0*kal); //1/d
  kzpolgr=qT*gamgrow*pow(Wzpol,-1.0*kal); //1/d
  kzampgr=qT*gamgrow*pow(Wzamp,-1.0*kal); //1/d
  kzdecgr=qT*gamgrow*pow(Wzdec,-1.0*kal); //1/d
  kzmysgr=qT*gamgrow*pow(Wzmys,-1.0*kal); //1/d
  kzostgr=qT*gamgrow*pow(Wzost,-1.0*kal); //1/d
  lambmetbivII=0.0;
  lambmetpolII=0.0;
  lambmetampII=0.0;
  lambmetdecII=0.0;
  lambmetmysII=0.0;
  lambmetostII=0.0;
  lambmetbivMM=0.0;
  lambmetpolMM=0.0;
  lambmetampMM=0.0;
  lambmetdecMM=0.0;
  lambmetmysMM=0.0;
  lambmetostMM=0.0;
  
  Wfish=aWf*pow((Lfish0/10.0),bWf)*pow(10.0,-3.0); // Kg
  psfoodfish1=PrefZoobiv1*psbiv+PrefZoopol1*pspol+PrefZooamp1*psamp+PrefZoodec1*psdec+PrefZoomys1*psmys+PrefZooost1*psost+Prefsed1*pssed;  //Kg dry/Kg wet
  psfoodfish=PrefZoobiv*psbiv+PrefZoopol*pspol+PrefZooamp*psamp+PrefZoodec*psdec+PrefZoomys*psmys+PrefZooost*psost+Prefsed*pssed;  //Kg dry/Kg wet
  lambmetII=0.0;
  lambmetMM=0.0;
  
  for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
        for(k=1; k<=K; k++){ // rispetto allo spazio z
        
        if(Rini[i][j][k]>=Rin){             
            DHg[i][j][k]=dlHg; // ng/l or microg/m^3 
            THg[i][j][k]=dlHg; // ng/l or microg/m^3 
        }
        else{
            DHg[i][j][k]=0.0; // ng/l or microg/m^3 
            THg[i][j][k]=0.0; // ng/l or microg/m^3 
        } 
        
        Hg0[i][j][k]=0.2*DHg[i][j][k]; // ng/l or microg/m^3
        HgII[i][j][k]=0.794*DHg[i][j][k]; // ng/l or microg/m^3
        MMHg[i][j][k]=0.006*DHg[i][j][k]; // ng/l or microg/m^3
        kphupII[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((HgII[i][j][k]*pow(10.0,-3.0)),kpII)+(1.0/gamwat)); // l/(Kg*d)
        kphupMM[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((MMHg[i][j][k]*pow(10.0,-3.0)),kpMM)+(1.0/gamwat)); // l/(Kg*d)
        PHgII[i][j][k]=(Wp1*kphupII[i][j][k]*HgII[i][j][k]*pow(10.0,-12.0))/(kphexII+kphgr); //  microg
        PMMHg[i][j][k]=(Wp1*kphupMM[i][j][k]*MMHg[i][j][k]*pow(10.0,-12.0))/(kphexMM+kphgr); //  microg
        PHg[i][j][k]=PHgII[i][j][k]+PMMHg[i][j][k]; //  microg
        R[i][j][k]=Rini[i][j][k];
        
        if(Hg0[i][j][k]<=0.000000){
				Hg0[i][j][k]=0.0;
	    }
			
        if(HgII[i][j][k]<=0.000000){
				HgII[i][j][k]=0.0;
        }
			
        if(MMHg[i][j][k]<=0.000000){
				MMHg[i][j][k]=0.0;
        }
     
        if(PHgII[i][j][k]<=0.000000){
				PHgII[i][j][k]=0.0;
        }
		   
        if(PMMHg[i][j][k]<=0.000000){
				PMMHg[i][j][k]=0.0;
        }
			
        if(PHg[i][j][k]<=0.000000){
				PHg[i][j][k]=0.0;
        }

        if(Rini[i][j][k]==Rbot){

         kphupII[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((HgII[i][j][k]*pow(10.0,-3.0)),kpII)+(1.0/gamwat)); // l/(Kg*d)
         kphupMM[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((MMHg[i][j][k]*pow(10.0,-3.0)),kpMM)+(1.0/gamwat)); // l/(Kg*d)
         PhyHgII[i][j][k]=(kphupII[i][j][k]*HgII[i][j][k]*pow(10.0,-6.0))/(kphexII+kphgr); //  microg/g or mg/Kg
         PhyMMHg[i][j][k]=(kphupMM[i][j][k]*MMHg[i][j][k]*pow(10.0,-6.0))/(kphexMM+kphgr); //  microg/g or mg/Kg

         if(PhyHgII[i][j][k]<=0.000000){
		 		PhyHgII[i][j][k]=0.0;
         }
		   
         if(PhyMMHg[i][j][k]<=0.000000){
				PhyMMHg[i][j][k]=0.0;
         }
                   
           kzbivurII[i][j]=pow(Wzbiv,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzpolurII[i][j]=pow(Wzpol,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzampurII[i][j]=pow(Wzamp,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzdecurII[i][j]=pow(Wzdec,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzmysurII[i][j]=pow(Wzmys,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzosturII[i][j]=pow(Wzost,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzbivurMM[i][j]=pow(Wzbiv,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzpolurMM[i][j]=pow(Wzpol,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzampurMM[i][j]=pow(Wzamp,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzdecurMM[i][j]=pow(Wzdec,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzmysurMM[i][j]=pow(Wzmys,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzosturMM[i][j]=pow(Wzost,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           
           ZbivHgII[i][j]=((kzbivurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzbivinphyII*PrefPhybiv*PhyHgII[i][j][k]+kzbivinsedII*Prefsedbiv*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzbivexrII+kzbivegrII+kzbivgr+lambmetbivII); // microg/g or mg/Kg
           ZampHgII[i][j]=((kzampurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzampinphyII*PrefPhyamp*PhyHgII[i][j][k]+kzampinsedII*Prefsedamp*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzampexrII+kzampegrII+kzampgr+lambmetampII); // microg/g or mg/Kg
           ZpolHgII[i][j]=((kzpolurII[i][j]*HgIIpw[i][j][1]*pow(10.0,-6.0))+(kzpolinsedII*Prefsedbotpol*((1.0-kMM)*THgsed[i][j][1])+kzpolinampII*PrefZooamppol*ZampHgII[i][j]+kzpolinpolII*PrefZoopolpol*ZpolHgII[i][j]))/(kzpolexrII+kzpolegrII+kzpolgr+lambmetpolII); // microg/g or mg/Kg
           ZmysHgII[i][j]=((kzmysurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzmysinphyII*PrefPhymys*PhyHgII[i][j][k]+kzmysinpolII*PrefZoopolmys*ZpolHgII[i][j]+kzmysinampII*PrefZooampmys*ZampHgII[i][j]+kzmysinsedII*Prefsedmys*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzmysexrII+kzmysegrII+kzmysgr+lambmetmysII); // microg/g or mg/Kg
           ZostHgII[i][j]=((kzosturII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzostinphyII*PrefPhyost*PhyHgII[i][j][k]+kzostinbivII*PrefZoobivost*ZbivHgII[i][j]+kzostinampII*PrefZooampost*ZampHgII[i][j]+kzostinmysII*PrefZoomysost*ZmysHgII[i][j]+kzostindecII*PrefZoodecost*ZdecHgII[i][j]+kzostinpolII*PrefZoopolost*ZpolHgII[i][j]+kzostinostII*PrefZooostost*ZostHgII[i][j]+kzostinsedII*Prefsedost*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzostexrII+kzostegrII+kzostgr+lambmetostII); // microg/g or mg/Kg
           ZdecHgII[i][j]=((kzdecurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzdecinphyII*PrefPhydec*PhyHgII[i][j][k]+kzdecinpolII*PrefZoopoldec*ZpolHgII[i][j]+kzdecinbivII*PrefZoobivdec*ZbivHgII[i][j]+kzdecinostII*PrefZooostdec*ZostHgII[i][j]+kzdecindecII*PrefZoodecdec*ZdecHgII[i][j]+kzdecinsedII*Prefsedbotdec*((1.0-kMM)*THgsed[i][j][1])))/(kzdecexrII+kzdecegrII+kzdecgr+lambmetdecII); // microg/g or mg/Kg
           
           ZbivMMHg[i][j]=((kzbivurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzbivinphyMM*PrefPhybiv*PhyMMHg[i][j][k]+kzbivinsedMM*Prefsedbiv*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzbivexrMM+kzbivegrMM+kzbivgr+lambmetbivMM); // microg/g or mg/Kg
           ZampMMHg[i][j]=((kzampurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzampinphyMM*PrefPhyamp*PhyMMHg[i][j][k]+kzampinsedMM*Prefsedamp*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzampexrMM+kzampegrMM+kzampgr+lambmetampMM); // microg/g or mg/Kg
           ZpolMMHg[i][j]=((kzpolurMM[i][j]*MMHgpw[i][j][1]*pow(10.0,-6.0))+(kzpolinsedMM*Prefsedbotpol*(kMM*THgsed[i][j][1])+kzpolinampMM*PrefZooamppol*ZampMMHg[i][j]+kzpolinpolMM*PrefZoopolpol*ZpolMMHg[i][j]))/(kzpolexrMM+kzpolegrMM+kzpolgr+lambmetpolMM); // microg/g or mg/Kg
           ZmysMMHg[i][j]=((kzmysurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzmysinphyMM*PrefPhymys*PhyMMHg[i][j][k]+kzmysinpolMM*PrefZoopolmys*ZpolMMHg[i][j]+kzmysinampMM*PrefZooampmys*ZampMMHg[i][j]+kzmysinsedMM*Prefsedmys*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzmysexrMM+kzmysegrMM+kzmysgr+lambmetmysMM); // microg/g or mg/Kg
           ZostMMHg[i][j]=((kzosturMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzostinphyMM*PrefPhyost*PhyMMHg[i][j][k]+kzostinbivMM*PrefZoobivost*ZbivMMHg[i][j]+kzostinampMM*PrefZooampost*ZampMMHg[i][j]+kzostinmysMM*PrefZoomysost*ZmysMMHg[i][j]+kzostindecMM*PrefZoodecost*ZdecMMHg[i][j]+kzostinpolMM*PrefZoopolost*ZpolMMHg[i][j]+kzostinostMM*PrefZooostost*ZostMMHg[i][j]+kzostinsedMM*Prefsedost*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzostexrMM+kzostegrMM+kzostgr+lambmetostMM); // microg/g or mg/Kg
           ZdecMMHg[i][j]=((kzdecurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzdecinphyMM*PrefPhydec*PhyMMHg[i][j][k]+kzdecinpolMM*PrefZoopoldec*ZpolMMHg[i][j]+kzdecinbivMM*PrefZoobivdec*ZbivMMHg[i][j]+kzdecinostMM*PrefZooostdec*ZostMMHg[i][j]+kzdecindecMM*PrefZoodecdec*ZdecMMHg[i][j]+kzdecinsedMM*Prefsedbotdec*(kMM*THgsed[i][j][1])))/(kzdecexrMM+kzdecegrMM+kzdecgr+lambmetdecMM); // microg/g or mg/Kg
           
           if(ZbivHgII[i][j]<=0.000000){
				ZbivHgII[i][j]=0.0;
           } 
	   
	       if(ZbivMMHg[i][j]<=0.000000){
				ZbivMMHg[i][j]=0.0;
	       } 

           if(ZpolHgII[i][j]<=0.000000){
				ZpolHgII[i][j]=0.0;
           } 
	   
	       if(ZpolMMHg[i][j]<=0.000000){
				ZpolMMHg[i][j]=0.0;
	       } 

           if(ZampHgII[i][j]<=0.000000){
				ZampHgII[i][j]=0.0;
           } 
	   
	       if(ZampMMHg[i][j]<=0.000000){
				ZampMMHg[i][j]=0.0;
	       }

           if(ZdecHgII[i][j]<=0.000000){
				ZdecHgII[i][j]=0.0;
           } 
	   
	       if(ZdecMMHg[i][j]<=0.000000){
				ZdecMMHg[i][j]=0.0;
	       }
           
           if(ZmysHgII[i][j]<=0.000000){
				ZmysHgII[i][j]=0.0;
           } 
	   
	       if(ZmysMMHg[i][j]<=0.000000){
				ZmysMMHg[i][j]=0.0;
	       }
	       
	       if(ZostHgII[i][j]<=0.000000){
				ZostHgII[i][j]=0.0;
           } 
	   
	       if(ZostMMHg[i][j]<=0.000000){
				ZostMMHg[i][j]=0.0;
	       }
	       
           psfish=0.20*pow(Wfish,0.03); //Kg dry/Kg wet
           
           kfurII[i][j]=pow(Wfish,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kfurMM[i][j]=pow(Wfish,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kfinbivII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinpolII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinampII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfindecII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinmysII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinostII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal);
           kfinsedII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinbivMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinpolMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinampMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfindecMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinmysMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinostMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal);
           kfinsedMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d 
           kfexrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
           kfexrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
           kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
           kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
           kfgr=qT*gamgrow*pow(Wfish,-1.0*kal); //1/d
      
           //FiHgII[i][j]=((kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+((kfinbivII*PrefZoobiv1*ZbivHgII[i][j]+kfinpolII*PrefZoopol1*ZpolHgII[i][j]+kfinampII*PrefZooamp1*ZampHgII[i][j]+kfindecII*PrefZoodec1*ZdecHgII[i][j]+kfinmysII*PrefZoomys1*ZmysHgII[i][j]+kfinostII*PrefZooost1*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1])))/(kfexrII+kfegrII+kfgr+lambmetII); // microg/g or mg/Kg
           //FiMMHg[i][j]=((kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+((kfinbivMM*PrefZoobiv1*ZbivMMHg[i][j]+kfinpolMM*PrefZoopol1*ZpolMMHg[i][j]+kfinampMM*PrefZooamp1*ZampMMHg[i][j]+kfindecMM*PrefZoodec1*ZdecMMHg[i][j]+kfinmysMM*PrefZoomys1*ZmysMMHg[i][j]+kfinostMM*PrefZooost1*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1])))/(kfexrMM+kfegrMM+kfgr+lambmetMM); // microg/g or mg/Kg
           
           FiHgII[i][j]=((kfurII[3][3]*HgII[3][3][k]*pow(10.0,-6.0))+((kfinbivII*PrefZoobiv1*ZbivHgII[3][3]+kfinpolII*PrefZoopol1*ZpolHgII[3][3]+kfinampII*PrefZooamp1*ZampHgII[3][3]+kfindecII*PrefZoodec1*ZdecHgII[3][3]+kfinmysII*PrefZoomys1*ZmysHgII[3][3]+kfinostII*PrefZooost1*ZostHgII[3][3])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[3][3][1])))/(kfexrII+kfegrII+kfgr+lambmetII); // microg/g or mg/Kg
           FiMMHg[i][j]=((kfurMM[3][3]*MMHg[3][3][k]*pow(10.0,-6.0))+((kfinbivMM*PrefZoobiv1*ZbivMMHg[3][3]+kfinpolMM*PrefZoopol1*ZpolMMHg[3][3]+kfinampMM*PrefZooamp1*ZampMMHg[3][3]+kfindecMM*PrefZoodec1*ZdecMMHg[3][3]+kfinmysMM*PrefZoomys1*ZmysMMHg[3][3]+kfinostMM*PrefZooost1*ZostMMHg[3][3])+kfinsedMM*Prefsed1*(kMM*THgsed[3][3][1])))/(kfexrMM+kfegrMM+kfgr+lambmetMM); // microg/g or mg/Kg

           if(FiHgII[i][j]<=0.000000){
				FiHgII[i][j]=0.0;
           } 
	   
	       if(FiMMHg[i][j]<=0.000000){
				FiMMHg[i][j]=0.0;
	       } 
           
        } 

	  }

     } 
  }      
  
  for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
        for(k=1; k<=K; k++){ // rispetto allo spazio z     
        
        if(Rini[i][j][k]>=Rin){
           
           vz[i][j][k]=vz0;
           b1[i][j][k]=B1; // cell/m^3
           forg[i][j][k]=0.52*SPOM[i][j][k]/SPM[i][j][k];
           SPIM[i][j][k]=SPM[i][j][k]-SPOM[i][j][k]; //  Kg/l
           chla1[i][j][k]=b1[i][j][k]*exp((((k-1)*dz)+33.72)/19.57)*pow(10.0,-12.0);  // mg/m^3
           chlatot[i][j][k]= chla1[i][j][k]+chla2;  // mg/m^3
           SIIDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PHgII[i][j][k]; // microg/(m^3*h)
           SMMDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PMMHg[i][j][k]; // microg/(m^3*h)
           SLSPM[i][j][k]=(m1*b1[i][j][k]*Wp1*(1.0-lambda1)); // microg/(m^3*h)
           
		   if(SIIDOM[i][j][k]<=0.000000){
				SIIDOM[i][j][k]=0.0;
			}
		   
		   if(SMMDOM[i][j][k]<=0.000000){
				SMMDOM[i][j][k]=0.0;
			}
		   
		   if(SLSPM[i][j][k]<=0.000000){
				SLSPM[i][j][k]=0.0;
			}
		   
		   if(chla1[i][j][k]<=0.000000){
				chla1[i][j][k]=0.0;
			}
		   
           if(chlatot[i][j][k]<=0.000000){
				chlatot[i][j][k]=0.0;
			}
           
           NPP[i][j][k]=pow(10.0,(2.09+0.81*log10(chlatot[i][j][k])))*(pow(10.0,-3.0)/24.0); // g/m^2*h
           peratio[i][j][k]=-0.0081*Tatm+0.0806*log(chlatot[i][j][k])+0.426; //dimensionless
           OCRR[i][j][k]=(NPP[i][j][k]/(12.011*75.0))*(1.0-peratio[i][j][k]); // mol/m^3 *h
           k3[i][j][k]=k3bio*OCRR[i][j][k]; // h
           k4[i][j][k]=k4bio*OCRR[i][j][k]; //h
           
           if(k==1){
               SIISPM[i][j][k]=NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*(HgII[i][j][k]/dz)+vset*((kDIIsilt*SPIM[i][j][k]*HgII[i][j][k])/dz); //microg/m^3*h
               SMMSPM[i][j][k]=NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*(MMHg[i][j][k]/dz)+vset*((kDMMsilt*SPIM[i][j][k]*MMHg[i][j][k])/dz); //microg/m^3*h
           }
           else{
               SIISPM[i][j][k]=(NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*HgII[i][j][k]-NPP[i][j][k-1]*peratio[i][j][k-1]*(kD0/forg[i][j][k-1])*HgII[i][j][k-1])*(pow(10,-6.0)/dz)+vset*kDIIsilt*((SPIM[i][j][k]*HgII[i][j][k]-SPIM[i][j][k-1]*HgII[i][j][k-1])/dz); //microg/m^3*h
               SMMSPM[i][j][k]=(NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*MMHg[i][j][k]-NPP[i][j][k-1]*peratio[i][j][k-1]*(kD0/forg[i][j][k-1])*MMHg[i][j][k-1])*(pow(10,-6.0)/dz)+vset*kDMMsilt*((SPIM[i][j][k]*MMHg[i][j][k]-SPIM[i][j][k-1]*MMHg[i][j][k-1])/dz); //microg/m^3*h
           }
                     
           if(k==1){
              sommab1[i][j]=chla1[i][j][k];
              sommab2[i][j]=chla2;
              It[i][j][k]=Iin;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           else{
              sommab1[i][j] += chla1[i][j][k];
              sommab2[i][j] += chla2;
              It[i][j][k]=Iin*exp(-(abg*(k-1)+(a2*(2*sommab2[i][j]-2*chla2)/2)+(a1*(2*sommab1[i][j]-chla1[i][j][k]-chla1[i][j][1])/2))*dz);
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           
           if(It[i][j][k]<=0.000000){
				It[i][j][k]=0.0;
			}
           
           F1I[i][j][k]=(r1*It[i][j][k])/(KI1+It[i][j][k]);
           F1R[i][j][k]=(r1*R[i][j][k])/(KR1+R[i][j][k]);
  
           if(F1I[i][j][k]>F1R[i][j][k]){
              G1[i][j][k]=F1R[i][j][k]-m1;
           }
           else{
              G1[i][j][k]=F1I[i][j][k]-m1;
           } 
              
        }	
        else{
        
           forg[i][j][k]=0.0; // in Kg/l
           SPIM[i][j][k]=0.0; // in Kg/l
           b1[i][j][k]=0.0;  // cell/m^3
           chla1[i][j][k]=0.0; // mg/m^3
           chlatot[i][j][k]=0.0; // mg/m^3
           SIIDOM[i][j][k]=0.0; // microg/(m^3*h)
           SMMDOM[i][j][k]=0.0; // microg/(m^3*h)
           SLSPM[i][j][k]=0.0; // microg/(m^3*h)
           vz[i][j][k]=0.0;
           
           if(k==1){
              It[i][j][k]=Iin;
		      k1[i][j][k]=0.0;
	          k2[i][j][k]=0.0;
           }
           else{
              It[i][j][k]=0.0;
		      k1[i][j][k]=0.0;
		      k2[i][j][k]=0.0;
           }
           
           F1I[i][j][k]=0.0;
           F1R[i][j][k]=0.0;
           G1[i][j][k]=0.0;
           
        }
         
        } 
     } 
  }  
  
  
  for(j=1; j<=J; j++){
     for(k=1; k<=K; k++){
     
     b1[I+1][j][k]=B1ext;
     R[I+1][j][k]=Rin;
     Hg0[I+1][j][k]=0.2*DHgexts27;
     HgII[I+1][j][k]=0.794*DHgexts27;
     MMHg[I+1][j][k]=0.006*DHgexts27;
     SPM[I+1][j][k]=SPMexts27;
                 
     } 
  }  
  
  for(i=1; i<=I; i++){
     for(k=1; k<=K; k++){
     
     b1[i][J+1][k]=B1ext;
     R[i][J+1][k]=Rin;
     Hg0[i][J+1][k]=0.2*DHgexts26;
     HgII[i][J+1][k]=0.794*DHgexts26;
     MMHg[i][J+1][k]=0.006*DHgexts26;
     SPM[i][J+1][k]=SPMexts26;
                 
     } 
  } 
  
  
for(i=1; i<=I; i++){
  for(j=1; j<=J; j++){
           
    if(Rini[i][j][1]>=Rin){
                                             
     MTCwaw[i][j]=(0.108*pow(uwind,1.64)*pow((PMCO2/PMHg0),0.25))/(24.0); // m/h 
     MTCwag[i][j]=(864.0*(0.2*uwind+0.3)*pow((PMH2O/PMHg0),0.3))/(24.0); // m/h 
     MTCwa[i][j]=(MTCwaw[i][j]*MTCwag[i][j])/(MTCwaw[i][j]+H1*MTCwag[i][j]); // m/h 
     MTCIIsw[i][j]=(Dwin*pow(porsed[i][j][1],(4.0/3.0)))/(delsed+delw*pow(porsed[i][j][1],(4.0/3.0))); // m/h
     MTCMMsw[i][j]=(Dwor*pow(porsed[i][j][1],(4.0/3.0)))/(delsedMM+delw*pow(porsed[i][j][1],(4.0/3.0))); // m/h
     
     }
     else{
     
     MTCwaw[i][j]=0.0; // m/h 
     MTCwag[i][j]=0.0; // m/h 
     MTCwa[i][j]=0.0;  // m/h 
     MTCIIsw[i][j]=0.0; // m/h
     MTCMMsw[i][j]=0.0; // m/h
     
    }
    
    for(r=1; r<=RL; r++){
     
     if(Rini[i][j][1]>=Rin){
                                             
     Dinsed[i][j][r]=(Dwin*porsed[i][j][r])/(1.0-log(pow(porsed[i][j][r],2.0))); // m^2/h
     Dorsed[i][j][r]=(Dwor*porsed[i][j][r])/(1.0-log(pow(porsed[i][j][r],2.0))); // m^2/h
     HgIIpw[i][j][r]=(1.0-kMM)*(THgsed[i][j][r]/kDIIsed)*pow(10.0,6.0); // microg/m^3
     MMHgpw[i][j][r]=kMM*(THgsed[i][j][r]/kDMMsed)*pow(10.0,6.0); // microg/m^3
    
     }
     else{
     
     Dinsed[i][j][r]=0.0; // m^2/h
     Dorsed[i][j][r]=0.0; // m^2/h
     HgIIpw[i][j][r]=0.0; // microg/m^3
     MMHgpw[i][j][r]=0.0; // microg/m^3
     
     }
     
     THgsedold[i][j][r]=THgsed[i][j][r]; // mg/Kg

   } 
  } 
 }
  
    for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
        
				fprintf(ftotdep,"%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, Totdep[i][j]);
				fprintf(fZbiv,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZbivHgII[i][j], ZbivMMHg[i][j]);
				fprintf(fZpol,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZpolHgII[i][j], ZpolMMHg[i][j]);
				fprintf(fZamp,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZampHgII[i][j], ZampMMHg[i][j]);
				fprintf(fZdec,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZdecHgII[i][j], ZdecMMHg[i][j]);
				fprintf(fZmys,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZmysHgII[i][j], ZmysMMHg[i][j]);
				fprintf(fZost,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, ZostHgII[i][j], ZostMMHg[i][j]);
				fprintf(fFi,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, FiHgII[i][j], FiMMHg[i][j]);

            for(r=1; r<=RL; r++){
                     
                fprintf(fHgIIpw,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, HgIIpw[i][j][r]);
                fprintf(fMMHgpw,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, MMHgpw[i][j][r]); 
                fprintf(fTHgsed,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, THgsed[i][j][r]);
                
            } 
            
            
            for(k=1; k<=K; k++){
            
				fprintf(fb1,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, b1[i][j][k]);
				fprintf(fct,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, chlatot[i][j][k]);
				fprintf(fR,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, R[i][j][k]);
				fprintf(fI,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, It[i][j][k]);
				fprintf(fHg0,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, Hg0[i][j][k]);
				fprintf(fHgII,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, HgII[i][j][k]);
				fprintf(fMMHg,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, MMHg[i][j][k]);
				fprintf(fDHg,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, DHg[i][j][k]);
				fprintf(fTHg,"%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, THg[i][j][k]);
				fprintf(fP,"%f\t%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, PHgII[i][j][k], PMMHg[i][j][k]);
				fprintf(fPhy,"%f\t%f\t%f\t%f\t%f\t%f\n", 0.0, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, PhyHgII[i][j][k], PhyMMHg[i][j][k]);

				
            }    
        }
    }
  
   PhyHgIIsptmean=0.0;
   PhyMMHgsptmean=0.0;
   ZbivHgIIsptmean=0.0;
   ZbivMMHgsptmean=0.0;
   ZpolHgIIsptmean=0.0;
   ZpolMMHgsptmean=0.0;
   ZampHgIIsptmean=0.0;
   ZampMMHgsptmean=0.0;
   ZdecHgIIsptmean=0.0;
   ZdecMMHgsptmean=0.0;
   ZmysHgIIsptmean=0.0;
   ZmysMMHgsptmean=0.0;
   ZostHgIIsptmean=0.0;
   ZostMMHgsptmean=0.0;
   FiHgIIsptmean=0.0;
   FiMMHgsptmean=0.0;
   PhyHgIIsptmean2=0.0;
   PhyMMHgsptmean2=0.0;
   ZbivHgIIsptmean2=0.0;
   ZbivMMHgsptmean2=0.0;
   ZpolHgIIsptmean2=0.0;
   ZpolMMHgsptmean2=0.0;
   ZampHgIIsptmean2=0.0;
   ZampMMHgsptmean2=0.0;
   ZdecHgIIsptmean2=0.0;
   ZdecMMHgsptmean2=0.0;
   ZmysHgIIsptmean2=0.0;
   ZmysMMHgsptmean2=0.0;
   ZostHgIIsptmean2=0.0;
   ZostMMHgsptmean2=0.0;
   FiHgIIsptmean2=0.0;
   FiMMHgsptmean2=0.0;


for(n=1; n<=N; n++){ // rispetto all'anno n

    for(p=1; p<=P; p++){
           fscanf(fv5,"%lf\t%lf\n", &value1[p][1],&value1[p][2]); 
           fscanf(fv10,"%lf\t%lf\n", &value2[p][1],&value2[p][2]);
           fscanf(fv20,"%lf\t%lf\n", &value3[p][1],&value3[p][2]);
           fscanf(fv30,"%lf\t%lf\n", &value5[p][1],&value5[p][2]);
           fscanf(fero,"%lf\n", &ero[p][1]);    
    } 
    
    for(p=1; p<=180; p++){
    fscanf(fero2,"%lf\n", &ero2[p][1]);
    }
  
  for(p=1; p<=180; p++){                   
      for(j=1; j<=J; j++){ // rispetto allo spazio y 
         for(i=1; i<=I; i++){ // rispetto allo spazio x                
             if(p==i+I*(j-1)){  

                vxc[i][j][1]=3600.0*value1[p][1];
                vyc[i][j][1]=-3600.0*value1[p][2];
                vxc[i][j][2]=3600.0*value2[p][1];
                vyc[i][j][2]=-3600.0*value2[p][2];
                vxc[i][j][3]=3600.0*value3[p][1];
                vyc[i][j][3]=-3600.0*value3[p][2];
                vxc[i][j][4]=3600.0*value3[p][1];
                vyc[i][j][4]=-3600.0*value3[p][2];
                vxc[i][j][5]=3600.0*value5[p][1];
                vyc[i][j][5]=-3600.0*value5[p][2];
                vxc[i][j][6]=3600.0*value5[p][1];
                vyc[i][j][6]=-3600.0*value5[p][2];
                dep[i][j]=depmed;
                //dep[i][j]=ero[p][1];
                Totdepold[i][j]=ero2[p][1];
             }
         }       
      }               
  }
    
  for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
        for(k=1; k<=K; k++){ // rispetto allo spazio z     

        vx[i][j][k]=0.5*(vxc[i-1][j][k]+vxc[i][j][k]);
        vy[i][j][k]=0.5*(vyc[i][j-1][k]+vyc[i][j][k]);
        vxold[i][j][k]=vx[i][j][k];
        vyold[i][j][k]=vy[i][j][k];

        }
         
        depold[i][j]=dep[i][j];   
        Totdep[i][j]=(n-1)*Totdepold[i][j];  
         
     }               
  }

    TotSIISPM = 0.0; // kmol
    TotSMMSPM = 0.0; // kmol  
    TotSIIDOM = 0.0; // kmol
    TotSMMDOM = 0.0; // kmol
    
    for(i=1; i<=I; i++){ // rispetto allo spazio x
        for(j=1; j<=J; j++){ // rispetto allo spazio y 
            for(k=1; k<=K; k++){ // rispetto allo spazio z     
        
            if(Rini[i][j][k]>=Rin){
            TotSIISPM += SIISPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
            TotSMMSPM += SMMSPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol 
            TotSIIDOM += SIIDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
            TotSMMDOM += SMMDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol
            }
            
            }       
        }               
    }

   TotfluHg0xlev=0.0; 
   TotfluHgIIxlev=0.0; 
   TotfluMMHgxlev=0.0; 
   Totlev=0.0; 
   
   TotfluHg0xysci=0.0; 
   TotfluHgIIxysci=0.0; 
   TotfluMMHgxysci=0.0; 
   Totsci=0.0; 
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluxHgIIsed[i][j] = MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*24.0; // microg/m^2*d
               fluxMMHgsed[i][j] = MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*24.0; // microg/m^2*d    
           } 
             
           }
       }
   }
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][1]>=Rin){
               fluxHg0atm[i][j] = -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10,3.0); // ng/m^2*h
               fluxHg0dep[i][j] = Hggas*(Pr/det); // ng/m^2*h
               fluxHgIIdep[i][j] = HgIIatm*(Pr/det)+DrydepHgII*pow(10,3.0); // ng/m^2*h  
               fluxMMHgdep[i][j] = 0.005025*(HgIIatm*(Pr/det)+DrydepHgII*pow(10,3.0)); //MMHgatm*(Pr/det); // ng/m^2*h 
           }
           else{
               fluxHg0atm[i][j] = 0.0; // ng/m^2*h
               fluxHg0dep[i][j] = 0.0; // ng/m^2*h
               fluxHgIIdep[i][j] = 0.0; // ng/m^2*h  
               fluxMMHgdep[i][j] = 0.0; // ng/m^2*h
           }
            
           }
       }
   }
 
 if(n==1){ 
    for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
                 
        fprintf(fHgIIfluxsed,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHgIIsed[i][j]);
        fprintf(fMMHgfluxsed,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxMMHgsed[i][j]); 
        fprintf(fHg0fluxatm,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHg0atm[i][j]);
        fprintf(fHg0fluxdep,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHg0dep[i][j]);
        fprintf(fHgIIfluxdep,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxHgIIdep[i][j]);
        fprintf(fMMHgfluxdep,"%f\t%f\t%f\t%f\n", M*(n-1)*dt, (i-1)*dx, (j-1)*dy, fluxMMHgdep[i][j]);
                  
        }
    }
 } 
    
    
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queste variabili dipendono dalla forma del bacino%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    
    fluHgIIzsed=0.0;
    fluMMHgzsed=0.0;
    fluHgIIzbur=0.0;
    fluMMHgzbur=0.0;
    fluHgIIzbur2=0.0;
    fluMMHgzbur2=0.0;
    fluHgIIzsedext1=0.0;
    fluMMHgzsedext1=0.0;
    fluHgIIzburext1=0.0;
    fluMMHgzburext1=0.0;
    fluHgIIzburext12=0.0;
    fluMMHgzburext12=0.0;
    fluHgIIzsedext2=0.0;
    fluMMHgzsedext2=0.0;
    fluHgIIzburext2=0.0;
    fluMMHgzburext2=0.0;
    fluHgIIzburext22=0.0;
    fluMMHgzburext22=0.0;
    fluHgIIzsedext3=0.0;
    fluMMHgzsedext3=0.0;
    fluHgIIzburext3=0.0;
    fluMMHgzburext3=0.0;
    fluHgIIzburext32=0.0;
    fluMMHgzburext32=0.0;
    fluxHg0zatm=0.0;
    fluxHg0zdep=0.0;
    fluxHgIIzdep=0.0;
    fluxMMHgzdep=0.0;
    fluxHg0zatmext1=0.0;
    fluxHg0zdepext1=0.0;
    fluxHgIIzdepext1=0.0;
    fluxMMHgzdepext1=0.0;
    fluxHg0zatmext2=0.0;
    fluxHg0zdepext2=0.0;
    fluxHgIIzdepext2=0.0;
    fluxMMHgzdepext2=0.0;
    fluxHg0zatmext3=0.0;
    fluxHg0zdepext3=0.0;
    fluxHgIIzdepext3=0.0;
    fluxMMHgzdepext3=0.0;
   
   TotfluHgIIzsed = 0.0; 
   TotfluMMHgzsed = 0.0; 
   TotfluHgIIzbur = 0.0; 
   TotfluMMHgzbur = 0.0; 
   TotfluHgIIzbur2 = 0.0; 
   TotfluMMHgzbur2 = 0.0;
   TotfluHgIIzsedext1 = 0.0; 
   TotfluMMHgzsedext1 = 0.0; 
   TotfluHgIIzburext1 = 0.0; 
   TotfluMMHgzburext1 = 0.0; 
   TotfluHgIIzburext12 = 0.0; 
   TotfluMMHgzburext12 = 0.0;
   TotfluHgIIzsedext2 = 0.0; 
   TotfluMMHgzsedext2 = 0.0; 
   TotfluHgIIzburext2 = 0.0; 
   TotfluMMHgzburext2 = 0.0;
   TotfluHgIIzburext22 = 0.0; 
   TotfluMMHgzburext22 = 0.0;
   TotfluHgIIzsedext3 = 0.0; 
   TotfluMMHgzsedext3 = 0.0; 
   TotfluHgIIzburext3 = 0.0; 
   TotfluMMHgzburext3 = 0.0; 
   TotfluHgIIzburext32 = 0.0; 
   TotfluMMHgzburext32 = 0.0;
   
   TotfluHg0zatm = 0.0; 
   TotfluHg0zdep = 0.0; 
   TotfluHgIIzdep = 0.0; 
   TotfluMMHgzdep = 0.0; 
   TotfluHg0zatmext1 = 0.0; 
   TotfluHg0zdepext1 = 0.0; 
   TotfluHgIIzdepext1 = 0.0; 
   TotfluMMHgzdepext1 = 0.0; 
   TotfluHg0zatmext2 = 0.0; 
   TotfluHg0zdepext2 = 0.0; 
   TotfluHgIIzdepext2 = 0.0; 
   TotfluMMHgzdepext2 = 0.0; 
   TotfluHg0zatmext3 = 0.0; 
   TotfluHg0zdepext3 = 0.0; 
   TotfluHgIIzdepext3 = 0.0; 
   TotfluMMHgzdepext3 = 0.0; 
   
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    

  for(q=1; q<=Q; q++){
		   fscanf(fIin,"%lf\t%lf\n", &Iinin[q][1],&Iinin[q][2]); 
		   fscanf(fTatm,"%lf\t%lf\n", &Tatmin[q][1],&Tatmin[q][2]); 
		   fscanf(fPrec,"%lf\t%lf\n", &Prin[q][1],&Prin[q][2]); 
		   fscanf(fHgIIatm,"%lf\t%lf\n", &HgIIatmin[q][1],&HgIIatmin[q][2]);
		   fscanf(fHggas,"%lf\t%lf\n", &Hggasin[q][1],&Hggasin[q][2]);
  }

    
 for(m=1; m<=M; m++){ // rispetto al tempo t

     if(m%idt==0){  
                               
       for(p=181*(m/idt)+1; p<=181*(m/idt+1)-1; p++){                 
          for(j=1; j<=J; j++){ // rispetto allo spazio y 
             for(i=1; i<=I; i++){ // rispetto allo spazio x                
                if(p==181*(m/idt)+i+I*(j-1)){

                vxc[i][j][1]=3600.0*value1[p][1];
                vyc[i][j][1]=-3600.0*value1[p][2];
                vxc[i][j][2]=3600.0*value2[p][1];
                vyc[i][j][2]=-3600.0*value2[p][2];
                vxc[i][j][3]=3600.0*value3[p][1];
                vyc[i][j][3]=-3600.0*value3[p][2];
                vxc[i][j][4]=3600.0*value3[p][1];
                vyc[i][j][4]=-3600.0*value3[p][2];
                vxc[i][j][5]=3600.0*value5[p][1];
                vyc[i][j][5]=-3600.0*value5[p][2];
                vxc[i][j][6]=3600.0*value5[p][1];
                vyc[i][j][6]=-3600.0*value5[p][2];
                dep[i][j]=depmed; //m/h
                //dep[i][j]=(ero[p][1]-ero[p-181][1])/3.0; //m/h
 
                     
                }    
             }       
          }              
       }     
       
       for(i=1; i<=I; i++){ // rispetto allo spazio x
           for(j=1; j<=J; j++){ // rispetto allo spazio y 
               for(k=1; k<=K; k++){ // rispetto allo spazio z     

               vx[i][j][k]=0.5*(vxc[i-1][j][k]+vxc[i][j][k]);
               vy[i][j][k]=0.5*(vyc[i][j-1][k]+vyc[i][j][k]);

               } 
                 
           }               
       }
       
                     
       }
       else{
            
           for(i=1; i<=I; i++){ // rispetto allo spazio x
              for(j=1; j<=J; j++){ // rispetto allo spazio y 
                  for(k=1; k<=K; k++){ // rispetto allo spazio
               
                  vx[i][j][k]=vxold[i][j][k];
                  vy[i][j][k]=vyold[i][j][k];

                  }

                  dep[i][j]=depold[i][j];
                  
                
              }
           }  
                       
       }
             
                
       for(i=1; i<=I; i++){ // rispetto allo spazio x
           for(j=1; j<=J; j++){ // rispetto allo spazio y 
               for(k=1; k<=K; k++){ // rispetto allo spazio
       
               vxold[i][j][k]=vx[i][j][k];
               vyold[i][j][k]=vy[i][j][k];
       
               }

               depold[i][j]=dep[i][j];
               Totdep[i][j]+= dep[i][j]*dt;
               
               
           }
       } 
        
      for(q=1; q<=Q; q++){
                        
			if((m/(idtb*((int) Iinin[q][1])))==1){
				Iin=Iinin[q][2];
			}
            
            if((m/(idtb*((int) Tatmin[q][1])))==1){
				Tatm=Tatmin[q][2];
			}	
   
            if((m/(idtb*((int) Prin[q][1])))==1){
				Pr=Prin[q][2];
			}

		if((m/(idtb*((int) HgIIatmin[q][1])))==1){
				HgIIatm=HgIIatmin[q][2];
			}

			
			if((m/(idtb*((int) Hggasin[q][1])))==1){
				Hggas=Hggasin[q][2];
			}
   
      }
     
   for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
       for(k=1; k<=K; k++){ // rispetto allo spazio z
     
        if(Rini[i][j][k]>=Rin){
           
           if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]>=Rin){
                                     
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
        
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
           
           }
           else if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]<Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           } 
           else if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]<Rin && Rini[i][j][k-1]>=Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
			
           }
           else if(Rini[i-1][j][k]<Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]>=Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
			
           } 
           else if(Rini[i-1][j][k]<Rin && Rini[i][j-1][k]<Rin && Rini[i][j][k-1]>=Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*((flub1z[i][j][k]+1.0*Dzz*((b1[i][j][k]-b1[i][j][k-1])/dz))/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*((fluHg0z[i][j][k]+1.0*Dzz*((Hg0[i][j][k]-Hg0[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*((fluHgIIz[i][j][k]+1.0*Dzz*((HgII[i][j][k]-HgII[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*((fluMMHgz[i][j][k]+1.0*Dzz*((MMHg[i][j][k]-MMHg[i][j][k-1])/dz))/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*((fluRz[i][j][k]+1.0*Dzz*((R[i][j][k]-R[i][j][k-1])/dz))/dz);
           } 
			
           } 
           else if(Rini[i-1][j][k]<Rin && Rini[i][j-1][k]>=Rin && Rini[i][j][k-1]<Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*((flub1y[i][j][k]+1.0*Dyy*((b1[i][j][k]-b1[i][j-1][k])/dy))/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*((fluHg0y[i][j][k]+1.0*Dyy*((Hg0[i][j][k]-Hg0[i][j-1][k])/dy))/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*((fluHgIIy[i][j][k]+1.0*Dyy*((HgII[i][j][k]-HgII[i][j-1][k])/dy))/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*((fluMMHgy[i][j][k]+1.0*Dyy*((MMHg[i][j][k]-MMHg[i][j-1][k])/dy))/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*((fluRy[i][j][k]+1.0*Dyy*((R[i][j][k]-R[i][j-1][k])/dy))/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           }  
           else if(Rini[i-1][j][k]>=Rin && Rini[i][j-1][k]<Rin && Rini[i][j][k-1]<Rin){
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*((flub1x[i][j][k]+1.0*Dxx*((b1[i][j][k]-b1[i-1][j][k])/dx))/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*((fluHg0x[i][j][k]+1.0*Dxx*((Hg0[i][j][k]-Hg0[i-1][j][k])/dx))/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluHgIIx[i][j][k]+1.0*Dxx*((HgII[i][j][k]-HgII[i-1][j][k])/dx))/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*((fluMMHgx[i][j][k]+1.0*Dxx*((MMHg[i][j][k]-MMHg[i-1][j][k])/dx))/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*((fluRx[i][j][k]+1.0*Dxx*((R[i][j][k]-R[i-1][j][k])/dx))/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           }
           else{
           
           b1[i][j][k]+= G1[i][j][k]*b1[i][j][k]*dt-1.0*dt*(flub1x[i][j][k]/dx)-1.0*dt*(flub1y[i][j][k]/dy)-1.0*dt*(flub1z[i][j][k]/dz); // cell/m^3
           Hg0[i][j][k]+= (k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-1.0*(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt+kPhde*MMHg[i][j][k]*dt-1.0*dt*(fluHg0x[i][j][k]/dx)-1.0*dt*(fluHg0y[i][j][k]/dy)-1.0*dt*(fluHg0z[i][j][k]/dz); // ng/l or microg/m^3
           HgII[i][j][k]+= (SLII+SIIDOM[i][j][k]-SIISPM[i][j][k])*dt+(k1[i][j][k]+k3[i][j][k])*Hg0[i][j][k]*dt-1.0*(k2[i][j][k]+k4[i][j][k])*HgII[i][j][k]*dt-kmeth*HgII[i][j][k]*dt+kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluHgIIx[i][j][k]/dx)-1.0*dt*(fluHgIIy[i][j][k]/dy)-1.0*dt*(fluHgIIz[i][j][k]/dz); // ng/l or microg/m^3
           MMHg[i][j][k]+= (SLMM+SMMDOM[i][j][k]-SMMSPM[i][j][k])*dt-1.0*kPhde*MMHg[i][j][k]*dt+kmeth*HgII[i][j][k]*dt-kdemeth*MMHg[i][j][k]*dt-1.0*dt*(fluMMHgx[i][j][k]/dx)-1.0*dt*(fluMMHgy[i][j][k]/dy)-1.0*dt*(fluMMHgz[i][j][k]/dz); // ng/l or microg/m^3
           
           if(Rini[i][j][k]==Rbot){
				R[i][j][k]=Rbot;
           }
           else{
				R[i][j][k]+= (dt/Y1)*epsilon1*(m1*b1[i][j][k])-1.0*(dt/Y1)*((G1[i][j][k]+m1)*b1[i][j][k])-1.0*dt*(fluRx[i][j][k]/dx)-1.0*dt*(fluRy[i][j][k]/dy)-1.0*dt*(fluRz[i][j][k]/dz);
           } 
			
           }
           
           
           if(b1[i][j][k]<=0.000000){
				b1[i][j][k]=0.0;
           }
  
           if(R[i][j][k]<=0.000000){
				R[i][j][k]=0.0;
           }
			
		   if(Hg0[i][j][k]<=0.000000){
				Hg0[i][j][k]=0.0;
		   }
			
		   if(HgII[i][j][k]<=0.000000){
				HgII[i][j][k]=0.0;
           }
			
		   if(MMHg[i][j][k]<=0.000000){
				MMHg[i][j][k]=0.0;
	       }
		  
        }	
        else{
         
           b1[i][j][k]=0.0; // cell/m^3
           R[i][j][k]=0.0;
           Hg0[i][j][k]=0.0; // ng/l or microg/m^3
           HgII[i][j][k]=0.0; // ng/l or microg/m^3
           MMHg[i][j][k]=0.0; // ng/l or microg/m^3
                    
        }  
                 
        } 
     } 
  }        
                  
   for(i=1; i<=I; i++){ // rispetto allo spazio x
     for(j=1; j<=J; j++){ // rispetto allo spazio y 
       for(k=1; k<=K; k++){ // rispetto allo spazio z
     
        if(Rini[i][j][k]>=Rin){
           
           DHg[i][j][k]=Hg0[i][j][k]+HgII[i][j][k]+MMHg[i][j][k];
           kphupII[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((HgII[i][j][k]*pow(10.0,-3.0)),kpII)+(1.0/gamwat)); // l/(Kg*d)
           kphupMM[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((MMHg[i][j][k]*pow(10.0,-3.0)),kpMM)+(1.0/gamwat)); // l/(Kg*d)
           PHgII[i][j][k]+=(Wp1*kphupII[i][j][k]*HgII[i][j][k]*pow(10.0,-12.0))*(dt/24.0)-(kphexII+kphgr)*PHgII[i][j][k]*(dt/24.0); //  microg
           PMMHg[i][j][k]+=(Wp1*kphupMM[i][j][k]*MMHg[i][j][k]*pow(10.0,-12.0))*(dt/24.0)-(kphexMM+kphgr)*PMMHg[i][j][k]*(dt/24.0); //  microg
           PHg[i][j][k]=PHgII[i][j][k]+PMMHg[i][j][k]; //  microg
           THg[i][j][k]=Hg0[i][j][k]+HgII[i][j][k]*(1.0+kDSPM0*SPM[i][j][k])+MMHg[i][j][k]*(1.0+kDSPM0*SPM[i][j][k]);
           SIIDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PHgII[i][j][k]; // microg/(m^3*h)
           SMMDOM[i][j][k]=lambda1*m1*b1[i][j][k]*PMMHg[i][j][k]; // microg/(m^3*h)
           SLSPM[i][j][k]=(m1*b1[i][j][k]*(1.0-lambda1)*Wp1); // microg/(m^3*h)
           chla1[i][j][k]=b1[i][j][k]*exp((((k-1)*dz)+33.72)/19.57)*pow(10.0,-12.0);  // mg/m^3
           chlatot[i][j][k]=chla1[i][j][k]+chla2;  // mg/m^3
           
           TotSIIDOM += SIIDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
           TotSMMDOM += SMMDOM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol
           
           if(DHg[i][j][k]<=0.000000){
				DHg[i][j][k]=0.0;
			}
           
           if(kphupII[i][j][k]<=0.000000){
				kphupII[i][j][k]=0.0;
			}
		   
		   if(kphupMM[i][j][k]<=0.000000){
				kphupMM[i][j][k]=0.0;
			}
		   
		   if(PHgII[i][j][k]<=0.000000){
				PHgII[i][j][k]=0.0;
			}
		   
		   if(PMMHg[i][j][k]<=0.000000){
				PMMHg[i][j][k]=0.0;
			}
			
           if(PHg[i][j][k]<=0.000000){
				PHg[i][j][k]=0.0;
			}
			
		   if(THg[i][j][k]<=0.000000){
				THg[i][j][k]=0.0;
			}
		   
		   if(SIIDOM[i][j][k]<=0.000000){
				SIIDOM[i][j][k]=0.0;
			}
		   
		   if(SMMDOM[i][j][k]<=0.000000){
				SMMDOM[i][j][k]=0.0;
			}
		   
		   if(SLSPM[i][j][k]<=0.000000){
				SLSPM[i][j][k]=0.0;
			}
		   
		   if(chla1[i][j][k]<=0.000000){
				chla1[i][j][k]=0.0;
			}
		   
           if(chlatot[i][j][k]<=0.000000){
				chlatot[i][j][k]=0.0;
			}
           
           SPIM[i][j][k]=SPM[i][j][k]-SPOM[i][j][k]; //  Kg/l
           vz[i][j][k]=vz0; // m/h
           
           NPP[i][j][k]=pow(10.0,(2.09+0.81*log10(chlatot[i][j][k])))*(pow(10.0,-3.0)/24.0); // g/m^2*h
           peratio[i][j][k]=-0.0081*Tatm+0.0806*log(chlatot[i][j][k])+0.426; //dimensionless
           OCRR[i][j][k]=(NPP[i][j][k]/(12.011*75.0))*(1.0-peratio[i][j][k]); // mol/m^3 *h
           k3[i][j][k]=k3bio*OCRR[i][j][k]; // h
           k4[i][j][k]=k4bio*OCRR[i][j][k]; //h
            
           if(k==1){
               SIISPM[i][j][k]=NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*(HgII[i][j][k]/dz)+vset*kDIIsilt*((SPIM[i][j][k]*HgII[i][j][k])/dz); //microg/m^3*h
               SMMSPM[i][j][k]=NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*(MMHg[i][j][k]/dz)+vset*kDMMsilt*((SPIM[i][j][k]*MMHg[i][j][k])/dz); //microg/m^3*h
           }
           else{
               SIISPM[i][j][k]=(NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*HgII[i][j][k]-NPP[i][j][k-1]*peratio[i][j][k-1]*(kD0/forg[i][j][k-1])*HgII[i][j][k-1])*(pow(10,-6.0)/dz)+vset*kDIIsilt*((SPIM[i][j][k]*HgII[i][j][k]-SPIM[i][j][k-1]*HgII[i][j][k-1])/dz); //microg/m^3*h
               SMMSPM[i][j][k]=(NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*MMHg[i][j][k]-NPP[i][j][k-1]*peratio[i][j][k-1]*(kD0/forg[i][j][k-1])*MMHg[i][j][k-1])*(pow(10,-6.0)/dz)+vset*kDMMsilt*((SPIM[i][j][k]*MMHg[i][j][k]-SPIM[i][j][k-1]*MMHg[i][j][k-1])/dz); //microg/m^3*h
           }
           
           TotSIISPM += SIISPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMHgII); // kmol
           TotSMMSPM += SMMSPM[i][j][k]*dx*dy*dz*dt*pow(10,-9.0)*(1.0/PMMMHg); // kmol
           
           if(k==1){
              sommab1[i][j]=chla1[i][j][k];
              sommab2[i][j]=chla2;
              It[i][j][k]=Iin;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           else{
              sommab1[i][j] += chla1[i][j][k];
              sommab2[i][j] += chla2;
              It[i][j][k]=Iin*exp(-(abg*(k-1)+(a2*(2*sommab2[i][j]-2*chla2)/2.0)+(a1*(2*sommab1[i][j]-chla1[i][j][k]-chla1[i][j][1])/2.0))*dz);
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           
           if(It[i][j][k]<=0.000000){
				It[i][j][k]=0.0;
			}
            
           F1I[i][j][k]=(r1*It[i][j][k])/(KI1+It[i][j][k]);
           F1R[i][j][k]=(r1*R[i][j][k])/(KR1+R[i][j][k]);
  
           if(F1I[i][j][k]>F1R[i][j][k]){
              G1[i][j][k]=F1R[i][j][k]-m1;
           }
           else{
              G1[i][j][k]=F1I[i][j][k]-m1;
           }   
                        
        }	
        else{
         
           vz[i][j][k]=0.0;
           DHg[i][j][k]=0.0;
           kphupII[i][j][k]=0.0;
           kphupMM[i][j][k]=0.0;
           PHgII[i][j][k]=0.0; //  microg
           PMMHg[i][j][k]=0.0; //  microg
           PHg[i][j][k]=0.0; 
           THg[i][j][k]=0.0;
           SPIM[i][j][k]=0.0; // in Kg/l
           chla1[i][j][k]=0.0; // mg/m^3
           chlatot[i][j][k]=0.0; // mg/m^3
           SIIDOM[i][j][k]=0.0; // microg/(m^3*h)
           SMMDOM[i][j][k]=0.0; // microg/(m^3*h)
           SLSPM[i][j][k]=0.0; // microg/(m^3*h)
           SIISPM[i][j][k]=0.0;
           SMMSPM[i][j][k]=0.0;
           
           if(k==1){
              It[i][j][k]=Iin;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           else{
              It[i][j][k]=0.0;
		      k1[i][j][k]=k1phox*It[i][j][k]*776.467;
		      k2[i][j][k]=k2phre*It[i][j][k]*776.467;
           }
           
           F1I[i][j][k]=0.0;
           F1R[i][j][k]=0.0;
           G1[i][j][k]=0.0;
           
        }
           
        } 
     } 
  }  
  
  for(i=1; i<=I; i++){
     for(j=1; j<=J; j++){
     
     if(Rini[i][j][1]>=Rin){
     
     if(THgsedold[i][j][1]>0.000000){
         HgIIpw[i][j][1]+= Kdeme*MMHgpw[i][j][1]*dt-Kme*HgIIpw[i][j][1]*dt+(Dinsed[i][j][1]*(((HgIIpw[i][j][2]-HgIIpw[i][j][1])/dz2)-((HgIIpw[i][j][1]-HgIIpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][1]*(HgIIpw[i+1][j][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dinsed[i][j][1]*(HgIIpw[i][j+1][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dinsed[i][j][2]-Dinsed[i][j][1])*(HgIIpw[i][j][2]-HgIIpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][1]-Dinsed[i][j][1])*(HgIIpw[i+1][j][1]-HgIIpw[i][j][1]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][1]-Dinsed[i][j][1])*(HgIIpw[i][j+1][1]-HgIIpw[i][j][1]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][1]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3                      
         MMHgpw[i][j][1]+= Kme*HgIIpw[i][j][1]*dt-Kdeme*MMHgpw[i][j][1]*dt+(Dorsed[i][j][1]*(((MMHgpw[i][j][2]-MMHgpw[i][j][1])/dz2)-((MMHgpw[i][j][1]-MMHgpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][1]*(MMHgpw[i+1][j][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dorsed[i][j][1]*(MMHgpw[i][j+1][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dorsed[i][j][2]-Dorsed[i][j][1])*(MMHgpw[i][j][2]-MMHgpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][1]-Dorsed[i][j][1])*(MMHgpw[i+1][j][1]-MMHgpw[i][j][1]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][1]-Dorsed[i][j][1])*(MMHgpw[i][j+1][1]-MMHgpw[i][j][1]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][1]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][1]+= -1.0*alfa*THgsed[i][j][1]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][1]+= Kdeme*MMHgpw[i][j][1]*dt-Kme*HgIIpw[i][j][1]*dt+(Dinsed[i][j][1]*(((HgIIpw[i][j][2]-HgIIpw[i][j][1])/dz2)-((HgIIpw[i][j][1]-HgIIpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dinsed[i][j][1]*(HgIIpw[i+1][j][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dinsed[i][j][1]*(HgIIpw[i][j+1][1]-2.0*HgIIpw[i][j][1]+HgIIpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dinsed[i][j][2]-Dinsed[i][j][1])*(HgIIpw[i][j][2]-HgIIpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][1]-Dinsed[i][j][1])*(HgIIpw[i+1][j][1]-HgIIpw[i][j][1]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][1]-Dinsed[i][j][1])*(HgIIpw[i][j+1][1]-HgIIpw[i][j][1]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][1]+= Kme*HgIIpw[i][j][1]*dt-Kdeme*MMHgpw[i][j][1]*dt+(Dorsed[i][j][1]*(((MMHgpw[i][j][2]-MMHgpw[i][j][1])/dz2)-((MMHgpw[i][j][1]-MMHgpw[i][j][1])/(dz1+Totdep[i][j])))*(dt/dz2))+(Dorsed[i][j][1]*(MMHgpw[i+1][j][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i-1][j][1]))*(dt/pow(dx,2.0))+(Dorsed[i][j][1]*(MMHgpw[i][j+1][1]-2.0*MMHgpw[i][j][1]+MMHgpw[i][j-1][1]))*(dt/pow(dy,2.0))+((Dorsed[i][j][2]-Dorsed[i][j][1])*(MMHgpw[i][j][2]-MMHgpw[i][j][1]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][1]-Dorsed[i][j][1])*(MMHgpw[i+1][j][1]-MMHgpw[i][j][1]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][1]-Dorsed[i][j][1])*(MMHgpw[i][j+1][1]-MMHgpw[i][j][1]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][1]+= 0.0; // mg/Kg
     }

     
     for(r=2; r<=RL-1; r++){
              
     if(THgsedold[i][j][r]>0.000000){
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][r]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][r]+= -1.0*alfa*THgsed[i][j][r]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][r]+= Kdeme*MMHgpw[i][j][r]*dt-Kme*HgIIpw[i][j][r]*dt+(Dinsed[i][j][r]*(HgIIpw[i][j][r+1]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dinsed[i][j][r]*(HgIIpw[i+1][j][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dinsed[i][j][r]*(HgIIpw[i][j+1][r]-2.0*HgIIpw[i][j][r]+HgIIpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dinsed[i][j][r+1]-Dinsed[i][j][r])*(HgIIpw[i][j][r+1]-HgIIpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dinsed[i+1][j][r]-Dinsed[i][j][r])*(HgIIpw[i+1][j][r]-HgIIpw[i][j][r]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][r]-Dinsed[i][j][r])*(HgIIpw[i][j+1][r]-HgIIpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][r]+= Kme*HgIIpw[i][j][r]*dt-Kdeme*MMHgpw[i][j][r]*dt+(Dorsed[i][j][r]*(MMHgpw[i][j][r+1]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j][r-1]))*(dt/pow(dz2,2.0))+(Dorsed[i][j][r]*(MMHgpw[i+1][j][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i-1][j][r]))*(dt/pow(dx,2.0))+(Dorsed[i][j][r]*(MMHgpw[i][j+1][r]-2.0*MMHgpw[i][j][r]+MMHgpw[i][j-1][r]))*(dt/pow(dy,2.0))+((Dorsed[i][j][r+1]-Dorsed[i][j][r])*(MMHgpw[i][j][r+1]-MMHgpw[i][j][r]))*(dt/pow(dz2,2.0))+((Dorsed[i+1][j][r]-Dorsed[i][j][r])*(MMHgpw[i+1][j][r]-MMHgpw[i][j][r]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][r]-Dorsed[i][j][r])*(MMHgpw[i][j+1][r]-MMHgpw[i][j][r]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][r]+= 0.0; // mg/Kg
     }
     
     }
     
     if(THgsedold[i][j][10]>0.000000){
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*((1.0-kMM)/kDIIsed)*pow(10.0,6.0)*dt; // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0))+alfa*THgsed[i][j][10]*(kMM/kDMMsed)*pow(10.0,6.0)*dt; // microg/m^3
         THgsed[i][j][10]+= -1.0*alfa*THgsed[i][j][10]*dt; // mg/Kg
     }
     else{
         HgIIpw[i][j][10]+= Kdeme*MMHgpw[i][j][10]*dt-Kme*HgIIpw[i][j][10]*dt+(Dinsed[i][j][10]*(HgIIpw[i+1][j][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dinsed[i][j][10]*(HgIIpw[i][j+1][10]-2.0*HgIIpw[i][j][10]+HgIIpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dinsed[i+1][j][10]-Dinsed[i][j][10])*(HgIIpw[i+1][j][10]-HgIIpw[i][j][10]))*(dt/pow(dx,2.0))+((Dinsed[i][j+1][10]-Dinsed[i][j][10])*(HgIIpw[i][j+1][10]-HgIIpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         MMHgpw[i][j][10]+= Kme*HgIIpw[i][j][10]*dt-Kdeme*MMHgpw[i][j][10]*dt+(Dorsed[i][j][10]*(MMHgpw[i+1][j][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i-1][j][10]))*(dt/pow(dx,2.0))+(Dorsed[i][j][10]*(MMHgpw[i][j+1][10]-2.0*MMHgpw[i][j][10]+MMHgpw[i][j-1][10]))*(dt/pow(dy,2.0))+((Dorsed[i+1][j][10]-Dorsed[i][j][10])*(MMHgpw[i+1][j][10]-MMHgpw[i][j][10]))*(dt/pow(dx,2.0))+((Dorsed[i][j+1][10]-Dorsed[i][j][10])*(MMHgpw[i][j+1][10]-MMHgpw[i][j][10]))*(dt/pow(dy,2.0)); // microg/m^3
         THgsed[i][j][10]+= 0.0; // mg/Kg
     }
 
     for(r=1; r<=RL; r++){
     
     if(HgIIpw[i][j][r]<0.000000){
		HgIIpw[i][j][r]=0.0;
     }
     
     if(MMHgpw[i][j][r]<0.000000){
		MMHgpw[i][j][r]=0.0;
     }
     
     if(THgsed[i][j][r]<0.000000){
		THgsed[i][j][r]=0.0;
     }
     
     }

     }
     else{
     
     for(r=1; r<=RL; r++){
              
     HgIIpw[i][j][r]=0.0; // microg/m^3
     MMHgpw[i][j][r]=0.0; // microg/m^3
     THgsed[i][j][r]=0.0; // mg/Kg
     
     }

     }
     
     for(r=1; r<=RL; r++){
              
     THgsedold[i][j][r]=THgsed[i][j][r]; // mg/Kg

     }
         
     } 
  }
  
  if(((n==NF && m>=Mbir1) || (n>NF && n<=NF+AGE)) || ((n==NF2 && m>=Mbir2) || (n>NF2 && n<=NF2+AGE2))){
                                        
  if(n==NF && m>=Mbir1){
  Wfish=aWf*pow((Lfinf*(1.0-exp(-Kfish*((((m-Mbir1)*dt)/8760.0)-to))))/10.0,bWf)*pow(10.0,-3.0); // Kg
  }
  else if(n>NF && n<=NF+AGE){
  Wfish=aWf*pow((Lfinf*(1.0-exp(-Kfish*(((m*dt+(M-Mbir1)*dt+M*dt*(n-NF-1))/8760.0)-to))))/10.0,bWf)*pow(10.0,-3.0); // Kg
  }
  else if(n==NF2 && m>=Mbir2){
  Wfish=aWf*pow((Lfinf*(1.0-exp(-Kfish*((((m-Mbir2)*dt)/8760.0)-to))))/10.0,bWf)*pow(10.0,-3.0); // Kg
  }
  else if(n>NF2 && n<=NF2+AGE2){
  Wfish=aWf*pow((Lfinf*(1.0-exp(-Kfish*(((m*dt+(M-Mbir2)*dt+M*dt*(n-NF2-1))/8760.0)-to))))/10.0,bWf)*pow(10.0,-3.0); // Kg
  }
  else{
  Wfish=aWf*pow((Lfish0/10.0),bWf)*pow(10.0,-3.0); // Kg
  }
  
  if(n==NF+AGE && m==Mmay){           
  WfishAGE1=Wfish;
  }
  
  if(n==NF2+AGE2 && m==Moct){          
  WfishAGE2=Wfish;
  }
  
  for(i=1; i<=I; i++){
      for(j=1; j<=J; j++){    
         for(k=1; k<=K; k++){  
        
         if(Rini[i][j][k]==Rbot){
                                  
         kphupII[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((HgII[i][j][k]*pow(10.0,-3.0)),kpII)+(1.0/gamwat)); // l/(Kg*d)
         kphupMM[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((MMHg[i][j][k]*pow(10.0,-3.0)),kpMM)+(1.0/gamwat)); // l/(Kg*d)
         PhyHgII[i][j][k]+=(kphupII[i][j][k]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kphexII+kphgr)*PhyHgII[i][j][k]*(dt/24.0); //  microg/g or mg/Kg
         PhyMMHg[i][j][k]+=(kphupMM[i][j][k]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kphexMM+kphgr)*PhyMMHg[i][j][k]*(dt/24.0); //  microg/g or mg/Kg

         if(PhyHgII[i][j][k]<=0.000000){
		 		PhyHgII[i][j][k]=0.0;
         }
		   
         if(PhyMMHg[i][j][k]<=0.000000){
				PhyMMHg[i][j][k]=0.0;
         }
                            
           kzbivurII[i][j]=pow(Wzbiv,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzpolurII[i][j]=pow(Wzpol,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzampurII[i][j]=pow(Wzamp,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzdecurII[i][j]=pow(Wzdec,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzmysurII[i][j]=pow(Wzmys,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzosturII[i][j]=pow(Wzost,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzbivurMM[i][j]=pow(Wzbiv,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzpolurMM[i][j]=pow(Wzpol,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzampurMM[i][j]=pow(Wzamp,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzdecurMM[i][j]=pow(Wzdec,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzmysurMM[i][j]=pow(Wzmys,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzosturMM[i][j]=pow(Wzost,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           
           ZbivHgII[i][j]+=(kzbivurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzbivinphyII*PrefPhybiv*PhyHgII[i][j][k]+kzbivinsedII*Prefsedbiv*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzbivexrII+kzbivegrII+kzbivgr+lambmetbivII)*ZbivHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZampHgII[i][j]+=(kzampurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzampinphyII*PrefPhyamp*PhyHgII[i][j][k]+kzampinsedII*Prefsedamp*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzampexrII+kzampegrII+kzampgr+lambmetampII)*ZampHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZpolHgII[i][j]+=(kzpolurII[i][j]*HgIIpw[i][j][1]*pow(10.0,-6.0))*(dt/24.0)+(kzpolinsedII*Prefsedbotpol*((1.0-kMM)*THgsed[i][j][1])+kzpolinampII*PrefZooamppol*ZampHgII[i][j]+kzpolinpolII*PrefZoopolpol*ZpolHgII[i][j])*(dt/24.0)-(kzpolexrII+kzpolegrII+kzpolgr+lambmetpolII)*ZpolHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZmysHgII[i][j]+=(kzmysurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzmysinphyII*PrefPhymys*PhyHgII[i][j][k]+kzmysinpolII*PrefZoopolmys*ZpolHgII[i][j]+kzmysinampII*PrefZooampmys*ZampHgII[i][j]+kzmysinsedII*Prefsedmys*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzmysexrII+kzmysegrII+kzmysgr+lambmetmysII)*ZmysHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZostHgII[i][j]+=(kzosturII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzostinphyII*PrefPhyost*PhyHgII[i][j][k]+kzostinbivII*PrefZoobivost*ZbivHgII[i][j]+kzostinampII*PrefZooampost*ZampHgII[i][j]+kzostinmysII*PrefZoomysost*ZmysHgII[i][j]+kzostindecII*PrefZoodecost*ZdecHgII[i][j]+kzostinpolII*PrefZoopolost*ZpolHgII[i][j]+kzostinostII*PrefZooostost*ZostHgII[i][j]+kzostinsedII*Prefsedost*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzostexrII+kzostegrII+kzostgr+lambmetostII)*ZostHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZdecHgII[i][j]+=(kzdecurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzdecinphyII*PrefPhydec*PhyHgII[i][j][k]+kzdecinpolII*PrefZoopoldec*ZpolHgII[i][j]+kzdecinbivII*PrefZoobivdec*ZbivHgII[i][j]+kzdecinostII*PrefZooostdec*ZostHgII[i][j]+kzdecindecII*PrefZoodecdec*ZdecHgII[i][j]+kzdecinsedII*Prefsedbotdec*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kzdecexrII+kzdecegrII+kzdecgr+lambmetdecII)*ZdecHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
           
           ZbivMMHg[i][j]+=(kzbivurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzbivinphyMM*PrefPhybiv*PhyMMHg[i][j][k]+kzbivinsedMM*Prefsedbiv*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzbivexrMM+kzbivegrMM+kzbivgr+lambmetbivMM)*ZbivMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZampMMHg[i][j]+=(kzampurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzampinphyMM*PrefPhyamp*PhyMMHg[i][j][k]+kzampinsedMM*Prefsedamp*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzampexrMM+kzampegrMM+kzampgr+lambmetampMM)*ZampMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZpolMMHg[i][j]+=(kzpolurMM[i][j]*MMHgpw[i][j][1]*pow(10.0,-6.0))*(dt/24.0)+(kzpolinsedMM*Prefsedbotpol*(kMM*THgsed[i][j][1])+kzpolinampMM*PrefZooamppol*ZampMMHg[i][j]+kzpolinpolMM*PrefZoopolpol*ZpolMMHg[i][j])*(dt/24.0)-(kzpolexrMM+kzpolegrMM+kzpolgr+lambmetpolMM)*ZpolMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZmysMMHg[i][j]+=(kzmysurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzmysinphyMM*PrefPhymys*PhyMMHg[i][j][k]+kzmysinpolMM*PrefZoopolmys*ZpolMMHg[i][j]+kzmysinampMM*PrefZooampmys*ZampMMHg[i][j]+kzmysinsedMM*Prefsedmys*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzmysexrMM+kzmysegrMM+kzmysgr+lambmetmysMM)*ZmysMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZostMMHg[i][j]+=(kzosturMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzostinphyMM*PrefPhyost*PhyMMHg[i][j][k]+kzostinbivMM*PrefZoobivost*ZbivMMHg[i][j]+kzostinampMM*PrefZooampost*ZampMMHg[i][j]+kzostinmysMM*PrefZoomysost*ZmysMMHg[i][j]+kzostindecMM*PrefZoodecost*ZdecMMHg[i][j]+kzostinpolMM*PrefZoopolost*ZpolMMHg[i][j]+kzostinostMM*PrefZooostost*ZostMMHg[i][j]+kzostinsedMM*Prefsedost*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)-(kzostexrMM+kzostegrMM+kzostgr+lambmetostMM)*ZostMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           ZdecMMHg[i][j]+=(kzdecurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+(kzdecinphyMM*PrefPhydec*PhyMMHg[i][j][k]+kzdecinpolMM*PrefZoopoldec*ZpolMMHg[i][j]+kzdecinbivMM*PrefZoobivdec*ZbivMMHg[i][j]+kzdecinostMM*PrefZooostdec*ZostMMHg[i][j]+kzdecindecMM*PrefZoodecdec*ZdecMMHg[i][j]+kzdecinsedMM*Prefsedbotdec*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kzdecexrMM+kzdecegrMM+kzdecgr+lambmetdecMM)*ZdecMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           
           if(ZbivHgII[i][j]<=0.000000){
				ZbivHgII[i][j]=0.0;
           } 
	   
	       if(ZbivMMHg[i][j]<=0.000000){
				ZbivMMHg[i][j]=0.0;
	       } 

           if(ZpolHgII[i][j]<=0.000000){
				ZpolHgII[i][j]=0.0;
           } 
	   
	       if(ZpolMMHg[i][j]<=0.000000){
				ZpolMMHg[i][j]=0.0;
	       } 

           if(ZampHgII[i][j]<=0.000000){
				ZampHgII[i][j]=0.0;
           } 
	   
	       if(ZampMMHg[i][j]<=0.000000){
				ZampMMHg[i][j]=0.0;
	       }

           if(ZdecHgII[i][j]<=0.000000){
				ZdecHgII[i][j]=0.0;
           } 
	   
	       if(ZdecMMHg[i][j]<=0.000000){
				ZdecMMHg[i][j]=0.0;
	       }

           if(ZmysHgII[i][j]<=0.000000){
				ZmysHgII[i][j]=0.0;
           } 
	   
	       if(ZmysMMHg[i][j]<=0.000000){
				ZmysMMHg[i][j]=0.0;
	       }
	       
	       if(ZostHgII[i][j]<=0.000000){
				ZostHgII[i][j]=0.0;
           } 
	   
	       if(ZostMMHg[i][j]<=0.000000){
				ZostMMHg[i][j]=0.0;
	       }
	       
           psfish=0.20*pow(Wfish,0.03); //Kg dry/Kg wet
           
           kfurII[i][j]=pow(Wfish,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kfurMM[i][j]=pow(Wfish,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kfinbivII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinpolII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinampII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfindecII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinmysII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinostII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal);
           kfinsedII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinbivMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinpolMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinampMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfindecMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinmysMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinostMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal);
           kfinsedMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d 
           kfexrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
           kfexrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
           kfgr=qT*gamgrow*pow(Wfish,-1.0*kal); //1/d
           
		   if(((n==NF && m>=Mbir1) || (n==NF+1 && m<Mbir1)) || ((n==NF2 && m>=Mbir2) || (n==NF2+1 && m<Mbir2))){
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish1*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish1*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
               FiHgII[i][j]+=(kfurII[3][3]*HgII[3][3][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobiv1*ZbivHgII[3][3]+kfinpolII*PrefZoopol1*ZpolHgII[3][3]+kfinampII*PrefZooamp1*ZampHgII[3][3]+kfindecII*PrefZoodec1*ZdecHgII[3][3]+kfinmysII*PrefZoomys1*ZmysHgII[3][3]+kfinostII*PrefZooost1*ZostHgII[3][3])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[3][3][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[3][3]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[3][3]*MMHg[3][3][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobiv1*ZbivMMHg[3][3]+kfinpolMM*PrefZoopol1*ZpolMMHg[3][3]+kfinampMM*PrefZooamp1*ZampMMHg[3][3]+kfindecMM*PrefZoodec1*ZdecMMHg[3][3]+kfinmysMM*PrefZoomys1*ZmysMMHg[3][3]+kfinostMM*PrefZooost1*ZostMMHg[3][3])+kfinsedMM*Prefsed1*(kMM*THgsed[3][3][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[3][3]*(dt/24.0); // microg/g or mg/Kg
           }
           else if(((n==NF+1 && m>=Mbir1) || (n==NF+2 && m<Mbir1)) || ((n==NF2+1 && m>=Mbir2) || (n==NF2+2 && m<Mbir2))){
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish1*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish1*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
               FiHgII[i][j]+=(kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobiv1*ZbivHgII[i][j]+kfinpolII*PrefZoopol1*ZpolHgII[i][j]+kfinampII*PrefZooamp1*ZampHgII[i][j]+kfindecII*PrefZoodec1*ZdecHgII[i][j]+kfinmysII*PrefZoomys1*ZmysHgII[i][j]+kfinostII*PrefZooost1*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobiv1*ZbivMMHg[i][j]+kfinpolMM*PrefZoopol1*ZpolMMHg[i][j]+kfinampMM*PrefZooamp1*ZampMMHg[i][j]+kfindecMM*PrefZoodec1*ZdecMMHg[i][j]+kfinmysMM*PrefZoomys1*ZmysMMHg[i][j]+kfinostMM*PrefZooost1*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           }
           else if(n==NF+2 && m>=Mbir1){
               PrefZoobivt=PrefZoobiv1+deprefbivdet*(m-Mbir1)*dt;
               PrefZoopolt=PrefZoopol1+deprefpoldet*(m-Mbir1)*dt;
               PrefZooampt=PrefZooamp1+deprefampdet*(m-Mbir1)*dt;
               PrefZoodect=PrefZoodec1+deprefdecdet*(m-Mbir1)*dt;
               PrefZoomyst=PrefZoomys1+deprefmysdet*(m-Mbir1)*dt;
               PrefZooostt=PrefZooost1+deprefostdet*(m-Mbir1)*dt;
               psfoodfisht=PrefZoobivt*psbiv+PrefZoopolt*pspol+PrefZooampt*psamp+PrefZoodect*psdec+PrefZoomyst*psmys+PrefZooostt*psost+Prefsed1*pssed;  //Kg dry/Kg wet
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
			   FiHgII[i][j]+=(kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobivt*ZbivHgII[i][j]+kfinpolII*PrefZoopolt*ZpolHgII[i][j]+kfinampII*PrefZooampt*ZampHgII[i][j]+kfindecII*PrefZoodect*ZdecHgII[i][j]+kfinmysII*PrefZoomyst*ZmysHgII[i][j]+kfinostII*PrefZooostt*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobivt*ZbivMMHg[i][j]+kfinpolMM*PrefZoopolt*ZpolMMHg[i][j]+kfinampMM*PrefZooampt*ZampMMHg[i][j]+kfindecMM*PrefZoodect*ZdecMMHg[i][j]+kfinmysMM*PrefZoomyst*ZmysMMHg[i][j]+kfinostMM*PrefZooostt*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           }
           else if(n==NF+3 && m<=Madu1){
               PrefZoobivt=PrefZoobiv1+deprefbivdet*(m+M-Mbir1)*dt;
               PrefZoopolt=PrefZoopol1+deprefpoldet*(m+M-Mbir1)*dt;
               PrefZooampt=PrefZooamp1+deprefampdet*(m+M-Mbir1)*dt;
               PrefZoodect=PrefZoodec1+deprefdecdet*(m+M-Mbir1)*dt;
               PrefZoomyst=PrefZoomys1+deprefmysdet*(m+M-Mbir1)*dt;
               PrefZooostt=PrefZooost1+deprefostdet*(m+M-Mbir1)*dt;
               psfoodfisht=PrefZoobivt*psbiv+PrefZoopolt*pspol+PrefZooampt*psamp+PrefZoodect*psdec+PrefZoomyst*psmys+PrefZooostt*psost+Prefsed1*pssed;  //Kg dry/Kg wet
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
			   FiHgII[i][j]+=(kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobivt*ZbivHgII[i][j]+kfinpolII*PrefZoopolt*ZpolHgII[i][j]+kfinampII*PrefZooampt*ZampHgII[i][j]+kfindecII*PrefZoodect*ZdecHgII[i][j]+kfinmysII*PrefZoomyst*ZmysHgII[i][j]+kfinostII*PrefZooostt*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobivt*ZbivMMHg[i][j]+kfinpolMM*PrefZoopolt*ZpolMMHg[i][j]+kfinampMM*PrefZooampt*ZampMMHg[i][j]+kfindecMM*PrefZoodect*ZdecMMHg[i][j]+kfinmysMM*PrefZoomyst*ZmysMMHg[i][j]+kfinostMM*PrefZooostt*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           }
           else if(n==NF2+2 && m>=Mbir2){
               PrefZoobivt=PrefZoobiv1+deprefbivdet*(m-Mbir2)*dt;
               PrefZoopolt=PrefZoopol1+deprefpoldet*(m-Mbir2)*dt;
               PrefZooampt=PrefZooamp1+deprefampdet*(m-Mbir2)*dt;
               PrefZoodect=PrefZoodec1+deprefdecdet*(m-Mbir2)*dt;
               PrefZoomyst=PrefZoomys1+deprefmysdet*(m-Mbir2)*dt;
               PrefZooostt=PrefZooost1+deprefostdet*(m-Mbir2)*dt;
               psfoodfisht=PrefZoobivt*psbiv+PrefZoopolt*pspol+PrefZooampt*psamp+PrefZoodect*psdec+PrefZoomyst*psmys+PrefZooostt*psost+Prefsed1*pssed;  //Kg dry/Kg wet
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
			   FiHgII[i][j]+=(kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobivt*ZbivHgII[i][j]+kfinpolII*PrefZoopolt*ZpolHgII[i][j]+kfinampII*PrefZooampt*ZampHgII[i][j]+kfindecII*PrefZoodect*ZdecHgII[i][j]+kfinmysII*PrefZoomyst*ZmysHgII[i][j]+kfinostII*PrefZooostt*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobivt*ZbivMMHg[i][j]+kfinpolMM*PrefZoopolt*ZpolMMHg[i][j]+kfinampMM*PrefZooampt*ZampMMHg[i][j]+kfindecMM*PrefZoodect*ZdecMMHg[i][j]+kfinmysMM*PrefZoomyst*ZmysMMHg[i][j]+kfinostMM*PrefZooostt*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           }
           else if(n==NF2+3 && m<=Madu2){
               PrefZoobivt=PrefZoobiv1+deprefbivdet*(m+M-Mbir2)*dt;
               PrefZoopolt=PrefZoopol1+deprefpoldet*(m+M-Mbir2)*dt;
               PrefZooampt=PrefZooamp1+deprefampdet*(m+M-Mbir2)*dt;
               PrefZoodect=PrefZoodec1+deprefdecdet*(m+M-Mbir2)*dt;
               PrefZoomyst=PrefZoomys1+deprefmysdet*(m+M-Mbir2)*dt;
               PrefZooostt=PrefZooost1+deprefostdet*(m+M-Mbir2)*dt;
               psfoodfisht=PrefZoobivt*psbiv+PrefZoopolt*pspol+PrefZooampt*psamp+PrefZoodect*psdec+PrefZoomyst*psmys+PrefZooostt*psost+Prefsed1*pssed;  //Kg dry/Kg wet
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfisht*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
			   FiHgII[i][j]+=(kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobivt*ZbivHgII[i][j]+kfinpolII*PrefZoopolt*ZpolHgII[i][j]+kfinampII*PrefZooampt*ZampHgII[i][j]+kfindecII*PrefZoodect*ZdecHgII[i][j]+kfinmysII*PrefZoomyst*ZmysHgII[i][j]+kfinostII*PrefZooostt*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobivt*ZbivMMHg[i][j]+kfinpolMM*PrefZoopolt*ZpolMMHg[i][j]+kfinampMM*PrefZooampt*ZampMMHg[i][j]+kfindecMM*PrefZoodect*ZdecMMHg[i][j]+kfinmysMM*PrefZoomyst*ZmysMMHg[i][j]+kfinostMM*PrefZooostt*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           }
           else if(((n==NF+3 && m>Madu1) || (n>NF+3 && n<=NF+AGE)) || ((n==NF2+3 && m>Madu2) || (n>NF2+3 && n<=NF2+AGE2))){
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
               FiHgII[i][j]+=(kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivII*PrefZoobiv*ZbivHgII[i][j]+kfinpolII*PrefZoopol*ZpolHgII[i][j]+kfinampII*PrefZooamp*ZampHgII[i][j]+kfindecII*PrefZoodec*ZdecHgII[i][j]+kfinmysII*PrefZoomys*ZmysHgII[i][j]+kfinostII*PrefZooost*ZostHgII[i][j])+kfinsedII*Prefsed*((1.0-kMM)*THgsed[i][j][1]))*(dt/24.0)-(kfexrII+kfegrII+kfgr+lambmetII)*FiHgII[i][j]*(dt/24.0); // microg/g or mg/Kg
               FiMMHg[i][j]+=(kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))*(dt/24.0)+((kfinbivMM*PrefZoobiv*ZbivMMHg[i][j]+kfinpolMM*PrefZoopol*ZpolMMHg[i][j]+kfinampMM*PrefZooamp*ZampMMHg[i][j]+kfindecMM*PrefZoodec*ZdecMMHg[i][j]+kfinmysMM*PrefZoomys*ZmysMMHg[i][j]+kfinostMM*PrefZooost*ZostMMHg[i][j])+kfinsedMM*Prefsed*(kMM*THgsed[i][j][1]))*(dt/24.0)-(kfexrMM+kfegrMM+kfgr+lambmetMM)*FiMMHg[i][j]*(dt/24.0); // microg/g or mg/Kg
           }
           else{
               kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish1*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
               kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish1*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
               FiHgII[i][j]=((kfurII[3][3]*HgII[3][3][k]*pow(10.0,-6.0))+((kfinbivII*PrefZoobiv1*ZbivHgII[3][3]+kfinpolII*PrefZoopol1*ZpolHgII[3][3]+kfinampII*PrefZooamp1*ZampHgII[3][3]+kfindecII*PrefZoodec1*ZdecHgII[3][3]+kfinmysII*PrefZoomys1*ZmysHgII[3][3]+kfinostII*PrefZooost1*ZostHgII[3][3])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[3][3][1])))/(kfexrII+kfegrII+kfgr+lambmetII); // microg/g or mg/Kg
           	   FiMMHg[i][j]=((kfurMM[3][3]*MMHg[3][3][k]*pow(10.0,-6.0))+((kfinbivMM*PrefZoobiv1*ZbivMMHg[3][3]+kfinpolMM*PrefZoopol1*ZpolMMHg[3][3]+kfinampMM*PrefZooamp1*ZampMMHg[3][3]+kfindecMM*PrefZoodec1*ZdecMMHg[3][3]+kfinmysMM*PrefZoomys1*ZmysMMHg[3][3]+kfinostMM*PrefZooost1*ZostMMHg[3][3])+kfinsedMM*Prefsed1*(kMM*THgsed[3][3][1])))/(kfexrMM+kfegrMM+kfgr+lambmetMM); // microg/g or mg/Kg
           }

           if(FiHgII[i][j]<=0.000000){
				FiHgII[i][j]=0.0;
           } 
	   
	       if(FiMMHg[i][j]<=0.000000){
				FiMMHg[i][j]=0.0;
	       } 
           
        }
         
        if(n==NF+AGE && m==Mmay){    

        if(Rini[i][j][k]==Rbot){
             PhyHgIIsptmean+=PhyHgII[i][j][k]/SUR;
             PhyMMHgsptmean+=PhyMMHg[i][j][k]/SUR;                     
        }
        else{
             PhyHgIIsptmean+=0.0;
             PhyMMHgsptmean+=0.0;  
        }
               
        }
        
        if(n==NF2+AGE2 && m==Moct){    
 
        if(Rini[i][j][k]==Rbot){
             PhyHgIIsptmean2+=PhyHgII[i][j][k]/SUR;
             PhyMMHgsptmean2+=PhyMMHg[i][j][k]/SUR;                     
        }
        else{
             PhyHgIIsptmean2+=0.0;
             PhyMMHgsptmean2+=0.0;  
        }   
        
        }
        
        } 
        
        if(n==NF+AGE && m==Mmay){

        if(Rini[i][j][1]>=Rin){
             ZbivHgIIsptmean+=(ZbivHgII[i][j]/SUR);
             ZbivMMHgsptmean+=(ZbivMMHg[i][j]/SUR); 
             ZpolHgIIsptmean+=(ZpolHgII[i][j]/SUR);
             ZpolMMHgsptmean+=(ZpolMMHg[i][j]/SUR);    
             ZampHgIIsptmean+=(ZampHgII[i][j]/SUR);
             ZampMMHgsptmean+=(ZampMMHg[i][j]/SUR);
             ZdecHgIIsptmean+=(ZdecHgII[i][j]/SUR);
             ZdecMMHgsptmean+=(ZdecMMHg[i][j]/SUR);
             ZmysHgIIsptmean+=(ZmysHgII[i][j]/SUR);
             ZmysMMHgsptmean+=(ZmysMMHg[i][j]/SUR); 
             ZostHgIIsptmean+=(ZostHgII[i][j]/SUR);
             ZostMMHgsptmean+=(ZostMMHg[i][j]/SUR);           
             FiHgIIsptmean+=(FiHgII[i][j]/SUR); 
             FiMMHgsptmean+=(FiMMHg[i][j]/SUR); 
          }
          else{
             ZbivHgIIsptmean+=0.0;
             ZbivMMHgsptmean+=0.0;  
             ZpolHgIIsptmean+=0.0;
             ZpolMMHgsptmean+=0.0;  
             ZampHgIIsptmean+=0.0;
             ZampMMHgsptmean+=0.0;
             ZdecHgIIsptmean+=0.0;
             ZdecMMHgsptmean+=0.0;
             ZmysHgIIsptmean+=0.0;
             ZmysMMHgsptmean+=0.0;
             ZostHgIIsptmean+=0.0;
             ZostMMHgsptmean+=0.0;
             FiHgIIsptmean+=0.0;
             FiMMHgsptmean+=0.0;
          } 
          
        }
        
        if(n==NF2+AGE2 && m==Moct){
        
        if(Rini[i][j][1]>=Rin){
             ZbivHgIIsptmean2+=(ZbivHgII[i][j]/SUR);
             ZbivMMHgsptmean2+=(ZbivMMHg[i][j]/SUR); 
             ZpolHgIIsptmean2+=(ZpolHgII[i][j]/SUR);
             ZpolMMHgsptmean2+=(ZpolMMHg[i][j]/SUR);    
             ZampHgIIsptmean2+=(ZampHgII[i][j]/SUR);
             ZampMMHgsptmean2+=(ZampMMHg[i][j]/SUR);
             ZdecHgIIsptmean2+=(ZdecHgII[i][j]/SUR);
             ZdecMMHgsptmean2+=(ZdecMMHg[i][j]/SUR);
             ZmysHgIIsptmean2+=(ZmysHgII[i][j]/SUR);
             ZmysMMHgsptmean2+=(ZmysMMHg[i][j]/SUR); 
             ZostHgIIsptmean2+=(ZostHgII[i][j]/SUR);
             ZostMMHgsptmean2+=(ZostMMHg[i][j]/SUR);                 
             FiHgIIsptmean2+=(FiHgII[i][j]/SUR); 
             FiMMHgsptmean2+=(FiMMHg[i][j]/SUR); 
          }
          else{
             ZbivHgIIsptmean2+=0.0;
             ZbivMMHgsptmean2+=0.0;  
             ZpolHgIIsptmean2+=0.0;
             ZpolMMHgsptmean2+=0.0;  
             ZampHgIIsptmean2+=0.0;
             ZampMMHgsptmean2+=0.0;
             ZdecHgIIsptmean2+=0.0;
             ZdecMMHgsptmean2+=0.0;
             ZmysHgIIsptmean2+=0.0;
             ZmysMMHgsptmean2+=0.0;
             ZostHgIIsptmean2+=0.0;
             ZostMMHgsptmean2+=0.0;  
             FiHgIIsptmean2+=0.0;
             FiMMHgsptmean2+=0.0;
          } 
          
        }
        
     } 
  }
  
  }
  else{
                                                
  Wfish=aWf*pow((Lfish0/10.0),bWf)*pow(10.0,-3.0); // Kg
  
  for(i=1; i<=I; i++){
      for(j=1; j<=J; j++){
                    
         for(k=1; k<=K; k++){  
        
         if(Rini[i][j][k]==Rbot){
                                
         kphupII[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((HgII[i][j][k]*pow(10.0,-3.0)),kpII)+(1.0/gamwat)); // l/(Kg*d)
         kphupMM[i][j][k]=pow(Wp1*pow(10.0,-9.0),-kal)/(rowat+rolip*pow((MMHg[i][j][k]*pow(10.0,-3.0)),kpMM)+(1.0/gamwat)); // l/(Kg*d)
         PhyHgII[i][j][k]=(kphupII[i][j][k]*HgII[i][j][k]*pow(10.0,-6.0))/(kphexII+kphgr); //  microg/g or mg/Kg
         PhyMMHg[i][j][k]=(kphupMM[i][j][k]*MMHg[i][j][k]*pow(10.0,-6.0))/(kphexMM+kphgr); //  microg/g or mg/Kg

         if(PhyHgII[i][j][k]<=0.000000){
		 		PhyHgII[i][j][k]=0.0;
         }
		   
         if(PhyMMHg[i][j][k]<=0.000000){
				PhyMMHg[i][j][k]=0.0;
         }
         
           kzbivurII[i][j]=pow(Wzbiv,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzpolurII[i][j]=pow(Wzpol,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzampurII[i][j]=pow(Wzamp,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzdecurII[i][j]=pow(Wzdec,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzmysurII[i][j]=pow(Wzmys,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzosturII[i][j]=pow(Wzost,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kzbivurMM[i][j]=pow(Wzbiv,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzpolurMM[i][j]=pow(Wzpol,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzampurMM[i][j]=pow(Wzamp,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzdecurMM[i][j]=pow(Wzdec,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzmysurMM[i][j]=pow(Wzmys,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kzosturMM[i][j]=pow(Wzost,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           
           ZbivHgII[i][j]=((kzbivurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzbivinphyII*PrefPhybiv*PhyHgII[i][j][k]+kzbivinsedII*Prefsedbiv*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzbivexrII+kzbivegrII+kzbivgr+lambmetbivII); // microg/g or mg/Kg
           ZampHgII[i][j]=((kzampurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzampinphyII*PrefPhyamp*PhyHgII[i][j][k]+kzampinsedII*Prefsedamp*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzampexrII+kzampegrII+kzampgr+lambmetampII); // microg/g or mg/Kg
           ZpolHgII[i][j]=((kzpolurII[i][j]*HgIIpw[i][j][1]*pow(10.0,-6.0))+(kzpolinsedII*Prefsedbotpol*((1.0-kMM)*THgsed[i][j][1])+kzpolinampII*PrefZooamppol*ZampHgII[i][j]+kzpolinpolII*PrefZoopolpol*ZpolHgII[i][j]))/(kzpolexrII+kzpolegrII+kzpolgr+lambmetpolII); // microg/g or mg/Kg
           ZmysHgII[i][j]=((kzmysurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzmysinphyII*PrefPhymys*PhyHgII[i][j][k]+kzmysinpolII*PrefZoopolmys*ZpolHgII[i][j]+kzmysinampII*PrefZooampmys*ZampHgII[i][j]+kzmysinsedII*Prefsedmys*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzmysexrII+kzmysegrII+kzmysgr+lambmetmysII); // microg/g or mg/Kg
           ZostHgII[i][j]=((kzosturII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzostinphyII*PrefPhyost*PhyHgII[i][j][k]+kzostinbivII*PrefZoobivost*ZbivHgII[i][j]+kzostinampII*PrefZooampost*ZampHgII[i][j]+kzostinmysII*PrefZoomysost*ZmysHgII[i][j]+kzostindecII*PrefZoodecost*ZdecHgII[i][j]+kzostinpolII*PrefZoopolost*ZpolHgII[i][j]+kzostinostII*PrefZooostost*ZostHgII[i][j]+kzostinsedII*Prefsedost*kDSPM0*HgII[i][j][k]*pow(10.0,-6.0)))/(kzostexrII+kzostegrII+kzostgr+lambmetostII); // microg/g or mg/Kg
           ZdecHgII[i][j]=((kzdecurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+(kzdecinphyII*PrefPhydec*PhyHgII[i][j][k]+kzdecinpolII*PrefZoopoldec*ZpolHgII[i][j]+kzdecinbivII*PrefZoobivdec*ZbivHgII[i][j]+kzdecinostII*PrefZooostdec*ZostHgII[i][j]+kzdecindecII*PrefZoodecdec*ZdecHgII[i][j]+kzdecinsedII*Prefsedbotdec*((1.0-kMM)*THgsed[i][j][1])))/(kzdecexrII+kzdecegrII+kzdecgr+lambmetdecII); // microg/g or mg/Kg
           
		   ZbivMMHg[i][j]=((kzbivurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzbivinphyMM*PrefPhybiv*PhyMMHg[i][j][k]+kzbivinsedMM*Prefsedbiv*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzbivexrMM+kzbivegrMM+kzbivgr+lambmetbivMM); // microg/g or mg/Kg
           ZampMMHg[i][j]=((kzampurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzampinphyMM*PrefPhyamp*PhyMMHg[i][j][k]+kzampinsedMM*Prefsedamp*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzampexrMM+kzampegrMM+kzampgr+lambmetampMM); // microg/g or mg/Kg
           ZpolMMHg[i][j]=((kzpolurMM[i][j]*MMHgpw[i][j][1]*pow(10.0,-6.0))+(kzpolinsedMM*Prefsedbotpol*(kMM*THgsed[i][j][1])+kzpolinampMM*PrefZooamppol*ZampMMHg[i][j]+kzpolinpolMM*PrefZoopolpol*ZpolMMHg[i][j]))/(kzpolexrMM+kzpolegrMM+kzpolgr+lambmetpolMM); // microg/g or mg/Kg
           ZmysMMHg[i][j]=((kzmysurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzmysinphyMM*PrefPhymys*PhyMMHg[i][j][k]+kzmysinpolMM*PrefZoopolmys*ZpolMMHg[i][j]+kzmysinampMM*PrefZooampmys*ZampMMHg[i][j]+kzmysinsedMM*Prefsedmys*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzmysexrMM+kzmysegrMM+kzmysgr+lambmetmysMM); // microg/g or mg/Kg
           ZostMMHg[i][j]=((kzosturMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzostinphyMM*PrefPhyost*PhyMMHg[i][j][k]+kzostinbivMM*PrefZoobivost*ZbivMMHg[i][j]+kzostinampMM*PrefZooampost*ZampMMHg[i][j]+kzostinmysMM*PrefZoomysost*ZmysMMHg[i][j]+kzostindecMM*PrefZoodecost*ZdecMMHg[i][j]+kzostinpolMM*PrefZoopolost*ZpolMMHg[i][j]+kzostinostMM*PrefZooostost*ZostMMHg[i][j]+kzostinsedMM*Prefsedost*kDSPM0*MMHg[i][j][k]*pow(10.0,-6.0)))/(kzostexrMM+kzostegrMM+kzostgr+lambmetostMM); // microg/g or mg/Kg
           ZdecMMHg[i][j]=((kzdecurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+(kzdecinphyMM*PrefPhydec*PhyMMHg[i][j][k]+kzdecinpolMM*PrefZoopoldec*ZpolMMHg[i][j]+kzdecinbivMM*PrefZoobivdec*ZbivMMHg[i][j]+kzdecinostMM*PrefZooostdec*ZostMMHg[i][j]+kzdecindecMM*PrefZoodecdec*ZdecMMHg[i][j]+kzdecinsedMM*Prefsedbotdec*(kMM*THgsed[i][j][1])))/(kzdecexrMM+kzdecegrMM+kzdecgr+lambmetdecMM); // microg/g or mg/Kg
           
           if(ZbivHgII[i][j]<=0.000000){
				ZbivHgII[i][j]=0.0;
           } 
	   
	       if(ZbivMMHg[i][j]<=0.000000){
				ZbivMMHg[i][j]=0.0;
	       } 

           if(ZpolHgII[i][j]<=0.000000){
				ZpolHgII[i][j]=0.0;
           } 
	   
	       if(ZpolMMHg[i][j]<=0.000000){
				ZpolMMHg[i][j]=0.0;
	       } 

           if(ZampHgII[i][j]<=0.000000){
				ZampHgII[i][j]=0.0;
           } 
	   
	       if(ZampMMHg[i][j]<=0.000000){
				ZampMMHg[i][j]=0.0;
	       }

           if(ZdecHgII[i][j]<=0.000000){
				ZdecHgII[i][j]=0.0;
           } 
	   
	       if(ZdecMMHg[i][j]<=0.000000){
				ZdecMMHg[i][j]=0.0;
	       }

           if(ZmysHgII[i][j]<=0.000000){
				ZmysHgII[i][j]=0.0;
           } 
	   
	       if(ZmysMMHg[i][j]<=0.000000){
				ZmysMMHg[i][j]=0.0;
	       }
	       
	       if(ZostHgII[i][j]<=0.000000){
				ZostHgII[i][j]=0.0;
           } 
	   
	       if(ZostMMHg[i][j]<=0.000000){
				ZostMMHg[i][j]=0.0;
	       }
	       
           psfish=0.20*pow(Wfish,0.03); //Kg dry/Kg wet
           
           kfurII[i][j]=pow(Wfish,-1.0*kal)/(rowat+rolip*pow(HgII[i][j][k]*pow(10.0,-3.0),kpII)+(1.0/gamwat)); // l/Kg*d
           kfurMM[i][j]=pow(Wfish,-1.0*kal)/(rowat+rolip*pow(MMHg[i][j][k]*pow(10.0,-3.0),kpMM)+(1.0/gamwat)); // l/Kg*d
           kfinbivII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinpolII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinampII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfindecII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinmysII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinostII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal);
           kfinsedII=AssFoodII*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinbivMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinpolMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinampMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfindecMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinmysMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d
           kfinostMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal);
           kfinsedMM=AssFoodMM*qT*gamfood*pow(Wfish,-1.0*kal); // 1/d 
           kfexrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
           kfexrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowat+rolipexc+(1.0/gamwat)));  // 1/d
           kfegrII=(1.0/(psfish*KtwII))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish*KtwII*(1.0-AssFood)*qT*gamfood)))); // 1/d
           kfegrMM=(1.0/(psfish*KtwMM))*(pow(Wfish,-1.0*kal)/(rowatfood+(rolipexc/qT)+(1.0/(psfoodfish*KtwMM*(1.0-AssFood)*qT*gamfood)))); // 1/d
           kfgr=qT*gamgrow*pow(Wfish,-1.0*kal); //1/d
           
           //FiHgII[i][j]=((kfurII[i][j]*HgII[i][j][k]*pow(10.0,-6.0))+((kfinbivII*PrefZoobiv1*ZbivHgII[i][j]+kfinpolII*PrefZoopol1*ZpolHgII[i][j]+kfinampII*PrefZooamp1*ZampHgII[i][j]+kfindecII*PrefZoodec1*ZdecHgII[i][j]+kfinmysII*PrefZoomys1*ZmysHgII[i][j]+kfinostII*PrefZooost1*ZostHgII[i][j])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[i][j][1])))/(kfexrII+kfegrII+kfgr+lambmetII); // microg/g or mg/Kg
           //FiMMHg[i][j]=((kfurMM[i][j]*MMHg[i][j][k]*pow(10.0,-6.0))+((kfinbivMM*PrefZoobiv1*ZbivMMHg[i][j]+kfinpolMM*PrefZoopol1*ZpolMMHg[i][j]+kfinampMM*PrefZooamp1*ZampMMHg[i][j]+kfindecMM*PrefZoodec1*ZdecMMHg[i][j]+kfinmysMM*PrefZoomys1*ZmysMMHg[i][j]+kfinostMM*PrefZooost1*ZostMMHg[i][j])+kfinsedMM*Prefsed1*(kMM*THgsed[i][j][1])))/(kfexrMM+kfegrMM+kfgr+lambmetMM); // microg/g or mg/Kg
           
           FiHgII[i][j]=((kfurII[3][3]*HgII[3][3][k]*pow(10.0,-6.0))+((kfinbivII*PrefZoobiv1*ZbivHgII[3][3]+kfinpolII*PrefZoopol1*ZpolHgII[3][3]+kfinampII*PrefZooamp1*ZampHgII[3][3]+kfindecII*PrefZoodec1*ZdecHgII[3][3]+kfinmysII*PrefZoomys1*ZmysHgII[3][3]+kfinostII*PrefZooost1*ZostHgII[3][3])+kfinsedII*Prefsed1*((1.0-kMM)*THgsed[3][3][1])))/(kfexrII+kfegrII+kfgr+lambmetII); // microg/g or mg/Kg
           FiMMHg[i][j]=((kfurMM[3][3]*MMHg[3][3][k]*pow(10.0,-6.0))+((kfinbivMM*PrefZoobiv1*ZbivMMHg[3][3]+kfinpolMM*PrefZoopol1*ZpolMMHg[3][3]+kfinampMM*PrefZooamp1*ZampMMHg[3][3]+kfindecMM*PrefZoodec1*ZdecMMHg[3][3]+kfinmysMM*PrefZoomys1*ZmysMMHg[3][3]+kfinostMM*PrefZooost1*ZostMMHg[3][3])+kfinsedMM*Prefsed1*(kMM*THgsed[3][3][1])))/(kfexrMM+kfegrMM+kfgr+lambmetMM); // microg/g or mg/Kg

           if(FiHgII[i][j]<=0.000000){
				FiHgII[i][j]=0.0;
           } 
	   
	       if(FiMMHg[i][j]<=0.000000){
				FiMMHg[i][j]=0.0;
	       } 
           
        }

        } 
     } 
  }
   
  }

   if(n==1 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9 || n==10 || n==11 || n==12 || n==13 || n==25 || n==50 || n==75 || n==100 || n==150 || n==200 || n==N){
     for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){ 
                 
            if(m%tempo==0){
				   fprintf(ftotdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, Totdep[i][j]);
				   fprintf(fZbiv,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZbivHgII[i][j], ZbivMMHg[i][j]);
				   fprintf(fZpol,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZpolHgII[i][j], ZpolMMHg[i][j]);
				   fprintf(fZamp,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZampHgII[i][j], ZampMMHg[i][j]);
				   fprintf(fZdec,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZdecHgII[i][j], ZdecMMHg[i][j]);
				   fprintf(fZmys,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZmysHgII[i][j], ZmysMMHg[i][j]);
				   fprintf(fZost,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, ZostHgII[i][j], ZostMMHg[i][j]);
				   fprintf(fFi,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, FiHgII[i][j], FiMMHg[i][j]);
            }             
                             
            
            for(r=1; r<=RL; r++){
            
                if(m%tempo==0){
                                        
                fprintf(fHgIIpw,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, HgIIpw[i][j][r]);
                fprintf(fMMHgpw,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, MMHgpw[i][j][r]); 
                fprintf(fTHgsed,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (r-1)*dz2+dz1, THgsed[i][j][r]);
                
                } 
                
            } 
            
            for(k=1; k<=K; k++){
            
                if(m%tempo==0){
	               fprintf(fb1,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, b1[i][j][k]);
				   fprintf(fct,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, chlatot[i][j][k]);
				   fprintf(fR,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, R[i][j][k]);
				   fprintf(fI,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, It[i][j][k]);
				   fprintf(fHg0,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, Hg0[i][j][k]);
				   fprintf(fHgII,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, HgII[i][j][k]);
				   fprintf(fMMHg,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, MMHg[i][j][k]);
				   fprintf(fDHg,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, DHg[i][j][k]);
				   fprintf(fTHg,"%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, THg[i][j][k]);
			       fprintf(fP,"%f\t%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, PHgII[i][j][k], PMMHg[i][j][k]);
                   fprintf(fPhy,"%f\t%f\t%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, (k-1)*dz+2.5, PhyHgII[i][j][k], PhyMMHg[i][j][k]);

                }          	
            }    
        }
     }
  }  
   
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
    
       if(Rini[i][j][1]==Rbot){
               
               flub1z[i][j][1]=0.0;
               fluRz[i][j][1]=0.0;
               fluHg0z[i][j][1]=-1.0*Hggas*(Pr/det)*pow(10.0,-3.0)-1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1]); // microg/(m^2*h)
               fluHgIIz[i][j][1]=-1.0*HgIIatm*(Pr/det)*pow(10.0,-3.0)-DrydepHgII-1.0*MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][1]); // microg/(m^2*h)
               fluMMHgz[i][j][1]=-0.005025*(HgIIatm*(Pr/det)*pow(10.0,-3.0)+DrydepHgII)-1.0*MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][1]); // microg/(m^2*h)      
                 
       }
       else if(Rini[i][j][1]==Rin && Rini[i][j][2]>=Rin){
            
               if(vz[i][j][1]>=0.000000){
               fluRz[i][j][1]=-1.0*Dzz*((R[i][j][2]-R[i][j][1])/dz);
               fluHg0z[i][j][1]=-1.0*Hggas*(Pr/det)*pow(10.0,-3.0)-1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])+vz[i][j][1]*(Hg0[i][j][1])-1.0*Dzz*((Hg0[i][j][2]-Hg0[i][j][1])/dz);
               fluHgIIz[i][j][1]=-1.0*HgIIatm*(Pr/det)*pow(10.0,-3.0)-DrydepHgII-1.0*Dzz*((HgII[i][j][2]-HgII[i][j][1])/dz);
               fluMMHgz[i][j][1]=-0.005025*(HgIIatm*(Pr/det)*pow(10.0,-3.0)+DrydepHgII)-1.0*Dzz*((MMHg[i][j][2]-MMHg[i][j][1])/dz);
               }
               else if(vz[i][j][1]<0.000000){
               fluRz[i][j][1]=vz[i][j][1]*(R[i][j][2]-R[i][j][1])-1.0*Dzz*((R[i][j][2]-R[i][j][1])/dz);
               fluHg0z[i][j][1]=-1.0*Hggas*(Pr/det)*pow(10.0,-3.0)-1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])+vz[i][j][1]*(Hg0[i][j][2]-Hg0[i][j][1])-1.0*Dzz*((Hg0[i][j][2]-Hg0[i][j][1])/dz);
               fluHgIIz[i][j][1]=-1.0*HgIIatm*(Pr/det)*pow(10.0,-3.0)-DrydepHgII+vz[i][j][1]*(HgII[i][j][2]-HgII[i][j][1])-1.0*Dzz*((HgII[i][j][2]-HgII[i][j][1])/dz);
               fluMMHgz[i][j][1]=-0.005025*(HgIIatm*(Pr/det)*pow(10.0,-3.0)+DrydepHgII)+vz[i][j][1]*(MMHg[i][j][2]-MMHg[i][j][1])-1.0*Dzz*((MMHg[i][j][2]-MMHg[i][j][1])/dz);
               }
               else{
               fluRz[i][j][1]=0.0;
               fluHg0z[i][j][1]=0.0;
               fluHgIIz[i][j][1]=0.0;
               fluMMHgz[i][j][1]=0.0;
               }  
                
               if(v1+vz[i][j][1]>=0.000000){
               flub1z[i][j][1]=-1.0*Dzz*((b1[i][j][2]-b1[i][j][1])/dz);
               }
               else if(v1+vz[i][j][1]<0.000000){
               flub1z[i][j][1]=(v1+vz[i][j][1])*(b1[i][j][2]-b1[i][j][1])-1.0*Dzz*((b1[i][j][2]-b1[i][j][1])/dz);
               }
               else{
               flub1z[i][j][1]=0.0;
               }  
                                     
       }
       else{
               fluHg0z[i][j][1]=0.0; // microg/(m^2*h) 
               fluHgIIz[i][j][1]=0.0; // microg/(m^2*h)
               fluMMHgz[i][j][1]=0.0; // microg/(m^2*h)
               flub1z[i][j][1]=0.0;
               fluRz[i][j][1]=0.0;
       }
  
     }
   }
   
    for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=1; k<=K; k++){ // rispetto allo spazio z	
            
            if(Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin && vx[i][j][k]>=0.000000){
			   flub1x[i][j][k]=vx[i][j][k]*(b1[i][j][k]-b1[i-1][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i][j][k]-R[i-1][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i][j][k]-Hg0[i-1][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i][j][k]-HgII[i-1][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i][j][k]-MMHg[i-1][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
            }
            else if(vx[i][j][k]<0.000000 && Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin){   
           	   flub1x[i][j][k]=vx[i][j][k]*(b1[i+1][j][k]-b1[i][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i+1][j][k]-R[i][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i+1][j][k]-Hg0[i][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i+1][j][k]-HgII[i][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i+1][j][k]-MMHg[i][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
            }
            else if(Rini[i-1][j][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin && vx[i][j][k]>=0.000000){
			   flub1x[i][j][k]=vx[i][j][k]*(b1[i][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
            }
            else if(Rini[i-1][j][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i+1][j][k]>=Rin && vx[i][j][k]<0.000000){
			   flub1x[i][j][k]=vx[i][j][k]*(b1[i+1][j][k]-b1[i][j][k])-1.0*Dxx*((b1[i+1][j][k]-b1[i][j][k])/dx);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i+1][j][k]-R[i][j][k])-1.0*Dxx*((R[i+1][j][k]-R[i][j][k])/dx);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i+1][j][k]-Hg0[i][j][k])-1.0*Dxx*((Hg0[i+1][j][k]-Hg0[i][j][k])/dx);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i+1][j][k]-HgII[i][j][k])-1.0*Dxx*((HgII[i+1][j][k]-HgII[i][j][k])/dx);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i+1][j][k]-MMHg[i][j][k])-1.0*Dxx*((MMHg[i+1][j][k]-MMHg[i][j][k])/dx);
            }
            else if(Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]<=0.000000 && vx[i][j][k]<=0.000000){
               flub1x[i][j][k]=vx[i][j][k]*(-b1[i][j][k]);
			   fluRx[i][j][k]=vx[i][j][k]*(-R[i][j][k]);
               fluHg0x[i][j][k]=vx[i][j][k]*(-Hg0[i][j][k]);
               fluHgIIx[i][j][k]=vx[i][j][k]*(-HgII[i][j][k]);
               fluMMHgx[i][j][k]=vx[i][j][k]*(-MMHg[i][j][k]);
            }
            else if(Rini[i-1][j][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i+1][j][k]<=0.000000 && vx[i][j][k]>0.000000){
               flub1x[i][j][k]=vx[i][j][k]*(b1[i][j][k]-b1[i-1][j][k]);
			   fluRx[i][j][k]=vx[i][j][k]*(R[i][j][k]-R[i-1][j][k]);
               fluHg0x[i][j][k]=vx[i][j][k]*(Hg0[i][j][k]-Hg0[i-1][j][k]);
               fluHgIIx[i][j][k]=vx[i][j][k]*(HgII[i][j][k]-HgII[i-1][j][k]);
               fluMMHgx[i][j][k]=vx[i][j][k]*(MMHg[i][j][k]-MMHg[i-1][j][k]);
            }
            else{
               flub1x[i][j][k]=0.0;
			   fluRx[i][j][k]=0.0;
               fluHg0x[i][j][k]=0.0;
               fluHgIIx[i][j][k]=0.0;
               fluMMHgx[i][j][k]=0.0;
            }  
                  
            }
        }
    }    
                         
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=1; k<=K; k++){ // rispetto allo spazio z	     
            
            if(Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin && vy[i][j][k]>=0.000000){
			   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j][k]-b1[i][j-1][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j][k]-R[i][j-1][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j][k]-Hg0[i][j-1][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j][k]-HgII[i][j-1][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j][k]-MMHg[i][j-1][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
            }
            else if(vy[i][j][k]<0.000000 && Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin){   
           	   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j+1][k]-b1[i][j][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j+1][k]-R[i][j][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j+1][k]-Hg0[i][j][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j+1][k]-HgII[i][j][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j+1][k]-MMHg[i][j][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
            }
            else if(Rini[i][j-1][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin && vy[i][j][k]>=0.000000){
			   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy); 
            }
            else if(Rini[i][j-1][k]<=0.000000 && Rini[i][j][k]>=Rin && Rini[i][j+1][k]>=Rin && vy[i][j][k]<0.000000){
			   flub1y[i][j][k]=vy[i][j][k]*(b1[i][j+1][k]-b1[i][j][k])-1.0*Dyy*((b1[i][j+1][k]-b1[i][j][k])/dy);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j+1][k]-R[i][j][k])-1.0*Dyy*((R[i][j+1][k]-R[i][j][k])/dy);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j+1][k]-Hg0[i][j][k])-1.0*Dyy*((Hg0[i][j+1][k]-Hg0[i][j][k])/dy);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j+1][k]-HgII[i][j][k])-1.0*Dyy*((HgII[i][j+1][k]-HgII[i][j][k])/dy);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j+1][k]-MMHg[i][j][k])-1.0*Dyy*((MMHg[i][j+1][k]-MMHg[i][j][k])/dy);
            }
            else if(Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]<=0.000000 && vy[i][j][k]<=0.000000){
               flub1y[i][j][k]=vy[i][j][k]*(-b1[i][j][k]);
			   fluRy[i][j][k]=vy[i][j][k]*(-R[i][j][k]);
               fluHg0y[i][j][k]=vy[i][j][k]*(-Hg0[i][j][k]);
               fluHgIIy[i][j][k]=vy[i][j][k]*(-HgII[i][j][k]);
               fluMMHgy[i][j][k]=vy[i][j][k]*(-MMHg[i][j][k]);
            }
            else if(Rini[i][j-1][k]>=Rin && Rini[i][j][k]>=Rin && Rini[i][j+1][k]<=0.000000 && vy[i][j][k]>0.000000){
               flub1y[i][j][k]=vy[i][j][k]*(b1[i][j][k]-b1[i][j-1][k]);
			   fluRy[i][j][k]=vy[i][j][k]*(R[i][j][k]-R[i][j-1][k]);
               fluHg0y[i][j][k]=vy[i][j][k]*(Hg0[i][j][k]-Hg0[i][j-1][k]);
               fluHgIIy[i][j][k]=vy[i][j][k]*(HgII[i][j][k]-HgII[i][j-1][k]);
               fluMMHgy[i][j][k]=vy[i][j][k]*(MMHg[i][j][k]-MMHg[i][j-1][k]);
            }
            else{
               flub1y[i][j][k]=0.0;
			   fluRy[i][j][k]=0.0;
               fluHg0y[i][j][k]=0.0;
               fluHgIIy[i][j][k]=0.0;
               fluMMHgy[i][j][k]=0.0;
            }  
      
            }
        }
    }
    
    for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=2; k<=K; k++){ // rispetto allo spazio z	     
       
            if(Rini[i][j][k]==Rbot){
			   fluRz[i][j][k]=0.0;
               fluHg0z[i][j][k]=0.0;
               fluHgIIz[i][j][k]=-1.0*MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k]); // microg/(m^2*h)
               fluMMHgz[i][j][k]=-1.0*MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k]); // microg/(m^2*h)  
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin &&  vz[i][j][k]>=0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k]-R[i][j][k-1])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k]-Hg0[i][j][k-1])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k]-HgII[i][j][k-1])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k]-MMHg[i][j][k-1])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);		   
	        }
	        else if(vz[i][j][k]<0.000000 && Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin){ 
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k+1]-R[i][j][k])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k+1]-Hg0[i][j][k])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k+1]-HgII[i][j][k])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k+1]-MMHg[i][j][k])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
	        }
            else if(Rini[i][j][k-1]<=0.000000 && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && vz[i][j][k]<0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k+1]-R[i][j][k])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k+1]-Hg0[i][j][k])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k+1]-HgII[i][j][k])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k+1]-MMHg[i][j][k])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
            }
            else if(Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && vz[i][j][k]<=0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*((R[i][j][k+1]-R[i][j][k]))-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*((Hg0[i][j][k+1]-Hg0[i][j][k]))-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*((HgII[i][j][k+1]-HgII[i][j][k]))-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*((MMHg[i][j][k+1]-MMHg[i][j][k]))-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && vz[i][j][k]>0.000000){
			   fluRz[i][j][k]=vz[i][j][k]*(R[i][j][k]-R[i][j][k-1])-1.0*Dzz*((R[i][j][k+1]-R[i][j][k])/dz);
               fluHg0z[i][j][k]=vz[i][j][k]*(Hg0[i][j][k]-Hg0[i][j][k-1])-1.0*Dzz*((Hg0[i][j][k+1]-Hg0[i][j][k])/dz);
               fluHgIIz[i][j][k]=vz[i][j][k]*(HgII[i][j][k]-HgII[i][j][k-1])-1.0*Dzz*((HgII[i][j][k+1]-HgII[i][j][k])/dz);
               fluMMHgz[i][j][k]=vz[i][j][k]*(MMHg[i][j][k]-MMHg[i][j][k-1])-1.0*Dzz*((MMHg[i][j][k+1]-MMHg[i][j][k])/dz);
            }
            else{
			   fluRz[i][j][k]=0.0;
               fluHg0z[i][j][k]=0.0;
               fluHgIIz[i][j][k]=0.0;
               fluMMHgz[i][j][k]=0.0;
            }  
             
            }
        }
    } 

    for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y	
           for(k=2; k<=K; k++){ // rispetto allo spazio z	     
       
            if(Rini[i][j][k]==Rbot){
               flub1z[i][j][k]=0.0;
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (v1+vz[i][j][k]>=0.000000)){
			   flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k]-b1[i][j][k-1])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz); 
	        }
	        else if((v1+vz[i][j][k]<0.000000) && Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin){
           	   flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k+1]-1.0*b1[i][j][k])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz);
	        }
            else if(Rini[i][j][k-1]<=0.000000 && Rini[i][j][k]==Rin && Rini[i][j][k+1]>=Rin && (v1+vz[i][j][k]<0.000000)){
			   flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k+1]-1.0*b1[i][j][k])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz);
            }
            else if(Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && (v1+vz[i][j][k]<=0.000000)){
               flub1z[i][j][k]=(v1+vz[i][j][k])*((b1[i][j][k+1]-b1[i][j][k]))-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz);
            }
            else if(Rini[i][j][k-1]==Rin && Rini[i][j][k]==Rin && Rini[i][j][k+1]==Rbot && Rini[i][j][k+2]<=0.000000 && (v1+vz[i][j][k]>0.000000)){
                flub1z[i][j][k]=(v1+vz[i][j][k])*(b1[i][j][k]-b1[i][j][k-1])-1.0*Dzz*((b1[i][j][k+1]-b1[i][j][k])/dz); 
            }
            else{
               flub1z[i][j][k]=0.0;
            }  

            }
        }
    }

 //%%%%%%%%%%%%%%%%%%%%%Queste subroutine dipendono dalla forma e dal posizionamento degli inlets dei SIN %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
   
   for(k=1; k<=klev; k++){ // rispetto allo spazio z
   
      if(k==1){
               
            if(vx[I][L][k]<=0.000000){
               sumfluHg0x[I][L]=vx[I][L][k]*(0.2*DHgexts27)-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]=(vx[I][L][k]*(0.794*DHgexts27)-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluMMHgx[I][L]=(vx[I][L][k]*(0.006*DHgexts27)-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluTHgx[I][L]=vx[I][L][k]*(THgexts27)-1.0*Dxx*((THgexts27-THg[I][L][k])/dx);
            }
            else{                                       
               sumfluHg0x[I][L]=vx[I][L][k]*(Hg0[I][L][k])-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]=(vx[I][L][k]*(HgII[I][L][k])-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluMMHgx[I][L]=(vx[I][L][k]*(MMHg[I][L][k])-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluTHgx[I][L]=vx[I][L][k]*(THg[I][L][k])-1.0*Dxx*((THgexts27-THg[I][L][k])/dx); 
            }   
            
      }
      else{
           
            if(vx[I][L][k]<=0.000000){
               sumfluHg0x[I][L]+=vx[I][L][k]*(0.2*DHgexts27)-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]+=(vx[I][L][k]*(0.794*DHgexts27)-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluMMHgx[I][L]+=(vx[I][L][k]*(0.006*DHgexts27)-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluTHgx[I][L]+=vx[I][L][k]*(THgexts27)-1.0*Dxx*((THgexts27-THg[I][L][k])/dx);
            }
            else{                                       
               sumfluHg0x[I][L]+=vx[I][L][k]*(Hg0[I][L][k])-1.0*Dxx*((0.2*DHgexts27-Hg0[I][L][k])/dx);
               sumfluHgIIx[I][L]+=(vx[I][L][k]*(HgII[I][L][k])-1.0*Dxx*((0.794*DHgexts27-HgII[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluMMHgx[I][L]+=(vx[I][L][k]*(MMHg[I][L][k])-1.0*Dxx*((0.006*DHgexts27-MMHg[I][L][k])/dx))*(1.0+kDSPM0*SPM[I][L][k]);
               sumfluTHgx[I][L]+=vx[I][L][k]*(THg[I][L][k])-1.0*Dxx*((THgexts27-THg[I][L][k])/dx);
            }  
            
      }
   
   }
   
   fluHg0xlev=Llev*sumfluHg0x[I][L]*dz;
   fluHgIIxlev=Llev*sumfluHgIIx[I][L]*dz;
   fluMMHgxlev=Llev*sumfluMMHgx[I][L]*dz;
   fluTHgxlev=Llev*sumfluTHgx[I][L]*dz;
   
 
   for(k=1; k<=ksci; k++){ // rispetto allo spazio z
   
      if(k==1){
               
            if(vy[C][J][k]<=0.000000){
               sumfluHg0y[C][J]=vy[C][J][k]*(0.2*DHgextb26)-1.0*Dyy*((0.2*DHgextb26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]=(vy[C][J][k]*(0.794*DHgextb26)-1.0*Dyy*((0.794*DHgextb26-HgII[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgy[C][J]=(vy[C][J][k]*(0.006*DHgextb26)-1.0*Dyy*((0.006*DHgextb26-MMHg[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgy[C][J]=vy[C][J][k]*(THgexts26)-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);
            }
            else{                                       
               sumfluHg0y[C][J]=vy[C][J][k]*(Hg0[C][J][k])-1.0*Dyy*((0.2*DHgextm26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]=(vy[C][J][k]*(HgII[C][J][k])-1.0*Dyy*((0.794*DHgextm26-HgII[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgy[C][J]=(vy[C][J][k]*(MMHg[C][J][k])-1.0*Dyy*((0.006*DHgextm26-MMHg[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgy[C][J]=vy[C][J][k]*(THg[C][J][k])-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);  
            }  
               
            if(vx[C][J][k]<=0.000000){
               sumfluHg0xs[C][J]=vx[C][J][k]*(Hg0[C+1][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]=(vx[C][J][k]*(HgII[C+1][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgxs[C][J]=(vx[C][J][k]*(MMHg[C+1][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgxs[C][J]=vx[C][J][k]*(THg[C+1][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
            else{                                       
               sumfluHg0xs[C][J]=vx[C][J][k]*(Hg0[C][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]=(vx[C][J][k]*(HgII[C][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgxs[C][J]=(vx[C][J][k]*(MMHg[C][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgxs[C][J]=vx[C][J][k]*(THg[C][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
            
      }
      else{
           
            if(vy[C][J][k]<=0.000000){
               sumfluHg0y[C][J]+=vy[C][J][k]*(0.2*DHgextb26)-1.0*Dyy*((0.2*DHgextb26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]+=(vy[C][J][k]*(0.794*DHgextb26)-1.0*Dyy*((0.794*DHgextb26-HgII[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgy[C][J]+=(vy[C][J][k]*(0.006*DHgextb26)-1.0*Dyy*((0.006*DHgextb26-MMHg[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgy[C][J]+=vy[C][J][k]*(THgexts26)-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);
            }
            else{                                       
               sumfluHg0y[C][J]+=vy[C][J][k]*(Hg0[C][J][k])-1.0*Dyy*((0.2*DHgextm26-Hg0[C][J][k])/dy);
               sumfluHgIIy[C][J]+=(vy[C][J][k]*(HgII[C][J][k])-1.0*Dyy*((0.794*DHgextm26-HgII[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgy[C][J]+=(vy[C][J][k]*(MMHg[C][J][k])-1.0*Dyy*((0.006*DHgextm26-MMHg[C][J][k])/dy))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgy[C][J]+=vy[C][J][k]*(THg[C][J][k])-1.0*Dyy*((THgexts26-THg[C][J][k])/dy);
            }  
               
            if(vx[C][J][k]<=0.000000){
               sumfluHg0xs[C][J]+=vx[C][J][k]*(Hg0[C+1][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]+=(vx[C][J][k]*(HgII[C+1][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgxs[C][J]+=(vx[C][J][k]*(MMHg[C+1][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgxs[C][J]+=vx[C][J][k]*(THg[C+1][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
            else{                                       
               sumfluHg0xs[C][J]+=vx[C][J][k]*(Hg0[C][J][k])-1.0*Dxx*((Hg0[C+1][J][k]-Hg0[C][J][k])/dx);
               sumfluHgIIxs[C][J]+=(vx[C][J][k]*(HgII[C][J][k])-1.0*Dxx*((HgII[C+1][J][k]-HgII[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluMMHgxs[C][J]+=(vx[C][J][k]*(MMHg[C][J][k])-1.0*Dxx*((MMHg[C+1][J][k]-MMHg[C][J][k])/dx))*(1.0+kDSPM0*SPM[C][J][k]);
               sumfluTHgxs[C][J]+=vx[C][J][k]*(THg[C][J][k])-1.0*Dxx*((THg[C+1][J][k]-THg[C][J][k])/dx);
            }
      }
      
   }
   
   fluHg0ysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHg0y[C][J]*dz;
   fluHgIIysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHgIIy[C][J]*dz;
   fluMMHgysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluMMHgy[C][J]*dz;
   fluTHgysci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluTHgy[C][J]*dz;
   fluHg0xsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHg0xs[C][J]*dz;
   fluHgIIxsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluHgIIxs[C][J]*dz;
   fluMMHgxsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluMMHgxs[C][J]*dz;
   fluTHgxsci=Lsci*cos((3.14159265*45.0)/180.0)*sumfluTHgxs[C][J]*dz;
   
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluxHgIIsed[i][j] = MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*24.0; // microg/m^2*d
               fluxMMHgsed[i][j] = MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*24.0; // microg/m^2*d    
           }
            
           }
       }
   }
   
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][1]>=Rin){
               fluxHg0atm[i][j] = -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0); // ng/m^2*h
               fluxHg0dep[i][j] = Hggas*(Pr/det); // ng/m^2*h
               fluxHgIIdep[i][j] = HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0); // ng/m^2*h  
               fluxMMHgdep[i][j] = 0.005025*(HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0)); //MMHgatm*(Pr/det); // ng/m^2*h 
           }
           else{
               fluxHg0atm[i][j] = 0.0; // ng/m^2*h
               fluxHg0dep[i][j] = 0.0; // ng/m^2*h
               fluxHgIIdep[i][j] = 0.0; // ng/m^2*h
               fluxMMHgdep[i][j] = 0.0; // ng/m^2*h
           }

           }
       }
   }
  
    if(n==1 || n==3 || n==5 || n==7 || n==8 || n==10 || n==13 || n==25 || n==50 || n==75 || n==100 || n==150 || n==200 || n==N){
     for(i=1; i<=I; i++){
        for(j=1; j<=J; j++){
                 
           if(m%tempo==0){  
                 fprintf(fHgIIfluxsed,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHgIIsed[i][j]);
                 fprintf(fMMHgfluxsed,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxMMHgsed[i][j]); 
                 fprintf(fHg0fluxatm,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHg0atm[i][j]);
                 fprintf(fHg0fluxdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHg0dep[i][j]);
                 fprintf(fHgIIfluxdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxHgIIdep[i][j]);
                 fprintf(fMMHgfluxdep,"%f\t%f\t%f\t%f\n", (m+M*(n-1))*dt, (i-1)*dx, (j-1)*dy, fluxMMHgdep[i][j]);
           }      
                  
        }
     }
  }   
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queste variabili dipendono dalla forma del bacino%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
   
    fluHgIIzsed=0.0;
    fluMMHgzsed=0.0;
    fluHgIIzbur=0.0;
    fluMMHgzbur=0.0;
    fluHgIIzbur2=0.0;
    fluMMHgzbur2=0.0;
    fluHgIIzsedext1=0.0;
    fluMMHgzsedext1=0.0;
    fluHgIIzburext1=0.0;
    fluMMHgzburext1=0.0;
    fluHgIIzburext12=0.0;
    fluMMHgzburext12=0.0;
    fluHgIIzsedext2=0.0;
    fluMMHgzsedext2=0.0;
    fluHgIIzburext2=0.0;
    fluMMHgzburext2=0.0;
    fluHgIIzburext22=0.0;
    fluMMHgzburext22=0.0;
    fluHgIIzsedext3=0.0;
    fluMMHgzsedext3=0.0;
    fluHgIIzburext3=0.0;
    fluMMHgzburext3=0.0;
    fluHgIIzburext32=0.0;
    fluMMHgzburext32=0.0;
    
    fluxHg0zatm=0.0;
    fluxHg0zdep=0.0;
    fluxHgIIzdep=0.0;
    fluxMMHgzdep=0.0;
    fluxHg0zatmext1=0.0;
    fluxHg0zdepext1=0.0;
    fluxHgIIzdepext1=0.0;
    fluxMMHgzdepext1=0.0;
    fluxHg0zatmext2=0.0;
    fluxHg0zdepext2=0.0;
    fluxHgIIzdepext2=0.0;
    fluxMMHgzdepext2=0.0;
    fluxHg0zatmext3=0.0;
    fluxHg0zdepext3=0.0;
    fluxHgIIzdepext3=0.0;
    fluxMMHgzdepext3=0.0;
    
    
   for(i=1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluHgIIzsed += MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*dx*dy; // microg/h
               fluMMHgzsed += MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*dx*dy; // microg/h   
               fluHgIIzbur += THgsed[i][j][1]*(1.0-kMM)*(1.0-porsed[i][j][1])*SDsed*dep[i][j]*pow(10.0,6.0)*dx*dy; // microg/h
               fluMMHgzbur += THgsed[i][j][1]*kMM*(1.0-porsed[i][j][1])*SDsed*dep[i][j]*pow(10.0,6.0)*dx*dy; // microg/h
               fluHgIIzbur2 += NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*HgII[i][j][k]*dx*dy; //microg/h
               fluMMHgzbur2 += NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*MMHg[i][j][k]*dx*dy; //microg/h
           }
           else{
               fluHgIIzsed += 0.0;
               fluMMHgzsed += 0.0;
               fluHgIIzbur += 0.0; // microg/h
               fluMMHgzbur += 0.0; // microg/h
               fluHgIIzbur2 += 0.0; // microg/h
               fluMMHgzbur2 += 0.0; // microg/h
           } 
           
           if(Rini[i][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatm += -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdep += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdep += (HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h  
               fluxMMHgzdep += 0.005025*(HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h 
           }
           else{
               fluxHg0zatm += 0.0; // ng/h
               fluxHg0zdep += 0.0; // ng/h
               fluxHgIIzdep += 0.0; // ng/h
               fluxMMHgzdep += 0.0; // ng/h
           }
           
           }
       }
   }
   
   
   for(i=iext1; i<=I; i++){ // rispetto allo spazio x
       for(j=1; j<=jext1; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluHgIIzsedext1 += MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*dx*dy; // microg/h
               fluMMHgzsedext1 += MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*dx*dy; // microg/h 
               fluHgIIzburext1 += THgsed[i][j][1]*(1.0-kMM)*(1.0-porsed[i][j][1])*SDsed*dep[i][j]*pow(10.0,6.0)*dx*dy;//+HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzburext1 += THgsed[i][j][1]*kMM*(1.0-porsed[i][j][1])*SDsed*dep[i][j]*pow(10.0,6.0)*dx*dy;//+MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluHgIIzburext12 += NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*HgII[i][j][k]*dx*dy; //microg/h
               fluMMHgzburext12 += NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*MMHg[i][j][k]*dx*dy; //microg/h
           }
           else{
               fluHgIIzsedext1 += 0.0;
               fluMMHgzsedext1 += 0.0;
               fluHgIIzburext1 += 0.0; // microg/h
               fluMMHgzburext1 += 0.0; // microg/h
               fluHgIIzburext12 += 0.0; //microg/h
               fluMMHgzburext12 += 0.0; //microg/h
           }
           
           if(Rini[i][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatmext1 += -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdepext1 += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdepext1 += (HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h  
               fluxMMHgzdepext1 += 0.005025*(HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h 
           }
           else{
               fluxHg0zatmext1 += 0.0; // ng/h
               fluxHg0zdepext1 += 0.0; // ng/h
               fluxHgIIzdepext1 += 0.0; // ng/h
               fluxMMHgzdepext1 += 0.0; // ng/h
           }
           
           }
       }
   }
   
   for(i=iext2; i<=I; i++){ // rispetto allo spazio x
       for(j=jext2; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[i][j][k]==Rbot){  
               fluHgIIzsedext2 += MTCIIsw[i][j]*(HgIIpw[i][j][1]-HgII[i][j][k])*dx*dy; // microg/h
               fluMMHgzsedext2 += MTCMMsw[i][j]*(MMHgpw[i][j][1]-MMHg[i][j][k])*dx*dy; // microg/h 
               fluHgIIzburext2 += THgsed[i][j][1]*(1.0-kMM)*(1.0-porsed[i][j][1])*SDsed*dep[i][j]*pow(10.0,6.0)*dx*dy;//+HgIIpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluMMHgzburext2 += THgsed[i][j][1]*kMM*(1.0-porsed[i][j][1])*SDsed*dep[i][j]*pow(10.0,6.0)*dx*dy;//+MMHgpw[i][j][1]*porsed[i][j][1]*dep[i][j]*dx*dy; // microg/h
               fluHgIIzburext22 += NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*HgII[i][j][k]*dx*dy; //microg/h
               fluMMHgzburext22 += NPP[i][j][k]*peratio[i][j][k]*(kD0/forg[i][j][k])*pow(10,-6.0)*MMHg[i][j][k]*dx*dy; //microg/h
           }
           else{
               fluHgIIzsedext2 += 0.0;
               fluMMHgzsedext2 += 0.0;
               fluHgIIzburext2 += 0.0; // microg/h
               fluMMHgzburext2 += 0.0; // microg/h
               fluHgIIzburext22 += 0.0; //microg/h
               fluMMHgzburext22 += 0.0; //microg/h
           } 
           
           if(Rini[i][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatmext2 += -1.0*MTCwa[i][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[i][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdepext2 += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdepext2 += (HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h  
               fluxMMHgzdepext2 += 0.005025*(HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h 
           }
           else{
               fluxHg0zatmext2 += 0.0; // ng/h
               fluxHg0zdepext2 += 0.0; // ng/h
               fluxHgIIzdepext2 += 0.0; // ng/h
               fluxMMHgzdepext2 += 0.0; // ng/h
           }
           
           }
       }
   }
   
       for(j=jext3; j<=J; j++){ // rispetto allo spazio y
           for(k=1; k<=K; k++){ // rispetto allo spazio y
       
           if(Rini[H][j][k]==Rbot){  
               fluHgIIzsedext3 += MTCIIsw[H][j]*(HgIIpw[H][j][1]-HgII[H][j][k])*dx*dy; // microg/h
               fluMMHgzsedext3 += MTCMMsw[H][j]*(MMHgpw[H][j][1]-MMHg[H][j][k])*dx*dy; // microg/h   
               fluHgIIzburext3 += THgsed[H][j][1]*(1.0-kMM)*(1.0-porsed[H][j][1])*SDsed*dep[H][j]*pow(10.0,6.0)*dx*dy;//+HgIIpw[H][j][1]*porsed[H][j][1]*dep[H][j]*dx*dy; // microg/h
               fluMMHgzburext3 += THgsed[H][j][1]*kMM*(1.0-porsed[H][j][1])*SDsed*dep[H][j]*pow(10.0,6.0)*dx*dy;//+MMHgpw[H][j][1]*porsed[H][j][1]*dep[H][j]*dx*dy; // microg/h
               fluHgIIzburext32 += NPP[H][j][k]*peratio[H][j][k]*(kD0/forg[H][j][k])*pow(10,-6.0)*HgII[H][j][k]*dx*dy; //microg/h
               fluMMHgzburext32 += NPP[H][j][k]*peratio[H][j][k]*(kD0/forg[H][j][k])*pow(10,-6.0)*MMHg[H][j][k]*dx*dy; //microg/h
           }
           else{
               fluHgIIzsedext3 += 0.0;
               fluMMHgzsedext3 += 0.0;
               fluHgIIzburext3 += 0.0; // microg/h
               fluMMHgzburext3 += 0.0; // microg/h
               fluHgIIzburext32 += 0.0; //microg/h
               fluMMHgzburext32 += 0.0; //microg/h
           } 
            
           if(Rini[H][j][1]>=Rin && Rini[i][j][k]==Rbot){
               fluxHg0zatmext3 += -1.0*MTCwa[H][j]*(Hggas*pow(10.0,-3.0)-H1*Hg0[H][j][1])*pow(10.0,3.0)*dx*dy; // ng/h
               fluxHg0zdepext3 += Hggas*(Pr/det)*dx*dy; // ng/h
               fluxHgIIzdepext3 += (HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h  
               fluxMMHgzdepext3 += 0.005025*(HgIIatm*(Pr/det)+DrydepHgII*pow(10.0,3.0))*dx*dy; // ng/h 
           }
           else{
               fluxHg0zatmext3 += 0.0; // ng/h
               fluxHg0zdepext3 += 0.0; // ng/h
               fluxHgIIzdepext3 += 0.0; // ng/h
               fluxMMHgzdepext3 += 0.0; // ng/h
           }
            
           }
       }
   
   TotfluHg0xlev += fluHg0xlev*dt*pow(10,-9.0)*(1.0/PMHg0);
   TotfluHgIIxlev += fluHgIIxlev*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgxlev += fluMMHgxlev*dt*pow(10,-9.0)*(1.0/PMMMHg);
   Totlev += fluTHgxlev*dt*pow(10,-9.0)*(1.0/PMHgII);
   
   TotfluHg0xysci += (fluHg0ysci+fluHg0xsci)*dt*pow(10,-9.0)*(1.0/PMHg0);
   TotfluHgIIxysci += (fluHgIIysci+fluHgIIxsci)*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgxysci += (fluMMHgysci+fluMMHgxsci)*dt*pow(10,-9.0)*(1.0/PMMMHg);
   Totsci += (fluTHgysci+fluTHgxsci)*dt*pow(10,-9.0)*(1.0/PMHgII);
   
   TotfluHgIIzsed += fluHgIIzsed*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsed += fluMMHgzsed*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzbur += fluHgIIzbur*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzbur += fluMMHgzbur*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzbur2 += fluHgIIzbur2*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzbur2 += fluMMHgzbur2*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzsedext1 += fluHgIIzsedext1*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsedext1 += fluMMHgzsedext1*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext1 += fluHgIIzburext1*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext1 += fluMMHgzburext1*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext12 += fluHgIIzburext12*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext12 += fluMMHgzburext12*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzsedext2 += fluHgIIzsedext2*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsedext2 += fluMMHgzsedext2*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext2 += fluHgIIzburext2*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext2 += fluMMHgzburext2*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext22 += fluHgIIzburext22*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext22 += fluMMHgzburext22*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzsedext3 += fluHgIIzsedext3*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzsedext3 += fluMMHgzsedext3*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext3 += fluHgIIzburext3*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext3 += fluMMHgzburext3*dt*pow(10,-9.0)*(1.0/PMMMHg);
   TotfluHgIIzburext32 += fluHgIIzburext32*dt*pow(10,-9.0)*(1.0/PMHgII);
   TotfluMMHgzburext32 += fluMMHgzburext32*dt*pow(10,-9.0)*(1.0/PMMMHg);
   
   TotfluHg0zatm += fluxHg0zatm*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdep += fluxHg0zdep*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdep += fluxHgIIzdep*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdep += fluxMMHgzdep*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluHg0zatmext1 += fluxHg0zatmext1*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdepext1 += fluxHg0zdepext1*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdepext1 += fluxHgIIzdepext1*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdepext1 += fluxMMHgzdepext1*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluHg0zatmext2 += fluxHg0zatmext2*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdepext2 += fluxHg0zdepext2*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdepext2 += fluxHgIIzdepext2*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdepext2 += fluxMMHgzdepext2*dt*pow(10,-12.0)*(1.0/PMMMHg);
   TotfluHg0zatmext3 += fluxHg0zatmext3*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHg0zdepext3 += fluxHg0zdepext3*dt*pow(10,-12.0)*(1.0/PMHg0);
   TotfluHgIIzdepext3 += fluxHgIIzdepext3*dt*pow(10,-12.0)*(1.0/PMHgII);
   TotfluMMHgzdepext3 += fluxMMHgzdepext3*dt*pow(10,-12.0)*(1.0/PMMMHg);
   
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
 }
 
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queste variabili dipendono dalla forma del bacino%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
 
   TotHgIIsed=TotfluHgIIzsed-TotfluHgIIzsedext1-TotfluHgIIzsedext2-TotfluHgIIzsedext3;
   TotMMHgsed=TotfluMMHgzsed-TotfluMMHgzsedext1-TotfluMMHgzsedext2-TotfluMMHgzsedext3;
   TotHgsed=TotHgIIsed+TotMMHgsed;
   TotHgIIbur=TotfluHgIIzbur-TotfluHgIIzburext1-TotfluHgIIzburext2-TotfluHgIIzburext3;
   TotMMHgbur=TotfluMMHgzbur-TotfluMMHgzburext1-TotfluMMHgzburext2-TotfluMMHgzburext3;
   TotHgIIbur2=TotfluHgIIzbur2-TotfluHgIIzburext12-TotfluHgIIzburext22-TotfluHgIIzburext32;
   TotMMHgbur2=TotfluMMHgzbur2-TotfluMMHgzburext12-TotfluMMHgzburext22-TotfluMMHgzburext32;
   TotHgbur=TotHgIIbur+TotMMHgbur;
   TotHgbur2=TotHgIIbur2+TotMMHgbur2;
   TotfluHg0atm=TotfluHg0zatm-TotfluHg0zatmext1-TotfluHg0zatmext2-TotfluHg0zatmext3;
   TotfluHg0dep=TotfluHg0zdep-TotfluHg0zdepext1-TotfluHg0zdepext2-TotfluHg0zdepext3;
   TotfluHgIIdep=TotfluHgIIzdep-TotfluHgIIzdepext1-TotfluHgIIzdepext2-TotfluHgIIzdepext3;
   TotfluMMHgdep=TotfluMMHgzdep-TotfluMMHgzdepext1-TotfluMMHgzdepext2-TotfluMMHgzdepext3;
   TotfluHgdep=TotfluHg0dep+TotfluHgIIdep+TotfluMMHgdep;

 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   
   
   fprintf(fu,"  Hg0lev        HgIIlev        MMHglev         Totlev         Hg0sci         HgIIsci         MMHgsci         Totsci \n");
   fprintf(fu, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", TotfluHg0xlev, TotfluHgIIxlev, TotfluMMHgxlev, Totlev, TotfluHg0xysci, TotfluHgIIxysci, TotfluMMHgxysci,Totsci);
   fprintf(fu,"  TotHgIIsed       TotMMHgsed       TotHgsed       TotHgIIbur       TotMMHgbur       TotHgbur \n");
   fprintf(fu, "%f\t%f\t%f\t%f\t%f\t%f\n", TotHgIIsed, TotMMHgsed, TotHgsed, TotHgIIbur, TotMMHgbur, TotHgbur);
   fprintf(fu,"  TotSIIDOM      TotSMMDOM      TotHgIISPM      TotMMHgSPM \n");
   fprintf(fu, "%f\t%f\t%f\t%f\n", TotSIIDOM, TotSMMDOM, TotSIISPM, TotSMMSPM);
   fprintf(fu,"  TotfluHg0atm  TotfluHg0dep   TotfluHgIIdep  TotfluMMHgdep   TotfluHgdep\n");
   fprintf(fu, "%f\t%f\t%f\t%f\t%f\n", TotfluHg0atm, TotfluHg0dep, TotfluHgIIdep,TotfluMMHgdep,TotfluHgdep);
   fprintf(fRelease, "%i\t%f\t%f\t%f\n", n+2004, TotHgIIsed, TotMMHgsed, TotHgsed);
   fprintf(fOutflow, "%i\t%f\t%f\t%f\t%f\t%f\t%f\n", n+2004, Totlev, Totsci, Totlev+Totsci, TotfluMMHgxlev,  TotfluMMHgxysci, TotfluMMHgxlev+TotfluMMHgxysci);
   fprintf(fEvasion, "%i\t%f\t%f\t%f\t%f\n", n+2004, TotfluHg0atm, TotfluHgdep, TotfluMMHgdep, TotfluHg0atm-TotfluHgdep);
   fprintf(fRecycled, "%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", n+2004, TotHgsed-Totlev-Totsci-TotfluHg0atm+TotfluHgdep, TotHgbur, TotSIISPM+TotSMMSPM, TotMMHgbur, TotSMMSPM, TotHgbur2, TotMMHgbur2);

 }  
  
   fprintf(fFisptmean,"HgII phyto (mg/Kg) MMHg phyto (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", PhyHgIIsptmean, PhyMMHgsptmean);
   fprintf(fFisptmean,"HgII Bivalvia (mg/Kg) MMHg Bivalvia (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZbivHgIIsptmean, ZbivMMHgsptmean);
   fprintf(fFisptmean,"HgII Polychaeta (mg/Kg) MMHg Polychaeta (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZpolHgIIsptmean, ZpolMMHgsptmean);
   fprintf(fFisptmean,"HgII Amphipoda (mg/Kg) MMHg Amphipoda (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZampHgIIsptmean, ZampMMHgsptmean);
   fprintf(fFisptmean,"HgII Decapoda (mg/Kg) MMHg Decapoda (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZdecHgIIsptmean, ZdecMMHgsptmean);
   fprintf(fFisptmean,"HgII Mysidacea (mg/Kg) MMHg Mysidacea (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZmysHgIIsptmean, ZmysMMHgsptmean);
   fprintf(fFisptmean,"HgII Osteichthyes (mg/Kg) MMHg Osteichthyes (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZostHgIIsptmean, ZostMMHgsptmean);
   fprintf(fFisptmean,"HgII Mullus (mg/Kg) MMHg Mullus (mg/Kg) Wfish AGE1 (Kg)\n");
   fprintf(fFisptmean, "%f\t%f\t%f\n", FiHgIIsptmean, FiMMHgsptmean, WfishAGE1);
   fprintf(fFisptmean,"HgII phyto (mg/Kg) MMHg phyto (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", PhyHgIIsptmean2, PhyMMHgsptmean2);
   fprintf(fFisptmean,"HgII Bivalvia (mg/Kg) MMHg Bivalvia (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZbivHgIIsptmean2, ZbivMMHgsptmean2);
   fprintf(fFisptmean,"HgII Polychaeta (mg/Kg) MMHg Polychaeta (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZpolHgIIsptmean2, ZpolMMHgsptmean2);
   fprintf(fFisptmean,"HgII Amphipoda (mg/Kg) MMHg Amphipoda (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZampHgIIsptmean2, ZampMMHgsptmean2);
   fprintf(fFisptmean,"HgII Decapoda (mg/Kg) MMHg Decapoda (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZdecHgIIsptmean2, ZdecMMHgsptmean2);
   fprintf(fFisptmean,"HgII Mysidacea (mg/Kg) MMHg Mysidacea (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZmysHgIIsptmean2, ZmysMMHgsptmean2);
   fprintf(fFisptmean,"HgII Osteichthyes (mg/Kg) MMHg Osteichthyes (mg/Kg)\n");
   fprintf(fFisptmean, "%f\t%f\n", ZostHgIIsptmean2, ZostMMHgsptmean2);
   fprintf(fFisptmean,"HgII Mullus (mg/Kg) MMHg Mullus (mg/Kg) Wfish AGE2 (Kg)\n");
   fprintf(fFisptmean, "%f\t%f\t%f\n", FiHgIIsptmean2, FiMMHgsptmean2, WfishAGE2);

   fclose(fb1);
   fclose(fct);
   fclose(fR);
   fclose(fI);
   fclose(fHg0);
   fclose(fHgII);
   fclose(fMMHg);
   fclose(fDHg);
   fclose(fTHg);
   fclose(fHgIIpw);
   fclose(fMMHgpw);
   fclose(fHgIIfluxsed);
   fclose(fMMHgfluxsed);
   fclose(fHg0fluxatm);
   fclose(fHg0fluxdep);
   fclose(fHgIIfluxdep);
   fclose(fMMHgfluxdep);
   fclose(fu);
   fclose(fRelease);
   fclose(fOutflow);
   fclose(fEvasion);
   fclose(fRecycled);
   fclose(fP);
   fclose(fPhy);
   fclose(fZbiv);
   fclose(fZpol);
   fclose(fZamp);
   fclose(fZdec);
   fclose(fZmys);
   fclose(fZost);
   fclose(fFi);
   fclose(fFisptmean);
   fclose(fRin1);
   fclose(fSPMin1);
   fclose(fSPOMin1);
   fclose(fRin2);
   fclose(fSPMin2);
   fclose(fSPOMin2);
   fclose(fRin3);
   fclose(fSPMin3);
   fclose(fSPOMin3);
   fclose(fRin4);
   fclose(fSPMin4);
   fclose(fSPOMin4);
   fclose(fRin5);
   fclose(fSPMin5);
   fclose(fSPOMin5);
   fclose(fRin6);
   fclose(fSPMin6);
   fclose(fSPOMin6);
   fclose(fTHgsedin);
   fclose(fTHgsedin2);
   fclose(fTHgsedin3);
   fclose(fTHgsedin4);
   fclose(fTHgsedin5);
   fclose(fTHgsedin6);
   fclose(fTHgsedin7);
   fclose(fTHgsedin8);
   fclose(fTHgsedin9);
   fclose(fTHgsedin10);
   fclose(fTHgsed);
   fclose(ftotdep);
   fclose(fSWsed);
   fclose(fporsed);
   fclose(fporsed2);
   fclose(fporsed3);
   fclose(fporsed4);
   fclose(fporsed5);
   fclose(fporsed6);
   fclose(fporsed7);
   fclose(fporsed8);
   fclose(fporsed9);
   fclose(fporsed10);
   fclose(fIin);
   fclose(fTatm);
   fclose(fPrec);
   fclose(fHgIIatm);
   fclose(fHggas);
   fclose(fv5);
   fclose(fv10);
   fclose(fv20);
   fclose(fv30);
   fclose(fero);
   fclose(fero2);
}
