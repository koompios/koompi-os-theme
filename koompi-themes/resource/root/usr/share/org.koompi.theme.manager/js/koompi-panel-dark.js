
// Remove all existing panels 


for (i in panelIds) {
    panel = panelById(panelIds[i]);
    panel.remove();
};

//Create KOOMPI Panel

var koompi_panel = new Panel();

koompi_panel.location = "top";
koompi_panel.height = 32;

var space1 = koompi_panel.addWidget("org.kde.plasma.panelspacer");
space1.currentConfigGroup = ["General"]
space1.writeConfig("expanding", false);
space1.writeConfig("length", 7);

var menu = koompi_panel.addWidget("org.kde.plasma.umenu");
menu.currentConfigGroup = ["Shortcuts"]
menu.writeConfig("global", "Alt+F1")

var space2 = koompi_panel.addWidget("org.kde.plasma.panelspacer");
space2.currentConfigGroup = ["General"]
space2.writeConfig("expanding", false);
space2.writeConfig("length", 3);

var all_tasks = koompi_panel.addWidget("org.kde.plasma.icontasks");
all_tasks.currentConfigGroup = ["General"]
all_tasks.writeConfig("launchers" ,"file:///usr/share/applications/org.kde.dolphin.desktop,file:///usr/share/applications/firefox.desktop,file:///usr/share/applications/org.kde.konsole.desktop")

// Add system tray
var systray = koompi_panel.addWidget("org.kde.plasma.systemtray")
var systrayContainmentId = systray.readConfig("SystrayContainmentId")
var systrayContainment = desktopById(systrayContainmentId)
systrayContainment.currentConfigGroup = ["General"]
systrayContainment.writeConfig("extraItems","org.kde.plasma.devicenotifier,org.kde.plasma.networkmanagement,org.kde.discovernotifier,org.kde.plasma.diskquota,org.kde.plasma.bluetooth,org.kde.plasma.clipboard,org.kde.plasma.printmanager,org.kde.plasma.battery")
systrayContainment.writeConfig("knownItems", "org.kde.plasma.volume,org.kde.plasma.networkmanagement,org.kde.plasma.bluetooth,org.kde.plasma.battery,org.kde.discovernotifier,org.kde.plasma.clipboard,org.kde.plasma.mediacontroller,org.kde.plasma.devicenotifier,org.kde.plasma.notifications,org.kde.plasma.printmanager,org.kde.plasma.notifications,org.kde.kdeconnect")
systrayContainment.writeConfig("hiddenItems","org.kde.plasma.clipboard,org.kde.plasma.volume,org.kde.plasma.networkmanagement,org.kde.plasma.battery")


koompi_panel.addWidget("org.kde.plasma.bluetooth")
koompi_panel.addWidget("org.kde.plasma.networkmanagement")
koompi_panel.addWidget("org.kde.plasma.volume")
koompi_panel.addWidget("org.kde.plasma.battery")

var space3 = koompi_panel.addWidget("org.kde.plasma.panelspacer");
space3.currentConfigGroup = ["General"]
space3.writeConfig("expanding", false);
space3.writeConfig("length", 5);

var dateviewer = koompi_panel.addWidget("org.kde.plasma.chiliclock");
dateviewer.currentConfigGroup = ["Appearance"];
dateviewer.writeConfig("customDateFormat", "ddd dd/MM/yy");
dateviewer.writeConfig("fixedFont", true);
dateviewer.writeConfig("fontSize", 14);

var space4 = koompi_panel.addWidget("org.kde.plasma.panelspacer");
space4.currentConfigGroup = ["General"]
space4.writeConfig("expanding", false);
space4.writeConfig("length", 10);

var power = koompi_panel.addWidget("org.kde.plasma.lock_logout");
power.currentConfigGroup = ["General"];
power.writeConfig("show_lockScreen", false);

var space5 = koompi_panel.addWidget("org.kde.plasma.panelspacer");
space5.currentConfigGroup = ["General"]
space5.writeConfig("expanding", false);
space5.writeConfig("length", 10);

var show_desktop = koompi_panel.addWidget("org.kde.plasma.win7showdesktop");
show_desktop.currentConfigGroup = ["General"];
show_desktop.writeConfig("size", 5);

var Desktops = desktops();                                                                                                                       
for (i=0;i<Desktops.length;i++) {
        d = Desktops[i];
        d.wallpaperPlugin = "org.kde.image";
        d.currentConfigGroup = Array("Wallpaper",
                                    "org.kde.image",
                                    "General");
        d.writeConfig("Image", "file:///usr/share/wallpapers/koompi-dark.svg");
}


