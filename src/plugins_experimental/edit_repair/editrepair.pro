include (../../shared.pri)


HEADERS       = edit_repair_factory.h \
				editrepair.h \
    circle.h \
    repairDialog.h \
    RepairDialog.h \
    dockwidget.h
				 
SOURCES       = edit_repair_factory.cpp \
				editrepair.cpp \ 
    circle.cpp \
    repairDialog.cpp \
    RepairDialog.cpp \
    dockwidget.cpp

TARGET        = editrepair

QT           += opengl

RESOURCES     = editrepair.qrc

FORMS += \
    repairDialog.ui \
    RepairDialog.ui \
    dockwidget.ui
