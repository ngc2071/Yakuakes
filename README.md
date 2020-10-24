# Yakuakes
Yakuake for Multiple Monitors

For those who are interested in having one independent Yakuake terminal for each monitor, you can use these modifications here.

Basically, they were modified to be installed in the folder /opt/.

So cmake complication would be cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/Yakuake1stScreen and cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/Yakuake2ndScreen

These folders are hardcoded in the cpp files. So you can look into the source code and change them to your liking. Also, just rename everything with Yakuake1stScreen/Yakuake2ndScreen (including files) for better naming, if you so wish.

Packages (Fedora 32):

dnf install cmake extra-cmake-modules qt5-qtbase-devel qt5-qtsvg-devel kf5-karchive-devel kf5-ki18n-devel kf5-kparts-devel kf5-knotifications-devel kf5-knotifyconfig-devel kf5-kglobalaccel-devel kf5-kdbusaddons-devel kf5-knewstuff-devel kf5-kiconthemes-devel kf5-kcrash-devel qt5-qtx11extras-devel kf5-kwayland-devel
