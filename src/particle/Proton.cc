#include "Proton.h"

Proton::Proton(const double& xi, const int& method, const int& lhcSector, const bool& isValid):
_xi{xi}, _method{method}, _lhcSector{lhcSector}, _isValid{isValid}
{}
const double& Proton::Xi() const
{
    return _xi;
}
const int& Proton::Method() const
{
    return _method;
}
const int& Proton::LHCSector() const
{
    return _lhcSector;
}
const bool& Proton::IsValid() const
{
    return _isValid;
}