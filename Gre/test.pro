######################################################################
# Automatically generated by qmake (3.0) Sun Jan 18 14:14:19 2015
######################################################################


TEMPLATE = app
TARGET = ft_gkrellm
INCLUDEPATH += . include

LIBS += -lncurses

QT += widgets



# Input
HEADERS += include/ANcursesDisplay.hpp \
           include/CPUInfo.hpp \
           include/DateTimeInfo.hpp \
           include/HostMonitor.hpp \
           include/IMonitorDisplay.hpp \
           include/IMonitorModule.hpp \
           include/Monitor.hpp \
           include/NcCpuDisplay.hpp \
           include/NcDateDisplay.hpp \
           include/NcHostDisplay.hpp \
           include/NcNameDisplay.hpp \
           include/NcOSInfoDisplay.hpp \
           include/NcRamDisplay.hpp \
           include/OSInfo.hpp \
           include/RAMInfo.hpp \
           include/tools.hpp \
           include/Title.hpp \
           include/QtDisplay.hpp \
           include/NetInfo.hpp \
           include/NcNetDisplay.hpp

SOURCES += src/ANcursesDisplay.cpp \
           src/CPUInfo.cpp \
           src/DateTimeInfo.cpp \
           src/HostMonitor.cpp \
           src/IMonitorDisplay.cpp \
           src/IMonitorModule.cpp \
           src/main.cpp \
           src/Monitor.cpp \
           src/NcCpuDisplay.cpp \
           src/NcDateDisplay.cpp \
           src/NcHostDisplay.cpp \
           src/NcNameDisplay.cpp \
           src/NcOSInfoDisplay.cpp \
           src/NcRamDisplay.cpp \
           src/OSInfo.cpp \
           src/RAMInfo.cpp \
           src/tools.cpp \
           src/Title.cpp \
           src/QtDisplay.cpp \
           src/NetInfo.cpp \
           src/NcNetDisplay.cpp

