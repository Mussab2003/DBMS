QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Base_Column.cpp \
    Base_Node.cpp \
    Column.cpp \
    CreateDatabase.cpp \
    Database.cpp \
    DatabaseLogin.cpp \
    DatabaseScreen.cpp \
    Dependencies.cpp \
    LinkedList.cpp \
    Node.cpp \
    Table.cpp \
    displaytable.cpp \
    main.cpp \
    MainScreen.cpp

HEADERS += \
    Base_Column.h \
    Base_Node.h \
    Column.h \
    CreateDatabase.h \
    Database.h \
    DatabaseLogin.h \
    DatabaseScreen.h \
    Dependencies.h \
    LinkedList.h \
    MainScreen.h \
    Node.h \
    Table.h \
    displaytable.h

FORMS += \
    CreateDatabase.ui \
    DatabaseLogin.ui \
    DatabaseScreen.ui \
    MainScreen.ui \
    displaytable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
