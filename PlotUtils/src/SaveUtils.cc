/*******************************************************************************
*
*  Filename    : SaveUtils.cc
*  Description : Plot saving utility functions  implementation
*  Author      : Yi-Mu "Enoch" Chen [ ensc@hep1.phys.ntu.edu.tw ]
*
*******************************************************************************/
#include "ManagerUtils/SysUtils/interface/PathUtils.hpp"

#include "TCanvas.h"
#include "TFile.h"

#include <boost/format.hpp>
#include <iostream>
#include <string>

using namespace std;

/******************************************************************************/

namespace mgr {


/******************************************************************************/

void
SaveToPDF( TCanvas* c, const string& filename )
{
  CheckPath( filename );
  c->SaveAs(filename.c_str());
}

/******************************************************************************/
void
SaveToROOT( TCanvas* c, const string& filename, const string& objname )
{
  CheckPath( filename );
  TFile* myfile = TFile::Open( filename.c_str(), "UPDATE" );
  c->Write( objname.c_str(), TFile::kOverwrite );
  delete myfile;
}

};
