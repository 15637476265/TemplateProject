#ifndef CAMERA_DAHENG_H
#define CAMERA_DAHENG_H

#include "CameraBase.h"


class Camera_Daheng : public CameraBase
{
public:
    Camera_Daheng();

    virtual int ScanDevice() override;
    virtual bool OpenDeviceByIndex(QString index) override;
    virtual bool OpenDeviceBySerial(int index) override;

    virtual bool CloseDevice() override;

    virtual bool SetExposure(int) override;
    virtual bool SetGain(int) override;

    virtual bool GetConnect() override;

    virtual bool GetImage() const override;
};

#endif // CAMERA_DAHENG_H
