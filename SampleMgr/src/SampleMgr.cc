#include "ManagerUtils/SampleMgr/interface/SampleMgr.h"

using namespace std;

namespace mgr{
    
/*******************************************************************************
*  Class initialization 
*******************************************************************************/
    SampleMgr::SampleMgr(){}
    SampleMgr::SampleMgr(TChain* ch){
        SetTChain(ch);
    }
    SampleMgr::~SampleMgr(){}
    void
    SampleMgr::SetTChain(TChain* ch){
        _vtx.Register( ch );
        _lep.Register( ch );
        _evt.Register( ch );
        _jet.Register( ch );
        _gen.Register( ch );
    }

/*******************************************************************************
*   Common calculation
*******************************************************************************/
    double 
    SampleMgr::RelIsoR04(){
        double rel = ( _lep.ChargedHadronIsoR04[_idx] + max( float ( 0. ), _lep.NeutralHadronIsoR04[_idx] + _lep.PhotonIsoR04[_idx] - float ( 0.5 ) * _lep.sumPUPtR04[_idx] ) ) / _lep.Pt[_idx];
        return rel;
    }

    TLorentzVector
    SampleMgr::GetMET(const TLorentzVector& tl){
        double px = tl.Px() + _evt.PFMETx;
        double py = tl.Py() + _evt.PFMETy;
        double e  = tl.E()  + _evt.PFMET;
        double pz2 = e * e - ( 82.9 * 82.9 ) - px * px - py * py;
        double pz;

        if( pz2 < 0 ) {
            pz = 1000000;
        }

        else {
            pz  = -1 * ( sqrt( pz2 ) - tl.Pz() );
        }

        return TLorentzVector(_evt.PFMETx, _evt.PFMETy, pz, _evt.PFMET);
    }

    double 
    SampleMgr::Phi_mpi_pi(double x){
        Double_t const  kPI        = TMath::Pi();
        Double_t const  kTWOPI     = 2.*kPI;

        while ( x >=  kPI ) {
            x -= kTWOPI;
        }

        while ( x <  -kPI ) {
            x += kTWOPI;
        }

        return x;
    }

    bool 
    SampleMgr::isIsoLepton(const int& lepidx, const int& jetidx){
        double deta = ( double ) ( _lep.Eta[lepidx] - _jet.Eta[jetidx] );
        double dphi = Phi_mpi_pi( ( double ) ( _lep.Phi[lepidx] - _jet.Phi[jetidx] ) );
        double deltaR = TMath::Sqrt( deta * deta + dphi * dphi );
        return deltaR >= 0.4;
    }

    TLorentzVector
    SampleMgr::getLorentzVector(const string& type, const int& idx){
        if( type == "lep"){
            return TLorentzVector( _lep.Px[idx], _lep.Py[idx], _lep.Pz[idx], _lep.Energy[idx] ); 
        }

        else if( type == "jet" ){
            return TLorentzVector( _jet.Px[idx], _jet.Py[idx], _jet.Pz[idx], _lep.Energy[idx] );
        }

        else 
            return TLorentzVector();
    }
}
