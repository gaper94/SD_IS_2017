#pragma once

#include <fstream>

class CarRecord
{
public:

    enum Parameter
    {
        UNKNOWN = -1,
        REGISTRATION_NUMBER,
        PRODUCTION_YEAR,
        BRAND,
        MODEL,
        POWER,
        FUEL_CONSUMPTION
    };

    static Parameter getParaeterWithName(const char* name);

    CarRecord(char* registrationNuber_ = NULL, unsigned productionYear_ = 1900,
              char* brand_ = NULL, char* model_ = NULL,
              unsigned power_ = 0, double averageFuelConsumption_ = 0.0);

    CarRecord(const CarRecord& other);
    CarRecord& operator = (const CarRecord& other);

    ~CarRecord();

    const char* getRegistrationNuber() const;
    unsigned getProductionYear() const;
    const char* getBrand() const;
    const char* getModel() const;
    unsigned getPower() const;
    double getAverageFuelConsumption() const;

    void setRegistrationNuber(char* registrationNumber);
    void setProductionYear(unsigned productionYear);
    void setBrand(char* brand);
    void setModel(char* model);
    void setPower(unsigned power);
    void setAverageFuelConsumption(double averageFuelConsumption);

    unsigned getUnsignedParameterValue(Parameter parameter) const;
    const char* getStringParameterValue(Parameter parameter) const;

    friend std::ostream& operator << (std::ostream& os, const CarRecord& record);
    friend std::istream& operator >> (std::istream& is, CarRecord& record);

 private:

    void copy(const CarRecord& other);

    char registrationNuber[9];
    unsigned productionYear;
    char brand[40];
    char model[40];
    unsigned power;
    double averageFuelConsumption;
};
