#include "ManagerUtils/ArgHelper/interface/Readmgr.hpp"
#include "ManagerUtils/ArgHelper/interface/Common.hpp"

using namespace std;
namespace pt = boost::property_tree;

namespace mgr {

    Readmgr::Readmgr( const string& file ) {
        ReadFile( file, root );
    }

    pt::ptree Readmgr::GetSubTree( const string& t ) {
        return root.get_child( t );
    }

}
