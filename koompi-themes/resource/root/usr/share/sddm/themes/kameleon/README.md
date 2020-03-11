# Kameleon (SDDM)

This theme is part of the Kameleon project

## Project

Kameleon is a project to create a full desktop theming to (I know, I know) looking like Windows 10. Nowadays Windows 10 seems to looking like KDE so ...

## Configuration

Support of virtual keyboard is functionnal (top right of the screen).

If you don't have virtual keyboard showing up (Debian Buster for exemple), just install it :

```
sudo apt install virtualkeyboard-plugin
```

## Tweaks

### Background

Open theme folder then go to :

* ./components/artwork/

Replace the "background.png" file to the one you like (it needs to be .png file) 

### Avatars

Open theme folder then go to :

* ./components/artwork/

Replace the "user.png" file to the one you like (it needs to be .png file)

### Timers

Open theme folder then edit the file :

* ./Main.qml

```
Line 55 :

interval: 30000 // set the interval you want the cover to appear default is 30 seconds
```

### Colors

Open theme folder then edit all of this file :

* ./Login.qml

* ./Main.qml

```
In each file, look for :

color: "#1e92ff"

Replace the part "#1e92ff" to the one you want, this will apply your color to all component of the theme if you edit all the file (go for a search and replace)
```

## Credits

This theme is adapt from original Breeze and Breeze-cover. All copyrights, credits and everything goes to their original authors.

## Notes

Since I don't understand well QML language, I've trying to do what I could to obtain the things I want. Feel free to modify to feet your needs, you can also submit part of code that I could add to the theme when I find some time.

I'm using this theme daily and so far got no issue, I wanted to share with community since a long time, enjoy if you like, otherwise, then look for some nice SDDM theme like chili login theme (https://store.kde.org/p/1240784) or Sugar Candy for SDDM (https://store.kde.org/p/1312658/) or even Lime green (https://store.kde.org/p/1310489/) and others.

Feel free to copy the theme and made your own change !


