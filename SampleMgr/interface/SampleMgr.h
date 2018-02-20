#ifndef SAMPLEMGR_H
#define SAMPLEMGR_H

#include "ManagerUtils/SampleMgr/interface/BranchInfo.h"
#include "TChain.h"
#include "TLorentzVector.h"

#include <string>
#include <vector>

namespace mgr{
    class SampleMgr {
        public:

            /*******************************************************************************
            *  Class initialization
            *******************************************************************************/
            SampleMgr( TChain* );
            ~SampleMgr();
            void SetIndex( const int& i ){ _idx = i; }

            /*******************************************************************************
            *  Return file info
            *******************************************************************************/
            int Vsize()   { return _vtx.Size; }
            int Lsize()   { return _lep.Size; }
            int Jsize()   { return _jet.Size; }
            int Gsize()   { return _gen.Size; }
            int Lep_Type(){ return _lep.LeptonType[ _idx ]; }
            int RunNo()   { return _evt.RunNo; }
            int LumiNo()  { return _evt.LumiNo; }

            VertexInfo& Vtx(){ return _vtx; }
            LeptonInfo& Lep(){ return _lep; }
            EvtInfo&    Evt(){ return _evt; }
            JetInfo&    Jet(){ return _jet; }
            GenInfo&    Gen(){ return _gen; }
            /*******************************************************************************
            *   Common calculation
            *******************************************************************************/
            double         RelIsoR04();
            TLorentzVector GetMET( const TLorentzVector& );
            double         Phi_mpi_pi( double );
            bool           isIsoLepton( const int&, const int& );
            TLorentzVector GetLorentzVector( const std::string&, const int& );

            /*******************************************************************************
            *   Vertex & HLT selection
            *******************************************************************************/
            bool passHLT( const std::vector<int>& );
            bool IsFake();
            bool IsOfflinePV();
            bool passNdof();
            bool passAbsZ();
            bool passRho();

            /*******************************************************************************
            *   Muon selection
            *******************************************************************************/
            bool passMuPt( const double& );
            bool passMuEta( const double& );
            bool passMuRelIsoR04( const double& );
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
            bool passElPt( const double& );
            bool passElEta( const double& );
            bool passElIDLoose();
            bool passElIDTight();

            /*******************************************************************************
            * Jet selection
            *******************************************************************************/
            unsigned bitcon( const float x );
            double MakeSmeared();
            TLorentzVector JetP4();

            bool passJetPt( const double& );
            bool passJetEta( const double& );
            bool JetNConstituents();
            bool JetNEF();
            bool JetNHF();
            bool JetCHF();
            bool JetNCH();
            bool JetCEF();
            // b-tagging
            bool JetCSVM( const double& );

            /*******************************************************************************
            *   MC Truth
            *******************************************************************************/
            float GetLepCharge(const int&);
            int GetPartonID( const int&);
            int MCTruthJet( const int&);
            int MatchGenlevel(const float&, const float&);


        private:

            int _idx;
            VertexInfo _vtx;
            LeptonInfo _lep;
            EvtInfo _evt;
            JetInfo _jet;
            GenInfo _gen;

    };
}

#endif
