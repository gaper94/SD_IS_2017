#include "CarRecord.h"
#include <cstring>

CarRecord::Parameter CarRecord::getParaeterWithName(const char* name)
{
    if(strcmp("registrationNumber", name) == 0)
    {
        return CarRecord::REGISTRATION_NUMBER;
    }
    if(strcmp("productionYear", name) == 0)
    {
        return CarRecord::PRODUCTION_YEAR;
    }
    if(strcmp("brand", name) == 0)
    {
        return CarRecord::BRAND;
    }
    if(strcmp("model", name) == 0)
    {
        return CarRecord::MODEL;
    }
    if(strcmp("consumption", name) == 0)
    {
        return CarRecord::FUEL_CONSUMPTION;
    }

    return CarRecord::UNKNOWN;
}

CarRecord::CarRecord(char* registrationNuber_ , unsigned productionYear_,
          char* brand_, char* model_,
          unsigned power_, double averageFuelConsumption_) :
    productionYear(productionYear_), power(power_),
    averageFuelConsumption(averageFuelConsumption_)
{
    if(registrationNuber_ != NULL)
    {
        strcpy(registrationNuber, registrationNuber_);
    }

    if(brand_ != NULL)
    {
        strcpy(brand, brand_);
    }

    if(model_ != NULL)
    {
        strcpy(model, model_);
    }
}

void CarRecord::copy(const CarRecord& other)
{
    strcpy(registrationNuber, other.registrationNuber);
    productionYear = other.productionYear;
    strcpy(brand, other.brand);
    strcpy(model, other.model);
    power = other.power;
    averageFuelConsumption = other.averageFuelConsumption;
}

CarRecord::CarRecord(const CarRecord& other)
{
    copy(other);
}

CarRecord& CarRecord::operator = (const CarRecord& other)
{
    if(this != &other)
    {
        copy(other);
    }

    return *this;
}

CarRecord::~CarRecord()
{
}

const char* CarRecord::getRegistrationNuber() const
{
    return registrationNuber;
}

unsigned CarRecord::getProductionYear() const
{
    return productionYear;
}

const char* CarRecord::getBrand() const
{
    return brand;
}

const char* CarRecord::getModel() const
{
    return model;
}

unsigned CarRecord::getPower() const
{
    return power;
}

double CarRecord::getAverageFuelConsumption() const
{
    return averageFuelConsumption;
}

void CarRecord::setRegistrationNuber(char* registrationNumber)
{
    strcpy(this->registrationNuber, registrationNumber);
}

void CarRecord::setProductionYear(unsigned productionYear)
{
    this->productionYear = productionYear;
}

void CarRecord::setBrand(char* brand)
{
    strcpy(this->brand, brand);
}

void CarRecord::setModel(char* model)
{
    strcpy(this->model, model);
}

void CarRecord::setPower(unsigned power)
{
    this->power = power;
}

void CarRecord::setAverageFuelConsumption(double averageFuelConsumption)
{
    this->averageFuelConsumption = averageFuelConsumption;
}

unsigned CarRecord::getUnsignedParameterValue(CarRecord::Parameter parameter) const
{
    switch (parameter)
    {
    case CarRecord::PRODUCTION_YEAR:
        return getProductionYear();

    case CarRecord::POWER:
        return getPower();

    default:
        return 0;
    }
}

const char* CarRecord::getStringParameterValue(CarRecord::Parameter parameter) const
{
   switch (parameter)
   {
   case CarRecord::REGISTRATION_NUMBER:
       return getRegistrationNuber();

   case CarRecord::BRAND:
       return getBrand();

   case CarRecord::MODEL:
       return getModel();

   default:
       return "";
   }
}

std::ostream& operator << (std::ostream& os, const CarRecord& record)
{
    os << record.registrationNuber << " " << record.productionYear << " "
       << record.brand << " " << record.model << " " << record.power << " "
       << record.averageFuelConsumption << std::endl;

    return os;
}

std::istream& operator >> (std::istream& is, CarRecord& record)
{
    is >> record.registrationNuber >> record.productionYear >> record.brand
       >>record.model >> record.power >> record.averageFuelConsumption;

    return is;
}

