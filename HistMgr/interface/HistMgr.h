#ifndef MANAGERUTILS_ROOTMGR_HISTMGR_H
#define MANAGERUTILS_ROOTMGR_HISTMGR_H

#include "ManagerUtils/HistMgr/interface/RootObjMgr.h"

#include "TH1D.h"
#include <string>

namespace mgr {

class HistMgr 
{
public:
  HistMgr( const std::string& );  // Must have unique name
  virtual
  ~HistMgr ();

  TH1D*       Hist( const std::string& );
  const TH1D* Hist( const std::string& ) const;

  std::vector<std::string> AvailableHistList() const;
  void                     Scale( const double );
  void                     SetColor( const Color_t );
  void                     SetLineColor( const Color_t );
  void                     SetFillColor( const Color_t );
  void                     SetFillStyle( const Style_t );

  void LoadFromFile( const std::string& );
  void SaveToFile( const std::string& );

  // Static functions for helping with title creation
  static std::string GetXUnit( const TH1D* );

protected:
  void AddHist(
    const std::string&, 
    const std::string&, 
    const std::string&, 
    const int         ,
    const double      , 
    const double       
    );

private:
  std::string _tag;
  RootObjMgr<TH1D> _histmgr;
};

};

#endif/* end of include guard: MANAGERUTILS_HISTMGR_HISTMGR_HPP */
