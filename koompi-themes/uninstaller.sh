#!/bin/bash
yes | sudo pacman -R kvantum-qt5  breeze10-kde-git

sudo rm -rf /usr/bin/theme-manager \
            /usr/share/applications/theme-manager.desktop \
            /usr/share/org.koompi.theme.manager/ \
            /usr/share/sddm/themes/kameleon \
            /usr/share/sddm/themes/McMojave \
            /usr/share/sddm/themes/plasma-chili \
            /usr/share/wallpapers/koompi-dark.svg \
            /usr/share/wallpapers/koompi-light.jpg \
            /usr/share/wallpapers/mosx-dark.jpg \
            /usr/share/wallpapers/mosx-light.jpg \
            /usr/share/wallpapers/winx-dark.jpg \
            /usr/share/wallpapers/winx-light.jpg

rm -rf ~/.config/Kvantum/Fluent-Dark \
        ~/.config/Kvantum/Fluent-Light \
        ~/.config/Kvantum/kvantum.kvconfig \
        ~/.icons/Bibata_Ice/ \
        ~/.icons/Bibata_Oil/ \
        ~/.icons/McMojave-cursors \
        ~/.Win-8.1-S \
        ~/.local/share/aurorae/themes/McMojave \
        ~/.local/share/aurorae/themes/McMojave-light \
        ~/.local/share/aurorae/color-scheems/McMojave.colors \
        ~/.local/share/aurorae/color-scheems/McMojaveLight.colors \
        ~/.local/share/icons/la-capitaine-icon-theme \
        ~/.local/share/icons/Qogir \
        ~/.local/share/icons/Qogir-dark \
        ~/.local/share/plasma/desktoptheme/Helium \
        ~/.local/share/plasma/desktoptheme/Nilium \
        ~/.local/share/plasma/desktoptheme/McMojave \
        ~/.local/share/plasma/desktoptheme/McMojave-light \
        ~/.local/share/plasma/look-and-feel/org.koompi.theme.koompi-dark \
        ~/.local/share/plasma/look-and-feel/org.koompi.theme.koompi-light \
        ~/.local/share/plasma/look-and-feel/org.koompi.theme.koompi-mosx-dark \
        ~/.local/share/plasma/look-and-feel/org.koompi.theme.koompi-mosx-light \
        ~/.local/share/plasma/look-and-feel/org.koompi.theme.koompi-winx-dark \
        ~/.local/share/plasma/look-and-feel/org.koompi.theme.koompi-winx-light \
        ~/.local/share/plasma/plasmoids/com.github.zren.tiledmenu \
        ~/.local/share/plasma/plasmoids/org.communia.apptitle \
        ~/.local/share/plasma/plasmoids/org.kde.plasma.chiliclock \
        ~/.local/share/plasma/plasmoids/org.kde.plasma.umenu \
        ~/.local/share/plasma/plasmoids/org.kde.plasma.win7showdesktop \
        ~/Desktop/theme-manager.desktop

