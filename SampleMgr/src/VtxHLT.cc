#include "ManagerUtils/SampleMgr/interface/SampleMgr.h"
#include <climits>

using namespace std;

namespace mgr{
    /*******************************************************************************
    *   Vertex selection
    *   https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookPATExampleTopQuarks
    *******************************************************************************/
    bool
    SampleMgr::IsFake()
    {
        return _vtx.isFake[ _idx ];
    }

    bool
    SampleMgr::IsOfflinePV()
    {
        return _vtx.Type[ _idx ] == 1;
    }

    bool
    SampleMgr::passNdof()
    {
        return _vtx.Ndof[ _idx ] > 4;
    }

    bool
    SampleMgr::passAbsZ()
    {
        return fabs( _vtx.z[ _idx ] ) < 24;
    }

    bool
    SampleMgr::passRho()
    {
        return _vtx.Rho[ _idx ] < 2;
    }

    /*******************************************************************************
    *   HLT selection
    *******************************************************************************/
    bool
    SampleMgr::passHLT( const vector<int>& hlt )
    {
        for( const auto h : hlt ){
            if( int(_evt.TrgBook[ h ]) == 1 ){
                return true;
            }
        }

        return false;
    }
}
