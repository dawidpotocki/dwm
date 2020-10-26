# dwm

*Personal fork of dwm (dynamic window manager) from suckless.org*

**NOTE:** It doesn't have any non-dwm related bindings, use `sxhkd` for them.

## Installation

Make sure you have dependencies installed before you build dwm.

### Dependencies

```sh
$ sudo pacman -S libx11 libxinerama libxft freetype2  # Arch Linux
```

### Building

```sh
$ git clone https://git.dawidpotocki.com/dawid/dwm
$ cd dwm
$ sudo make clean install
```

## Patches

- [fixborders](https://dwm.suckless.org/patches/alpha/)
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
- [movestack](https://dwm.suckless.org/patches/movestack/)
- [pertag](https://dwm.suckless.org/patches/pertag/)
- [scratchpads](https://dwm.suckless.org/patches/scratchpads/)
- [shiftview](https://github.com/bakkeby/dwm-flexipatch/blob/master/patch/shiftview.c)
- [systray](https://dwm.suckless.org/patches/systray/)
- systray-toggle
- [zoomswap](https://dwm.suckless.org/patches/zoomswap/)
