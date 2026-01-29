#include "servicedata.hh"
#include <iostream>


ServiceData::ServiceData()
{

}

ServiceData::~ServiceData()
{

}

bool ServiceData::makeService(const Service &service, int kilometres)
{



    if(services_.find(kilometres) != services_.end()){

        std::cout<<"Error: already serviced with the same kilometres"<<std::endl;
        return false;

    }

    services_.insert({kilometres,service});

   // services_[kilometres]=service;


    return true;
    //service.services_
}

void ServiceData::print() const
{


    for (const auto& serv : services_) {
        int kilometres = serv.first;
        const Service& service = serv.second;

        std::cout<<"* Kilometres driven "<<kilometres<<" until "<<service.date_<<std::endl;
        for(auto op : service.operations_){
            std::cout<<"  --- "<<op<<std::endl;
        }

    }
 std::cout<<std::endl;

}

const std::map<int, Service> &ServiceData::getServices() const
{
    return services_;
}
