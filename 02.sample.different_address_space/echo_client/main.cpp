// SmallCorbaProject.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "../echo_corba_lib/echo.h"

using namespace std;


// client
static void hello( Echo_ptr e )
{
    CORBA::String_var src = "Hello!";
    CORBA::String_var dest = e->echoString( src );
    cout << "I said, \"" << (char*)src << "\"." << endl
        << "The Echo object replied, \"" << (char*)dest <<"\"." << endl;
}


int main( int argc, char** argv )
{
    try
    {
        CORBA::ORB_var orb = CORBA::ORB_init( argc, argv );

        // get sior from file
        string sior;
        ifstream is( "../echo_server/sior", ios::in );
        is >> sior;
        is.close();
        
        // delete the file
        _unlink( "../echo_server/sior" );

        // Note: the string is different in every time, so we can not hard code here
        CORBA::Object_var obj = orb->string_to_object( sior.c_str() );

        Echo_var echoref = Echo::_narrow( obj );

        if ( CORBA::is_nil( echoref ) )
        {
            cerr << "Can't narrow reference to type Echo (or it was nil)." << endl;
            return 1;
        }

        hello( echoref );

        orb->destroy();
    }
    catch( CORBA::TRANSIENT& )
    {
        cerr << "Caught system exception TRANSIENT -- unable to contact the "  << "server." << endl;
    }
    catch( CORBA::SystemException& ex )
    {
        cerr << "Caught a CORBA::" << ex._name() << endl;
    }
    catch( CORBA::Exception& ex )
    {
        cerr << "Caught CORBA::Exception: " << ex._name() << endl;
    }
    catch( omniORB::fatalException& fe )
    {
        cerr << "Caught omniORB::fatalException:" << endl;
        cerr << " file: " << fe.file() << endl;
        cerr << " line: " << fe.line() << endl;
        cerr << " mesg: " << fe.errmsg() << endl;
    }

    return 0;
}
