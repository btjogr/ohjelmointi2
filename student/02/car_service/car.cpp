#include "car.hh"
#include <memory>

Car::Car()
{

    kilometresDriven_=0;
    service_data_ = std::unique_ptr<ServiceData>(new ServiceData()); // Luo uusi ServiceData-olio
}

Car::Car(const std::string &brand, const std::string &model, const std::string &color, const std::string &regNum)
{
    brand_=brand;
    model_=model;
    color_=color;
    registerNum_=regNum;
    kilometresDriven_=0;

    service_data_ = std::unique_ptr<ServiceData>(new ServiceData()); // Luo uusi ServiceData-olio



}

Car::Car(const Car &other) : brand_(other.brand_), model_(other.model_),color_(other.color_),registerNum_("")
{


    kilometresDriven_=0;


    service_data_ = std::unique_ptr<ServiceData>(new ServiceData()); // Luo uusi ServiceData-olio


    // for (const auto& entry : other.service_data_->getServices()) {
    //     int kilometres = entry.first;
    //     const Service& service = entry.second;

    //     // Lisää uusi service olioon
    //     service_data_->makeService(service, kilometres);
    // }

}

Car::~Car()
{

}

Car& Car::operator=(const Car &other)
{
    if (this == &other) return *this; // Estetään itselle kopiointi

    // Kopioidaan perusjäsenmuuttujat
    brand_ = other.brand_;
    model_ = other.model_;
    color_ = other.color_;
    registerNum_ = other.registerNum_;
    kilometresDriven_ = other.kilometresDriven_;

    // Kopioidaan service_data_
    if (other.service_data_) {
        service_data_ = std::unique_ptr<ServiceData>(new ServiceData());

        // Kopioidaan services_ erikseen, koska se on private
        for (const auto& entry : other.service_data_->getServices()) {
            service_data_->makeService(entry.second, entry.first);
        }
    } else {
        service_data_.reset();  // Tyhjennetään, jos toisessa ei ole dataa
    }
     return *this;
}

void Car::setRegisterNum(const std::string &regNum)
{
    registerNum_=regNum;
}

void Car::setColor(const std::string &color)
{
    color_=color;
}

std::string Car::brand() const
{
    return brand_;
}

std::string Car::model() const
{
    return model_;
}

std::string Car::color() const
{
    return color_;
}

std::string Car::registerNum() const
{
    return registerNum_;
}

int Car::kilometresDriven() const
{
    return kilometresDriven_;
}

const ServiceData &Car::serviceData() const
{
    return *service_data_;
}

void Car::drive(int kilometres)
{
    kilometresDriven_+=kilometres;
}

bool Car::service(const Service &service)
{


    try {
        Service* sr = new Service(service);
        bool success = service_data_->makeService(*sr, kilometresDriven_);
        delete sr; // 🔹 Vapautetaan muisti
        return success;
    } catch (...) {
        return false;
    }

    // Tries to insert the given service in the service data.
    // Returns the result of the service data's makeService function.




}

bool Car::service(const std::string &date, const std::vector<std::string> &operations)
{
    Service* service = new Service;
    service->date_ = date;
    service->operations_ = operations;
    bool success = service_data_->makeService(*service, kilometresDriven_);
    delete service;  // 🔹 Vapautetaan muisti
    return success;
}

void Car::print() const
{
    std::cout<< registerNum_ <<" : "<<brand_<<" : "<<model_<<" : "<<color_<<std::endl;

    service_data_->print();


}
