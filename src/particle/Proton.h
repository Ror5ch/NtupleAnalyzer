#ifndef _PROTON_
#define _PROTON_

class Proton
{
public:
    Proton() = delete;
    Proton(const double& xi, const int& method, const int& lhcSector, const bool& isValid);
    ~Proton() {};
    const double& Xi() const;
    const int& Method() const;
    const int& LHCSector() const;
    const bool& IsValid() const;
private:
    const double _xi;
    const int _method;
    const int _lhcSector;
    const bool _isValid;
};

#endif