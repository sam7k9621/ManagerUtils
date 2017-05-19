#include "ManagerUtils/Analysis/interface/Readmgr.hpp"
#include "ManagerUtils/Analysis/interface/Common.hpp"

using namespace std;
namespace pt = boost::property_tree;

dra::Readmgr::Readmgr(const string& file){
    dra::ReadFile(file,root);
}

pt::ptree
dra::Readmgr::GetSubTree(const string& t){
    return root.get_child(t);
} 

