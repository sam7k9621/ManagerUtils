#ifndef COMMON_HPP
#define COMMON_HPP

// http://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files-in-c

#include "ManagerUtils/Common/interface/STLUtils/StringUtils.hpp"
#include <string>
#include <vector>

/*******************************************************************************
*   Operator overloading, defined in src/Common.cc
*******************************************************************************/


/*******************************************************************************
*   Global variable, defined in src/Common.cc
*******************************************************************************/

namespace mgr{
    /*******************************************************************************
    *   Common variable, defined in src/Common.cc
    *******************************************************************************/

    /*******************************************************************************
    *   Common function, defined in src/Common.cc
    *******************************************************************************/
    extern std::string SubPackagePath( const std::string&, const std::string& );
    extern std::string PackagePath( const std::string& );

}

#endif
