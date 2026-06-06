# Yakuakes
Yakuake for Multiple Monitors

For those who are interested in having one independent Yakuake terminal for each monitor, you can use these modifications here.

Basically, they were modified to be installed in the folder /opt/.

So cmake complication would be cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/Yakuake1stScreen and cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/Yakuake2ndScreen

These folders are hardcoded in the cpp files. So you can look into the source code and change them to your liking. Also, just rename everything with Yakuake1stScreen/Yakuake2ndScreen (including files) for better naming, if you so wish.

## For Fedora 32

 - Packages:
    dnf install \
        cmake
        extra-cmake-modules
        qt5-qtbase-devel
        qt5-qtsvg-devel
        kf5-karchive-devel
        kf5-ki18n-devel
        kf5-kparts-devel
        kf5-knotifications-devel
        kf5-knotifyconfig-devel
        kf5-kglobalaccel-devel
        kf5-kdbusaddons-devel
        kf5-knewstuff-devel
        kf5-kiconthemes-devel
        kf5-kcrash-devel
        qt5-qtx11extras-devel
        kf5-kwayland-devel

## For Almalinux 10
 I did not make a complete list, but here what I could find:

 - Packages:
    dnf install \
        cmake
        extra-cmake-modules
        qt6-qtbase-private-devel
        qt6-qtmultimedia
        qt6-qtsvg-devel
        qt6-qtwayland-devel
        kf6-karchive-devel
        kf6-kcolorscheme-devel
        kf6-kconfig-devel
        kf6-kcrash-devel
        kf6-kdbusaddons-devel
        kf6-kglobalaccel-devel
        kf6-ki18n-devel
        kf6-kiconthemes-devel
        kf6-kio-devel
        kf6-knewstuff-devel
        kf6-knotifications-devel
        kf6-knotifyconfig-devel
        kf6-kparts-devel
        kf6-kstatusnotifieritem-devel
        kf6-kwayland-devel 
        kf6-kwidgetsaddons-devel
        kf6-kwindowsystem-devel
        
        
# How to update to a different version

## Replace name in the files

```console
YAKUAKE=Yakuake1stScreen; export IFS=$'\n'; list=$(find -iname '*' -type f -exec grep -nHi '".*yakuake.*"' {} \;); for each in $list; do filename=$(echo "$each" | cut -d ':' -f 1); line=$(echo "$each" | cut -d ':' -f 2); replace="$line"s; sed -i "$replace/\(.*\)yakuake\(.*\)/\1$YAKUAKE\2/I" $filename; done;
```

```console
YAKUAKE=Yakuake1stScreen; export IFS=$'\n'; list=$(find -iname '*' -type f -exec grep -nHi 'yakuake\.' {} \;); for each in $list; do filename=$(echo "$each" | cut -d ':' -f 1); line=$(echo "$each" | cut -d ':' -f 2); replace="$line"s; sed -i "$replace/\(.*\)yakuake\.\(.*\)/\1$YAKUAKE\.\2/I" $filename; done;
```

## Rename files

```console
YAKUAKE=Yakuake1stScreen;list=$(find -iname '*yakuake*'); for each in $list; do newname=$(echo $each | sed "s/[yY]akuake/$YAKUAKE/g"); mv $each $newname;  done;
```

## Manual steps

```console
YAKUAKE=Yakuake1stScreen; export IFS=$'\n'; list=( \
data/org.kde.$YAKUAKE.desktop \
data/$YAKUAKE.notifyrc \
CMakeLists.txt \
app/mainwindow.cpp \
app/firstrundialog.ui \
app/CMakeLists.txt \
app/$YAKUAKE.knsrc \
app/$YAKUAKE.knsrc \
data/org.kde.$YAKUAKE.desktop \
data/org.kde.$YAKUAKE.appdata.xml \
data/skins/CMakeLists.txt \
data/skins/default/CMakeLists.txt \
data/skins/legacy/CMakeLists.txt \
data/skins/plastik_light/CMakeLists.txt \
data/skins/plastik_dark/CMakeLists.txt \
data/CMakeLists.txt );
for each in ${list[@]}; do 
    sed -i "s/[Yy]akuake\([^0-9]\|$\)/$YAKUAKE\1/g" $each;
done;
rm app/config-$YAKUAKE.h.in 
git restore app/config-yakuake.h.in
YAKUAKE=Yakuake1stScreen; export IFS=$'\n'; list=( \
app/CMakeLists.txt \
app/mainwindow.h \
app/sessionstack.h \
app/outputorderwatcher.h);
for each in ${list[@]}; do 
    sed -i "s/config-$YAKUAKE\.h/config-yakuake\.h/g" $each 
done;
git restore README.md
```

# Final steps for Almalinux 10

After installation, copy the `$YAKUAKE/skins` folder from the installation location, like `/opt/Yakuake1stScreen/share/Yakuake1stScreen/skins`, to your `$HOME/.local/share/`. Having a folder like `$HOME/.local/share/Yakuake1stScreen/skins` should avoid the error that skins were not found and installation was faulty.
