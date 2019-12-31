#include "CameraBase.h"

CameraBase::CameraBase()
{

}

int CameraBase::ScanDevice()
{
    return 666;
}

bool CameraBase::OpenDeviceByIndex(QString index)
{
    bool ret = false;
    return ret;
}

bool CameraBase::OpenDeviceBySerial(int index)
{
    bool ret = false;
    return ret;
}

bool CameraBase::CloseDevice()
{
    bool ret = false;
    return ret;
}

bool CameraBase::SetExposure(int)
{
    bool ret = false;
    return ret;
}

bool CameraBase::SetGain(int)
{
    bool ret = false;
    return ret;
}

bool CameraBase::GetConnect()
{
    bool ret = false;
    return ret;
}

bool CameraBase::GetImage() const
{
    bool ret = false;
    return ret;
}

bool CameraBase::SaveImg(const cv::Mat &mat, const std::string &path, const std::string &name)
{
    namespace bf = boost::filesystem ;
    using namespace std ;
    string strDir = "picture" ;
    boost::posix_time::ptime pt = boost::posix_time::microsec_clock::universal_time() ;
    // 以当前时间为默认图片文件名
    string strName = boost::posix_time::to_iso_string(pt) + ".jpg";
    if ( "" != path ) {
       strDir = path ;
    }
    if ( "" != name ) {
       strName = name ;
    }
    if ( !mat.data ) return false;

    if ( !bf::exists(strDir) ) {
         bf::create_directory(strDir) ;
    }
    cv::imwrite(strDir + "/" + strName , mat) ;
    return true;
}
