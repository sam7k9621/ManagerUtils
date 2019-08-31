#ifndef READMGR_IPP
#define READMGR_IPP

#include "ManagerUtils/ArgHelper/interface/Common.hpp"

using namespace std;

namespace mgr {
    template < typename T >
    T
    Readmgr::GetParam( const string& sub, const string& tag )
    {
        return GetSubPSet( sub ).getParameter< T >( tag );
    }

    template < typename T >
    vector < T > 
    Readmgr::GetVParam( const string& sub, const string &tag )
    {
        return GetSubPSet( sub ).getParameter< vector< T > >( tag );
    }
}
#endif
