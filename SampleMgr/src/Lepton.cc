#include "ManagerUtils/SampleMgr/interface/SampleMgr.h"

using namespace std;

namespace mgr{
    /*******************************************************************************
    *  Muon selection info
    *  https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideMuonIdRun2#Tight_Muon
    *  http://cmsdoxygen.web.cern.ch/cmsdoxygen/CMSSW_8_0_11/doc/html/de/d37/DataFormats_2MuonReco_2interface_2Muon_8h_source.html
    *******************************************************************************/

    bool
    SampleMgr::passMuPt( const double& pt )
    {
        return _lep.Pt[ _idx ] > pt;
    }

    bool
    SampleMgr::passMuEta( const double& eta )
    {
        return fabs( _lep.Eta[ _idx ] ) < eta;
    }

    bool
    SampleMgr::passMuRelIsoR04( const double& rel )
    {
        return RelIsoR04() < rel;
    }

    bool
    SampleMgr::MuInnerTrackDxy_PV()
    {
        return fabs( _lep.MuInnerTrackDxy_PV[ _idx ] ) < 0.2;
    }

    bool
    SampleMgr::MuInnerTrackDz()
    {
        return fabs( _lep.MuInnerTrackDz[ _idx ] ) < 0.5;
    }

    // number of muon hits
    bool
    SampleMgr::MuNMuonhits()
    {
        return _lep.MuNMuonhits[ _idx ] > 0;
    }

    // number of matched muon stations
    bool
    SampleMgr::MuNMatchedStations()
    {
        return _lep.MuNMatchedStations[ _idx ] > 1;
    }

    // global normalized chi^2 / dof
    bool
    SampleMgr::MuGlobalNormalizedChi2()
    {
        return _lep.MuGlobalNormalizedChi2[ _idx ] < 10;
    }

    // number of track layers with measurement
    bool
    SampleMgr::MuNTrackLayersWMeasurement()
    {
        return _lep.MuNTrackLayersWMeasurement[ _idx ] > 5;
    }

    bool
    SampleMgr::MuNPixelLayers()
    {
        return _lep.MuNPixelLayers[ _idx ] > 0;
    }

    bool
    SampleMgr::isGlobalMuon()
    {
        return ( _lep.MuType[ _idx ] ) & 0x02;
    }

    bool
    SampleMgr::isTrackerMuon()
    {
        return ( _lep.MuType[ _idx ] ) & 0x04;
    }

    /*******************************************************************************
    *   Electron selection
    *   https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Cut_Based_Electron_ID_for_Run_2
    *   https://github.com/ntuhep/bprimeKit/blob/master/src/LeptonNtuplizer_Electron.cc#L101
    *******************************************************************************/

    bool
    SampleMgr::passElPt( const double& pt )
    {
        return _lep.Pt[ _idx ] > pt;
    }

    bool
    SampleMgr::passElEta( const double& eta )
    {
        if( fabs( _lep.Eta[ _idx ] ) < 1.566 && fabs( _lep.Eta[ _idx ] ) > 1.4442 ){
            return false;
        }

        return _lep.Eta[ _idx ] < eta;
    }

    bool
    SampleMgr::passElIDLoose()
    {
        return _lep.EgammaCutBasedEleIdLOOSE[ _idx ];
    }

    bool
    SampleMgr::passElIDTight()
    {
        return _lep.EgammaCutBasedEleIdTIGHT[ _idx ];
    }
}
