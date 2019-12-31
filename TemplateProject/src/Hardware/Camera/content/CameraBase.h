#ifndef CAMERABASE_H
#define CAMERABASE_H

#include <QObject>
#include <boost/filesystem.hpp>
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

class CameraBase
{
public:
    CameraBase();


    virtual int ScanDevice();
    virtual bool OpenDeviceByIndex(QString index);
    virtual bool OpenDeviceBySerial(int index);

    virtual bool CloseDevice();

    virtual bool SetExposure(int);
    virtual bool SetGain(int);

    virtual bool GetConnect();

    virtual bool GetImage() const;

    static bool SaveImg(const cv::Mat &mat, const std::string &path = "", const std::string &name = "");
};

#endif // CAMERABASE_H
