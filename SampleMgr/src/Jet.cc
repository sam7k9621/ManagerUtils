#include "ManagerUtils/SampleMgr/interface/SampleMgr.h"
#include <random>
#include <iostream>
using namespace std;

namespace mgr{
    /*******************************************************************************
    * Jet selection
    *******************************************************************************/
    unsigned
    bitconv( const float x )
    {
        const void* temp = &x;
        return *( (const unsigned*)( temp ) );
    }

    double
    SampleMgr::MakeSmeared()
    {
        // Getting normal
        const double res   = _jet.JERPt[ _idx ];
        const double ressf = _jet.JERScale[ _idx ];
        const double width = ressf > 1 ? sqrt( ressf*ressf-1 ) * res : 0;
        
        // Generating random number
        // https://github.com/cms-sw/cmssw/blob/CMSSW_8_0_25/PhysicsTools/PatUtils/interface/SmearedJetProducerT.h
        std::default_random_engine gen( bitconv( _jet.Phi[ _idx ] ) );
        std::normal_distribution<double> myrand( _jet.Pt[ _idx ], width );
        const double newpt = myrand( gen );
        
        // Anonymouns namespace require (bug in gcc530)
        const double scale = newpt/_jet.Pt[_idx];
        
        if( scale <= 0 || ::isnan( scale ) ){
          return 1;
        } 
        else {
          return scale;
        }
    }
   
    TLorentzVector
    SampleMgr::JetP4()
    {
        return TLorentzVector( _jet.Px[ _idx ], _jet.Py[ _idx ], _jet.Pz[ _idx ], _jet.Energy[ _idx ] );
    }

    bool
    SampleMgr::passJetPt( const double& pt )
    {
        return _jet.Pt[ _idx ] > pt;
    }

    bool
    SampleMgr::passJetEta( const double& eta )
    {
        return fabs( _jet.Eta[ _idx ] ) < eta;
    }

    bool
    SampleMgr::JetNConstituents()
    {
        return _jet.NConstituents[ _idx ] > 1;
    }

    bool
    SampleMgr::JetNEF()
    {
        return _jet.NEF[ _idx ] <= 0.99;
    }

    bool
    SampleMgr::JetNHF()
    {
        return _jet.NHF[ _idx ] <= 0.99;
    }

    bool
    SampleMgr::JetCHF()
    {
        return _jet.CHF[ _idx ] > 0;
    }

    bool
    SampleMgr::JetNCH()
    {
        return _jet.NCH[ _idx ] > 0;
    }

    bool
    SampleMgr::JetCEF()
    {
        return _jet.CEF[ _idx ] <= 0.99;
    }

    // b-tagging
    bool
    SampleMgr::JetCSVM( const double& csv )
    {
        return _jet.pfCombinedInclusiveSecondaryVertexV2BJetTags[ _idx ] > csv;
    }
}
