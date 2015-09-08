// SmallCorbaProject.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "echo_corba_lib/echo.h"

using namespace std;

// server
class Echo_i : public POA_Echo
{
public:
    inline Echo_i() {}
    virtual ~Echo_i() {}
    virtual char* echoString(const char* mesg)
    {
        return CORBA::string_dup(mesg);
    }
};


// client
void  hello( CORBA::Object_ptr obj )
{
    Echo_var e = Echo::_narrow( obj );

    if ( CORBA::is_nil( e ) )
    {
        cerr << "cannot invoke on a nil object reference."
             << endl;
        return;
    }

    CORBA::String_var src = "Hello!";
    CORBA::String_var dest;

    dest = e->echoString(src);

    cerr << "I said,\"" << src << "\"."
         << " The Object said,\"" << dest <<"\"" << endl;
}


// same address space
int main( int argc, char* argv[] )
{
    CORBA::ORB_ptr orb = CORBA::ORB_init( argc, argv, "omniORB4" );

    CORBA::Object_var obj = orb->resolve_initial_references( "RootPOA" );
    PortableServer::POA_var poa = PortableServer::POA::_narrow( obj );

    Echo_i *myecho = new Echo_i();
    PortableServer::ObjectId_var myechoid = poa->activate_object(myecho);

    Echo_var myechoref = myecho->_this();
    myecho->_remove_ref();

    PortableServer::POAManager_var pman = poa->the_POAManager();
    pman->activate();

    hello( myechoref );

    orb->destroy();

    return 0;
}
