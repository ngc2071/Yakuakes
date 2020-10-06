configure_file(config-yakuake.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-yakuake.h)

set(Yakuake1stScreen_SRCS
    main.cpp
    mainwindow.cpp
    skin.cpp
    titlebar.cpp
    tabbar.cpp
    sessionstack.cpp
    session.cpp
    terminal.cpp
    splitter.cpp
    firstrundialog.cpp
    visualeventoverlay.cpp
    config/windowsettings.cpp
    config/appearancesettings.cpp
    config/skinlistdelegate.cpp
)

ki18n_wrap_ui(Yakuake1stScreen_SRCS
    firstrundialog.ui
    config/windowsettings.ui
    config/behaviorsettings.ui
    config/appearancesettings.ui
)

kconfig_add_kcfg_files(Yakuake1stScreen_SRCS config/settings.kcfgc)

file(GLOB ICONS_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/../data/icons/*-apps-yakuake.png")
ecm_add_app_icon(Yakuake1stScreen_SRCS ICONS ${ICONS_SRCS})

add_executable(Yakuake1stScreen ${Yakuake1stScreen_SRCS})

target_link_libraries(Yakuake1stScreen
    Qt5::Widgets
    KF5::Archive
    KF5::ConfigGui
    KF5::CoreAddons
    KF5::Crash
    KF5::DBusAddons
    KF5::GlobalAccel
    KF5::I18n
    KF5::IconThemes
    KF5::KIOCore
    KF5::NewStuff
    KF5::Notifications
    KF5::NotifyConfig
    KF5::Parts
    KF5::WidgetsAddons
    KF5::WindowSystem)

if(X11_FOUND)
  target_link_libraries(Yakuake1stScreen Qt5::X11Extras ${X11_X11_LIB})
endif(X11_FOUND)

if(KF5Wayland_FOUND)
  target_link_libraries(Yakuake1stScreen KF5::WaylandClient)
endif()

install(TARGETS Yakuake1stScreen ${INSTALL_TARGETS_DEFAULT_ARGS})

install(FILES Yakuake1stScreen.knsrc DESTINATION ${KDE_INSTALL_KNSRCDIR})
