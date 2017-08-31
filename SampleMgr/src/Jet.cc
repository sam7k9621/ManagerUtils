#include "ManagerUtils/SampleMgr/interface/SampleMgr.h"

using namespace std;

namespace mgr{

    /*******************************************************************************
    * Jet selection
    *******************************************************************************/

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
