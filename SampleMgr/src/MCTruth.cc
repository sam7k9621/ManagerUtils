#include "ManagerUtils/SampleMgr/interface/SampleMgr.h"
#include <climits>

using namespace std;

namespace mgr{

    int
    SampleMgr::MatchGenlevel( const float& eta, const float& phi )
    {

        double deltaR = INT_MAX;
        int idx       = -1;

        for( int i = 0; i < Gsize(); i++ ){
            double deta = eta - _gen.Eta[ i ];
            double dphi = Phi_mpi_pi( (double)( phi - _gen.Phi[ i ] ) );
            double delR = TMath::Sqrt( deta * deta + dphi * dphi );

            if( delR < deltaR && delR < 0.4 ){
                deltaR = delR;
                idx    = i;
            }
        }

        return idx;
    }

    int
    SampleMgr::GetGenLep( const int& idx )
    {
        return MatchGenlevel( _lep.GenEta[ idx ], _lep.GenPhi[ idx ] );
    }

    int
    SampleMgr::GetGenJet( const int& idx )
    {
        return MatchGenlevel( _jet.Eta[ idx ], _jet.Phi[ idx ] );
    }

    int
    SampleMgr::GetDirectMother( int idx )
    {
        if( _gen.Mo1[ idx ] < 0 ){
            return -1;
        }

        while( fabs( _gen.Mo1PdgID[ idx ] ) == fabs( _gen.PdgID[ idx ] ) ){
            idx = _gen.Mo1[ idx ];
        }

        return _gen.Mo1[ idx ];
    }

    int
    SampleMgr::GetGenPdgID( const int& idx )
    {
        return _gen.PdgID[ idx ];
    }

    int
    SampleMgr::GetLepCharge( const int& idx )
    {
        return _lep.Charge[ idx ];
    }

    int
    SampleMgr::GetDirectMotherPdgID( const int& idx )
    {
        return GetGenPdgID( GetDirectMother( idx ) );
    }

    bool
    SampleMgr::HasCommonMo( const int& idx1, const int& idx2, const int& pdgid )
    {
        if( GetDirectMother( idx1 ) != GetDirectMother( idx2 ) ){
            return false;
        }

        if( fabs( GetDirectMotherPdgID( idx1 ) ) != pdgid ){
            return false;
        }

        return true;
    }

    bool
    SampleMgr::MCTruthBJet( vector<int>& bhandle )
    {

        bhandle.clear();

        for( int i = 0; i < Gsize(); i++ ){
            if( fabs( _gen.PdgID[ i ] ) == 6 ){

                if( fabs( _gen.Da1PdgID[ i ] ) == 5 ){
                    bhandle.push_back( _gen.Da1[ i ] );
                    continue;
                }

                if( fabs( _gen.Da2PdgID[ i ] ) == 5 ){
                    bhandle.push_back( _gen.Da2[ i ] );
                }
            }
        }

        return bhandle.size() == 2;

    }

}
