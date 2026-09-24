# Pluto12 macropad

An 11-key macropad with a rotary encoder, assembled at a Penn State IEEE workshop and customized for music, coding, and everyday desktop shortcuts.

> **Status:** The keymap compiles for `psuieee/pluto12`. The final physical button order and launcher actions still need to be tested on the pad. In particular, the original USB device reported `VID_4748`, while the QMK board definition currently uses `VID_4747`; confirm the PCB is a Pluto12 before flashing.

## Intended layout

The knob occupies the first position in the top row. Numbers refer to the physical buttons moving left to right, then down.

| Row | Left | Second | Third | Right |
| --- | --- | --- | --- | --- |
| Top | Knob: volume; press unused | 1 · Play/pause | 2 · Next track | 3 · Mute |
| Middle | 4 · Spotify | 5 · Run VS Code notebook cell | 6 · Alt+Tab | 7 · Discord |
| Bottom | 8 · Copy | 9 · Paste | 10 · Select all | 11 · Krillion |

Buttons 4, 7, and 11 send `F13`, `F14`, and `F15`. The optional Windows launcher script listens for those keys and opens Spotify, Discord, and [Krillion](https://krillion.io/). Button 5 sends `Ctrl+Enter`, which runs a cell in a VS Code notebook when that cell has focus. The encoder mapping is inverted relative to QMK's `clockwise` value on this assembled pad so that turning right raises the volume.

## Files

- [`firmware/keymap.c`](firmware/keymap.c): QMK keymap for the Pluto12.
- [`windows/macropad.ahk`](windows/macropad.ahk): AutoHotkey v2 launch actions for Windows.

## Build on Windows

1. Install [QMK MSYS](https://msys.qmk.fm/) and open it.
2. Run `qmk setup` if the QMK firmware checkout is not already installed.
3. Copy `firmware/keymap.c` to `qmk_firmware/keyboards/psuieee/pluto12/keymaps/encoder/keymap.c`. Create the `encoder` directory if needed.
4. Run `qmk compile -kb psuieee/pluto12 -km encoder`. Confirm the final output says the firmware size is fine.
5. **Confirm your PCB is a Pluto12 and the knob is top left.** With the pad plugged in, run `qmk flash -kb psuieee/pluto12 -km encoder`. When QMK waits for the bootloader, press the PCB reset button near the USB port. Wait for writing to finish and the pad to reconnect.

The [IEEE build guide](https://github.com/psuieee/projects/blob/main/spring2024/macropad/Macropad%20Build%20Instructions.pdf) shows the reset button and original setup. The QMK keyboard target is [`psuieee/pluto12`](https://github.com/qmk/qmk_firmware/tree/master/keyboards/psuieee/pluto12).

## Windows launch buttons

1. Install [AutoHotkey v2](https://www.autohotkey.com/).
2. Double-click `windows/macropad.ahk` to start the script. Its `F13`/`F14` handlers look for installed Start Menu shortcuts and open the browser versions if none are found; `F15` opens Krillion.
3. To launch it automatically at sign-in, press `Win+R`, enter `shell:startup`, and put a shortcut to `macropad.ahk` in the folder that opens.

The script works only while running. The media and editing buttons are programmed in the pad and do not need it.

## Verification checklist

- [ ] Right turn increases volume; left turn decreases volume.
- [ ] Buttons 1–3 control playback, next track, and mute.
- [ ] Buttons 5, 6, and 8–10 work in their intended apps.
- [ ] With the Windows script running, 4 opens Spotify, 7 opens Discord, and 11 opens Krillion.
- [ ] If actions appear on different buttons, identify the physical matrix order and update `LAYOUT(...)` before calling the mapping final.

## Credits

The [Pluto12 PCB](https://github.com/psuieee/pluto12) was designed by the Penn State IEEE Projects Committee. The [workshop instructions and example encoder keymap](https://github.com/psuieee/projects/tree/main/spring2024/macropad) are from Penn State IEEE; the example keymap carries Will McGLoughlin's 2021–22 copyright and a GPL-2.0-or-later notice. This repository documents the assembled pad and its personal key assignments and Windows launch integration.

The QMK keymap is licensed under GPL-2.0-or-later; see the header in `firmware/keymap.c`.
