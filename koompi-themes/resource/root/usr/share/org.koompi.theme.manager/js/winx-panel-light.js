/*
*  remove all existing panels 
*/

for (i in panelIds) {
    panel = panelById(panelIds[i]);
    panel.remove();
};

/*
* Create KOOMPI Panel
*/

var window_panel = new Panel();

// very important data
// to get it you need to:
// 1. customize the tile look
// 2. copy the json file in TileMenu setting Import/Eport
// 3. convert to Base64 string in this webiste "https://www.base64encode.org/"

var data = "WwogICAgICB7CiAgICAgICAgIngiOiAwLAogICAgICAgICJ5IjogMCwKICAgICAgICAidyI6IDYsCiAgICAgICAgImgiOiAxLAogICAgICAgICJ1cmwiOiAiIiwKICAgICAgICAidGlsZVR5cGUiOiAiZ3JvdXAiLAogICAgICAgICJsYWJlbCI6ICJCYXNpYyBDb21wdXRpbmciCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDAsCiAgICAgICAgInkiOiAxLAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJvcmcua2RlLmRvbHBoaW4uZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogMiwKICAgICAgICAieSI6IDEsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogIm9yZy5rZGUua29uc29sZS5kZXNrdG9wIgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiA0LAogICAgICAgICJ5IjogMSwKICAgICAgICAidyI6IDIsCiAgICAgICAgImgiOiAyLAogICAgICAgICJ1cmwiOiAic3lzdGVtc2V0dGluZ3MuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogMiwKICAgICAgICAieSI6IDMsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogIm9yZy5rZGUua3N5c2d1YXJkLmRlc2t0b3AiCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDAsCiAgICAgICAgInkiOiA1LAogICAgICAgICJ3IjogNiwKICAgICAgICAiaCI6IDEsCiAgICAgICAgInVybCI6ICIiLAogICAgICAgICJ0aWxlVHlwZSI6ICJncm91cCIsCiAgICAgICAgImxhYmVsIjogIkludGVybmV0IgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiAwLAogICAgICAgICJ5IjogNiwKICAgICAgICAidyI6IDIsCiAgICAgICAgImgiOiAyLAogICAgICAgICJ1cmwiOiAiZmlyZWZveC5kZXNrdG9wIgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiA0LAogICAgICAgICJ5IjogNiwKICAgICAgICAidyI6IDIsCiAgICAgICAgImgiOiAyLAogICAgICAgICJ1cmwiOiAieGRtYW4uZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogNCwKICAgICAgICAieSI6IDMsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogImNvbS50ZWFtdmlld2VyLlRlYW1WaWV3ZXIuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogMCwKICAgICAgICAieSI6IDgsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogInRlbGVncmFtZGVza3RvcC5kZXNrdG9wIgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiA3LAogICAgICAgICJ5IjogMCwKICAgICAgICAidyI6IDYsCiAgICAgICAgImgiOiAxLAogICAgICAgICJ1cmwiOiAiIiwKICAgICAgICAidGlsZVR5cGUiOiAiZ3JvdXAiLAogICAgICAgICJsYWJlbCI6ICJTdHVkeSAmIFdvcmsiCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDcsCiAgICAgICAgInkiOiAxLAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJsaWJyZW9mZmljZS13cml0ZXIuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogOSwKICAgICAgICAieSI6IDEsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogImxpYnJlb2ZmaWNlLWNhbGMuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogMTEsCiAgICAgICAgInkiOiAxLAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJsaWJyZW9mZmljZS1pbXByZXNzLmRlc2t0b3AiCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDIsCiAgICAgICAgInkiOiA2LAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJnb29nbGUtY2hyb21lLmRlc2t0b3AiCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDcsCiAgICAgICAgInkiOiAzLAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJmcmVlbWluZC5kZXNrdG9wIgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiAwLAogICAgICAgICJ5IjogMywKICAgICAgICAidyI6IDIsCiAgICAgICAgImgiOiAyLAogICAgICAgICJ1cmwiOiAib3JnLmtkZS5kaXNjb3Zlci5kZXNrdG9wIgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiA5LAogICAgICAgICJ5IjogMywKICAgICAgICAidyI6IDIsCiAgICAgICAgImgiOiAyLAogICAgICAgICJ1cmwiOiAiRm94aXRSZWFkZXIuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogNywKICAgICAgICAieSI6IDUsCiAgICAgICAgInciOiA2LAogICAgICAgICJoIjogMSwKICAgICAgICAidXJsIjogIiIsCiAgICAgICAgInRpbGVUeXBlIjogImdyb3VwIiwKICAgICAgICAibGFiZWwiOiAiR3JhcGhpYyAmIE11bHRpbWVkaWEiCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDcsCiAgICAgICAgInkiOiA2LAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJnaW1wLmRlc2t0b3AiCiAgICAgIH0sCiAgICAgIHsKICAgICAgICAieCI6IDksCiAgICAgICAgInkiOiA2LAogICAgICAgICJ3IjogMiwKICAgICAgICAiaCI6IDIsCiAgICAgICAgInVybCI6ICJpbmtzY2FwZS5kZXNrdG9wIgogICAgICB9LAogICAgICB7CiAgICAgICAgIngiOiAxMSwKICAgICAgICAieSI6IDYsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogIm9yZy5rZGUua3JpdGEuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogNywKICAgICAgICAieSI6IDgsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogImJsZW5kZXIuZGVza3RvcCIKICAgICAgfSwKICAgICAgewogICAgICAgICJ4IjogOSwKICAgICAgICAieSI6IDgsCiAgICAgICAgInciOiAyLAogICAgICAgICJoIjogMiwKICAgICAgICAidXJsIjogIm9yZy5rZGUua2RlbmxpdmUuZGVza3RvcCIKICAgICAgfQogICAgXQ=="

window_panel.location = "bottom";
window_panel.height = 44;

var widget_list = [ "com.github.zren.tiledmenu", 
                    "org.kde.plasma.icontasks",
                    "org.kde.plasma.systemtray",
                    "org.kde.plasma.digitalclock",
                    "org.kde.plasma.win7showdesktop"
                  ];

for(i in widget_list) {
    if(widget_list[i] == "com.github.zren.tiledmenu") {

        menu = window_panel.addWidget("com.github.zren.tiledmenu");
        menu.currentConfigGroup = ["Shortcuts"]
        menu.writeConfig("global", "Alt+F1")

        menu.currentConfigGroup = ["General"]
        menu.writeConfig("showRecentApps", false)
        menu.writeConfig("appDescription", "hidden")
        menu.writeConfig("searchFieldHeight", 32)
        menu.writeConfig("sidebarButtonSize", 40)
        menu.writeConfig("favGridCols", 13)
        menu.writeConfig("tileModel", data);

    }
    else if (widget_list[i] == "org.kde.plasma.icontasks") {
        task = window_panel.addWidget("org.kde.plasma.icontasks");
        task.currentConfigGroup = ["General"]
        task.writeConfig("launchers" ,"file:///usr/share/applications/org.kde.dolphin.desktop,file:///usr/share/applications/firefox.desktop,file:///usr/share/applications/org.kde.konsole.desktop")
    }
    else if (widget_list[i] == "org.kde.plasma.digitalclock") {

        clock = window_panel.addWidget("org.kde.plasma.digitalclock");
        clock.currentConfigGroup = ["Appearance"]
        clock.writeConfig("showDate", true)
        clock.writeConfig("dateFormat", "isoDate")
    } 
    else if(widget_list[i] == "org.kde.plasma.win7showdesktop") {

        show_desktop = window_panel.addWidget("org.kde.plasma.win7showdesktop")
        show_desktop.currentConfigGroup = ["General"]
        show_desktop.writeConfig("size", 10)
        show_desktop.writeConfig("click_action", "minimizeall")
    } 
    else {

        window_panel.addWidget(widget_list[i]);
    }
} 

var Desktops = desktops();                                                                                                                       
for (i=0;i<Desktops.length;i++) {
        d = Desktops[i];
        d.wallpaperPlugin = "org.kde.image";
        d.currentConfigGroup = Array("Wallpaper",
                                    "org.kde.image",
                                    "General");
        d.writeConfig("Image", "file:///usr/share/wallpapers/winx-light.jpg");
}