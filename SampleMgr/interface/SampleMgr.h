#ifndef SAMPLEMGR_H
#define SAMPLEMGR_H

#include "ManagerUtils/SampleMgr/interface/BranchInfo.h"
#include "TChain.h"
#include "TLorentzVector.h"

#include <vector>
#include <string>

namespace mgr{
    class SampleMgr {
        public:

/*******************************************************************************
*  Class initialization 
*******************************************************************************/
            SampleMgr();
            SampleMgr(TChain*);
            ~SampleMgr();
            void SetIndex(const int& i){ _idx = i; }
            void SetTChain(TChain*);
/*******************************************************************************
*  Return file info
*******************************************************************************/
    
            int    Vsize(){ return _vtx.Size; }
            int    Lsize(){ return _lep.Size; }
            int    Jsize(){ return _jet.Size; }
            int    Gsize(){ return _gen.Size; }
            int    Lep_Type(){ return _lep.LeptonType[_idx]; }
            int    RunNo(){ return _evt.RunNo; }
            int    LumiNo(){ return _evt.LumiNo; }

/*******************************************************************************
*   Common calculation
*******************************************************************************/
            double RelIsoR04();
            TLorentzVector GetMET(const TLorentzVector&);
            double  Phi_mpi_pi(double);
            bool isIsoLepton(const int&, const int&);
            TLorentzVector getLorentzVector(const std::string&, const int&);

/*******************************************************************************
*   Vertex & HLT selection
*******************************************************************************/
            bool passHLT(const std::vector<int>&) ;    
            bool IsFake();
            bool IsOfflinePV();
            bool passNdof();
            bool passAbsZ();
            bool passRho();

/*******************************************************************************
*   Muon selection
*******************************************************************************/
            bool passMuPt(const double&);
            bool passMuEta(const double&);
            bool passMuRelIsoR04(const double&);
            bool MuInnerTrackDxy_PV();
            bool MuInnerTrackDz();
            bool MuNMuonhits();
            bool MuNMatchedStations();
            bool MuGlobalNormalizedChi2();
            bool MuNTrackLayersWMeasurement();
            bool MuNPixelLayers();
            bool isGlobalMuon();
            bool isTrackerMuon();

/*******************************************************************************
* Electron selection
*******************************************************************************/
            bool passElPt(const double&);
            bool passElEta(const double&);
            bool passElIDLoose();
            bool passElIDTight();

/*******************************************************************************
* Jet selection
*******************************************************************************/
            bool passJetPt(const double&);
            bool passJetEta(const double&);
            bool JetNConstituents();
            bool JetNEF();
            bool JetNHF();
            bool JetCHF();
            bool JetNCH();
            bool JetCEF();

            //b-tagging
            bool JetCSVM(const double&);

/*******************************************************************************
*   MC Truth
*******************************************************************************/
            int     MatchGenlevel(const float&, const float&);
            //if doesn't match return -1
            int     GetGenLep(const int&);
            int     GetGenJet(const int&);
            int     GetDirectMother(int);
            int     GetGenPdgID(const int&);
            int     GetLepCharge(const int&);
            int     GetDirectMotherPdgID(const int&);
            bool    MCTruthBJet(std::vector<int>&);
            bool    HasCommonMo(const int&, const int&, const int&);

        private:
            
            int _idx;
            VertexInfo _vtx;
            LeptonInfo _lep;
            EvtInfo    _evt;
            JetInfo    _jet;
            GenInfo    _gen;

    };
}

#endif
