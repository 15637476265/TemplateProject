#-------------------------------------------------
#
# Project created by QtCreator 2019-11-06T16:38:12
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


include(module/module.pri)


TARGET = TemplateProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


OPENCV_HOME=/SDK/opencv320
BOOST_HOME = /SDK/boost1640

INCLUDEPATH += $${OPENCV_HOME}/include \
               $${PROROOT}/include \
               $${PROROOT}/include/image2 \
               $${BOOST_HOME}/include \
               $${MVCAM_COMMON_HOME}/include

LIBS += -L$${OPENCV_HOME}/lib \
        -L$${BOOST_HOME}/lib/release \
        -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lopencv_tracking \
        -latomic  -lpcan \ #-lm3api
        -lboost_filesystem -lboost_system -lboost_date_time \
        -lnlopt \
       # -L$${MVCAM_COMMON_HOME}/lib/64 -lGCBase_gcc421_v3_0 -lGenApi_gcc421_v3_0 -lXmlParser_gcc421_v3_0 -lMvCameraControl

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    src/Hardware/Serial/SerialHelper.cpp \
    src/Hardware/Serial/content/BoostControl.cpp \
    src/Hardware/Serial/content/ModbusControl.cpp \
    src/Hardware/Serial/content/QSerialControl.cpp \
    src/Hardware/Serial/content/SerialBase.cpp \
    src/SoftWare/ReadWrite/content/RWFile.cpp \
    src/SoftWare/ReadWrite/RWFileHelper.cpp \
    src/Hardware/Camera/CameraHelper.cpp \
    src/Hardware/Camera/content/CameraBase.cpp \
    src/Hardware/Camera/content/Camera_Daheng.cpp \
    src/Hardware/Camera/content/Camera_XIMEA.cpp \
    src/Hardware/Camera/content/Camera_HIKANG.cpp \
    src/SoftWare/DataRecode/DataRecodeHelper.cpp \
    src/SoftWare/DataRecode/content/RecodeBase.cpp \
    src/SoftWare/DataRecode/content/RecodeByTXT.cpp \
    src/SoftWare/DataRecode/content/RecodeBySQL.cpp \
    src/SoftWare/DataRecode/content/RecodeByChart.cpp \
    src/SoftWare/LogCreat/LogHelper.cpp \
    src/SoftWare/LogCreat/content/LogBase.cpp

HEADERS += \
        mainwindow.h \
    src/Hardware/Serial/SerialHelper.h \
    src/Hardware/Serial/content/BoostControl.h \
    src/Hardware/Serial/content/ModbusControl.h \
    src/Hardware/Serial/content/QSerialControl.h \
    src/Hardware/Serial/content/SerialBase.h \
    src/SoftWare/ReadWrite/content/RWFile.h \
    src/SoftWare/ReadWrite/RWFileHelper.h \
    src/Hardware/Camera/CameraHelper.h \
    src/Hardware/Camera/content/CameraBase.h \
    src/Hardware/Camera/content/Camera_Daheng.h \
    src/Hardware/Camera/content/Camera_XIMEA.h \
    src/Hardware/Camera/content/Camera_HIKANG.h \
    src/SoftWare/DataRecode/DataRecodeHelper.h \
    src/SoftWare/DataRecode/content/RecodeBase.h \
    src/SoftWare/DataRecode/content/RecodeByTXT.h \
    src/SoftWare/DataRecode/content/RecodeBySQL.h \
    src/SoftWare/DataRecode/content/RecodeByChart.h \
    src/SoftWare/LogCreat/LogHelper.h \
    src/SoftWare/LogCreat/content/LogBase.h

FORMS += \
        mainwindow.ui
