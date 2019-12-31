#ifndef CAMERA_HIKANG_H
#define CAMERA_HIKANG_H

#include "CameraBase.h"

class Camera_HIKANG : public CameraBase
{
public:
    Camera_HIKANG();

    virtual int ScanDevice() override;
    virtual bool OpenDeviceByIndex(QString index) override;
    virtual bool OpenDeviceBySerial(int index) override;

    virtual bool CloseDevice() override;

    virtual bool SetExposure(int) override;
    virtual bool SetGain(int) override;

    virtual bool GetConnect() override;

    virtual bool GetImage() const override;
};

#endif // CAMERA_HIKANG_H
