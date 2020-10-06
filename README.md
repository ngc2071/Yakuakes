# Yakuakes
Yakuake for Multiple Monitors

For those who are interested in having one independent Yakuake terminal for each monitor, you can use these modifications here.

Basically, they were modified to be installed in the folder /opt/.

So cmake complication would be cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/Yakuake1stScreen and cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/Yakuake2ndScreen

These folders are hardcoded in the cpp files. So you can look into the source code and change them to your liking. Also, just rename everything with Yakuake1stScreen/Yakuake2ndScreen (including files) for better naming, if you so wish.
