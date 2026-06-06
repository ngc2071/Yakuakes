add_subdirectory(icons)
add_subdirectory(skins)

ecm_generate_dbus_service_file(
    NAME org.kde.Yakuake2ndScreen
    EXECUTABLE ${KDE_INSTALL_FULL_BINDIR}/Yakuake2ndScreen
    DESTINATION ${KDE_INSTALL_DBUSSERVICEDIR}
)

install(FILES org.kde.Yakuake2ndScreen.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.kde.Yakuake2ndScreen.appdata.xml DESTINATION  ${KDE_INSTALL_METAINFODIR})
install(FILES Yakuake2ndScreen.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFYRCDIR})
