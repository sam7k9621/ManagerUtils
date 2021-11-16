#include <iostream>

namespace mgr {
    /*******************************************************************************
    *   Constructor and destructor
    *******************************************************************************/
    template < typename T, typename U >
    RootObjMgr < T, U > ::RootObjMgr()
    {
    }

    /******************************************************************************/

    template < typename T, typename U >
    RootObjMgr < T, U > ::~RootObjMgr()
    {
    }

    /*******************************************************************************
    *   Addition and removal functions
    *******************************************************************************/
    template < typename T, typename U >
    void
    RootObjMgr < T, U > ::AddObj( T * obj )
    {
                          // name                // sample_name  // sample
        const std::string store = MakeStoreName( obj->GetName(), obj->GetTitle() );

        if( store != obj->GetName() ){
            obj->SetTitle( "" );
        }

        _objmap.erase( store );// deleting existing instance if already exist
        _objmap[ store ] = U( obj );
    }

    /******************************************************************************/

    template < typename T, typename U >
    void
    RootObjMgr < T, U > ::RemoveObj( const std::string& name )
    {
        if( _objmap.count( name ) ){
            _objmap.erase( name );
        }
        else{
        }
    }

    /*******************************************************************************
    *   Object access functions
    *******************************************************************************/
    template < typename T, typename U >
    T *
    RootObjMgr < T, U > ::GetObj( const std::string& name )
    {
        try{
            return _objmap.at( name ).get();
        }
        catch( const std::out_of_range& oor ) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
            return NULL;
        } 
    }

    /******************************************************************************/

    template < typename T, typename U >
    const T *
    RootObjMgr < T, U > ::GetObj( const std::string& name ) const
    {
        if( _objmap.count( name ) ){
            return _objmap.at( name ).get();
        }
        else{
            return NULL;
        }
    }

    /*******************************************************************************
    *   Object listing functions
    *******************************************************************************/
    template < typename T, typename U >
    std::vector < std::string >
    RootObjMgr < T, U > ::ObjNameList() const
    {
        std::vector < std::string > ans;

        for( const auto& mypair : _objmap ){
            ans.push_back( mypair.first );
        }

        return ans;
    }

    /******************************************************************************/

    template < typename T, typename U >
    std::vector < T * >
    RootObjMgr < T, U > ::GetObjContains( const std::string& substring )
    {
        std::vector < T * > ans;

        for( auto& mypair : _objmap ){
            if( mypair.first.find( substring ) != std::string::npos ){
                ans.push_back( mypair.second.get() );
            }
        }

        return ans;
    }

    /*******************************************************************************
    *   Naming convention functions
    *******************************************************************************/
    template < typename T, typename U >
    std::string
    RootObjMgr < T, U > ::MakeStoreName( const std::string& objname, const std::string& tag ) const
    {
        std::regex pattern( tag + "_" );

        return std::regex_replace( objname, pattern, "" );
    }
}/* mgr */
