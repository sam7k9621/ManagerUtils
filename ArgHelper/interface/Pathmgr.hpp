#ifndef PATHMGR_HPP
#define PATHMGR_HPP

#include "ManagerUtils/Common/interface/STLUtils/StringUtils.hpp"
#include <map>
#include <string>
namespace mgr{
    class Pathmgr {
        public:

            Pathmgr();
            Pathmgr(
                const std::string& package,
                const std::string& sub_package,
                const std::string& settings_dir = "settings",
                const std::string& results_dir  = "results",
                const std::string& python_dir   = "python",
                const std::string& datas_dir    = "data"
                );
            virtual ~Pathmgr ();

            // Instance functions for getting file names
            std::string PackageDir()    const;
            std::string SubPackageDir() const;

            // Instance functions for getting hostname
            std::string HostName();

            // Default settings for sample
            std::string SubDir( const std::string& ) const;
            std::string SettingsDir() const;
            std::string ResultsDir()  const;
            std::string PythonDir()  const;
            std::string DatasDir() const;

            
        private:
            
            std::string _hostname;
            const std::string _package_name;
            const std::string _sub_package_name;
            const std::string _settings_dir;
            const std::string _results_dir;
            const std::string _python_dir;
            const std::string _datas_dir;
    };
}

#endif
