#ifndef CAMERAHELPER_H
#define CAMERAHELPER_H

#include <QMutex>
#include <QThread>
#include <QObject>
#include "content/Camera_Daheng.h"
#include "content/Camera_HIKANG.h"
#include "content/Camera_XIMEA.h"

#include <memory>

namespace Cam {
    typedef enum Control_Tag{
        DAHENG_MODE =(0u),
        HIKANG_MODE ,
        XIMEA_MODE,
        TAG_ALL
    }REQUEST_MODE;
}



static Cam::REQUEST_MODE current_mode = Cam::DAHENG_MODE;

class CameraHelper
{
public:

    int ScanDevice(){return _m_ptr.get()->ScanDevice();}
    bool OpenDeviceByIndex(QString index){return _m_ptr.get()->OpenDeviceByIndex(index);}
    bool OpenDeviceBySerial(int index){return _m_ptr.get()->OpenDeviceBySerial(index);}
    bool CloseDevice(){return _m_ptr.get()->CloseDevice();}
    bool SetExposure(int value){return _m_ptr.get()->SetExposure( value);}
    bool SetGain(int value){return _m_ptr.get()->SetGain( value);}
    bool GetConnect(){return _m_ptr.get()->GetConnect();}
    bool GetImage() const{return _m_ptr.get()->GetImage();}

    CameraHelper(){
        init();
    }
    static CameraHelper* GetInstance(){
        static QMutex mutex;
        static QScopedPointer<CameraHelper> inst;
        if (Q_UNLIKELY(!inst)) {
            mutex.lock();
            if (!inst) {
                inst.reset(new CameraHelper);
            }
            mutex.unlock();
        }
        return inst.data();
    }



private:
    static std::shared_ptr<CameraBase> _m_ptr ;

    std::shared_ptr<CameraBase> operator->() {
        return _m_ptr;
    }

private:
    void init(){

        switch (current_mode) {
        case Cam::DAHENG_MODE:
            _m_ptr.reset(new Camera_Daheng);
            break;
        case Cam::HIKANG_MODE:
            _m_ptr.reset(new Camera_HIKANG);
            break;
        case Cam::XIMEA_MODE:
            _m_ptr.reset(new Camera_XIMEA);
            break;
        default:
            _m_ptr.reset(new CameraBase);
            break;
        }
    }


};








#endif // CAMERAHELPER_H
