#ifndef PARSERMGR_IPP
#define PARSERMGR_IPP

#include "ManagerUtils/ArgHelper/interface/Parsermgr.hpp"
 

namespace opt = boost::program_options;
using namespace std;

template <typename T>
T dra::Parsermgr::GetOption(const string& op){
    return _vm[op].as<T>();
}


//http://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c
template <typename T>
void dra::Parsermgr::SetFileName(initializer_list<T> list){

    for(const auto& name : list){
        _namelist.push_back(name);
    }
}

template <typename T>
void dra::Parsermgr::AddCutName(initializer_list<T> list){
    
    for(const auto& name : list){
        if(CheckOption(name)){
            _cutlist.push_back(name);
        }
    }
}

#endif
