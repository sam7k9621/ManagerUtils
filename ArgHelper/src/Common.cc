#include "ManagerUtils/ArgHelper/interface/Common.hpp"
#include <stdlib.h>
using namespace std;

/*******************************************************************************
*   Operator overloading
*******************************************************************************/


/*******************************************************************************
*   Global variable
*******************************************************************************/

/*******************************************************************************
*   Common function
*******************************************************************************/

namespace mgr{

    string
    SubPackagePath( const string& package, const string& sub )
    {
        return mgr::PackagePath( package ) / sub;
    }

    // https://ubuntuforums.org/archive/index.php/t-895400.html
    string
    PackagePath( const string& package )
    {
        string base = getenv( "CMSSW_BASE" );
        return ( base / "src" ) / package;
    }
}
