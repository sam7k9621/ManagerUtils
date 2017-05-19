#ifndef READMGR_IPP
#define READMGR_IPP

#include "ManagerUtils/Analysis/interface/Readmgr.hpp"
#include "ManagerUtils/Analysis/interface/Common.hpp"

using namespace std;
using namespace boost::property_tree;

template<typename T>
T dra::Readmgr::GetSingleData(const string& tag){
    return dra::GetSingle<T>(tag,root);
}


template<typename T>
vector<T> dra::Readmgr::GetListData(const string& tag){
    return dra::GetList<T>(tag, root);
}


#endif


