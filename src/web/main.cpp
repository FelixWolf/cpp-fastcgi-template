#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "boost/cgi/fcgi.hpp"

using namespace boost::fcgi;

int handle_request(acceptor& a, request& req){
    boost::system::error_code ec;
    req.load(parse_all);
    
    response resp;
    resp << content_type("text/plain");
    
    resp << "Hello, world!";
    
    //TODO: This is done in the example code, but looks like a possible
    //      infinit loop?
    int status = commit(req, resp);
    if (!status)
        a.async_accept(boost::bind(&handle_request, boost::ref(a), _1));
    
    return status;
}

int main(){
    try{
        service s;
        acceptor a(s);
        
        int count(10);
        while (--count)
            a.async_accept(boost::bind(&handle_request, boost::ref(a), _1));
        
        s.run();
        return 0;
    }catch(boost::system::system_error const& se){
        std::cerr << "[fcgi] System error: " << se.what() << std::endl;
        return -1;
    }catch(std::exception const& e){
        std::cerr << "[fcgi] Exception: " << e.what() << std::endl;
        return -2;
    }catch(...){
        std::cerr << "[fcgi] Uncaught exception!" << std::endl;
        return -3;
    }
}