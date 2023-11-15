# found-meishi

A small macropad based on [Biacco42's meishi2](https://github.com/Biacco42/meishi2)

#### What is meishi?
'Meishi' is the Japanese word for business card. I inherited the name from Biacco42's project. The PCB is in fact 91mm x 55mm, the proper meishi dimensions. Make sure you follow [the rules](https://workinjapan.today/work/the-secret-world-of-meishi/) when handling your meishi.

#### What does it do?
Whatever you manage to program it to do. It runs the open source Quantum Mechanical Keyboard ([QMK](https://docs.qmk.fm/#/)) firmware, which is extremely flexible and configurable... as long as your C compiles.

To give you some ideas, you can control media, type entire sequences of characters, send different keycodes on key press and key release, send different codes based on a single/double/triple presses, etc.

This functionality is written into a keymap. The macropad comes with the `demo` keymap preinstalled, which contains some examples of what's possible. There are other sample keymaps in the `keymaps` directory.

To build a keymap, clone this repo and run `util/docker_build.sh found_meishi:<keymap-name>`.
You may need to run `make git-submodule` before building the first time.

You will most likely want to use [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash your keymap. Refer to QMK documentation for more information on building and flashing.
