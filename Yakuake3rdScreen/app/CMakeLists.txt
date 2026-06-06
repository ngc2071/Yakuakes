configure_file(config-yakuake.h.in ${CMAKE_CURRENT_BINARY_DIR}/config-yakuake.h)

add_executable(Yakuake3rdScreen)

target_sources(Yakuake3rdScreen PRIVATE
    config/appearancesettings.cpp
    config/appearancesettings.h
    config/skinlistdelegate.cpp
    config/skinlistdelegate.h
    config/windowsettings.cpp
    config/windowsettings.h
    firstrundialog.cpp
    firstrundialog.h
    main.cpp
    mainwindow.cpp
    mainwindow.h
    session.cpp
    session.h
    sessionstack.cpp
    sessionstack.h
    skin.cpp
    skin.h
    splitter.cpp
    splitter.h
    tabbar.cpp
    tabbar.h
    terminal.cpp
    terminal.h
    titlebar.cpp
    titlebar.h
    visualeventoverlay.cpp
    visualeventoverlay.h
    outputorderwatcher.cpp
)

ki18n_wrap_ui(Yakuake3rdScreen
    firstrundialog.ui
    config/windowsettings.ui
    config/behaviorsettings.ui
    config/appearancesettings.ui
)

if (Qt6_VERSION VERSION_GREATER_EQUAL "6.8.0")
    set(private_code_option  "PRIVATE_CODE")
endif()
qt6_generate_wayland_protocol_client_sources(Yakuake3rdScreen
    ${private_code_option}
    FILES
        ${PLASMA_WAYLAND_PROTOCOLS_DIR}/kde-output-order-v1.xml
)

kconfig_add_kcfg_files(Yakuake3rdScreen config/settings.kcfgc)

file(GLOB ICONS_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/../data/icons/*-apps-Yakuake3rdScreen.png")
ecm_add_app_icon(Yakuake3rdScreen_SRCS ICONS ${ICONS_SRCS})


target_link_libraries(Yakuake3rdScreen
    Qt::Widgets
    KF6::Archive
    KF6::ConfigGui
    KF6::CoreAddons
    KF6::Crash
    KF6::DBusAddons
    KF6::GlobalAccel
    KF6::I18n
    KF6::IconThemes
    KF6::KIOCore
    KF6::NewStuffWidgets
    KF6::Notifications
    KF6::NotifyConfig
    KF6::Parts
    KF6::WidgetsAddons
    KF6::WindowSystem
    KF6::StatusNotifierItem
    KF6::ColorScheme
    Wayland::Client
    Qt::WaylandClient
)

if(HAVE_X11)
    if(TARGET Qt6::Gui)
        target_link_libraries(Yakuake3rdScreen Qt6::GuiPrivate XCB::RANDR XCB::UTIL) # qtx11extras_p.h
    endif()
endif()

if(KWayland_FOUND)
  target_link_libraries(Yakuake3rdScreen Plasma::KWaylandClient)
endif()

install(TARGETS Yakuake3rdScreen ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

install(FILES Yakuake3rdScreen.knsrc DESTINATION ${KDE_INSTALL_KNSRCDIR})
