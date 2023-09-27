### 1. Explain the technical concept 📘
When developing Linux Kernel Modules, it’s crucial to consider the Kernel Version the module is intended for as there are changes in function arguments, deprecations, and different implementations between versions. `access_ok` is one such function that witnessed a change in its signature with Linux version 5.0. To support multiple kernel versions within one module, conditional compilation directives are necessary. This involves comparing `LINUX_VERSION_CODE` with `KERNEL_VERSION` to manage differences in kernel API. The `LINUX_VERSION_CODE` represents the binary equivalent of the kernel version, and it's calculated from the top-level Makefile of the Kernel using `VERSION`, `PATCHLEVEL`, and `SUBLEVEL`.

### 2. Curious Questions 🤔
**Q:** How is the `LINUX_VERSION_CODE` for a specific kernel version calculated?
**A:** It’s calculated using the formula: `LINUX_VERSION_CODE = (VERSION * 65536) + (PATCHLEVEL * 256) + SUBLEVEL`, wherein `VERSION`, `PATCHLEVEL`, and `SUBLEVEL` are the major, minor, and sublevel version numbers of the kernel, respectively.

**Q:** Why is it important to consider `LINUX_VERSION_CODE` when developing kernel modules?
**A:** It is important because it helps in managing the changes in function arguments, deprecations, and different implementations between kernel versions, allowing developers to write modules that are compatible with multiple kernel versions.

**Q:** What does adding `EXTRA_CFLAGS=’-save-temps’` in your Makefile do during the compilation of a kernel module?
**A:** It will generate all intermediate files during the creation of `.ko` (Kernel Object) files, which can be helpful in debugging and understanding the preprocessing stage of compilation.

### 3. Explain the concept in simple words 🌟
Imagine you are baking different versions of a cake 🍰 (kernel versions). Some people (modules) have different preferences or allergies (API changes). The `LINUX_VERSION_CODE` is like a recipe card 📜 that tells you which version of the cake you are baking. So, when you are baking (compiling), you need to check the recipe card (LINUX_VERSION_CODE) to make sure you are adding the right ingredients (using the right API) for the people (modules) who will eat the cake (run on the kernel). If you want to save every step of your baking process (compilation), adding `EXTRA_CFLAGS=’-save-temps’` is like taking pictures 📸 at every step, so you can go back and see what you did at each stage.


 The way to do this to compare the macro LINUX_VERSION_CODE to the macro KERNEL_VERSION.

LINUX_VERSION_CODE:This macro expands to the binary representation of the  kernel version.
One byte for each part of the version release number.
Eg. 5.0.0 = 0x050000 = 327680

Header File: <linux/version.h>

From Kernel Top Level Makefile

LINUX_VERSION_CODE = $(VERSION) * 65536 + $(PATCHLEVEL) * 256 + $(SUBLEVEL)
Eg: 5.0.0 = 5*65536+0*256+0 = 327680
