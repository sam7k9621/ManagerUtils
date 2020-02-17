#ifndef READMGR_HPP
#define READMGR_HPP

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/PythonParameterSet/interface/MakeParameterSets.h"
#include <string>
#include <vector>

namespace mgr{
    class Readmgr {
        public:

            Readmgr();
            Readmgr( const std::string& );

            virtual ~Readmgr(){}

            void                        InitRoot( const std::string& );
            edm::ParameterSet           GetSubPSet( const std::string& );

            template<typename T>
            T GetParam( const std::string&, const std::string& );

            template<typename T>
            std::vector<T> GetVParam( const std::string&, const std::string& );

        private:
            
            std::shared_ptr<edm::ParameterSet> _file;
            edm::ParameterSet _root;
    };
}

#include "ManagerUtils/ArgHelper/src/Readmgr.ipp"

#endif
