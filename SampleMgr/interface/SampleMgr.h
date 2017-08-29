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
            SampleMgr(TChain* );
            ~SampleMgr();
            void SetIndex(const int&);

/*******************************************************************************
*  Return file info
*******************************************************************************/
            int GetEntries();
            void GetEntry(const int&);
    
            int    Vsize();
            int    Lsize();
            int    Jsize();
            int    Gsize();
            int    Lep_Type();
            int    RunNO();
            int    LumiNO();

/*******************************************************************************
*   Common calculation
*******************************************************************************/
            double RelIsoR04();
            TLorentzVector GetMET(const TLorentzVector);
            double  Phi_mpi_pi(double);
            bool isIsoLepton(const int&, const int&);
            TLorentzVector getLorentzVector(const std::string&, const int&);

/*******************************************************************************
*   Vertex & HLT selection
*******************************************************************************/
            bool passHLT(std::vector<int>) ;    
            bool IsFake();
            bool IsOfflinePV();
            bool passNdof();
            bool passAbsZ();
            bool passRho();

/*******************************************************************************
*   Muon selection
*******************************************************************************/
            bool passMuPt(double);
            bool passMuEta(double);
            bool passMuRelIsoR04(double);
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
            bool passElPt(double);
            bool passElEta(double);
            bool passElIDLoose();
            bool passElIDTight();

/*******************************************************************************
* Jet selection
*******************************************************************************/
            bool passJetPt(double);
            bool passJetEta(double);
            bool JetNConstituents();
            bool JetNEF();
            bool JetNHF();
            bool JetCHF();
            bool JetNCH();
            bool JetCEF();

            //b-tagging
            bool JetCSVM();

/*******************************************************************************
*   MC Truth
*******************************************************************************/
            int     MatchGenlevel(const float&, const float&);
            int     GetDirectMother(const int&);
            int     GetGenPdgID(const int&);
            int     GetLepCharge(const int&);
            int     DeltaR_jet(const int&);
            int     DeltaR_lep(const int&);
            int     GetDirectMotherPdgID(const int&);
            void    MCTruthBJet(std::vector<int>&);
            bool    HasCommonMo(const int&, const int&, const int&);

        private:
            
            int _idx;
            TChain* _ch;
            VertexInfo _vtx;
            LeptonInfo _lep;
            EvtInfo    _evt;
            JetInfo    _jet;
            GenInfo    _gen;

    }
}
