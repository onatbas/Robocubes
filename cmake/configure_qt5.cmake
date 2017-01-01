find_package(Qt5Widgets)
find_package(Qt5Script)

include_directories(${Qt5Widgets_INCLUDE_DIRS})

set (QT5_LINK_TARGETS Qt5::Widgets Qt5::Script)


#deploy with qt dlls.
#link against QT5_LINK_TARGETS