#include "LocalTrack.h"

LocalTrack::LocalTrack(const int& rpId, const double& x, const double& x_unc, const double& y, const double& y_unc, const double& tx, const double& tx_unc, const double& ty, const double& ty_unc, const double& chiSquaredOverNDF):
_rpId{rpId}, _x{x}, _x_unc{x_unc}, _y{y}, _y_unc{y_unc}, _tx{tx}, _tx_unc{tx_unc}, _ty{ty}, _ty_unc{ty_unc}, _chiSquaredOverNDF{chiSquaredOverNDF}
{}
const int& LocalTrack::RPID() const
{
    return _rpId;
}
const double& LocalTrack::X() const
{
    return _x;
}
const double& LocalTrack::XUnc() const
{
    return _x_unc;
}
const double& LocalTrack::Y() const
{
    return _y;
}
const double& LocalTrack::YUnc() const
{
    return _y_unc;
}
const double& LocalTrack::Tx() const
{
    return _tx;
}
const double& LocalTrack::TxUnc() const
{
    return _tx_unc;
}
const double& LocalTrack::Ty() const
{
    return _ty;
}
const double& LocalTrack::TyUnc() const
{
    return _ty_unc;
}
const double& LocalTrack::ChiSquaredOverNDF() const
{
    return _chiSquaredOverNDF;
}