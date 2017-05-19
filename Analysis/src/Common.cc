#include "ManagerUtils/Analysis/interface/Common.hpp"
#include <stdlib.h>
using namespace std;
using namespace boost::property_tree;
using namespace dra;
/*******************************************************************************
*   Operator overloading
*******************************************************************************/

string operator/( const string& x , const string& y )
{
  return x+"/"+y;
}


namespace dra{
/*******************************************************************************
*   Common function
*******************************************************************************/

void ReadFile(const string& file, ptree& root){
    read_json(file,root);
}

string SubPackagePath(const string& package, const string& sub){
    return dra::PackagePath(package) / sub;
}

//https://ubuntuforums.org/archive/index.php/t-895400.html
string PackagePath(const string& package){
    string base = getenv("CMSSW_BASE");
    return ( base / "src") / package;
}

}




