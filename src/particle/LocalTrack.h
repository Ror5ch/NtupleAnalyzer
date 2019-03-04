#ifndef _LocalTrack_
#define _LocalTrack_

class LocalTrack
{
public:
    LocalTrack() = delete;
    LocalTrack(const int& rpId, const double& x, const double& x_unc, const double& y, const double& y_unc, const double& tx, const double& tx_unc, const double& ty, const double& ty_unc, const double& chiSquaredOverNDF);
    ~LocalTrack() {};
    const int& RPID() const;
    const double& X() const;
    const double& XUnc() const;
    const double& Y() const;
    const double& YUnc() const;
    const double& Tx() const;
    const double& TxUnc() const;
    const double& Ty() const;
    const double& TyUnc() const;
    const double& ChiSquaredOverNDF() const;
private:
    const int _rpId;
    const double _x;
    const double _x_unc;
    const double _y;
    const double _y_unc;
    const double _tx;
    const double _tx_unc;
    const double _ty;
    const double _ty_unc;
    const double _chiSquaredOverNDF;
};

#endif