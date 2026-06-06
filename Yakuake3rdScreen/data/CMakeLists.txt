add_subdirectory(icons)
add_subdirectory(skins)

ecm_generate_dbus_service_file(
    NAME org.kde.Yakuake3rdScreen
    EXECUTABLE ${KDE_INSTALL_FULL_BINDIR}/Yakuake3rdScreen
    DESTINATION ${KDE_INSTALL_DBUSSERVICEDIR}
)

install(FILES org.kde.Yakuake3rdScreen.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.kde.Yakuake3rdScreen.appdata.xml DESTINATION  ${KDE_INSTALL_METAINFODIR})
install(FILES Yakuake3rdScreen.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFYRCDIR})
