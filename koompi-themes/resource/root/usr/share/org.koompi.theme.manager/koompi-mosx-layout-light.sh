#!/bin/bash
qdbus org.kde.plasmashell /PlasmaShell org.kde.PlasmaShell.evaluateScript "$(cat /usr/share/org.koompi.theme.manager/js/mosx-panel-light.js)"

if ! pgrep -x "latte-dock" > /dev/null
then
    	cp /usr/share/applications/org.kde.latte-dock.desktop ${HOME}/.config/autostart/
	latte-dock </dev/null &>/dev/null &
    	echo -e "Done"
fi

pkexec cp /usr/share/org.koompi.theme.manager/config/mosx.conf /etc/sddm.conf.d/kde_settings.conf