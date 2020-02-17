#include "ManagerUtils/ArgHelper/interface/Common.hpp"
#include "ManagerUtils/ArgHelper/interface/Readmgr.hpp"

using namespace std;
using namespace edm;

namespace mgr{
    Readmgr::Readmgr(){}
    Readmgr::Readmgr( const string& file ):
        _file( readPSetsFrom( file ) )
    {}

    ParameterSet 
    Readmgr::GetSubPSet( const string& t )
    {
        return _root.getParameter<ParameterSet>( t );
    }

    void
    Readmgr::InitRoot( const string& tag )
    {
        _root = _file->getParameter<ParameterSet>( tag );
    }
}
