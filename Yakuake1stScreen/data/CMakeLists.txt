add_subdirectory(icons)
add_subdirectory(skins)

ecm_generate_dbus_service_file(
    NAME org.kde.Yakuake1stScreen
    EXECUTABLE ${KDE_INSTALL_FULL_BINDIR}/Yakuake1stScreen
    DESTINATION ${KDE_INSTALL_DBUSSERVICEDIR}
)

install(FILES org.kde.Yakuake1stScreen.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.kde.Yakuake1stScreen.appdata.xml DESTINATION  ${KDE_INSTALL_METAINFODIR})
install(FILES Yakuake1stScreen.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFYRCDIR})
