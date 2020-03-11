#!/bin/bash
qdbus org.kde.plasmashell /PlasmaShell org.kde.PlasmaShell.evaluateScript "$(cat /usr/share/org.koompi.theme.manager/js/koompi-panel-dark.js)"

if pgrep -x "latte-dock" > /dev/null
then
	rm -rf ${HOME}/.config/autostart/org.kde.latte-dock.desktop
	killall latte-dock
fi

pkexec cp /usr/share/org.koompi.theme.manager/config/koompi.conf /etc/sddm.conf.d/kde_settings.conf