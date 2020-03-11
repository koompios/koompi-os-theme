#!/bin/bash

work_dir=$(pwd);

[ ! -d ${HOME}/.pix/koompi-themes ] && mkdir -p ${HOME}/.pix/koompi-themes

cp -r ${work_dir}/uninstaller.sh ${HOME}/.pix/koompi-themes/
cp -r ${work_dir}/version.sh ${HOME}/.pix/koompi-themes/
cp -r ${work_dir}/README.md ${HOME}/.pix/koompi-themes/
cp -r ${work_dir}/LICENSE ${HOME}/.pix/koompi-themes/

chmod +x ${work_dir}/resource/home/Desktop/theme-manager.desktop
chmod +x ${work_dir}/resource/root/usr/share/applications/theme-manager.desktop
chmod +x ${work_dir}/resource/root/usr/bin/theme-manager
chmod +x ${work_dir}/resource/root/usr/share/org.koompi.theme.manager/*.sh

rsync -av ${work_dir}/resource/home/ ${HOME}/
sudo rsync -av ${work_dir}/resource/root/ /

yes | sudo pacman -U ${work_dir}/resource/packages/breeze10-kde-git-r20.18edb47-1-x86_64.pkg.tar.xz
yes | sudo pacman -U ${work_dir}/resource/packages/kvantum-qt5-0.14.1-1-x86_64.pkg.tar.zst

[ ! -d /etc/sddm.conf.d/ ] && sudo mkdir -p /etc/sddm.conf.d
[ -f /etc/sddm.conf ] && sudo rm -rf /etc/sddm.conf
